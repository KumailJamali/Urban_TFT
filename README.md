# Urban_TFT
240x320 TFT screen display designed for SEM Urban EV. Uses TFT_eSPI.

setup_screen(1); 
setup function to initialize the TFT display library and draw base layout of the screen. (Always use this in void setup()) You can give it a rotation value while initializing. 1,3 for landscape orientation and 2,4 for portrait. Default value is 1 so keeping it empty won't be a problem.

update_screen_values(speed, throttle, BatterySOC, range_kms);
This updates the necessary values displayed on the screen. Expects arguments in sequence: speed(int), throttle%(int 0-100), batterySOC%(int 0-100), range_kms(int). Function is set with default values so keeping any argument empty wont be a problem.

update_screen_warnings(charging, Btemp_warning, Mtemp_warning, BMS_connected, WiFi_connected);
This updates warning signs on the screen. Expects arguments in sequence: Is_battery_charging?(bool), Battery_temp_over_threshold?(bool), Motor_temp_over_threshold?(bool), Is_BMS_connected?(bool), Is_WiFi_connected?(bool). Function is set with default values so keeping any argument empty wont be a problem.

Author: Kumail Jamali
Written for Urban class Electric Vehicle in Shell Eco Marathon
dated: 30th September 2025
