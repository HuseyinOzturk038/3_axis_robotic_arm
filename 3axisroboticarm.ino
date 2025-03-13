/*bu proje Aralık 2024 yılında aşağıdaki kişiler tarafından oluşturulmuştur:
 Hüseyin Öztürk -HuseyinOzturk038
 Beran Deniz Akar -BDeniz24
 Emre Burak Kaya -EmreBurakKaya
 Kerim Bilik -KerimBilik
*/
#include  <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
const int LED1 = 7;
const int LED2 = 8;
const int LED3 = 4;
const int LED4 = 10;
const int LED5 = 11;
const int ledPins[] = {LED1, LED2, LED3, LED4, LED5};
const int button1 = 12;
const int button2 = 13;
int button1deger = 0;
boolean button2deger = false;
const int pot1 = A2;
const int pot2 = A1;
const int pot3 = A0;
const int pot4 = A3;
int pot1deger;
int pot2deger;
int pot3deger;
int pot4deger;
int pot1aci;
int pot2aci;
int pot3aci;
int pot4aci;
int servo1Poskayit[] = {1,1,1,1,1};
int servo2Poskayit[] = {1,1,1,1,1};
int servo3Poskayit[] = {1,1,1,1,1};
int servo4Poskayit[] = {1,1,1,1,1};
void setup() {
  servo1.attach(3);
  servo2.attach(5);
  servo3.attach(6);
  servo4.attach(9);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Serial.begin(9600);
}
void loop()  {
 pot1deger = analogRead(pot1);
 pot1aci = map(pot1deger,0, 1023, 0, 180);
 pot2deger = analogRead(pot2);
 pot2aci = map(pot2deger,0, 1023, 0, 180);
 pot3deger =  analogRead(pot3);
 pot3aci = map(pot3deger, 0,1023, 90, 180);
 pot4deger = analogRead(pot4);
 pot4aci = map(pot4deger,0, 1023, 0, 180);
 servo1.write(pot1aci);
 servo2.write(pot2aci);
 servo3.write (pot3aci);
 servo4.write(pot4aci);
  if(digitalRead(button1) == HIGH){
    delay(200);
    if (button1deger >= 0 && button1deger < 10){
        int i = button1deger;
        
        servo1Poskayit[i] = pot1aci;
        servo2Poskayit[i] = pot2aci;
        servo3Poskayit[i] = pot3aci;
        servo4Poskayit[i] = pot4aci;

        if (i < 5) {
            digitalWrite(ledPins[i], HIGH);
        } else {
            digitalWrite(ledPins[i-5], LOW);
        }

        Serial.print("Pos ");
        Serial.print(button1deger+1);
        Serial.println(" Kayit");
        button1deger++;
    }
  }
  if(digitalRead(button2) == HIGH){
      button2deger = true;
     }
     if(button2deger) {
       for(int i = 0; i < 10; i++) {
         servo1.write(servo1Poskayit[i]);
         servo2.write(servo2Poskayit[i]);
         servo3.write(servo3Poskayit[i]);
         servo4.write(servo4Poskayit[i]);
         delay(600);
         Serial.println("Potansiyometre acilari:");
         Serial.println(servo1Poskayit[i]);
         Serial.println(servo2Poskayit[i]);
         Serial.println(servo3Poskayit[i]);
         Serial.println(servo4Poskayit[i]);
         delay(1000);
       }
     }
     delay(30);
}