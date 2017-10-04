//
// Created by felix on 2017/10/4.
//

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hashmap; //元素、位置

        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            //是否能找到目标？
            auto it = hashmap.find(nums[i]);
            if (it == hashmap.end()) {
                hashmap.insert(make_pair(target - nums[i], i)); //添加要找的目标元素和当前的位置
            } else {

                //找到目标，返回结果
                result.push_back(it->second);
                result.push_back(i);
                break;
            }
        }

        return result;
    }
};


void printvector(const vector<int> &_vec) {
//    for (auto iter = _vec.cbegin(); iter != _vec.cend(); iter++) {
//        cout << (*iter) << ", ";
//    }
    for (const auto &it:_vec) {
        cout << it << ", ";
    }
    cout << endl;

}

int main() {

    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ret = Solution().twoSum(nums, target);

    printvector(ret);

    return 0;
}





