// Lab 9, The "Elevator" Program
// Programmer: Sydney Schiller
// Editor(s) used: Notepad
// Compiler(s) used: MinGW TDM GCC


#include "Rider.h"

int Rider::n = 0;

Rider::Rider(const Floor& d)
: riderID(n++), dest(&d)
{} // end class Rider constructor

bool Rider::operator== (const Rider& b) const
{
  bool result = true;
  if(riderID != b.riderID)
    result = false;
  return result;
}

bool Rider::operator< (const Rider& b) const
{
  bool result = true;
  if(riderID >= b.riderID)
    result = false;
  return result;
}

Rider& Rider::operator= (const Rider& r)
{
  if (this == &r) return *this;
  const_cast<const Floor*&>(dest) = r.dest;
  const_cast<int&>(riderID) = r.riderID;
  return *this;
}

const Floor& Rider::getDestination() const
{
  return *dest;
}
