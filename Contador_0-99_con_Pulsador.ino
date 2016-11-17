int A=13;
int B=12;
int C=11;
int D=10;
int decenas=9;
int unidades=8;
int valor_decena;
int valor_unidad;
int contador=0;

int boton = 7;                  // pulsador conectado al pin 7 
int tiempoAntirebote=12;        // para que lea correctamente el estado del boton 

int cuenta=0;                   // cuenta las veces presionamos el boton
int estadoBoton;
int estadoBotonAnterior;

boolean antirebote(int pin) {   // boolean es todo valor que puede tener dos posibles valores 
 
  int i=0;
  boolean estado;         // guarda el estado del pulsador
  boolean estadoAnterior;  // guarda el último estado del botón  


  do {                           //similar al for, el do se ejecunta siempre y cuando se cumpla la condicion de while
  estado = digitalRead(pin);
  if (estado != estadoAnterior) {  //comparamos el estado actual con el anterior 
    i=0;                     // reiniciamos el contador 
    estadoAnterior=estado;
       }
  else {
  i=i+1;                 // aumenta el contador en 1
  }
  delay(1);
        
  }
  while (i<tiempoAntirebote);
   return estado;      // retorna el estado si el boton esta siendo presionado

  }

  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   // comunicación de datos digitales que nos permite establecer transferencia de información entre varios dispositivos
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(unidades,OUTPUT);
  pinMode(decenas,OUTPUT);
  pinMode(boton,INPUT);
  

}

void contador_display(int numero){
    switch(numero){

   case 0:  
  //0
   digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
    break;
    case 1:
  //1
   digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
    break;
    case 2:
  //2
   digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
    break;
    case 3:
  //3
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
    break;
    case 4:
  
  //4
   digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
    break;
    case 5:
  //5
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
    break;
    case 6:
  //6
  digitalWrite(A,LOW);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
    break;
    case 7:
  //7
  digitalWrite(A,HIGH);
  digitalWrite(B,HIGH);
  digitalWrite(C,HIGH);
  digitalWrite(D,LOW);
    break;
    case 8:
  //8
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);
    break;
    case 9:
  //9
  digitalWrite(A,HIGH);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,HIGH);

    }
}

void loop() {
  // put your main code here, to run repeatedly:
  estadoBoton = digitalRead(boton);       // leemos el estado del boton 

if (estadoBoton != estadoBotonAnterior) {  // si hay cambio con el estado anterior 

   if(antirebote(boton)) {                  // se revisa si esta siendo presionado el boton y si lo está 
    cuenta++;                          // se aumenta la cuenta 
    if (cuenta > 99){
       cuenta = 0;
       }
  
     }
   }

   estadoBotonAnterior= estadoBoton;      // se guarda el estado del boton 
 
      valor_decena=cuenta/10;   // obtener las decenas del numero del valor de pulsaciones
      valor_unidad=cuenta-(valor_decena*10); // obtener unidad del numero cuenta 
      digitalWrite(unidades,HIGH);
      digitalWrite(decenas,LOW);
      //imprimir dato
      contador_display(valor_unidad);
      delay(100);
      digitalWrite(unidades,LOW);
      digitalWrite(decenas,HIGH);
      //imprimir dato
      contador_display(valor_decena);
      delay(100);
      
      
  

}



