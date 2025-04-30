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

// Find consecutive seats
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

int main(){
	
    int i, j;

    // Initialize all seats
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            seats[i][j] = 0;

    // Password
    int pass, ok = 0;
    for (i = 0; i <=2; i++) {
        printf("Please enter the password (Default: 2025): ");
        scanf("%d", &pass);
        if (pass == 2025) {
            printf("Login successful!\n");
            ok = 1;
	    system("CLS");
            break;
        } else {
            printf("Incorrect password!\n");
        }
    }
    if (!ok) {
        printf("Incorrect three times. Exiting program.\n");
        return 0;
    }

    // Preset occupied seats
    int preset[10][2] = {
        {0,1}, {0,8}, {1,8}, {2,3}, {3,4},
        {4,2}, {5,1}, {5,8}, {6,7}, {8,3}
    };
    for (i = 0; i < 10; i++) {
        seats[preset[i][0]][preset[i][1]] = 1;
    }

    // Main menu loop
    char sel;
    while (1) {
        printf("\n---------[Booking System]---------\n");
        printf("a. View available seats\n");
        printf("b. Auto arrange seats\n");
        printf("c. Choose seats manually\n");
        printf("d. Exit\n");
        printf("----------------------------------\n");
        printf("Please select an option: ");
        scanf(" %c", &sel);

        if (sel == 'a') {
            showSeats();
        }






















}

return 0;

} 
