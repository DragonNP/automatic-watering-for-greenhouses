#include <microDS18B20.h>

MicroDS18B20<BUCK_TEMP_PIN> dallas;

float GetTempFromDallas() {
  if (dallas.readTemp()) return dallas.getTemp();
  else return 0.0;
}

void requestTempFromDallas() {
  dallas.requestTemp();
}