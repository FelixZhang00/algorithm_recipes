//
// Created by felix on 2017/10/3.
//

/**
 * 生成从N个元素中取出M个的所有组合
 * 输出从7个不同元素中取出3个元素的所有组合
 * 思路：对序列{0, 0, 0, 0, 1, 1, 1}做全排列，每次输出数字1对应的位置上的元素。
 */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int values[] = {1, 2, 3, 4, 5, 6, 7};
    int elements[] = {0, 0, 0, 0, 1, 1, 1};
    const size_t N = sizeof(elements) / sizeof(elements[0]);
    std::vector<int> selectors(elements, elements + N);

    int count = 0;
    do {
        std::cout << ++count << ": ";
        for (size_t i = 0; i < selectors.size(); ++i) {
            if (selectors[i] == 1) {
                std::cout << values[i] << ", ";
            }
        }
        std::cout << std::endl;
    } while (std::next_permutation(selectors.begin(), selectors.end()));


    return 0;
}

