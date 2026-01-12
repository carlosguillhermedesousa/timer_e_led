#include <Ds1302.h> //Biblioteca RTC DS1302
#define CLKpin 5 //Pino CLK
#define DATpin 6 //Pino DAT
#define RSTpin 7 //Pino RST

//Objeto rtc do tipo DS1302 - Parâmetros (pino RST, pino CLK, pino DAT)
Ds1302 rtc(RSTpin, CLKpin, DATpin);

const static char* DiasdaSemana[] = { "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado", "Domingo" };

int led = 2;
int botao = 4;

bool dataHoraAtualizada = false;

int estadoLed = LOW;
int ultimoBotao = LOW;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT);

  Serial.begin(9600);
  rtc.init(); //Inicializa o rtc

  // Ajuste inicial da data/hora (faça uma vez, depois comente estas linhas)
  Ds1302::DateTime dt;
  dt.year = 25;     // ano 2025 → biblioteca usa dois dígitos
  dt.month = 12;    // mês (1–12)
  dt.day = 2;       // dia (1–31)
  dt.hour = 16;     // hora (0–23)
  dt.minute = 28;   // minuto (0–59)
  dt.second = 0;    // segundo (0–59)
  dt.dow = 2;       // dia da semana (1=Segunda, 7=Domingo)
  rtc.setDateTime(&dt);  // grava no RTC
}

void loop() {
  Ds1302::DateTime now;
  rtc.getDateTime(&now);

  int leitura = digitalRead(botao);
  // Monta a string com data e hora
  String dataHora = String(now.day) + "/" + 
                    String(now.month) + "/" + 
                    String(2000 + now.year) + " " +
                    String(now.hour) + ":" +
                    String(now.minute) + ":" +
                    String(now.second);

  // Detecta mudança de estado do botão (bordo de subida)
  if (leitura == HIGH && ultimoBotao == LOW) {
    estadoLed = !estadoLed;          // Alterna o LED
    digitalWrite(led, estadoLed);
    delay(200);  
    if (estadoLed == HIGH) {
    Serial.println("Led Ligado! "+dataHora);
  } else {
    Serial.println("Led Desligado! "+dataHora);
  }               
  }

  if(Serial.available()>0){
    String comando = Serial.readStringUntil('\n'); // lê até ENTER
    comando.trim(); // remove espaços e quebras de linha


    if (comando.equalsIgnoreCase("ligar")){
      estadoLed = HIGH;
      digitalWrite(led, estadoLed);
      Serial.println("LED Ligado "+dataHora);
    } else if (comando.equalsIgnoreCase("desligar")){
      estadoLed = LOW;
      digitalWrite(led, estadoLed);
      Serial.println("LED Desligado "+dataHora);
    } 
    else if (comando.startsWith("atualiza")) {
      if(!dataHoraAtualizada){
      int ano, mes, dia, hora, minuto, segundo;
      sscanf(comando.c_str(), "atualiza %d %d %d %d %d %d", 
             &ano, &mes, &dia, &hora, &minuto, &segundo);
      atualizaHora(ano, mes, dia, hora, minuto, segundo);      
      }  
    }else {
      Serial.println("Comando desconhecido. "+dataHora);
    }
  }
  /*
  if(Serial.available()>0){
    char comando = Serial.read();
    if (comando == '1'){
        estadoLed= HIGH;
      digitalWrite(led, HIGH);
      	Serial.println("Led Ligado! "+dataHora);
              }

    else if (comando == '0') {        // Comando para desligar
      estadoLed = LOW;
      digitalWrite(led, LOW);
      Serial.println("Led Desligado! "+dataHora);
    }
  }*/
      
      
  // Agora sim: verifica o estado REAL do LED
  

  ultimoBotao = leitura;             // Atualiza estado do botão
}

void atualizaHora(int ano, int mes, int dia, int hora, int minuto, int segundo) {
  Ds1302::DateTime dt;   
  dt.year   = ano % 100;   // biblioteca usa apenas 2 dígitos
  dt.month  = mes;
  dt.day    = dia;
  dt.hour   = hora;
  dt.minute = minuto;
  dt.second = segundo;
  dt.dow    = 1;           // ajuste conforme necessário

  rtc.setDateTime(&dt); 

  // Recalcula dataHora após atualizar
  Ds1302::DateTime now;
  rtc.getDateTime(&now);

  String dataHora = String(now.day) + "/" + 
                    String(now.month) + "/" + 
                    String(2000 + now.year) + " " +
                    String(now.hour) + ":" +
                    String(now.minute) + ":" +
                    String(now.second);

  dataHoraAtualizada=true;

  Serial.println("Hora atualizada! " + dataHora);
} 
