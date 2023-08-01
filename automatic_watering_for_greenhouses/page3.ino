void ShowPage3() {
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Peжumы");
  lcd.setCursor(0,2);
  lcd.print("Пoлuв: ");
  if (poliv) {
    lcd.print("BKЛ.");
  }
  else {
    lcd.print("BЫKЛ.");
  }
}

void ClickPage3() {
  if (!edit_mode) {
    if (poliv)
      lcd.setCursor(10,2);
    else
      lcd.setCursor(11,2);

    lcd.cursor();
    lcd.blink();
    edit_mode = true;
  }
  else {
    lcd.noBlink();
    lcd.noCursor();
    edit_mode = false;
  }
}

void TurnPage3() {
  if (!edit_mode) { return; }

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