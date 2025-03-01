#include <iostream>

#define NUM_DYNOSAURS 2

enum DynosaurType { TYRANNOSAURUS, VELOCIRAPTOR, BRACHIOSAURUS, DIPLODOCUS };

struct Dynosaur
{
    DynosaurType dynosaur;
    std::string dynosaurName;
    int health = 100;
    int attackPower;
};

int getDynosaurTypeToString(DynosaurType dynosaur, std::string dynosaurName)
{
     
}

    switch (*dynosaur)
    {
        case DynosaurType::TYRANNOSAURUS:
            return dynosaurName = "TYRANNOSAURUS";

        case DynosaurType::VELOCIRAPTOR:
            return dynosaurName = "VELOCIRAPTOR";

        case DynosaurType::BRACHIOSAURUS:
            return dynosaurName = "BRACHIOSAURUS";

        case DynosaurType::DIPLODOCUS:
            return dynosaurName = "DIPLODOCUS";
        default:
            return dynosaurName = "INVALID";
    }
}

//int compareDynosaurStrength(Dynosaur strength)
//{
//
//}
//
int createRandomDynosaur()
{

}

int main()
{
    Dynosaur dynosaurs[NUM_DYNOSAURS];
    for (int i = 0; i < NUM_DYNOSAURS; ++i)
    {
        getDynosaurTypeToString(&dynosaurs[i].dynosaur, dynosaurs[i].dynosaurName);
        std::cout << "Dynosaur " << i + 1 << " is a " << dynosaurs[i].dynosaurName << std::endl;
    }

}