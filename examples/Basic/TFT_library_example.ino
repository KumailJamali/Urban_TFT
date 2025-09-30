/*
This Sketch uses a locally made TFT library
Uses of functions explained in this example
Library includes 3 functions only.
*/

#include "../TFT.h"

//Sample data
int speed = 23;
int throttle = 75;
int BatterySOC = 83;
int range_kms = 1108;
bool charging = false;
bool Btemp_warning = true;
bool Mtemp_warning = true;
bool BMS_connected = false;
bool WiFi_connected = false;

void setup() {
  setup_screen(1); /*setup function to initialize the TFT display library
                    and draw base layout of the screen. (Always use this in void setup())
                    You can give it a rotation value while initializing. 1,3 for landscape orientation
                    and 2,4 for portrait. Default value is 1 so keeping it empty won't be a problem.*/
}

void loop() {
  update_screen_values(speed, throttle, BatterySOC, range_kms); //This updates the necessary values displayed on the screen.
                                          //Expects arguments in sequence: speed(int), throttle%(int 0-100), batterySOC%(int 0-100), range_kms(int)
                                          //Function is set with default values so keeping any argument empty wont be a problem

  update_screen_warnings(charging, Btemp_warning, Mtemp_warning, BMS_connected, WiFi_connected); //This updates warning signs on the screen.
                                          //Expects arguments in sequence: Is_battery_charging?(bool), Battery_temp_over_threshold?(bool),
                                          //Motor_temp_over_threshold?(bool), Is_BMS_connected?(bool), Is_WiFi_connected?(bool).
                                          //Function is set with default values so keeping any argument empty wont be a problem
}
