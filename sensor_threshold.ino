#include <LiquidCrystal.h>
#define BLYNK_PRINT Serial

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int ledPin = 13;

int sensorPin = A0;
int sensorPin1 = A1;

int value = 0;
int value1 = 0;

const int threshold = 400 ;
const int threshold1 = 300;


void setup()
{

  Serial.begin(115200);
  lcd.begin(20, 4);
  lcd.clear();
}


void loop()
{

  value = analogRead(0);
  value1 = analogRead(1);

  if (value > threshold)
  {
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Tin LVL:");
    lcd.setCursor(12, 0);
    lcd.print(value);
   // Serial.println("alcohol");
    //Serial.println(value);
    lcd.setCursor(0, 1);
    lcd.print("You're Drunk!!");
    lcd.setCursor(12, 0);  // Set the cursor to the position
    lcd.print("      "); // Erase the largest possible number
    lcd.setCursor(12, 0);  // Reset the cursor to the original position
    lcd.print(value); // Print our value

    delay(3000);
    lcd.clear();

    if (value1 > threshold1){
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Smoke LVL:");
    lcd.setCursor(12, 0);
    lcd.print(value1);
    //Serial.println("smoke");
    //Serial.println(value1);
    lcd.setCursor(0, 1);
    lcd.print("Smoke LVL high");
    lcd.setCursor(12, 0);  // Set the cursor to the position
    lcd.print("      "); // Erase the largest possible number
    lcd.setCursor(12, 0);  // Reset the cursor to the original position
    lcd.print(value1); // Print our value
    }
    else {
      digitalWrite(ledPin, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Smoke LVL:");
    lcd.setCursor(12, 0);
    lcd.print(value1);
    //Serial.println(value1);
    lcd.setCursor(12, 0);  // Set the cursor to the position
    lcd.print("    "); // Erase the largest possible number
    lcd.setCursor(12, 0);  // Reset the cursor to the original position
    lcd.print(value1); // Print our value
    lcd.setCursor(0, 1);
    lcd.println("Low");
    lcd.setCursor(5, 1);
    lcd.print("  ");
      }
      
    delay(3000);
    lcd.clear();
  }
  else {
    digitalWrite(ledPin, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Tin LVL:");
    lcd.setCursor(12, 0);
    lcd.print(value);
    //Serial.println(value);
    lcd.setCursor(12, 0);  // Set the cursor to the position
    lcd.print("    "); // Erase the largest possible number
    lcd.setCursor(12, 0);  // Reset the cursor to the original position
    lcd.print(value); // Print our value
    lcd.setCursor(0, 1);
    lcd.println("Sober");
    lcd.setCursor(5, 1);
    lcd.print("  ");

    delay(3000);
    lcd.clear();
    
    if (value1 > threshold1){
    digitalWrite(ledPin, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("Smoke LVL:");
    lcd.setCursor(12, 0);
    lcd.print(value1);
    //Serial.println("smoke");
    //Serial.println(value1);
    lcd.setCursor(0, 1);
    lcd.print("Smoke LVL high");
    lcd.setCursor(12, 0);  // Set the cursor to the position
    lcd.print("      "); // Erase the largest possible number
    lcd.setCursor(12, 0);  // Reset the cursor to the original position
    lcd.print(value1); // Print our value
    }
    else {
      digitalWrite(ledPin, LOW);
    lcd.setCursor(0, 0);
    lcd.print("Smoke LVL:");
    lcd.setCursor(12, 0);
    lcd.print(value1);
    //Serial.println(value1);
    lcd.setCursor(12, 0);  // Set the cursor to the position
    lcd.print("    "); // Erase the largest possible number
    lcd.setCursor(12, 0);  // Reset the cursor to the original position
    lcd.print(value1); // Print our value
    lcd.setCursor(0, 1);
    lcd.println("Low");
    lcd.setCursor(5, 1);
    lcd.print("  ");
      }
    
  }

  delay(3000);
  lcd.clear();

String x = "";
String y = "";
x = String(value, DEC);
y = String(value1, DEC);
Serial.println(String(x + "," + y));
}

