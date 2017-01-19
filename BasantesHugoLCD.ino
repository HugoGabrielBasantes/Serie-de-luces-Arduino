// UNIVERSIDAD TÉCNICA DEL NORTE 
//           FICA/CIERCOM

// HUGO BASANTES

// SISTEMAS MICROPROCESADOS
// VISUALIZACION EN LCD 

/////////////////////
#include <LiquidCrystal.h>
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
String dato;
int tamano;
int estado = 0;
//////////////////////////
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  attachInterrupt (0, interruptor, RISING); // en el pin 2 cambia de estado BAJO a ALTO con el interruptor
}

void loop() {
  if (estado == 0) {
    if (Serial.available() > 0) {
      lcd.clear ();
      grabarP();
      iniciar();
      Serial.println(" ");
    }
  }
  else {
    lcd.clear();
    estado = estado - 1;
    Serial.println("SISTEMA APAGADO");
    lcd.print("SISTEMA APAGADO");
    Serial.end ();
  }
}
////////////////////

void interruptor () {
  estado = estado + 1;
}
////////////////////

void tiempoEspera () {
  for (; Serial.available () == 0;) {

  }
}
////////////////////

void grabarP () {
  Serial.println ("Ingrese la Palabra");
  tiempoEspera();
  dato = Serial.readString();
  tamano = dato.length();
  lcd.print(dato);
  delay(300);
  lcd.println(" ");
}
////////////////////

void iniciar () {
  Serial.print ( "Digite como visualizar la palabra: A(),B(),C(). ");
  tiempoEspera();
  char opcion = Serial.read();
  int i;
  int j = 0;
  char mensaje[tamano];
  switch (opcion)
  {
    case 'A':
      for (i = tamano; i >= 0; i--)
      {
        lcd.print(dato);
        lcd.setCursor(0, 0);
        lcd.autoscroll();
        lcd.print(" ");
        delay(100);
      }
      lcd.noAutoscroll();
      lcd.clear();
      break;
    case 'B':
      lcd.setCursor(16, 0);
      lcd.print(dato);
      i = 0;
      for (; i < (17 + tamano); i++) {
        lcd.setCursor(16, 0);
        lcd.autoscroll();
        lcd.print(" ");
        delay(100);
      }
      lcd.noAutoscroll();
      lcd.clear();
      break;
    case 'C':
      i = 0;
      dato.toCharArray(mensaje, tamano + 1);
      for (i = tamano; i >= 0; i--) {
        j = 1 - j;
        lcd.setCursor(i, j);
        lcd.print(mensaje[i]);
        delay(200);
        lcd.setCursor(i, j);
        lcd.print('$');
      }
      for (; i < tamano; i++) {
        j = 1 - j;
        lcd.setCursor(i, j);
        lcd.print(mensaje[i]);
        delay(200);
        lcd.setCursor(i, j);
        lcd.print(" ");
      }
      lcd.clear();
      break;
    default:
      Serial.println(" ");
      grabarP();
      break;
  }
}
