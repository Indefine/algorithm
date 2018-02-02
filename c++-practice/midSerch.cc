#pragma GCC diagnostic error "-std=c++11" 
#include <iostream>
#include <vector>

using std::vector;

void midSerch(vector<int> datas, int need);
void midSerch2(vector<int> datas, int need, int start, int end);
int main() {
    vector<int> datas(1000,1);
    datas[998] = 100;
    datas[999] = 1000;
    datas[356] = 1;
    midSerch2(datas, 1000, 0, datas.size() - 1);
    return 0;
}
void midSerch2(vector<int> datas, int need, int start, int end) {

    if (start > end)
        std::cout << "no postion find" <<std::endl;
    int mid = start + (end - start) / 2;
    
    if (need > datas[mid]) {
        midSerch2(datas, need, mid + 1, end);
    }
    else if (need < datas[mid])
    {
        midSerch2(datas, need, start, mid - 1);
    }
    else
        std::cout << "find postion is " << mid << std::endl;
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
