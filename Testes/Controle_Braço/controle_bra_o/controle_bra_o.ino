#include <Servo.h>

//Servo motorBase;
//Servo motor1;
//Servo motor2;
//Servo motor3;
//Servo motor4;
//Servo motorGarra;

Servo motor[6];

int anguloMt[6];


int botao = 2; //PINO REFERENTE A LIGAÇÃO NO PINO KEY (EIXO Z)
int val=90;
int i = 0;
 
void setup(){
  // A0 deve ser Horizontal
  anguloMt[0]= 80;
  anguloMt[1]= 25;
  anguloMt[2]= 45;
  anguloMt[3]= 80;
  anguloMt[4]= 80;
  anguloMt[5]= 20;
  motor[0].attach(3); // MOTOR BASE
  motor[1].attach(5); // MOTOR 01
  motor[2].attach(6); // MOTOR 02
  motor[3].attach(9); // MOTOR 03
 // motor[4].attach(10); // MOTOR 04 (GIRO DA GARRA)
  motor[5].attach(11); // MOTOR GARRA
  
  Serial.begin (9600); //INICIALIZA O MONITOR SERIAL
} 


void loop() {
  // pinos pwm disponíveis no arduino => 3, 5, 6, 9, 10, 11

  // MOTOR BASE
   if((analogRead(A0) < 400) and (anguloMt[0] < 170)){ //SE LEITURA FOR IGUAL A 0, FAZ
        anguloMt[0]++;
        delay(30);
    }
     if((analogRead(A0) > 600) and (anguloMt[0] > 11)){ //SE LEITURA FOR IGUAL A 1023, FAZ
        anguloMt[0]--;
        delay(30);
    }

    //MOTOR 01
   if((analogRead(A1) < 400) and (anguloMt[1] < 50)){ //SE LEITURA FOR IGUAL A 0, FAZ
        anguloMt[1]++;
        delay(30);
    }
     if((analogRead(A1) > 600) and (anguloMt[1] > 0)){ //SE LEITURA FOR IGUAL A 1023, FAZ
        anguloMt[1]--;
        delay(30);
    }

    // MOTOR 02
     if((analogRead(A2) < 400) and (anguloMt[2] < 90)){ //SE LEITURA FOR IGUAL A 0, FAZ
        anguloMt[2]++;
        delay(30);
    }
     if((analogRead(A2) > 600) and (anguloMt[2] > 0)){ //SE LEITURA FOR IGUAL A 1023, FAZ
        anguloMt[2]--;
        delay(30);
    }

    //MOTOR 03
     if((analogRead(A3) < 400) and (anguloMt[3] < 180)){ //SE LEITURA FOR IGUAL A 0, FAZ
        anguloMt[3]++;
        delay(30);
    }
     if((analogRead(A3) > 600) and (anguloMt[3] > 20)){ //SE LEITURA FOR IGUAL A 1023, FAZ
        anguloMt[3]--;
        delay(30);
    }
/*
    // MOTOR 04 (ROTAÇÃO DA GARRA)
     if((analogRead(A4) < 400) and (anguloMt[4] < 180)){ //SE LEITURA FOR IGUAL A 0, FAZ
        anguloMt[4]++;
        delay(10);
    }
     if((analogRead(A4) > 600) and (anguloMt[4] > 0)){ //SE LEITURA FOR IGUAL A 1023, FAZ
        anguloMt[4]--;
        delay(10);
    }
    */
    // MOTOR GARRA
    /*
     if((analogRead(A5) < 50) and (anguloMt[5] < 46)){ //SE LEITURA FOR IGUAL A 0, FAZ
        anguloMt[5]++;
        delay(80);
    }
     if((analogRead(A5) > 900) and (anguloMt[5] > 0)){ //SE LEITURA FOR IGUAL A 1023, FAZ
        anguloMt[5]--;
        delay(80);
    }
    */
    motor[5].write( map( analogRead( A5 ), 0, 1023, 0, 46 ) ); 
  for(i=0; i<5; i++ ){
     motor[i].write(anguloMt[i]);
  }

 // motor[0].write( map( analogRead( A0 ), 0, 1023, 11, 170 ) ); 
 // motor[1].write( map( analogRead( A1 ), 0, 1023, 0, 50 ) ); 
 // motor[2].write( map( analogRead( A2 ), 0, 1023, 0, 90 ) ); 
 // motor[3].write( map( analogRead( A3 ), 0, 1023, 20, 180 ) ); 
 // motor[4].write( map( analogRead( A4 ), 0, 1023, 0, 180 ) ); 
 // motor[5].write( map( analogRead( A5 ), 0, 1023, 0, 46 ) ); 
  
}
