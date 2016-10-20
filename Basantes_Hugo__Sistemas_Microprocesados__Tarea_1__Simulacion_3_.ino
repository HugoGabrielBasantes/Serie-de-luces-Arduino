void setup() {
  // put your setup code here, to run once:
  
// En la serie de luces_1.
// Se ha definido la variable contador.
// Se ha definido el vector leds [14] de 14 elementos.
// la primera sentencia condicional for da valores al contador desde 0 a 13 de uno en uno, además de encender y apagar Respectivamente cada led a medida que incrementa el valor del contador.
// La segunda sentencia for realiza el proceso contrario, es decir va desde 13 hasta 0.

//En la serie de luces_2.
// las dos primeras lineas se repiten de luces_1.
// la primera sentencia permite encender los leds del 14 al 1 de manera descendente y de uno en uno.
// la segunda los apaga de manera ascendente.
// la tercera los enciende de manera ascendiente.
// la cuarta los apaga de manera descendente.

//En la serie de luces_3.
// Ademas de las dos lineas que se repiten de las anteriores series se ha definido una nueva variable n.
// la primera sentencia for da valores al contador de 0 a 13 de uno en uno.
// luego la variable n se utiliza para almacenar la division del contador para 2.
// Tambien se ha utilizado un condicional if para que reconosca los numeros pares es decir n=0 y encender los leds conectados a los pines pares de manera ascendente.
//En la siguiente linea  es un proceso similar pero esta vez se reconoce y enciende los leds impares de manera descendente.
//En la siguiente linea se apaga los pares en forma ascendente y en la ultima se apagan los impares en forma descendente.

}

 void luces_1 () {
   int contador; 
   int leds[14]={0,1,2,3,4,5,6,7,8,9,10,11,12,13};
   for (contador=0;contador<=13;contador ++){pinMode(contador, OUTPUT);digitalWrite (leds[contador], HIGH); delay(200); digitalWrite (leds[contador],LOW); delay (200);}
   for (contador=13;contador>=0;contador --){pinMode(contador, OUTPUT);digitalWrite (leds[contador], HIGH); delay(200); digitalWrite (leds[contador],LOW); delay (200);}
   delay(200);
}

 void luces_2 (){
   int contador;
   int leds[14]={0,1,2,3,4,5,6,7,8,9,10,11,12,13};
   for (contador=13;contador>=0;contador--){pinMode(contador,OUTPUT);digitalWrite(leds[contador],HIGH);delay(100);}
   for (contador=0;contador<14;contador ++){pinMode (contador,OUTPUT);digitalWrite(leds[contador],LOW);delay(200);}
   for (contador=0;contador<14;contador++){ pinMode(contador,OUTPUT);digitalWrite(leds[contador],HIGH);delay(100);}
   for (contador=13;contador>=0;contador--){pinMode(contador,OUTPUT);digitalWrite(leds[contador],LOW);delay(200);}
   delay(200);
}

void luces_3(){
  int contador;
  int n;
  int leds[14]={0,1,2,3,4,5,6,7,8,9,10,11,12,13};
  for (contador=0;contador <13;contador++) { n=contador%2;   if (n==0){pinMode(contador,OUTPUT);digitalWrite(leds[contador],HIGH);delay(200);}}
  for (contador=13;contador >=0;contador--){ n=contador%2;   if(n=!0){pinMode(contador,OUTPUT);digitalWrite(leds[contador],HIGH);delay(100);}}
  for (contador=0;contador <13;contador++) { n=contador%2;   if (n==0){pinMode(contador,OUTPUT);digitalWrite(leds[contador],LOW);delay(200);}}
  for (contador=13;contador >=0;contador--){ n=contador%2;   if(n=!0){pinMode(contador,OUTPUT);digitalWrite(leds[contador],LOW);delay(100);}}
  delay(200);
}
void loop() {
    // put your main code here, to run repeatedly:
    luces_1();
    luces_2();
    luces_3();
}
