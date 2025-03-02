#include <iostream>

// Definitions of enum class DynosaurType
enum class DynosaurType {
    TYRANNOSAURUS,
    VELOCIRAPTOR,
    BRACHIOSAURUS,
    DIPLODOCUS
};

// Dynosaur structure
struct Dynosaur
{
    DynosaurType dynosaur;          // Type of dynosaur
    std::string dynosaurName;       // Name of the dynosaur
    int health = 100;               // Health (100 by default)
    int attackPower;                // Power of attack
    int strength;                   // Strength = health + attackPower
};

// Function declarations
//Converts type of dynosaur into a readable string
std::string getDynosaurTypeToString(DynosaurType dynosaur);
//Creates a random dynosaur with defined attributes 
Dynosaur* createRandomDynosaur();
//Compares two dynosaur strength's (True if they're equal)
bool compareDynosaurStrength(const Dynosaur* d1, const Dynosaur* d2);

