#include <stdio.h>

void print_arg(int *data_list, int length);

void bubbleSort(int *data_list, int length);

void bubbleSort2(int *data_list, int length);

void bubbleSort3(int *data_list, int length);

int main() {
    int a[] = {9,8,7,7,109,82, -1,2,1,0};
    bubbleSort3(a, 10);
    print_arg(a, 10);
    return 0;
}

void bubbleSort(int *data_list, int length) {
    int i,j,swap;

    //onece loop get one biger value on top;
    for(i = 0; i < length; i++) {
        for(j = 0; j < length - i - 1; j++){
            if(data_list[j] > data_list[j + 1]) {
                swap = data_list[j];
                data_list[j] = data_list[j + 1];
                data_list[j + 1] = swap;
            }
        }
    }
}


void bubbleSort2(int *data_list, int length) {
    int i =length - 1;
    int pos = 1, j, tmp;
    while (i) {
        pos = 0;
        for (j = 0; j < i; j ++) {
            if (data_list[j] > data_list[j + 1]) {
                tmp = data_list[j];
                data_list[j] = data_list[j + 1];
                data_list[j + 1] = tmp;
                pos = j;
            }
        }
        i = pos;
    }
}

void bubbleSort3(int *data_list, int length) {
    int i, j , tmp;
    int low = 0, hight = length - 1;
    while (low < hight) {
        
        for (i = 0; i <hight; i++) {
            if (data_list[i] > data_list[i + 1]) {
                tmp = data_list[i];
                data_list[i] = data_list[i + 1];
                data_list[i + 1] = tmp;
            }
        }
        hight--;

        for (i = length - 1; i > low; i--) {
            if (data_list[i] < data_list[i - 1]) {
                tmp = data_list[i];
                data_list[i] = data_list[i - 1];
                data_list[i - 1] = tmp;
            }
        }

        low++;
    }
}


void print_arg(int *data_list, int length) {
    int i;
    for(i = 0; i < length - 1; i++) {
        printf(" %d,",data_list[i]);
    }
    printf(" %d\n",data_list[i]);
}
