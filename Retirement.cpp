#include <iostream>
#include <iomanip>
#include "Retirement.h"
using namespace std;

// this is a driver function that prompts the user for the information to create a rough estimate of how much will be saved by retirement and then will call estimatEarnings() function
void Retirement::estimateDriver(){
  int curAge, retAge; // curAge: current age, retAge: age when retired
  double princAmt, contrib, RoR; // princAmt: principal amount, contrib: monthly contribution, RoR: Rate of Return
  char choice;
  bool repeat = true;

  cout << endl << "Estimate Savings at Retirement." << endl;
  cout << "Disclaimer: This is only a rough estimate!" << endl << endl;
  cout << "Enter your current age in years: ";
  cin >> curAge;
  while(curAge <= 0){
    cout << "Age cannot be 0 or less.\nRe-enter age in years: ";
    cin >> curAge;
  }
  cout << "Enter your target retirement age: ";
  cin >> retAge;
  while(retAge < curAge){

    cout << "Retirement age cannot be less than current age." << endl;
    cout << "Re-enter age in years: ";
    cin >> retAge;
  }
  cout << "How much have you saved towards retirement? $";
  cin >> princAmt;

  while(princAmt < 0){

    cout << "Current money saved cannot be negative." << endl;
    cout << "Re-enter your current money saved: $";
    cin >> princAmt;
  }
  cout << "Enter your monthly contribution to retirement: $";
  cin >> contrib;

  while(contrib < 0){

    cout << "Monthly contribution cannot be negative." << endl;
    cout << "Re-enter your monthly contribution: $";
    cin >> contrib;
  }

  cout << "Enter the estimate annual return on investment (in %): ";
  cin >> RoR;

  while(RoR < 0){

    cout << "Annual return cannot be negative." << endl;
    cout << "Re-enter your annual return: ";
    cin >> RoR;
  }

  cout << "." << endl << "." << endl <<"...calculating" << endl << endl;

  estimateEarnings(curAge, retAge, princAmt, contrib, RoR);

  do{
        cout << "Calculate another estimate? (y/n): ";
        cin >> choice;

        switch(toupper(choice)){
        case 'Y':
          estimateDriver();
          repeat = false;
          break;
        case 'N':
          return; // stops switch statement and display menu options thats continually running
        }
    }while(repeat);
}
// the function will calculate and print retirement savings and growth based on user input and will return the total retirement savings
double Retirement::estimateEarnings(int curAge, int retAge, double princAmt, double contrib, double RoR){

  double totSavings = princAmt;
  double monthlyGrowth = 0;
  double totGrowth = 0;
  int numOfYearsToCalc = (retAge * 12) - (curAge * 12);

  for(int i = 1; i <= numOfYearsToCalc; i++){
    monthlyGrowth = (totSavings * (RoR * 0.01)) / 12; // calc monthly growth

    totSavings += contrib + monthlyGrowth;
    totGrowth += monthlyGrowth;
  }
  cout << "Estimated Retirement Savings: $" << fixed << setprecision(2) << totSavings << endl;
  cout << "Estimated Retirement Growth: $" << fixed << setprecision(2) <<totGrowth << endl << endl;
  return totSavings;

}