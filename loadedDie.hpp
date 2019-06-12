#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "die.hpp"

//LoadedDie class has public inheritance of the Die class.
class LoadedDie : public Die
{
    public:
        //Die roll() method to be overloaded.
        int roll(int bias);

};

#endif