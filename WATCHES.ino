/* +-----------------------------------------------+
   |                                               |
   | +-------------------------------------------+ |
   | |-----------WERY BIG WALL WATCHES-----------| |
   | +-------------------------------------------+ |
   | ____W____  ____X____ DOT ____Y____  ____Z____ |
   |  +--A--+    +--A--+       +--A--+    +--A--+  |
   |  F     B    F     B   +   F     B    F     B  |
   |  +--G--+    +--G--+       +--G--+    +--G--+  |
   |  E     C    E     C   +   E     C    E     C  |
   |  +--D--+    +--D--+       +--D--+    +--D--+  |
   | ____W____  ____X____ DOT ____Y____  ____Z____ |
   |                                               |
   +-----------------------------------------------+
   A-G = 2-8
   DOT = 9
   W A0=14
   X A1=15
   Y A2=16
   Z A3=17
*/
#define USE_TRANSISTORS
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8

#define DOT 9

#define W 14
#define X 15
#define Y 16
#define Z 17

#define tBlink 500
#define tTick 60*1000

unsigned long blinkUpdate = 0;
unsigned long tickUpdata  = 0;
int hours = 0;
int minutes = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(DOT, OUTPUT);
  pinMode(W, OUTPUT);
  pinMode(X, OUTPUT);
  pinMode(Y, OUTPUT);
  pinMode(Z, OUTPUT);
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  digitalWrite(DOT, LOW);
#ifdef USE_TRANSISTORS
  digitalWrite(W, LOW);
  digitalWrite(X, LOW);
  digitalWrite(Y, LOW);
  digitalWrite(Z, LOW);
#else
  digitalWrite(W, !LOW);
  digitalWrite(X, !LOW);
  digitalWrite(Y, !LOW);
  digitalWrite(Z, !LOW);
#endif

}

void loop() {
  // get current millis
  unsigned long currentMillis = millis();
  //blink doubledot
  if ((currentMillis - blinkUpdate) >= tBlink ) {
    digitalWrite(DOT, !digitalRead(DOT));
    blinkUpdate = currentMillis;
  }
  //update time
  if ((currentMillis - tickUpdata) >= tTick ) {
    tick ();
    tickUpdata = currentMillis;
  }
  for (int i = 0; i < 4; i++) {
    disp(char(hours / 10), 0);
    disp(char(hours % 10), 1);
    disp(char(minutes / 10), 2);
    disp(char(minutes % 10), 3);

  }
}

void tick () {
  minutes++;
  if (minutes >= 60) {
    minutes = 0;
    hours++;
  }
  if (hours >= 24) hours = 0;
}

void disp(char x, int y) {
#ifdef USE_TRANSISTORS
  switch (y) {
    case 0:
      digitalWrite(W, HIGH);
      digitalWrite(X, LOW);
      digitalWrite(Y, LOW);
      digitalWrite(Z, LOW);
      break;
    case 1:
      digitalWrite(W, LOW);
      digitalWrite(X, HIGH);
      digitalWrite(Y, LOW);
      digitalWrite(Z, LOW);
      break;
    case 2:
      digitalWrite(W, LOW);
      digitalWrite(X, LOW);
      digitalWrite(Y, HIGH);
      digitalWrite(Z, LOW);
      break;
    case 3:
      digitalWrite(W, LOW);
      digitalWrite(X, LOW);
      digitalWrite(Y, LOW);
      digitalWrite(Z, HIGH);
      break;
    default:
      digitalWrite(W, LOW);
      digitalWrite(X, LOW);
      digitalWrite(Y, LOW);
      digitalWrite(Z, LOW);
      break;
  }
#else
  switch (y) {
    case 0:
      digitalWrite(W, !HIGH);
      digitalWrite(X, !LOW);
      digitalWrite(Y, !LOW);
      digitalWrite(Z, !LOW);
      break;
    case 1:
      digitalWrite(W, !LOW);
      digitalWrite(X, !HIGH);
      digitalWrite(Y, !LOW);
      digitalWrite(Z, !LOW);
      break;
    case 2:
      digitalWrite(W, !LOW);
      digitalWrite(X, !LOW);
      digitalWrite(Y, !HIGH);
      digitalWrite(Z, !LOW);
      break;
    case 3:
      digitalWrite(W, !LOW);
      digitalWrite(X, !LOW);
      digitalWrite(Y, !LOW);
      digitalWrite(Z, !HIGH);
      break;
    default:
      digitalWrite(W, !LOW);
      digitalWrite(X, !LOW);
      digitalWrite(Y, !LOW);
      digitalWrite(Z, !LOW);
      break;
  }
#endif
  switch (x) {
    case '0':
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
    case '1':
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    case '2':
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;
    case '3':
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case '4':
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case '5':
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case '6':
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case '7':
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    case '8':
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case '9':
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, LOW);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 'A':
      digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 'B':
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 'C':
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, LOW);
      break;
    case 'D':
      digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, LOW);
      digitalWrite(G, HIGH);
      break;
    case 'E':
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 'F':
      digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case 't':
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      digitalWrite(E, HIGH);
      digitalWrite(F, HIGH);
      digitalWrite(G, HIGH);
      break;
    case '-':
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
    case ' ':
    default:
      digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      digitalWrite(E, LOW);
      digitalWrite(F, LOW);
      digitalWrite(G, LOW);
      break;
  }
}
