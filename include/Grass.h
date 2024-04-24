#include "Plant.h"

class Grass : public Plant{
    Organism* getChild(int x, int y) override;
public:
    Grass(int x, int y, World* world);
};