int brightness = 0;
int fadeAmount = 5;
int flag=0;
int regim=0;
int led1 = 3;
int led2 = 5;
int led3 = 6;
int led4 = 10;
int ledState11 = LOW;
int ledState12 = HIGH;
int ledState21 ;
int ledState22 ;
int ledState23 ;
int ledState24 ;
int i=0;
int k=0;
unsigned long previousMillis = 0;
unsigned long currentTime;
unsigned long loopTime;
const long interval = 1500;

void setup()
{

     pinMode(led1, OUTPUT);
     pinMode(led2, OUTPUT);
     pinMode(led3, OUTPUT);
     pinMode(led4, OUTPUT);

}

void loop()

{
     if(digitalRead(2)==HIGH&&flag==0)
     {
       regim++;
       flag=1;
         if(regim>4)
           {
            regim=1;
           }

     }

     if(digitalRead(2)==LOW&&flag==1)
     {
        flag=0;
     }


if(regim==1) //первый режим

{
unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
   {
     previousMillis = currentMillis;

     if (ledState11 == LOW)
      {
        ledState11 = HIGH;
        ledState12 = LOW;
      }
     else
      {
        ledState11 = LOW;
        ledState12 = HIGH;
      }

    digitalWrite(led1, ledState11);
    digitalWrite(led2, ledState11);
    digitalWrite(led3, ledState12);
    digitalWrite(led4, ledState12);
  }
}

if(regim==2) //второй режим

{
unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval)
   {
     previousMillis = currentMillis;
     i++; if(i>=5) {i=1;}

     if (i==1) {
         ledState21 = HIGH;
         ledState22 = LOW;
         ledState23 = LOW;
         ledState24 = LOW;
               }

     if (i==2) {
         ledState21 = LOW;
         ledState22 = HIGH;
         ledState23 = LOW;
         ledState24 = LOW;
               }

     if (i==3) {
         ledState21 = LOW;
         ledState22 = LOW;
         ledState23 = HIGH;
         ledState24 = LOW;
               }

     if (i==4) {
         ledState21 = LOW;
         ledState22 = LOW;
         ledState23 = LOW;
         ledState24 = HIGH;
               }

     digitalWrite(led1, ledState21);
     digitalWrite(led2, ledState22);
     digitalWrite(led3, ledState23);
     digitalWrite(led4, ledState24);
   }
}

if(regim==3) //третий режим
{
unsigned long currentTime = millis();

  if(currentTime >= (loopTime + 20))
   {
     analogWrite(led1, brightness);
     analogWrite(led2, brightness);
     analogWrite(led3, brightness);
     analogWrite(led4, brightness);

     brightness = brightness + fadeAmount;

       if (brightness == 0 || brightness == 255)
        {
          fadeAmount = -fadeAmount ;
        }
     loopTime = currentTime;
    }
}

if(regim==4) //четвертый режим
{
unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
   {
     previousMillis = currentMillis;
      k++; if(k>=7) {k=1;}

      if (k==1) {
          ledState21 = HIGH;
          ledState22 = LOW;
          ledState23 = LOW;
          ledState24 = LOW;
                }

      if (k==2) {
          ledState21 = LOW;
          ledState22 = HIGH;
          ledState23 = LOW;
          ledState24 = LOW;
                }

      if (k==3) {
          ledState21 = LOW;
          ledState22 = LOW;
          ledState23 = HIGH;
          ledState24 = LOW;
                }

      if (k==4) {
          ledState21 = LOW;
          ledState22 = LOW;
          ledState23 = LOW;
          ledState24 = HIGH;
                }

      if (k==5) {
          ledState21 = LOW;
          ledState22 = LOW;
          ledState23 = HIGH;
          ledState24 = LOW;
                }

      if (k==6) {
          ledState21 = LOW;
          ledState22 = HIGH;
          ledState23 = LOW;
          ledState24 = LOW;
                 }

      digitalWrite(led1, ledState21);
      digitalWrite(led2, ledState22);
      digitalWrite(led3, ledState23);
      digitalWrite(led4, ledState24);
   }
}
}
