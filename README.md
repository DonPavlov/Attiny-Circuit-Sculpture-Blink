# Circuit Sculpture Blink Code

This repository contains the code to create a small and easy to use Circuit Sculpture Code.

![](img/circuit-sculpture.gif)

## Functionality
The Code just uses an Attiny45, with an Arduino Bootloader programmed into, via USBASP.

It sleeps and waits until a Button Press via Interrupt wakes it up and then starts waking it up and blinking "I love you" in morse.

After that it sleeps again. 

The code is in no way optimised, but just a quick way to get it done as a present.

### Needed Tools
* Arduino with USBasp / or
* USBasp programmer
* Small breadboard to program and test
* LED
* Button
* Dupont Jumper Cables

## Programming with a USBASP

// TODO  (INSERT IMAGEs HERE of USBASP and Connections)
Connect it the following way:

* MOSI to MOSI ATTiny pin 5
* MISO to MISO ATTiny pin 6
* SCK to SCK ATTiny pin 7
* Reset to RESET ATTiny pin 1
* VCC to VCC ATTiny pin 8
* GND to GND ATTiny pin 4

