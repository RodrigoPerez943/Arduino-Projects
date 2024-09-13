#include <Wire.h>
#include <VL53L0X.h>

VL53L0X sensor;

#define LONG_RANGE
#define HIGH_ACCURACY

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  sensor.setTimeout(500); // Configurar el tiempo de espera
  
  if (!sensor.init()) {
    Serial.println("Error al inicializar el sensor VL53L0X");
    while (1);
  }
  
  // Activar modo de largo alcance
  #if defined LONG_RANGE
    sensor.setSignalRateLimit(0.1);  // Reducir el límite de señal
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodPreRange, 18);
    sensor.setVcselPulsePeriod(VL53L0X::VcselPeriodFinalRange, 14);
  #endif

  // Configurar para alta precisión
  #if defined HIGH_ACCURACY
    sensor.setMeasurementTimingBudget(200000);  // Aumentar el tiempo de medición
  #endif
}

void loop() {
  uint16_t distancia = sensor.readRangeSingleMillimeters();
  
  if (sensor.timeoutOccurred()) {
    Serial.println("Error de tiempo de espera");
  } else if (distancia > 2000) {
    Serial.println("Fuera de rango");
  } else {
    Serial.print("Distancia medida: ");
    Serial.print(distancia);
    Serial.println(" mm");
  }

  delay(1000); // Espera entre mediciones
}
