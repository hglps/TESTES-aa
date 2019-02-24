///INCOMPLETE 1
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int count=0,flag=0;
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

int solve_pre(btree* bt)
{
  if(!empty(bt))
  {
    if((bt->left->item < bt->item) && (bt->left != NULL))
    {
      solve_pre(bt->left);
    }
    else
    {
      if(flag) return 0;
      else if(!flag && bt->left->item > bt->item)
      {
        printf("FALSO\n");
        flag = 1;
        return 0;
      }
      
    }
    if((bt->right->item > bt->item) && (bt->right != NULL))
    {
      solve_pre(bt->right);
    }
    else
    {
      if(flag) return 0;
      else if(!flag && bt->right->item < bt->item)
      {
        printf("FALSO\n");
        flag = 1;
        return 0;
      }
      
    }
  }
  return 0;
}

void print_pre(btree *bt)
{
    if(!empty(bt))
    {
        printf("%d ", bt->item);
        print_pre(bt->left);
        print_pre(bt->right);
    }
}

void main()
{
  btree *tree = create_empty();
  int n,i;
  char num[500];
  scanf("%[^\n]s", num);
  //puts(num);
  getchar();

  tree = form_btree(num);
  if(solve_pre(tree))
  {
    printf("VERDADEIRO\n");
  }

  free(tree);

}

/// INCOMPLETE 2
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int count=0;
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

int solve_pre(btree* bt)
{
  if(empty(bt)) return 1;
  else if(bt->left->item < bt->item && bt->right->item > bt->item)
  {
    if(solve_pre(bt->left) && solve_pre(bt->right))
    {
      return 1;
    }
    else return 0;
  }
  else return 0;
}

void print_pre(btree *bt)
{
    if(!empty(bt))
    {
        printf("%d ", bt->item);
        print_pre(bt->left);
        print_pre(bt->right);
    }
}

void main()
{
  btree *tree = create_empty();
  int n,i;
  char num[500];
  scanf("%[^\n]s", num);
  //puts(num);
  getchar();

  tree = form_btree(num);
  if(solve_pre(tree))
  {
    printf("VERDADEIRO\n");
  }
  else printf("FALSO\n");

  free(tree);

}

