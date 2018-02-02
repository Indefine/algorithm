#pragma GCC diagnostic error "-std=c++11"  
#include <iostream>
#include <vector>
#include <cctype>


using std::vector;

void string_opt(std::string &str);
void vector_count();
void vector_init();
void vector_opt();
void vector_iter();

int main() {
    std::string str;
//    vector_init();
//    vector_opt();
//    vector_count();
    vector_iter();
    return 0;
}

void vector_iter() {
    vector<int> v {100, 3};
    for (auto i = v.begin(); i != v.end(); i++) {
        *i = *i * 2;
    }

    for (auto i = v.begin(); i != v.end(); i++) {
        std::cout << *i;
    }
}

void vector_count() {
    vector<int> v(10);
    for (auto &i : v)
        std::cin >> i;

    for (int j = 0; j < v.size(); j++) {
        std::cout << v[j] + v[v.size() - j - 1];
    }
    std::cout << std::endl;
    for (int j = 0; j < v.size(); j++) {
        if (j == 0)
            std::cout << v[1];
        else if (j == v.size() - 1)
            std::cout << v[v.size() - 2];
        else
            std::cout << v[j + 1] + v[j -1];
    }
}

void vector_opt() {
    vector<std::string> v;

    std::string word;
    for (int i = 0; i < 10; i++) {
        std::cin >> word;
        for (auto &c: word) 
            c = toupper(c);
        v.push_back(word);
    }
    
    for (auto s : v) {
        std::cout << s << std::endl;
    }

}

void  vector_init() {
    vector<std::string> v{10, "hi"};

    for (auto x : v) {
        std::cout << x;
    }
}
void string_opt(std::string &str) {
    for (char &c : str) {
        c = 'a';
    }
}

void string_in() {
    int opt;
    std::string line1, line2;
    while (true) {
        std::cout << "input get line : 1 or get char : 2" <<std::endl;
        std::cin >> opt;
        switch (opt) {
            case 1:
                while (getline(std::cin, line1)) std::cout << line1 << std::endl;
            case 2:
                while (std::cin >> line1) std::cout << line1 << std::endl;
            case 3:
                
                std::cin.ignore();
                getline(std::cin, line1);
                std::cin.sync();
                getline(std::cin, line2);
                std::cin.sync();
                if (line1 == line2) std::cout << "lin1 is equal line2" << std::endl;
                else
                    std::cout<< (line1.size() > line2.size() ? line1 : line2);
                if(line1.size() == line2.size()) std::cout << "size1 equal size2" <<std::endl;
                
            default:
                std::cin.ignore();
                break;
        }
    }
 
}
