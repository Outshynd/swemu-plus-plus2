#include "EggHatch.h"
#include "Descriptors.h"
#include "Joystick.h"

General gen;
EasyInput _input;

bool _hatchInit = false;

/////////////////////////////////////////////////////////
///// Hatch an egg that takes ~5120 steps (scorbunny)
/////////////////////////////////////////////////////////
void Hatch5120()
{
  //only initialize once
  if (_hatchInit == false)
  {
    //initialize input
    gen.Init();

    _hatchInit = true;
  }

  //fly to nursery & walk to known location
  FlyToNursery();

  //grab egg from nursery, put in slot 1
  GetEggSlot(1);

  //loop until egg is (hopefully) ready
  EggLoops(20);

  //grab egg from nursery, put in slot 2
  GetEggSlot(2);

  //loop until egg is (hopefully) ready
  EggLoops(20);

  //grab egg from nursery, put in slot 3
  GetEggSlot(3);

  //loop until egg is (hopefully) ready
  EggLoops(20);

  //grab egg from nursery, put in slot 4
  GetEggSlot(4);

  //loop to hatch eggs
  EggLoops(200);

  gen.Sleep(2000);
  //finish off any open hatch dialogs
  // for (int i = 0; i < 6; i++)
  // {
  //   gen.PressButton(gen.B_BUTTON);
  //   gen.Sleep(1500);
  // }
}



/////////////////////////////////////////////////////////
///// Hatch an egg that takes ~10240 steps (dragapult, tyranitar)
/////////////////////////////////////////////////////////
void Hatch10240()
{
  //only initialize once
  if (_hatchInit == false)
  {
    //initialize input
    gen.Init();

    _hatchInit = true;

    
  }

  //fly to nursery & walk to known location
  FlyToNursery();

  //grab egg from nursery, put in slot 1
  GetEggSlot(1);

  //loop until egg is (hopefully) ready
  EggLoops(30);

  //grab egg from nursery, put in slot 2
  GetEggSlot(2);

  //loop until egg is (hopefully) ready
  EggLoops(30);

  //grab egg from nursery, put in slot 3
  GetEggSlot(3);

  //loop until egg is (hopefully) ready
  EggLoops(30);

  //grab egg from nursery, put in slot 4
  GetEggSlot(4);

  //loop until egg is (hopefully) ready
  EggLoops(30);

  //grab egg from nursery, put in slot 5
  GetEggSlot(5);

  //loop to hatch eggs
  EggLoops(310);

  //gen.Sleep(1000);
  
  //walk to start position
  //gen.LeftJoystick(gen.LEFT, gen.HALF_UP, 1000);
}


#pragma region Helper_Functions
/////////////////////////////////////////////////////////
///// helper functions
/////////////////////////////////////////////////////////
void EggLoops(int loops)
{
  //walk away
  gen.LeftJoystick(gen.LEFT, gen.DOWN, 1200);
  gen.Sleep(250);
  //get on bike
  gen.PressButton(gen.PLUS_BUTTON);
  gen.Sleep(500);

  //start looping for an egg to be ready
  BikeLoop(loops);

  //get off bike
  gen.PressButton(gen.PLUS_BUTTON);
  gen.Sleep(1000);
}

void GetEggSlot(int slot)
{
  //infinite loop if we enter the wrong thing
  if (slot > 5 || slot < 1)
    while (true)
      gen.Sleep(100);

  GatherEggFromNursery();

  //select party slot
  for (int i = 1; i < slot; i++)
  {
    gen.LeftJoystick(gen.STICK_CENTER, gen.DOWN, 100);
    gen.Sleep(200);
  }

  //finish dialog
  gen.PressButton(gen.A_BUTTON);
  gen.Sleep(2500);
  gen.PressButton(gen.B_BUTTON);
  gen.Sleep(2000);
  gen.PressButton(gen.B_BUTTON);
  gen.Sleep(1500);
}

void GatherEggFromNursery()
{
  WalkToNurseryAttendant();

  //start conversation
  gen.PressButton(gen.A_BUTTON);
  gen.Sleep(1000);
  gen.PressButton(gen.A_BUTTON);
  gen.Sleep(500);

  //attempt to exit if no egg
  gen.PressButton(gen.B_BUTTON, 150);
  gen.Sleep(150);
  gen.PressButton(gen.B_BUTTON, 150);
  gen.Sleep(150);
  gen.PressButton(gen.B_BUTTON, 150);
  gen.Sleep(150);
  gen.LeftJoystick(gen.LEFT, gen.DOWN, 300);

  //agree to put in party
  gen.PressButton(gen.A_BUTTON, 150);
  gen.Sleep(1500);
  gen.PressButton(gen.A_BUTTON);
  gen.Sleep(1000);
  gen.PressButton(gen.A_BUTTON);
  gen.Sleep(1000);
  gen.PressButton(gen.A_BUTTON);
  gen.Sleep(1000);
  gen.PressButton(gen.A_BUTTON);
  gen.Sleep(2000);

  return;
}

//initial implementation
/*
void WalkToNurseryAttendant()
{
  //walks up towards the fence for a bit
  gen.LeftJoystick(gen.STICK_CENTER, gen.UP, 1200);
  gen.Sleep(100);
  //walks up-right towards attendant
  gen.LeftJoystick(gen.RIGHT, gen.HALF_UP, 2500);
  gen.Sleep(100);

  return;
}
*/

void WalkToNurseryAttendant()
{
  //walks up towards the fence for a bit
  gen.LeftJoystick(gen.STICK_CENTER, gen.UP, 1200);
  gen.Sleep(100);
  //walks up-right towards attendant
  gen.LeftJoystick(gen.RIGHT, gen.HALF_UP, 3000);
  gen.Sleep(100);

  return;
}

void FlyToNursery()
{
  //open menu
  gen.PressButton(gen.X_BUTTON);
  gen.Sleep(1500);
  //select map
  gen.LeftJoystick(gen.STICK_CENTER, gen.DOWN, 600);
  gen.LeftJoystick(gen.LEFT, gen.STICK_CENTER, 1400);
  //open map
  gen.PressButton(gen.A_BUTTON);
  gen.Sleep(3000);
  //move cursor to nursery -- this only works if player has discovered tent at route 5
  gen.LeftJoystick(gen.RIGHT, gen.UP, 50);
  gen.Sleep(250);
  //select fly point
  gen.PressButton(gen.A_BUTTON);
  gen.Sleep(1000);
  //confirm fly to nursery
  gen.PressButton(gen.A_BUTTON);
  gen.Sleep(4000);

  //walk to start position
  gen.LeftJoystick(gen.LEFT, gen.STICK_CENTER, 1000);

  return;
}

void BikeLoop(int loops)
{
  for (int i = 0; i < loops; i++)
  {
    gen.LeftJoystick(gen.LEFT, gen.UP, 100);
    gen.LeftJoystick(gen.STICK_CENTER, gen.UP, 100);
    gen.LeftJoystick(gen.RIGHT, gen.UP, 100);
    gen.LeftJoystick(gen.RIGHT, gen.STICK_CENTER, 100);
    gen.LeftJoystick(gen.RIGHT, gen.DOWN, 100);
    gen.LeftJoystick(gen.STICK_CENTER, gen.DOWN, 100);
    gen.LeftJoystick(gen.LEFT, gen.DOWN, 100);
    gen.LeftJoystick(gen.LEFT, gen.STICK_CENTER, 100);

    //every 2nd loop, press a button
    if (i % 2 == 0)
      gen.PressButton(gen.A_BUTTON, 25);
  }

  gen.Sleep(500);
}
#pragma endregion Helper_Functions