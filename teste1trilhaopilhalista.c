#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    char word[50];

    while(scanf("%s", word) != EOF)
    {
        getchar();
        if(!strcmp(word,"PUSH"))
        {
            char trash;
            int num;
            while(1)
            {
                printf("É PUSH\nNumeros:\n");
                scanf("%d%c", &num, &trash);
                printf("%d ", num);
                if(trash == '\n') { break; }
            }
            printf("\n");
        }
        else
        {
            printf("É POP\n");
        }
    }
}
