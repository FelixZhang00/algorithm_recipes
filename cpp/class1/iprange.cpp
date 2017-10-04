//
// Created by tmac on 2017/10/3.
//

#include <vector>
#include <string>
#include <assert.h>
#include <stdint.h>

#include <algorithm>

/**
 * 题目：已知N个IP地址区间和它们对应的城市名称，写一个程序，能从IP地址找到它所在的城市。注意这些IP地址区间互不重叠
 * 思路：先做一遍排序，再用std::lower_bound()进行查找
 */

template<typename V>
struct IpRange {

    IpRange(int _startip, int _endip, V _val) : startIp(_startip), endIp(_endip), value(_val) {};

    IpRange(int _startip, int _endip) : startIp(_startip), endIp(_endip), value() {};

    int startIp;
    int endIp;
    V value;

    bool operator<(const IpRange &rhs) const {
        return startIp < rhs.startIp;
    }

//    bool operator==(const IpRange &rhs) {
//        return startIp == rhs.startIp;
//    }

};

template<typename V>
bool operator==(const IpRange<V> &lhs, const IpRange<V> &rhs) {
    return lhs.startIp == rhs.startIp;
}

// REQUIRE: ranges is sorted.
template<typename V>
V findIpValue(const std::vector<IpRange<V>> &ranges, int ip) {
    V result;

    if (!ranges.empty()) {
        IpRange<V> needle = {ip, 0};
        auto it = std::lower_bound(ranges.begin(), ranges.end(), needle);
        if (it == ranges.end()) {
            --it;
        } else if (it != ranges.begin() && it->startIp > ip) {
            --it;
        }
        if (it->startIp <= ip && it->endIp >= ip) {
            result = it->value;
        }

    }

    return result;
}

int main() {

    std::vector<IpRange<std::string>> ipRanges;
    IpRange<std::string> r1(1, 100, "shanghai");
    ipRanges.push_back(r1);
    ipRanges.emplace_back(102, 200, "shenzheng");
    ipRanges.emplace_back(202, 300, "beijing");

    std::sort(ipRanges.begin(), ipRanges.end());
    assert(std::adjacent_find(ipRanges.begin(), ipRanges.end()) == ipRanges.end());

    std::string v = findIpValue(ipRanges, 0);
    assert(v.empty());

    v = findIpValue(ipRanges, 101);
    assert(v.empty());

    v = findIpValue(ipRanges, 50);
    assert(v == "shanghai");

    v = findIpValue(ipRanges, 150);
    assert(v == "shenzheng");

    v = findIpValue(ipRanges, 250);
    assert(v == "beijing");


    return 0;
}