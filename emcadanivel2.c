#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct btree btree;
struct btree
{
  int item;
  int id;
  int depth;
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

btree* create_btree(int item, int id, btree *left, btree *right)
{
  btree *new_btree = (btree*) malloc(sizeof(btree));
  new_btree->item = item;
  new_btree->id = id;
  new_btree->left = left;
  new_btree->right = right;
  return new_btree;
}

btree* add_to_tree(btree *bt, int *number, int *index_left, int *index_right, int i)
{
  if(i != -1)
  {
    bt = create_btree(number[i], i, NULL,NULL);
    bt->left = add_to_tree(bt->left,number,index_left,index_right,index_left[i]);
    bt->right = add_to_tree(bt->right,number,index_left,index_right,index_right[i]);
  }
  else
  {
    return NULL;
  }
  return bt;
}

int depth(btree *bt,int it,int dept)
{
  if(bt == NULL) return 0;

  if(bt->item == it)
  {
    bt->depth = dept; //// fix this
    return dept;
  }

  int next_depth = depth(bt->left,it,dept+1);
  if(next_depth != 0) return next_depth;

  next_depth = depth(bt->right,it,dept+1);
  return next_depth;
}

void print_pre(btree *bt)
{
  if(!empty(bt))
  {
    printf("ITEM= %d   DEPTH= %d\n", bt->item, bt->depth);
    print_pre(bt->left);
    print_pre(bt->right);
  }
}

void main()
{
  int i,n;
  int num[501], ind_left[501],ind_right[501];
  btree *tree = create_empty();
  scanf("%d", &n);
  for(i=0;i<n;i++)
  {
    scanf("%d %d %d", &num[i],&ind_left[i],&ind_right[i]);

  }
  tree = add_to_tree(tree,num, ind_left, ind_right,0);

  print_pre(tree);


}
