// Lab 11, The "Geometry Homework 6" Program
// Programmer: Sydney Schiller
// Editor(s) used: Notepad
// Compiler(s) used: MinGW TDM GCC

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::ostream;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <iomanip>
using std::setprecision;

#include <vector>
using std::vector;

#include <cstring>
#include <cstdlib>
#include <cmath>

// global variables
const double PI = 3.14159;
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 4;
const char* const DELIMITER = " ";

ostream& reset(ostream&);
ostream& set(ostream&);

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
Shape::Shape(const char* const token[])
:dimension1(token[1] ? atof(token[1]) : 0),
 dimension2(token[2] ? atof(token[2]) : 0),
 dimension3(token[3] ? atof(token[3]) : 0){}

struct Square : public Shape
{
    Square(const char* const []);
    void output(ostream&) const;
    void xls(ostream&) const;
};
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

struct Rectangle : public Shape
{
  Rectangle(const char* const []);
  void output(ostream&) const;
  void xls(ostream&) const;
};
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

struct Circle : public Shape
{
  Circle(const char* const []);
  void output(ostream&) const;
  void xls(ostream&) const;
};
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

struct Cube : public Square
{
  Cube(const char* const []);
  void output(ostream&) const;
  void xls(ostream&) const;
};
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

struct Prism : public Rectangle
{
  Prism(const char* const[]);
  void output(ostream&) const;
  void xls(ostream&) const;
};
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

struct Cylinder : public Circle
{
    Cylinder(const char* const []);
    void output(ostream&) const;
    void xls(ostream&) const;
};
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

int main()
{
  // print my name and this assignment's title
  cout << "\n Lab 11, The \"Geometry Homework 6\" Program \n";
  cout << "Programmer: Sydney Schiller\n";
  cout << "Editor(s) used: Notepad\n";
  cout << "Compiler(s) used: MinGW TDM GCC\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
  //declare vector
  vector<const Shape*> shapes;
  // create a file-reading object
  ifstream fin;
  ofstream fout;

  fin.open("geo.txt"); // open a file
  if (!fin.good())
    return 1; // exit if file not found
  // read each line of the file
  while (!fin.eof())
  {
    // read an entire line into memory
    char buf[MAX_CHARS_PER_LINE];
    fin.getline(buf, MAX_CHARS_PER_LINE); // parse the line into blank-delimited tokens
    int n = 0; // a for-loop index
    // array to store memory addresses of the tokens in buf
    const char* token[MAX_TOKENS_PER_LINE] = {}; // initialize to 0
    // parse the line
    token[0] = strtok(buf, DELIMITER); // first token
    if (token[0]) // zero if line is blank
    {
      for (n = 1; n < MAX_TOKENS_PER_LINE; n++)
      {
        token[n] = strtok(0, DELIMITER); // subsequent tokens
        if (!token[n]) break; // no more tokens
      }

      if((strcmp(token[0], "SQUARE") == 0))
      {
        const Square* const sq = new Square(token);
        shapes.push_back(sq);
      }
      else if((strcmp(token[0], "RECTANGLE") == 0))
      {
        const Rectangle* const rec = new Rectangle(token);
        shapes.push_back(rec);
      }
      else if((strcmp(token[0], "CIRCLE") == 0))
      {
        const Circle* const cir = new Circle(token);
        shapes.push_back(cir);
      }
      else if((strcmp(token[0], "CUBE") == 0))
      {
        const Cube* const cu = new Cube(token);
        shapes.push_back(cu);
      }
      else if((strcmp(token[0], "PRISM") == 0))
      {
        const Prism* const p = new Prism(token);
        shapes.push_back(p);
      }
      else if((strcmp(token[0], "CYLINDER") == 0))
      {
        const Cylinder* const cyl = new Cylinder(token);
        shapes.push_back(cyl);
      }
      else
      {
        cout << token[0] << " invalid object" << endl;// if object is not listed above, then it is invalid
      }
    }
  }
  fin.close(); // close files
  // 2nd loop for console output
  for(unsigned int j = 0; j < shapes.size(); j++)
  {
    shapes[j] -> output(cout);
  }

  fout.open("geo.xls");// open xls file
  if (!fout.good())
    return 1;

  fout << "shape\t side\t radius\t length\t width\t height\t area\t perimeter\t surface area\t volume\n";

  // 3rd loop for xls output
  for(unsigned int j = 0; j < shapes.size(); j++)
  {
    shapes[j] -> xls(fout);
  }
  fout.close(); // close file

  for(unsigned int k = 0; k < shapes.size(); k++) // deallocate dynamic memory
  {
      delete shapes[k];
  }
} // end main
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
