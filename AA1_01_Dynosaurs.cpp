#include <iostream>
#include <time.h>

#define MAX_DYNOSAURS 15

enum DynosaurType { TYRANNOSAURUS, VELOCIRAPTOR, BRACHIOSAURUS, DIPLODOCUS };

struct Dynosaur
{
    DynosaurType dynosaur;
    std::string dynosaurName;
    int health = 100;
    int attackPower;
    int strength;
};

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

Dynosaur* createRandomDynosaur()
{
    Dynosaur* dyno = new Dynosaur;
    int dynoType = rand() % 4;

    dyno->dynosaur = static_cast<DynosaurType>(dynoType);
    dyno->dynosaurName = getDynosaurTypeToString(dyno->dynosaur);

    switch (dyno->dynosaur)
    {
    case TYRANNOSAURUS:
        dyno->attackPower = 100;
        DynosaurType::TYRANNOSAURUS;
        break;
    case VELOCIRAPTOR:
        dyno->attackPower = 80;
        DynosaurType::VELOCIRAPTOR;
        break;
    case BRACHIOSAURUS:
        dyno->attackPower = 65;
        DynosaurType::BRACHIOSAURUS;
        break;
    case DIPLODOCUS:
        dyno->attackPower = 45;
        DynosaurType::DIPLODOCUS;
        break;
    default:
        dyno->attackPower = 0;
        break;
    }

    dyno->strength = dyno->health + dyno->attackPower;

    return dyno;
}

bool compareDynosaurStrength(const Dynosaur* d1, const Dynosaur* d2)
{
    return d1->strength == d2->strength;
}

int main()
{
    srand(time(NULL));
    
    Dynosaur* jurassicPark[MAX_DYNOSAURS];

    for (int i = 0; i < MAX_DYNOSAURS; ++i)
    {
        Dynosaur* newDyno = nullptr;

        do
        {
            if (newDyno != nullptr)
            {
                delete newDyno;
            }
            newDyno = createRandomDynosaur();
        } while (i >= 2 && compareDynosaurStrength(newDyno, jurassicPark[i - 2]));

        jurassicPark[i] = newDyno;
    }
    
    for (int i = 0; i < MAX_DYNOSAURS; ++i)
    {
        if (jurassicPark[i] != nullptr)
        {
            std::cout << "Position " << i << ": " << jurassicPark[i]->dynosaurName
                << " (Strength: " << jurassicPark[i]->strength << ")" << std::endl;
        }
        else
        {
            std::cout << "Position " << i << ": There's no dynosaur" << std::endl;
        }
    }

    for (int i = 0; i < MAX_DYNOSAURS; ++i)
    {
        delete jurassicPark[i];
    }

    return 0;
}