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

void ShowPage2() {
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Kaждый:");
  lcd.setCursor(0,1);
  lcd.print(format_time_for_lcd(poliv_time));
  lcd.setCursor(0,2);
  lcd.print("Ha npoтяжeнuu:");
  lcd.setCursor(0,3);
  lcd.print(format_time_for_lcd(poliv_duration));
}

uint8_t position_corsor = 1;
void UpdatePage2() {
  check_encoder_for_page2();
  if (enc.click()) {
    if (millis() - btn_press > 130) {
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

      btn_press = millis();
    }
  }
}

void check_encoder_for_page2() {
  if (!edit_mode) { return; }
  
  if (enc.right()) {
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
  else if (enc.left()) {
    if (position_corsor == 1) {
      poliv_time_day--;
      if (poliv_time_day < 0) {
        poliv_time_day = 99;
      }
      print_new_value(poliv_time_day, 1, 1);
    }
    else if (position_corsor == 2) {
      poliv_time_hour--;
      if (poliv_time_hour < 0) {
        poliv_time_hour = 23;
      }
      print_new_value(poliv_time_hour, 5, 1);
    }
    else if (position_corsor == 3) {
      poliv_time_minutes--;
      if (poliv_time_minutes < 0) {
        poliv_time_minutes = 59;
      }
      print_new_value(poliv_time_minutes, 9, 1);
    }
    else if (position_corsor == 4) {
      poliv_time_seconds--;
      if (poliv_time_seconds < 0) {
        poliv_time_seconds = 59;
      }
      print_new_value(poliv_time_seconds, 13, 1);
    }
    else if (position_corsor == 5) {
      poliv_duration_day--;
      if (poliv_duration_day < 0) {
        poliv_duration_day = 99;
      }
      if (poliv_duration_day > 9) {
        lcd.setCursor(0, 3);
      }
      print_new_value(poliv_duration_day, 1, 3);
    }
    else if (position_corsor == 6) {
      poliv_duration_hour--;
      if (poliv_duration_hour < 0) {
        poliv_duration_hour = 23;
      }
      print_new_value(poliv_duration_hour, 5, 3);
    }
    else if (position_corsor == 7) {
      poliv_duration_minutes--;
      if (poliv_duration_minutes < 0) {
        poliv_duration_minutes = 59;
      }
      print_new_value(poliv_duration_minutes, 9, 3);
    }
    else if (position_corsor == 8) {
      poliv_duration_seconds--;
      if (poliv_duration_seconds < 0) {
        poliv_duration_seconds = 59;
      }
      print_new_value(poliv_duration_seconds, 13, 3);
    }

    save_poliv();
  }
}

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

void UpdatePage3() {
  check_encoder_for_page3();
  if (enc.click()) {
    if (millis() - btn_press > 130) {
      if (!edit_mode) {
        if (poliv) {
          lcd.setCursor(10,2);
        }
        else {
          lcd.setCursor(11,2);
        }
        lcd.cursor();
        lcd.blink();

        edit_mode = true;
      }
      else {
        lcd.noBlink();
        lcd.noCursor();
        edit_mode = false;
      }
      btn_press = millis();
    }
  }
}

void check_encoder_for_page3() {
  if (!edit_mode) { return; }
  
  if (enc.turn()) {
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
}