// importa libreria Keypad
#include <Keypad.h>

// define numero de filas
const uint8_t ROWS = 4;

// define numero de columnas
const uint8_t COLS = 4;

// define la distribucion de teclas
char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

// pines correspondientes a las filas
uint8_t colPins[COLS] = { 16, 4, 2, 15 };

// pines correspondientes a las columnas
uint8_t rowPins[ROWS] = { 19, 18, 5, 17 };

// crea objeto con los prametros creados previamente
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// 'pass' guarda la contraseña permanente (empieza vacía)
String pass = "";
// 'input' acumula temporalmente lo que el usuario teclea
String input = "";


void setup() {
  Serial.begin(9600);
}

void loop() {
  // obtiene tecla presionada y asigna a variable
  char key = keypad.getKey();
  
  // comprueba que se haya presionado una tecla
  if (key) {
    // envia a monitor serial la tecla presionada
    Serial.println(key);
    
    // Verifica si el usuario presionó la tecla # (confirmar)
    if (key == '#') {
      // Comprueba si es la primera vez (password está vacía)
      if (pass == "") {
        // PRIMERA VEZ: Guarda lo escrito como nueva contraseña
        pass = input;  // Asigna la entrada actual a la contraseña
        Serial.print("Password establecida: ");
        Serial.println(pass);
      } else {
        // VERIFICACIÓN: Compara entrada con contraseña guardada
        if (input == pass) {
          Serial.println("ACCESO PERMITIDO");
        } else {
          Serial.println("ACCESO DENEGADO");
        }
      }
      // Limpia la entrada para el próximo intento
      input = "";
    } 
    else {
      // Si no es #, agrega la tecla a la entrada acumulada
      input += key;
    }
  }
}