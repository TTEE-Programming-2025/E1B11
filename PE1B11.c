#include <stdio.h>
#include<stdlib.h>

int main()
{
    int i, input;
    char ch;

    /*�@ʾ�����L����*/  
    for (i = 0; i < 20; i++) {
        printf("*********************\n", i + 1);
   }

    /*�ȴ�ʹ���߰��I�^�m*/
    printf("��Enter�I�������K�M���ܴa��C...\n");
    getchar();  /*�ȴ�ʹ����ݔ��*/
    system("CLS"); /*���ΞĻ*/
    
    /*ݔ���ܴa*/
    printf("Ոݔ��4λ���ܴa:");
    scanf("%d",&input);

    if (input == 2024)
     {
        printf("�ܴa���_!�gӭ�M��ϵ�y��\n");
        system("CLS"); /*���ΞĻ*/
     } 
     
     else 
     {
        printf("�ܴa�e�`!��ʽ�Y����\n");
        return 0;
     }

    /*�@ʾ�x��*/
    
    printf("---------------------------------\n");
    printf("A...Z : Uppercase       \n");
    printf("a...z : Lowercase       \n");
    printf("0...9 : Digit           \n");
    printf("Otherwise : Your name       \n");
    printf("---------------------------------\n");

    /*ݔ��һ����Ԫ�K�Д�*/
    getchar(); /*����ϴ�ݔ���Enter*/ 
    printf("Ոݔ��һ����Ԫ");
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
        printf("E1B11���\n");
        }

    /*�ȴ����I��Y��*/
    printf("��Enter�I�Y����ʽ...\n");
    getchar();  /*����ϴ�ݔ���Enter*/
    getchar();  /*�ȴ�ʹ���߰�Enter*/
    
    system("pause");
    return 0;
}

/*�ĵü�����:�@�Ǳ��W�ڵ�һ�����I�����Y���˺ܶ���Ԫ�ă��ݣ�
է��֮�����c���y�������H�������l�F�кܶ��|�������n�r������о����^�ˣ�
��˾Ϳ���형�������������GitHub���O�ñ����I�����韩����...*/
