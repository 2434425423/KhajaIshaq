#include <iostream>
#include <vector>
#include <tuple> // Include this to use std::make_tuple

class SparseMatrix {
private:
    std::vector<std::tuple<int, int, int>> elements;
    int rows, cols;

public:
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    void addElement(int row, int col, int value) {
        if (value != 0) {
            elements.push_back(std::make_tuple(row, col, value));
        }
    }

    void displaySparse() {
        for (const auto &element : elements) {
            std::cout << std::get<0>(element) << " "
                      << std::get<1>(element) << " "
                      << std::get<2>(element) << std::endl;
        }
    }

    void displayFullMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                bool found = false;
                for (const auto &element : elements) {
                    if (std::get<0>(element) == i && std::get<1>(element) == j) {
                        std::cout << std::get<2>(element) << " ";
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    std::cout << "0 ";
                }
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    SparseMatrix sm(4, 5);

    // Adding non-zero elements
    sm.addElement(0, 2, 5);
    sm.addElement(1, 3, 8);
    sm.addElement(2, 1, 4);
    sm.addElement(3, 0, 7);
    sm.addElement(3, 4, 6);

    std::cout << "Sparse Matrix Representation:\n";
    sm.displaySparse();
    std::cout << "\nFull Matrix Representation:\n";
    sm.displayFullMatrix();

    return 0;
}
