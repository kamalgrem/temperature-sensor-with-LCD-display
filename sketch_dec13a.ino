#include <LiquidCrystal.h>

String c[40]={"The Algerian Developer                                         "};
int ThermistorPin = 0;

float  voltage,T,mesure;

LiquidCrystal lcd(13,12,11,10,9,8,7);
byte degree[8] =
{
0b00011,
0b00011,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000
}; // These lines are to create a custom Degree sign



void setup() {
  lcd.begin(16,2);
  lcd.createChar(1, degree); //we assign a number 1 to the degree
  lcd.setCursor(4,0);
  lcd.print("T");
  delay(100);
  lcd.setCursor(5,0);
  lcd.print("A");
  delay(100);
  lcd.setCursor(6,0);
  lcd.print("D");
  delay(1000);


  lcd.setCursor(1,1);
  lcd.print("LOADING...");
  delay(1000);


}

void loop() {

  

  
mesure=analogRead(ThermistorPin); //read from the analog input 0
voltage=mesure*(5.0/1024.0);      //convert to voltage
T=voltage*10;




  
  lcd.setCursor(4,0);
  lcd.print("TAD");
  lcd.setCursor(1,1);
  lcd.print("Temp = ");
  lcd.setCursor(7,1);
  lcd.print(T);              // display temperature 
  lcd.setCursor(13,1);
  lcd.print("C");
  lcd.setCursor(12,1);
  lcd.write(1);       // Write the custom charecter we created (degree sign)



  
  delay(100);      
        
  
}


