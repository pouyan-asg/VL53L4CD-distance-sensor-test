/*
  Reading distance from the laser based VL53L1X
  By: Nathan Seidle
  SparkFun Electronics
  Date: April 4th, 2018
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  SparkFun labored with love to create this code. Feel like supporting open source hardware?
  Buy a board from SparkFun! https://www.sparkfun.com/products/14667

  This example prints the distance to an object.

  Are you getting weird readings? Be sure the vacuum tape has been removed from the sensor.
*/

#include <Wire.h>
#include "SparkFun_VL53L1X.h" //Click here to get the library: http://librarymanager/All#SparkFun_VL53L1X

//Optional interrupt and shutdown pins.
#define SHUTDOWN_PIN 2
#define INTERRUPT_PIN 3

SFEVL53L1X distanceSensor;
//Uncomment the following line to use the optional shutdown and interrupt pins.
//SFEVL53L1X distanceSensor(Wire, SHUTDOWN_PIN, INTERRUPT_PIN);

void setup(void)
{
  Wire.begin();

  Serial.begin(115200);
  Serial.println("VL53L1X Qwiic Test");
  distanceSensor.setOffset(2037);

  if (distanceSensor.begin() != 0) //Begin returns 0 on a good init
  {
    Serial.println("Sensor failed to begin. Please check wiring. Freezing...");
    while (1)
      ;
  }
  Serial.println("VL53L4CD sensor is online!");
}

void loop(void)
{
  distanceSensor.startRanging(); //Write configuration bytes to initiate measurement
  while (!distanceSensor.checkForDataReady())
  {
    delay(1);
  }
  int distance = distanceSensor.getDistance(); //Get the result of the measurement from the sensor
  distanceSensor.clearInterrupt();
  distanceSensor.stopRanging();

  Serial.print("Distance(mm): ");
  Serial.print(distance);

  float distanceInches = distance * 0.0393701;
  float distanceFeet = distanceInches / 12.0;

  // Serial.print("\tDistance(ft): ");
  // Serial.print(distanceFeet, 2);

  Serial.println();

  delay(5000);

}


// ----------------------------------
// // serial plotter 
// void loop(void)
// {
//   distanceSensor.startRanging(); // Write configuration bytes to initiate measurement
//   while (!distanceSensor.checkForDataReady())
//   {
//     delay(1);
//   }
//   int distance = distanceSensor.getDistance(); // Get the result of the measurement from the sensor
//   distanceSensor.clearInterrupt();
//   distanceSensor.stopRanging();

//   Serial.print(distance); // Print distance in mm for real-time plotting

//   Serial.println();

//   // Optional delay for better readability in the Serial Monitor
//   // delay(1000);
// }


// ----------------------------------


// void loop(void)
// {
//   unsigned long startTime = millis();  // Record the start time

//   while (millis() - startTime < 3000)  // Run the loop for 10 seconds
//   {
//     distanceSensor.startRanging(); // Write configuration bytes to initiate measurement
//     while (!distanceSensor.checkForDataReady())
//     {
//       delay(1);
//     }
//     int distance = distanceSensor.getDistance(); // Get the result of the measurement from the sensor
//     distanceSensor.clearInterrupt();
//     distanceSensor.stopRanging();

//     Serial.print("Distance(mm): ");
//     Serial.print(distance);

//     float distanceInches = distance * 0.0393701;
//     float distanceFeet = distanceInches / 12.0;

//     Serial.print("\tDistance(ft): ");
//     Serial.print(distanceFeet, 2);

//     Serial.println();
//   }
// }

// void loop(void)
// {
//   unsigned long startTime = millis();  // Record the start time
//   unsigned long elapsedTime;

//   do
//   {
//     distanceSensor.startRanging(); // Write configuration bytes to initiate measurement
//     while (!distanceSensor.checkForDataReady())
//     {
//       delay(1);
//     }
//     int distance = distanceSensor.getDistance(); // Get the result of the measurement from the sensor
//     distanceSensor.clearInterrupt();
//     distanceSensor.stopRanging();

//     Serial.print("Distance(mm): ");
//     Serial.print(distance);

//     float distanceInches = distance * 0.0393701;
//     float distanceFeet = distanceInches / 12.0;

//     Serial.print("\tDistance(ft): ");
//     Serial.print(distanceFeet, 2);

//     Serial.println();

//     elapsedTime = millis() - startTime;  // Calculate elapsed time

//   } while (elapsedTime < 3000);  // Run the loop for 10 seconds
// }

// void loop(void)
// {
//   unsigned long startTime = millis();  // Record the start time
//   unsigned int resultCounter = 0;      // Counter variable

//   while (millis() - startTime < 5000)  // Run the loop for 10 seconds
//   {
//     distanceSensor.startRanging(); // Write configuration bytes to initiate measurement
//     while (!distanceSensor.checkForDataReady())
//     {
//       delay(1);
//     }
//     int distance = distanceSensor.getDistance(); // Get the result of the measurement from the sensor
//     distanceSensor.clearInterrupt();
//     distanceSensor.stopRanging();

//     Serial.print("Distance(mm): ");
//     Serial.print(distance);

//     float distanceInches = distance * 0.0393701;
//     float distanceFeet = distanceInches / 12.0;

//     Serial.print("\tDistance(ft): ");
//     Serial.print(distanceFeet, 2);

//     Serial.println();

//     resultCounter++;  // Increment the counter
//   }

// delay(5000);

//   // Exit the loop after 10 seconds
//   while (true) {
//     Serial.print(resultCounter);
//     Serial.print("Pouyan ");
//     break;
//   }
// }

