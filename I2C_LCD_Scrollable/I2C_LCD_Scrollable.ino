#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);

//Heart Character

byte heart[] = {
  0x00,
  0x0A,
  0x1F,
  0x1F,
  0x0E,
  0x04,
  0x00,
  0x00
};

// it's a 16x2 LCD so...
int screenWidth = 16;
int screenHeight = 2;

// the two lines
// line1 = scrolling
String line1 = "nava sparsh deeptam ";
// line2 = static
String line2 = " Jai Hind ";

// just some reference flags
int stringStart, stringStop = 0;
int scrollCursor = screenWidth;

// most of the part is pretty basic
void setup() {
  lcd.begin();
}

void loop() {
  lcd.setCursor(scrollCursor, 0);
  lcd.print(line1.substring(stringStart,stringStop));
  lcd.setCursor(0, 1);
  lcd.write(1);
  lcd.print(line2);
  lcd.write(1);
  delay(300);
  lcd.clear();
  if(stringStart == 0 && scrollCursor > 0){
    scrollCursor--;
    stringStop++;
  } else if (stringStart == stringStop){
    stringStart = stringStop = 0;
    scrollCursor = screenWidth;
  } else if (stringStop == line1.length() && scrollCursor == 0) {
    stringStart++;
  } else {
    stringStart++;
    stringStop++;
  }
}
