#include <Wire.h>
#define _LCD_TYPE 1
#include <LCD_1602_RUS_ALL.h>

// SETTINGS
#define DHT_PIN A1 // Pin for DHT11 sensor
#define PUMP_PIN 1 // Пин для помпы (реле)
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

uint32_t tmr_poliv_time;
uint32_t poliv_time = 10000;
uint8_t poliv_time_day;
uint8_t poliv_time_hour;
uint8_t poliv_time_minutes;
uint8_t poliv_time_seconds;

uint32_t tmr_poliv_duration;
uint32_t poliv_duration = 4000;
uint8_t poliv_duration_day;
uint8_t poliv_duration_hour;
uint8_t poliv_duration_minutes;
uint8_t poliv_duration_seconds;

void setup(){
  lcd.init();
  lcd.backlight();

  SetupDHT();
  SetupPump();
  SetupEEPROM();
}

void loop() {
  checkEncoder();

  if (curr_page == 0)
    checkDisableLCD();
  else
    checkLCD();

  RequestTempFromDallas();
  CheckStartPoliv();
  CheckStopPoliv();
}

void enableLCD() {
  curr_page = 1;
  force_update = true;
  tmr_lcd_dsb = millis();

  lcd.display();
  lcd.backlight();
}

void checkDisableLCD() {
  if (millis() - tmr_lcd_dsb >= 10000) {
    curr_page = 0;
    tmr_lcd_dsb = millis();

    lcd.noDisplay();
    lcd.noBacklight();
  }
}

void checkLCD() {
  static uint32_t tmr_lcd;
  if (millis() - tmr_lcd >= 1000 || curr_page == 2 || curr_page == 3 || force_update) {
    tmr_lcd = millis();
    update_lcd();
  }
}

void update_lcd() {
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