/******************************************************************************

Machine Problem 04 = GCD and LCM Calculator

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

// ----- Function declarations (prototypes) -----
int gcdRecursive(int n1, int n2);
long long lcm(int n1, int n2);
bool Coprime(int n1, int n2);
void readPair(int &n1, int &n2);

// ----- Main -----
int main()
{
    int n1 = 0, n2 = 0;
    string choice;

    do {
        cout << "\n\t - - Menu Options - - \n";
        cout << "\t1 - GCD\n";
        cout << "\t2 - LCM\n";
        cout << "\t3 - Coprime\n";
        cout << "\t4 - GCD and LCM\n";
        cout << "\t0 - Exit\n";
        cout << "\n\tChoice: ";
        cin >> choice;
        cout << "\n";

        if (choice == "1" || choice == "GCD") {
            readPair(n1, n2);
            cout << "GCD(" << n1 << ", " << n2 << ") = "
                 << gcdRecursive(n1, n2) << "\n";
        }
        else if (choice == "2" || choice == "LCM") {
            readPair(n1, n2);
            cout << "LCM(" << n1 << ", " << n2 << ") = "
                 << lcm(n1, n2) << "\n";
        }
        else if (choice == "3" || choice == "Coprime") {
            readPair(n1, n2);
            if (Coprime(n1, n2))
                cout << n1 << " and " << n2 << " ARE coprime.\n";
            else
                cout << n1 << " and " << n2 << " are NOT coprime.\n";
        }
        else if (choice == "4" || choice == "GCD and LCM") {
            readPair(n1, n2);
            cout << "GCD(" << n1 << ", " << n2 << ") = "
                 << gcdRecursive(n1, n2) << "\n";
            cout << "LCM(" << n1 << ", " << n2 << ") = "
                 << lcm(n1, n2) << "\n";
        }
        else if (choice == "0" || choice == "Exit") {
            cout << "Finish\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != "0" && choice != "Exit");

    return 0;
}

// ----- Function definitions -----

int gcdRecursive(int n1, int n2) {
    if (n2 == 0)
        return n1;
    return gcdRecursive(n2, n1 % n2);
}

long long lcm(int n1, int n2) {
    return (long long)n1 / gcdRecursive(n1, n2) * n2;
}

bool Coprime(int n1, int n2) {
    return gcdRecursive(n1, n2) == 1;
}

void readPair(int &n1, int &n2) {
    do {
        cout << "Enter two integers (1 to 10000): ";
        cin >> n1 >> n2;
    } while (n1 < 1 || n1 > 10000 || n2 < 1 || n2 > 10000);
}