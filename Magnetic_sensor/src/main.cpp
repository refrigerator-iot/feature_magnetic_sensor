#include <M5Core2.h>
#define val
#define PIN_YELLOW 32
#define PIN_GREEN 33

void header(const char *string, uint16_t color) {
  M5.Lcd.fillScreen(color);
  M5.Lcd.setTextSize(1);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  M5.Lcd.fillRect(0, 0, 320, 30, TFT_BLACK);
  M5.Lcd.setTextDatum(TC_DATUM);
  M5.Lcd.drawString(string, 160, 3, 4);
}

void setup() {
    M5.begin(true, false, true);
    header("Sensor", TFT_BLACK);
    pinMode(PIN_YELLOW, OUTPUT);  
    pinMode(PIN_GREEN, INPUT);  
}

void loop() {
  bool status = digitalRead(PIN_GREEN);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(20, 80, 2);
  M5.Lcd.printf("Hall status : %d", status);
}