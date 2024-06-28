#include <BluetoothSerial.h>

// Configuración de los pines de los LEDs
#define VERDE_LED_PIN 13
#define ROJO_LED_PIN 19
#define AZUL_LED_PIN 17

BluetoothSerial SerialBT;
String inputString = "";

void setup() {
  // Inicialización de los pines de los LEDs como salida
  pinMode(VERDE_LED_PIN, OUTPUT);
  pinMode(ROJO_LED_PIN, OUTPUT);
  pinMode(AZUL_LED_PIN, OUTPUT);
  
  // Apagar todos los LEDs al inicio
  digitalWrite(VERDE_LED_PIN, LOW);
  digitalWrite(ROJO_LED_PIN, LOW);
  digitalWrite(AZUL_LED_PIN, LOW);

  // Inicialización de Bluetooth
  Serial.begin(115200);
  SerialBT.begin("ESP32_LED_Controlador"); // Nombre del dispositivo Bluetooth
  Serial.println("El dispositivo Bluetooth está listo para emparejarse.");
}

void loop() {
 

    digitalWrite(VERDE_LED_PIN, HIGH);
    digitalWrite(ROJO_LED_PIN, HIGH);
    digitalWrite(AZUL_LED_PIN, HIGH);
    delay(3000);
    digitalWrite(VERDE_LED_PIN, LOW);
    digitalWrite(ROJO_LED_PIN, LOW);
    digitalWrite(AZUL_LED_PIN, LOW);
    delay(3000);
   
   
}
