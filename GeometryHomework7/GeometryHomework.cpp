// Lab 12, The "Geometry Homework 7" Program
// Programmer: Sydney Schiller
// Editor(s) used: Notepad
// Compiler(s) used: MinGW TDM GCC

#include "GeometryHomework.h"

#include <iostream>
using std::endl;
using std::ios;
using std::ostream;

#include <iomanip>
using std::setprecision;

#include <cstdlib>
#include <cmath>

// global variables
const double PI = 3.14159;

// base class Shape
Shape::Shape(const char* const token[])
:dimension1(token[1] ? atof(token[1]) : 0),
 dimension2(token[2] ? atof(token[2]) : 0),
 dimension3(token[3] ? atof(token[3]) : 0){}

//Square
Square::Square(const char* const token[])
:Shape(token){}
void Square::output(ostream &out) const
{
  out << "SQUARE side=" << dimension1;// output to screen
  out << set << " area=" << dimension1 * dimension1;
  out << " perimeter= " << dimension1 * 4 << reset << endl;
}
void Square::xls(ostream &out) const
{
  out << "SQUARE" << "\t" << dimension1 << "\t\t\t\t\t"// output to .xls file
   << set << dimension1 * dimension1 << "\t"
   << reset << dimension1 * 4 << "\t\t\n";
}

//Rectangle
Rectangle::Rectangle(const char* const token[])
:Shape(token){}
void Rectangle::output(ostream &out) const
{
  out << "RECTANGLE length=" << dimension1 << " width=" << dimension2;
  out << set << " area=" << dimension1 * dimension2;
  out << " perimeter=" << (dimension1 * 2) + (dimension2 * 2) << reset << endl;
}
void Rectangle::xls(ostream &out) const
{
  out << "RECTANGLE\t\t\t" << dimension1 << "\t" << dimension2 << "\t\t"
   << set << dimension1 * dimension2 << "\t"
   << reset << (dimension1 * 2) + (dimension2 * 2) << "\t\t\n";
}

//Circle
Circle::Circle(const char* const token[])
:Shape(token){}
void Circle::output(ostream &out) const
{
  out << "CIRCLE radius=" << dimension1;
  out << set << " area=" << PI * ((dimension1) * (dimension1));
  out << " perimeter=" << 2 * PI * (dimension1) << reset << endl;
}
void Circle::xls(ostream &out) const
{
  out << "CIRCLE" << "\t\t" << dimension1 << "\t\t\t\t"
   << set << PI * ((dimension1) * (dimension1)) << "\t"
   << 2 * PI * (dimension1) << "\t\t\n" << reset;
}

//Cube
Cube::Cube(const char* const token [])
:Square(token){}
void Cube::output(ostream &out) const
{
  out << "CUBE" << " side=" << dimension1;
  out << set <<  " surface area=" << 6 * (dimension1 * dimension1);
  out << " volume=" << pow(dimension1, 3.0) << reset << endl;
}
void Cube::xls(ostream &out) const
{
  out << "CUBE" << "\t" << dimension1 << "\t\t\t\t\t\t\t"
   << 6 * (dimension1 * dimension1) << "\t"
   << pow(dimension1, 3.0) << "\n";
}

//Prism
Prism::Prism(const char* const token[])
:Rectangle(token){}
void Prism::output(ostream &out) const
{
  out << "PRISM" << " length=" << dimension1 << " width=" << dimension2 << " height=" << dimension3;
  out << set << " surface area=" << (2 * (dimension1) * (dimension2)) + (2 * ((dimension1) + (dimension2)) * (dimension3));
  out << " volume=" << (dimension1) * (dimension2) * (dimension3) << reset << endl;
}
void Prism::xls(ostream &out) const
{
  out << "PRISM" << "\t\t\t" << dimension1 << "\t" << dimension2 << "\t" << dimension3 << "\t\t\t"
    << (2 * (dimension1) * (dimension2)) + (2 * ((dimension1) + (dimension2)) * (dimension3)) << "\t"
    << (dimension1) * (dimension2) * (dimension3) << "\n";
}

//Cylinder
Cylinder::Cylinder(const char* const token[])
:Circle(token){}
void Cylinder::output(ostream &out) const
{
  out << "CYLINDER" << " radius=" << dimension1 << " height=" << dimension2;
  out << set << " surface area=" << 2 * (PI * (dimension1 * dimension1)) + 2 * (PI * dimension1 * dimension2);
  out << " volume=" << PI * dimension1 * dimension1 * dimension2 << reset << endl;
}
void Cylinder::xls(ostream &out) const
{
  out << reset << "CYLINDER" << "\t\t" << dimension1 << "\t\t\t" << dimension2 << "\t\t\t"
    << set << 2 * (PI * (dimension1 * dimension1)) + 2 * (PI * dimension1 * dimension2) << "\t"
    << reset <<  PI * dimension1 * dimension1 * dimension2 << "\n";
}

//overloaded operator <<
ostream& operator<<(ostream& out, const Shape* s)
 {
   s->output(out);
   return out;
 }
 // newly defined output stream manipulators
ostream& reset(ostream& out) // requires iostream, using ostream
{
  out.unsetf(ios::fixed|ios::showpoint); // requires iostream, using ios
  out << setprecision(6); // requires iostream and iomanip, using setprecision
  return out;
}

ostream& set(ostream& out) // requires iostream, using ostream
{
  out.setf(ios::fixed|ios::showpoint); // requires iostream, using ios
  out << setprecision(2); // requires iostream and iomanip, using setprecision
  return out;
}
