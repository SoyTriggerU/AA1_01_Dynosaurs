#include <iostream>
#include <time.h>

#define NUM_DYNOSAURS 2

enum DynosaurType { TYRANNOSAURUS, VELOCIRAPTOR, BRACHIOSAURUS, DIPLODOCUS };

struct Dynosaur
{
    DynosaurType dynosaur;
    std::string dynosaurName;
    int health = 100;
    int attackPower;
    int strength;
};

Dynosaur createRandomDynosaur()
{
    Dynosaur dyno;
    int dynoType = rand() % 4;

    dyno.dynosaur = static_cast<DynosaurType>(dynoType);

    switch (dyno.dynosaur)
    {
    case TYRANNOSAURUS:
        dyno.dynosaurName = "TYRANNOSAURUS";
        dyno.attackPower = 100;
        DynosaurType::TYRANNOSAURUS;
        break;
    case VELOCIRAPTOR:
        dyno.dynosaurName = "VELOCIRAPTOR";
        dyno.attackPower = 80;
        DynosaurType::VELOCIRAPTOR;
        break;
    case BRACHIOSAURUS:
        dyno.dynosaurName = "BRACHIOSAURUS";
        dyno.attackPower = 65;
        DynosaurType::BRACHIOSAURUS;
        break;
    case DIPLODOCUS:
        dyno.dynosaurName = "DIPLODOCUS";
        dyno.attackPower = 45;
        DynosaurType::DIPLODOCUS;
        break;
    default:
        dyno.dynosaurName = "INVALID";
        dyno.attackPower = 0;
        break;
    }

    return dyno;
}

std::string getDynosaurTypeToString(DynosaurType dynosaur)
{
    switch (dynosaur)
    {
    case TYRANNOSAURUS:
        return "TYRANNOSAURUS";
    case VELOCIRAPTOR:
        return "VELOCIRAPTOR";
    case BRACHIOSAURUS:
        return "BRACHIOSAURUS";
    case DIPLODOCUS:
        return "DIPLODOCUS";
    default:
        return "INVALID";
    }
}

bool compareDynosaurStrength(const Dynosaur& d1, const Dynosaur& d2)
{
    int strength1 = d1.health + d1.attackPower;
    int strength2 = d2.health + d2.attackPower;

    return strength1 == strength2;
}

int main()
{
    srand(time(NULL));
    Dynosaur dynosaurs[NUM_DYNOSAURS];

    for (int i = 0; i < NUM_DYNOSAURS; ++i)
    {
        dynosaurs[i] = createRandomDynosaur();
        std::cout << "Dynosaur " << i + 1 << " is a " << dynosaurs[i].dynosaurName
            << " with Attack Power: " << dynosaurs[i].attackPower << std::endl;
    }
    
    for (int i = 0; i < NUM_DYNOSAURS; ++i)
    {
        for (int j = i + 1; j < NUM_DYNOSAURS; ++j)
        {
            if (compareDynosaurStrength(dynosaurs[i], dynosaurs[j]))
            {
                std::cout << "Dynosaur " << i + 1 << " and Dynosaur " << j + 1 << " have the same strength!" << std::endl;
            }
            else
            {
                std::cout << "Dynosaur " << i + 1 << " and Dynosaur " << j + 1 << " have different strengths!" << std::endl;
            }
        }
    }
   
    return 0;
}