uint8_t position_corsor_page3 = 1;

void ShowPage3() {
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Peжumы");

  lcd.setCursor(0, 1);
  lcd.print("Muн. temn. Boды: ");

  print_new_value(temp_water_for_run_pump, 18, 1);
  lcd.setCursor(19, 1);
  lcd.print("C");

  lcd.setCursor(0,2);
  lcd.print("ПoлuB: ");
  if (poliv) {
    lcd.print("BKЛ. ");
  }
  else {
    lcd.print("BЫKЛ.");
  }
}

void ClickPage3() {
  if (!edit_mode) {
    lcd.setCursor(18, 1);
    
    lcd.cursor();
    lcd.blink();
    edit_mode = true;
    position_corsor_page3 = 1;
  }
  else if (position_corsor_page3 == 1) {
      if (poliv)
        lcd.setCursor(10,2);
      else
        lcd.setCursor(11,2);

      position_corsor_page3++;
  }
  else if (position_corsor_page3 == 2) {
      lcd.noBlink();
      lcd.noCursor();
      edit_mode = false;
  }
}

void LeftPage3() {
  if (!edit_mode) return;
  if (position_corsor_page3 != 1) return;

  temp_water_for_run_pump--;
  if (temp_water_for_run_pump < 0) {
    temp_water_for_run_pump = 30;
  }

  print_new_value(temp_water_for_run_pump, 18, 1);
  saveTempWaterForRunPump();
}

void RightPage3() {
  if (!edit_mode) { return; }
  if (position_corsor_page3 != 1) return;

  temp_water_for_run_pump++;
  if (temp_water_for_run_pump > 30) {
    temp_water_for_run_pump = 0;
  }

  print_new_value(temp_water_for_run_pump, 18, 1);
  saveTempWaterForRunPump();
}

void TurnPage3() {
  if (!edit_mode) { return; }
  if (position_corsor_page3 != 2) return;

  poliv = !poliv;
  lcd.setCursor(7,2);
  if (poliv) {
    lcd.print("BKЛ. ");
    lcd.setCursor(10, 2);
  }
  else {
    lcd.print("BЫKЛ.");
    lcd.setCursor(11,2);
  }
  SavePoliv();
}