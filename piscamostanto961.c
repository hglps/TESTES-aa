// PISCAMOS TANTO ASSIM - 461 - THE HUXLEY

#include <stdio.h>
#include <stdlib.h>

struct dia 
{
	int m;
	int minutos[1140];
	int maior;
};
void trocandinho(struct dia *a, struct dia *b){
	struct dia aux;
	aux = *a;
	*a = *b;
	*b = aux;

}
void deletar_dias(struct dia *a,int qnt_max, int d){
	int j;
	struct dia aux;
	for (j = d; j < qnt_max; ++j)
	{
		trocandinho(&a[j], &a[j+1]);
	}
	return;

}
int maiordodia(struct dia *b,int d)
{
	int maior = 0;
	int i;
	
	for(i=0;i<b[d].m;i++)
	{
		if(b[d].minutos[i]>maior)
		{
			maior=b[d].minutos[i];
		}
		
	}
	return maior;
}
void setar(struct dia *a, int i){
    int j;
	a[i].m = 0;
	a[i].maior = 0;
 	for(j = 0; j < 3; j++)
	{
	a[i].minutos[j] = 0;
 	}
}

int maior_min(struct dia *a, int i,int minuto){
	int higher = 0;
	int j;
	for(j = 0; j < i; j++)
	{
		if(a[j].minutos[minuto] > higher)
		{
			higher = a[j].minutos[minuto];
		}
	}
	return higher;
}
// i --> Contador para o ?ndice da struct
// cont --> quantidade de dias
// t --> instru?ao
// indel --> Contador do Indice dos deletados

int main()
{
	int t = 1, i = 0, cont = 0;
	int k;
	int indel;
	struct dia *a = (struct dia *) malloc(sizeof(struct dia));
    int deletados[1140];
	while(t!=0)
	{
		scanf("%d\n", &t);
		//printf("T: %d :T\n", t);
		switch(t)
		{
			case 1:
			{
				setar(a,i);
				//adicionar;
				int j;
				cont++;
				scanf("%d", &a[i].m);
				for(j = 0; j<a[i].m; j++)
				{
					scanf("%d", &a[i].minutos[j]);
				}
				printf("%d\n",cont);
				i++;
				a = (struct dia *) realloc(a, (i+1)*sizeof(struct dia));


				break;
			}
		    case 2:
			{
				//deletar;
				int d;
				int minutosremovidos;
				scanf("%d",&d);
				deletar_dias(a,i,d);
				printf("%d\n",a[i].m);
				i--;
				//deletados[indel] = d;
				cont--;
			    break;	
			}
			case 3:
			{
				//maior do dia;
				int d;
				scanf("%d",&d); 
				int mais;
				mais = maiordodia(a,d);
				printf("%d\n",mais);
			    break;
			}
			case 4:
			{
				//maior do minuto;
				int d;
				int minuto;
				scanf("%d",&minuto);
				printf("%d\n", maior_min(a,i,minuto));
				break;
			}
			
		}
	}
    free(a);
	
	return 0;
}
