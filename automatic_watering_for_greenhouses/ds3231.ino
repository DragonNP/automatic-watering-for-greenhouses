#include <microDS3231.h>

MicroDS3231 rtc;

void setupDS3231() {
  if (rtc.lostPower()) {
    rtc.setTime(BUILD_SEC, BUILD_MIN, BUILD_HOUR, BUILD_DAY, BUILD_MONTH, BUILD_YEAR);
  }
}

uint32_t getCurrentUnixTime() {
  return rtc.getUnix(3);
}