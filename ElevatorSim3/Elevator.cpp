// Lab 9, The "Elevator" Program
// Programmer: Sydney Schiller
// Editor(s) used: Notepad
// Compiler(s) used: MinGW TDM GCC

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <cstdlib>

#include "Elevator.h"
#include "Floor.h"

// initialize static variables
int Elevator::elevatorID = 1;
const int Elevator::IDLE = 0;
const int Elevator::UP = 1;
const int Elevator::DOWN = -1;

Elevator::Elevator(const int cap, const int s, const Floor& tFloor)
: ID(elevatorID++), capacity(cap), speed(s), toFloor(0) // initialize const data members
{
  location = tFloor.getLocation();
  direction = IDLE;
  doorOpen = true;
} // end Elevator class constructor

bool Elevator::isNearDestination() const
{
  //true if distance to destination is less than OR EQUAL TO the speed
  if(direction == UP) // above ground level
  {
    return(toFloor->getLocation() - location) <= speed? true: false;
  }else // compensate for basement level
  {
    return(location - toFloor->getLocation()) <= speed? true: false;
  }
} // end isNearDestination member function

void Elevator::moveToDestinationFloor()
{
  // set location to that of destination floor (if there is one)
  if(hasADestination())
    location = toFloor -> getLocation();

} // end moveToDestinationFloor member function

vector<Rider> Elevator::removeRidersForDestinationFloor()
{
  vector<Rider> removed;// create empty vector of removed riders to be used as return value
  if(!storage.empty())// if elevator has any riders
    {
      vector<Rider> remaining;// create an empty vector for riders who remain on elevator
      for(unsigned int i = 0; i < storage.size(); i++) // traverse vector of current riders
      {
        if(toFloor == &(storage[i]).getDestination())// if a rider's destination floor is same as elevator's destination...
          removed.push_back(storage[i]); // add rider to vector of removed riders
        else// else
          remaining.push_back(storage[i]); // add rider to vector of remaining riders
      }
      storage = remaining;// reassign elevator rider vector to vector of remaining riders
    }
  return removed;// return vector of removed riders
}

void Elevator::addRiders(const vector<Rider>& riders)
{
  for(unsigned int i = 0; i < riders.size(); i++) // traverse the parameter vector
  {
    if(getAvailableSpace() > 0) // if there is still room on the elevator
      storage.push_back(riders[i]);// add the rider to the elevator's rider vector
  }
}

void Elevator::setDestinationBasedOnRiders()
{
  if(!hasRiders())// if there are no riders on the elevator
    return;// exit the function

  toFloor = &storage[0].getDestination();// set elevator's destination to the zeroth Rider's destination
  for(unsigned int i = 0; i < storage.size(); i++) // traverse the vector of elevator riders
  {
    int rDest = abs(getLocation() - (storage[i].getDestination().getLocation()));// get the absolute value of the distance from the elevator to the rider's destination floor
    int eDest = abs(getLocation() - (toFloor->getLocation()));// get the absolute value of the distance from the elevator to the elevator's destination floor
    if(eDest < rDest)// if closer to the rider's destination than to the elevator's destination
      setDestination(&(storage[i].getDestination()));// set elevator's destination to the rider's destination
  }
}

ostream& operator<<(ostream& out, const Elevator& elev)
{
  // output inches and location
  out << elev.getLocation();
  if(elev.getLocation() == 0)
  {
    out << " inches at ground level. ";
  }else if(elev.getLocation() > 0)
  {
    out << " inches above ground. ";
  }else if(elev.getLocation() < 0)
  {
    out << " inches below ground. ";
  }

  //check to see if idle/up/down
  if(elev.isIdle())
  {
    out << "Idle. ";
  }else if(elev.isDirectionUp())
  {
    out << "Going up. ";
  }else if(elev.isDirectionDown())
  {
    out << "Going down. ";
  }

  //check if doors are open
  out << "Doors are ";
  elev.doorOpen == true ? out << "open." : out << "closed. ";

  //output number of riders
  if(elev.storage.empty())
    out << "No riders.";
  else if(elev.storage.size() == 1)
    out << elev.storage.size() << " rider. ";
  else
    out << elev.storage.size() << " riders. ";


  //output ID
  out << "Elevators: " << elev.ID;

  return out;
} // end operator function

