#include <stdio.h>
#include "avl.h"
int main(int argc, char* argv[]){
  struct AVL* root = 0;
  root = insert(root,5);
  root = insert(root,3);
  root = insert(root,9);
  root = insert(root,1);
  root = insert(root,4);
  root = insert(root,6);
  printf("%d\n",isAVL(root));
}

