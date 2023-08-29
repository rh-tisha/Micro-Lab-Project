#include <SPI.h>
#include <MFRC522.h>
#include <ESP32_Servo.h>

Servo servo1;
Servo servo2;

int flag = 0;

constexpr uint8_t RST_PIN = 22;
constexpr uint8_t SS_PIN = 5;

MFRC522 rfid(SS_PIN, RST_PIN);
MFRC522::MIFARE_Key key;

String tag;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(15, OUTPUT);

  servo1.attach(16);
  servo2.attach(17);

  servo1.write(0);
  servo2.write(0);
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent())
    return;
  if (rfid.PICC_ReadCardSerial()) {
    for (byte i = 0; i < 4; i++) {
      tag += rfid.uid.uidByte[i];
    }
    Serial.println(tag);

    if (tag == "1543622711") {
      if (flag == 0) {
        Serial.println("Access Granted!");
        AllowBuzzer();
        Serial.println("Locker Open");
        GateOpen();
        flag = 1;  // Set the flag to indicate the locker is open
      } 
    else if (flag == 1) {
        Serial.println("Locker closing");
        GateClose();
        flag = 0;  // Set the flag to indicate the locker is closed
      }
    } 
    else {
      Serial.println("Access Denied!");
      Denied();
    }
    tag = "";
    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
}

void AllowBuzzer() {
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
}

void Denied() {
  digitalWrite(15, HIGH);
  delay(2000);
  digitalWrite(15, LOW);
}

void GateOpen() {
  servo1.write(180);
  servo2.write(0);
}

void GateClose() {
  servo1.write(0);
  servo2.write(180);
}



//195244558
//1543622711
