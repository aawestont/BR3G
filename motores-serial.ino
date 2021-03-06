#include<Servo.h>

Servo myServo1;
Servo myServo2;
Servo myServo3;

int pos1;
int pos2;
int pos3;
int flag1;
int flag2;
int flag3;
void setup() 
{
  Serial.begin(9600); // Iniciar ccomunicacón serial
  
  // Vincular los motores a los pines 9, 10 y 11 del arduino
  myServo1.attach(9);
  myServo2.attach(10);
  myServo3.attach(11);
  
  // Posición inicial de los 3 motores = 0°
  myServo1.write(0);
  myServo2.write(0);
  myServo3.write(0);

  flag1 = 0;
  flag2 = 0;
  flag3 = 0;
}

void loop() 
{
  if(Serial.available() > 0) // Si hay comunicación serial (escribes algo en el monitor de serie)
    {
      if(Serial.peek() == 'q') //si escribes q y después un numero
        {
          Serial.read(); // Leer el dato despues de la letra "q"
          pos1 = Serial.parseInt(); // Guardar el dato en una variable como entero
        
        // Los "for loops" son para que se muevan despacio
        
          if (pos1 > flag3) // Si es mayor al ángulo anterior, sumar
            {     
              for (int i = flag3; i <= pos1; i++)
                {
                  myServo3.write(i);
                  delay(10);
                  flag3 = i;
                }
            }
          if (pos1 < flag3) // Si es menor al ángulo anterior, restar
            {
              for (int i = flag3; i >= pos1; i = i - 1)
                {
                  myServo3.write(i);
                  delay(10);
                  flag3 = i;
                }
            }
        }
    
    // Lo demás funciona de la misma manera
    
      if(Serial.peek() == 'w')
        {
          Serial.read();
          pos1 = Serial.parseInt();

          if (pos1 > flag2)
            {     
              for (int i = flag2; i <= pos1; i++)
                {
                  myServo2.write(i);
                  delay(10);
                  flag2 = i;
                }
            }
          if (pos1 < flag2)
            {
              for (int i = flag2; i >= pos1; i = i - 1)
                {
                  myServo2.write(i);
                  delay(10);
                  flag2 = i;
                }
            }
        }
       if(Serial.peek() == 'e')
        {
          Serial.read();
          pos1 = Serial.parseInt();

          if (pos1 > flag1)
            {     
              for (int i = flag1; i <= pos1; i++)
                {
                  myServo1.write(i);
                  delay(10);
                  flag1 = i;
                }
            }
          if (pos1 < flag1)
            {
              for (int i = flag1; i >= pos1; i = i - 1)
                {
                  myServo1.write(i);
                  delay(10);
                  flag1 = i;
                }
            }
        }
     
        }
    }
