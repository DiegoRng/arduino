#define btn 2
#define led 13

void setup(){
  Serial.begin(9600);
  pinMode(btn, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop(){

  //Atribui o valor de btn a val_btn
  int val_btn = digitalRead(btn);
  //Imprime o valor de val_btn na console
  Serial.println(val_btn);

  if(val_btn == HIGH) {
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
}

