# switch-tempSensor-arduino

This is an arduino UNO code for ON/OFF switch for lightning a led with temprature sensor (LM53)

# Instructions:
- Connect your switch with the digital pin 2 in your arduino kit, Read the link below dertermine the interrupt digtal pin for your board: 
https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
- Connect your led with digital pin 13 in your arduino kit.
- Connect your temprature sensor input pin with analog pin A0 in your arduino kit.

# Overview:
- The switch uses arduino external interrupt for providing whether it's pressed and also the led status on serial monitor.
- The temprature sensor uses arduino Timer1 interrupt for monitoring the temprature in Celsius and Fahrenheit every 3 seconds, The used reference voltage is 1.1v for more accurate reading, for more information, read the links below:
https://playground.arduino.cc/Main/LM35HigherResolution
https://www.timdejong.nl/blog/get-accurate-temperature-lm35-arduino-correctly
