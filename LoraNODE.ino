#include <SPI.h>
#include <LoRa.h>

int nodenumber = 1;

int counter = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial);
    // Configurar los pines para LoRa
  int ss = 5;      // Pin SS
  int rst = 34;    // Pin RESET
  int dio0 = 35;   // Pin DIO0

  LoRa.setPins(ss, rst, dio0);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("Node ");
  LoRa.print(nodenumber);
  LoRa.print("  Readings ");
  LoRa.print(counter);
  LoRa.endPacket();

  counter++;

  delay(1000);
}

