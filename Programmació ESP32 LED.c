
/*
Project: Blink (El "Hello, World!" dels microcontroladors)
Description: Fa parpellejar un LED connectat al pin 23.
*/

// Definim una constant per al pin on hem connectat el LED
const int LED_PIN = 23;

// Variables configurables per establir el temps desitjat
const int TEMPS_ENCESA = 1000;   
const int TEMPS_APAGAT = 1000;    

// La funció setup() s'executa un cop quan la placa arrenca
void setup() {
  // Configurem el pin del LED com una SORTIDA (OUTPUT)
  pinMode(LED_PIN, OUTPUT);
}

// La funció loop() s'executa contínuament
void loop() {
  digitalWrite(LED_PIN, HIGH);  // Envia 3.3V al pin (encén el LED)
  delay(TEMPS_ENCESA);          // Espera el temps configurat d'encesa
  
  digitalWrite(LED_PIN, LOW);   // Envia 0V al pin (apaga el LED)
  delay(TEMPS_APAGAT);          // Espera el temps configurat d'apagat
}

/*Al final la única diferència respecte al codi original és la substitució 
dels 1000 mil·lisegons dins del delay per el nom de la variable ja establert 
anteriorment amb el codi "const int TEMPS_ENCESA = 1000;", on temps_encesa
és el nom de la variable en aquest cas i 1000 són els mil·lisegons establerts*/
