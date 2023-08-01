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