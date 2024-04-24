#include "Plant.h"

class Dandelion : public Plant{
    Organism* getChild(int x, int y) override;
public:
    Dandelion(int x, int y, World*);
    void action() override;
};