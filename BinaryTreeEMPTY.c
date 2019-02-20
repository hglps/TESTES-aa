#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int count = 0;

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

btree* create_btree(int it,btree *left,btree *right)
{
  btree* new_btree = (btree*)malloc(sizeof(btree));
  new_btree->item = it;
  new_btree->left = left;
  new_btree->right = right;
  return new_btree;
}

btree* form_btree(char *text) /// read between parenthesis
{
  btree *bt = create_empty();
  int integer, i=0;
  char extractText[100];

  while(text[count] == '(')
  { count+=1; }
  if(text[count] == ')')
  {
    count++;
    return NULL;
  }
  else
  {
    while(text[count] != '(')
    {
      extractText[i++] = text[count];
      count+=1;
    }
    extractText[i] = '\0';
    integer = atoi(extractText);
    bt = create_btree(integer,NULL,NULL);
    bt->left = form_btree(text);
    bt->right = form_btree(text);
  }
  count+=1;
  return bt;
}

////////////////////// start of print functions
void print_pre(btree* bt)
{
  if(!empty(bt))
  {
    printf("%d ", bt->item);
    print_pre(bt->left);
    print_pre(bt->right);
  }
}
void print_in(btree *bt)
{
  if(!empty(bt))
  {
    print_in(bt->left);
    printf("%d ", bt->item);
    print_in(bt->right);
  }
}
void print_post(btree *bt)
{
  if(!empty(bt))
  {
    print_post(bt->left);
    print_post(bt->right);
    printf("%d ", bt->item);
  }
}
/////////////////////// end of print functions

int search_(btree *bt,int it)
{
  if(bt->item == it) return 1;
  else if(bt->left != NULL) search_(bt->left,it);
  else if(bt->right!=NULL) search_(bt->right,it);
  return -1;
  //search_(bt->left,it);
  //search_(bt->right,it);
  //printf("%d\n", bt->item);
}

void main()
{
  btree *tree = create_empty();
  int n,i;
  char num[500];
  scanf("%[^\n]s", num);
  puts(num);
  getchar();

  tree = form_btree(num);

  print_pre(tree);
  printf("\n");
  printf("%d", search_(tree,4));

  free(tree);

}
