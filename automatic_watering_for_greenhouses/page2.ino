uint8_t position_corsor = 1;

void ShowPage2() {
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Kaждый:");
  lcd.setCursor(0,1);
  lcd.print(format_time_for_lcd(poliv_time));
  lcd.setCursor(0,2);
  lcd.print("Ha npoтяжeнuu:");
  lcd.setCursor(0,3);
  lcd.print(format_time_for_lcd(poliv_duration / 1000));
}

void ClickPage2() {
  if (!edit_mode) {
    lcd.setCursor(1, 1);
    lcd.cursor();
    lcd.blink();

    edit_mode = true;
    position_corsor = 1;
  }
  else if (position_corsor == 8) {
    lcd.noBlink();
    lcd.noCursor();

    edit_mode = false;
  }
  else if (position_corsor == 1) {
    lcd.setCursor(5, 1);
    position_corsor++;
  }
  else if (position_corsor == 2) {
    lcd.setCursor(9, 1);
    position_corsor++;
  }
  else if (position_corsor == 3) {
    lcd.setCursor(13, 1);
    position_corsor++;
  }
  else if (position_corsor == 4) {
    lcd.setCursor(1, 3);
    position_corsor++;
  }
  else if (position_corsor == 5) {
    lcd.setCursor(5, 3);
    position_corsor++;
  }
  else if (position_corsor == 6) {
    lcd.setCursor(9, 3);
    position_corsor++;
  }
  else if (position_corsor == 7) {
    lcd.setCursor(13, 3);
    position_corsor++;
  }
}

void RightPage2() {
  if (!edit_mode) return;

  if (position_corsor == 1) {
    poliv_time_day++;
    if (poliv_time_day > 99) {
      poliv_time_day = 0;
    }
    print_new_value(poliv_time_day, 1, 1);
  }
  else if (position_corsor == 2) {
    poliv_time_hour++;
    if (poliv_time_hour > 23) {
      poliv_time_hour = 0;
    }
    print_new_value(poliv_time_hour, 5, 1);
  }
  else if (position_corsor == 3) {
    poliv_time_minutes++;
    if (poliv_time_minutes > 59) {
      poliv_time_minutes = 0;
    }
    print_new_value(poliv_time_minutes, 9, 1);
  }
  else if (position_corsor == 4) {
    poliv_time_seconds++;
    if (poliv_time_seconds > 59) {
      poliv_time_seconds = 0;
    }
    print_new_value(poliv_time_seconds, 13, 1);
  }
  else if (position_corsor == 5) {
    poliv_duration_day++;
    if (poliv_duration_day > 99) {
      poliv_duration_day = 0;
    }
    print_new_value(poliv_duration_day, 1, 3);
  }
  else if (position_corsor == 6) {
    poliv_duration_hour++;
    if (poliv_duration_hour > 23) {
      poliv_duration_hour = 0;
    }
    print_new_value(poliv_duration_hour, 5, 3);
  }
  else if (position_corsor == 7) {
    poliv_duration_minutes++;
    if (poliv_duration_minutes > 59) {
      poliv_duration_minutes = 0;
    }
    print_new_value(poliv_duration_minutes, 9, 3);
  }
  else if (position_corsor == 8) {
    poliv_duration_seconds++;
    if (poliv_duration_seconds > 59) {
      poliv_duration_seconds = 0;
    }
    print_new_value(poliv_duration_seconds, 13, 3);
  }
  save_poliv();
}

void LeftPage2() {
  if (!edit_mode) return;

  if (position_corsor == 1) {
    poliv_time_day--;
    if (poliv_time_day == 255) {
      poliv_time_day = 99;
    }
    print_new_value(poliv_time_day, 1, 1);
  }
  else if (position_corsor == 2) {
    poliv_time_hour--;
    if (poliv_time_hour == 255) {
      poliv_time_hour = 23;
    }
    print_new_value(poliv_time_hour, 5, 1);
  }
  else if (position_corsor == 3) {
    poliv_time_minutes--;
    if (poliv_time_minutes == 255) {
      poliv_time_minutes = 59;
    }
    print_new_value(poliv_time_minutes, 9, 1);
  }
  else if (position_corsor == 4) {
    poliv_time_seconds--;
    if (poliv_time_seconds == 255) {
      poliv_time_seconds = 59;
    }
    print_new_value(poliv_time_seconds, 13, 1);
  }
  else if (position_corsor == 5) {
    poliv_duration_day--;
    if (poliv_duration_day == 255) {
      poliv_duration_day = 99;
    }
    if (poliv_duration_day > 9) {
      lcd.setCursor(0, 3);
    }
    print_new_value(poliv_duration_day, 1, 3);
  }
  else if (position_corsor == 6) {
    poliv_duration_hour--;
    if (poliv_duration_hour == 255) {
      poliv_duration_hour = 23;
    }
    print_new_value(poliv_duration_hour, 5, 3);
  }
  else if (position_corsor == 7) {
    poliv_duration_minutes--;
    if (poliv_duration_minutes == 255) {
      poliv_duration_minutes = 59;
    }
    print_new_value(poliv_duration_minutes, 9, 3);
  }
  else if (position_corsor == 8) {
    poliv_duration_seconds--;
    if (poliv_duration_seconds == 255) {
      poliv_duration_seconds = 59;
    }
    print_new_value(poliv_duration_seconds, 13, 3);
  }

  save_poliv();
}