
int btnArriba = 2;
int btnAbajo  = 3;
int btnPoder1 = 4;
int btnPoder2 = 5;
int a = 6;
int b = 7;
int c = 8;
int d = 9;
int e = 10;
int f = 11;
int g = 12;
int num = Serial.read();
//const int pins [7] = {6,7,8,9,10,11,12};
//                a b c d  e f  g
//                                    //gfedcba   
/*const byte numerosDisplayCatodo[5] = {0b0000110, //1
                              0b1011011,          //2
                              0b1001111,          //3
                              0b1100110,          //4
                              0b1101101,          //5
                              };
*/
void setup() {

  Serial.begin(9600);

  pinMode(btnArriba, INPUT);
  pinMode(btnAbajo,  INPUT);
  pinMode(btnPoder1, INPUT);
  pinMode(btnPoder2, INPUT);
  //for(int i = 0; i < 7; i++){
  //  pinMode(pins[i],INPUT);
  //}

  //enciendeSegmentos(0);
}
void loop() {
  int estadoBtnAr = digitalRead(btnArriba);
  int estadoBtnAb = digitalRead(btnAbajo);
  int estadoBtnPU = digitalRead(btnPoder1);
  int estadoBtnPD = digitalRead(btnPoder2);

  int estadoPot   = analogRead(A0);
  if( estadoPot == 0){

      estadoPot = 0;
    
  }else{
    estadoPot = estadoPot/100;
  }
  int arr[5] = {estadoBtnAr, estadoBtnAb, estadoBtnPU, estadoBtnPD, estadoPot};
  for (int i = 0; i < 5; i++) {
    Serial.print(arr[i]);

  }
  Serial.println();
  //for(int = 0; i <= 5; i++){
  //  enciendeSegmentos(i);
  //  delay(1000)
  //}
  
  if(num == 1){
    
    pinMode(b, INPUT);
    pinMode(c, INPUT);
    delay(1000);
  }
  if(num == 2){
    pinMode(a,INPUT);
    pinMode(b,INPUT);
    pinMode(g,INPUT);
    pinMode(e,INPUT);
    pinMode(d,INPUT);
    delay(1000);
  }
  if(num == 3){
    pinMode(a,INPUT);
    pinMode(b,INPUT);
    pinMode(g,INPUT);
    pinMode(c,INPUT);
    pinMode(d,INPUT);
    delay(1000);
  }
  if(num == 4){
    pinMode(f,INPUT);
    pinMode(g,INPUT);
    pinMode(b,INPUT);
    pinMode(c,INPUT);
    delay(1000);
  }
  if(num == 5){
    pinMode(a,INPUT);
    pinMode(f,INPUT);
    pinMode(g,INPUT);
    pinMode(c,INPUT);
    pinMode(d,INPUT);
    delay(1000);
  }
  delay(1000);
  
} 
