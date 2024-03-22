// Inclusion de librerias
#include <U8g2lib.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN 23     // Digital pin connected to the DHT sensor

// Uncomment the type of sensor in use:
//#define DHTTYPE    DHT11     // DHT 11
#define DHTTYPE    DHT11     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

/* ----------------------------------------------------------------------------------------------------- */

// Definicion de constructores y variables globales

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

/* ----------------------------------------------------------------------------------------------------- */
void  printBMP_OLED(void );


void setup() 
{
  Serial.begin(115200);
  dht.begin();
  u8g2.begin();
}
  
void loop() 
{
 printBMP_OLED();
    delay(2000);
}

void printBMP_OLED(void)
{
    int temp1;
    char stringtemp1[5];	
	  u8g2.clearBuffer();          // clear the internal memory
    temp1 = dht.readTemperature();

    u8g2.setFont(u8g2_font_ncenB14_tr); // choose a suitable font
    //u8g2.drawStr(15,15,"ALARMA!!");  // write something to the internal memory
    //u8g2.setFont(u8g2_font_ncenB08_tr); // choose a suitable font
    u8g2.drawStr(0,30,"T1: ");  // write something to the internal memory
    sprintf (stringtemp1, "%d" , temp1); ///convierto el valor float a string
    u8g2.drawStr(17,30,stringtemp1);
    u8g2.drawStr(50,30,"C");
            // transfer internal memory to the display

u8g2.sendBuffer();
}