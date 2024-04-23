#pragma once
#include "Organism.h"

class Animal : public Organism {
public:
  void action() override;
  void colision(Organism*) override;
protected:
  Animal(char, int, int, int, int);
};
