#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int pass;
    int count = 0;

    // 畫個人風格畫面
    for (int i = 0; i < 20; i++) 
    {
        printf("***********\n");
    }

    // 密碼驗證
    while (count < 3)
    {
        printf("請輸入四位密碼：");
        scanf("%d", &pass);

        if (pass == 2025)
        {   
		    printf("密碼正確");
		    system("CLS");
            break;
        }
        else 
        {
            count++;
            if (count == 3)
            {
                printf("密碼錯誤三次，程式結束！\n");
                return 0;
            }
            else
            {
                printf("密碼錯誤，請再試一次！\n");
            }
        }
    }
    
    
     // 主選單
    char choice;
    while (1) 
    {  
        printf("密碼=2025 正確");
        printf("\n==== 主選單 ====\n");
        printf("a. 倒直角字母三角形\n");
        printf("b. 顯示乘法表\n");
        printf("c. 結束\n");
        printf("請選擇功能 (a/b/c)：");
        scanf(" %c", &choice);

    }

    return 0;
}

