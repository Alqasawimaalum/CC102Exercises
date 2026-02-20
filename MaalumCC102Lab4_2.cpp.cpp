#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        const int PRODUCTS = 5;
        const int SALESPERSONS = 4;

        double sales[PRODUCTS][SALESPERSONS] = {0};
        int salesperson, product;
        double amount;

        while (true) {
            cout << "\nEnter Salesperson number (1-4, 0 to stop): ";
            cin >> salesperson;

            if (salesperson == 0)
                break;

            cout << "Enter Product number (1-5): ";
            cin >> product;

            cout << "Enter amount sold: ";
            cin >> amount;

            sales[product - 1][salesperson - 1] += amount;
        }

        cout << "\n\n                           Salesperson\n";
        cout << setw(10) << "Product";

        for (int j = 0; j < SALESPERSONS; j++) {
            cout << setw(10) << j + 1;
        }

        cout << setw(12) << "total \n" << endl;
                cout << "_____________________________________________________________\n";

        double grandTotal = 0;

        for (int i = 0; i < PRODUCTS; i++) {
            double rowTotal = 0;

            cout << setw(10) << i + 1;

            for (int j = 0; j < SALESPERSONS; j++) {
                cout << setw(10) << fixed << setprecision(2) << sales[i][j];
                rowTotal += sales[i][j];
            }

            cout << setw(10) << rowTotal << endl;
            grandTotal += rowTotal;
        }
                        cout << "_____________________________________________________________\n";

        cout << setw(10) << "Total";

        for (int j = 0; j < SALESPERSONS; j++) {
            double columnTotal = 0;

            for (int i = 0; i < PRODUCTS; i++) {
                columnTotal += sales[i][j];
            }

            cout << setw(10) << columnTotal;
        }

        cout << setw(10) << grandTotal << endl;

        cout << "\nDo you want to repeat? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}
