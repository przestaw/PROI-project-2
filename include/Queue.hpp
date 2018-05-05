/*
 * Queue.hpp
 *
 * Class Queue - a template linked list queue to contain any type of data:
 * - Able to:
 *  > attach, detach an element
 *  > return data containted by a specific node
 *  > check if an element is containted in the queue
 * - Contains its own custom iterator
 * ^ DECLARATION AND DEFINITION
 *
 * PROI, Lab project 2: "Theater"
 * Tutor: dr inż. Wiktor Kuśmirek
 *
 * Version: 06.04.2018, Kamil Zacharczuk
 * PROI, Lab project 3: 'Theater'
 * Tutor: dr inz. Wiktor Kusmirek
 * Przemysław Stawczyk
 */
#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <iostream>
#include <cassert>


/*TEMPLATE CLASS QUEUE - DECLARATION*/
template <typename T>
class Queue
{
  private:
		/*struct type Node - the node of the list*/
		typedef struct s_Node
    {
		    T* pointed;
		    struct s_Node* next;
    } Node;

    /*Fields*/
		//The first and the last node of the list
		Node* head;
		Node* tail;

    /*the iterator for the queue*/
    class CustomIterator
    {
      public:
	      Node* itr;
        /*Cons&des*/
        CustomIterator() : itr(nullptr) {}
        CustomIterator(Node* temp_node) : itr(temp_node) {}
        ~CustomIterator() {}

        /*Operators*/
        CustomIterator& operator++ ()
        { //pre-incr
            assert (itr!=nullptr);
            itr = itr->next;
            return *this;
        }

        CustomIterator operator++ (int){ //post-incr
          assert (itr!=nullptr);
          CustomIterator temp_iterator(*this);
          itr = itr->next;
          return temp_iterator;
        }

        T& operator* () const
        { //data
	         assert (itr!=nullptr);
	          return *itr->pointed;
        }
    };//CustomIterator
		/*Methods*/
		Node* getPrecedingNode (T &);
    //returns temp_node: temp_node->next->pointed = *element passed as an argument*
	public:
		/*Cons&des*/
		Queue();
    ~Queue();

		/*Operators*/
		Node* operator+ (T&); //attach an element
		bool operator- (T&); //detach an element

		/*Methods*/
		T* getElement (int); //get data the n-th node points at
		bool findElement (T&); //check if the element is containted in the queue
};

          /*      DEFINITIONS      */
template <typename T>
Queue<T>::Queue()
{
  this->head = nullptr;
  this->tail = nullptr;
}

template <typename T>
Queue<T>::~Queue()
{
  if (this->head!=nullptr)
  {
    Node* del_node;
    CustomIterator iter(this->head);

    for (; iter.itr->next!=nullptr ;)
    { //free any memory the queue has still been using
      del_node = iter.itr;
      iter++;
      delete del_node;
    }
  }
}

/*-Private-*/
template <typename T>
typename Queue<T>::Node* Queue<T>::getPrecedingNode(T & el)
{
	//WARNING: this function will not check if the head is the node you are looking for
  //You must check if the head is initialized (not will nullptr) BEFORE calling this function (memory leak otherwise)
  //NOTE : function used only in one place, [safely]

  CustomIterator iter(this->head); //Create the iterator to iterate through the list
	for (; iter.itr->next!=nullptr; iter++)
  {
      if (iter.itr->next->pointed == &el)
      {//WARNING: type T must have the operator == defined
		    return iter.itr;
      } //return the node preceding the matching one
	}
	return nullptr;
}

/*-Public-*/
template <typename T>
typename Queue<T>::Node* Queue<T>::operator+ (T & el) //attach new element
{

	Node* temp_node = new Node; //the element hasn't been in the queue so far
	temp_node->pointed = &el;
	temp_node->next = nullptr;

	if (this->head==nullptr)
  { //in case of the queue being empty
		this->head = temp_node;
	}
	else
  {
		this->tail->next = temp_node;
	}

	this->tail = temp_node;

	return this->tail;
}

template <typename T>
bool Queue<T>::operator- (T & el) //detach an element
{
	if (this->head==nullptr)
  {
		return false;
	}

	Node* del_node;
	////
	if (this->head->pointed == &el)
  { //if the head points at the element we want to detach
		//WARNING: type T has to have operator == defined
		del_node = this->head;

		if (this->head->next == nullptr)
    {
			this->head = nullptr;
			this->tail = nullptr;
		}
		else
    {
			this->head = this->head->next;
		}
	}
	else //if it's not the head that we are detaching
	{
		Node* preced_node = getPrecedingNode(el);

		if (preced_node==nullptr)
    { //no matching element in the list
			return false;
		}

		del_node = preced_node->next;

		if (del_node->next == nullptr)
    { //if we are deleting the tail
      preced_node->next = nullptr;
			this->tail = preced_node;
		}
		else
    {
      preced_node->next = del_node->next;
		}
	}
  delete del_node;
  return true;
}

template <typename T>
T* Queue<T>::getElement (int n)
{ //take the data the n-th node points at
	int i = 0;

	CustomIterator iter(this->head);
	for (; iter.itr!=nullptr; iter++)
  {
		if (i==n)
    {
			break;
		}
		i++;
	}
  if (iter.itr==nullptr)
  {
		return nullptr;
	}else
  {
    return &(*iter); //operator * is here used as overloaded for the class CustomIterator
  }
}

template <typename T>
bool Queue<T>::findElement (T & el) //NOTE: missleading name - left as-is
{ //check if the element is containted in the queue
	CustomIterator iter(this->head);
	for (; iter.itr!=nullptr; iter++)
  {
		if (&(*iter) == &el){
			return true;
		}
	}
	return false; //reached the end of the queue and didn't find the elemnet
}

#endif //_QUEUE_HPP_
