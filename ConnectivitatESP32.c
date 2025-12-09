#include <WiFi.h>
#include <HTTPClient.h>
 

const String endpoint = "http://api.openweathermap.org/data/2.5/weather?q=Lisbon,pt&APPID=";
const String key = "dff65ece7cd56e5609a961090c1815a5";



 
void setup() {
 
  Serial.begin(115200);
 
  WiFi.begin("Wokwi-GUEST", "", 6);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting WiFi..");
  }
 
  Serial.println("WiFi connected");
 
}
 
void loop() {
 
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
 
    http.begin(endpoint + key); //Specify the URL
    int httpCode = http.GET();  //Make the request
 
    if (httpCode > 0) { //Check for the returning code
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); //Free the resources
  }
 
  delay(30000);
 
}