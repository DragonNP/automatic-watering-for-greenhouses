#include <EEPROM.h>

#define EEPROM_ADDRESS_POLIV 0
#define EEPROM_ADDRESS_POLIV_TIME 2
#define EEPROM_ADDRESS_POLIV_DURATION 8
#define EEPROM_ADDRESS_TEMP_FOR_POLIV_DURATION 14
#define EEPROM_ADDRESS_TIME_FOR_START_PUMP 20

void SetupEEPROM() {
  if (EEPROM.read(EEPROM_ADDRESS_POLIV) != 255) {
    EEPROM.get(EEPROM_ADDRESS_POLIV, poliv);
  }
  else {
    EEPROM.put(EEPROM_ADDRESS_POLIV, poliv);
  }

  if (EEPROM.read(EEPROM_ADDRESS_POLIV_TIME) != 255) {
    EEPROM.get(EEPROM_ADDRESS_POLIV_TIME, poliv_time);
  }
  else {
    EEPROM.put(EEPROM_ADDRESS_POLIV_TIME, poliv_time);
  }

  if (EEPROM.read(EEPROM_ADDRESS_POLIV_DURATION) != 255) {
    EEPROM.get(EEPROM_ADDRESS_POLIV_DURATION, poliv_duration);
  }
  else {
    EEPROM.put(EEPROM_ADDRESS_POLIV_DURATION, poliv_duration);
  }

  if (EEPROM.read(EEPROM_ADDRESS_TEMP_FOR_POLIV_DURATION) != 255) {
    EEPROM.get(EEPROM_ADDRESS_TEMP_FOR_POLIV_DURATION, temp_water_for_run_pump);
  }
  else {
    EEPROM.put(EEPROM_ADDRESS_TEMP_FOR_POLIV_DURATION, temp_water_for_run_pump);
  }

  if (EEPROM.read(EEPROM_ADDRESS_TIME_FOR_START_PUMP) != 255) {
    EEPROM.get(EEPROM_ADDRESS_TIME_FOR_START_PUMP, next_time_start_pump);
  }
  else {
    next_time_start_pump = getCurrentUnixTime() + poliv_time;
    EEPROM.put(EEPROM_ADDRESS_TIME_FOR_START_PUMP, next_time_start_pump);
  }
}

void save_poliv_state() {
  EEPROM.put(EEPROM_ADDRESS_POLIV, poliv);
}

void SavePolivTime() {
  saveNextTimeForStartPump();
  EEPROM.put(EEPROM_ADDRESS_POLIV_TIME, poliv_time);
}

void SavePolivDuration() {
  EEPROM.put(EEPROM_ADDRESS_POLIV_DURATION, poliv_duration);
}

void saveTempWaterForRunPump() {
  EEPROM.put(EEPROM_ADDRESS_TEMP_FOR_POLIV_DURATION, temp_water_for_run_pump);
}

void saveNextTimeForStartPump() {
  EEPROM.put(EEPROM_ADDRESS_TIME_FOR_START_PUMP, next_time_start_pump);
}