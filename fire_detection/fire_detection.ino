const int buzzerPin = 12; // Pin connected to the buzzer
const int flamePin = 11;  // Pin connected to the flame sensor
int Flame = LOW;         // Variable to store the flame sensor state
int redled = 5;           // Pin connected to the red LED
int greenled = 6;         // Pin connected to the green LED

void setup() 
{
  pinMode(buzzerPin, OUTPUT); // Set buzzer pin as output
  pinMode(redled, OUTPUT);    // Set red LED pin as output
  pinMode(greenled, OUTPUT);  // Set green LED pin as output
  pinMode(flamePin, INPUT);   // Set flame sensor pin as input

  Serial.begin(9600);         // Initialize serial communication at 9600 baud rate
}

void loop() 
{
  Flame = digitalRead(flamePin); // Read the state of the flame sensor

  if (Flame == HIGH) // If fire is detected
  {
    digitalWrite(buzzerPin, HIGH);    // Turn on the buzzer
    digitalWrite(redled, HIGH);       // Turn on the red LED
    digitalWrite(greenled, LOW);      // Turn off the green LED

                      
  }
  else // If no fire is detected
  {
    digitalWrite(buzzerPin, LOW);   // Turn off the buzzer
    digitalWrite(greenled, HIGH);   // Turn on the green LED
    digitalWrite(redled, LOW);      // Turn off the red LED
  }
}
