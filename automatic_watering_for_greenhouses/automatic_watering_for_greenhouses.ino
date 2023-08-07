#include <Wire.h>
#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>

// SETTINGS
#define DHT_PIN A1 // Пин для DHT11 датчика
#define PUMP_PIN 4 // Пин для помпы (реле)
#define BUCK_TEMP_PIN A2 // Пин для dallas датчика температуры
#define ENCODER_1_PIN 3 // Первый пин для энкодера
#define ENCODER_2_PIN 2 // Первый пин для энкодера
#define ENCODER_BUTTON_PIN 0 // Пин на котором кнопка энкодера

LCD_1602_RUS lcd(0x3f, 20, 4);

uint32_t tmr_lcd_dsb;
uint8_t curr_page = 1;
bool force_update = true;

bool edit_mode = false;

bool started_poliv = false;
bool poliv = true;

short temp_water_for_run_pump;

uint32_t tmr_check_pump;
uint32_t tmr_check_sensors;

uint32_t next_time_start_pump;
uint32_t poliv_time;
uint8_t poliv_time_day;
uint8_t poliv_time_hour;
uint8_t poliv_time_minutes;
uint8_t poliv_time_seconds;

uint32_t tmr_poliv_duration;
uint32_t poliv_duration;
uint8_t poliv_duration_day;
uint8_t poliv_duration_hour;
uint8_t poliv_duration_minutes;
uint8_t poliv_duration_seconds;

void setup(){
  lcd.init();
  lcd.backlight();

  setupDS3231();
  SetupDHT();
  SetupPump();
  SetupEEPROM();
}

void loop() {
  checkEncoder();

  if (curr_page != 0)
    timerForDisableLCD();
    updateLCD();

  if (millis() - tmr_check_pump >= 1000) {
    tmr_check_pump = millis();
    CheckStartPoliv();
    CheckStopPoliv();
  }

  if (millis() - tmr_check_sensors >= 1000) {
    tmr_check_sensors = millis();
    requestTempFromDallas();
  }
}

void enableLCD() {
  curr_page = 1;
  force_update = true;
  tmr_lcd_dsb = millis();

  lcd.display();
  lcd.backlight();
}

void timerForDisableLCD() {
  if (millis() - tmr_lcd_dsb >= 10000) {
    curr_page = 0;
    tmr_lcd_dsb = millis();

    lcd.noDisplay();
    lcd.noBacklight();
  }
}

void updateLCD() {
  static uint32_t tmr_lcd;

  if (millis() - tmr_lcd >= 1000 || force_update) {
    tmr_lcd = millis();

    if (curr_page == 1) {
      if (force_update) {
        ShowPage1();
        force_update = false;
      }
      else {
        UpdatePage1();
      }
    }
    else if (curr_page == 2) {
      if (force_update) {
        ShowPage2();
        force_update = false;
      }
    }
    else if (curr_page == 3) {
      if (force_update) {
        ShowPage3();
        force_update = false;
      }
    }
  }
}

void NextPage() {
  curr_page++;
  if (curr_page >= 4) {
    curr_page = 1;
  }
  force_update = true;
}

void PrevPage() {
  curr_page--;
  if (curr_page <= 0) {
    curr_page = 3;
  }
  force_update = true;
}