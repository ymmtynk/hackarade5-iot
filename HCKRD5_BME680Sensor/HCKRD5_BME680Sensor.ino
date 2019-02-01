#include <M5Stack.h>
#include <seeed_bme680.h>

// BME680 Sensor Connection
// Connect to GROVE
// YELLOW: GPIO22/SCL   BME680 I2C SCL
// WHITE : GPIO21/SDA   BME680 I2C SDA
// RED   : 5V
// BLACK : GND


Seeed_BME680 bme680((uint8_t)0x76);  // BME680 Control Object


// the setup routine runs once when M5Stack starts up
void setup(){
    
    // Initialize the M5Stack object
    M5.begin();
    
    // LCD display
    M5.Lcd.print("BME680 Sample");
    M5.Lcd.setCursor(0, 10);         // print位置を変更

    while (!bme680.init()) {
        Serial.println("bme680 init failed ! can't find device!");
        delay(10000);
    }
    
    delay(1000);                // 1000ms wait
}

// the loop routine runs over and over again forever
void loop() {
    
    M5.Lcd.fillScreen(BLACK);       // 画面全消し
    M5.Lcd.setCursor(0, 0);         // print位置を戻す

    if (bme680.read_sensor_data()) {
        
        M5.Lcd.print("Failed to perform reading.");
        return;
    }
    
    M5.Lcd.print("Temperature: ");
    M5.Lcd.print(bme680.sensor_result_value.temperature);
    M5.Lcd.print("[degC]");
    
    M5.Lcd.setCursor(0, 10);         // print位置をずらす
    
    M5.Lcd.print("Pressure: ");
    M5.Lcd.print(bme680.sensor_result_value.pressure/ 1000.0);
    M5.Lcd.print("[KPa]");
    
    M5.Lcd.setCursor(0, 20);         // print位置をずらす
    
    M5.Lcd.print("Humidity: ");
    M5.Lcd.print(bme680.sensor_result_value.humidity);
    M5.Lcd.print("[%]");
    
    M5.Lcd.setCursor(0, 30);         // print位置をずらす
    
    M5.Lcd.print("Gas: ");
    M5.Lcd.print(bme680.sensor_result_value.gas/ 1000.0);
    M5.Lcd.print("[Kohms]");
    
    delay(1000);    
}
