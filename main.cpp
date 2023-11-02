#include <iostream>

using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int array[size][size];

    int userInput;
    cout << "Enter the starting number: ";
    cin >> userInput;

    array[0][0] = userInput;

    for (int i = 0; i < size; ++i) {
        if (i > 0) {
            array[0][i] = array[0][i - 1] * 2;
        }
    }

    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            array[i][j] = array[i - 1][j] * 2;
        }
    }

    cout << "The resulting array:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
