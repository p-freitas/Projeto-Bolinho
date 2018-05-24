#include <Ultrasonic.h>
 Ultrasonic ultrassom(8,7); // 7 = cinza 8 = roxorE

// the setup function runs once when you press reset or power the board

int motor11 = 3;
int motor12 = 4;
int motor21 = 5;
int motor22 = 6;
int randNumberAnt = 0;
long distancia;
long randNumber;

int led = 12;

unsigned long time;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(motor11, OUTPUT);
  pinMode(motor12, OUTPUT);
  pinMode(motor21, OUTPUT);
  pinMode(motor22, OUTPUT);
  randomSeed(analogRead(0));
  pinMode(led, OUTPUT);

  Serial.begin(9600); //Habilita Comunicação Serial a uma taxa de 9600 bauds.

}


void loop() {
 sensor();
 

  randNumber = random(8);
  Serial.print(randNumber);
  milliss2();
if(randNumberAnt != randNumber) { 
  sw();
}
randNumberAnt = randNumber;
sw();
}
void frente(){
  digitalWrite(motor11, HIGH);   // movendo motor 1.1 para frente
  digitalWrite(motor21, HIGH);   // movendo motor 2.1 para frente
  digitalWrite(motor12, LOW);    // movendo motor 1.2 para trás
  digitalWrite(motor22, LOW);    // movendo motor 2.2 para trás

  milliss();
  sensor();
 
}

void tras(){
  digitalWrite(motor12, HIGH);   // movendo motor 1.2 para frente
  digitalWrite(motor22, HIGH);   // movendo motor 2.2 para frente
  digitalWrite(motor11, LOW);    // movendo motor 1.1 para trás
  digitalWrite(motor21, LOW);    // movendo motor 2.1 para trás

  milliss();
  sensor();
}

void esquerda(){
  digitalWrite(motor11, HIGH);   // movendo motor 1.1 para frente
  digitalWrite(motor21, LOW);   // movendo motor 2.1 para frente
  digitalWrite(motor12, LOW);    // movendo motor 1.2 para trás
  digitalWrite(motor22, HIGH);    // movendo motor 2.2 para trás

  milliss();
  sensor();
}

void direita(){
  digitalWrite(motor12, HIGH);   // movendo motor 1.2 para frente
  digitalWrite(motor22, LOW);   // movendo motor 2.2 para frente
  digitalWrite(motor11, LOW);    // movendo motor 1.1 para trás
  digitalWrite(motor21, HIGH);    // movendo motor 2.1 para trás

  milliss();
  sensor();
}

 void parar(){
  digitalWrite(motor11, HIGH);
  digitalWrite(motor12, HIGH);
  digitalWrite(motor21, HIGH);
  digitalWrite(motor22, HIGH);
  delay(5000);
}


void milliss(){
  time = millis();
  delay(1000);
   
}

void milliss2(){
  time = millis();
  delay(500);
}
void sensor(){
   
   distancia = ultrassom.Ranging(CM);// ultrassom.Ranging(CM) retorna a distancia em centímetros(CM) ou polegadas(INC)
    if ((distancia <= 3)&& (distancia != 0)){
      Serial.print(distancia); //imprime o valor da variável distancia
      Serial.println("cm");  
      digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
      milliss2();                       // wait for a second
      digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW

      parar();
      milliss2() ;                      
    }
             
   
}
void mov1(){
 frente();
 frente();
 esquerda();
 frente();
 frente();
 direita(); 
 }
void mov2(){
 tras();
 tras();
 direita();
 frente();
 frente();
 direita(); 
 }
void mov3(){
 tras();
 tras();
 direita();
 tras();
 tras();
 esquerda(); 
 }
void mov4(){
 frente();
 frente();
 esquerda();
 tras();
 tras();
 direita(); 
 }
void mov5(){
 frente();
 frente();
 direita();
 esquerda();
 tras();
 tras();
 esquerda();
 esquerda(); 
 }

 void sw(){

   switch(randNumber){
  case 0 :
    frente();
    break;
  case 1 :
    tras();
    break;
  case 2 :
    esquerda();
    break;
  case 3 :
    direita();
    break;
  case 4 :
    frente();
    frente();
    break;
  case 5 :
    tras();
    tras();
    break;
  case 6 :
    esquerda();
    esquerda();
    break;
  case 7 :
    direita();
    direita();
    break;    
 }
 }


