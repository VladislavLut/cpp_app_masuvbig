#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX_ROWS = 3;
const int MAX_COLS = 6;

void displayArray(int array[MAX_ROWS][MAX_COLS]) {
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void shiftArray(int array[MAX_ROWS][MAX_COLS], int shifts, std::string direction) {
    
    if (direction == "left") {
        shifts = MAX_COLS - (shifts % MAX_COLS);  
        for (int i = 0; i < MAX_ROWS; ++i) {
            for (int s = 0; s < shifts; ++s) {
                int temp = array[i][0];
                for (int j = 0; j < MAX_COLS - 1; ++j) {
                    array[i][j] = array[i][j + 1];
                }
                array[i][MAX_COLS - 1] = temp;
            }
        }
    }
    else if (direction == "right") {
        shifts = shifts % MAX_COLS;  
        for (int i = 0; i < MAX_ROWS; ++i) {
            for (int s = 0; s < shifts; ++s) {
                int temp = array[i][MAX_COLS - 1];
                for (int j = MAX_COLS - 1; j > 0; --j) {
                    array[i][j] = array[i][j - 1];
                }
                array[i][0] = temp;
            }
        }
    }
    else if (direction == "up") {
        shifts = shifts % MAX_ROWS; 
        for (int s = 0; s < shifts; ++s) {
            int temp = array[0][0];
            for (int i = 0; i < MAX_ROWS - 1; ++i) {
                for (int j = 0; j < MAX_COLS; ++j) {
                    array[i][j] = array[i + 1][j];
                }
            }
            for (int j = 0; j < MAX_COLS; ++j) {
                array[MAX_ROWS - 1][j] = array[MAX_ROWS - 2][j];
            }
            array[MAX_ROWS - 2][0] = temp;
        }
    }
    else if (direction == "down") {
        shifts = MAX_ROWS - (shifts % MAX_ROWS);  
        for (int s = 0; s < shifts; ++s) {
            int temp = array[MAX_ROWS - 1][0];
            for (int i = MAX_ROWS - 1; i > 0; --i) {
                for (int j = 0; j < MAX_COLS; ++j) {
                    array[i][j] = array[i - 1][j];
                }
            }
            for (int j = 0; j < MAX_COLS; ++j) {
                array[0][j] = array[1][j];
            }
            array[1][0] = temp;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int array[MAX_ROWS][MAX_COLS];

    
    for (int i = 0; i < MAX_ROWS; ++i) {
        for (int j = 0; j < MAX_COLS; ++j) {
            array[i][j] = rand() % 10;
        }
    }

    std::cout << "The initial array:" << std::endl;
    displayArray(array);

    int shifts;
    std::string direction;
    std::cout << "Enter the number of shifts: ";
    std::cin >> shifts;
    std::cout << "Select a shift direction (left, right, up, down): ";
    std::cin >> direction;

    shiftArray(array, shifts, direction);

    std::cout << "The resulting array after shifting:" << std::endl;
    displayArray(array);

    return 0;
}
