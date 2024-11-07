#include<stdlib.h>
#include<stdio.h>
#include "avl.h"

int max(int a, int b){
  return (a > b) ? a : b;
}

struct AVL* newNode(int data){
  struct node* node = malloc(sizeof(node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  return node;
}


struct AVL* insert(struct node, int data){
  if(node){
    if(data <= node->data){
      node->left = insert(node->left, data);
      node->left->parent = node;
    } else {
      node->right = insert(node->right, data);
      node->right->parent = node;
    }
  }else
    return newNode(data);
  return node;
}

