#include <M5Stack.h>
#include "Seeed_vl53l0x.h"

// VL53L0X Sensor Connection
// Connect to GROVE
// YELLOW: GPIO22/SCL   VL53L0X I2C SCL
// WHITE : GPIO21/SDA   VL53L0X I2C SDA
// RED   : 5V
// BLACK : GND


Seeed_vl53l0x VL53L0X;  // VL53L0X Control Object

// the setup routine runs once when M5Stack starts up
void setup(){
    
    // Initialize the M5Stack object
    M5.begin();
    
    // LCD display
    M5.Lcd.print("BME680 Sample");
    M5.Lcd.setCursor(0, 10);         // print位置を変更

    VL53L0X_Error Status = VL53L0X_ERROR_NONE;
    Status=VL53L0X.VL53L0X_common_init();
    
    if (Status != VL53L0X_ERROR_NONE) {
        M5.Lcd.print("start vl53l0x mesurement failed!");
        VL53L0X.print_pal_error(Status);
        while(1);
    }
    
    VL53L0X.VL53L0X_long_distance_ranging_init();
    
    if (Status != VL53L0X_ERROR_NONE) {
        M5.Lcd.print("start vl53l0x mesurement failed!");
        VL53L0X.print_pal_error(Status);
        while(1);
    }
}

// the loop routine runs over and over again forever
void loop() {
    
    M5.Lcd.fillScreen(BLACK);       // 画面全消し
    M5.Lcd.setCursor(0, 0);         // print位置を戻す
    
    VL53L0X_RangingMeasurementData_t RangingMeasurementData;
    VL53L0X_Error Status = VL53L0X_ERROR_NONE;

    memset(&RangingMeasurementData, 0, sizeof(VL53L0X_RangingMeasurementData_t));
    Status = VL53L0X.PerformSingleRangingMeasurement(&RangingMeasurementData);
    
    if (Status == VL53L0X_ERROR_NONE) {
        if (RangingMeasurementData.RangeMilliMeter >= 2000) {
            M5.Lcd.print("Out of Range!");
        } else {
            M5.Lcd.print("Distance: ");
            M5.Lcd.print(RangingMeasurementData.RangeMilliMeter);
            M5.Lcd.print("[mm]");
        }
    } else {
        M5.Lcd.print("Mesurement Failed! Status code =");
        M5.Lcd.print(Status);
    }
    
    delay(300);
}
