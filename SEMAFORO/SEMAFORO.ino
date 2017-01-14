#define ledVerde 11
#define ledAmarelo 12
#define ledVermelho 13
#define ledVerde_2 7
#define ledVermelho_2 8
#define botao 2

boolean jaPressionado = false;
int tempoTravessia = 5000;
int segundos = 3000;

void setup(){
  Serial.begin(9600);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVermelho_2, OUTPUT);
  pinMode(ledVerde_2, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  digitalWrite(ledVerde_2, LOW);
  digitalWrite(ledVermelho_2, HIGH);
}

void acionarLedVerde(){
  digitalWrite(ledVerde, HIGH);
  delay(segundos);
  digitalWrite(ledVerde, LOW);
}

void acionarLedAmarelo(){
  digitalWrite(ledAmarelo, HIGH);
  delay(segundos);
  digitalWrite(ledAmarelo, LOW);
}

void acionarLedVermelho(){
  digitalWrite(ledVermelho, HIGH);
  delay(segundos);
  digitalWrite(ledVermelho, LOW);
}

void realizarTravessia(){
  acionarLedAmarelo();
  acionarLedVermelho();
  digitalWrite(ledVermelho_2, LOW);
  digitalWrite(ledVerde_2, HIGH);
  delay(tempoTravessia);
  for (int x = 0; x < 10; x++) {
    digitalWrite(ledVerde_2, HIGH);
    delay(250);
    digitalWrite(ledVerde_2, LOW);
    delay(250);
  }
  digitalWrite(ledVermelho_2, HIGH);
  jaPressionado = true;
}

void loop(){ 
  acionarLedVermelho();
  acionarLedVerde();
  acionarLedAmarelo();
  int estadoBotao = digitalRead(botao);
  Serial.println(estadoBotao);
  //Verifica se o botao foi pressionado.
  if(estadoBotao == LOW && !jaPressionado){
    realizarTravessia();
  }
  if(jaPressionado){
    int i = 0;
    while (i < 10) {
        acionarLedVermelho();
        acionarLedVerde();
        acionarLedAmarelo();
    }
    jaPressionado = false;
  }
}
