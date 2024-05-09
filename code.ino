/*13:58:25.658 -> Tag UID:  B5 AA 29 05
13:58:27.710 -> Tag UID:  C3 12 50 15
13:58:29.305 -> Tag UID:  53 F1 1A 31
13:58:30.942 -> Tag UID:  16 37 C6 29
*/
int signal1[] = {23  ,25,27};
int signal2[] = { 46,48,37};
int signal3[] = { 13 ,12,15};
int signal4[] = {14, 9, 8};
#include <SPI.h>

#include <MFRC522.h>
#define SS_PIN 53

#define RST_PIN 49

MFRC522 mfrc522(SS_PIN, RST_PIN); 

int redDelay = 25;
int yellowDelay =13;
int count=0;

void setup() {
  // Declaring all the LED's as output
  Serial.begin(9600);

// Init SPI bus

SPI.begin();

mfrc522.PCD_Init(); // Init MFRC522

Serial.println("RFID reading UID");
  for (int i = 0; i < 3; i++) {
    pinMode(signal1[i], OUTPUT);
    pinMode(signal2[i], OUTPUT);
    pinMode(signal3[i], OUTPUT);
    pinMode(signal4[i], OUTPUT);
  }

}
 
int a(){
  String content="";
   if (mfrc522.PICC_IsNewCardPresent())

{

if (mfrc522.PICC_ReadCardSerial())

{
  

Serial.print("Tag UID: ");
for (byte i = 0; i < mfrc522.uid.size; i++)
{ Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0":" ");
Serial.print(mfrc522.uid.uidByte[i], HEX);
content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
content.concat(String(mfrc522.uid.uidByte[i],HEX));
}

Serial.println();
mfrc522.PICC_HaltA();

}
}
Serial.println(content);
content.toUpperCase();
Serial.println(content);

  if(content.substring(1)=="B5 AA 29 05" || content.substring(1)=="16 37 C6 29" || content=="53 F1 1A 31" || content=="C3 12 50 15"){
    return(1);
  }
  else{
    return(0); 
  }


}
int b(){

   return(0);
}



int c()
{
 return(0);
   
} 




int d(){

   return(0);
} 
   



void e(){
  
   if(a()){
          digitalWrite(signal1[2],HIGH);
          digitalWrite(signal1[0],LOW);
          digitalWrite(signal1[1],LOW);
          digitalWrite(signal2[0],HIGH);
          digitalWrite(signal2[2],LOW);
          digitalWrite(signal2[1],LOW);
          digitalWrite(signal3[0],HIGH);
          digitalWrite(signal3[2],LOW);
          digitalWrite(signal3[1],LOW);
          digitalWrite(signal4[0],HIGH);
          digitalWrite(signal4[1],LOW);
          digitalWrite(signal4[2],LOW);
          delay(10000);
          digitalWrite(signal1[2],LOW);
        }
        else if(b()){
          digitalWrite(signal1[0],HIGH);
          digitalWrite(signal1[1],LOW);
          digitalWrite(signal1[2],LOW);
          digitalWrite(signal2[0],LOW);
          digitalWrite(signal2[1],LOW);
          digitalWrite(signal2[2],HIGH);
          digitalWrite(signal3[0],HIGH);
          digitalWrite(signal3[1],LOW);
          digitalWrite(signal3[2],LOW);
          digitalWrite(signal4[0],HIGH);
          digitalWrite(signal4[1],LOW);
          digitalWrite(signal4[2],LOW);
          delay(10000);
          digitalWrite(signal2[2],LOW);        
      }
      else if(c()){

          digitalWrite(signal1[0],HIGH);
          digitalWrite(signal1[1],LOW);
          digitalWrite(signal1[2],LOW);
          digitalWrite(signal2[0],HIGH);
          digitalWrite(signal2[1],LOW);
          digitalWrite(signal2[2],LOW);
          digitalWrite(signal3[0],LOW);
          digitalWrite(signal3[1],LOW);
          digitalWrite(signal3[2],HIGH);
          digitalWrite(signal4[0],HIGH);
          digitalWrite(signal4[1],LOW);
          digitalWrite(signal4[2],LOW);
          delay(10000);
          digitalWrite(signal3[2],LOW);
      }
      else if(d())
      {
          digitalWrite(signal1[0],HIGH);
          digitalWrite(signal1[1],LOW);
          digitalWrite(signal1[2],LOW);
          digitalWrite(signal2[0],HIGH);
          digitalWrite(signal2[1],LOW);
          digitalWrite(signal2[2],LOW);
          digitalWrite(signal3[0],HIGH);
          digitalWrite(signal3[1],LOW);
          digitalWrite(signal3[2],LOW);
          digitalWrite(signal4[0],LOW);
          digitalWrite(signal4[1],LOW);
          digitalWrite(signal4[2],HIGH);
          delay(10000);
          digitalWrite(signal4[2],LOW);
      }
  
  
  }
void loop() {


  
for (int j=0;j<100;j++)
{     
        digitalWrite(signal1[2],HIGH);
       e();
      digitalWrite(signal1[0],LOW);
      digitalWrite(signal2[0],HIGH);
      digitalWrite(signal3[0],HIGH);
      digitalWrite(signal4[0],HIGH);
      delay(redDelay);
      count=count+1;
     }
   //making green down and yellow up at signal 1
   for (int i=0;i<100;i++)
   {
        digitalWrite(signal1[1],HIGH);
        digitalWrite(signal1[2],LOW);
       e();
       delay(yellowDelay);}
    digitalWrite(signal1[1],LOW);
  // Making Green  LED at signal 2 and red LED's at other signal HIGH
for (int j=0;j<100;j++)
      {
        digitalWrite(signal2[2],HIGH);
        e();
      digitalWrite(signal1[0],HIGH);
      digitalWrite(signal2[0],LOW);
      digitalWrite(signal3[0],HIGH);
      digitalWrite(signal4[0],HIGH);
      delay(redDelay);
     }
   //making green down and yellow up at signal 2
   for (int i=0;i<100;i++)
   {
        digitalWrite(signal2[1],HIGH);
        digitalWrite(signal2[2],LOW);
          e();
          delay(yellowDelay);}
    digitalWrite(signal2[1],LOW);
  // Making Green  LED at signal 3 and red LED's at other signal HIGH
  for (int j=0;j<100;j++)
      {
        digitalWrite(signal3[2],HIGH);
        e();
      digitalWrite(signal1[0],HIGH);
      digitalWrite(signal2[0],HIGH);
      digitalWrite(signal3[0],LOW);
      digitalWrite(signal4[0],HIGH);
      delay(redDelay);
     }
   //making green down and yellow up at signal 3
   for (int i=0;i<100;i++)
   {
        digitalWrite(signal3[1],HIGH);
        digitalWrite(signal3[2],LOW);
            e();
      delay(yellowDelay);
      }
    digitalWrite(signal3[1],LOW);
  // Making Green  LED at signal 4 and red LED's at other signal HIGH
 for (int j=0;j<100;j++)
      {
        digitalWrite(signal4[2],HIGH);
        e();
      digitalWrite(signal1[0],HIGH);
      digitalWrite(signal2[0],HIGH);
      digitalWrite(signal3[0],HIGH);
      digitalWrite(signal4[0],LOW);
      delay(redDelay);
      }
   //making green down and yellow up at signal 4
 for(int i=0;i<100;i++)
   {   
        digitalWrite(signal4[1],HIGH);
        digitalWrite(signal4[2],LOW);
          e();
      delay(yellowDelay);
      }
    digitalWrite(signal4[1],LOW);

}
