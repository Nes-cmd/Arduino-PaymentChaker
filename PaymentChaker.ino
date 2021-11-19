/*
** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)
*/
#include <SPI.h>
#include <SD.h>
#include<SoftwareSerial.h>
SoftwareSerial uno(2,3);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  uno.begin(9600);
  while (!Serial) {}
  if (!SD.begin(4)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(8) == LOW){
    String txn,phone,message,amount;
    while(uno.available() == 0){}
    message = uno.readString();
    message.trim();
//    int pos1 = message.indexOf(" ",6);
//    txn = message.substring(message.length() - 10);
//    phone = message.substring((message.length() - 20),(message.length() - 10));
//    amount = message.substring(pos1,(message.length() - 20));
//    Serial.print(txn);
//    Serial.print(" ");
//    Serial.print(phone);
//    Serial.print(" ");
//    Serial.println(amount);
    File dataFile = SD.open("registered.txt", FILE_WRITE);
      if (dataFile) {
      dataFile.println(message);
      dataFile.close();
      // print to the serial port too:
      Serial.println(message);
    }
    // if the file isn't open, pop up an error:
    else {
      Serial.println("error opening datalog.txt");
    }
}
else if(digitalRead(8) == HIGH){
  String myCustomer;
  File myFile = SD.open("registered.txt");
  if (myFile) {
  while (myFile.available()) {
      myCustomer = myFile.readStringUntil("\n");
    }
    myFile.close();
  } else {
    Serial.println("error opening test.txt");
  }
  }
}
bool compare(){}
