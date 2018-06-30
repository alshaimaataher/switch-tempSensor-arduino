- The application can be used in smart homes for lightning leds and monitoring the enviroment switch
- When using external interrupt for the switch, the interrupt can be triggered many times for one press, this can be solved by 
software by using millis()  arduino function to stop any other interrupt for milliseconds, but as this example we grauntee that 
every press the switch status must be different from its previous status we can use the XOR (^) to check it. 
-The switch is a pull up switch which means that its status is inverted, so it's considered in the code.
- For timer 1, a prescalar 1024 is used to give a 3 seconds. 
