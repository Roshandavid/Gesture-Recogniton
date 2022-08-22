#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int peakValue = 200;
int sensorValue[4]={0,0,0,0};
int a[4]={0,0,0,0};   //set your own value based on your sensors
int e[4];
int d=0;
int n=4;
int swap;
int j=0;
void printarray(int b[],int len)   // helps in printing array
{
  for(int i=0;i<len;i++)
  {
    Serial.print(a[i]);
    Serial.print("\t");
  }
  Serial.println("");
}
int exitconditioncheck(int b[], int len)   // to get the exit conditon
{
  int c=0;
  for(int i=0;i<len;i++)
  {
    if(a[i]==2)
    {
      c++;
      break;
    }
  }
  return(c);
}

 
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(13, OUTPUT);
 lcd.begin(16, 2);
  // Print a message to the LCD.

  lcd.print("pattern recognition");
}
 
void loop() {
   digitalWrite(13,HIGH);
    digitalWrite(13,HIGH);
     digitalWrite(13,HIGH);
      digitalWrite(13,HIGH);
 Serial.println("selectpoint");
 lcd.setCursor(0, 0);
  // Print a message to the LCD.

   lcd.print("pattern recognition");
    lcd.setCursor(0, 1);
  lcd.print("Select a point");
for(;;)
 { 
  sensorValue[0] = analogRead(A0); // to read the values of sensor
  //Serial.println(sensorValue[0]);
  //Serial.println(sensorValue[0]);
  sensorValue[1] = analogRead(A2);
 // Serial.println(sensorValue[1]);
  sensorValue[2] = analogRead(A3);
  //Serial.println(sensorValue[2]);
  sensorValue[3] = analogRead(A4);
  //Serial.println(sensorValue[3]);
  if (sensorValue[0] < peakValue)  // check if it's higher than the current peak:
    {a[0]=a[0]+1;
    printarray(a,4);
     lcd.setCursor(0, 1);
  lcd.print("detected!!!!!!");
    digitalWrite(13, LOW);
     delay(500);
    /*  lcd.setCursor(0, 1);
      lcd.print("Selectpoint");*/
      delay(1000);
     digitalWrite(13,HIGH);
    break;
     }
  if (sensorValue[1] < peakValue) {
    a[1]=a[1]+1;
    printarray(a,4);
   lcd.setCursor(0, 1);
  lcd.print("detected!!!!!!");

     digitalWrite(13, LOW);
     delay(500);
    /*  lcd.setCursor(0, 1);
      lcd.print("Selectpoint");
       delay(1000);  */
     digitalWrite(13,HIGH);
    break;
   
  }
   if (sensorValue[2] < peakValue) {
    a[2]=a[2]+1;
    printarray(a,4);
     lcd.setCursor(0, 1);
  lcd.print("detected!!!!!!");
     digitalWrite(13, LOW);
     delay(500);
   /*   lcd.setCursor(0, 1);
      lcd.print("Selectpoint");*/
       delay(1000);
     digitalWrite(13,HIGH);
    break;
    
   }
 if (sensorValue[3] < peakValue) {
    a[3]=a[3]+1;
    printarray(a,4);
     lcd.setCursor(0, 1);
  lcd.print("detected!!!!!!");
     digitalWrite(13, LOW);
     delay(500);
     /* lcd.setCursor(0, 1);
      lcd.print("Selectpoint");*/
      delay(1000);
     digitalWrite(13,HIGH);
    break;
     }  
   }
   
  d=exitconditioncheck(a,4);      // check for exit condition
   
  if(d==1)                      // after exit condition has been satisfied
  {
    for(int i=0;i<4;i++)
  {
    e[i]=a[i];                                // creating a new array.
  }
 for (int m = 0 ; m < ( n - 1 ); m++)              // sorting the new array
  {
    for (int k = 0 ; k < n - m - 1; k++)
    {
      if (e[k] < e[k+1]) /* For decreasing order use < */
      {
        swap=e[k];
        e[k]=e[k+1];
        e[k+1]=swap;
      }
    }
  }
  
printarray(e,4);
if(e[1]==0)                                    // pattern recognition
{Serial.println("Point");
 lcd.setCursor(0, 0);
  lcd.print("ptern recognised");
 lcd.setCursor(0, 1);
  lcd.print("point!!!!");
  delay(2000);
  j++;}
else if(e[2]==0)
{Serial.println("lin");
 lcd.setCursor(0, 0);
  lcd.print("ptern rgnsed");
   lcd.setCursor(0, 1);
  lcd.print("line!!!!!");
  delay(2000);
  j++;}
else if(e[3]==0)
{Serial.println("Tri");
 lcd.setCursor(0, 0);
  lcd.print("ptern recognised");
 lcd.setCursor(0, 1);
  lcd.print("Triangle!");
  delay(2000);
  j++;}
else if(e[4]!=0)
{Serial.println("rectangle");
 lcd.setCursor(0, 0);
  lcd.print("ptern recognised");
  lcd.setCursor(0, 1);
  lcd.print("rectangle");
  delay(2000);
  j++;}

if(j>0)                                          // to deinitialize the values so that new pattern can be created
{
  for(int i=0;i<4;i++)
  {
    a[i]=0;
  }
j=0;}
  d=0;
}
}
/* Serial.print(sensorValue[0]);
  Serial.print("\t");
  Serial.println(sensorValue[1]);*/
