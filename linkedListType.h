#ifndef LINKED_LIST_TYPE_H
#define LINKED_LIST_TYPE_H
#include <iostream>
#include <cassert>
#include "linkedListIterator.h"
using namespace std;

template <class Type>
class linkedListType
{
 public:

  const linkedListType<Type>& operator=(const linkedListType<Type>&);
  // Overload the assignment operator
  

  void initializeList();
  // Initialize the list to an empty state.
  // Postcondition: first = NULL, last = NULL, count = 0.

  bool isEmptyList() const;
  // Function to determine whether the list is empty.
  // Postcondition: Returns true if the list is empty;
  //     otherwise, returns false.

  void print() const;
  // Function to output the data contained in each node.
  // Postcondition: None.

  int length() const;
  // Function to return the number of nodes in the list.
  // Postcondition: None.

  void destroyList() const;
  // Function to delete all the nodes from the list.
  // Postcondition: first = NULL, last = NULL, count = 0.

  Type front() const;
  // Function to return the first element of the list.
  // Precondition: The list must exist and must not be empty.
  // Postcondition: If the list is empty, the program terminates;
  //     otherwise, the first element of the list is returned.

  Type back() const;
  // Function to return the last element of the list.
  // Precondition: The list must exist and must not be empty.
  // Postcondition: If the list is empty, the program terminates;
  //     otherwise, the last element of the list is returned.

  virtual bool search(const Type& searchItem) const = 0;
  // Function to determine whether searchItem is in the list.
  // Postcondtion: Returns true if searchItem is in the list,
  //     otherwise the value false is returned.

  virtual void insertFirst(const Type& newItem) = 0;
  // Function to insert newItem at the beginning of the list.
  // Postcondition: First points to the new list, newItem is
  //     inserted at the beginning of the list, last points to
  //     the last node in the list, and count is incremented by
  //     one.


  virtual void insertLast(const Type& newItem) = 0;
  // Function to insert newItem at the end of the list.
  // Postcondition: First points to the new list, newItem
  //     is inserted at the end of the list, last points
  //     to the last node in the list, and count is
  //     incremented by one.

  virtual void deleteNode(const Type& deleteItem) = 0;
  // Function to delete deleteItem from the list.
  // Postcondition: If found, the node containing
  //     deleteItem is deleted from the list.
  //     First points to the first node, last
  //     points to the last node of the updated
  //     list, and count is decremented by one.

  linkedListIterator<Type> begin();
  // Function to return an iterator at the beginning
  // of the linked list.
  // Postcondition: Returns an iterator such that
  //     current is set to first.

  linkedListIterator<Type> end();
  // Function to return an iterator one element past the
  // last element of the linked list.
  // Postcondition: Returns an iterator such that current
  //     is set to NULL.

  linkedListType();
  // Default constructor
  // Initializes the list to an empty state.
  // Postcondition: first = NULL, last = NULL, count = 0.

  linkedListType(const linkedListType<Type>& otherList);
  // Copy constructor

  ~linkedListType();
  // Destructor
  // Deletes all the nodes from the list.
  // Postcondition: The list object is destroyed.

 protected:
  int count; // Variable to store the number of list elements

  nodeType<Type> *first; // Pointer to the first node of the list
  nodeType<Type> *last; // Pointer to the last node of the list

 private:
  void copyList(const linkedListType<Type>& otherList);
  // Function to make a copy of otherList.
  // Postcondition: A copy of otherList is created and assigned
  //     to this list.

};

template <class Type>
const linkedListType<Type>& linkedListType<Type>::operator=(const linkedListType<Type>& otherList)
{
  if(this != &otherList) // Avoid self copy
    {
      copyList(otherList);
    } // End if

  return *this;
  
} // End operator=

template <class Type>
void linkedListType<Type>::initializeList()
{
  destroyList(); // If the list has any nodes, delete them.

} // End initializeList

template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
  return (first == NULL);

} // End isEmptyList

template <class Type>
void linkedListType<Type>::print() const
{
  nodeType<Type> *current; // Pointer to traverse the list.

  current = first; // Set current point to the first node.

  while(current != NULL) // While more data to print
    {
      cout << current->info << " ";
      current = current->link;
    }
} // End print

template <class Type>
int linkedListType<Type>::length() const
{
  return count;
  
} // End length

template <class Type>
void linkedListType<Type>::destroyList() const
{
  nodeType<Type> *temp; // Pointer to deallocate the memory occupied
                        // by the node while there are nodes in the list.

  while(first != NULL)
    {
      temp = first; // Set temp to the current node.
      first = first->link; // Advance first to the next node.
      delete temp; // Deallocate the memory occupied by temp.
    }
  last = NULL; // Initialize last to NULL; first has already been
               // set to NULL by the while loop.
  
  count = 0;

} // End destroyList

template <class Type>
Type linkedListType<Type>::front() const
{
  assert(first != NULL);

  return first->info; // Return the info of the first node

} // End front

template <class Type>
Type linkedListType<Type>::back() const
{
  assert(last != NULL);

  return last->info; // Return the info of the last node
  
} // End last

template <class Type>
linkedListIterator<Type> linkedListType<Type>::begin()
{
  linkedListIterator<Type> temp(first);

  return temp;
  
} // End begin

template <class Type>
linkedListIterator<Type> linkedListType<Type>::end()
{
  linkedListIterator<Type> temp(NULL);

  return temp;
  
} // End end

template <class Type>
linkedListType<Type>::linkedListType()
{
  first = NULL;
  last = NULL;
  count = 0;

} // End constructor
  
template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList)
{
  first = NULL;
  copyList(otherList);
  
} // End copy constructor

template <class Type>
linkedListType<Type>::~linkedListType()
{
  destroyList();
  
} // End destructor

template <class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList)
{
  nodeType<Type> *newNode; // Pointer to create a node
  nodeType<Type> *current; // List to be copied

  if(first != NULL) // If list is nonempty, make it empty
    {
      destroyList();
    }
  if(otherList.first == NULL) // otherList is empty
    {
      first = NULL;
      last = NULL;
      count = 0;
    }
  else
    {
      current = otherList.first; // Current points to the list to be occupied
      count = otherList.count;

      // Copy first node
      first = new nodeType<Type>; // Create the node

      first->info = current->info; // Copy the info

      first->link = NULL; // Set the link field of the node to NULL

      last = first; // Make last point to the first node

      current = current->link; // Make current point to the next node


      // Copy the remaining list
      while(current != NULL)
	{
	  newNode = new nodeType<Type>; // Create the node

	  newNode->info = current->info; // Copy the info

	  newNode->link = NULL; // Set the link of newNode to NULL

	  last->link = newNode; // Attach newNode after last

	  last = newNode; // Make last point to the actual last node

	  current = current->link;
	} // End while

    } // End else
  
} // End copyList
#endif
