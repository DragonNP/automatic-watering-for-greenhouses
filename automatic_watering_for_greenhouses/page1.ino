void ShowPage1() {
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Temn:    C Бak:    С");

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
  lcd.print(format_time_for_lcd(GetRemainingPoliv()));
}