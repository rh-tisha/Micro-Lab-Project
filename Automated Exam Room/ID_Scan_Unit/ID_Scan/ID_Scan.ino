#include <SPI.h>
#include <MFRC522.h>

constexpr uint8_t RST_PIN = 0 ;    
constexpr uint8_t SS_PIN = 2;     

MFRC522 rfid(SS_PIN, RST_PIN); 
MFRC522::MIFARE_Key key;

String tag;

void setup() {
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522
  pinMode(15, OUTPUT);  //Buzzer
  pinMode(5, OUTPUT);  //Green LED(granted)
  pinMode(16, OUTPUT);  //Red LED(Denied)
 
}

void loop() {
  if ( ! rfid.PICC_IsNewCardPresent())
    return;
  if (rfid.PICC_ReadCardSerial()) {
    for (byte i = 0; i < 4; i++) {
      tag += rfid.uid.uidByte[i];
    }
    
    if (tag == "195244558") {
      Serial.println("Exam CSE-4326 Micro Lab");
      Serial.println("ID recognized: 011171276");
      Serial.println("Welcome 'Rabeya Hossain'");
      Serial.println("Your Allowcated seat is 'B5'");
      Serial.println("Room '305'");
      Serial.println("Access Granted!");
       digitalWrite(5, HIGH);
      
      digitalWrite(15, HIGH);
      delay(100);
      digitalWrite(15, LOW);
      delay(100);
      digitalWrite(15, HIGH);
      delay(100);
      digitalWrite(15, LOW);
      delay(100);
      digitalWrite(15, HIGH);
      delay(100);
      digitalWrite(15, LOW);
      delay(100);
      digitalWrite(5, LOW);
    
    }

     else if (tag == "1543622711") {
      Serial.println("Exam CSE-4326 Micro Lab");
      Serial.println("ID recognized: 011201377");
      Serial.println("Welcome 'Md. Mehrab Hossain Khan'");
      Serial.println("Your Allowcated seat is 'C8'");
      Serial.println("Room '305'");
      Serial.println("Access Granted!");
       digitalWrite(5, HIGH);
      
      digitalWrite(15, HIGH);
      delay(100);
      digitalWrite(15, LOW);
      delay(100);
      digitalWrite(15, HIGH);
      delay(100);
      digitalWrite(15, LOW);
      delay(100);
      digitalWrite(15, HIGH);
      delay(100);
      digitalWrite(15, LOW);
      delay(100);
      digitalWrite(5, LOW);
    }

     else {
      
      Serial.println("Exam CSE-4326 Micro Lab");
      Serial.println("ID recognized: 011181093");
      Serial.println("Name: 'Dip Chowdhury'");
      Serial.println("WARNING! Wrong Entry");
      Serial.println("Your Exam room is 605");
      Serial.println("Room '305'");
      Serial.println("Access DENIED!");
      digitalWrite(16, HIGH);
    

      digitalWrite(15, HIGH);
      delay(1500);
      digitalWrite(15, LOW);

      digitalWrite(16, LOW);
    }
    tag = "";
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}
