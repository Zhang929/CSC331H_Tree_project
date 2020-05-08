//
//  BSTree.hpp
//  Tree_project
//
//  Created by J Q on 4/24/20.
//  Copyright © 2020 csc331. All rights reserved.
//

#ifndef BSTree_hpp
#define BSTree_hpp

#include <stdio.h>
#include <vector>
using namespace std;

template <class T>
struct node
{
   T info;
   node *left;
   node *right;
};

template <class T>
class BSTree
{
   private:
      node<T> *root;
      void printPreorder (node<T> *);
      void printPostorder (node<T> *);
      void printInorder (node<T> *, char);
      void destroyTree (node<T> * &);
      void copyTree (node<T> *&, node<T> *);
      int Unique = 0;
      int RealWord = 0;
      vector <T> Repeat_word;
      
   public:
      BSTree();
      ~BSTree();
      BSTree (const BSTree<T> &);
      void operator= (const BSTree<T> &);
      void insertItem (T);
      void deleteItem (T);
      void deleteItem (node<T> *&, T);
      void DeleteNode (node<T> *&);
      T  getPredecessor ( node<T> * );
      int  getUnique ();
      bool searchItem (T);
      void printPreorder();
      void printPostorder();
      void printInorder(char);
      bool isEmpty();
      bool checkLetter(T);
      void getRepeat(T);
      void printRepeat();
      int getRealWord();
      void printIndex(T,char);
};

#endif /* BSTree_hpp */
