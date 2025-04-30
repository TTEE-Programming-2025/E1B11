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

        else if (sel == 'b') {
            int need, found = 0;
            int temp[4][2];
            clearSeats();

            printf("How many seats do you need (1~4)? ");
            scanf("%d", &need);

            if (need >= 1 && need <= 3) {
                found = findRowSeats(need, temp);
            } else if (need == 4) {
                found = findRowSeats(4, temp);
                if (!found) found = findBlockSeats(temp);
            }

            if (found) {
                for (i = 0; i < need; i++) {
                    seats[temp[i][0]][temp[i][1]] = 2;
                }
                printf("Suggested seats (@):\n");
                showSeats();
                char ans;
                printf("Are you satisfied with these seats? (y/n): ");
                scanf(" %c", &ans);
                if (ans == 'y') {
                    for (i = 0; i < need; i++)
                        seats[temp[i][0]][temp[i][1]] = 1;
                    printf("Seats confirmed, returning to main menu.\n");
                } else {
                    clearSeats();
                    printf("Suggestion canceled, returning to main menu.\n");
                }
            } else {
                printf("No suitable seats found.\n");
            }
        }

	else if (sel == 'c') {
            int r, c, num, count = 0;
            int temp[4][2];
            clearSeats();

            printf("How many seats do you want to choose (1~4)? ");
            scanf("%d", &num);
            if (num < 1 || num > 4) {
                printf("Invalid number of seats.\n");
                continue;
            }

            for (i = 0; i < num; i++) {
                while (1) {
                    printf("Enter seat %d (format Row-Column, example 2-9): ", i + 1);
                    scanf("%d-%d", &r, &c);
                    int row = 9 - r;
                    int col = c - 1;
                    if (row >= 0 && row < 9 && col >= 0 && col < 9) {
                        if (seats[row][col] == 0) {
                            seats[row][col] = 2;
                            temp[count][0] = row;
                            temp[count][1] = col;
                            count++;
                            break;
                        } else {
                            printf("Seat already taken, please choose another.\n");
                        }
                    } else {
                        printf("Invalid input, please try again.\n");
                    }
                }
            }

            printf("Suggested seats (@):\n");
            showSeats();
            printf("Press Enter to confirm...");
            getchar(); // Clear previous newline
            getchar(); // Wait for Enter

            for (i = 0; i < count; i++) {
                seats[temp[i][0]][temp[i][1]] = 1;
            }

            printf("Seats confirmed, returning to main menu.\n");
        }

        else if (sel == 'd') {
            char cont;
            while (1) {
                printf("Continue? (y/n): ");
                scanf(" %c", &cont);
                if (cont == 'y') break;
                else if (cont == 'n') {
                    printf("Thank you for using the system.\n");
                    return 0;
                } else {
                    printf("Invalid input, please enter 'y' or 'n'.\n");
                }
            }
        }

        else {
            printf("Invalid option, please try again.\n");
        }


*心得:做完這次作業，除了對陣列有更加了解外，也在函式、
多重迴圈方面有更多練習的機會，收穫很多。*/














}

return 0;

} 
