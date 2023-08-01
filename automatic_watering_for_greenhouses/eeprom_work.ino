#include <EEPROM.h>

#define EEPROM_ADDRESS_POLIV 0
#define EEPROM_ADDRESS_POLIV_TIME 2
#define EEPROM_ADDRESS_POLIV_DURATION 8

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

  ParsePolivData();
}

void SavePoliv() {
  EEPROM.put(EEPROM_ADDRESS_POLIV, poliv);
}

void SavePolivTime() {
  EEPROM.put(EEPROM_ADDRESS_POLIV_TIME, poliv_time);
}

void SavePolivDuration() {
  EEPROM.put(EEPROM_ADDRESS_POLIV_DURATION, poliv_duration);
}

void ParsePolivData() {
  poliv_time_day = poliv_time / 86400 / 1000;
  poliv_time_hour = poliv_time / 3600 / 1000;
  poliv_time_minutes = poliv_time / 60 / 1000;
  poliv_time_seconds = poliv_time / 1000;

  poliv_duration_day = poliv_duration / 86400 / 1000;
  poliv_duration_hour = poliv_duration / 3600 / 1000;
  poliv_duration_minutes = poliv_duration / 60 / 1000;
  poliv_duration_seconds = poliv_duration / 1000;
}