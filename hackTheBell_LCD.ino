#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int S = 00; // count seconds 
int M = 15; // count minutes
int H = 00; // count hours

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);

signed short minutes, secondes;
char timeline[16];

void setup()
{
 lcd.begin();//set up the LCD's number of columns and rows
}
void loop()
{
 lcd.setCursor(2,0); 
 lcd.print ("STEAL AND ESCAPE");
 lcd.setCursor(8,2);
 lcd.print(":");
 lcd.setCursor(11,2);
 lcd.print(":");
 
 S--;
 delay(1000);
  
 if(S<0)
 {
   M--;
   S=59;
 }
 if(M<0)
 {
   H--;
   M=59;
 }
 
 //if(H<0) { H=23; M=59; S=59; } 
 
 if(M>9)
 {
   lcd.setCursor(9,2);
   lcd.print(M);
 }
 else
 {
   lcd.setCursor(9,2);
   lcd.print("0"); 
   lcd.setCursor(10,2);
   lcd.print(M);
   lcd.setCursor(11,2);
   lcd.print(":");
 }
  
 if(S>9)
 {
   lcd.setCursor(12,2);
   lcd.print(S);
 }
 else
 {
   lcd.setCursor(12,2);
   lcd.print("0"); 
   lcd.setCursor(13,2);
   lcd.print(S);
   lcd.setCursor(14,2);
   lcd.print(" ");
 }
  
 if(H>9)
 {
   lcd.setCursor(6,2);
   lcd.print (H);
 }
 else
 {
   lcd.setCursor(6,2);
   lcd.print("0"); 
   lcd.setCursor(7,2);
   lcd.print(H);
   lcd.setCursor(8,2);
   lcd.print(":");
 }
}
