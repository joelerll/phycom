#define CUSTOM_SETTINGS
#define INCLUDE_TWITTER_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#define INCLUDE_CAMERA_SHIELD
#include <stdlib.h>
#include <string.h>
#include <OneSheeld.h>
#define TRIGG 9 
#define ECHO 8
#define LED_6 6

int Distancia()
{
  long tiempo;
  digitalWrite(TRIGG,LOW);
  delayMicroseconds(5);
  digitalWrite(TRIGG, HIGH); 
  delayMicroseconds(10);
  tiempo = pulseIn(ECHO, HIGH);
  return int(0.017*tiempo);
}


void setup() {
  OneSheeld.begin();
  pinMode(LED_6, OUTPUT);
  pinMode(TRIGG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(A0, INPUT);
  //Serial.begin(9600);
}


void loop() {
  int soundDetectedVal = analogRead (A0);
  if ((Distancia() < 10 && soundDetectedVal >= 120)) {
    digitalWrite(6, HIGH);
    //Twitter.tweet("I'm tweeting from @Arduino via @1Sheeld!");
    //Serial.print("Twitteado");
    Camera.rearCapture();
    OneSheeld.delay(1000);
    Twitter.tweetLastPicture("@joelerll #1ShieldPrueba #");
    //Twitter.tweet(post);
    //Facebook.post(post);
    OneSheeld.delay(10000);
    Terminal.println("tweet enviado");
  }
   digitalWrite(6, LOW);
  Terminal.println("no foto");
}
