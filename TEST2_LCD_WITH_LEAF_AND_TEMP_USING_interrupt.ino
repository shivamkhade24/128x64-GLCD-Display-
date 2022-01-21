
#include <glcd.h>
#include "glcd.h" 
#include <DHT.h>
#include "fonts/allFonts.h"   
#define DHTPIN 12
#define DHTTYPE DHT22 
DHT dht(DHTPIN,DHTTYPE);
volatile boolean BUTTON = false;
  
int Temp;

void setup() 
{
pinMode(2,INPUT);
// Initialize the GLCD
GLCD.Init();
GLCD.SelectFont(System5x7, BLACK);
// Initialize the DHT
dht.begin();
Serial.begin(9600);
attachInterrupt(0,LEAFVALUE,RISING);

}

void loop() 
{ 
  int Humi = dht.readHumidity();
  int Temp = dht.readTemperature();
  Serial.println(Temp);
  Serial.println(Humi);
  TEMP();
  delay(1000);
  // GLCD.ClearScreen();

}

void TEMP(){
   int Humi = dht.readHumidity();
   Temp = dht.readTemperature();
  GLCD.CursorTo(8, 0);
  GLCD.print("WEATHER :");
  GLCD.CursorTo(8,1);
  GLCD.print(Temp);
  GLCD.print("C");
  GLCD.print("/");
  GLCD.print(Humi);
  GLCD.print("%");
}

void LEAF(){

//  if(BUTTON)
//  {
//   TEMP();
//  LEAFVALUE();
//  BUTTON = false;
//  
//  }
//  
//  else
//  {
//  TEMP();
//  LEAFVALUE();
//  BUTTON = true;
//  }


 TEMP();
 LEAFVALUE();








}

void LEAFVALUE()
{
  GLCD.ClearScreen();
  int L = Temp-2;
  GLCD.CursorTo(8,3);
  GLCD.print("LEAF TEMP");
  GLCD.CursorTo(9,4);
  GLCD.print(L);
  GLCD.print("C"); 
}
