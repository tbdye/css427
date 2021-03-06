// 3. Difficult (30 min): Implement a simple calculator which can only do multiplication
// a. Use the “#” key as “=”, use the “*” key as multiplication
// b. If multiple keys are pressed before “*” or “*”, those keys form an integer
// c. if “#” is pressed, print the equation to the host PC, e.g., 11*12*13=1716

#include <Key.h>
#include <Keypad.h>
  
const byte rows = 4; //four rows
const byte cols = 3; //three columns
char keys[rows][cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[rows] = {18, 17, 16, 15}; //connect to the row pinouts of the keypad
byte colPins[cols] = {21, 20, 19}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, rows, cols );

String equation;
String number;
int total;

// Setup
void setup()
{
  equation = "";
  number = "";
  total = 0;

  Serial.begin(9600);
}

// Loop
void loop()
{
  char key = keypad.getKey();
  
  if (key != NO_KEY)
  {
    Serial.println(key);

    if (key == '#' || key == '*')
    {
      if (equation.length() != 0)
      {
        equation += "*";
      }
      equation += number;

      if (total == 0)
      {
        total = number.toInt();
      }
      else
      {
        total *= number.toInt();
      }

      // equals
      if (key == '#')
      {
        Serial.println(equation + "=" + String(total));
        
        equation = "";
        number = "";
        total = 0;
      }
      // multiply
      else if (key == '*')
      {
        Serial.println(equation);
        
        number = "";
      }
    }
    // build a number
    else
    {
      number += key;
    }
  }   
}
  
