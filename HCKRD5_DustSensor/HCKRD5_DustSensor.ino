#include <M5Stack.h>

// Dust Sensor Connection
// Connect to GROVE
// YELLOW: GPIO22/SCL    Dust Sensor Output(PWM)
// WHITE : 
// RED   : 5V
// BLACK : GND


unsigned long duration;
unsigned long starttime;
unsigned long sampletime_ms = 30000;    //sampe 30s ;
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0;


// the setup routine runs once when M5Stack starts up
void setup(){
    
    // Initialize the M5Stack object
    M5.begin();
    
    starttime = millis();       //get the current time;

    // LCD display
    M5.Lcd.print("Dust Sensor Sample");
    M5.Lcd.setCursor(0, 10);         // print位置を変更

    pinMode(22, INPUT);         // GPIO22 Digital Input
 
    delay(1000);                // 1000ms wait
}

// the loop routine runs over and over again forever
void loop() {
    
    duration = pulseIn(22, LOW);
    lowpulseoccupancy = lowpulseoccupancy+duration;

        
    if ((millis()-starttime) > sampletime_ms) {
        //if the sampel time == 30s
        
        ratio = lowpulseoccupancy/(sampletime_ms*10.0);  // Integer percentage 0=>100
        concentration = 1.1*pow(ratio,3)-3.8*pow(ratio,2)+520*ratio+0.62; // using spec sheet curve
        
        M5.Lcd.fillScreen(BLACK);       // 画面全消し
        M5.Lcd.setCursor(0, 0);         // print位置を戻す

        M5.Lcd.print("Concentration:");
        M5.Lcd.println(concentration);
        M5.Lcd.setCursor(0, 10);         // print位置を変更
        lowpulseoccupancy = 0;
        starttime = millis();
    } else {
        M5.Lcd.print(".");       
    }
}
