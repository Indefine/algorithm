#include <iostream>

bool plalindrome(std::string, int, int);

int main() {
    std::string str;
    getline(std::cin, str);
    if (plalindrome(str, 0, str.size() - 1))
        std::cout << "this string is a plalindrome" << std::endl;
    else
        std::cout << "this string is not a plalindrome" << std::endl;
    return 0;
}

bool plalindrome(std::string str, int begin, int end) {
    if (begin > end)
        return true;
    if (str[begin] != str[end])
        return false;
    else
        return plalindrome(str, begin + 1, end - 1);
}
