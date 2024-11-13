#include <stdio.h>
#include "avl.h"
int main(int argc, char* argv[]){
  struct AVL* root = 0;
  root = insertBST(root,5);
  root = insertBST(root,3);
  root = insertBST(root,9);
  root = insertBST(root,1);
  root = insertBST(root,4);
  root = insertBST(root,6);
  printf("%d\n",isAVL(root));
}

