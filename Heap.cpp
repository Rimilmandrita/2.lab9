#include<iostream>
using namespace std;


//maxheap class, using array


class MaxHeap
{
  public:
  int maxheap[100];
  int size;
  MaxHeap()
  { 
    size=0;
    }
//insert function inserts the element at the end,and then reheapifies it upwards
  void insert(int key)
  {
  int i=size++;
  maxheap[i]=key;
  while(i!=0)
  {
    int p=(i-1)/2;
    if(maxheap[p]>=key)
      break;
    else
    {
       int temp=maxheap[p];
       maxheap[p]=maxheap[i];
       maxheap[i]=teMaxHeap()
  { 
    size=0;
  }
mp;
    }
    i=p;
   }
  }

//1711106
//Rimilmandrita Ghosh

  //displays the array as it should be, since elements are arranged adhering to the properties of maximum heap
  void display()
  {
   cout<<"\nTHE MAX-HEAP ELEMENTS ARE:";
   for(int i=0;i<size;i++)
   {
     cout<<"\t"<<maxheap[i];
   }
  }
 //takes into consideration three cases, size=0, size=1, and size greater than 1
  void remove()   //remove maximum element (i.e., root element)
  {
  if(size==0)
  {
     cout<<"\nTHE HEAP IS EMPTY !!! \n \n";
  }
  else if(size==1)
  {
    size--;
  }
    
  //when size>1
  else
  {
    int i=0;
    maxheap[i]=maxheap[size-1];
    size--;
    
    //if the current node has a children
    while((2*i+1)+1<=size)
    {
       
      //if it has two children
      if((2*i+2)+1<=size)
      {
        int lc=maxheap[2*i+1];
        int rc=maxheap[2*i+2];
        int maxind=(lc>=rc)?(2*i+1):(2*i+2);
        if(maxheap[i]<maxheap[maxind])
        {
          int temp=maxheap[i];
          maxheap[i]=maxheap[maxind];
          maxheap[maxind]=temp;
          i=maxind;
        }
        
      }
      
      //if it has only one child
      else
      {
        if(maxheap[i]<maxheap[2*i+1])
        {
          int temp=maxheap[i];
          maxheap[i]=maxheap[2*i+1];
          maxheap[2*i+1]=temp;
          i=2*i+1;
        }
        else
          break;
      }
    }
  }
 }
};

int main()
{
  MaxHeap MH;
  cout<<"\n \nEnter the number of elements you want to enter: ";
  int n;
  cin>>n;
  cout<<"\nEnter the datas:\n";
  for(int x=0;x<n;x++)
  { 
    int num;
    cout<<"\nDATA"<<(x+1)<<": ";
    cin>>num;
    MH.insert(num);
  }
  MH.display();
  MH.remove();
  MH.display();
  return 0;
}
