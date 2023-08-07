void SetupPump() {
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, HIGH);
}

uint32_t GetRemainingPoliv() {
  return next_time_start_pump - getCurrentUnixTime();
}

void CheckStartPoliv() {
  if (!poliv || started_poliv) { return; }
  
  if (getCurrentUnixTime() >= next_time_start_pump && GetTempFromDallas() >= temp_water_for_run_pump) {
    digitalWrite(PUMP_PIN, LOW);

    tmr_poliv_duration = millis();
    started_poliv = true;
  }
}

void CheckStopPoliv() {
  if (!poliv || !started_poliv) { return; }

  if (millis() - tmr_poliv_duration >= poliv_duration) {
    digitalWrite(PUMP_PIN, HIGH);

    next_time_start_pump = getCurrentUnixTime() + poliv_time;
    started_poliv = false;
    
    saveNextTimeForStartPump();
  }
}

short getStatePump() {
  // Возвращает: 0 - поливает, 1 - время полива еще не наступило, 2 - Пора поливать, но вода холодная, 3 - неизвестная ошибка

  if (!started_poliv) {
    uint32_t current_time = getCurrentUnixTime();

    if (current_time >= next_time_start_pump && GetTempFromDallas() < temp_water_for_run_pump)
      return 2;
    else if (current_time < next_time_start_pump)
      return 1;
    else
      return 3;
  }
  return 0;
}