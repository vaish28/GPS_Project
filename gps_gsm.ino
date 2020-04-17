#include <SoftwareSerial.h>
#include<TinyGPS++.h>


SoftwareSerial gsm(8,9);
TinyGPSPlus gps ;

void setup()
{
  Serial.begin(9600);
  gsm.begin(9600);
 
 
}

void loop()
{
   while(Serial.available())
   {
        gps.encode(Serial.read());
        if (gps.location.isUpdated())
        {  
         
          gsm.println("AT+CMGF=1");
          delay(1000);
          gsm.println("AT+CMGS=\"+91xxxxxxxxxx\"\r");
          delay(1000);
          String link = "http://www.google.com/maps/place/" + String(gps.location.lat(),6) + "," + String(gps.location.lng(),6) ;
          gsm.println(link);
          gsm.println((char)26);
          delay(6000);
        }
           
   

  }

}
