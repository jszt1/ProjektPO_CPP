#pragma once
#include "Organism.h"

class Animal : public Organism {
public:
  void action() override;
  void colision(Organism*) override;
  bool isAnimal();
protected:
  Animal(char, int, int, int, int, World*);
  virtual Organism* getChild(int x, int y) = 0;
  void createChild(int x, int y);
};
