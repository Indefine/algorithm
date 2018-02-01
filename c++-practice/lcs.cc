#include <iostream>
#include <stack>
#define MAXLEN 100

int dp[MAXLEN][MAXLEN];
int pos[MAXLEN][MAXLEN];

std::string lcs(std::string a, std::string b);

int main() {
    std::string a = "asdfghjklzxcvbnmqwertyuiop";
    std::string b = "dsadasdaasdaasaasdfghjklzxcvbnmqwertyuiopdass";
    lcs(a, b);

    std::cout << lcs(a,b) <<std::endl;
    return 0;
}

std::string lcs(std::string a, std::string b) {
    std::stack<char> ret;
    int i, j;
    int m = a.size();
    int n = b.size();
    for (i = 0; i < a.size(); i++) {
        dp[i][0] = 0;
    }

    for (j = 0; j < b.size(); j++) {
        dp[0][j] = 0;
    }

    for (i = 1; i < a.size(); i++) {
        for (j = 1; j < b.size(); j++) {
            if (a[i] == a[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                pos[i][j] = 0;
            }
            else if (dp[i - 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i - 1][j];
                pos[i][j] = 1;
            }
            else {
                dp[i][j] = dp[i][j - 1];
                pos[i][j] = 2;
            }
        }
    }

    while (m > 0 && n > 0) {
        if (pos[m - 1][n - 1] == 0) {
            ret.push(a[m - 1]);
            m--;
            n--;
        }
        else if (pos[m - 1][n - 1] == 1) {
            m--;
        }
        else
            n--;
    }
    std::string str = "";
    while (!ret.empty()) {
       str = str + ret.top();
       ret.pop();
    }

    return str;
}
