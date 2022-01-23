// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
#include <TFT_eSPI.h>        //LCD函式庫
#include "DHT.h"
#include "font.h"
#define DHTPIN 33     //這個腳位測試OK Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 3 (on the right) of the sensor to GROUND (if your sensor has 3 pins)
// Connect pin 4 (on the right) of the sensor to GROUND and leave the pin 3 EMPTY (if your sensor has 4 pins)
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);
TFT_eSPI tft = TFT_eSPI();


static const unsigned char PROGMEM str_1[] = {    //東
  0x01, 0x00, 0x01, 0x00, 0x01, 0x04, 0x7F, 0xFE, 0x01, 0x00, 0x3F, 0xF8, 0x21, 0x08, 0x3F, 0xF8,
  0x21, 0x08, 0x3F, 0xF8, 0x05, 0x40, 0x09, 0x20, 0x11, 0x10, 0x21, 0x0E, 0x41, 0x04, 0x01, 0x00
};

static const unsigned char PROGMEM str_2[] = {    //洲
  0x01, 0x04, 0x41, 0x04, 0x31, 0x24, 0x11, 0x24, 0x81, 0x24, 0x65, 0xB4, 0x2B, 0x6C, 0x0B, 0x6C,
  0x11, 0x24, 0x11, 0x24, 0x61, 0x24, 0x21, 0x24, 0x22, 0x24, 0x22, 0x24, 0x24, 0x04, 0x20, 0x04
};


String str1;
String str2;
void setup() {
  Serial.begin(115200);
  Serial.println(F("DHT12 溫溼度實驗!"));

  tft.begin();               // 初始化LCD
  tft.setRotation(1);  // landscape
  tft.fillScreen(TFT_BLACK); // 用全黑清除螢幕
  tft.setSwapBytes(true);

  //TFT上顯示溫度
  //str1 = String(t, 2);
  tft.fillScreen(TFT_BLACK); // 用全黑清除螢幕
  tft.setTextColor(TFT_RED);
  tft.loadFont(font48); //指定tft屏幕对象载入font字库
  tft.drawString("溫度:", 0, 0);

  tft.setTextColor(TFT_RED);
  tft.drawString("濕度:", 0, 60);
    
  tft.unloadFont(); //释放字库文件,节省资源

  dht.begin();



}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("DHT sensor讀取資料失敗!請檢查DHT傳感器??"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("濕度: "));
  Serial.print(h);
  Serial.print(F("%  溫度: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  熱指數: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));


  //TFT上顯示溫度
  str1 = String(t, 2);
  str2 = String(h, 2);
  //  tft.fillScreen(TFT_BLACK); // 用全黑清除螢幕
  //  tft.setTextColor(TFT_RED);
  //  tft.setTextSize(1);                   //sets the size of text
  //  tft.loadFont(font); //指定tft屏幕对象载入font字库
  //  tft.drawString("溫度:", 0, 0);
  //  tft.unloadFont(); //释放字库文件,节省资源

  //文字 T-Display
  tft.fillScreen(TFT_BLACK); // 用全黑清除螢幕
  tft.setTextColor(TFT_BLUE);
 
  tft.loadFont(font48); //指定tft屏幕对象载入font字库
 
  tft.setTextColor(TFT_RED);
  tft.drawString("溫度:", 0, 0);
  tft.setTextColor(TFT_BLUE);
  tft.drawString(str1, 110, 0);


  tft.setTextColor(TFT_RED);
  tft.drawString("濕度:", 0, 60);
  tft.setTextColor(TFT_BLUE);
  tft.drawString(str2, 110, 60);


  
  tft.unloadFont(); //释放字库文件,节省资源
}
