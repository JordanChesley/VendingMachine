#include "VendingMachine.h"
#include <iostream>
using namespace std;

void VendingMachine::showChoices(int totalCost)
{
  cout << "1. Twinkies - $2.50\n";
  cout << "2. Snickers Bar - $1.50\n";
  cout << "3. Pop -Tarts - $1.75\n";
  cout << "4. Granola Bars - $3.25\n";
  cout << "5. Pretzels - $4.10\n";
  printf("0. Checkout - $%.2f \n", totalCost / 100.00);
}

void VendingMachine::getCustomerChoice(int &userChoice)
{
  cout << "Make a choice: ";
  cin >> userChoice;
}

int VendingMachine::takeMoney(int totalCost)
{
  if (totalCost == 0)
    return 0;
  int totalReceived = 0;
  float enteredMoney = 0;
  do
  {
    printf("Money Entered: %.2f\n", totalReceived / 100.00);
    cout << "Enter money in the following demoninations (1,0.25): ";
    cin >> enteredMoney;
    if (enteredMoney != 1.00 && enteredMoney != 0.25)
      continue;
    totalReceived += enteredMoney * 100;
  } while (totalReceived < totalCost);
  return totalReceived;
}

void VendingMachine::computeChange(int totalCost, int moneyReceived)
{
  int pennies = 0, nickels = 0, dimes = 0, quarters = 0;
  int change = moneyReceived - totalCost;
  while ((change / VendingMachine::QUARTER) > 0)
  {
    quarters++;
    change -= VendingMachine::QUARTER;
  }
  while ((change / VendingMachine::DIME) > 0)
  {
    dimes++;
    change -= VendingMachine::DIME;
  }
  while ((change / VendingMachine::NICKEL) > 0)
  {
    nickels++;
    change -= VendingMachine::NICKEL;
  }
  while ((change / VendingMachine::PENNY) > 0)
  {
    pennies++;
    change -= VendingMachine::PENNY;
  }
  printf("Dispensing Change: $%.2f, Quarters: %d, Dimes: %d, Nickels: %d, Pennies: %d\n", (moneyReceived - totalCost) / 100.00, quarters, dimes, nickels, pennies);
}
