#include "Animal.h"

class World;
class Fox : public Animal {
  Organism* getChild(int x, int y) override;
public:
  Fox(int, int, World*);
  void action();
};
