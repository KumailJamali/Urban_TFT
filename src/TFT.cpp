#include "TFT.h"
//#include "FreeSans9pt7b.h"
#include "Org_01.h"

TFT_eSPI tft = TFT_eSPI();
char SOCbuf[4];

void setup_screen(uint8_t rotation){
  tft.begin();
  tft.setRotation(rotation);
  tft.fillScreen(bgColor);
  tft.setTextSize(1);
  tft.setFreeFont(&FreeSans9pt7b);
  tft.setTextDatum(BL_DATUM);
  tft.setTextColor(speedColor);
  tft.drawString("KMPH", 230, 142);
  tft.setTextColor(rangeColor);
  tft.drawString("KM", 278, 221);
  tft.fillSmoothRoundRect(216, 224, 91, 3, 1, rangeColor, bgColor);
}

void update_screen_values(uint8_t speed, uint8_t throttle, uint8_t batterySOC, uint16_t range){
  tft.setTextDatum(BC_DATUM);
  tft.setFreeFont(&Org_01);
  //speed
  tft.fillRect(80, 75, 147, 68, bgColor);
  tft.setTextSize(13);
  tft.setTextColor(speedColor);
  tft.drawNumber(speed, 160, 142);
  //Throttle bar
  tft.fillRect(6, 6, 308, 25, bgColor);
  tft.fillRect(6, 6, map(throttle, 0, 100, 0, 308), 25, (throttle >= 75)? 0xe269 : 0xdf85);
  //SOC  
  tft.drawSmoothArc(60, 210, 52, 50, 45, 315, 0x94b2, bgColor, true);  // SOC background arc
  tft.drawSmoothArc(60, 210, 52, 50, 45, map(batterySOC, 0, 100, 45, 315), (batterySOC <= 20)? 0xe269 : 0x365b, true);  //SOC arc
  tft.setTextSize(4);
  sprintf(SOCbuf, "%d%%", batterySOC);
  tft.fillRect(25, 183, 76, 44, bgColor);
  tft.setTextColor((batterySOC <= 20)? 0xe269 : 0x365b);
  tft.drawString(SOCbuf, 62, 216);
  //Range
  tft.setTextColor(rangeColor);
  tft.fillRect(215, 202, 61, 20, bgColor);
  tft.drawNumber(range, 244, 221);
}

void update_screen_warnings(bool charging, bool Btemp_warning, bool Mtemp_warning, bool BMS_connected, bool WiFi_connected){
  //Battery charging
  tft.drawSmoothArc(60, 210, 55, 54, 315, 45, charging? 0x94b2 : bgColor, bgColor, true);  //charging arc
  //Battery Temp warning
  tft.fillSmoothCircle(21, 57, 11, Btemp_warning? BtempColor : bgColor, bgColor);
  //Motor Temp warning
  tft.fillSmoothCircle(53, 57, 11, Mtemp_warning? MtempColor : bgColor, bgColor);
  //BMS Connectivity indication
  tft.fillSmoothCircle(298, 57, 6, BMS_connected? 0x053a : bgColor, bgColor);
  //WiFi Connectivity indication
  tft.fillSmoothCircle(280, 57, 6, WiFi_connected? 0x06a0 : bgColor, bgColor);
}