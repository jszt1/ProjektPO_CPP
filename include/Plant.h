#pragma once
#include "Organism.h"

class Plant : public Organism{
public:
  void action() override;
  void colision(Organism*) override;
protected:
  Plant(char, int, int, int, World*);
  virtual Organism* getChild(int x, int y) = 0;
  void createChild(int x, int y);
};