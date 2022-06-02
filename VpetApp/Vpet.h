#ifndef VPET_H
#define VPET_H


#include <iostream>

class VPet
{
    public:

        friend std::ostream& operator<<(std::ostream& os, const VPet& vp);

        // Constructors (Member function)
        VPet(double, bool);
        VPet();

        // Member functions
        void feedPet(int amount);
        bool getHungry() const;
        double getWeight() const;

    private:

        // Data Members
        double weight;
        bool hungry;
};



#endif // VPET_H
