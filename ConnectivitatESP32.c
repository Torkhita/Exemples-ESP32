#include <WiFi.h>
#include <HTTPClient.h>
#include <time.h>  // <- NUEVO: Para NTP

const String endpoint = "http://api.openweathermap.org/data/2.5/weather?q=Barcelona,es&APPID=";
const String key = "dff65ece7cd56e5609a961090c1815a5"; // ¡Cambia esta clave!

// Configuración NTP - NUEVO
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 3600; // GMT+1 para España
const int daylightOffset_sec = 3600; // Horario de verano

void setup() {
  Serial.begin(115200);
  
  // 1. CONEXIÓN WiFi (igual que antes)
  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting WiFi..");
  }
  Serial.println("WiFi connected");
  
  // 2. CONFIGURACIÓN NTP - NUEVO
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  Serial.println("Configurando hora NTP...");
  
  // Esperar a que NTP sincronice
  delay(2000);
  printLocalTime(); // Muestra la hora obtenida
}

void loop() {
  // Mostrar hora actual antes de cada consulta - NUEVO
  printLocalTime();
  
  // 3. PETICIÓN HTTP 
  if ((WiFi.status() == WL_CONNECTED)) {
    HTTPClient http;
    http.begin(endpoint + key);
    int httpCode = http.GET();
    
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.print("HTTP Code: ");
      Serial.println(httpCode);
      Serial.println("Datos del clima:");
      Serial.println(payload);
    } else {
      Serial.println("Error on HTTP request");
    }
    http.end();
  }
  
  delay(30000); // Espera 30 segundos
}

// FUNCIÓN NUEVA: Obtiene y muestra la hora actual vía NTP
void printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Error obteniendo hora NTP");
    return;
  }
  
  Serial.print("Hora actual (NTP): ");
  Serial.print(timeinfo.tm_hour);
  Serial.print(":");
  Serial.print(timeinfo.tm_min);
  Serial.print(":");
  Serial.println(timeinfo.tm_sec);
}