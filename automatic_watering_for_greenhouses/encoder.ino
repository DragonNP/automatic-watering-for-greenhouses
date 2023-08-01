#include <EncButton2.h>

EncButton2<EB_ENCBTN> enc(INPUT, ENCODER_1_PIN, ENCODER_2_PIN, ENCODER_BUTTON_PIN);  // энкодер с кнопкой <A, B, KEY>

void checkEncoder() {
  enc.tick();

  if (enc.left()) {
    tmr_lcd_dsb = millis();

    if (curr_page == 2) LeftPage2();
    if (curr_page == 3) TurnPage3();

    if (curr_page != 0 && !edit_mode) PrevPage();
    if (curr_page == 0) enableLCD();
  }

  if (enc.right()) {
    tmr_lcd_dsb = millis();

    if (curr_page == 2) RightPage2();
    if (curr_page == 3) TurnPage3();

    if (curr_page != 0 && !edit_mode) NextPage();
    if (curr_page == 0) enableLCD();
  }

  if (enc.click()) {
    tmr_lcd_dsb = millis();

    if (curr_page == 2) ClickPage2();
    if (curr_page == 3) ClickPage3();

    if (curr_page == 0) enableLCD();
  }
}
