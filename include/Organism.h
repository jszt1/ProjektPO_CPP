#pragma once

class World;

class Organism {
private:
  World *world;
  char orgType;
  int power;
  int initiative;
  int age;
  int x;
  int y;

protected:
  World getWorld() const;

public:
  Organism(char, int, int, int, int);
  virtual void action() = 0;
  virtual void colision(Organism*) = 0;
  void makeOlder();
  void draw() const;
  int getX() const;
  int getY() const;
  int getPower() const;
  int getInitiative() const;
  bool setXY(int x, int y, bool forcedEmpty);
  char getType() const;
  ~Organism() { }
  // void setType();
  // void setPower();
  // void setInitiative();
  // void setXY();
};
