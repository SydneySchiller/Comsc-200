// Lab 10, The "Geometry Homework 5" Program
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
class Shape{};

class Square : public Shape
{
  public:
    Square(const char* const []);
    void output(ostream&) const;
    void xls(ostream&) const;
  protected:
    const double side;
};
Square::Square(const char* const token[])
:side(token[1] ? atof(token[1]) : 0){}

void Square::output(ostream &out) const
{
  out << "SQUARE side=" << side;// output to screen
  out << set << " area=" << side * side;
  out << " perimeter= " << side * 4 << reset << endl;
}
void Square::xls(ostream &out) const
{
  out << "SQUARE" << "\t" << side << "\t\t\t\t\t";// output to .xls file
  out << set << side * side << "\t";
  out << reset << side * 4 << "\t\t\n";
}

class Rectangle : public Shape
{
  public:
    Rectangle(const char* const []);
    void output(ostream&) const;
    void xls(ostream&) const;
  protected:
    const double length;
    const double width;
};
Rectangle::Rectangle(const char* const token[])
:length(token[1] ? atof(token[1]) : 0), width(token[2] ? atof(token[2]) : 0)
{
}
void Rectangle::output(ostream &out) const
{
  out << reset << "RECTANGLE length=" << length << " width=" << width;
  out << set << " area=" << length * width;
  out << " perimeter=" << (length * 2) + (width * 2) << endl;
}
void Rectangle::xls(ostream &out) const
{
  out << "RECTANGLE" << "\t\t\t" << length << "\t" << width << "\t\t";
  out << set << length * width << "\t";
  out << reset << (length * 2) + (width * 2) << "\t\t\n";
}

class Circle : public Shape
{
  public:
    Circle(const char* const []);
    void output(ostream&) const;
    void xls(ostream&) const;
  protected:
    const double radius;
};
Circle::Circle(const char* const token[])
:radius(token[1] ? atof(token[1]) : 0) // initialize data members
{
}
void Circle::output(ostream &out) const
{
  out << reset << "CIRCLE radius=" << radius;
  out << set << " area=" << PI * ((radius) * (radius));
  out << " perimeter=" << 2 * PI * (radius) << endl;
}
void Circle::xls(ostream &out) const
{
  out << reset << "CIRCLE" << "\t\t" << radius << "\t\t\t\t";
  out << set << PI * ((radius) * (radius)) << "\t";
  out << 2 * PI * (radius) << "\t\t\n" << reset;
}

class Cube : public Square
{
  public:
    Cube(const char* const []);
    void output(ostream&) const;
    void xls(ostream&) const;
};
Cube::Cube(const char* const token [])
:Square(token) // initialize data members
{
}
void Cube::output(ostream &out) const
{
  out << "CUBE" << " side=" << side;
  out << set <<  " surface area=" << 6 * (side * side);
  out << " volume=" << pow(side, 3.0) << endl;
}
void Cube::xls(ostream &out) const
{
  out << reset << "CUBE" << "\t" << side << "\t\t\t\t\t\t\t";
  out << 6 * (side * side) << "\t";
  out << pow(side, 3.0) << "\n";
}

class Prism : public Rectangle
{
  public:
    Prism(const char* const[]);
    void output(ostream&) const;
    void xls(ostream&) const;
  private:
    const double height;
};
Prism::Prism(const char* const token[])
:Rectangle(token), height(token[3] ? atof(token[3]) : 0) // initialize data members
{
}
void Prism::output(ostream &out) const
{
  out << reset << "PRISM" << " length=" << length << " width=" << width << " height=" << height;
  out << set << " surface area=" << (2 * (length) * (width)) + (2 * ((length) + (width)) * (height));
  out << " volume=" << (height) * (length) * (width) << endl;
}
void Prism::xls(ostream &out) const
{
  out << reset << "PRISM" << "\t\t\t\t" << length << "\t" << width << "\t" << height << "\t\t\t";
  out << (2 * (length) * (width)) + (2 * ((length) + (width)) * (height)) << "\t";
  out << (height) * (length) * (width) << "\n";
}

class Cylinder : public Circle
{
  public:
    Cylinder(const char* const []);
    void output(ostream&) const;
    void xls(ostream&) const;
  private:
    const double height;
};
Cylinder::Cylinder(const char* const token[])
:Circle(token), height(token[2] ? atof(token[2]) : 0) // initialize data members
{
}
void Cylinder::output(ostream &out) const
{
  out << reset << "CYLINDER" << " radius=" << radius << " height=" << height;
  out << set << " surface area=" << 2 * (PI * (radius * radius)) + 2 * (PI * radius * height);
  out << " volume=" << PI * radius * radius * height << endl;
}
void Cylinder::xls(ostream &out) const
{
  out << reset << "CYLINDER" << "\t\t" << radius << "\t\t\t" << height << "\t\t\t";
  out << set << 2 * (PI * (radius * radius)) + 2 * (PI * radius * height) << "\t";
  out << reset <<  PI * radius * radius * height << "\n";
}

int main()
{
  // print my name and this assignment's title
  cout << "\n Lab 10, The \"Geometry Homework 5\" Program \n";
  cout << "Programmer: Sydney Schiller\n";
  cout << "Editor(s) used: Notepad\n";
  cout << "Compiler(s) used: MinGW TDM GCC\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl << endl;
  //declare vectors
  vector<const Shape*> shapes;
  vector<int> shapeID;
  // create a file-reading object
  ifstream fin;
  // xls output
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
        shapeID.push_back(1);
      }
      else if((strcmp(token[0], "RECTANGLE") == 0))
      {
        const Rectangle* const rec = new Rectangle(token);
        shapes.push_back(rec);
        shapeID.push_back(2);
      }
      else if((strcmp(token[0], "CIRCLE") == 0))
      {
        const Circle* const cir = new Circle(token);
        shapes.push_back(cir);
        shapeID.push_back(3);
      }
      else if((strcmp(token[0], "CUBE") == 0))
      {
        const Cube* const cu = new Cube(token);
        shapes.push_back(cu);
        shapeID.push_back(4);
      }
      else if((strcmp(token[0], "PRISM") == 0))
      {
        const Prism* const p = new Prism(token);
        shapes.push_back(p);
        shapeID.push_back(5);
      }
      else if((strcmp(token[0], "CYLINDER") == 0))
      {
        const Cylinder* const cyl = new Cylinder(token);
        shapes.push_back(cyl);
        shapeID.push_back(6);
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
    if(shapeID[j] == 1) // check shapeId for index
    {
      ((Square*)shapes[j]) -> output(cout);
    }else if(shapeID[j] == 2)
    {
      ((Rectangle*)shapes[j]) -> output(cout);
    }else if(shapeID[j] == 3)
    {
      ((Circle*)shapes[j]) -> output(cout);
    }else if(shapeID[j] == 4)
    {
      ((Cube*)shapes[j]) -> output(cout);
    }else if(shapeID[j] == 5)
    {
      ((Prism*)shapes[j]) -> output(cout);
    }else if(shapeID[j] == 6)
    {
      ((Cylinder*)shapes[j]) -> output(cout);
    }
    if(!shapes[j])
      break;
  }

  fout.open("geo.xls");// open xls file
  if (!fout.good())
    return 1;

  fout << "shape\t side\t radius\t length\t width\t height\t area\t perimeter\t surface area\t volume\n";

  // 3rd loop for xls output
  for(unsigned int j = 0; j < shapes.size(); j++)
  {
    if(shapeID[j] == 1) // check shapeId for index
    {
      ((Square*)shapes[j]) -> xls(fout);
    }else if(shapeID[j] == 2)
    {
      ((Rectangle*)shapes[j]) -> xls(fout);
    }else if(shapeID[j] == 3)
    {
      ((Circle*)shapes[j]) -> xls(fout);
    }else if(shapeID[j] == 4)
    {
      ((Cube*)shapes[j]) -> xls(fout);
    }else if(shapeID[j] == 5)
    {
      ((Prism*)shapes[j]) -> xls(fout);
    }else if(shapeID[j] == 6)
    {
      ((Cylinder*)shapes[j]) -> xls(fout);
    }
    if(!shapes[j])
      break;
  }
  fout.close(); // close file

  for(unsigned int k = 0; k < shapes.size(); k++) // deallocate dynamic memory
  {
    if(shapeID[k] == 1) // check shapeId for index
    {
      delete(Square*)shapes[k];
    }else if(shapeID[k] == 2)
    {
      delete(Rectangle*)shapes[k];
    }else if(shapeID[k] == 3)
    {
      delete(Circle*)shapes[k];
    }else if(shapeID[k] == 4)
    {
      delete(Cube*)shapes[k];
    }else if(shapeID[k] == 5)
    {
      delete(Prism*)shapes[k];
    }else if(shapeID[k] == 6)
    {
      delete(Cylinder*)shapes[k];
    }
    if(!shapes[k])
      break;
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
