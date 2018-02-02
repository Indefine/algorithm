#include <iostream>

int route[10][10]
void dfs(int **);

void dfs(int **Map, int need, int x, int y) {
    for (int i = 0; i < 4; i++) {
        switch (i)
        case 0:
             dfs(Map, need, x + 1, y);
             break;
        case 1:
             dfs(Map, need, x -1, y);
             break;
        case 2:
             dfs(Map, need, x, y + 1);
        case 3:
            dfs(Map, need, x, y - 1);
        default:
           break; 

    }
}
