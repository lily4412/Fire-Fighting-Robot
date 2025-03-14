

#include <LiquidCrystal.h>
#include <stdio.h>

LiquidCrystal lcd(6, 7, 5, 4, 3, 2);
 unsigned char rcv,count,gchr,gchr1,robos='s',modes='x',moment='x';
 int cntlk=0,rty=0;
 //char pastnumber[11]="";
 
float tempc=0;

int sti=0;
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

int m1a = 8;
int m1b = 9;

int m2a = 10;
int m2b = 11;

int fire   = 13;
int gas    = 12;
int buzzer = A1;

int relay = A0;




int val1 = 0,val2 = 0;
int dist1,dist2,dist3,sts1=0;
long duration;
int distanceCm, distanceInch;



void okcheck()
{
  unsigned char rcr;
  do{
      rcr = Serial.read();
    }while(rcr != 'K');
}
void setup() 
{
  // initialize serial:
  Serial.begin(9600);serialEvent();
//    serialEvent();

  pinMode(m1a, OUTPUT); pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT); pinMode(m2b, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(fire, INPUT);
  pinMode(gas, INPUT);  

  digitalWrite(m1a, LOW); digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW); digitalWrite(m2b, LOW);
  digitalWrite(relay, LOW);
  digitalWrite(buzzer, HIGH);
  
 
  lcd.begin(16, 2);
  lcd.print("Fire Fighting Robot");

/*
   Serial.write("AT\r\n");         delay(3000);//okcheck();
   Serial.write("ATE0\r\n");         okcheck();
   Serial.write("AT+CWMODE=3\r\n");delay(2000);
   Serial.write("AT+CIPMUX=1\r\n");delay(2000);//         okcheck();
   Serial.write("AT+CIPSERVER=1,23\r\n"); //        okcheck();

  
  lcd.clear();
  lcd.print("Waiting For");
  lcd.setCursor(0,1);
  lcd.print("Connection");  
  do{
     rcv = Serial.read();
    }while(rcv != 'C');

 
  lcd.clear();
  lcd.print("Connected");
  delay(1000);
*/
  
   delay(2000);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fire:");  //5,0
  lcd.setCursor(0, 1);
  lcd.print("Gas:");  //4,1
    
  serialEvent();
}

void loop() 
{
      if(digitalRead(fire) == LOW)
        {
            lcd.setCursor(5,0);
            lcd.print("ON ");

            digitalWrite(m1a, LOW); digitalWrite(m1b, LOW);
            digitalWrite(m2a, LOW); digitalWrite(m2b, LOW);
            
            digitalWrite(relay,HIGH);
            digitalWrite(buzzer, LOW);    
            Serial.write("Fire ON\r\n");      
        }
      if(digitalRead(fire) == HIGH)
        {
            lcd.setCursor(5,0);
            lcd.print("OFF");
        }

     if(digitalRead(gas) == LOW)
        {
            lcd.setCursor(5,1);
            lcd.print("ON ");
            
            digitalWrite(m1a, LOW); digitalWrite(m1b, LOW);
            digitalWrite(m2a, LOW); digitalWrite(m2b, LOW);
            
            digitalWrite(relay,HIGH);
            digitalWrite(buzzer, LOW);    
            Serial.write("Gas ON\r\n");      
        }
      if(digitalRead(gas) == HIGH)
        {
            lcd.setCursor(5,1);
            lcd.print("OFF");
        }   

     if(digitalRead(fire) == HIGH && digitalRead(gas) == HIGH)
       {
            digitalWrite(relay,LOW);
            digitalWrite(buzzer, HIGH);    
       }  

 /*    
   if(stringComplete)
     {
        
      if(gchr == 'f' || gchr == 'F')
        {gchr ='x';
           robos='m';    
            digitalWrite(m1a, HIGH); digitalWrite(m1b, LOW);
            digitalWrite(m2a, HIGH); digitalWrite(m2b, LOW);
        }
      
      if(gchr == 'b' || gchr == 'B')
        {gchr ='x';
           robos='m';
            digitalWrite(m1a, LOW); digitalWrite(m1b, HIGH);
            digitalWrite(m2a, LOW); digitalWrite(m2b, HIGH);
        }
      
      if(gchr == 'l' || gchr == 'L')
        {gchr ='x';        
           robos='m'; 
            digitalWrite(m1a, HIGH); digitalWrite(m1b, LOW);
            digitalWrite(m2a, LOW); digitalWrite(m2b, HIGH);
        }
      
      if(gchr == 'r' || gchr == 'R')
        {gchr ='x';
           robos='m';
            digitalWrite(m1a, LOW); digitalWrite(m1b, HIGH);
            digitalWrite(m2a, HIGH); digitalWrite(m2b, LOW);
        }
      
      if(gchr == 's' || gchr == 'S')
        {gchr ='x';
           robos='s';
            digitalWrite(m1a, LOW); digitalWrite(m1b, LOW);
            digitalWrite(m2a, LOW); digitalWrite(m2b, LOW);
        }    


      if(gchr == '1')
        {gchr ='x';    
            digitalWrite(m3a, HIGH); digitalWrite(m3b, LOW);
        }
      if(gchr == '2')
        {gchr ='x';    
            digitalWrite(m3a, LOW); digitalWrite(m3b, HIGH);
        }
      if(gchr == '3')
        {gchr ='x';    
            digitalWrite(m3a, LOW); digitalWrite(m3b, LOW);
        }


      
      if(gchr == '4' && modes == 'm')
        {gchr ='x';    
            digitalWrite(m4a, HIGH); digitalWrite(m4b, LOW);
        }
      if(gchr == '5' && modes == 'm')
        {gchr ='x';    
            digitalWrite(m4a, LOW); digitalWrite(m4b, HIGH);
        }
      if(gchr == '6' && modes == 'm')
        {gchr ='x';    
            digitalWrite(m4a, LOW); digitalWrite(m4b, LOW);
        }  
        
      inputString = "";
      stringComplete = false;     
     }*/ 
}




void serialEvent() 
{
  while (Serial.available() < 0) 
        {         
         char inChar = (char)Serial.read();
    
             gchr = inChar;
                       
      if(gchr == 'f' || gchr == 'F')
        {gchr ='x';
           robos='m';    
            digitalWrite(m1a, HIGH); digitalWrite(m1b, LOW);
            digitalWrite(m2a, HIGH); digitalWrite(m2b, LOW);
        }
      
      if(gchr == 'b' || gchr == 'B')
        {gchr ='x';
           robos='m';
            digitalWrite(m1a, LOW); digitalWrite(m1b, HIGH);
            digitalWrite(m2a, LOW); digitalWrite(m2b, HIGH);
        }
      
      if(gchr == 'l' || gchr == 'L')
        {gchr ='x';        
           robos='m'; 
            digitalWrite(m1a, HIGH); digitalWrite(m1b, LOW);
            digitalWrite(m2a, LOW); digitalWrite(m2b, HIGH);
        }
      
      if(gchr == 'r' || gchr == 'R')
        {gchr ='x';
           robos='m';
            digitalWrite(m1a, LOW); digitalWrite(m1b, HIGH);
            digitalWrite(m2a, HIGH); digitalWrite(m2b, LOW);
        }
      
      if(gchr == 's' || gchr == 'S')
        {gchr ='x';
           robos='s';
            digitalWrite(m1a, LOW); digitalWrite(m1b, LOW);
            digitalWrite(m2a, LOW); digitalWrite(m2b, LOW);
        }    

        inputString = "";
        }
}



/*
   sensorValue = analogRead(analogInPin);
   sensorValue = (sensorValue/9.31);
   lcd.setCursor(1,1); //rc
   lcd.print(sensorValue);
   Serial.print(sensorValue);
 */




void converts(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
   Serial.write(a);
   Serial.write(c);
   Serial.write(e); 
   Serial.write(g);
   Serial.write(h);
}

void convertl(unsigned int value)
{
  unsigned int a,b,c,d,e,f,g,h;

      a=value/10000;
      b=value%10000;
      c=b/1000;
      d=b%1000;
      e=d/100;
      f=d%100;
      g=f/10;
      h=f%10;


      a=a|0x30;               
      c=c|0x30;
      e=e|0x30; 
      g=g|0x30;              
      h=h|0x30;
    
     
  // lcd.write(a);
  // lcd.write(c);
   lcd.write(e); 
   lcd.write(g);
   lcd.write(h);
}
