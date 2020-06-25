#include "LUFAConfig.h"
#include <LUFA.h>
#include "Joystick.h"
#include "General.h"
#include "PokemonEggHatching.h"
#include "PokemonExtra.h"
#include "SimpleScripting.h"
#include "EggHatch.h"

String incoming = "";

PokemonEggHatching pokemonEggHatching; // Creates an instance of pokemon egg hatching class
PokemonExtra pokemonExtra; // Creates an instance of pokemon extra class

void setup() {
  SetupHardware(); // Needed for LUFA
  GlobalInterruptEnable(); // Needed for LUFA
  Serial1.begin(9600);
  pinMode(2, OUTPUT);
}

void loop() {
  //pokemonEggHatching.eggHatch(2560);
  //pokemonEggHatching.eggHatch(3840);
  //pokemonEggHatching.eggHatch(5120);
  //pokemonEggHatching.eggHatch(6400);
  //pokemonEggHatching.eggHatch(7680);
  //pokemonEggHatching.eggHatch(8960);
  //pokemonEggHatching.eggHatch(10240);
  //pokemonEggHatching.boxHatch(1);
  //uartScriptSelect();
    
  //pokemonExtra.boxRelease(5);
  //pokemonExtra.diggerBrothers();
  //pokemonExtra.wattFarming();
  //pokemonExtra.fossilPokemon("arctovish", 20);
  //pokemonExtra.stowOnSideBargain();
  //pokemonExtra.lottoFarm();
  //pokemonExtra.evTrain("hp", "spatk");
  //pokemonExtra.pokeJobs();
  //pokemonExtra.championsCup();

  //simpleScript();

  //Hatch5120();
  Hatch10240();
}

// For writing simple scripts, use this function and call to it in the main. 
void simpleScript() {
  using namespace simple;

  for (;;)
  {
    Up(1000);
    Nothing(2000);
  }
  
//  Left(1000);
//  Nothing(1000);
//  Right(1000);
//  Nothing(1000);
//  Up(1000);
//  Nothing(1000);
//  X(1000);
//  Nothing(1000);
//  Y(1000);
//  Nothing(1000);
//  A(1000);
//  Nothing(1000);
//  B(1000);
//  Nothing(1000);
}

// Allows the use of a console program to select a script instead of reflashing
void uartScriptSelect() {
  while(Serial1.available()) {
    incoming = Serial1.readString();
    if (incoming == "a") {
      while(1) {
        pokemonEggHatching.eggHatch(2560);
      }
    }
    else if (incoming == "b"){
      while(1) {
        pokemonEggHatching.eggHatch(3840);
      }
    }
    else if (incoming == "c"){
      while(1) {
        pokemonEggHatching.eggHatch(5120);
      }
    }
    else if (incoming == "d"){
      while(1) {
        pokemonEggHatching.eggHatch(6400);
      }
    }
    else if (incoming == "e"){
      while(1) {
        pokemonEggHatching.eggHatch(7680);
      }
    }
    else if (incoming == "f"){
      while(1) {
        pokemonEggHatching.eggHatch(8960);
      }
    }
    else if (incoming == "g"){
      while(1) {
        pokemonEggHatching.eggHatch(10240);
      }
    }
    else if (incoming == "i") {
      while(1) {
        pokemonEggHatching.boxHatch(1);
      }
    }
    else if (incoming == "j"){
      while(1) {
        pokemonExtra.boxRelease(5);
      }
    }
    else if (incoming == "k"){
      while(1) {
        pokemonExtra.diggerBrothers();
      }
    }
    else if (incoming == "l"){
      while(1) {
        pokemonExtra.wattFarming();
      }
    }
    else if (incoming == "n"){
      while(1) {
        pokemonExtra.berryFarm();
      }
    }
    else if (incoming == "o"){
      while(1) {
        pokemonExtra.stowOnSideBargain();
      }
    }
    else if (incoming == "p"){
      while(1) {
        pokemonExtra.lottoFarm();
      }
    }
    else if (incoming == "r"){
      while(1) {
        pokemonExtra.pokeJobs();
      }
    }
    else if (incoming == "s"){
      while(1) {
        pokemonExtra.championsCup();
      }
    }
  }
}
