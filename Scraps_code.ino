#include <Servo.h>    // use a set of functions to control the servo
#include <LiquidCrystal.h>   
#include <time.h>

  int trashData[] = {1710,1970,2320,4270,6280,7570,8900,10540,11150,11300};
  int yearData[] = {1960,1970,1980,1990,2000,2005,2010,2015,2017,2018};
  int array_length =  sizeof(trashData) / sizeof(trashData[0]);
  int year_length = sizeof(yearData) / sizeof(yearData[0]);
  int servoPositionA;
  int servoPositionB;
  Servo myservo1;
  Servo myservo2;
  Servo myservo3;
  Servo myservo4;
  Servo myservo5;
  Servo myservo6;
  Servo myservo7;
  int servPin1 = 1;
  int servPin2 = 2;
  int servPin3 = 3;
  int servPin4 = 4;
  int servPin5 = 5;
  int servPin6 = 6;
  int servPin7 = 7;
  int starttime;
  int endtime;
  int posAdjust;

  LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

void setup() {
 
  lcd.begin(16, 2);  
  lcd.clear();
  
  myservo1.attach(servPin1);
  myservo2.attach(servPin2);
  myservo3.attach(servPin3);
  myservo4.attach(servPin4);
  myservo5.attach(servPin5);
  myservo6.attach(servPin6);
  myservo7.attach(servPin7);

  Serial.begin(9600);

}


void loop() {
  // counts through each item of the arrays
  for (int i = 0; i < array_length; i++) {
    int waitTime = (1650 - (trashData[i] /10));
    Serial.print("delay: ");
    Serial.println(waitTime);

    //add/subtract scale of like 15-6 extra degrees of movement based on wait time calculation
    int posAdjust = waitTime/80;

    Serial.print("pos adjust:");
    Serial.println(posAdjust);
    
    
//loops for 8 second intervals
starttime = millis();
endtime = starttime;
while ((endtime - starttime) <=8000) // do this loop for up to 8000mS
{
    Serial.println(starttime);
    Serial.println(endtime);
        
    //Lcd show year 
        lcd.clear();

        lcd.setCursor(0,0);
        lcd.print("      ");
        lcd.print(yearData[i]);

        lcd.setCursor(0,1);
        if(i < 7){
         lcd.print("  ");
        }
        else{
          lcd.print(" ");
        }
        lcd.print(trashData[i]);
        lcd.print("000 tons");
     
      
      
    //movement
    servoPositionA = (25 + posAdjust);
    servoPositionB = (165 - posAdjust); 
    myservo1.write(servoPositionA);
    //delay(random(0,8));
    myservo2.write(servoPositionB);
    //delay(random(0,8));
    myservo3.write(servoPositionA);
    //delay(random(0,8));
    myservo4.write(servoPositionB);
    //delay(random(0,8));
    myservo5.write(servoPositionA);
    //delay(random(0,8));
    myservo6.write(servoPositionB);
    //delay(random(0,8));
    myservo7.write(servoPositionA);
    
    delay(waitTime);  
    myservo1.write(servoPositionB);
    //delay(random(0,8));
    myservo2.write(servoPositionA);
    //delay(random(0,8));
    myservo3.write(servoPositionB);
    //delay(random(0,8));
    myservo4.write(servoPositionA);
    //delay(random(0,8));
    myservo5.write(servoPositionB);
    //delay(random(0,8));
    myservo6.write(servoPositionA);
    //delay(random(0,8));
    myservo7.write(servoPositionB);
    delay(waitTime);
    
    endtime = millis();
}
  }
  }
