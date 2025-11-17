#include <algorithm>
#include <print>
#include <vector>

int findMinArrowShots(std::vector<std::vector<int>> &points) {
    std::sort(points.begin(), points.end());
    int arrows{0};
    size_t i{0};

    while (i < points.size()) {
        size_t j = i;
        arrows++;

        int lim_sup = points[i][1];
        while (j < points.size()) {
            if (points[j][0] <= lim_sup) {
                lim_sup = std::min(points[j][1], lim_sup);
                ++i;
            } else {
                break;
            }
            ++j;
        }
        ++i;
    }

    return arrows;
}

int main() {
    std::vector<std::vector<int>> matrix = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    std::println("Total arrows: {}", findMinArrowShots(matrix));
}
