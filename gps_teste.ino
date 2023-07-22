#include <TinyGPS++.h>
#include <SoftwareSerial.h>

#define RXD2 16
#define TXD2 17
 
int GPSBaud = 9600;
 
TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXD2, TXD2);
 
void setup()
{
Serial.begin(9600);
 
gpsSerial.begin(GPSBaud);
}
 
void loop()
{

while (gpsSerial.available() > 0)
if (gps.encode(gpsSerial.read()))
displayInfo();
 

if (millis() > 5000 && gps.charsProcessed() < 10)
{
Serial.println("Sinal GPS não detectado");
while(true);
}
}
 
void displayInfo() 
{
if (gps.location.isValid())
{
Serial.print("Latitude: ");
Serial.println(gps.location.lat(), 6);
Serial.print("Longitude: ");
Serial.println(gps.location.lng(), 6);
 
}
else
{
Serial.println("Sem localização");
}

}