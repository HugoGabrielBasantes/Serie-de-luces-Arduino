
int sw_1=6; // inicializacion variable
int sw_2=7; // inicializacion variable
void setup() {
  // put your setup code here, to run once:
  
pinMode(sw_1,INPUT); // configuracion de las variables como entradas 
pinMode(sw_2,INPUT); // 
}
//////////////////////////////
void luces_1(){
  int contador;                               // definicion de la variable contador
  int i=0;                                    // variable contador i 
  int n;                                      // variable n
  int num_ale=0;                              // variable contador numero aleatorio
  int leds[6]={8,9,10,11,12,13};              // definicion del vector leds 
  //////////////////////////
  
 if(digitalRead(sw_1)==HIGH && digitalRead (sw_2)== LOW)  // condicion de reconocimiento de las entradas de los switchs
 {
  num_ale=random(10);   // guardar el valor aleatrorio en la variable num_ale entre el 0 al 10 
 
  for (;i<num_ale;i++){ // for repetitivo del juego
    
    for (contador=0;contador <6;contador++) { n=contador%2;   if (n==0){pinMode(leds[contador],OUTPUT);digitalWrite(leds[contador],HIGH);delay(200);}}// poner 5v ,encender numeros pares 
    for (contador=6;contador >=0;contador--){ n=contador%2;   if(n>0){pinMode(leds[contador],OUTPUT);digitalWrite(leds[contador],HIGH);delay(100);}}// encender impares
    for (contador=0;contador <6;contador++) { n=contador%2;   if (n==0){pinMode(leds[contador],OUTPUT);digitalWrite(leds[contador],LOW);delay(200);}}// poner 0V ,apagar numeros pares
    for (contador=6;contador >=0;contador--){ n=contador%2;   if(n>0){pinMode(leds[contador],OUTPUT);digitalWrite(leds[contador],LOW);delay(100);}}// apagar numeros impares
  delay(200);
  contador =0;
  }//cierre for repetitivo
 }// cierre if
}// cierre del metodo luces_1 ()

void luces_2(){
  // definicion de variables y contadores y vectores 
  //////////////////
  int j;
  int i=0;
  int num_ale=0;
  int leds [3]={8,9,10};
  int leds2[3]={13,12,11};
///////////////////////

 if(digitalRead(sw_1)==LOW && digitalRead (sw_2)== HIGH) { // condicion de reconocimiento de las entradas de los switchs
  
  num_ale=random(10);  // guardar el valor aleatrorio en la variable num_ale entre el 0 al 10 
  
  for(;i<num_ale;i++){ // for repetidor del juego 
          
     for ( j=0;j<3;j++)  
         { pinMode(leds[j],OUTPUT);pinMode(leds2[j],OUTPUT);digitalWrite(leds[j],HIGH);digitalWrite(leds2[j],HIGH);delay(150);
         pinMode(leds[j],OUTPUT);pinMode(leds2[j],OUTPUT);digitalWrite(leds[j],LOW);digitalWrite(leds2[j],LOW);delay(200);
         }  
      for (j=2;j>=0;j--)
        {
         pinMode(leds[j],OUTPUT);pinMode(leds2[j],OUTPUT);digitalWrite(leds[j],HIGH);digitalWrite(leds2[j],HIGH);delay(150);
         pinMode(leds[j],OUTPUT);pinMode(leds2[j],OUTPUT);digitalWrite(leds[j],LOW);digitalWrite(leds2[j],LOW);delay(200);
        }
    j=0;
     }// for repetitivo 
    }// if
   }// cierre del metodo luces_2 ()
   
void loop() {
    // put your main code here, to run repeatedly:
   luces_1();
   luces_2();
    
}
