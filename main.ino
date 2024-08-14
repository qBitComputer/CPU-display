#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
String stringreceived;
Adafruit_SSD1306 display(128, 64, &Wire, -1); // define the display

void setup() {
  Serial.begin(115200);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("Couldn't find display :("));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();


}
void loop() {
  while(Serial.available()){
    stringreceived = Serial.readString();
    Serial.println(stringreceived);
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
    display.println(stringreceived);
    display.display(); 
    delay(100);
    display.clearDisplay();
  }
}
