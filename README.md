# arduino-fan-speed-controller
DC motor voltage/speed controller with buttons and LCD Screen

-Components-

Arduino Mega 2560 Microcontroller

Breadboard

Jumper Wires

3-6V Motor

Fan Blade

LCD1602 Module

NPN Transistor PN2222

Diode Rectifier/1N4007 Diode

Two 220 ohm Resistors

104pF Capacitor

-Libraries-

LiquidCrystal by Arduino, Adafruit

-IMPORTANT-

The circuit diagram shows pin 11 connected to Register Select and pin 12 connected to Enable, but if you have a different arduino board, connect it according to your SPI Bus pins

Pin 11 = MOSI/PICO

Pin 12 = MISO/POCI

The code used pins 50 and 51, please replace them with your respective SPI bus pins
