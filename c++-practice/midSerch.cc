#pragma GCC diagnostic error "-std=c++11" 
#include <iostream>
#include <vector>

using std::vector;

void midSerch(vector<int> datas, int need);
void midSerch2(vector<int> datas, int begin, int end, int need);
int main() {
    vector<int> datas(1000,1);
    datas[998] = 100;
    datas[999] = 1000;
    datas[356] = 1;
    midSerch2(datas, 0,datas.size() - 1,1000);
    return 0;
}

void midSerch2(vector<int> datas, int begin, int end, int need) {
    int mid = (begin - end) / 2;
    if (begin < mid) {
        std::cout << " unfind postion ";
        return;
    }
    if (datas[mid] == need)
    {
        std::cout << "find postion is " << mid;
        return;
    }
    if (datas[mid] < need)
        midSerch2(datas, mid + 1, end, need);
    else
        midSerch2(datas, begin, mid - 1, need);
}


void midSerch(vector<int> datas, int need) {
    auto begin = datas.begin();
    auto end = datas.end();
    auto mid = begin + (end - begin) / 2;
    
    while (mid != end && *mid != need) {
        if (need < *mid) {
            end = mid;
        }
        else {
            begin = mid + 1;
        } 
        mid = begin + (end - begin)/ 2;
    }

    std::cout << "find mid" << *mid;
}
