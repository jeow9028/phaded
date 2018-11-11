#include <Key.h>
#include <Keypad.h>



//Project K JC


const byte ROWS = 4; // number of rows
const byte COLS = 4; // number of columns

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};      // row pinouts of the keypad R1 = D8, R2 = D7, R3 = D6, R4 = D5
byte colPins[COLS] = {5, 4, 3, 2};      // column pinouts of the keypad C1 = D4, C2 = D3, C3 = D2
//
//uint32_t red;
//uint32_t green;



Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);

  
  //Test Board works
//  pinMode(LED_BUILTIN, OUTPUT);

  //LED Red, LED2 Green
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

char password[4] = {'#','A','5','5'};
int count = 0;


char pushButton(){
  char key = keypad.getKey(); 
  while (key == NO_KEY){
    Serial.println(key);
    key = keypad.getKey();
  }
  return key;
    
}

void loop() {

//  red = 1;
//  green = 1;
  //  *********************** LED code********************

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  //digitalWrite(11, HIGH);  //Green
  //digitalWrite(12, HIGH);  //Red
  //ath(red, green);

  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  //  *********************** keypad code*****************

  char pass = pushButton();
//  *********************password ************************
  
     if (pass == password[count]) {
      count++;
      Serial.println(pass);
    } else {
         digitalWrite(11, HIGH);  //Red
         count = 0;
    }
  if (count == 4) {
       digitalWrite(12, HIGH);  //Green
       count = 0;
  }
}
//int  ath(uint32_t x, uint32_t y) {
//  if (x == 1) {
//    digitalWrite(11, HIGH);  //Green
//  }
//  if (y == 1) {
//    digitalWrite(12, HIGH);  //Red
//  }
//  return 0;
//}


