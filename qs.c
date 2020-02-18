///// ADAPTAR CODIGO PARA MAIS NUMEROS!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(long int *array1, long int *array2)
{
    long int aux;
    aux = *array1;
    *array1 = *array2;
    *array2 = aux;
}
void qs(long int *ar, long int start, long int end)
{
    if((end-start) <= 1)
    {
        return ;
    }
    else
    {
        long int a=start;
        long int b= end-1;
        long int pivot = ar[(b+a)/2];

        while(a<=b)
        {
            while(ar[a]< pivot && a< end)
                a++;
            while(ar[b]> pivot && b> start)
                b--;

            if(a<=b)
            {
                swap(&ar[a], &ar[b]);
                a++;
                b--;
            }
        }

        qs(ar,start, b+1);
        qs(ar, a, end);
    }
}


int main()
{
    long int a[20];/// limitado a 5 numeros :/
    long int i;
    srand(time(NULL));
    for(i=0;i<20;i++)
    {
        a[i] = rand()%100;
    }

    qs(a, 0, 20);

    for(i=0;i<20;i++)
    {
        printf("%ld \n", *(a+i));
    }
    return 0;

}
