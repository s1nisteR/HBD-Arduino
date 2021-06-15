#define R 7
#define G 6
#define B 5
#define Y 4
#define W 3

#define MAX_NOTES 25

//Melody frequencies
unsigned int Notes[MAX_NOTES] = 
{
  262, 262, 294, 262, 349, 330, 262, 262, 294, 262, 392,
  360, 262, 262, 524, 440, 349, 330, 294, 466, 466, 440,
  349, 392, 360
};

unsigned char Durations[MAX_NOTES] = 
{
  1,1,2,2,2,3,1,1,2,2,2,3,1,1,2,2,2,2,2,
  1,1,2,2,2,3
};

unsigned int ledSequence[MAX_NOTES] = 
{
  7,7,6,5,4,3,5,4,3,5,6,
  7,3,4,5,6,7,4,4,6,7,3,
  4,5,7
};

unsigned int i;


void setup() {
  // put your setup code here, to run once:
  randomSeed(analogRead(0));
  pinMode(8, OUTPUT);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(W, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(R, LOW);
  digitalWrite(G, LOW);
  digitalWrite(B, LOW);
  digitalWrite(Y, LOW);
  digitalWrite(W, LOW);
}


void loop() {
  // put your main code here, to run repeatedly:
  for(i = 0; i < MAX_NOTES; i++)
  {
    tone(8, Notes[i]);
    digitalWrite(ledSequence[i], HIGH);
    delay(400 * Durations[i]);
    digitalWrite(ledSequence[i], LOW);
    noTone(8);
    delay(100);
  }
  delay(3000);
}
