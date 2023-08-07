String format_time_for_lcd(uint32_t tmr) {
  String result = "";

  int day = tmr / 86400;
  tmr = tmr % 86400;
  if (day == 0) {
    result += "00";
  }
  else if (day < 10) {
    result += "0";
    result += day;
  }
  else {
    result += day;
  }
  result += "д ";

  int hour = tmr / 3600;
  tmr = tmr % 3600;
  if (hour == 0) {
    result += "00";
  }
  else if (hour < 10) {
    result += "0";
    result += hour;
  }
  else {
    result += hour;
  }
  result += "ч ";

  int minute = tmr / 60;
  tmr = tmr % 60;
  if (minute == 0) {
    result += "00";
  }
  else if (minute < 10) {
    result += "0";
    result += minute;
  }
  else {
    result += minute;
  }
  result += "m ";

  int second = tmr;
  if (second == 0) {
    result += "00";
  }
  else if (second < 10) {
    result += "0";
    result += second;
  }
  else {
    result += second;
  }
  result += "с";

  return result;
}

void print_new_value(int value, int x, int y) {
  lcd.setCursor(x-1, y);
  if (value < 10) {
    lcd.print(0, DEC);
  }
  lcd.print(value, DEC);
  lcd.setCursor(x, y);
} 

void save_poliv() {
  poliv_time = 0;
  poliv_time += poliv_time_day * 86400;
  poliv_time += poliv_time_hour * 3600;
  poliv_time += poliv_time_minutes * 60;
  poliv_time += poliv_time_seconds;
  next_time_start_pump = getCurrentUnixTime() + poliv_time;
  SavePolivTime();

  poliv_duration = 0;
  poliv_duration += poliv_duration_day * 86400;
  poliv_duration += poliv_duration_hour * 3600;
  poliv_duration += poliv_duration_minutes * 60;
  poliv_duration += poliv_duration_seconds;
  poliv_duration *= 1000;
  tmr_poliv_duration = millis();
  SavePolivDuration();
}