#include "Dynosaur.h"  
#include <iostream>

// Implementation of getDynosaurTypeToString
std::string getDynosaurTypeToString(DynosaurType dynosaur)
{
    switch (dynosaur)
    {
    case DynosaurType::TYRANNOSAURUS:
        return "TYRANNOSAURUS";
    case DynosaurType::VELOCIRAPTOR:
        return "VELOCIRAPTOR";
    case DynosaurType::BRACHIOSAURUS:
        return "BRACHIOSAURUS";
    case DynosaurType::DIPLODOCUS:
        return "DIPLODOCUS";
    default:
        return "INVALID";
    }
}

// Implementation of createRandomDynosaur
Dynosaur* createRandomDynosaur()
{
    Dynosaur* dyno = new Dynosaur;  // Reserves memory for the new dyno
    int dynoType = rand() % 4;  // Random type (0-3)

    dyno->dynosaur = static_cast<DynosaurType>(dynoType);   // Random type assignation
    dyno->dynosaurName = getDynosaurTypeToString(dyno->dynosaur);   //Assigns a name based on the type

    // Assign attack power based on the type
    switch (dyno->dynosaur)
    {
    case DynosaurType::TYRANNOSAURUS:
        dyno->attackPower = 100;
        break;
    case DynosaurType::VELOCIRAPTOR:
        dyno->attackPower = 80;
        break;
    case DynosaurType::BRACHIOSAURUS:
        dyno->attackPower = 65;
        break;
    case DynosaurType::DIPLODOCUS:
        dyno->attackPower = 45;
        break;
    default:
        dyno->attackPower = 0;
        break;
    }

    dyno->strength = dyno->health + dyno->attackPower;  // Calculates total strength

    return dyno;    //Returns created dyno
}

// Implementation of compareDynosaurStrength
bool compareDynosaurStrength(const Dynosaur* d1, const Dynosaur* d2)
{
    return d1->strength == d2->strength;
}