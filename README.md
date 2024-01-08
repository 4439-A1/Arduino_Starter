# Arduino Starter Kit
This repository contains code and documentation that describes what I have learned from the Arduino starter kit.

## Project 2: Spaceship Interface

In this project, I learned the basics of controlling the pins on the Arduino board using the commands `pinMode()`, `digitalRead()`, and `digitalWrite()`.

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

Once I found the temperature, I used if/else loops in the code to control the output pins wired to LED indicators. The green LED indicates the temperature being above the baseline temperature (I set this to 19 degrees as I did this project over winter break and thus the room was cold). For every 1.5 degrees Celsius increase above this baseline temperature, one LED was set to turn on.

## Project 4: Color Mixing Lamp

The purpose of the project was to detect Red, Green, and Blue light from the room's natural lighting and produce a light which depends on the external conditions.

I used three phototransistors, each of which were covered by colored gel which filter the light coming in. Each photoresistor results in an analog reading ranging from 0 to 1023, and we divide this value by 4 to get a value ranging from 0 to 255. This gives our duty cycle.

The duty cycle is given as a fraction of 255. Thus, if our reading for green light is 1000, we will get 250 by dividing by 4, and the duty cycle will be 250/255=98%.

We output the duty cycle to the corresponding LED in the multicolor LED, to produce a nice off-white color light (in natural lighting conditions). This is done by using the `analogWrite()` function, which takes two arguments: the pin to write to, and the duty cycle (in the notation discussed above).
