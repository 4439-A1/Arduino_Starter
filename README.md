# Arduino_Starter
This repository contains code and documentation that describes what I have learned from the Arduino starter kit.

## Project 2: Spaceship Interface

In this project, I learned the basics of controlling the pins on the Arduino board using the commands pinMode(), digitalRead(), and digitalWrite ().

The code is designed to flash between the two red LEDs controlled by pins 4 and 5 whenever the button is pressed. We detect the button being pressed by reading the state of pin 2.

Otherwise, the green LED is turned on, by writing a HIGH output to pin 3.

## Project 3: Love-O-Meter

The purpose of this project was to take advantage of the TMP36 sensor to read the temperature.

The TMP36 temperature sensor has three pins: a power pin which is the left pin on the flat side, a ground pin which is the right pin, and importantly, an analog output pin which is the pin in the middle. I wired this analog output pin to the pin A0 on the arduino, which is one of the analog input pins. The analog reading ranges from 0 to 1024. To convert this to a voltage reading, I use the formula below:

$$V = (A/1024) \cdot 5.0$$

Next, from the data sheet, we can find that the temperature can be found from the voltage $V$ by the below formula:

$$T = (V-.5)\cdot100$$

as the offset voltage is .5 V (to display temperature in the negatives), and each 0.01 V (or 10 mV) corresponds to a 1 degree Celsius increment.
<img width="362" alt="image" src="https://github.com/4439-A1/Arduino_Starter/assets/84205848/ce2b0136-da1e-4bd6-80b3-06184b718891">
