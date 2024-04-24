#include "Animal.h"

class World;
class Antelope : public Animal {
  Organism* getChild(int x, int y) override;
public:
  Antelope(int, int, World*);
  bool canEscape();
  void action();
};
