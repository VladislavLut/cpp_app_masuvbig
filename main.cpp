#include <iostream>

int main() {
    int rows;
    std::cout << "Enter the number of rows and columns in the array: ";
    std::cin >> rows;

    int* array = new int[rows * rows];

    int firstElement;
    std::cout << "Enter the first element of the array: ";
    std::cin >> firstElement;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            array[i * rows + j] = firstElement + i + j;
        }
    }

    std::cout << "Array:" << std::endl;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            std::cout << array[i * rows + j] << " ";
        }
        std::cout << std::endl;
    }

    delete[] array;

    return 0;
}
