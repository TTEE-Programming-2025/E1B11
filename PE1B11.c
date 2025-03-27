#include <stdio.h>
#include<stdlib.h>

int main()
{
    int i, input;
    char ch;

    /*顯示個人風格畫面*/  
    for (i = 0; i < 20; i++) {
        printf("*********************\n", i + 1);
   }

    /*等待使用者按鍵繼續*/
    printf("按Enter鍵清除畫面並進入密碼驗證...\n");
    getchar();  /*等待使用者輸入*/
    system("CLS"); /*清除螢幕*/
    
    /*輸入密碼*/
    printf("請輸入4位數密碼:");
    scanf("%d",&input);

    if (input == 2024)
     {
        printf("密碼正確!歡迎進入系統。\n");
        system("CLS"); /*清除螢幕*/
     } 
     
     else 
     {
        printf("密碼錯誤!程式結束。\n");
        return 0;
     }

    /*顯示選單*/
    
    printf("---------------------------------\n");
    printf("A...Z : Uppercase       \n");
    printf("a...z : Lowercase       \n");
    printf("0...9 : Digit           \n");
    printf("Otherwise : Your name       \n");
    printf("---------------------------------\n");

    /*輸入一個字元並判斷*/
    getchar(); /*清除上次輸入的Enter*/ 
    printf("請輸入一個字元");
    scanf("%c", &ch);  

    if (ch >= 'A' && ch <= 'Z')
     {
        printf("Uppercase\n");
     }
     
     else if (ch >= 'a' && ch <= 'z')
      {
        printf("Lowercase\n");
      } 
      
      else if (ch >= '0' && ch <= '9') 
      {
        printf("Digit\n");
      }
      
       else
        {
        printf("E1B11吳睿承\n");
        }

    /*等待按鍵後結束*/
    printf("按Enter鍵結束程式...\n");
    getchar();  /*清除上次輸入的Enter*/
    getchar();  /*等待使用者按Enter*/
    
    system("pause");
    return 0;
}

/*心得及感想:這是本學期第一個作業，因為結合了很多單元的內容，
乍看之下有點困難。但實際操作會發現有很多東西在上課時好像就有練習過了，
因此就可以順暢的做出來。倒是GitHub的設置比作業本身麻煩多了...*/
