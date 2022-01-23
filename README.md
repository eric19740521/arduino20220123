ESP32實驗: 溫度與濕度感測器DHT22.TFT顯示溫度

參考資料:
https://www.hwlibre.com/zh-TW/dht22/

0.如何 建字庫/中文.
https://chowdera.com/2021/09/20210918...

1)解說
工具目錄  C:\Users\user\Documents\Arduino\libraries\TFT_eSPI\Tools\Create_Smooth_Font\Create_font
引用的字型檔 C:\Users\user\Documents\Arduino\libraries\TFT_eSPI\Tools\Create_Smooth_Font\Create_font\data
自建字庫  C:\Users\user\Documents\Arduino\libraries\TFT_eSPI\Tools\Create_Smooth_Font\Create_font\FontFiles
2)下載軟體 Processing
https://processing.org/download
3)使用轉換軟體 Processing

C:\Windows\Fonts
打開Create_font.pde文件

String fontName = "kaiu";  //引用的字庫檔
String fontType = ".ttf";
//String fontType = ".otf";


// Define the font size in points for the TFT_eSPI font file
int  fontSize = 48;

// Font size to use in the Processing sketch display window that pops up (can be different to above)
int displayFontSize = 48;


static final int[] unicodeBlocks = {
  0x0021, 0x007E,  //Basic Latin, 128, 128, Latin (52 characters), Common (76 characters)
};

// Here we specify particular individual Unicodes to be included (appended at end of selected range)
static final int[] specificUnicodes = {
 0x85cd,0x82bd,0x6e2c,0x8a66 //藍芽測試
}

4)中文轉unicode
http://tool.chinaz.com/tools/unicode....
藍芽測試 == \u85cd\u82bd\u6e2c\u8a66

5)結果目錄
C:\Users\user\Documents\Arduino\libraries\TFT_eSPI\Tools\Create_Smooth_Font\Create_font\FontFiles
kaiu48.vlw 自建字庫

6)用底下網址.File to hexadecimal converter
https://tomeko.net/online_tools/file_...

7)複製過去
font_12.h


1.LIB DHT22
https://github.com/adafruit/DHT-sensor-library
https://github.com/adafruit/Adafruit_Sensor

2.燒錄時候
把DHT22電源拔掉

3.電路圖

4.



9.AI天氣預報!!!










