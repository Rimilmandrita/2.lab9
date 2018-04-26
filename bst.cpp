#include<iostream>
using namespace std;

class node{
     public:
     node *parent;
     node *left;
     node *right;
     int data;
    node(){
     parent=left=right=NULL;
     data=0;
    }
};

class BStree{
     public:
     node *root;
     int noofnodes,leaves;
     int rngsrc;

    BStree()
    {
    root=NULL;
    }


 void insert(int x){
   if(searchNode(x)==NULL)
   {node *temp=new node;
   temp->data=x;
   temp->parent=temp->left=temp->right=NULL;

   if(root==NULL)
   { root=temp;
   }
   else{ node *curr;
         curr=root;
        while(1){
            if(x<curr->data){

               if(curr->left==NULL){
                  temp->parent=curr;
                  curr->left=temp;
               break;
               }
              else{curr=curr->left;}
            }
           else {
                    if(curr->right==NULL)
                       {
                       temp->parent=curr;
                       curr->right=temp;
                     break;}
                   else{curr=curr->right;}
                  }

        }
     }}
  else
  cout<<"\nElement exists";
 }
//Rimilmandrita Ghosh, 1711106
 void display(node *temp){

      if(temp==NULL)
         return;
      display(temp->left);
      cout<<"\t"<<temp->data;
      display(temp->right);
}

node* searchNode(int dt)
{
 node * check = root;
 if(check == NULL)
     return NULL;
 else
  while(true)
  {
   if(check->data == dt)
   {
     cout << "\nNode found.\n";
     return check;
   }
   else if(check->data > dt)
   {
    if(check->left == NULL)
      {

       return NULL;
      }
    else
       check = check->left;
   }
   else
   {
    if(check->right == NULL)
    {

      return NULL;
    }
    else
      check = check->right;
   }

  }

}


void deleteNode(int s)
{

  if(searchNode(s)==NULL)
  {cout<<"Node not found \n";
  }
  else
{

    node*curr=searchNode(s);

    // if this is leaf node
    if(curr->left==NULL && curr->right==NULL)
    { if(curr==root)
        {root=NULL;
        cout<<"Tree deleted \n";}
      if(curr->parent->left==curr)
        curr->parent->left=NULL;
      else
         curr->parent->right=NULL;
     cout<<"Node deleted \n";
    }
    //if it has one single child
    else if(curr->left==NULL || curr->right==NULL)
    {if(curr==root)
      {if(curr->left==NULL)
        {root=curr->right;
         curr->right->parent=NULL;
        }
       else
        {root=curr->left;
         curr->left->parent==NULL;
        }
        cout<<"Node deleted \n";
      }
     if(curr->left==NULL)
      { curr->right->parent=curr->parent;
        if(curr->parent->left==curr)
          curr->parent->left=curr->right;
        else
          curr->parent->right=curr->right;
      }
      else
      { curr->left->parent=curr->parent;
        if(curr->parent->left==curr)
           curr->parent->left=curr->left;
        else
           curr->parent->right=curr->left;
      }
      cout<<"Node deleted \n";
    }
   //if it has two children
   else
   {node* temp=curr->right;
    while(temp->left!=NULL)
     {temp=temp->left;}
     //temp has the element we want to replace
     int cons;
     cons=temp->data;
     deleteNode(cons);
     curr->data=cons;

 }}  }



void counting (node* temp)
{ if(temp==NULL)
         return;
       counting(temp->left);
      noofnodes++;
      if(temp->left==NULL && temp->right==NULL)
      {leaves++;}
      counting(temp->right);}



 void rangeSearch(node* temp,int k1,int k2)
 {  if(temp==NULL)
         return;
      rangeSearch(temp->left,k1,k2);
      if(temp->data>=k1 && temp->data<=k2)
      {cout<<"\t"<<temp->data;
       rngsrc++;
      }
      rangeSearch(temp->right,k1,k2);
 }


//Rimilmandrita Ghosh


 };

 int main(){
 BStree b;
b.insert(1);
b.insert(2);
b.insert(3);
b.display(b.root);
b.rangeSearch(b.root,1,2);
int ch,x;


return 0;
}
