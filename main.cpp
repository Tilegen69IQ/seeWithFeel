#include <Arduino.h>
#define TRIG_PIN 5   // Пин TRIG на D5 (GPIO5)
#define ECHO_PIN 18  // Пин ECHO на D18 (GPIO18)

long duration;
float distance_cm;

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // Отправляем ультразвуковой импульс
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Считываем время отклика
  duration = pulseIn(ECHO_PIN, HIGH);

  // Вычисляем расстояние (в сантиметрах)
  distance_cm = duration * 0.0343 / 2;

  // Выводим результат
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  delay(500);
}
