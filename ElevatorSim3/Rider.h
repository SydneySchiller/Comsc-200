// Lab 9, The "Elevator" Program
// Programmer: Sydney Schiller
// Editor(s) used: Notepad
// Compiler(s) used: MinGW TDM GCC

#ifndef RIDER_H
#define RIDER_H

class Floor;
class Rider
{
  public:
    Rider(const Floor&);
    bool operator== (const Rider&) const;
    bool operator< (const Rider&) const;
    Rider& operator= (const Rider&);
    const Floor& getDestination() const;

    private:
      static int n;
      const int riderID;
      const Floor* const dest;
};

#endif // RIDER_H
