// Lab 9, The "Elevator" Program
// Programmer: Sydney Schiller
// Editor(s) used: Notepad
// Compiler(s) used: MinGW TDM GCC

#ifndef FLOOR_H
#define FLOOR_H


class Floor
{
  public:
    Floor(const int inches) : location(inches){}
    int getLocation() const {return location;}

    private:
      const int location;
};

#endif // FLOOR_H
