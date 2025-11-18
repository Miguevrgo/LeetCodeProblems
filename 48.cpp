#include <print>
#include <vector>

void rotate(std::vector<std::vector<int>> &matrix) {
    // Transpose
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = i + 1; j < matrix.size(); ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Swap
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix.size() / 2; ++j) {
            std::swap(matrix[i][j], matrix[i][matrix.size() - j - 1]);
        }
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::print("{} ", matrix);
    rotate(matrix);
    std::print("{}", matrix);
}
