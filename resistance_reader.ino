int inputPin = A5;
int raw = 0;
float Vin = 3.3;
float Vout = 0;
float R1 = 1000;
float R2 = 0;
float buf = 0;

/* 
  The resistance calculation is done using a voltage divide circuit. 
  The calculation below assumes that the known resistance is on the positive leg 
  and the unknown resistance is on the negative leg. 
  Like so:
 
               +---+ Vcc
               |
               \
   R1 (known)  /
               \
               |
               +---+ Vout (analog input pin to microcontroller)
               |
               \
  R2 (unknown) /
               \
               |
               +---+ Gnd

  Vout = (Vcc * R2) / (R1 + R2)
*/

void setup() {
  // put your setup code here, to run once:
  delay(500);
  Serial.begin(115200);
}

void loop()
{
  raw = analogRead(inputPin);
  if(raw)
  {
    Vout = raw * (Vin / 1024.0);
    R2 = R1 * (Vout / (Vin - Vout));
        
    //Serial.print("Vout: ");
    //Serial.println(Vout);
    //Serial.print("R2: ");
    Serial.println(R2);
  }
  delay(100);
}
