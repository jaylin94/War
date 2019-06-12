#ifndef DIE_HPP
#define DIE_HPP

class Die
{
private:
    int N;
    int rollValue;

public:
    Die()
    {
        N = 100;
        rollValue = (rand() % getN()) + 1;
    }

    // Generates a random roll value for the normal die.
    // No parameters, tells user that the next roll will be generated
    // by a normal die.
    int roll();

    //Get functions for N (sides) and roll value
    int getN()
    {
        return N;
    }
    int getRollValue()
    {
        return rollValue;
    }

    //Set functions fo N (sides) and roll value
    void setN(int N)
    {
        this->N = N;
    }
    void setRollValue(int rollValue)
    {
        this->rollValue = rollValue;
    }
};

#endif