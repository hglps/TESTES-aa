#include <stdio.h>
#include <stdlib.h>


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
int empty(btree *bt)
{
  return (bt == NULL);
}

btree* create_btree(int item, btree *left, btree *right)
{
  btree *new_btree = (btree*) malloc(sizeof(btree));
  new_btree->item = item;
  new_btree->left = left;
  new_btree->right = right;
  return new_btree;
}

btree* del(btree *bt, int num)
{
  if(bt == NULL) return bt;

  if(bt->item > item) bt->left = del(bt->left, num);
  else if(bt->item < item) bt->right = del(bt->right, num);
  else
  {
    if(bt->right == NULL)
    btree *aux = bt->left; free(bt);
    return aux;
  }
}

btree* add_term(btree *bt, int item, int i, int *save) //// binary search tree ////
{
  if(bt == NULL) bt = create_btree(item,NULL,NULL);
  else if(bt->item > item) bt->left = add(bt->left, item, i+1, save);
  else bt->right = add(bt->right, item, i+1, save);

  return bt;
}

int search_term(btree *bt, int item, int i, int *save)//// binary search tree////
{
 if(bt == NULL) return 0;
 else if(bt->item == item) return 1;
 else if(bt->item > item) search_term(bt->left, item, i+1, save);
 else search_term(bt->right, item, i+1, save);
}

int search_level(btree *bt,int item, int i, int *save)
{
  if(bt == NULL) return 0;
  else if(bt->item == item) {*save+=i; return *save; }
  else if(bt->item > item) search_term(bt->left, item, i+1, save);
  else search_term(bt->right, item, i+1, save);
}

void main()
{
  btree *tree =create_empty();
  long int t,n,op,i=0,num,save=0;
  long int a[100000];
  printf("inicio\n");
  scanf("%d", &t);
  while(t--)
  {
    scanf("%d", &n);
    while(n--)
    {
      scanf("%d %d", &op, &num);
      if(op == 1) // add num
      {
        if(search(tree,num,0, &save)){ printf("%d\n", search_level(tree,num,0,&save)); save = 0;}
        else
        {
          a[i] = num; i++;
          tree = add_term(tree, num,0,&save);
          printf("%d\n", save); save = 0;
        }
      }
      else if(op == 2) // del num
      {
        if(search(tree,num,0,&save))
        {
          printf("%d\n", save); save=0;
          tree = del(tree,num);
        }
      }
      else if( op == 3) //maiores que num
      {

      }
      else if(op == 4) // kth num in order
      {

      }




    }
  }

  tree = create_btree(5,NULL,NULL);
  tree->left = create_btree(2,NULL,NULL);
  tree->right = create_btree(6,NULL,NULL);
    print_pre(tree);
  printf("resposta da busca de 5 = %d\n",search_term(tree,5,0,&save)); save=0;
     printf("resposta da busca de 2= %d\n",search_term(tree,2,0,&save)); save=0;
      printf("resposta da busca de 6 = %d",search_term(tree,6,0,&save));










}
