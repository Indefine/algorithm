#include <stdio.h>

int dp[100][100];
int ret[100][100];
void lcs();
int main() {

    char* a = "abcdefghijklmnopqrstuvwxyz";
    char* b = "aaabcdefghijklmnopqrstuvwxyzzz";

    lcs(a, b, 26, 30);
    return 0;
}


void lcs(char *a, char *b, int la, int lb) {
    int i,j;
    for (i = 0; i < la; i++) {
        dp[i][0] = 0;
    }

    for (j = 0; j < lb; j++) {
        dp[0][j] = 0;
    }

    for (i = 1; i < la; i++) {
        for (j = 0; j < lb; j++) {
            if (a[i] == b[j]) {
                ret[i][j] = 0;
                dp[i][j] = dp[i-1][j-1] + 1; // lcs + 1 up left
            }
            else if(dp[i][j - 1] > dp[i - 1][j]) {
                ret[i][j] = 1;
                dp[i][j] = dp[i][j - 1];   //unequal left
            }
            else{
                ret[i][j] = 2;
                dp[i][j] = dp[i - 1][j];   //unqueal up
            }
        }
    }

    while (la > 0 && lb > 0) {
        if (ret[la - 1][lb - 1] == 0) {
            printf("%c", a[la - 1]);
            la--;
            lb--;
        }
        else if (ret[la - 1][lb - 1] == 1) {
            lb--;
        }
        else
            la--;
    }
}
