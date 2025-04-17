#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
    printf("輸入的密碼=2025 密碼正確 \n");
    char choice;
    while (1) 
    
    {
        printf("\n==== 主選單 ====\n");
        printf("a. 倒直角字母三角形\n");
        printf("b. 顯示乘法表\n");
        printf("c. 結束\n");
        printf("請選擇功能 (a/b/c)：");
        scanf(" %c", &choice);

        // 功能 a：直角字母三角形
        if (choice == 'a'||choice == 'A') 
        
        {
            char end;
            printf("請輸入一個字母(a-n)：");
            scanf(" %c",&end);

            if (end < 'a' || end > 'n') 
            
            {
                printf("輸入錯誤，請重新輸入。\n");
                continue;
            }

            char row = end;
            while (row >= 'a') 
            
            {
                char space = 'a';
                while (space < row) 
                
                {
                    printf(" ");
                    space++;
                }

                char ch = row;
                while (ch <= end) 
                
                {
                    printf("%c", ch);
                    ch++;
                }

                printf("\n");
                row--;
                
                
        
            }
            
            printf("按下任何按鍵以回到主選單");
            getch();
            system("CLS");
            
        }


        // 功能 b：乘法表
        else if (choice == 'b'||choice == 'B') 
        
        {
            int n;
            printf("請輸入1到9之間的整數：");
            scanf("%d", &n);

            if (n < 1 || n > 9) 
            
            {
                printf("輸入錯誤，請重新輸入。\n");
                continue;
            }

            int i = 1;
            while (i <= n) 
            
            {
                int j = 1;
                while (j <= n) 
                
                {
                    printf("%d*%d=%2d ", i, j, i * j);
                    j++;
                }
                
                printf("\n");
                i++;
                
            }
            
            printf("按下任何按鍵以回到主選單");
            getch();
            system("CLS"); 
            
        }
           
            
            // 功能 c：結束
        else if (choice == 'c'||choice == 'C')
        
        {
            char yn;
            printf("Continue? (y/n)：");
            scanf(" %c", &yn);

            if (yn == 'y' || yn == 'Y') 
            
            {
                continue;
            } 
            
            else if (yn == 'n' || yn == 'N') 
            
            {
                printf("結束程式，謝謝使用！\n");
                break;
            } 
            
            else 
            
            {
                printf("輸入錯誤，請重新輸入。\n");
            }
            
        }

        else 
        
        {
            printf("無效的選項，請重新輸入 按下任意鍵以繼續\n");
            getch();
            system("CLS"); 
            
        }
    
        
  /*心得:這次的作業比起上次稍顯困難,因為我對雙重迴圈還是有不夠了解的地方,
  所以花了一些時間在了解他的邏輯,搞懂邏輯後,就發現其實並不難懂,之後寫作業時也通暢很多。*/ 

    } 
    return 0;
}

