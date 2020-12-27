
#define VELOCIDAD 10 // Tiempo de espera entre cada señal de los pasos.

int MS1 = 2;      // pin MS1 de A4988 a pin 2
int MS2 = 3;      // pin MS2 de A4988 a pin 3
int MS3 = 4;      // pin MS3 de A4988 a pin 4
int RESET = 5;    // pin RESET de A4988 a pin 5
int STEP = 6;     // pin STEP de A4988 a pin 6
int DIR = 7;      // pin DIR de A4988 a pin 7

int PASOS = 96;   //Cantidad de pasos a meter.

void setup() {  
                
  pinMode(MS1, OUTPUT);     // pin 2 como salida
  pinMode(MS2, OUTPUT);     // pin 3 como salida
  pinMode(MS3, OUTPUT);     // pin 4 como salida
  pinMode(RESET, OUTPUT);   // pin 5 como salida
  pinMode(STEP, OUTPUT);    // pin 6 como salida
  pinMode(DIR, OUTPUT);     // pin 7 como salida

}

void loop() {

  digitalWrite(RESET, LOW);       //Mientras reset este en LOW el motor permanecerá apagado.
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(MS3, LOW);         //Configuración paso completo.
  delay(1000);
  digitalWrite(RESET, HIGH);      //Cuando reset se encuentre en HIGH el motor arrancará.
  digitalWrite(DIR, HIGH);        //Giro en un sentido.
    
  for (int i = 0; i<PASOS; i++)   //Ciclo para realizar una vuelta de 360°.
  {
    digitalWrite(STEP, HIGH);    //STEP con valor lógico 1.
    delay(10);                   //10ms
    digitalWrite(STEP, LOW);     //STEP con valor lógico 1. 
    delay(VELOCIDAD);
  } 

  digitalWrite(RESET, LOW);       //Ciclo para realizar una vuelta de 360°.
  delay(1000);
  digitalWrite(RESET, HIGH);      //Cuando reset se encuentre en HIGH el motor arrancará.
  digitalWrite(DIR, LOW);         //Giro en sentido opuesto.

  for (int i = 0; i<PASOS; i++)   //Ciclo para realizar una vuelta de 360°.
  {
    digitalWrite(STEP, HIGH);    //STEP con valor lógico 1.
    delay(10);                   //10ms
    digitalWrite(STEP, LOW);     //STEP con valor lógico 1. 
    delay(VELOCIDAD); 
  }
}
