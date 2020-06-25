#include "General.h"
#include "Descriptors.h"
#include "Joystick.h"

unsigned long previousMillis = 0; 
unsigned long currentMillis = millis();

void General::handleUSB() {
  HID_Task();
  USB_USBTask();
}

void General::Init()
{
  previousMillis = millis();
  while(LeftJoystick(STICK_CENTER, STICK_CENTER, 250, 250) == true);
  while(PressTwoButtons(LB_BUTTON, RB_BUTTON, 250, 500) == true);
  while(LeftJoystick(STICK_CENTER, STICK_CENTER, 250, 250) == true);
  while(PressTwoButtons(LB_BUTTON, RB_BUTTON, 250, 500) == true);
  while(Nothing(1000) == true);
}

bool General::PressOneButton(int button, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {
    ReportData.Button |= button;  
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER; 
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

void General::PressButton(int button)
{
  PressButton(button, 100);
}

void General::PressButton(int button, unsigned long pressDuration)
{
  while(PressOneButton(button, pressDuration, 1) == true);
}

bool General::PressTwoButtons(int buttonOne, int buttonTwo, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {
    ReportData.Button |= buttonOne;
    ReportData.Button |= buttonTwo;  
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::LeftJoystick(int joystickXVal, int joystickYVal, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {  
    ReportData.LX = joystickXVal;
    ReportData.LY = joystickYVal; 
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::LeftJoystick(int joyXVal, int joyYVal, unsigned long holdDuration)
{
  while(LeftJoystick(joyXVal, joyYVal, holdDuration, 1) == true);
  return true;
}

bool General::LeftJoystickOneButton(int joystickXVal, int joystickYVal, int button, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {  
    ReportData.Button |= button;
    ReportData.LX = joystickXVal;
    ReportData.LY = joystickYVal;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::LeftJoystickTwoButtons(int joystickXVal, int joystickYVal, int buttonOne, int buttonTwo, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {  
    ReportData.Button |= buttonOne;
    ReportData.Button |= buttonTwo;
    ReportData.LX = joystickXVal;
    ReportData.LY = joystickYVal; 
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::RightJoystick(int joystickXVal, int joystickYVal, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {  
    ReportData.RX = joystickXVal;
    ReportData.RY = joystickYVal; 
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::RightJoystick(int joyXVal, int joyYVal, unsigned long holdDuration)
{
  while(RightJoystick(joyXVal, joyYVal, holdDuration, 1) == true);
  return true;
}

bool General::RightJoystickOneButton(int joystickXVal, int joystickYVal, int button, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {  
    ReportData.Button |= button;
    ReportData.RX = joystickXVal;
    ReportData.RY = joystickYVal;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER; 
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::RightJoystickTwoButtons(int joystickXVal, int joystickYVal, int buttonOne, int buttonTwo, unsigned long pressDuration, unsigned long waitDuration) {
  currentMillis = millis();
  if ((currentMillis - previousMillis) < pressDuration) {  
    ReportData.Button |= buttonOne;
    ReportData.Button |= buttonTwo;
    ReportData.RX = joystickXVal;
    ReportData.RY = joystickYVal;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
  }
  else if ((currentMillis - previousMillis) < (pressDuration + waitDuration)) {
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
  }
  else {
    previousMillis = millis();
    ReportData.RX = STICK_CENTER;
    ReportData.RY = STICK_CENTER;
    ReportData.LX = STICK_CENTER;
    ReportData.LY = STICK_CENTER;
    return false;
  }
  handleUSB();
  return true;
}

bool General::Nothing(unsigned long waitDuration) {
    currentMillis = millis();
    if (currentMillis - previousMillis < waitDuration) {
      currentMillis = millis();
      ReportData.LX = STICK_CENTER;
      ReportData.LY = STICK_CENTER; 
      ReportData.RX = STICK_CENTER;
      ReportData.RY = STICK_CENTER; 
    }
    else {
      previousMillis = millis();
      return false;
    }
    handleUSB();
    return true;
}

void General::Sleep(unsigned long waitDuration) {
//  unsigned long start = millis();
//  unsigned long cur = start;
//    
//  while(cur - start < waitDuration)
//  {
//    cur = millis();
//    ReportData.LX = STICK_CENTER;
//    ReportData.LY = STICK_CENTER; 
//    ReportData.RX = STICK_CENTER;
//    ReportData.RY = STICK_CENTER; 
//    handleUSB();
//  }
  while(Nothing(waitDuration) == true);

  // currentMillis = millis();

  // while (currentMillis - previousMillis < waitDuration)
}
