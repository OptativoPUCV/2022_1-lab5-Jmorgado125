#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treemap.h"

typedef struct TreeNode TreeNode;


struct TreeNode {
    Pair* pair;
    TreeNode * left;
    TreeNode * right;
    TreeNode * parent;
};

struct TreeMap {
    TreeNode * root;
    TreeNode * current;
    int (*lower_than) (void* key1, void* key2);
};

int is_equal(TreeMap* tree, void* key1, void* key2){
    if(tree->lower_than(key1,key2)==0 &&  
        tree->lower_than(key2,key1)==0) return 1;
    else return 0;
}


TreeNode * createTreeNode(void* key, void * value) {
    TreeNode * new = (TreeNode *)malloc(sizeof(TreeNode));
    if (new == NULL) return NULL;
    new->pair = (Pair *)malloc(sizeof(Pair));
    new->pair->key = key;
    new->pair->value = value;
    new->parent = new->left = new->right = NULL;
    return new;
}

TreeMap * createTreeMap(int (*lower_than) (void* key1, void* key2)) {
  TreeMap * aux=(TreeMap *)malloc(sizeof(TreeMap));
  aux->root=NULL;
  aux->current=NULL;
  aux->lower_than=lower_than;
  
  return aux;
}


void insertTreeMap(TreeMap * tree, void* key, void * value) {
  /*TreeNode * nodo;
  if(tree == NULL){return;}
  if(tree->root == NULL){
    tree->root->pair->key=key;
    tree->root->pair->value=value;
    tree->current=tree->root;
  }
  nodo=tree->root;
  else
    {
      while(nodo != NULL){

      }
    }*/
}

TreeNode * minimum(TreeNode * x){
  if(x->left==NULL){
    return x;
  }
  else{
    while(x->left !=NULL){
      x=x->left;
    }
    return x;
  }
}


void removeNode(TreeMap * tree, TreeNode* node) {
  if(tree == NULL && tree->root == NULL){return;}
  if(tree->root==node){}

}

void eraseTreeMap(TreeMap * tree, void* key){
    if (tree == NULL || tree->root == NULL) return;

    if (searchTreeMap(tree, key) == NULL) return;
    TreeNode* node = tree->current;
    removeNode(tree, node);

}




Pair * searchTreeMap(TreeMap * tree, void* key) {
  tree->current=tree->root;
  if(tree->current->pair->key < key){}
  else 
  {}
  return tree->current->pair;
}


Pair * upperBound(TreeMap * tree, void* key) {
    return NULL;
}

Pair * firstTreeMap(TreeMap * tree) {
    if(tree->root==NULL){return NULL;}
    tree->current=tree->root;
    if(tree->current->left==NULL){
        return tree->current->pair;
    }
    else 
        while(tree->current->left != NULL){
            tree->current=tree->current->left;
        }
    return tree->current->pair;
}

Pair * nextTreeMap(TreeMap * tree) {
  if(tree->current->right !=NULL){
    tree->current=minimum(tree->current->right);
  }
  else{
    while (tree->current->parent != NULL)
    {
      if(tree->lower_than(tree->current, tree->current->parent)==1){
        tree->current=tree->current->parent;
        break;
      }
      else
        tree->current=tree->current->parent;
        if(tree->current==tree->root){return NULL;}
    }
  }
  
  return tree->current->pair;
}
