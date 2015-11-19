// Lab 12, The "Geometry Homework 7" Program
// Programmer: Sydney Schiller
// Editor(s) used: Notepad
// Compiler(s) used: MinGW TDM GCC

#include "GeometryHomework.h"

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <vector>
using std::vector;

#include <cstring>

// global variables
const int MAX_CHARS_PER_LINE = 512;
const int MAX_TOKENS_PER_LINE = 4;
const char* const DELIMITER = " ";

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
    cout << shapes[j];
  }

  fout.open("geo.xls");// open xls file
  if (!fout.good())
    return 1;

  fout << "shape\t side\t radius\t length\t width\t height\t area\t perimeter\t surface area\t volume\n";

  // 3rd loop for xls output
  for(unsigned int j = 0; j < shapes.size(); j++)
  {
    fout << shapes[j];
  }
  fout.close(); // close file

  for(unsigned int k = 0; k < shapes.size(); k++) // deallocate dynamic memory
  {
      delete shapes[k];
  }
} // end main
