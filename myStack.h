//Header file: myStack.h
#ifndef H_StackType
#define H_StackType
#include<iostream>
#include<cassert>
#include"stackADT.h"
using namespace std;

//Place the definition of the class template stackType, as given
//previously in this chapter, here.

template <class Type>
class stackType: public stackADT<Type>
{
 public:
  const stackType<Type> &operator=(const stackType<Type>&);
  //Overload the assignment operator.

  void initializeStack();
  //Function to initialize the stack to an empty state.

  bool isEmptyStack() const;
  //Function to determine whether the stack is empty.

  bool isFullStack() const;
  //Function to determine whether the stack is full.

  void push(const Type &newItem);
  //Function to add newItem to the stack.

  Type top()const;
  //Function to return the top element of the stack.

  void pop();
  //Function to remove the top element of the stack.


  stackType(int stackSize=100);
  //Constructor

  ~stackType();
  //Destructor

 private:
  int maxStackSize; //variable tos tore the maximum stack size
  int stackTop; //variable to point to the top of the stack
  Type *list; //pointer to the array that holds the stack elements
  void copyStack(const stackType<Type>&otherStack);
};

//Place the definitions of the member functions as discussed here.
template <class Type>
const stackType<Type>& stackType<Type>::operator= (const stackType<Type>& otherStack)
{
  if(this != &otherStack)  //avoid self-copy
    {
    copyStack(otherStack);
    }
  return *this;
    } //endoperator=

 template <class Type>
 void stackType<Type>::initializeStack()
{
  stackTop=0;
} //endinitializeStack

template <class Type>
bool stackType<Type>::isEmptyStack() const
{
  return (stackTop == 0);
} //endisEmptyStack


template <class Type>
bool stackType<Type>::isFullStack() const
{
  return (stackTop == maxStackSize);
} //endisFullStack

template <class Type>
void stackType<Type>::push(const Type& newItem)
{
  if( !isFullStack())
    {
      list[stackTop] = newItem;//addnewItematthetop
      stackTop++; //incrementstackTop
    }
  else
    {
      cout<< "Cannot add to a full stack." << endl;
    }
}//endpush

template <class Type>
Type stackType<Type>::top() const
  {
    assert(stackTop != 0); //if stack is empty, terminate the
                           //program
    return list[stackTop-1]; //return the element of the stack
                            //indicated by stackTop - 1
  } //endtop

template <class Type>
void stackType<Type>::pop()
 {
   if(!isEmptyStack())
     {
     stackTop--; //decrement stackTop
     }
   else
     {
       cout << "Cannot remove froman empty stack." << endl;
     }
 } //endpop

 template <class Type>
 void stackType<Type>::copyStack(const stackType<Type>& otherStack)
 {
   delete [] list;
   maxStackSize = otherStack.maxStackSize;
   stackTop = otherStack.stackTop;
   list= new Type[maxStackSize];

   //copy other Stack into this stack
   for (int j = 0; j < stackTop; j++)
     {
     list[j] = otherStack.list[j];
     } //endcopyStack
 }

template <class Type>
stackType<Type>::stackType(int stackSize)
{
   if (stackSize <= 0)
     {
       cout<< "Size of the array to hold the stack must"
	   << "be positive." <<endl;
       cout<< "Creating an array of size 100." <<endl;
       maxStackSize=100;
     }
   else
     {
     maxStackSize = stackSize;  //set the stack size to
                               //the value specified by
                               //the parameter stackSize
     }
   stackTop = 0; //set stackTop to 0
   list = new Type[maxStackSize]; //createcthecarraycto
				   //holdcthecstackcelements
 }//endconstructor
 
 template <class Type>
 stackType<Type>::~stackType() //destructor
 {
   delete [] list; //deallocate the memory occupied
                 //by the array
 } //end destructor
#endif


