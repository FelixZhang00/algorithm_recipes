//
// Created by felix on 2017/10/4.
//

/**
 * 用partition()实现重排数组，让奇数位于偶数前面
 */

#include <iostream>
#include <vector>
#include <algorithm>

bool isOdd(int x) {
    return x % 2 != 0;
}

int main() {

    int numbers[] = {1, 2, 3, 4, 5, 6};
    const size_t N = sizeof(numbers) / sizeof(numbers[0]);
    std::stable_partition(numbers, numbers + N, &isOdd);
    std::copy(numbers, numbers + N, std::ostream_iterator<int>(std::cout, ", "));
    std::cout << std::endl;

    return 0;
}