int i;

void setup()
{
	// initialize serial communication at 9600 bits per second:
	Serial.begin ( 9600 );
	delay ( 500 );
	i = 100;
}

// the loop routine runs over and over again forever:
void loop()
{
	Serial.println ( i );
	i = i + 1;
	delay ( 100 );     // delay in between reads for stability
}
