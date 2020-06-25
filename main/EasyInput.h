#ifndef _EasyInput_H_
#define _EasyInput_H_

#include "LUFAConfig.h"
#include <LUFA.h>
#include "Joystick.h"
#include "Descriptors.h"
#include "General.h"

class EasyInput
{
  public:
  EasyInput::EasyInput() { }

  void Sleep(int milliseconds);

  void PressButton(int button, int pressDuration, int waitDuration);
  void LeftJoy(int valX, int valY, int holdDuration, int waitDuration);
  void RightJoy(int valX, int valY, int holdDuration, int waitDuration);

  //General Gen;

  private:
};
#endif
