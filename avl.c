#include<stdlib.h>
#include<stdio.h>
#include "avl.h"
#include <assert.h>

int max(int a, int b){
  return (a > b) ? a : b;
}

int abs(int a){
  return (a < 0) ? -a : a;
}

struct AVL* newNode(int data){
  struct AVL* node = malloc(sizeof(struct AVL));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  return node;
}

struct AVL* insertBST(struct AVL* node, int data){
  if(node){
    if(data <= node->data){
      node->left = insertBST(node->left, data);
      node->left->parent = node;
    } else {
      node->right = insertBST(node->right, data);
      node->right->parent = node;
    }
  }else
    return newNode(data);
  return node;
}

int height(struct AVL* node){
  if(!node) return -1;
  return 1 + max(height(node->left),
                 height(node->right));
}

int balanceFactor(struct AVL* node){
  if(node)
    return height(node->right) - height(node->left);
  return 0;
}

int isAVL(struct AVL* node){
  if(!node) return 1;
  /*if(((abs(balanceFactor(node)) <= 1) && isAVL(node->left) &&
      isAVL(node->right))*/
  return abs(balanceFactor(node))<=1 && isAVL(node->left) && isAVL(node->right);
}

struct AVL* leftRotation(struct AVL* node){
  assert(node == NULL);
  struct AVL* tmp;
  struct AVL* x = node;
  struct AVL* y = node->right;
  y->parent = x->parent;
  x->parent = y;
  x->right = y->left; //right analizar
  y->right = x;
  tmp = y->right;
  y->right = y->left;
  y->left = tmp;
  return y;
}

struct AVL* rightRotation(struct AVL* node){
  assert(node == NULL);
  //Declaramos variables
  struct AVL* y = node;
  struct AVL* x = node->left;
  struct AVL* parentY = y->parent;
  struct AVL* B = y->right;
  //Realizamos rotacion
  x->right = y;
  y->parent = x;

  y->left = B;
  B->parent = y;
  //Casos especiales
  if(parentY){
    if(parentY->left == y)
      parentY->left = x;
    else
      parentY->left = x;
  }

  x->parent = parentY;
  return x;
}
