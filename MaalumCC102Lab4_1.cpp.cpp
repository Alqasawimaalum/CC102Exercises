#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    char again;

    do {
        int students, quizzes;

        cout << "Enter number of students: ";
        cin >> students;

        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        double scores[students][quizzes];
        double average[students];


        for (int i = 0; i < students; i++) {
            cout << "\nStudent " << i + 1 << " scores: ";
            double sum = 0;

            for (int j = 0; j < quizzes; j++) {
                cin >> scores[i][j];
                sum += scores[i][j];
            }

            average[i] = sum / quizzes;
        }

        cout << "\n\nStudent";

        for (int j = 0; j < quizzes; j++) {
            cout << setw(8) << "Q" + to_string(j + 1);
        }

        cout << setw(10) << "Average" << endl;
        cout << "_______________________________________________________\n";

        for (int i = 0; i < students; i++) {
            cout << setw(7) << i + 1;

            for (int j = 0; j < quizzes; j++) {
                cout << setw(8) << scores[i][j];
            }

            cout << setw(10) << fixed << setprecision(2) << average[i] << endl;
        }

        cout << "\nRun program again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}
