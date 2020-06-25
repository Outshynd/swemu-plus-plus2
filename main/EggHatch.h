#ifndef _EggHatch_H_
#define _EggHatch_H_

#include "LUFAConfig.h"
#include <LUFA.h>
#include "Joystick.h"
#include "Descriptors.h"
#include "General.h"
#include "EasyInput.h"

void Hatch5120();
void Hatch10240();
void EggLoops(int  loops);
void GetEggSlot(int num);
void GatherEggFromNursery();
void WalkToNurseryAttendant();

void FlyToNursery();
void BikeLoop(int loops);

#endif


#define SLEEP(x) while(gen.Nothing(x) == true)
#define PRESS_BUTTON(button, duration) while(gen.PressOneButton(button, duration, 1) == true)