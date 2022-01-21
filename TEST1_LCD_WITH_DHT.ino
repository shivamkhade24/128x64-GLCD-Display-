
#include <glcd.h>
#include "glcd.h" 
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22 

DHT dht(DHTPIN,DHTTYPE);

//
#include<fonts/allFonts.h>

void setup() {
  
// Initialize the GLCD
GLCD.Init();
// Initialize the DHT
dht.begin();
Serial.begin(9600);

}

void loop() {
  int Humi = dht.readHumidity();
  int Temp = dht.readTemperature();
  
Serial.println(Temp);
Serial.println(Humi);

  GLCD.SelectFont(System5x7);
  
  GLCD.CursorTo(8, 0);
  GLCD.print("WEATHER :");
  
  GLCD.CursorTo(8,1);
  GLCD.print(Temp);

  GLCD.print("C");
  GLCD.print("/");
//  GLCD.print("RH :");
  GLCD.print(Humi);
  GLCD.print("%");
  delay(2000);
}
