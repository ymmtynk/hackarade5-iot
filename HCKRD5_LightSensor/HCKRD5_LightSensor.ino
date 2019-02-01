#include <M5Stack.h>

// Light Sensor Connection
// YELLOW: GPIO35/AD    Light Sensor Output(Analog)
// WHITE : 
// RED   : BAT
// BLACK : GND


// the setup routine runs once when M5Stack starts up
void setup(){

    // Initialize the M5Stack object
    M5.begin();

    dacWrite(25, 0);          // ブザーがうるさいときにブザーを切る
  
    // LCD display
    M5.Lcd.print("Light Sensor Sample");
  
    delay(1000);              // 1000ms wait
}

// the loop routine runs over and over again forever
void loop() {
    M5.Lcd.fillScreen(BLACK);       // 画面全消し
    M5.Lcd.setCursor(0, 0);         // print位置を戻す
    M5.Lcd.print("Light:");
    M5.Lcd.print(analogRead(35));   // 光センサの出力を読んで、LCDに表示
                                    // 暗いと0
                                    // 明るいと3600を超える
    delay(1000);                    // 1000ms wait
}
