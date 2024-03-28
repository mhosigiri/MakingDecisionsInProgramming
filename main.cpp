//Anish KC
//CS1437 52008
//3-26-2024
//I will approach this program by creating prototype, defining functions, and calling functions.

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include "Input_Validation_Extended.h"
using namespace std;

void calculateVelocity();
void calculateAcceleration();
void motionMenu();
void solveForV();
void solveForS();
void solveForV2();
void solveForV_bar();
void calculateWeight();
void calculateMomentum();

string colorGreen = "\x1b[" + to_string(32) + ";1m";
string colorRed = "\x1b[" + to_string(31) + ";1m";
string colorBlue = "\x1b[" + to_string(36) + ";1m";
string reset = "\x1b[0m";



int main()
{
  string choice = "";
  do
    {
      cout << colorBlue;
      cout << "Physics Calculator\n";
      cout << "----------------------\n";
      cout << "1. Calculate Velocity\n";
      cout << "2. Calculate Acceleration\n";
      cout << "3. Motion Calculations Menu\n";
      cout << "4. Calculate Weight\n";
      cout << "5. Calculate Momentum\n";
      cout << "Press E or e to Exit\n";
      cout << reset;
      choice = validateString(choice);

      if(choice == "1"){
        calculateVelocity();
      } else if(choice == "2"){
        calculateAcceleration();
      } else if(choice == "3"){
        motionMenu();
      } else if(choice == "4"){
        calculateWeight();
      } else if(choice == "5"){
        calculateMomentum();
      } else if(choice == "e" || choice == "E"){
        cout << "Goodbye!\n";
      }
      else{
        cout << colorRed << "Invalid choice. Please try again.\n" << reset;
      }
      
    } while(choice != "E" && choice != "e");
    cout << "Thank you for using the Physics Calculator!\n";

    
  return 0;
}

void calculateVelocity()
{
  double ds = 0.0; //change in displacement

  string dsUnits = ""; //displacement unit

  double dt =0.0; //change in time

  string dtUnits = ""; //time unit

  cout << colorGreen;
  cout << "Enter the displacement (ds): ";
  ds = validateDouble(ds);
  cout << "Enter displacement unit (m, km, etc.): ";
  dsUnits = validateString(dsUnits);
  cout << "Enter the time (dt): ";
  dt = validateDouble(dt);
  cout << "Enter time unit (sec, hour, etc.): ";
  dtUnits = validateString(dtUnits);
  cout << reset;

  double v = ds / dt;
  cout << fixed << setprecision(4) << v << " = " << ds << "/" << dt << " " << dsUnits << " / " << dtUnits << endl; 
}

void calculateAcceleration()
{
  double dv = 0.0; //change in velocity

  string dvUnits = ""; //velocity unit

  double dt =0.0; //change in time

  string dtUnits = ""; //time unit

  cout << colorGreen;
  cout << "Enter the change in velocity (dv): ";
  dv = validateDouble(dv);
  cout << "Enter velocity unit (m/s, km/h, etc.): ";
  dvUnits = validateString(dvUnits);
  cout << "Enter the time (dt): ";
  dt = validateDouble(dt);
  cout << "Enter time unit (sec, hour, etc.): ";
  dtUnits = validateString(dtUnits);
  cout << reset;

  double a = dv / dt;
  cout << fixed << setprecision(4) << a << " = " << dv << "/" << dt << " " << dvUnits << " / " << endl;
  
}

void motionMenu()
{
  string choice = "";
  
  do {
    cout << colorBlue;
    cout << "Motion Menu;\n";
    cout << "1. Solve for v(v = vO + at)\n";
    cout << "2. Solve for s(s = sO + vOt + 1/2at^2)\n";
    cout << "3. Solve for v^2(v^2 = vO^2 + 2a(s - sO))\n";
    cout << "4. Solve for v_bar (v_bar = 1/2(v + vO))\n";
    cout << "Press E or e to return to main menu\n";
    cout << "Enter your choice: ";
    cout << reset;
    choice = validateString(choice);

    if(choice == "1"){
      solveForV();
    } else if(choice == "2"){
      solveForS();
    } else if(choice == "3"){
      solveForV2();
    } else if(choice == "4"){
      solveForV_bar();
    } else if(choice == "e" || choice == "E"){
      cout << "Goodbye!\n";
    } else {
      cout << colorRed << "Invalid choice. Please try again.\n" << reset;
    }
    
  } while (choice != "e" && choice != "E");
}

void solveForV()
{
  double vO = 0.0; //initial velocity
  double a = 0.0; //acceleration
  double t = 0.0; //time
  
  cout << colorGreen;
  cout << "Enter the initial velocity (vO) in m/s : ";
  vO = validateDouble(vO);
  cout << "Enter the acceleration (a) in m/s^2: ";
  a = validateDouble(a);
  cout << "Enter the time (t) in seconds: ";
  t = validateDouble(t);
  cout << reset;

  double v = vO + a * t;
  cout << fixed << setprecision(4) << "v = " << vO << " + " << a << " * " << t << " = " << v << " m/s" << endl;
}

void solveForS()
{
  double sO = 0.0; //initial displacement
  double vO = 0.0; //initial velocity
  double a = 0.0; //acceleration
  double t = 0.0; //time
  
  cout << colorGreen;
  cout << "Enter the initial displacement (sO) in m: ";
  sO = validateDouble(sO);
  cout << "Enter the initial velocity (vO) in m/s : ";
  vO = validateDouble(vO);
  cout << "Enter the acceleration (a) in m/s^2: ";
  a = validateDouble(a);
  cout << "Enter the time (t) in seconds: ";
  t = validateDouble(t);
  cout << reset;

  double s = sO + vO * t + (1/2 * a) * pow(t,2);
  cout << fixed << setprecision(4) << "s = " << sO << " + " << vO << " * " << t << " + 1/2" << a << " * " << t << "^2 = " << s << endl;
}

void solveForV2()
{
  double vO = 0.0; //initial velocity
  double a = 0.0; //acceleration
  double s = 0.0; //final displacement
  double sO = 0.0; //initial displacement

  cout << colorGreen;
  cout << "Enter the initial velocity (vO) in m/s : ";
  vO = validateDouble(vO);
  cout << "Enter the acceleration (a) in m/s^2: ";
  a = validateDouble(a);
  cout << "Enter the final displacement (s) in m: ";
  s = validateDouble(s);
  cout << "Enter the initial displacement (sO) in m: ";
  sO = validateDouble(sO);
  cout << reset;

  double v2 = pow(vO,2) + 2 * a * (s - sO);
  cout << fixed << setprecision(4) << "v^2 = " << vO << "^2 + 2 * " << a << " * (" << s << " - " << sO << ") = " << v2 << endl;
}

void solveForV_bar()
{
  double v = 0.0; //final velocity
  double vO = 0.0; //initial velocity

  cout << colorGreen;
  cout << "Enter the final velocity (v) in m/s : ";
  v = validateDouble(v);
  cout << "Enter the initial velocity (vO) in m/s : ";
  vO = validateDouble(vO);
  cout << reset;
  

  double v_bar = (v + vO) / 2;
  cout << fixed << setprecision(4) << "v_bar = (" << v << " + " << vO << ") / 2 = " << v_bar << endl;
}

void calculateWeight()
{
  double m = 0.0; //mass
  double g = 9.8; //gravity
  string mUnits = ""; //mass unit

  cout << colorGreen;
  cout << "Enter the mass (mass): ";
  m = validateDouble(m);
  cout << "Enter mass unit (kg, g, etc.): ";
  mUnits = validateString(mUnits);
  cout << reset;

  double w = m * g;
  cout << fixed << setprecision(4) << w << " = " << m << " * " << g << " " << mUnits << endl;
  
}

void calculateMomentum()
{
  double m = 0.0; //mass
  double v = 0.0; //velocity

  string momUnits = ""; //mass unit

  cout << colorGreen;
  cout << "Enter the mass of the object (m): ";
  m = validateDouble(m);
  cout << "Enter the velocity of the object (v): ";
  v = validateDouble(v);
  cout << "Enter the expected measure output unit (kg, g, etc.): ";
  momUnits = validateString(momUnits);
  cout << reset;

  double p = m * v;
  cout << fixed << setprecision(4) << p << " = " << m << " * " << v << " " << momUnits << endl;
}
