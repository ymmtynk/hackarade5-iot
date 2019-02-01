#include <M5Stack.h>

// Moisture Sensor Connection
// YELLOW: GPIO35/AD    Moisture Sensor Output(Analog)
// WHITE : 
// RED   : BAT
// BLACK : GND


// the setup routine runs once when M5Stack starts up
void setup(){

    // Initialize the M5Stack object
    M5.begin();

    dacWrite(25, 0);          // ブザーがうるさいときにブザーを切る
  
    // LCD display
    M5.Lcd.print("Moisture Sensor Sample");
  
    delay(1000);              // 1000ms wait
}

// the loop routine runs over and over again forever
void loop() {
    M5.Lcd.fillScreen(BLACK);       // 画面全消し
    M5.Lcd.setCursor(0, 0);         // print位置を戻す
    M5.Lcd.print("Moisture:");
    M5.Lcd.print(analogRead(35));   // 水分センサを読み、LCDに表示
                                    // センサ部大気中でほぼ0
                                    // センサ部水没で2600くらい
    delay(1000);                    // 1000ms wait
}
