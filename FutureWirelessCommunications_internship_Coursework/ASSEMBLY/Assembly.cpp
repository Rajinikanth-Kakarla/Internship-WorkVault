#define LED_A 4
#define LED_B 5
#define LED_C 6
#define LED_D 7

int A = 0;
int B = 0; 

void setup() {
  pinMode(LED_A, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(LED_C, OUTPUT);
  pinMode(LED_D, OUTPUT);
}

void loop() {

  int notA = !A;
  int notB = !B;
  int firstTerm = notA && B;
  int secondTerm = A && notB;
  int result = not(firstTerm && secondTerm);

  digitalWrite(LED_A, result == (A or B) ); 
  digitalWrite(LED_B, result == (A && notB)); 
  digitalWrite(LED_C, result == (A && notB)); 
  digitalWrite(LED_D, result == notB); 
}