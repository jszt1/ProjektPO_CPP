#pragma once
#include <vector>

class World;
class Pos;
class Organism {
private:
  
  char orgType;
  int power;
  int initiative;
  int age;
  int x;
  int y;
  int prevX;
  int prevY;
protected:
  World *itsWorld;
  virtual void createChild(int x, int y) = 0;
public:
  Organism(char, int, int, int, int, World*, int age=0);
  virtual void action() = 0;
  virtual void colision(Organism*) = 0;
  virtual bool canEscape();
  void makeOlder();
  void empower(int);
  void draw();
  int getX() const;
  int getY() const;
  int getPrevX() const;
  int getPrevY() const;
  int getPower() const;
  int getInitiative() const;
  int getAge() const;
  bool setXY(int x, int y, bool forcedEmpty);
  static bool priority(Organism*, Organism*);
  virtual bool isAnimal();
  void goBack();
  std::vector<Pos> getFreePos();
  std::vector<Pos> getNeighbours();
  char getType() const;
  ~Organism() { }
  // void setType();
  // void setPower();
  // void setInitiative();
  // void setXY();
};
