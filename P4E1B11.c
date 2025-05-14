#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10

// 學生資料結構
typedef struct {
    char name[20];
    char id[10]; // 學號（6位數字）
    int math, physics, english;
    float average;
} Student;

Student students[MAX];
int n = 0;

// 函式
void clearScreen();
void waitAndClear();
int validID(char[]);
void clearBuffer();
void inputStudents();
void displayStudents();
void searchStudent();
void rankStudents();

int main() {
    char password[10];
    int fail = 0;

    for (int i = 0; i < 20; i++) {
        printf("***********************\n");
    }

    // 登入驗證：輸入 4 位數密碼，最多三次
    while (fail < 3) {
        printf("請輸入4位數密碼（預設2025）：");
        scanf("%4s", password);
        clearBuffer();
        if (strcmp(password, "2025") == 0) break;
        else {
            fail++;
            printf("密碼錯誤，剩餘次數：%d\n", 3 - fail);
        }
    }

    if (fail == 3) {
        printf("密碼錯誤次數過多，系統結束。\n");
        return 0;
    }

    char choice;
    while (1) {
        clearScreen();
        printf("---------- [Grade System] ----------\n");
        printf("a. Enter student grades\n");
        printf("b. Display student grades\n");
        printf("c. Search for student grades\n");
        printf("d. Grade ranking\n");
        printf("e. Exit system\n");
        printf("------------------------------------\n");
        printf("請輸入選項：");
        scanf(" %c", &choice);
        clearBuffer();

        switch (choice) {
            case 'a': inputStudents(); break;
            case 'b': displayStudents(); break;
            case 'c': searchStudent(); break;
            case 'd': rankStudents(); break;
            case 'e': {
                char confirm;
                printf("確定離開?(y/n):");
                scanf(" %c", &confirm);
                clearBuffer();
               if (confirm == 'y' || confirm == 'Y')
				{
				return 0;
                break;
                }
                
                else if (confirm == 'N' || confirm == 'n')
                {
                	continue;
				}
				
	   			else 
				{
				    printf("確定離開?(y/n):");
                    scanf(" %c", &confirm);
                    clearBuffer();
                    if (confirm == 'y' || confirm == 'Y')
				    {
			 	    return 0;
                    break;
                    }
                
                    else if (confirm == 'N' || confirm == 'n')
                    {
                	    continue;
				    }      
                    else
                    {
  printf("無效選項，請重新輸入。\n"); break;
                    }
                         
                 }
            default: printf("無效選項，請重新輸入。\n"); break;
        }
    }
}
    
}
