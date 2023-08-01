#include "DHT.h"

DHT dht(DHT_PIN, DHT11);

void SetupDHT() {
  dht.begin();
}

float* getDataFromDHT() {
  static float data[2];
  float h = dht.readHumidity();    // Измеряем влажность
  float t = dht.readTemperature(); // Измеряем температуру

  if (isnan(h) || isnan(t)) {  // Если чтение не удалось, то заполняем возвращаемый массив нолями
    data[0] = 0.0;
    data[1] = 0.0;
    return data;
  }

  data[0] = t;
  data[1] = h;
  return data;
}