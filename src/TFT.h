#ifndef TFT_H
#define TFT_H

#include <TFT_eSPI.h>

#define speedColor 0xffff
#define rangeColor 0x1657
#define BtempColor 0xf504
#define MtempColor 0xf104
#define bgColor    0x0000
#define chrgColor  0x2f4e

void setup_screen(uint8_t rotation = 1);

void update_screen_values(uint8_t speed = 99,
                          uint8_t throttle = 100,
                          uint8_t batterySOC = 0,
                          uint16_t range = 0);

void update_screen_warnings(bool charging = false,
                            bool Btemp_warning = true,
                            bool Mtemp_warning = true,
                            bool BMS_connected = false,
                            bool WiFi_connected = false);

#endif                                            