// CONST - Serveix per guardar valors fixos que NO poden canviar. 
// S'utilitza per definir pins de components o valors constants.
// Aquest exemple fa parpadejar un LED connectat al pin 2


const int PIN_LED = 2;

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  digitalWrite(PIN_LED, HIGH);  // Encén el LED
  delay(1000);                  // Espera 1 segon
  digitalWrite(PIN_LED, LOW);   // Apaga el LED
  delay(1000);                  // Espera 1 segon
}


// INT - Serveix per guardar nombres sencers (sense decimals).
// S'utilitza per comptadors, iteracions i valors que canvien.
// Aquest exemple compta de 0 a infinit i mostra el valor per pantalla


int comptador = 0;  // Comença des de 0

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(comptador);  // Mostra el comptador
  comptador++;               // Augmenta el comptador en 1
  delay(1000);               // Espera 1 segon
}




// LONG - Serveix per guardar nombres sencers molt grans.
// S'utilitza especialment per funcions de temps com millis().
// Aquest exemple mostra el temps en mil·lisegons des que es va encendre l'ESP32


long tempsActual;  // Guarda el temps actual

void setup() {
  Serial.begin(115200);
}

void loop() {
  tempsActual = millis();      // Obte el temps actual en ms
  Serial.println(tempsActual); // Mostra el temps
  delay(1000);                 // Espera 1 segon
}


// FLOAT - Serveix per guardar nombres amb decimals.
// S'utilitza per valors de sensors, càlculs precisos i mesures.
// Aquest exemple simula la lectura d'un sensor de temperatura


float temperatura = 20.5;  // Temperatura inicial

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  temperatura = temperatura + 0.5;  // Augmenta la temperatura 0.5 graus
  delay(1000);                      // Espera 1 segon
}



// CHAR - Serveix per guardar un sol caràcter (lletra, número o símbol).
// S'utilitza per treballar amb text caràcter per caràcter.
// Aquest exemple mostra una lletra diferent cada segon


char lletra = 'A';  // Comença amb la lletra A

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.println(lletra);  // Mostra la lletra actual
  lletra++;               // Passa a la següent lletra de l'abecedari
  delay(1000);            // Espera 1 segon
}


// BOOL - Serveix per guardar valors de veritat (true o false).
// S'utilitza per controlar estats com encès/apagat, obert/tancat.
// Aquest exemple alterna l'estat d'un LED entre encès i apagat


bool ledEncès = false;    // Estat inicial del LED
const int PIN_LED = 2;    // Pin del LED

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  ledEncès = !ledEncès;           // Inverteix l'estat del LED
  digitalWrite(PIN_LED, ledEncès); // Aplica l'estat al LED
  delay(1000);                    // Espera 1 segon
}