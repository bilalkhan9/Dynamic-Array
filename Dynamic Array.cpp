#include<iostream>
using namespace std;

class DynamicArray
{
  int *Array;
  int size;
  int count;
  public :
  		 DynamicArray()
		   {
		     Array = new int[10];
			 size  = 0;
			 count = 10;			   
           } 	  
           ~DynamicArray()
           {
		     delete []Array;
			 size = 0;
			 count = 0;				  
	       }
	       
	       void insert(int a)
		   {
		     if(size == count)
			 		resize();
			 		Array[size]=a;
			 		size++;
		   }
		   
		   void resize()
		   {
		     int *temp = new int[2*size];
			 
			 for(int i=0; i<size; i++)
			 {
			   temp[i]=Array[i];
			    		 
	         }
			 count = 2*size;
			 delete []Array;
			 Array = temp;
			 		
		   }
		   int get(int index)
		   {
		     	   if(index >= size)
		     	   cout<<"Index Not Present"<<endl;
		     	   return Array[index];
		   }
		   
		   void print()
		   {
		     for(int i=0; i<size; i++) // Added type specifier for 'i'
			 {
			   cout<<Array[i]<<" ";	  
		      }
			  cout<<endl;		
		   }
		   
		   void insertat(int index , int value)
		   {
		     		if(size==count)
		     		resize();
		     		
   		      for(int i=size; i>index; i--) // Changed loop condition to 'size - 1'
   		      {
     	   		Array[i]=Array[i-1];	 
              }
              Array[index]=value;
              size++;
		   }
};

int main()
{
  DynamicArray a;
  a.insert(10);
  a.insert(20);
  a.insert(30);
  a.insert(40);
  a.insert(50);
  a.insertat(2,100);
  a.print(); 	
  
  system("pause");
  return 0;
}
