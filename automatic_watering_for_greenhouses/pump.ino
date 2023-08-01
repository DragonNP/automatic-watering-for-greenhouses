void SetupPump() {
  pinMode(PUMP_PIN, OUTPUT);
    digitalWrite(PUMP_PIN, HIGH);
}

uint32_t GetRemainingPoliv() {
  if (!started_poliv) {
    return poliv_time - (millis() - tmr_poliv_time);
  }
  return 1;
}

void CheckStartPoliv() {
  if (!poliv || started_poliv) { return; }
  
  if (millis() - tmr_poliv_time >= poliv_time && GetTempFromDallas() >= temp_water_for_run_pump) {
    digitalWrite(PUMP_PIN, LOW);
    tmr_poliv_duration = millis();
    started_poliv = true;
  }
}

void CheckStopPoliv() {
  if (!poliv || !started_poliv) { return; }

  if (millis() - tmr_poliv_duration >= poliv_duration) {
    digitalWrite(PUMP_PIN, HIGH);

    tmr_poliv_time = millis();
    started_poliv = false;
  }
}

short getStatePump() {
  // Возвращает: 0 - поливает, 1 - время полива еще не наступило, 2 - Пора поливать, но вода холодная, 3 - неизвестная ошибка

  if (!started_poliv)
    if (millis() - tmr_poliv_time >= poliv_time && GetTempFromDallas() < temp_water_for_run_pump)
      return 2;
    else if (millis() - tmr_poliv_time < poliv_time)
      return 1;
    else
      return 3;
  else
    return 0;
}