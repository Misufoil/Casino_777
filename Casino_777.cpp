#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void rules () {
    cout << "\t\t\t\t\tRULES\n";
    cout << "1) If three different numbers come up - you lose.\n";
    cout << "2) If two numbers are the same - the amount of the bet is returned to the balance.\n";
    cout << "3) If the first and last number are the same - the dropped number becomes the multiplier of the bet.\n";
    cout << "4) If three numbers are the same - the drawn number is squared and becomes the bet multiplier.\n";
    system("pause");
}

template<typename T>
T InputError(T number) {
    while (!(cin >> number) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Input error! Retry input: ";
    }
    return number;
}

int Amount() {
    int amount = 0;
    cout << "\nAmount: ";
    amount = InputError(amount);
    return amount;
}

int slots(int balance, string name) {
    int bet = 0;
    bool choice = 1;
    int spin = 0;

    do {
        if (balance == 0) {
            cout << "Your balance: " << balance << endl;
            cout << "Enter (1) - replenish the balance OR Enter (0) - finish playing: ";
            choice = InputError(choice);

            if (choice) {
                balance += Amount();
            }
        }
        else {
            system("cls");
            cout << name << ", enter bet amount: ";
            bet = InputError(bet);

            cout << "Enter the number of spins: ";
            spin = InputError(spin);
            cout << endl;
    
            if ((bet * spin) > balance) {
                cout << "Your bet is more than the balance!" << endl;
            }
            else {
                while (spin--) {
                    const int SIZE = 3;
                    int arr[SIZE];

                    for (int i = 0; i < SIZE; i++) {
                        arr[i] = rand() % 6 + 2;
                    }

                    cout << "\t________" << endl;
                    cout << "\t|";
                    for (int i = 0; i < SIZE; i++) {
                        cout << arr[i] << " ";
                    }
                    cout << "|" << endl << endl;

                    if (arr[0] == arr[1] && arr[1] == arr[2]) {
                        cout << name << ", YOU WIN!!! - " << bet * arr[0] * arr[0] << endl;
                        balance += bet * arr[0] * arr[0];
                        cout << "Balance: " << balance << endl << endl;
                    }
                    else if ((arr[0] == arr[2]) && (arr[0] != arr[1])) {
                        cout << name << ", you win! - " << bet * arr[0] << endl;
                        balance += bet * arr[0];
                        cout << "Balance: " << balance << endl << endl;
                    }
                    else if ((arr[0] == arr[1]) || (arr[1] == arr[2])) {
                        cout << "The bet returned to the balance." << endl;
                        cout << "Balance: " << balance << endl << endl;
                    }
                    else {
                        cout << name << ", you lost, better luck next time !!!" << endl;
                        balance -= bet;
                        cout << "Balance: " << balance << endl << endl;
                    }
                } 
            }
            cout << "Enter (1) - spin slots OR Enter (0) - If you want to return to the main menu: ";
            choice = InputError(choice);
        }
    } while (choice);

    return balance;
}

int main() {
    string name;
    int balance;
    bool choice = 1;
    int option = 1;
    srand(time(NULL)); 

    cout << "\n\t\t////////////WELCOM TO THE CASINO 777 !!!////////////\n\n";
    cout << "We have the most honest roulette in the Wild West, test your luck!\n\n";
    system("pause");
    system("cls");

    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter the starting balance.";
    balance = Amount();
    cout << endl;
    rules();

    do {
        system("cls");
        cout << "Player: " << name << endl;
        cout << "Your balance: " << balance << endl << endl;
        do {
            cout << "Enter (1) - spin slots.\n";
            cout << "Enter (2) - replenish the balance.\n";
            cout << "Enter (0) - finish playing.\n";
            cout << "Your choice: ";
            option = InputError(option);
            cout << endl;

            switch (option) {
                case 0: {
                    choice = 0;
                    option = 0;
                    break;
                }
                case 1: { 
                    balance = slots(balance, name);
                    option = 0;
                    break;
                }
                case 2: {
                    balance += Amount();
                    option = 0;
                    break;
                }
            }
        } while (option); 
    } while (choice);

    cout << "\n\t\t\tThank you for using the services of the CASINO 777.\n";
    cout << "\t\t\t\t\t\t Good luck!!!\n";
    system("pause");
        
    return 0;
}
