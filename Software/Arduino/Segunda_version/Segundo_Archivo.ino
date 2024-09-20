#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPL2qbE5mH7_"
#define BLYNK_TEMPLATE_NAME "Controlador ESP32"
#define BLYNK_AUTH_TOKEN "mN4bNeIndCw3U4QgGJuRuXGg4Im2fbhZ"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Configuración Wi-Fi
char ssid[] = "Estudiantes";
char pass[] = "educar_2018";

// Pines para controlar los colores RGB de la cinta LED
const int redPin = 17;   // Pin para el canal rojo
const int greenPin = 23; // Pin para el canal verde
const int bluePin = 19;  // Pin para el canal azul

// Variables para controlar el estado de los LEDs
bool ledsOn = false;   // Variable para encender/apagar los LEDs
int redValue = 0;      // Valor del color rojo (0 a 255)
int greenValue = 0;    // Valor del color verde (0 a 255)
int blueValue = 0;     // Valor del color azul (0 a 255)

void setup() {
  Serial.begin(115200);

  // Configuración de los pines de los LEDs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Conectar a Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Inicializar los LEDs apagados
  analogWrite(redPin, 0);
  analogWrite(greenPin, 0);
  analogWrite(bluePin, 0);
}

// Función para controlar el encendido y apagado de los LEDs
BLYNK_WRITE(V0) {
  ledsOn = param.asInt(); // Valor del botón (1 o 0)
  if (!ledsOn) {
    // Apagar todos los LEDs si el botón está en "off"
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  } else {
    // Encender los LEDs con los valores actuales
    setColor();
  }
}

// Función para ajustar el valor del color rojo
BLYNK_WRITE(V1) {
  redValue = param.asInt(); // Valor del slider (0 a 255)
  if (ledsOn) {
    setColor(); // Actualiza el color si los LEDs están encendidos
  }
}

// Función para ajustar el valor del color verde
BLYNK_WRITE(V2) {
  greenValue = param.asInt(); // Valor del slider (0 a 255)
  if (ledsOn) {
    setColor();
  }
}

// Función para ajustar el valor del color azul
BLYNK_WRITE(V3) {
  blueValue = param.asInt(); // Valor del slider (0 a 255)
  if (ledsOn) {
    setColor();
  }
}

// Función para aplicar los colores a los LEDs
void setColor() {
  analogWrite(redPin, redValue);   // Ajusta el valor del canal rojo
  analogWrite(greenPin, greenValue); // Ajusta el valor del canal verde
  analogWrite(bluePin, blueValue);  // Ajusta el valor del canal azul
}

void loop() {
  Blynk.run(); // Mantener la conexión con Blynk
}