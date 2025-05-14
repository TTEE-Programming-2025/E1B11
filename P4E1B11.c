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

// 清除螢幕
void clearScreen() {
    system("cls"); 
}

// 清除輸入緩衝區
void clearBuffer() {
    while (getchar() != '\n');
}

// 檢查學號是否為 6 位數字
int validID(char id[]) {
    if (strlen(id) != 6) return 0;
    for (int i = 0; i < 6; i++) {
        if (id[i] < '0' || id[i] > '9') return 0;
    }
    return 1;
}

// a. 輸入學生資料
void inputStudents() {
    clearScreen();
    printf("請輸入學生人數（5~10）：");
    scanf("%d", &n);
    clearBuffer();
    if (n < 5 || n > 10) {
        printf("人數不符規定。\n");
        waitAndClear();
        return;
    }

    for (int i = 0; i < n; i++) {
        printf("\n第 %d 位學生：\n", i + 1);

        printf("姓名：");
        scanf("%19s", students[i].name);
        clearBuffer();

        while (1) {
            printf("學號（6位數）：");
            scanf("%9s", students[i].id);
            clearBuffer();
            if (validID(students[i].id)) break;
            else printf("學號格式錯誤，請重新輸入。\n");
        }

        printf("數學成績：");
        scanf("%d", &students[i].math);
        printf("物理成績：");
        scanf("%d", &students[i].physics);
        printf("英文成績：");
        scanf("%d", &students[i].english);
        clearBuffer();

        if (students[i].math < 0 || students[i].math > 100 ||
            students[i].physics < 0 || students[i].physics > 100 ||
            students[i].english < 0 || students[i].english > 100) {
            printf("成績輸入錯誤，請重新輸入該生資料。\n");
            i--;
            continue;
        }

        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0f;
    }
    waitAndClear();
}

// b. 顯示學生資料
void displayStudents() {
    clearScreen();
    printf("\n%-10s %-10s %-6s %-6s %-6s %-6s\n", "姓名", "學號", "數學", "物理", "英文", "平均");
    for (int i = 0; i < n; i++) {
        printf("%-10s %-10s %-6d %-6d %-6d %-6.1f\n",
               students[i].name,
               students[i].id,
               students[i].math,
               students[i].physics,
               students[i].english,
               students[i].average);
    }
    waitAndClear();
}

// c. 搜尋特定學生
void searchStudent() {
    clearScreen();
    char search[20];
    int found = 0;

    printf("請輸入要搜尋的姓名：");
    scanf("%19s", search);
    clearBuffer();

    for (int i = 0; i < n; i++) {
        if (strcmp(search, students[i].name) == 0) {
            printf("學號：%s\n數學：%d\n物理：%d\n英文：%d\n平均：%.1f\n",
                   students[i].id,
                   students[i].math,
                   students[i].physics,
                   students[i].english,
                   students[i].average);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("找不到該學生。\n");
    }

    waitAndClear();
}

