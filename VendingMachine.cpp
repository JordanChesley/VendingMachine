#include "VendingMachine.h"
#include <iostream>
using namespace std;

void VendingMachine::showChoices(int totalCost)
{
  // Output each item in the machine
  cout << "1. Twinkies - $2.50\n";
  cout << "2. Snickers Bar - $1.50\n";
  cout << "3. Pop -Tarts - $1.75\n";
  cout << "4. Granola Bars - $3.25\n";
  cout << "5. Pretzels - $4.10\n";

  // Use printf to format the totalCost float
  printf("0. Checkout - $%.2f \n", totalCost / 100.00);

  // Print exit option
  cout << "-1 - Exit\n";
}

void VendingMachine::getCustomerChoice(int &userChoice)
{
  int input;
  // Keep asking for their choice if the input does not fall in the range [-1,5].
  do
  {
    cout << "Make a choice: ";
    cin >> input;
  } while (input > 6 || input < -1);

  // Overwrite userChoice to the new input.
  userChoice = input;
}

int VendingMachine::takeMoney(int totalCost)
{
  // If the totalCost is 0, no need to take in money.
  if (totalCost == 0)
    return 0;
  int totalReceived = 0;
  float enteredMoney = 0;

  // Continue to ask for money until the totalReceived is greater than the totalCost.
  do
  {
    printf("Money Entered: %.2f\n", totalReceived / 100.00);
    cout << "Enter money in the following demoninations (1,0.25): ";
    cin >> enteredMoney;
    // If the money is not 1 or 0.25 denomination, ask again.
    if (enteredMoney != 1.00 && enteredMoney != 0.25)
      continue;

    // Convert to cents
    totalReceived += enteredMoney * 100;
  } while (totalReceived < totalCost);

  // Return the total received.
  return totalReceived;
}

void VendingMachine::computeChange(int totalCost, int moneyReceived)
{
  // Initialize currency,
  int pennies = 0, nickels = 0, dimes = 0, quarters = 0;
  int change = moneyReceived - totalCost;

  // For each coin denomination, calculate the number of each coin type to return.
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

  // Output the returned change.
  printf("Dispensing Change: $%.2f, Quarters: %d, Dimes: %d, Nickels: %d, Pennies: %d\n", (moneyReceived - totalCost) / 100.00, quarters, dimes, nickels, pennies);
}
