#include "Animal.h"

class World;
class Turtle : public Animal {
  Organism* getChild(int x, int y) override;
public:
  Turtle(int, int, World*);
  void action();
};
