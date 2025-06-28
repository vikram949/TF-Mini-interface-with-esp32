
// 5V oprating so use the esp32 to vin pin get the 5v only 32 but 8266 not give a 5v in vin because using reverse current blok that case use vn pin in esp8266
#define RXD2 16
#define TXD2 17

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  Serial.println("TFmini-S Start...");
}

void loop() {
  if (Serial2.available() >= 9) {
    if (Serial2.read() == 0x59) {
      if (Serial2.read() == 0x59) {
        uint8_t raw[7];
        for (int i = 0; i < 7; i++) {
          raw[i] = Serial2.read();
        }

        uint16_t dist = raw[0] + (raw[1] << 8);
        uint16_t strength = raw[2] + (raw[3] << 8);
        uint16_t tempRaw = raw[4] + (raw[5] << 8);
        float temperature = tempRaw / 8.0 - 256;

        uint8_t checksum = (0x59 + 0x59);
        for (int i = 0; i < 6; i++) {
          checksum += raw[i];
        }

        if (checksum == raw[6]) {
          Serial.print("Distance: ");
          Serial.print(dist);
          Serial.print(" cm\t");

          Serial.print("Strength: ");
          Serial.print(strength);
          Serial.print("\t");

          Serial.print("Temperature: ");
          Serial.print(temperature);
          Serial.println(" °C");
        }
      }
    }
  }
}
