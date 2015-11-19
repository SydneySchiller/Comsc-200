// Lab 12, The "Geometry Homework 7" Program
// Programmer: Sydney Schiller
// Editor(s) used: Notepad
// Compiler(s) used: MinGW TDM GCC

#ifndef GEOMETRYHOMEWORK_H
#define GEOMETRYHOMEWORK_H

#include <iostream>
using std::ostream;

// base class Shape
class Shape
{
  public:
    Shape(const char* const []);
    virtual void output(ostream&) const = 0;
    virtual void xls(ostream&) const = 0;
    virtual ~Shape(){};
  protected:
    const double dimension1;
    const double dimension2;
    const double dimension3;
};

struct Square : public Shape
{
    Square(const char* const []);
    void output(ostream&) const;
    void xls(ostream&) const;
};

struct Rectangle : public Shape
{
  Rectangle(const char* const []);
  void output(ostream&) const;
  void xls(ostream&) const;
};

struct Circle : public Shape
{
  Circle(const char* const []);
  void output(ostream&) const;
  void xls(ostream&) const;
};

struct Cube : public Square
{
  Cube(const char* const []);
  void output(ostream&) const;
  void xls(ostream&) const;
};

struct Prism : public Rectangle
{
  Prism(const char* const[]);
  void output(ostream&) const;
  void xls(ostream&) const;
};

struct Cylinder : public Circle
{
    Cylinder(const char* const []);
    void output(ostream&) const;
    void xls(ostream&) const;
};

ostream& operator<<(ostream&, const Shape*);
ostream& reset(ostream&);
ostream& set(ostream&);

#endif
