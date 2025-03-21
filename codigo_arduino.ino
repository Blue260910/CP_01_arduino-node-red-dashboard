#include <Servo.h>
#include <DHT.h>
#include <ArduinoJson.h>

// Definir pinos dos sensores
#define DHT_PIN 2         // Pino do sensor DHT11
#define LDR_PIN A2        // Sensor LDR para luminosidade

// Pino do Servo Motor
#define SERVO_PIN 13

// Definir tipo de sensor e inicializar
#define DHT_TYPE DHT11
DHT dht(DHT_PIN, DHT_TYPE);

// Definição dos ângulos para o servo motor
const int angle1 = 0;     // Comando '1'
const int angle2 = 90;    // Comando '2'
const int angle3 = 180;   // Comando '3'

// Intervalo de leitura dos sensores (3000 ms)
unsigned long previousMillis = 0;
const long interval = 3000;

Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(SERVO_PIN);
  myservo.write(angle2); // Posição inicial do servo (90°)
  
  dht.begin(); // Inicializa o sensor DHT11
}

void loop() {
  unsigned long currentMillis = millis();

  // Leitura dos sensores a cada 3000ms
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Leitura do DHT11 (Temperatura e Umidade)
    float tempC = dht.readTemperature();   // Temperatura em °C
    float tempF = dht.readTemperature(true);  // Temperatura em °F
    float humidity = dht.readHumidity();   // Umidade em %

    // Leitura do sensor LDR (luminosidade)
    int ldrReading = analogRead(LDR_PIN);

    // Verifica se a leitura do DHT11 foi bem-sucedida
    if (isnan(tempC) || isnan(humidity)) {
      Serial.println("{\"error\":\"Falha na leitura do DHT11\"}");
    } else {
      // Criar documento JSON
      StaticJsonDocument<200> doc;
      doc["tempF"] = tempF;
      doc["humidity"] = humidity;
      doc["ldr"] = ldrReading;

      // Converter JSON para string e enviar via Serial
      String jsonString;
      serializeJson(doc, jsonString);
      Serial.println(jsonString);
    }
  }

  // Controle do Servo Motor via comandos seriais
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      myservo.write(angle1);
      Serial.println("{\"servo\":\"0 graus\"}");
    }
    else if (command == '2') {
      myservo.write(angle2);
      Serial.println("{\"servo\":\"90 graus\"}");
    }
    else if (command == '3') {
      myservo.write(angle3);
      Serial.println("{\"servo\":\"180 graus\"}");
    }
  }
}
