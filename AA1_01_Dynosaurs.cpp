#include <iostream>
#include <time.h>

#define MAX_DYNOSAURS 15

enum class DynosaurType { TYRANNOSAURUS, VELOCIRAPTOR, BRACHIOSAURUS, DIPLODOCUS };

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

Dynosaur* createRandomDynosaur()
{
    Dynosaur* dyno = new Dynosaur;
    int dynoType = rand() % 4;

    dyno->dynosaur = static_cast<DynosaurType>(dynoType);
    dyno->dynosaurName = getDynosaurTypeToString(dyno->dynosaur);

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
    
    Dynosaur* jurassicPark[MAX_DYNOSAURS] = { nullptr };

    for (int i = 0; i < MAX_DYNOSAURS; i+=2)
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
            std::cout << "Position " << i << ": There's no dynosaur here" << std::endl;
        }
    }

    for (int i = 0; i < MAX_DYNOSAURS; ++i)
    {
        delete jurassicPark[i];
    }

    return 0;
}