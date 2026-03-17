#include <iostream>
using namespace std;

void processScores(int *arr, int rows, int cols) {

    cout << "\nScore Table:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(arr + i * cols + j) << "\t";
        }
        cout << endl;
    }

    // Average per row
    cout << "\nAverage per student:\n";
    for (int i = 0; i < rows; i++) {
        int total = 0;

        for (int j = 0; j < cols; j++) {
            total += *(arr + i * cols + j);
        }

        double average = (double) total / cols;
        cout << "Student " << i + 1 << ": " << average << endl;
    }

    // Find lowest grade
    int lowest = *arr;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            int value = *(arr + i * cols + j);

            if (value < lowest) {
                lowest = value;
            }
        }
    }

    cout << "\nLowest score in table: " << lowest << endl;
}

int main() {

    int students, subjects;

    cout << "Number of students: ";
    cin >> students;

    cout << "Number of subjects: ";
    cin >> subjects;

    int *scores = new int[students * subjects];

    cout << "\nEnter scores:\n";

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < subjects; j++) {

            cout << "Student " << i + 1
                 << ", Subject " << j + 1 << ": ";

            cin >> *(scores + i * subjects + j);
        }
    }

    processScores(scores, students, subjects);

    delete[] scores;

    return 0;
}
