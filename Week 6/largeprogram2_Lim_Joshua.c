// Joshua Lim
// Dr. Steinberg
// COP3223C Section 4
// Large Program 2

#include <stdio.h>

void greeting(); // welcome the user
void order(double *balance); // user will make a purchase
void viewHand(double *balance); // display current amount in hand - user starts with $0.00
void transaction(double *balance, double price); // transaction with user
void pullMoney(double *balance); // grab more money from the unlimited wallet
void displayVendingOptions(); // display beverage options and prices

// Vending Machine Selections
//     Item     |   Price
// -------------------------
//   Sprite     |   $2.50
//   Coca-Cola  |   $2.50
//   Water      |   $2.00
//   Gatorade   |   $3.00
//   Diet Cola  |   $2.55
//   Fanta      |   $2.55
//   Root Beer  |   $1.50
//   Dr. Pepper |   $1.55

// done
int main(void) { // main function

    double balance = 0.00; // user's balance
    double *balancePtr = &balance; // pointer to balance
    balancePtr = &balance; // set pointer to balance
    char choice;
    greeting(); // welcome the user
    while (choice != 'e' && choice != 'E') { // while the user does not want to exit

        printf("Please select one of the following options.\n");
        printf("O: Order from the unlimited vending machine.\n");
        printf("V: View what you have in your hand currently\n");
        printf("D: Display what the unlimited vending machine contains.\n");
        printf("G: Grab money out of unlimted wallet.\n");
        printf("D: Display what the unlimited vending machine contains.\n");
        printf("E: Exit.\n");
        printf("*****************************************************\n");
        printf("Please select what you would like to do.\n");
        printf("Option Selected: ");
        scanf(" %c", &choice);
        printf("\n");

        switch (choice) { // switch statement to determine what the user wants to do

            case 'O':
            case 'o':
            {
                order(balancePtr);
                break;
            }
            case 'V':
            case 'v':
            {
                viewHand(balancePtr);
                break;
            }
            case 'D':
            case 'd':
            {
                printf("You selected the view vending machine option.\n");
                displayVendingOptions();
                break;
            }
            case 'G':
            case 'g':
            {
                pullMoney(balancePtr);
                break;
            }
            case 'E':
            case 'e':
            {
                printf("*****************************************************\n");
                printf("Thank you for visiting the unlimited vending machine!\n");
                printf("You have $%.2lf in your hand. Make sure to put that back into your unlimited wallet.\n", balance);
                printf("Have a great day!\n");
                break;
            }
            default:
            {
                printf("Invalid input. Please try again.\n");
                greeting();
                break;
            }

        }

    }

    return 0;

}

// done
void greeting() { // welcome the user

    printf("Welcome to the Unlimited Vending Machine\n");
    printf("We have an unlimited variety of drinks.\n");
    printf("With your unlimited wallet, you will never run out of cash!.\n");
    printf("What would you like to order today?\n");
    printf("*****************************************************\n");

}

// done
void order(double *balance) { // allow user to make a purchase

    int selection;
    double price;

    printf("You have selected to order something from the unlimited vending machine.\n");
    printf("*****************************************************\n");
    displayVendingOptions();
    printf("Please select one of the following options: ");
    scanf("%d", &selection);

    switch (selection) { // switch statement to determine what the user wants to order
        case 1:
            printf("Sprite has been selected. Total cost is: $2.50\n");
            printf("Beginning Transaction Process.\n");
            price = 2.50;
            transaction(balance, price);
            break;
        case 2:
            printf("Coca-Cola has been selected. Total cost is: $2.50\n");
            printf("Beginning Transaction Process.\n");
            price = 2.50;
            transaction(balance, price);
            break;
        case 3:
            printf("Water has been selected. Total cost is: $2.00\n");
            printf("Beginning Transaction Process.\n");
            price = 2.00;
            transaction(balance, price);
            break;
        case 4:
            printf("Gatorade has been selected. Total cost is: $3.00\n");
            printf("Beginning Transaction Process.\n");
            price = 3.00;
            transaction(balance, price);
            break;
        case 5:
            printf("Diet Cola has been selected. Total cost is: $2.55\n");
            printf("Beginning Transaction Process.\n");
            price = 2.55;
            transaction(balance, price);
            break;
        case 6:
            printf("Fanta has been selected. Total cost is: $2.55\n");
            printf("Beginning Transaction Process.\n");
            price = 2.55;
            transaction(balance, price);
            break;
        case 7:
            printf("Root Beer has been selected. Total cost is: $1.50\n");
            printf("Beginning Transaction Process.\n");
            price = 1.50;
            transaction(balance, price);
            break;
        case 8:
            printf("Dr. Pepper has been selected. Total cost is: $1.55\n");
            printf("Beginning Transaction Process.\n");
            price = 1.55;
            transaction(balance, price);
            break;
        default:
            printf("Invalid selection. Please try again.\n");
            order(balance);
            break;
    }

}

// done
void viewHand(double *balance) { // display current amount in hand - user starts with $0.00

    printf("You selected to see how much cash you have in your hand currently.\n");
    printf("*****************************************************\n");
    printf("You have $%.2lf in your hand currently.\n", *balance);
    printf("*****************************************************\n");

}

// done
void transaction(double *balance, double price) { // transaction with user, if user has enough money, subtract from balance, if not, force user to grab more money until they have enough

    if (*balance >= price) { // if user has enough money, subtract from balance & complete transaction

        printf("You have $%.2lf in your hand before the transaction.\n", *balance);
        printf("Putting $%.2lf into the vending machine.\n", price);
        *balance -= price;
        printf("Transaction was successful!\n");
        printf("You now have $%.2lf in your hand.\n", *balance);
        printf("*****************************************************\n");

    } else { // if user does not have enough money, force them to grab more money

        int validBalance = 0; // 0 = false, 1 = true
        while (validBalance == 0) { // while the user does not have enough money in their hand
            
            printf("You do not have enough in your account.\n");
            printf("Please pull more money from your the unlimited wallet.\n");
            printf("*****************************************************\n");
            pullMoney(balance);
            if (*balance >= price) { // if the user has enough money in their hand after pulling more money from the unlimited wallet
                validBalance = 1;
                printf("You have $%.2lfin your hand before the transaction.\n", *balance);
                printf("Putting $%.2lf into the vending machine.\n", price);
                *balance -= price;
                printf("Transaction was successful!\n");
                printf("You now have $%.2lf in your hand.\n", *balance);
                printf("*****************************************************\n");
            } else { // if the user still does not have enough money in their hand after pulling more money from the unlimited wallet
                validBalance = 0;
            }

        }

    }

}


// done
void pullMoney(double *balance) { // allow user to pull money from the unlimited wallet

    int choice;
    double newAmount;
    printf("You have selected to pull more money out of the unlimited wallet.\n");
    printf("*****************************************************\n");
    printf("How much would you like to pull from the unlimited wallet?\n");
    printf("1. $1.00\n");
    printf("2. $5.00\n");
    printf("3. $10.00\n");
    printf("Option Selected: ");
    scanf("%d", &choice);

    switch (choice) { // switch statement to determine how much money the user wants to pull from the unlimited wallet
        case 1:
        {
            newAmount = 1.00;
            break;
        }
        case 2:
        {
            newAmount = 5.00;
            break;
        }
        case 3:
        {
            newAmount = 10.00;
            break;
        }
        default:
        {
            printf("Invalid selection. Please try again.\n");
            pullMoney(balance);
            break;
        }

    }

    printf("*****************************************************\n");
    *balance += newAmount;
    printf("$%.2lf has been added to your hand successfully!\n", newAmount);
    printf("*****************************************************\n");

}

// done
void displayVendingOptions() { // display the vending options

    printf("Here are the options!\n");
    printf("*****************************************************\n");
    printf("1. Sprite        $2.50\n");
    printf("2. Coca-Cola     $2.50\n");
    printf("3. Water         $2.00\n");
    printf("4. Gatorade      $3.00\n");
    printf("5. Diet Cola     $2.55\n");
    printf("6. Fanta         $2.55\n");
    printf("7. Root Beer     $1.50\n");
    printf("8. Dr. Pepper    $1.55\n");
    printf("*****************************************************\n");

}