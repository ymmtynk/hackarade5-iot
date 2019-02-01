#include <M5Stack.h>

// Alcohol Sensor Connection
// YELLOW: GPIO35/AD    Data
// WHITE : GND          Heater Enable
// RED   : BAT
// BLACK : GND


// the setup routine runs once when M5Stack starts up
void setup(){
    
    // Initialize the M5Stack object
    M5.begin();
    
    // LCD display
    M5.Lcd.print("Alcohol Sensor Sample");
  
    delay(1000);              // 1000ms wait
}

// the loop routine runs over and over again forever
void loop() {
    M5.Lcd.fillScreen(BLACK);       // 画面全消し
    M5.Lcd.setCursor(0, 0);         // print位置を戻す
    M5.Lcd.print("Alcohol:");
    M5.Lcd.print(analogRead(35));   // アルコールセンサの出力を読んで、LCDに表示
                                    // アルコールを検知すると数字が小さくなる
    delay(1000);                    // 1000ms wait
}
