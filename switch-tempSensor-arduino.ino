const byte ledPin = 13; //Output digital pin connected to the led
const byte tempPin = 0; //Analog pin connected to LM35
const byte switchPin = 2; //Input digital pin connected the switch
volatile byte switchState; 
float referenceVoltage;
//------------------------------------------------------------------
//------------------------------------------------------------------
void setup() 
{
  // initialize timer1 
  cli();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 46875;            // compare match register 16MHz/256/(1/3)Hz (<65536)
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS10);    TCCR1B |= (1 << CS12);      // 1024 prescaler 
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  sei();                    // enable all interrupts
  //------------------------------------------------------------------
  //temprature sensor settings
  analogReference(INTERNAL);
  referenceVoltage = 1.1;  //Set to 5, 3.3, 2.56 or 1.1 depending on analogReference Setting
  //------------------------------------------------------------------
  //Switch and led settings
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(switchPin), toggle, CHANGE); //trigger interrupt when the switch status change
  switchState=!digitalRead(switchPin);   //switch initial status
  digitalWrite(ledPin,switchState);
  //------------------------------------------------------------------
  // Init serial monitor
  Serial.begin(9600);
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void loop() 
{
}
//------------------------------------------------------------------
//------------------------------------------------------------------
void toggle() 
{
  if ( switchState ^ (!digitalRead(switchPin)) )
  {
    Serial.println("//------------------------------------------------//");
    switchState = !digitalRead(switchPin);
    digitalWrite(ledPin,switchState);
    (switchState) ? Serial.println("Pressed!!\nLed Status: ON") : Serial.println("Led Status: OFF");
  }
}
//------------------------------------------------------------------------------------------------------
// timer compare interrupt service routine to print temprature sensor readings in Celsius and Fahrenheit
//------------------------------------------------------------------------------------------------------
ISR(TIMER1_COMPA_vect)          
{
  float  tempC =  (referenceVoltage * analogRead(tempPin) * 10) / 1023;
  Serial.println("//------------------------------------------------//");
  Serial.println("Temprature");
  Serial.print(tempC); Serial.println(" degrees C");
  //convert to Fahrenheit
  float tempF = (tempC * 9.0 / 5.0) + 32.0;
  Serial.print(tempF); Serial.println(" degrees F");
}
