#include <iostream>
#include <vector>

using namespace std;
void print_vector(vector<int> data_list);

void bubbleSort(vector<int> &data_list);

int main() {
    int array[] = {100,8,8,6,4,2,3,8,9,33,55,73,32};
    vector<int> data_list(array, array + 13);
    bubbleSort(data_list);
    print_vector(data_list);
    return 0;
}

void print_vector(vector<int> data_list) {
    for(vector<int>::iterator iter = data_list.begin(); iter != data_list.end(); iter++)
        cout << "  " << *iter << ",";
}

void bubbleSort(vector<int> &data_list) {
    int i , j, tmp;
    for(i = 0; i < data_list.size(); i++) {
        for(j = 0; j < data_list.size() - i - 1; j++) {
            if (data_list[j] > data_list[j + 1]) {
                tmp = data_list[j];
                data_list[j] = data_list[j+1];
                data_list[j + 1] = tmp;
            }
        }
    }
} 
