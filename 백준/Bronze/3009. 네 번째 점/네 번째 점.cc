#include <stdio.h>

int main(void) {
    int arr[3][2] = {0,};
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &(arr[i][0]), &(arr[i][1]));
    }
    int x, y;
    x = arr[0][0];
    y = arr[0][1];
    int cnt_x = 0, cnt_y = 0;
    for (int i = 0; i < 3; i++) {
        if (x == arr[i][0]) cnt_x++;
        if (y == arr[i][1]) cnt_y++;
    }
    if (cnt_x == 2) {
        int i = 0;
        while (arr[i][0] == x)
            i++;
        x = arr[i][0];
    }
    if (cnt_y == 2) {
        int i = 0;
        while (arr[i][1] == y)
            i++;
        y = arr[i][1];
    }
    printf("%d %d", x, y);
}