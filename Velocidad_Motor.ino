int A=13;
int B=12;
int C=11;
int D=10;
int decenas=7;
int unidades=8;
int valor_decena;
int valor_unidad;
int contador=0;
int motor=9;
double valor_cad=0;

void setup() {
  // put your setup code here, to run once:
 
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(unidades,OUTPUT);
  pinMode(decenas,OUTPUT);
  pinMode(motor,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
      valor_cad=analogRead(0);  
         
      valor_decena=(valor_cad/10.3)/10;
      valor_unidad=((valor_cad/10.3)-(valor_decena*10));
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
      analogWrite(motor,valor_cad/4);  //% de ciclo util de la sañal 
      delay(1);

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



