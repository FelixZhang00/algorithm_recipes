//
// Created by felix on 2017/10/3.
//

/**
 * 用 {make,push,pop}_heap()实现多路归并
 * 题目：用一台4GB内存的机器对磁盘上的单个100GB文件排序。
 * 思路：先分块排序，然后多路归并输出文件。
 * 多路归并用heap排序实现，
 * 比如要归并已经按照从小到大的顺序排好序的32个文件，
 * 我们可以构造一个32元素的min heap，每个元素是std::pair<Record,FILE*>.
 * 然后每次取出堆顶的元素，将其Record写入输出文件；如果FILE*还可读，就读入一条Record，再向heap中添加
 * std::pair<Record,FILE*>。这样当heap为空的时候，多路归并就完成了。
 */



#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

typedef int Record;
typedef std::vector<Record> File;

struct Input
{
    Record value;
    size_t index;
    const File* file;

    explicit Input(const File* f)
            : value(-1),
              index(0),
              file(f)
    { }

    bool next()
    {
        if (index < file->size())
        { value = (*file)[index];
            ++index;
            return true;
        } else {
            return false;
        }
    }

    bool operator<(const Input& rhs) const
    {
        // make_heap to build min-heap, for merging
        return value > rhs.value;
    }
};

File mergeN(const std::vector<File>& files)
{
    File output;
    std::vector<Input> inputs;

    for (size_t i = 0; i < files.size(); ++i) {
        Input input(&files[i]);
        if (input.next()) {
            inputs.push_back(input);
        }
    }

    //构造一个binary heap
    std::make_heap(inputs.begin(), inputs.end());
    //反复取出堆顶元素，直到堆为空
    while (!inputs.empty()) {
        //pop_heap会把堆顶元素放到序列末尾，即inputs.back()处。
        std::pop_heap(inputs.begin(), inputs.end());
        output.push_back(inputs.back().value); //得到当前最小的数

        //从堆顶元素所属文件读取下一条记录
        if (inputs.back().next()) {
            //如果当前文件还有内容，则再次把它放到堆中，进行下一轮读取
            std::push_heap(inputs.begin(), inputs.end());
        } else {
            //如果当前文件没有内容了，就把它从堆中移除
            inputs.pop_back();
        }
    }

    return output;
}

int main()
{
    const int kFiles = 32;
    std::vector<File> files(kFiles);
    for (int i = 0; i < kFiles; ++i) {
        //模拟实际需要排序的文件内容
        File file(rand() % 1000); //随机大小
        std::generate(file.begin(), file.end(), &rand); //随机元素


        std::sort(file.begin(), file.end());            //对单个文件的内容排序
        files[i].swap(file);
    }
    std::cout<<"Before:--------------"<<std::endl;
    std::copy(files[0].begin(), files[0].end(),
              std::ostream_iterator<Record>(std::cout, "\n"));

    //将多个文件归并排序成一个
    File output = mergeN(files);
    std::cout<<"After:--------------"<<std::endl;
    std::copy(output.begin(), output.end(),
              std::ostream_iterator<Record>(std::cout, "\n"));
}
