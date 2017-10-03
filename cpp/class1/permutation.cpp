//
// Created by felix on 2017/10/3.
//

/**
 * 题目：生成N个不同元素的全排列
 * 使用next_permutation，会修改迭代器
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {

    int elements[] = { 1, 2, 3, 4 };
    const size_t N = sizeof(elements)/sizeof(elements[0]);
    std::vector<int> vec(elements, elements + N);

    int count = 0;
    do
    {
        std::cout << ++count << ": ";
        std::copy(vec.begin(), vec.end(),
                  std::ostream_iterator<int>(std::cout, ", "));
        std::cout << std::endl;
    } while (next_permutation(vec.begin(), vec.end()));
}

