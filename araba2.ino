/*  Arduino DC Motor Control   *** reader code ***
    www.kayisimuhendisi.com
*/
#define enA 10
#define in1 6
#define in2 7

#define enB 12
#define in3 5
#define in4 4


//#define button 4
int rotDirection = 0;
int pressed = false;
void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);


 pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);


   digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  Serial.begin(9600);
}
void loop() {

if(Serial.available()>0) //if there is serial 

{
int deger[5] ={0,0,0,0,0};  // this is my buffer  since i expect 5 values from serial. 
//sender side  reads adc and sends that values with xbee (radio module) also same logic with bluetooth ..
//incoming data is like this   { # ,1 ,0 ,2, 3}   


deger[0] =readByte();   //i read just 1 byte and stops reading . this is very important or arduino will get confused.. 

  while (deger[0]!=35)  // countinue reading 1 byte until if incoming data equals to " # "  .
  { 
 deger[0] =readByte();
 
  }

//Serial.readBytes(deger, 4);

  deger[1] =readByte();   //now we reach start point of incoming packet. let me read 1 more . 
  deger[2] =readByte();
  deger[3] =readByte();
  deger[4] =readByte();   
//all the data has been read . yummy : )


// now i need to convert these digits to the real  numbers. 

  int number =deger[1]*1000   + (deger[2]*100 )  +  deger[3]*10   + deger[4];
//now i have my real values is in "number" 

 
  int pwmOutput = map(number, 0, 1023, 0 , 255); // Map the potentiometer value from 0 to 255
//mapping it to 255 so i can drive pwm with it  

//this part for debugging in case st goes wrong 
//Serial.print(deger[1]);
//Serial.print("-");
//Serial.print(deger[2]);
//Serial.print("-");
//Serial.print(deger[3]);
//Serial.print("-");
//Serial.print(deger[4]);
//Serial.print("-");
//Serial.write(pwmOutput);


  
  analogWrite(enA, pwmOutput); // Send PWM signal to L298N Enable pin


    analogWrite(enB, pwmOutput); // Send PWM signal to L298N Enable pin



//
//if(pwmOutput<125)
//{
// 
//pwmOutput=255-pwmOutput;
// digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);
//
//
//   
//    digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);
//
//}
    

    digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);


   
    digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   
//    rotDirection = 1;
  // delay(10);
  digitalWrite(15, HIGH);
   delay(10);                       // wait for a second
  digitalWrite(15, LOW);    // turn the LED off by making the voltage LOW
 
   
   
}
}


int readByte() {
   while (true) {
     if (Serial.available() > 0) {
     return Serial.read(); 
   }
 }
}
  
//  // Read button - Debounce
//  if (digitalRead(button) == true) {
//    pressed = !pressed;
//  }
//  while (digitalRead(button) == true);
//  delay(20);
//  // If button is pressed - change rotation direction
//  if (pressed == true  & rotDirection == 0) {
//    digitalWrite(in1, HIGH);
//    digitalWrite(in2, LOW);
//    rotDirection = 1;
//    delay(20);
//  }
//  // If button is pressed - change rotation direction
//  if (pressed == false & rotDirection == 1) {
//    digitalWrite(in1, LOW);
//    digitalWrite(in2, HIGH);
//    rotDirection = 0;
//    delay(20);
//  }
//}
