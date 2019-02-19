#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct btree btree;
//////////////BINARY SEARCH TREE
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

////////////////////// start of print functions
void print_pre(btree* bt) /// pre order
{
  if(!empty(bt))
  {
    printf("%d", bt->item);
    print_in(bt->left);
    print_in(bt->right);
  }
}

void print_in(btree *bt) /// in order
{
  if(!empty(bt))
  {
    print_in(bt->left);
    printf("%d", bt->item);
    print_in(bt->right);
  }
}

void print_post(btree *bt) /// post order
{
  if(!empty(bt))
  {
    print_in(bt->left);
    print_in(bt->right);
    printf("%d", bt->item);
  }
}
/////////////////////// end of print functions

btree* add_term(btree *bt, int item)
{
  if(bt == NULL) bt = create_btree(item,NULL,NULL);
  else if(bt->item > item) bt->left = add(bt->left,item);
  else bt->right = add(bt->right, item);

  return bt;
}

btree* search_term(btree *bt, int item)
{
  if((bt == NULL) || (bt->item == item)) return bt;
  else if(bt->item > item) return search_term(bt->left, item);
  else return search_term(bt->right,item);
}

void remove_term(btree *bt,int item)
{
  ///COMPLETE LATER...
}

void main()
{

}
