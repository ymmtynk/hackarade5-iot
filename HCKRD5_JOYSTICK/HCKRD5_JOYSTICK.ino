#include <M5Stack.h>

// JOY STICK Connection
// YELLOW: GPIO35/AD    X-axis+Push(Analog)
// WHITE : GPIO36/AD    Y-axis(Analog)
// RED   : BAT
// BLACK : GND


// the setup routine runs once when M5Stack starts up
void setup(){

    // Initialize the M5Stack object
    M5.begin();

    dacWrite(25, 0);          // ブザーがうるさいときにブザーを切る
  
    // LCD display
    M5.Lcd.print("Joy Stick Sample");
  
    delay(1000);              // 1000ms wait
}

// the loop routine runs over and over again forever
void loop() {
    int xval, yval, push;
    xval = analogRead(35);
    yval = analogRead(36);
    if (xval >= 4095) {
        push = 1;
    } else {
        push = 0;
    }

    M5.Lcd.fillScreen(BLACK);       // 画面全消し
    M5.Lcd.setCursor(0, 0);         // print位置を戻す
    if (push) {
        M5.Lcd.print("Push; Active X:Invalid");       
    } else {
        M5.Lcd.print("Push; Inactive X:");               
        M5.Lcd.print(xval-2372); 
    }
    M5.Lcd.print(" Y:");
    M5.Lcd.print(yval-2372); 
   
    delay(100);                    // 1000ms wait
}
