#include "Animal.h"

class World;
class Sheep : public Animal {
  Organism* getChild(int x, int y) override;
public:
  Sheep(int, int, World*);
};
