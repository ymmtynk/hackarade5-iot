#include <M5Stack.h>

// Flame Sensor Connection
// Connect to GROVE
// YELLOW: GPIO22/SCL    Flame Sensor Output(Digital)
// WHITE : 
// RED   : 5V
// BLACK : GND


// the setup routine runs once when M5Stack starts up
void setup(){
    
    // Initialize the M5Stack object
    M5.begin();
    
    // LCD display
    M5.Lcd.print("Flame Sensor Sample");

    pinMode(22, INPUT);         // GPIO22 Digital Input
 
    delay(1000);                // 1000ms wait
}

// the loop routine runs over and over again forever
void loop() {
    M5.Lcd.fillScreen(BLACK);       // 画面全消し
    M5.Lcd.setCursor(0, 0);         // print位置を戻す
    M5.Lcd.print("Flame:");

    if (digitalRead(22)) {
        M5.Lcd.print("Safe");   
    } else {
        M5.Lcd.print("Alert!!");    // 火炎を検出するとLOWになるらしい、未確認  
    }
    
    delay(1000);                    // 1000ms wait
}
