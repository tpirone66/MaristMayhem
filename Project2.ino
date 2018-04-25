/*
 * Trevor Pirone
 * Professor Gormanly
 * 4/25/2018
 * Project 2: Marist Mayhem!
 * 
 * Marist Mayhem! is a quiz game that tests the player's knowledge
 * as it pertains to Marist College. There are 20 questions in the game.
 * If you get the question right, the screen displays the correct screen.
 * If you get it wrong, the incorrect screen will display. Each question is 
 * worth 10 points. At the end of the quiz, the program will determine 
 * your status. This means that it will display a message determinimg if
 * you attend Marist, if you are a Red Fox, etc. Depending on the score you
 * get will determine your pending status which will also be reflected
 * by the color the LED lights up.
 * 
 */

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11, 12, 2, 3, 4, 5);

// need this if the LED is an anode LED which it is in this case
#define COMMON_ANODE;

// set up constants for the contrast and backlight pin
const int contrastPin = 8;
const int backlightPin = 13;

// set up constants for RGB LED
const int redPin = 10;
const int bluePin = 6;
const int greenPin = 9;

// random numbers defined to change LED at the splash screen
int randNum;
int randNum2;
int randNum3;

// variables to hold the value of the switch pins
int switch1State = 0;
int switch2State = 0;
int switch3State = 0;

// variables to hold previous value of the switch pins
int prevSwitch1State = 0;
int prevSwitch2State = 0;
int prevSwitch3State = 0;

// default value of screen contrast
int contrast = 0;
int backlight = 255;

// initialize the starting screen
int screen = 0;

// keep track of question number
int questionNumber = 0;

// score
int score = 0;
int highScore;

// variables to scroll text or not scroll text
String noScroll, scroll;

// the last time the output pin was toggled
unsigned long lastDebounceTime = 0;
// the debounce time; increase if the output flickers
unsigned long debounceDelay = 100;

// setup method
void setup() {
  /* 
   * This allows to assign an empty pin to generate random numbers
   * each different execution time. After randomSeed(), the game 
   * initializes the splash screen and other necessary game
   * elements.
   * 
   */
  randomSeed(analogRead(5));
  score = 0;
  lcd.begin(16, 2);
  analogWrite(contrastPin, contrast);
  analogWrite(backlightPin, backlight);
  lcd.setCursor(0, 0);
  noScroll = " Marist Mayhem! ";
  scroll = " Press the middle button to advance. ";
  lcd.print(noScroll);
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

// loop method
void loop() {
  // define the read states for the switches and their pins
  switch1State = digitalRead(16);
  switch2State = digitalRead(15);
  switch3State = digitalRead(14);

  // splash screen
  if (screen == 0) {
    randNum = random(256);
    randNum2 = random(256);
    randNum3 = random(256);
    setColor(randNum, randNum2, randNum3);
    lcd.setCursor(0, 1);
    scroll = scrollText(scroll);
    lcd.print(scroll);
  }

  // question screens that set scroll parameters for the question
  if (screen > 0 && screen < 21) {
    lcd.setCursor(0, 0);
    scroll = scrollText(scroll);
    lcd.print(scroll);
  }
  
  // displays question 1
  if (screen == 1) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // incorrect answer
        if (prevSwitch1State != switch1State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // correct answer
        if (prevSwitch3State != switch3State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }
  
  // displays question 2
  if (screen == 2) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // correct answer
        if (prevSwitch1State != switch1State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // incorrect answer
        if (prevSwitch3State != switch3State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }
  
  // displays question 3
  if (screen == 3) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // correct answer
        if (prevSwitch1State != switch1State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // incorrect answer
        if (prevSwitch3State != switch3State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }
  
  // displays question 4
  if (screen == 4) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // incorrect answer
        if (prevSwitch1State != switch1State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // correct answer
        if (prevSwitch3State != switch3State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }
  
  // displays question 5
  if (screen == 5) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // incorrect answer
        if (prevSwitch1State != switch1State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // correct answer
        if (prevSwitch3State != switch3State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }
  
  // displays question 6
  if (screen == 6) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // incorrect answer
        if (prevSwitch1State != switch1State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // correct answer
        if (prevSwitch3State != switch3State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 7
  if (screen == 7) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // correct screen
        if (prevSwitch1State != switch1State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // incorrect screen
        if (prevSwitch3State != switch3State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 8
  if (screen == 8) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // correct screen
        if (prevSwitch1State != switch1State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // incorrect screen
        if (prevSwitch3State != switch3State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 9
  if (screen == 9) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // incorrect screen
        if (prevSwitch1State != switch1State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // correct screen
        if (prevSwitch3State != switch3State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 10
  if (screen == 10) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // correct screen
        if (prevSwitch1State != switch1State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // incorrect screen
        if (prevSwitch3State != switch3State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 11
  if (screen == 11) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // incorrect screen
        if (prevSwitch1State != switch1State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // correct screen
        if (prevSwitch3State != switch3State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 12
  if (screen == 12) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // incorrect screen
        if (prevSwitch1State != switch1State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // correct screen
        if (prevSwitch3State != switch3State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 13
  if (screen == 13) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // correct screen
        if (prevSwitch1State != switch1State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // incorrect screen
        if (prevSwitch3State != switch3State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 14
  if (screen == 14) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // incorrect screen
        if (prevSwitch1State != switch1State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // correct screen
        if (prevSwitch3State != switch3State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 15
  if (screen == 15) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // correct screen
        if (prevSwitch1State != switch1State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // incorrect screen
        if (prevSwitch3State != switch3State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 16
  if (screen == 16) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // incorrect screen
        if (prevSwitch1State != switch1State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // correct screen
        if (prevSwitch3State != switch3State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 17
  if (screen == 17) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // correct screen
        if (prevSwitch1State != switch1State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // incorrect screen
        if (prevSwitch3State != switch3State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 18
  if (screen == 18) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // correct screen
        if (prevSwitch1State != switch1State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // incorrect screen
        if (prevSwitch3State != switch3State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 19
  if (screen == 19) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // incorrect screen
        if (prevSwitch1State != switch1State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // correct screen
        if (prevSwitch3State != switch3State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays question 20
  if (screen == 20) {
    if (millis() - lastDebounceTime > debounceDelay) {
      if (switch1State == HIGH) {
        // correct screen
        if (prevSwitch1State != switch1State) {
          correctScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
      if (switch3State == HIGH) {
        // incorrect screen
        if (prevSwitch3State != switch3State) {
          incorrectScreen();
          scroll = " Press the middle button to advance. ";
        }
      }
    }
  }

  // displays the end of game screen
  if (screen == 21) {
    lcd.setCursor(0, 1);
    scroll = scrollText(scroll);
    lcd.print(scroll);
  }

  // change screens if the middle button is pressed
  if (switch2State == HIGH) {
    delay(250);
    screen++;

    // reset to the splash screen if the user is on the last screen
    if (screen > 21) {
      lcd.clear();
      screen = 0;
      setup();
    }
    
    switch (screen) {
      case 1: {
        question1(); 
        break; 
      }
      case 2: {
        question2(); 
        break; 
      }
      case 3: {
        question3();
        break;
      }
      case 4: {
        question4();
        break;
      }
      case 5: {
        question5();
        break;
      }
      case 6: {
        question6();
        break;
      }
      case 7: {
        question7();
        break;
      }
      case 8: {
        question8();
        break;
      }
      case 9: {
        question9();
        break;
      }
      case 10: {
        question10();
        break;
      }
      case 11: {
        question11();
        break;
      }
      case 12: {
        question12();
        break;
      }
      case 13: {
        question13();
        break;
      }
      case 14: {
        question14();
        break;
      }
      case 15: {
        question15();
        break;
      }
      case 16: {
        question16();
        break;
      }
      case 17: {
        question17();
        break;
      }
      case 18: {
        question18();
        break;
      }
      case 19: {
        question19();
        break;
      }
      case 20: {
        question20();
        break;
      }
      case 21: {
        endScreen();
        break;
      }
    }
  }
  
  // set the previous state of the button to the current
  prevSwitch3State = switch3State;
  prevSwitch2State = switch2State;
  prevSwitch1State = switch1State;
  
}

/*-----------Methods-----------*/

// method that allows text to scroll on the LCD
String scrollText(String text) {
  delay(350);
  return text.substring(1, text.length()) + text.substring(0, 1);
}

// method that sets the color of the LCD
void setColor(int red, int green, int blue) {
  // if the LED pin is an anode and not a cathode
  #ifdef COMMON_ANODE
    /*
     * Since the LED used in this project is an anode LED, it means
     * that the RGB values are inverted (i.e. (0, 0, 0) is white if
     * we do not define this.) By subtracting 255 - color, the RGB values
     * with the LED will be correct, as in it makes the anode LED act as 
     * a cathode LED and color values are not inverted.
     * 
     */
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

// method to display question 1
void question1() {
  questionNumber = 1;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " Marist is in the city of Poughkeepsie.";
}

// method to display question 2
void question2() {
  questionNumber = 2;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " Marist College was established in 1929.";
}

// method to display question 3
void question3() {
  questionNumber = 3;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " Marist has more adjunct faculty.";
}

// method to display question 4
void question4() {
  questionNumber = 4;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " All sports teams play in the MAAC.";
}

// method to display question 5
void question5() {
  questionNumber = 5;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " Marist Aboard has 30 study sites.";
}

// method to display question 6
void question6() {
  questionNumber = 6;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " Marist has 17 residential areas.";
}

// method to display question 7
void question7() {
  questionNumber = 7;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "Hudson      East";
  lcd.print(noScroll);
  scroll = " Marist College is on which river?";
}

// method to display question 8
void question8() {
  questionNumber = 8;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " There are more females than males.";
}

// method to display question 9
void question9() {
  questionNumber = 9;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " Marist only has had 3 presidents.";
}

// method to display question 10
void question10() {
  questionNumber = 10;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " Marian was a college and a gym.";
}

// method to display question 11
void question11() {
  questionNumber = 11;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " Marist Brothers occupies 100 countries.";
}

// method to display question 12
void question12() {
  questionNumber = 12;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " St. Ann's is not the oldest building.";
}

// method to display question 13
void question13() {
  questionNumber = 13;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " Professor Gormanly is the GOAT!";
}

// method to display question 14
void question14() {
  questionNumber = 14;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "Gopher       Fox";
  lcd.print(noScroll);
  scroll = " Marist's mascot is the red...";
}

// method to display question 15
void question15() {
  questionNumber = 15;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " Marist owns the Payne Estate.";
}

// method to display question 16
void question16() {
  questionNumber = 16;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " The college is Roman Catholic.";
}

// method to display question 17
void question17() {
  questionNumber = 17;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "Yes           No";
  lcd.print(noScroll);
  scroll = " To pray and to work. Motto?";
}

// method to display question 18
void question18() {
  questionNumber = 18;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " The president works in Greystone.";
}

// method to display question 19
void question19() {
  questionNumber = 19;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " Lowell Thomas is an alum.";
}

// method to display question 20
void question20() {
  questionNumber = 20;
  setColor(0, 0, 0);
  lcd.setCursor(0, 1);
  noScroll = "True       False";
  lcd.print(noScroll);
  scroll = " Marist was fully co-ed by 1968.";
}

// method to display a correct message
void correctScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  // LED becomes green
  setColor(0, 255, 0);
  lcd.print("    Correct!   ");
  // increment score
  score = score + 10;
  lcd.setCursor(0, 1);
  lcd.print("   Score: ");
  lcd.setCursor(10, 1);
  lcd.print(score);
  lastDebounceTime = millis();
  // delay 2 seconds before display new scroll text
  delay(2000);
}

// method to display an incorrect message
void incorrectScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  // LED becomes red
  setColor(255, 0, 0);
  lcd.print("   Incorrect!   ");
  // score remains the same
  score = score;
  lcd.setCursor(0, 1);
  lcd.print("   Score: ");
  lcd.setCursor(10, 1);
  lcd.print(score);
  lastDebounceTime = millis();
  // delay 2 seconds before display new scroll text
  delay(2000);
}

// method is called when the user reaches the end of the quiz
void endScreen() {
  lcd.clear();
  lcd.setCursor(0, 0);
  // LED turns off
  setColor(0, 0, 0);
  lcd.print("Score: ");
  // call the method to display score
  printScore();
  lcd.setCursor(0, 1);
  // set current score to high score if it is higher than the high score
  if (score > highScore) {
    highScore = score;
    lcd.print("High Score: ");
  }
  // print the high score 
  else {
    lcd.print("High Score: ");
  }
  printHighScore();
  lastDebounceTime = millis();
  // delay 2 seconds and call this method
  delay(2000);
  determineStatus();
}

/* 
 * This method prints the score. It formats it in a neat and tidy 
 * way, so that it appears nicely on the screen. Depending on your score,
 * it will print it on the rightmost columns. 
 * Ex. a score of 0 reads 00
 *     a score of 10 reads 10
 *     a score of 100 reads 100
 * There are no leading zeroes.
 * 
 */
void printScore() {
  if (score < 10) {
    lcd.setCursor(15, 0);
    lcd.print(score);
  }
  if (score < 100) {
    lcd.setCursor(14, 0);
    lcd.print(score);
  }
  if (score >= 100) {
    lcd.setCursor(13, 0);
    lcd.print(score);
  }
}

/* 
 * This method prints the high score. Similar to the printScore()
 * method, it will print out the high score and format it nicely on 
 * the LCD screen.
 * 
 */

void printHighScore() {
  if (score < 10) {
    lcd.setCursor(15, 1);
    lcd.print(highScore);
  }
  if (score < 100) {
    lcd.setCursor(14, 1);
    lcd.print(highScore);
  }
  if (score >= 100) {
    lcd.setCursor(13, 1);
    lcd.print(highScore);
  }
}

/*
 * This is the logic behind the program determining what message should display
 * when the game ends to reflect your score. In addition to the message, the LED
 * will also glow the color that corresponds to that message. Remember that score
 * increments by 10, so only scores that divide into 10 with remainder of 0 are possible.
 * 
 */
void determineStatus() {
  // score is 0
  if (score <= 0) {
    // set status
    scroll = " You forgot how to Internet.";
    // LED is blue
    setColor(0, 0, 255);
  }
  // score is between 10 and 40
  if (score > 0 && score <= 40) {
    // set status
    scroll = " Clearly not a Red Fox.";
    // LED is green
    setColor(0, 255, 0);
  }
  // score is between 50 and 80
  if (score > 40 && score <= 80) {
    // set status
    scroll = " An old alum? A sibling?";
    // LED is yellow
    setColor(80, 80, 0);
  }
  // score is between 90 and 110
  if (score > 80 && score <= 110) {
    // set status
    scroll = " You could be a fox, not red though.";
    // LED is purple
    setColor(80, 0, 80);
  }
  // score is between 120 and 150
  if (score > 110 && score <= 150) {
    // set status
    scroll = " I'd say you attend Marist College.";
    // LED is orange
    setColor(175, 80, 0);
  }
  // score is between 160 and 170
  if (score > 150 && score <= 170) {
    // set status
    scroll = " You bleed red and white stranger!";
    // LED is pink
    setColor(175, 0, 80);
  }
  // score is between 180 and 190
  if (score > 170 && score < 200) {
    // set status
    scroll = " You are a proud Red Fox! :)";
    // LED is red
    setColor(255, 0, 0);
  }
  // perfect score of 200
  if (score == 200) {
    // set status
    scroll = " Ultimate Red Fox...    or Googler?";
    // LED is white
    setColor(255, 255, 255);
  }
}

