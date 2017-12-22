/*  Arduino DC Motor Control - PWM L298N  -*****sender code *** 
    by Enes Kuzucu, www.kayisimuhendisi.com
*/
   int digit_1000;
   int digit_100;
   int digit_10;
   int digit_1;
   char isaret;  //sign of data 
char my_array[5];
void parse_to_digits(int number);  //function which convert real numbers to digits and 


void setup() {
 Serial.begin(9600);
}
void loop() {

 int potValue = analogRead(A0); // Read potentiometer value
 
   parse_to_digits(potValue); 

   //my packet is like thia  #1023 #1020 #506  
    Serial.write(35);   // #
    Serial.write (digit_1000);  //first digit
    Serial.write (digit_100);     
    Serial.write (digit_10);
    Serial.write (digit_1); 
 
    delay(200);
}
  
  
void parse_to_digits(int number)
{

  /********
   * 
   * int digit_1000;
   int digit_100;
   int digit_10;
   int digit_1;
   these values must been declared as global variables. 
   * 
   * 
   * 
   */

if(number<0)
number=-1*number;   //take absolute of it  , not neccesary for adc values 


int number_3digits;
int number_2digits;
int number_1digits;
int mod2;
int mod1;
int mod3;


//here is the math calculations . actually  each of the block'S third line are not neccesaryy but doesnt hurt no body. 

/*************************************calculate 1000  digit ************************************/
  mod1=number%1000; //564
  digit_1000=(number-mod1)/1000 ;  //4. digit   1
  number_3digits =(number-(1000*digit_1000))  ;    // 564 

 /*************************************calculate 100  digit ************************************/
  mod2=number_3digits % 100;  //  64
  digit_100=(  number_3digits-mod2   )/100;   // 3. digit   5
 number_2digits =(number_3digits-(100*digit_100)) ;    //2. hane digit_10iz digit_10ayı


 /*************************************calculate 10 digit ************************************/

mod3=number_2digits % 10;  //63
digit_10=(  number_2digits-mod3   )/10 ;   //2. hane
number_1digits= (number_2digits-(10*digit_10))  ;  //ı  

 /*************************************calculate 1  digit ************************************/
digit_1=number_1digits;
  
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
