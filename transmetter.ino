#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
const uint64_t pipe = 0xE8E8F0F0E1LL;
RF24 radio(7, 8);
int datos[5];
int val_x;
int val_y;

void setup(void)
{
  radio.begin();
  radio.openWritingPipe(pipe);
  //radio.setDataRate(RF24_250KBPS); // Recommended use of the capacitor in case of activating this function
  radio.setRetries(15, 15);
  Serial.begin(9600);
}
void loop() {
  datos[0] = analogRead(1);
  datos[1] = analogRead(0);
  //datos[2]=analogRead(2); 
 // datos[3]=analogRead(3);
  bool ok = radio.write(datos, sizeof(datos));
  Serial.println(datos[0]);
}
