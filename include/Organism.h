#pragma once
#include "World.h"
class World;

class Organism {
private:
  World &world;
  char orgType;
  int power;
  int initiative;
  int x;
  int y;

protected:
  World getWorld() const;

public:
  Organism(World &);
  Organism(World &, char, int, int, int, int);
  virtual void action() {}
  virtual void colision() {}
  virtual void draw() {}
  int getX() const;
  int getY() const;
  int getPower() const;
  int getInitiative() const;
  char getType() const;

  // void setType();
  // void setPower();
  // void setInitiative();
  // void setXY();
};
