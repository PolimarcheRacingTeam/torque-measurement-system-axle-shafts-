#include <SPI.h>
#include <SD.h>

File myFile;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Initializing SD card...");
  if (!SD.begin(4)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue*0.0048828125);
  myFile = SD.open("test.txt", FILE_WRITE);
  if(myFile){
    myFile.println(sensorValue*0.0048828125);
    myFile.close();
  }else{
    Serial.println("error opening text.txt");
  }
}
