/* 
 *  Vêtement de signalisation cycliste
 *  Programmation allumage des bandes led du harnais
 *  avec joystick 5D et accéléromètre MPU6050
 *  Médiathèque Gaston Baissette - Février 2022
*/

//Librairies nécessaires

//LEDS
#include "SPI.h"
#include <FastLED.h>
// ACCELEROMETRE
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

//Adafruit_MPU6050 mpu;

// RECEPTEUR
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif
// Déclaration des broches utilisées
int right = 33;
int up = 26;
int down = 25;
int left = 32;

*/
// Définition des bandes leds

// Signalisation gauche

// Nbre de  leds sur bande led située à gauche du harnais
#define NUM_LEDS 19
// pin led signalisation gauche 
#define DATAPIN  17 
// création de l'objet led
CRGB leds[NUM_LEDS]; 


// Signalisation droite
// Nbre de  leds sur  bande led située à droite du harnais
#define NUM_LEDS2 19 
// pin led signalisation droite
#define DATAPIN2   16 
// création de l'objet led
CRGB leds2[NUM_LEDS2]; 


// variables de temps de pause
int tempo = 400;
int tempo2 = 30;
// vairiable mpu
sensors_event_t a, aold, g, temp;

void setup()
{
  // definition du sens de communication des broches
  pinMode(left, INPUT); 
  pinMode(right, INPUT); 
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(17, OUTPUT);
  pinMode(16, OUTPUT);
//  Serial.begin(9600);
Serial.begin(115200);
  while (!Serial)
    delay(10); // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("Adafruit MPU6050 test!");

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
  Serial.println("MPU6050 Found!");

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
//  Serial.print("Accelerometer range set to: ");
//  switch (mpu.getAccelerometerRange()) {
//  case MPU6050_RANGE_2_G:
//    Serial.println("+-2G");
//    break;
//  case MPU6050_RANGE_4_G:
//    Serial.println("+-4G");
//    break;
//  case MPU6050_RANGE_8_G:
//    Serial.println("+-8G");
//    break;
//  case MPU6050_RANGE_16_G:
//    Serial.println("+-16G");
//    break;
//  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
//  Serial.print("Gyro range set to: ");
//  switch (mpu.getGyroRange()) {
//  case MPU6050_RANGE_250_DEG:
//    Serial.println("+- 250 deg/s");
//    break;
//  case MPU6050_RANGE_500_DEG:
//    Serial.println("+- 500 deg/s");
//    break;
//  case MPU6050_RANGE_1000_DEG:
//    Serial.println("+- 1000 deg/s");
//    break;
//  case MPU6050_RANGE_2000_DEG:
//    Serial.println("+- 2000 deg/s");
//    break;
//  }
//
  mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
//  Serial.print("Filter bandwidth set to: ");
//  switch (mpu.getFilterBandwidth()) {
//  case MPU6050_BAND_260_HZ:
//    Serial.println("260 Hz");
//    break;
//  case MPU6050_BAND_184_HZ:
//    Serial.println("184 Hz");
//    break;
//  case MPU6050_BAND_94_HZ:
//    Serial.println("94 Hz");
//    break;
//  case MPU6050_BAND_44_HZ:
//    Serial.println("44 Hz");
//    break;
//  case MPU6050_BAND_21_HZ:
//    Serial.println("21 Hz");
//    break;
//  case MPU6050_BAND_10_HZ:
//    Serial.println("10 Hz");
//    break;
//  case MPU6050_BAND_5_HZ:
//    Serial.println("5 Hz");
//    break;
//  }

  Serial.println("");
  delay(100);
  
  // instanciation des bandes leds
  FastLED.addLeds<WS2812, DATAPIN, GRB>(leds, NUM_LEDS);  // typiquement GRB pour ws2812
  FastLED.addLeds<WS2812, DATAPIN2, GRB>(leds2, NUM_LEDS2);  // typiquement GRB pour ws2812
  delay(2000);
  mpu.getEvent(&a, &g, &temp);
  aold = a;

}
void loop()
{
  /* Get new sensor events with the readings */
  mpu.getEvent(&a, &g, &temp);
//  
//  /* Print out the values */
  Serial.print("Acceleration X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", old X: ");
  Serial.print(aold.acceleration.y);
  Serial.print(", Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", Z: ");
  Serial.print(a.acceleration.z);
  Serial.println(" m/s^2");

  Serial.print("Rotation X: ");
  Serial.print(g.gyro.x);
  Serial.print(", Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");

  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" degC");
//
  Serial.print("aold - a : ");
  Serial.print(a.acceleration.y - aold.acceleration.y);
  Serial.println("");
  delay(100);

  //////////////////////////////////////////////////////////////////////////////
 //SOLUTION A TROUVER POUR LA GESTION DE L'ACCELEROMETRE 
  //////////////////////////////////////////////////////
  
// Traitement des infos en provenance de l'accelerometre
//  if(a.acceleration.y - aold.acceleration.y < -5) // VALEUR A DETERMINER
//  {
//    Frein();
//  }
////////////////////////////////////////////////////////////////////////////////  
  
  Serial.print("up :");
  Serial.println(digitalRead(up));
  Serial.print("down :");
  Serial.println(digitalRead(down));
  Serial.print("left :");
  Serial.println(digitalRead(left));
  Serial.print("right :");
  Serial.println(digitalRead(right));
  // Traitement des infos en provenance du recepteur radio
  if(digitalRead(down) == 1)
  {
  orderleds("Gauche");
  }
  if(digitalRead(up) == 1)
  {
    orderleds("Droite");
  }
  if(digitalRead(right) == 1)//digitalRead(center) == 1 ||
  {
    Frein();
  }
  if(digitalRead(left) == 1)//digitalRead(center) == 1 ||
  {
    Extinction();
  }
  
  delay(100);
  //aold = a;
  Serial.println(digitalRead(up));
  Serial.println(digitalRead(down));
  Serial.println(digitalRead(left));
   Serial.println(digitalRead(right));
}

//Méthode qui allume en rouge les leds situées dans le dos du harnais 
void Frein()
{
  for (int i = 0; i < 15; i++)
  {
    for (int i = 0; i < 14; i++)
    {
      leds[i] = CRGB::Red;
      leds2[i] = CRGB::Black;
    }
    FastLED.show(); // Refresh strip
    delay(250);
    for (int i = 1; i < 15; i++)
    {
      leds[i] = CRGB::Black;
      leds2[i] = CRGB::Red;
    }
    FastLED.show(); // Refresh strip
    delay(250);
//     if(digitalRead(left == 1))
//      {
//        break;
//      }
  }
  Extinction();
    FastLED.show(); // Refresh strip
}

//Méthode qui allume les leds de l'épaule droite du harnais
void EpauleDroite()
{
  //allumage épaule droite
  for (int i = 14; i < 19; i++)
  {
    leds2[i] = CRGB::Orange;
  }
}

//Méthode qui allume les leds de l'épaule gauche du harnais
void EpauleGauche()
{
  //allumage épaule droite
  for (int i = 14; i < 19; i++)
  {
    leds[i] = CRGB::Orange;
  }
}


// Méthode qui éteint toutes les leds des deux bandes led
void Extinction()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black;
  }
  for (int i = 0; i < NUM_LEDS2; i++)
  {
    leds2[i] = CRGB::Black;
  }
  FastLED.show(); // Refresh strip
}


// Méthode qui pilote l'allumage des leds
void orderleds(String Direction)
{
  if (Direction == "Droite")
  {
    // 10 clignotements
    for (int i = 1; i < 10; i++)
    {
      // Allumage épaule droite
      EpauleDroite();
      // Allumage X gauche
      leds[3] = CRGB::Orange;
      leds[4] = CRGB::Orange;
      leds[5] = CRGB::Orange;
      leds[6] = CRGB::Orange;
      leds[11] = CRGB::Orange;
      leds[12] = CRGB::Orange;
      leds[13] = CRGB::Orange;
      
      
      FastLED.show(); // Refresh strip
      delay(tempo);
      
      Extinction();
      
      // Allumage épaule droite
      EpauleDroite();
      
      // Allumage X droit
      leds2[0] = CRGB::Orange;
      leds2[1] = CRGB::Orange;
      leds2[2] = CRGB::Orange;
      leds2[3] = CRGB::Orange;
      leds2[7] = CRGB::Orange;
      leds2[8] = CRGB::Orange;
      leds2[9] = CRGB::Orange;
      
      
      FastLED.show(); // Refresh strip
      delay(tempo);
      
      Extinction();
      delay(tempo);
//      if(digitalRead(left == 1))
//      {
//        break;
//      }
      
    }
  }
  else if (Direction == "Gauche")
  {
    // 10 clignotements
    for (int i = 0; i < 10; i++)
    {
      // Allumage épaule gauche
      EpauleGauche();
      // Allumage X droit
      leds2[3] = CRGB::Orange;
      leds2[4] = CRGB::Orange;
      leds2[5] = CRGB::Orange;
      leds2[6] = CRGB::Orange;
      leds2[11] = CRGB::Orange;
      leds2[12] = CRGB::Orange;
      leds2[13] = CRGB::Orange;


      FastLED.show(); // Refresh strip
      delay(tempo);
      
      Extinction();

      // Allumage épaule gauche
      EpauleGauche();
      
      // Allumage x gauche
      leds[0] = CRGB::Orange;
      leds[1] = CRGB::Orange;
      leds[2] = CRGB::Orange;
      leds[3] = CRGB::Orange;
      leds[7] = CRGB::Orange;
      leds[8] = CRGB::Orange;
      leds[9] = CRGB::Orange;

      FastLED.show(); // Refresh strip
      delay(tempo);
      
      Extinction();
      
      delay(tempo);
//      if(digitalRead(left == 1))
//      {
//        break;
//      }
    }
  }
  else
  {
    Extinction();
  }
}
