unsigned char memory8[512];

char fileName[16];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.println("Ymodem test: ");

  delay(100);

  int fileSize = Ymodem_Receive(memory8, 2 * 1024, fileName);

  if (fileSize <= 0) {
    Serial.println("receive error!");
  } else {
    Serial.println("Receive done! :D");
    Serial.print("File name: ");
    Serial.println(fileName);
    Serial.print("Size: ");
    Serial.println(fileSize, DEC);

    Serial.println("\nShowing file contents:");
    for (uint32_t i = 0; i < 512; i++)
      Serial.print((char)memory8[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
