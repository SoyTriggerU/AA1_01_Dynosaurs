#include "Dynosaur.h"  
#include <iostream>
#include <time.h>

#define MAX_DYNOSAURS 15    // Max number of dynos

int main()
{
    srand(time(NULL));  //Inicializes random num generator

    Dynosaur* jurassicPark[MAX_DYNOSAURS] = { nullptr };    //Dyno array

    // Create dyno odd positions making sure they don't repeat every 2 positions
    for (int i = 0; i < MAX_DYNOSAURS; i += 2)
    {
        Dynosaur* newDyno = nullptr;

        // Generate different dynos randomly (Every 2 postions)
        do
        {
            if (newDyno != nullptr)
            {
                delete newDyno;    // Avoid memory leaks
            }
            newDyno = createRandomDynosaur(); // Create random dyno
        } while (i >= 2 && compareDynosaurStrength(newDyno, jurassicPark[i - 2]));

        jurassicPark[i] = newDyno;  // Assign dyno to array
    }

    // Show created dyno and empty positions
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

    // Empty reserved memory
    for (int i = 0; i < MAX_DYNOSAURS; ++i)
    {
        delete jurassicPark[i];
    }

    return 0;   // End of program
}