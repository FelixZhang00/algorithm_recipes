//
// Created by felix on 2017/10/3.
//

/**
 * 用unique()去除连续重复空白
 * 题目：给你一个字符串，要求原地把相邻的多个空格替换为一个
 * 例如，输入"a  b",输出"a b"
 * 思路: unique()的作用是去除相邻的重复元素。我们把"重复元素"定义为"两个元素都是空格"
 * 注意：所有针对STL algorithm都只能调换区间内元素的顺序，不能真正删除容器内的元素，需要手动删除。
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <assert.h>

struct AreBothSpaces {
    bool operator()(char x, char y) const {
        return x == ' ' && y == ' ';
    }
};


void removeContinuousSpaces(std::string& str){
    //unique()的作用是去除相邻的重复元素。我们把"重复元素"定义为"两个元素都是空格"
    std::string::iterator last = std::unique(str.begin(),str.end(),AreBothSpaces());
    //所有针对STL algorithm都只能调换区间内元素的顺序，不能真正删除容器内的元素，需要手动删除。
    str.erase(last,str.end());
}

int main() {

    std::string inout;

    inout = "";
    removeContinuousSpaces(inout);
    assert(inout == "");

    inout = "a";
    removeContinuousSpaces(inout);
    assert(inout == "a");

    inout = " a";
    removeContinuousSpaces(inout);
    assert(inout == " a");

    inout = "  a";
    removeContinuousSpaces(inout);
    assert(inout == " a");

    inout = "a ";
    removeContinuousSpaces(inout);
    assert(inout == "a ");

    inout = "a  ";
    removeContinuousSpaces(inout);
    assert(inout == "a ");

    inout = "aaa    bbb";
    removeContinuousSpaces(inout);
    assert(inout == "aaa bbb");

    inout = "aaa    bbb       ccc";
    removeContinuousSpaces(inout);
    assert(inout == "aaa bbb ccc");

    inout = " a b   c d ";
    removeContinuousSpaces(inout);
    assert(inout == " a b c d ");

    inout = "        ";
    removeContinuousSpaces(inout);
    assert(inout == " ");


    return 0;
}

