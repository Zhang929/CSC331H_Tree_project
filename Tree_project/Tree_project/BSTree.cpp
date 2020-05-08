//
//  BSTree.cpp
//  Tree_project
//
//  Created by J Q on 4/24/20.
//  Copyright © 2020 csc331. All rights reserved.
//

#include "BSTree.hpp"
#include <iostream>


template <class T>
BSTree<T> :: BSTree ()
{
   root = NULL;

  
}

template <class T>
BSTree<T> :: ~BSTree ()
{
   destroyTree (root);
  
}

template <class T>
void BSTree<T> :: destroyTree (node<T> * &p )
{
   if ( p != NULL )
   {
       destroyTree (p->left);
       destroyTree (p->right);
       delete p;
       p = NULL;

   }
    

}

template <class T>
BSTree<T> :: BSTree (const BSTree<T> & other)
{
   if ( other.root == NULL )
       root = NULL;

   else copyTree (root, other.root);
  
}

template <class T>
void BSTree<T> :: operator= (const BSTree<T> & other)
{
   if ( this != &other )
   {
      destroyTree (root);
      copyTree (root, other.root);
   }
}

template <class T>
void BSTree<T> :: copyTree (node<T> *& nroot, node<T> *croot  )
{
    if ( croot == NULL )
        nroot = NULL;
    else
    {
       nroot = new node<T>;
       nroot->info = croot->info;
       copyTree (nroot->left, croot->left);
       copyTree (nroot->right, croot->right);
    }
    

}

template <class T>
void BSTree<T> :: printPreorder ()
{
   printPreorder (root);
  
}

template <class T>
void BSTree<T> :: printPreorder (node<T> *p )
{
   if ( p != NULL )
   {
      cout<<"  "<< p->info;
      printPreorder (p->left);
      printPreorder (p->right);
   }

}

template <class T>
void BSTree<T> :: printPostorder ()
{
   printPostorder (root);
  
}

template <class T>
void BSTree<T> :: printPostorder (node<T> *p )
{
   if ( p != NULL )
   {
      
      printPostorder (p->left);
      printPostorder (p->right);
      cout<<"  "<< p->info;
   }

}

template <class T>
void BSTree<T> :: printInorder (char index)
{
   printInorder (root, index);
  
}

template <class T>
void BSTree<T> :: printInorder (node<T> *p, char index)
{
   if ( p != NULL )
   {
      
      printInorder (p->left, index);
      printIndex(p->info, index); //&***************@#$%^&*
      printInorder (p->right, index);
      
   }
}

template <class T>
void BSTree<T> :: insertItem (T item )
{
   node<T> *temp = new node<T>;
   temp->info = item;
   temp->left = NULL;
   temp->right = NULL;

   if ( root == NULL )
      root = temp;
   else
       {
           node<T> *p = root;
           node<T> *s = nullptr;

           while ( p != NULL )
           {
               s = p;
               if ( p->info == item )
               {
//                   cout<<"ITEM ALREADY THERE";
                   if(checkLetter(item))
                       getRepeat(item);
                   return;
               }
               else if ( p->info > item )
               {
                   p = p->left;
               }
               else
               {
                   p = p->right;
               }

           }
           Unique ++;
           if(checkLetter(item))
               RealWord ++;
           if ( s->info > item )
               s->left = temp;
           else
               s->right = temp;
        }
}

template <class T>
bool BSTree<T> :: searchItem (T item )
{
   if ( root == NULL )
      return false;
   else
   {
      node<T> *p = root;
      bool found = false;

      while ( p != NULL && !found )
      {
         if ( p->info == item )
            found = true;
         else if ( p->info < item )
            p = p->right;
         else
            p = p->left;

      }

     return found;

   }

}

template <class T>
void BSTree<T> :: deleteItem (T item )
{
   deleteItem (root, item);
}

template <class T>
void BSTree<T> :: deleteItem (node<T> *& p, T item)
{
   if ( p == NULL )
      cout<<"ITEM NOT THERE OR TREE EMPTY";
   else if ( item < p->info )
      deleteItem (p->left, item);
   else if ( item > p->info )
      deleteItem (p->right, item);
   else
      DeleteNode (p);
  
}

template <class T>
void BSTree<T> :: DeleteNode (node<T> *&p)
{
   node<T> *q = p;

   if ( p->left == NULL )
   {
     p = p->right;
     delete q;
   }
   else if ( p->right == NULL )
   {
     p = p->left;
     delete q;
   }
   else
   {
      T data = getPredecessor (p->left);
      p->info = data;
      deleteItem (p->left, data);
   }
}

template <class T>
T  BSTree<T> :: getPredecessor ( node<T> *p )
{
     while ( p->right != NULL )
        p = p->right;
     return p->info;
}
    

template <class T>
bool BSTree<T> :: isEmpty ()
{
    return root == NULL;
}

template <class T>
int  BSTree<T> :: getUnique ()
{
    return Unique;
}

template <class T>
void BSTree<T> :: getRepeat(T item)
{
    Repeat_word.push_back(item);
}

template <class T>
void BSTree<T> :: printRepeat()
{
    int index = 1;
    int times = 1;
    cout << "WORDS USED TOO OFTEN: \n";
    for(int i=0; i<Repeat_word.size(); i++)
    {
        for(int j=i+1;j<Repeat_word.size(); j++)
        {
            if(Repeat_word[i] == Repeat_word[j])
            {
                times++;
            }
        }
        if(times > 2)
        {
            cout  << "\t" << index << ") " << Repeat_word[i] << endl;
            index ++;
            times = 1;
        }
    }
}

template <class T>
bool BSTree<T> :: checkLetter(T item)
{
    string str = item;
    int i = 0;
    while(i < str.length())
    {
        i++;
    }
    if(i>3)
    {
        return true;
    }
    else
        return false;
}

template <class T>
int  BSTree<T> :: getRealWord()
{
    return RealWord;
}

template <class T>
void BSTree<T> :: printIndex(T item, char index)
{
    string str = item;
    if(str[0] == index || str[0] == index+32)
    {
        cout << "  " << item << endl;
    }
}


