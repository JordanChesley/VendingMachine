#include "VendingMachine.h"
#include <iostream>
using namespace std;

int main()
{
  VendingMachine vendingMachine;
  char orderAgain;
  do
  {

    // Initialize variables to track dynamic information
    int totalCost = 0;
    int userChoice = 0;

    // Continue to show options and get the user choice while the user is not ready to check out.
    do
    {
      vendingMachine.showChoices(totalCost);
      vendingMachine.getCustomerChoice(userChoice);
      switch (userChoice)
      {

      // Add the price according to their selection.
      case 1:
        totalCost += 250;
        break;
      case 2:
        totalCost += 150;
        break;
      case 3:
        totalCost += 175;
        break;
      case 4:
        totalCost += 325;
        break;
      case 5:
        totalCost += 410;
        break;
      // If user wishes to exit, end the program.
      case -1:
        exit(0);
      }

      // Apply the sales tax.
      if (userChoice != 0)
        totalCost *= 1.07;
    } while (userChoice != 0);

    // Have the user enter money into the machine.
    int moneyRecevied = vendingMachine.takeMoney(totalCost);

    // Return extra change entered into the machine.
    vendingMachine.computeChange(totalCost, moneyRecevied);

    // Ask if they would like to make another order.
    do
    {
      cout << "Do you want to start another order? Y/N ";
      cin >> orderAgain;
    } while (orderAgain != 'Y' && orderAgain != 'N');

  } while (orderAgain == 'Y');
  // No more orders. Exit.
  cout << "Exiting\n";
}
