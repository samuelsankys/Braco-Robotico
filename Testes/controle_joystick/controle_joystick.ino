
int botao = 2; //PINO REFERENTE A LIGAÇÃO NO PINO KEY (EIXO Z)
 
void setup(){
  pinMode (botao, INPUT_PULLUP); //DEFINE A PORTA COMO ENTRADA / "_PULLUP" É PARA ATIVAR O RESISTOR INTERNO
  //DO ARDUINO PARA GARANTIR QUE NÃO EXISTA FLUTUAÇÃO ENTRE 0 (LOW) E 1 (HIGH)
  Serial.begin (9600); //INICIALIZA O MONITOR SERIAL
} 
void loop(){
  int eixo_X= A0; //PINO REFERENTE A LIGAÇÃO DO EIXO X
  int eixo_Y = A1; //PINO REFERENTE A LIGAÇÃO DO EIXO Y
  int acao0 = (analogRead(eixo_X));
 
    if((acao0 < 505)){ //SE LEITURA FOR IGUAL A 0, FAZ
        Serial.println("PARA ESQUERDA"); //IMPRIME O TEXTO NO MONITOR SERIAL
        Serial.println(acao0);
    }
     if((analogRead(eixo_X)) > 510){ //SE LEITURA FOR IGUAL A 1023, FAZ
        Serial.println("PARA DIREITA"); //IMPRIME O TEXTO NO MONITOR SERIAL
        Serial.println((analogRead(eixo_X)));
    }
     if((analogRead(eixo_Y)) < 513){ //SE LEITURA FOR IGUAL A 0, FAZ
        Serial.println("CIMA"); //IMPRIME O TEXTO NO MONITOR SERIAL
        Serial.println((analogRead(eixo_Y)));
      }
      if((analogRead(eixo_Y)) > 517){ //SE LEITURA FOR IGUAL A 1023, FAZ
        Serial.println("BAIXO"); //IMPRIME O TEXTO NO MONITOR SERIAL
        Serial.println((analogRead(eixo_Y)));
      }
      if(digitalRead(botao) == LOW){ //SE LEITURA FOR IGUAL A HIGH, FAZ
         Serial.println("BOTAO PRESSIONADO"); //IMPRIME O TEXTO NO MONITOR SERIAL
      }  
     
      
    
    delay(50); //INTERVALO DE 500 MILISSEGUNDOS
}
