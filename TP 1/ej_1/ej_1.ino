// Inclusion de librerias
#include <U8g2lib.h>

/* ----------------------------------------------------------------------------------------------------- */

// Definicion de constructores y variables globales

U8G2_SH1106_128X64_NONAME_F_HW_I2C oled(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

/* ----------------------------------------------------------------------------------------------------- */


void setup() 
{
  Serial.begin(9600);
  Serial.println(F("OLED test"));
  oled.begin();
}

void loop() 
{
  oled.clearBuffer();

  oled.setFont(u8g2_font_ncenB14_tr);
  oled.drawStr(0,15, "Hola Mundo");
  oled.sendBuffer();
  Serial.println("Hola mundo");
  delay(2000);
}
