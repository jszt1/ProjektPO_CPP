#include "Organism.h"

class Animal : Organism {
  void action() override;
  void colision() override;
  void draw() override;

  Animal(World &);
};
