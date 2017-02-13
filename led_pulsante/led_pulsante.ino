#define led 3

float seno;
int valor;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {  

  for(int x = 0; x < 180; x++){
    seno = sin(x * (PI/180));
    valor = int(seno * 255);
    analogWrite(led, valor);
    delay(25);
  }
  
}
