#include <Adafruit_GFX.h>
#include <Adafruit_ST7789.h>
#include <SPI.h>
#include <Fonts/FreeSansBold12pt7b.h>

#define TFT_SCLK 21
#define TFT_MOSI 20
#define TFT_RST 10
#define TFT_DC 8
#define TFT_CS 7
#define TFT_BL 6

//these will def have to change once I get everything
#define ALARM_PIN 1
#define TIMER_PIN 2
#define LESS_PIN 3
#define LIGHT_PIN 4
#define MORE_PIN 5

#define ST77XX_LIGHTPURPLE 0x862F

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

// for the clock
int hours = 11;
int minutes = 11;
int seconds = 0;
unsigned long lastTick = 0;

// for the timer
bool timerOn = false; 
int minutesOnTimer = 5;
unsigned long countingMillis = 0;
unsigned long lastTimerTick = 0;

//for the alarm
int alarmHours = 12;
int alarmMinutes = 0;
bool alarmOn = false; 
bool alarmBuzz = false; 


//this will display the time

void setup() {
  Serial.begin(9600);
  
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  tft.init(284, 76);
  
  tft.setRotation(2);
  tft.setTextColor(ST77XX_LIGHTPURPLE);

  tft.fillScreen(ST77XX_BLACK);
  tft.setCursor(10, 20);
  tft.setTextSize(3);
  tft.setFont(&FreeSansBold12pt7b); // yayyy i added my own font tho I think I will need to find a new one 
  char buf[6];
  sprintf(buf, "%02d:%02d", hours, minutes);
  tft.print(buf); // yaya printing

  lastTick = millis();
}

void loop() {
  
  if (millis() - lastTick >= 1000) {
    lastTick = millis();
    seconds++;
    if (seconds >= 60) {
      seconds = 0;
      minutes++;
      if (minutes >= 60) {
        minutes = 0;
        hours++;
        if (hours >= 24) hours = 0; // so as soon as the clock hit 25, it should hit to 0 or 12am 
      }
    }

   //the screen should change every second hopefully!
    if (seconds == 0) {
      tft.fillScreen(ST77XX_BLACK);
      tft.setCursor(10, 20);
      tft.setTextSize(3);
      char buf[6];
      sprintf(buf, "%02d:%02d", hours, minutes);
      tft.print(buf);
    }
  }

 //int for each button
  int TIMERButton = digitalRead(TIMER_PIN);
  int moreButton = digitalRead(MORE_PIN);
  int lessButton = digitalRead(LESS_PIN);

    
//this is the timer

  if (TIMERButton == LOW) {
    
      if (!timerOn) {
        timerOn = true;
        countingMillis = minutesOnTimer * 60000; 
        lastTimerTick = millis();
        Serial.println("timer started!");
      } else {
        timerOn = false;
        Serial.println("timer stopped!");
      }
    }
  
   // this is for before the timer starts - so they see what options that
    if (!timerOn) {
      if (moreButton == LOW) {
        minutesOnTimer += 5;
        Serial.print("timer set: ");
        Serial.print(minutesOnTimer);
        Serial.println(" minutes");
      } 
      else if (lessButton == LOW) {
        minutesOnTimer = max(0, minutesOnTimer - 5); // since the first option u get is 5 - this will make sure that it doesnt hit the negatives
        Serial.print("timer set: ");
        Serial.print(minutesOnTimer);
        Serial.println(" minutes");
      }
  }
  
  if (timerOn && countingMillis > 0) {
    if (millis() - lastTimerTick >= 1000) {
      lastTimerTick = millis();
      countingMillis -= 1000;
      Serial.print("time remaining: ");
      Serial.print(countingMillis / 60000);
      Serial.println(" minutes");

      if (countingMillis <= 0) {
        timerOn = false;
        Serial.println("timer is done!");
      }
    }

  }

// this is the alarm 

 int ALARMButton = digitalRead(ALARM_PIN);

if  alarmOn && hours == alarmHours && minutes == alarmMinutes && seconds == 0) {
   alarmBuzz = true;
    Serial.println("WAKE UP!!!"); 
}

if (ALARMButton == LOW) {
    if (AlarmBuzz) {
       alarmBuzz = false; 
        Serial.println("alarm is done!");
    } else {
       alarmOn =  alarmOn; 
    }
}

}









