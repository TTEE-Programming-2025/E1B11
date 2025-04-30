#include <stdio.h>
#include <stdlib.h>

int seats[9][9];

// Clear all suggested seats (value 2)
void clearSeats() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (seats[i][j] == 2)
                seats[i][j] = 0;
}

// Display current seat map
void showSeats() {
    printf(" 123456789\n");
    for (int i = 0; i < 9; i++) {
        printf("%d", 9 - i);
        for (int j = 0; j < 9; j++) {
            if (seats[i][j] == 0) printf("-");
            else if (seats[i][j] == 1) printf("*");
            else if (seats[i][j] == 2) printf("@");
        }
        printf("\n");
    }
}

// Find horizontal consecutive seats
int findRowSeats(int need, int temp[4][2]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j <= 9 - need; j++) {
            int k;
            for (k = 0; k < need && seats[i][j + k] == 0; k++);
            if (k == need) {
                for (k = 0; k < need; k++) {
                    temp[k][0] = i;
                    temp[k][1] = j + k;
                }
                return 1;
            }
        }
    }
    return 0;
}

// Find a 2x2 block of available seats
int findBlockSeats(int temp[4][2]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (seats[i][j] == 0 && seats[i][j + 1] == 0 &&
                seats[i + 1][j] == 0 && seats[i + 1][j + 1] == 0) {
                temp[0][0] = i;     temp[0][1] = j;
                temp[1][0] = i;     temp[1][1] = j + 1;
                temp[2][0] = i + 1; temp[2][1] = j;
                temp[3][0] = i + 1; temp[3][1] = j + 1;
                return 1;
            }
        }
    }
    return 0;
}

int main{





























return 0;

} 
