// We will be using D1 to control our LED
int ledPin = D1;

// Our button wired to D0
int buttonPin = D0;

// Define a pin that we'll place the pot on
int slidePin = A0;

// Create a variable to hold the pot reading
int slideReading = 0;

// Create a variable to store the LED brightness.
int ledBrightness = 0;

void setup()  {

  // Set up the LED for output
  pinMode(ledPin, OUTPUT);

  // Create a cloud variable of type integer
  // called 'light' mapped to photoCellReading
  Particle.variable("slide", &slideReading, INT);
  
  // For input, we define the
  // pushbutton as an input-pullup
  // this uses an internal pullup resistor
  // to manage consistent reads from the device


  pinMode( buttonPin , INPUT_PULLUP); // sets pin as input

  // We also want to use the LED

  pinMode( ledPin , OUTPUT ); // sets pin as output

}

void loop() {

  // Use analogRead to read the potentiometer reading
  // This gives us a value from 0 to 4095
  slideReading = analogRead(slidePin);

  // Map this value into the PWM range (0-255)
  // and store as the led brightness
  ledBrightness = map(slideReading, 0, 4095, 0, 255);

  // fade the LED to the desired brightness
  analogWrite(ledPin, ledBrightness);

  // wait 1/10th of a second and then loop
  delay(100);

  // find out if the button is pushed
  // or not by reading from it.
   int buttonState = digitalRead( buttonPin );

  // remember that we have wired the pushbutton to
  // ground and are using a pulldown resistor
  // that means, when the button is pushed,
  // we will get a LOW signal
  // when the button is not pushed we'll get a HIGH

  // let's use that to set our LED on or off

  if( buttonState == LOW )
  {
    // turn the LED On
    digitalWrite( ledPin, HIGH);
  }else{
    // otherwise
    // turn the LED Off
    digitalWrite( ledPin, LOW);

  }


}
