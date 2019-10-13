#define LED 7
#define BUT1_Incrementa 8
#define BUT2_Decrementa 9
byte status=0;
long int Start_Time=0, End_Time, periodo=1000, tempo, Incrementa=0, Decrementa=0;
boolean Blink=true;


void alternancia(){                          //função de oscilação do timer
  if(status==1){
    periodo+=250;
  }
  else if((status==2)&&(periodo>200)){
    periodo-=250;
  }
  else if(((status==3)&&((millis()-tempo)<500))){
    digitalWrite(LED, LOW);
  }
}

void pisca(){
  tempo=millis();
  if(Blink==true){
    if((tempo-Start_Time)>=periodo){
      digitalWrite(LED, HIGH); Start_Time=tempo; Blink=false;
    }
  }
  else{
    if((tempo-Start_Time)>=periodo){
      Start_Time=tempo; digitalWrite(LED, LOW); Blink=true;
     }
  }
}

void setup() {

  pinMode(LED, OUTPUT);
  pinMode(BUT1_Incrementa, INPUT);
  pinMode(BUT2_Decrementa, INPUT);
}


void loop() {
 
  pisca();
  if( (digitalRead(BUT2_Decrementa)==0) && (digitalRead(BUT1_Incrementa)==0) ){
    status=3;
    alternancia();
    status=0;
    while(1);
  }
  if(Incrementa){
    if(digitalRead(BUT1_Incrementa)){
      Incrementa=0;
    }
  }
  else if(digitalRead(BUT1_Incrementa)==LOW){
    Incrementa=1;
    status=1;
    alternancia(); 
  }
  
  if(Decrementa){
    if(digitalRead(BUT2_Decrementa)){
      Decrementa=0;
    }
  }
  else if(digitalRead(BUT2_Decrementa)==LOW){
    Decrementa=1;
    status=2;
    alternancia(); 
  }
   
}
