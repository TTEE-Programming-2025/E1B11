#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int pass;
    int count = 0;

    // �������L����
    for (int i = 0; i < 20; i++) 
    {
        printf("***********\n");
    }

    // �ܴa��C
    while (count < 3)
    {
        printf("Ոݔ����λ�ܴa��");
        scanf("%d", &pass);

        if (pass == 2025)
        {   
		    printf("�ܴa���_");
		    system("CLS");
            break;
        }
        else 
        {
            count++;
            if (count == 3)
            {
                printf("�ܴa�e�`���Σ���ʽ�Y����\n");
                return 0;
            }
            else
            {
                printf("�ܴa�e�`��Ո��ԇһ�Σ�\n");
            }
        }
    }
    
    
     // ���x��
    char choice;
    while (1) 
    {  
        printf("�ܴa=2025 ���_");
        printf("\n==== ���x�� ====\n");
        printf("a. ��ֱ����ĸ������\n");
        printf("b. �@ʾ�˷���\n");
        printf("c. �Y��\n");
        printf("Ո�x���� (a/b/c)��");
        scanf(" %c", &choice);

    }

    return 0;
}

