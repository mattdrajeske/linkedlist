/////////////////////////////////////////////////
//Matt Drajeske								                 //
//CS 1575 A                                    //
//Assignment 3                                 //
//20 October 2019                              //
/////////////////////////////////////////////////

#include <string>
#include <iostream>
using namespace std;

//Default constructor
template<typename T>
LinkedList<T>::LinkedList(){
	m_back = new LLNode<T>();
	m_head = m_back;
  m_size = 0; //number of elements in list
}

/*
	BIG THREE
*/
//Destructor
template<typename T>
LinkedList<T>::~LinkedList(){
	LLNode<T>* current = m_head;
	while(current != NULL){
		LLNode<T>* next = current->m_next;
		delete current;
		current = next;
	}
}

//operator=
template<typename T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs){
	
}

//Copy Constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs){

}

/*
	ACCESSOR FUNCTIONS
*/
//size
template<typename T>
int LinkedList<T>::size() const{
  /*int size = 0;
  LLNode<T>* test = m_head;
  while(test != m_back){
    size++;
    test = test->m_next;
  }*/
	return m_size;
}

//if empty
template<typename T>
bool LinkedList<T>::isEmpty() const{
  if(m_size == 0){
    return true;
  }
  return false;
}

//first element
template<typename T>
LLNode<T>* LinkedList<T>::getFirstPtr(){

	return m_head;
}

//constant version
template<typename T>
const LLNode<T>* LinkedList<T>::getFirstPtr() const{
	return m_head;
}

//last element
template<typename T>
LLNode<T>* LinkedList<T>::getLastPtr(){
	if(m_size == 0){
		return NULL;
	}
	return m_back;
}

//any element
template<typename T>
LLNode<T>* LinkedList<T>::getAtPtr(int i){
	
}

/*
	MUTATOR FUNCTIONS
*/
//clear linked list
template<typename T>
void LinkedList<T>::clear(){
	LLNode<T>* current = m_head; //start at first element
	LLNode<T>* next; //variable for the next element in the list
	while(current->m_next != NULL){
		next = current->m_next; //done to iterate through the list
		delete current; //delete current element
		current = next; //set current element to the next one
	}
	m_size = 0; //set size to 0
	m_head = m_back;
	m_back = NULL;
}

//insert element at the front of the list
template<class T>
void LinkedList<T>::insert_front(const T& x){
	LLNode<T>* newnode = new LLNode<T>(x, m_head);
	m_head = newnode;
	m_size++;
}

//insert element at the back of the list)
template<typename T>
void LinkedList<T>::insert_back(const T& x){
	//create new node with NULL as m_next
	//set m_back as the newly created node
	//LLNode<T>* newnext = new LLNode<T>();
	LLNode<T>* newnode = new LLNode<T>(x, NULL);
	m_back->m_next = newnode;
	m_back = newnode;
	m_size++;
}

//insert element at specified node
template<typename T>
void LinkedList<T>::insert(const T& x, LLNode<T>* pos){

}

//remove element from front of list
template<typename T>
void LinkedList<T>::remove_front(){

}

//remove element from back of list
template<typename T>
void LinkedList<T>::remove_back(){

}

//remove specified node
template<typename T>
void LinkedList<T>::remove(LLNode<T>* pos){
	
}

/*
	COMPLEX OPERATIONS
*/
//operator==
template<typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const{

}

//determine whether parameter x is in list
template<typename T>
LLNode<T>* LinkedList<T>::find(const T& x){

}

//reverse list
template<typename T>
void LinkedList<T>::reverse(){

}

//adds one list to another
template<typename T>
void LinkedList<T>::append(const LinkedList<T>& xlist){

}

//removes a section of a list
template<typename T>
void LinkedList<T>::clip(LLNode<T>* start, LLNode<T>* stop){

}

//makes a list into a copy of a portion of the elements of another list
template<typename T>
void LinkedList<T>::slice(const LinkedList<T>& xlist, LLNode<T>* start, LLNode<T>* stop){

}

//Utility------------------------------------------------------------------
//Print Linked List
template <class T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list){
	out << "[";
	const LLNode<T>* current = list.getFirstPtr();
	while(current-> m_next != NULL){
		out << current->m_data << ", ";
		current = current->m_next;
	}
	out << "]";
	return out;
}