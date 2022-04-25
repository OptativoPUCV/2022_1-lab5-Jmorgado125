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
  TreeNode * nodo;
  nodo=createTreeNode(key,value);

  if(tree->root == NULL){
    tree->root=nodo;
    tree->current=tree->root;
    return;
  }
  tree->current=tree->root;
  while(tree->current != NULL){
    if(tree->lower_than(key,tree->current)==1){
      if(tree->current->left == NULL){
          tree->current->left=nodo;
          tree->current=nodo;
          break;
       }
       tree->current=tree->current->left;
      }

      else if(tree->lower_than(tree->current,key)==1){
        if(tree->current->right == NULL){
          tree->current->right=nodo;
          tree->current=nodo;
          break;
        }
        tree->current=tree->current->right;
      }
  }      
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
  /*TreeNode* ubNode = tree->root;
  TreeNode* aux = tree->root;
  while(ubNode != NULL){
    if(tree->lower_than(key,ubNode->pair->key)==1){
      aux=ubNode;
      ubNode=ubNode->left;
      continue;
    }
    else if (tree->lower_than(ubNode->pair->key,key)==1)
    {
      aux=ubNode;
      ubNode=ubNode->right;
      if(tree->lower_than(ubNode->pair->key,ubNode->pair->key)==1)
      {
        aux=ubNode;
        continue;
      }
      else continue;
    }
    else
    {
      return ubNode->pair;
    }
  }

  ubNode = aux;
  return ubNode->pair;*/
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
      if(tree->lower_than(tree->current->parent, tree->current)==1){
        tree->current=tree->current->parent;
      }
      else
        return tree->current->parent->pair;
    }
  }
  return tree->current->pair;
}
