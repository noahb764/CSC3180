#ifndef H_UnorderedLinkedList
#define H_UnorderedLinkedList
#include <iostream>
using namespace std;

//***********************************************************
// Author: D.S. Malik
//
// This class specifies the members to implement the basic
// properties of an unordered linked list. This class is
// derived from the class linkedListType. 
//***********************************************************

#include "linkedList.h"

using namespace std;

template <class Type>
class unorderedLinkedList: public linkedListType<Type>
{
public:
    bool search(const Type& searchItem) const;
      //Function to determine whether searchItem is in the list.
      //Postcondition: Returns true if searchItem is in the list,
      //    otherwise the value false is returned.

    void insertFirst(const Type& newItem);
      //Function to insert newItem at the beginning of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the beginning of the list, last points to
      //    the last node, and count is incremented by 1.
      //               

    void insertLast(const Type& newItem);
      //Function to insert newItem at the end of the list.
      //Postcondition: first points to the new list, newItem is
      //    inserted at the end of the list, last points to the
      //    last node, and count is incremented by 1.

    void deleteNode(const Type& deleteItem);
      //Function to delete deleteItem from the list.
      //Postcondition: If found, the node containing deleteItem
      //    is deleted from the list. first points to the first 
      //    node, last points to the last node of the updated 
      //    list, and count is decremented by 1.

    void linkedSelectionSort();

    void divideList(nodeType<Type>* first1, nodeType<Type>* &first2);
	
    nodeType<Type>* mergeList(nodeType<Type>* first1, nodeType<Type>* first2);

    void recMergeSort(nodeType<Type>* &head);

    void mergeSort();


 protected:
	nodeType<Type> *first;
	nodeType<Type> *last;
	int count = 0;
	
private:
	void selectionSortLinked(nodeType<Type>* &head);
	void minLocation(nodeType<Type>* &trailSmall,
					 nodeType<Type>* &small);
};

template<class Type>
void unorderedLinkedList<Type>::divideList(nodeType<Type>* first1, nodeType<Type>* &first2)
{
  nodeType<Type>* middle;
  nodeType<Type>* current;

  if(first == NULL) // List is empty
    {
      first2 = NULL;
    }
  else if(first1->link == NULL) // List has only one node
    {
      first2 = NULL;
    }
  else
    {
      middle = first1;
      current = first1->link;

      if(current != NULL) // List has more than two nodes
	{
	  current = current->link;
	}

      while(current != NULL)
	{
	  middle = middle->link;
	  current = current->link;

	  if(current != NULL)
	    {
	      current = current->link;
	    }
	}// end while

      first2 = middle->link; // First2 points to the first node of the second sublist

      middle->link = NULL; // Set the link of the last node of the first sublist to NULL

    }// end else
}// end divideList

template<class Type>
nodeType<Type>* unorderedLinkedList<Type>::mergeList(nodeType<Type>* first1, nodeType<Type>* first2)
{
  nodeType<Type> *lastSmall; // Pointer to the last node of the merged list
  nodeType<Type> *newHead; // Pointer to the merged list

  if(first1 == NULL) // The first sublist is empty
    {
      return first2;
    }
  else if(first2 == NULL) // The second sublist is empty
    {
      return first1;
    }
  else
    {
      if(first1->info < first2->info) // Compare the first nodes
	{
	  newHead = first1;
	  first1 = first1->link;
	  lastSmall = newHead;
	}
      else
	{
	  newHead = first2;
	  first2 = first2->link;
	  lastSmall = newHead;
	}

      while(first1 != NULL && first2 != NULL)
	{
	  if(first1->info < first2->info)
	    {
	      lastSmall->link = first1;
	      lastSmall = lastSmall->link;
	      first1 = first1->link;
	    }
	  else
	    {
	      lastSmall->link = first2;
	      lastSmall = lastSmall->link;
	      first2 = first2->link;
	    }
	}// end while

      if(first1 == NULL) // First sublist is exhausted first
	{
	  lastSmall->link = first2;
	}
      else // Second sublist is exhausted first
	{
	  lastSmall->link = first1;
	}
    }// end else

  return newHead;

}// end mergeList

template<class Type>
void unorderedLinkedList<Type>::recMergeSort(nodeType<Type>* &head)
{
  nodeType<Type> *otherHead;

  if(head != NULL) // If the list is not empty
    {
      if(head->link != NULL) // If the list has more than one node
	{
	  divideList(head, otherHead);
	  recMergeSort(head);
	  recMergeSort(otherHead);
	  head = mergeList(head, otherHead);
	}
    }
}// end recMergeSort

template<class Type>
void unorderedLinkedList<Type>::mergeSort()
{
  recMergeSort(first);

  if(first == NULL)
    {
      last = NULL;
    }
  else
    {
      last = first;

      while(last->link != NULL)
	{
	  last = last->link;
	}
    }
}// end mergeSort

template<class elemType>
void unorderedLinkedList<elemType>::linkedSelectionSort()
{
	selectionSortLinked(first);
}

template<class elemType>
void unorderedLinkedList<elemType>::selectionSortLinked(nodeType<elemType>* &head)
{
	nodeType<elemType> *lastInOrder;
	nodeType<elemType> *small;
	nodeType<elemType> *trailSmall;

	if (head == NULL)
		cout << "Cannot sort an empty list" << endl;
	else
	{
		small = head;
		
		minLocation(trailSmall,small);

		if (small != head)
		{
			trailSmall->link = small->link;
			small->link = head;
			head = small;
		}
	 
		lastInOrder = head;

		while (lastInOrder->link != NULL)
		{
			small = lastInOrder->link;

			minLocation(trailSmall,small);

			if (small != lastInOrder->link)
			{
				trailSmall->link = small->link;
				small->link = lastInOrder->link;
				lastInOrder->link = small;
			}

			lastInOrder = lastInOrder->link;
		}
	}
}

template<class elemType>
void unorderedLinkedList<elemType>::minLocation
		                (nodeType<elemType>* &trailSmall,
		                 nodeType<elemType>* &small)
{
	nodeType<elemType> *trailCurrent;
	nodeType<elemType> *current;

	current = small->link;
	trailCurrent = small;

	while (current != NULL)
	{
		if (small->info > current->info)
		{
			trailSmall = trailCurrent;
			small = current;
		}

		trailCurrent = current;
		current = current->link;
	}
}


template <class Type>
bool unorderedLinkedList<Type>::
                   search(const Type& searchItem) const
{
    nodeType<Type> *current; //pointer to traverse the list
    bool found = false;
    
    current = first; //set current to point to the first 
                     //node in the list

    while (current != NULL && !found)    //search the list
        if (current->info == searchItem) //searchItem is found
            found = true;
        else
            current = current->link; //make current point to
                                     //the next node
    return found; 
}//end search

template <class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

    if (last == NULL)   //if the list was empty, newNode is also 
                        //the last node in the list
        last = newNode;
}//end insertFirst

template <class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;  //store the new item in the node
    newNode->link = NULL;     //set the link field of newNode
                              //to NULL

    if (first == NULL)  //if the list is empty, newNode is 
                        //both the first and last node
    {
        first = newNode;
        last = newNode;
        count++;        //increment count
    }
    else    //the list is not empty, insert newNode after last
    {
        last->link = newNode; //insert newNode after last
        last = newNode; //make last point to the actual 
                        //last node in the list
        count++;        //increment count
    }
}//end insertLast


template <class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem)
{
    nodeType<Type> *current; //pointer to traverse the list
    nodeType<Type> *trailCurrent; //pointer just before current
    bool found;

    if (first == NULL)    //Case 1; the list is empty. 
        cout << "Cannot delete from an empty list."
             << endl;
    else
    {
        if (first->info == deleteItem) //Case 2 
        {
            current = first;
            first = first->link;
            count--;
            if (first == NULL)    //the list has only one node
                last = NULL;
            delete current;
        }
        else //search the list for the node with the given info
        {
            found = false;
            trailCurrent = first;  //set trailCurrent to point
                                   //to the first node
            current = first->link; //set current to point to 
                                   //the second node

            while (current != NULL && !found)
            {
                if (current->info != deleteItem) 
                {
                    trailCurrent = current;
                    current = current-> link;
                }
                else
                    found = true;
            }//end while

            if (found) //Case 3; if found, delete the node
            {
                trailCurrent->link = current->link;
                count--;

                if (last == current)   //node to be deleted 
                                       //was the last node
                    last = trailCurrent; //update the value 
                                         //of last
                delete current;  //delete the node from the list
            }
            else
                cout << "The item to be deleted is not in "
                     << "the list." << endl;
        }//end else
    }//end else
}//end deleteNode




#endif
