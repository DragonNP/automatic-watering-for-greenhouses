void ShowPage1() {
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Temn:    C БAK:    С");

  lcd.setCursor(0,1);
  lcd.print("Bлaж:    %");

  lcd.setCursor(0,2);
  lcd.print("Cлeд. noлuв чepeз:");
}

void UpdatePage1() {
  float* data = getDataFromDHT();

  lcd.setCursor(6,0);
  lcd.print(data[0], 1);

  lcd.setCursor(15,0);
  lcd.print(GetTempFromDallas(), 1);

  lcd.setCursor(6,1);
  lcd.print(data[1], 1);

  lcd.setCursor(0,3);

  short state = getStatePump();
  if (state == 0)
    lcd.print("ПOLUBAYU       ");
  else if (state == 1)
    lcd.print(format_time_for_lcd(GetRemainingPoliv()));
  else if (state == 2)
    lcd.print("BOДA XOLODHAYA ");
  else
    lcd.print("ERROR!!!!      ");
}