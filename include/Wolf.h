#include "Animal.h"

class World;
class Wolf : public Animal {
  Organism* getChild(int x, int y) override;
public:
  Wolf(int, int, World*);
};
