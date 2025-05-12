#include <Arduino.h>
#include <ezTime.h>
#include <internet.h>
#include <LiquidCrystal_I2C.h>
#include <Bounce2.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
Timezone tempo;
Bounce botaoboot = Bounce();

int dia = 0;
int mes = 0;
int ano = 0;
int hora = 0;
int segundos[2] = {0, 0};
int minutos[2] = {0, 0};
int diasemana = 0;
int diaano = 0;
bool formato24h = true;
bool manha = false;

const char *diasemanaTexto[] = {
    "domingo",
    "segunda",
    "terca",
    "quarta",
    "quinta",
    "sexta",
    "sabado"};

const char *mesTexto[] = {
    "jan",
    "fev",
    "mar",
    "abr",
    "mai",
    "jun",
    "jul",
    "ago",
    "set",
    "out",
    "nov",
    "dez"};

void display(void);

void setup()
{
  Serial.begin(9600);
  conectaWiFi();
  tempo.setLocation("America/Sao_Paulo");
  waitForSync();

  dia = tempo.day();
  mes = tempo.month();
  ano = tempo.year();
  hora = formato24h ? tempo.hour() : tempo.hourFormat12();
  minutos[1] = tempo.minute();
  segundos[1] = tempo.second();
  diasemana = tempo.weekday();
  diaano = tempo.dayOfYear();
  manha = tempo.isAM();

  lcd.init();
  lcd.backlight();
}

void loop()
{
  botaoboot.update();
  if (botaoboot.fell())
  {
    formato24h = !formato24h;

    if (formato24h)
    {
      lcd.setCursor(9, 2);
      lcd.printf("%s", manha ? "am" : "pm");
      lcd.setCursor(0, 2);
      lcd.printf("%02d", tempo.hourFormat12());
    }

    else
    {
      lcd.setCursor(9, 2);
      lcd.printf("  ");
      lcd.setCursor(0, 2);
      lcd.printf("%02d", tempo.hour());
    }
  }

  checkWiFi();
  segundos[1] = tempo.second();

  if (segundos[1] != segundos[0])
  {
    lcd.setCursor(6, 2);
    lcd.printf("%02d", segundos[1]);
    segundos[0] = segundos[1];
  }

  if (minutos[0] == 59 && minutos[1] == 0)
  {
    dia = tempo.day();
    mes = tempo.month();
    ano = tempo.year();
    hora = tempo.hour();
    diasemana = tempo.weekday();
    diaano = tempo.dayOfYear();
    manha = tempo.isAM();

    display();
  }

  if (minutos[1] != minutos[0])
  {
    lcd.setCursor(3, 2);
    lcd.printf("%02d", minutos[1]);
    minutos[0] = minutos[1];
  }
}

void display()
{
  lcd.setCursor(0, 0);
  lcd.printf("%02d/%s/%04d", dia, mesTexto[mes - 1], ano);

  // if (dia < 10 )
  //{
  //   lcd.print("0");
  //  lcd.print(dia);
  //  }

  lcd.setCursor(16, 0);
  lcd.printf("%03d", diaano);

  lcd.setCursor(0, 1);
  lcd.print(diasemanaTexto[diasemana - 1]);

  lcd.setCursor(0, 2);
  lcd.printf("%02d:%02d:%02d", hora, minutos[1], segundos[1]);
}

/*
#include <Arduino.h>               // Biblioteca base do Arduino
#include <ezTime.h>                // Biblioteca para controle de data/hora via NTP
#include <internet.h>              // Provavelmente uma biblioteca sua para Wi-Fi
#include <LiquidCrystal_I2C.h>     // Biblioteca para display LCD via I2C
#include <Bounce2.h>               // Biblioteca para debouncing de botões

// Instancia o display LCD no endereço 0x27, com 20 colunas e 4 linhas
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Cria objeto de fuso horário
Timezone tempo;

// Cria objeto para botão com debounce
Bounce botaoboot = Bounce();

// Variáveis para armazenar tempo e data
int dia = 0;
int mes = 0;
int ano = 0;
int hora = 0;
int segundos[2] = {0, 0};  // segundos[0] = anterior, segundos[1] = atual
int minutos[2] = {0, 0};   // mesmos critérios para minutos
int diasemana = 0;
int diaano = 0;

// Controle de formato e turno (manhã/tarde)
bool formato24h = true;
bool manha = false;

// Nomes dos dias da semana
const char *diasemanaTexto[] = {
    "domingo", "segunda", "terca", "quarta", "quinta", "sexta", "sabado"
};

// Abreviações dos meses
const char *mesTexto[] = {
    "jan", "fev", "mar", "abr", "mai", "jun",
    "jul", "ago", "set", "out", "nov", "dez"
};

// Prototipação da função que imprime tudo no display
void display(void);

void setup()
{
  Serial.begin(9600);            // Inicializa porta serial
  conectaWiFi();                 // Conecta ao Wi-Fi (função definida na internet.h)
  tempo.setLocation("America/Sao_Paulo");  // Define fuso horário para SP
  waitForSync();                // Aguarda sincronização do tempo via NTP

  // Captura valores iniciais de data e hora
  dia = tempo.day();
  mes = tempo.month();
  ano = tempo.year();
  hora = formato24h ? tempo.hour() : tempo.hourFormat12();
  minutos[1] = tempo.minute();
  segundos[1] = tempo.second();
  diasemana = tempo.weekday();
  diaano = tempo.dayOfYear();
  manha = tempo.isAM();

  // Inicializa display LCD
  lcd.init();
  lcd.backlight();

  // Inicializa botão BOOT (GPIO 0) com pull-up e debounce de 25ms
  botaoboot.attach(0, INPUT_PULLUP);
  botaoboot.interval(25);
}

void loop()
{
  botaoboot.update();          // Atualiza estado do botão
  if (botaoboot.fell())       // Se botão foi pressionado (borda de descida)
  {
    formato24h = !formato24h; // Alterna entre 12h e 24h

    if (formato24h)            // Se estiver no modo 24h
    {
      lcd.setCursor(9, 2);
      lcd.printf("  ");                        // Apaga "am"/"pm"
      lcd.setCursor(0, 2);
      lcd.printf("%02d", tempo.hour());        // Mostra hora no formato 24h
    }
    else                       // Se estiver no modo 12h
    {
      lcd.setCursor(9, 2);
      lcd.printf("%s", manha ? "am" : "pm");   // Mostra "am" ou "pm"
      lcd.setCursor(0, 2);
      lcd.printf("%02d", tempo.hourFormat12()); // Mostra hora no formato 12h
    }
  }

  checkWiFi();                 // Checa se o Wi-Fi ainda está conectado

  segundos[1] = tempo.second();   // Atualiza valor atual dos segundos

  if (segundos[1] != segundos[0]) // Se o segundo mudou
  {
    lcd.setCursor(6, 2);
    lcd.printf("%02d", segundos[1]); // Atualiza segundos no display
    segundos[0] = segundos[1];       // Armazena valor atual para comparação futura
  }

  if (minutos[0] == 59 && minutos[1] == 0) // Se houve virada de hora
  {
    // Atualiza todos os dados de tempo
    dia = tempo.day();
    mes = tempo.month();
    ano = tempo.year();
    hora = tempo.hour();
    diasemana = tempo.weekday();
    diaano = tempo.dayOfYear();
    manha = tempo.isAM();

    display(); // Reimprime toda a informação no display
  }

  if (minutos[1] != minutos[0]) // Se o minuto mudou
  {
    lcd.setCursor(3, 2);
    lcd.printf("%02d", minutos[1]); // Atualiza minutos no display
    minutos[0] = minutos[1];        // Salva novo valor
  }
}

// Função que imprime data e hora completas no display
void display()
{
  lcd.setCursor(0, 0);
  lcd.printf("%02d/%s/%04d", dia, mesTexto[mes - 1], ano); // Linha 0: data

  lcd.setCursor(16, 0);
  lcd.printf("%03d", diaano); // Dia do ano no canto direito

  lcd.setCursor(0, 1);
  lcd.print(diasemanaTexto[diasemana - 1]); // Linha 1: dia da semana

  lcd.setCursor(0, 2);
  lcd.printf("%02d:%02d:%02d", hora, minutos[1], segundos[1]); // Linha 2: hora completa
}
*/