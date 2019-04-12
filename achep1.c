#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct btree btree;
struct btree
{
  int item;
  btree *left;
  btree *right;
};

btree* create_empty()
{
return NULL;
}

btree* create_btree(int item, btree *left, btree *right)
{
	btree *new_bt = (btree*) malloc(sizeof(btree));
	new_bt->item = item;
	new_bt->left = left;
	new_bt->right = right;
	return new_bt;
}

// int left_index(int *a, int i)
// {
// 	return a[2*i];
// }

// int right_index(int *a, int i)
// {
// 	 return a[2*i + 1];
// }

btree* add_to_tree(btree *bt, int *a, int h,int size, int i)
{
	if(i > size) return bt;
	bt = create_btree(a[i], NULL, NULL);
	if((2*i) <= size) bt->left = add_to_tree(bt->left, a, h, size, 2*i);
	if((2*i+1) <= size)bt->right = add_to_tree(bt->right,a,h,size, 2*i + 1);
	return bt;
}

void result(btree *bt, int prod, int *maior)
{
	if(bt!= NULL)
	{
		prod*=bt->item;
		if(prod > (*maior)) *maior = prod;
		result(bt->left, prod, maior);
		result(bt->right, prod, maior);
	}
	//if(prod > (*maior)) *maior = prod;

}

void print_pre(btree *bt)
{
	if(bt != NULL)
	{
		printf("%d ", bt->item);
		print_pre(bt->left);
		print_pre(bt->right);
	}
}


void main()
{
    printf("insert h:\n");
	btree *tree = create_empty();
	int h; scanf("%d", &h);

	int num,i,size=1;
	int maior = 0;
	int all[65536];
	printf("insert numbers:\n");
	while(scanf("%d",&num))
	{
        if(num == -1) break;
		all[size] = num;
		size++;
	}
	size--;

	//tree = create_btree(all[1], NULL, NULL);

	if(h == 1) maior = all[1];//printf("%d", all[1]);
	else
	{
		tree = add_to_tree(tree,all,h,size,1);
	}
	//print_pre(tree);
	result(tree, 1 ,&maior);
	printf("MAIOR = %d", maior);
















}
