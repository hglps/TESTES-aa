#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct btree btree;
/////AVL TREE
struct btree
{
  int item;
  int h;
  btree *left;
  btree *right;
};

btree* create_btree(int item, btree *left, btree *right)
{
  btree *new_btree = (btree*) malloc(sizeof(btree));
  new_btree->item = item;
  new_btree->left = left;
  new_btree->right = right;
  return new_btree;
}

int is_balanced(btree *bt)
{
  int bt = height(bt->left) - h(bt->right);
  return ((-1 <= bt) && (bt <= 1));
}

int max(int l,int r)
{
  return (l > r) ? l : r;
}

int height(btree *bt)
{
  if(bt == NULL) return -1;
  else return (1 + max(h(bt->left),h(bt->right)));
}

int bfactor(btree *bt)
{
  if(bt == NULL)
    return 0;
  else if(bt->left != NULL && bt->right != NULL)
    return (bt->left->h - bt->right->h);
  else if(bt->left != NULL && bt->right == NULL)
    return (1 + bt->left->h);
  else
    return (-bt->right->h - 1);
}
btree* add_to_bt(btree *bt, int item)
{
  if(bt == NULL)
    return create_btree(item,NULL,NULL);
  else if(bt->item > item)
    bt->left = add_to_bt(bt->left,item);
  else
    bt->right = add_to_bt(bt->right,item);

  bt->h = height(bt);
  btree *child;

  if(bfactor(bt) == 2 || bfactor(bt) == -2)
  {
    if(bfactor(bt) == 2)
    {
      child = bt->left;
      if(bfactor(child) == -1)
        bt->left = rotate_left(child);
      bt = rotate_right(child);
    }
    else if(bfactor(bt) == -2)
    {
      child = bt->right;
      if(bfactor(child) == 1)
        bt->right = rotate_right(child);
      bt= rotate_left(bt);
    }
  }
  return bt;
}
btree* rotate_left(btree *bt)
{
  btree *subtree_root = NULL;

  if(bt != NULL && bt->right != NULL)
  {
    subtree_root = bt->right;
    bt->right = subtree_root->left;
    subtree_root->left = bt;
  }

  subtree_root->h = height(subtree_root);
  bt->h = height(bt);
  return subtree_root;
}

btree* rotate_right(btree *bt)
{
  btree *subtree_root = NULL;

  if(bt != NULL && bt->left != NULL)
  {
    subtree_root = bt->left;
    bt->left = subtree_root->right;
    subtree_root->right = bt;
  }

  subtree_root->h = height(subtree_root);
  bt->h = height(bt);
  return subtree_root;
}
