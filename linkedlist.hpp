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
	m_head = NULL;
	m_back = m_head;
	m_size = 0;
}

/*
	BIG THREE
*/
//Destructor
template<typename T>
LinkedList<T>::~LinkedList(){
	if(!isEmpty()){
		LLNode<T>* current = m_head;
		while(current->m_next != NULL){
			LLNode<T>* next = current->m_next;
			delete current;
			current = next;
		}
		m_head = NULL;
		m_back = m_head;
		m_size = 0;
	}
}

//operator=
template<typename T>
const LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs){
	
}

//Copy Constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs){
/*	//LinkedList<T> r = new LinkedList<T>();
	
	//if rhs is empty
	if(rhs.isEmpty()){
		m_head = NULL;
		m_back = m_head;
		m_size = 0;
	}

	//if rhs is not empty
	//m_head = new LLNode<T>();
	LLNode<T>* current = m_head;

	//what does m_head need to be assigned to?
	for(int i = 0; i < rhs.size(); i++){
		current = new LLNode<T>(rhs.getAtPtr(i)->m_data, current->m_next);
		if(current->m_next != NULL){
			current = current->m_next;
		}
	}*/
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
  return m_head == NULL;
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
	LLNode<T>* current = m_head;
	while(current->m_next != NULL){
		current = current->m_next;
	}
	m_back = current;
	return m_back;
}

//any element
template<typename T>
LLNode<T>* LinkedList<T>::getAtPtr(int i){
	/*cout << "getAtPtr function needs to be fixed" << endl;
	return m_head;*/
	LLNode<T>* current = m_head;
	for(int k = 0; k < i-1; k++){
		current = current->m_next;
	}
	return current;
}

/*
	MUTATOR FUNCTIONS
*/
//clear linked list
template<typename T>
void LinkedList<T>::clear(){
	if(!isEmpty()){
		LLNode<T>* current = m_head;
		while(current->m_next != NULL){
			LLNode<T>* next = current->m_next;
			delete current;
			current = next;
		}
		m_head = NULL;
		m_back = m_head;
		m_size = 0;
	}
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
	if(isEmpty()){
		insert_front(x);
	}
	else{
		LLNode<T>* current = m_head;
		while(current->m_next != NULL){
			current = current->m_next;
		}
		current->m_next = new LLNode<T>(x, NULL);
		m_size++;
	}
	
}

//insert element at specified node
template<typename T>
void LinkedList<T>::insert(const T& x, LLNode<T>* pos){
	LLNode<T>* temp; //to point to the position where the new node is to be inserted
	LLNode<T>* current = m_head;
	bool flag = false;
	while(current->m_next != NULL){
		if(current == pos){	
			flag = true;
			LLNode<T>* newnode = new LLNode<T>(x, current->m_next);
			current->m_next = newnode;
			m_size++;
			break;
		}
		current = current->m_next;
	}
	if(!flag){
		cout << "! ERROR ! Position was not found!" << endl;
	}
}

//remove element from front of list
template<typename T>
void LinkedList<T>::remove_front(){
	LLNode<T>* temp = m_head->m_next;
	delete m_head;
	m_head = temp;
	m_size--;
}

//remove element from back of list
template<typename T>
void LinkedList<T>::remove_back(){
	//if list is empty
	if(isEmpty()){
		cout << "! ERROR ! list is empty" << endl;
	}

	//if list is size 1
	if(m_head->m_next == NULL){
		delete m_head;
		m_head = NULL;
	}

	LLNode<T>* temp;

	//to iterate through list
	LLNode<T>* current = m_head;
	while(current->m_next->m_next != NULL){
		current = current->m_next;
	}
	temp = current;
	delete current->m_next;
	current->m_next = NULL;
	m_back = temp;
	//cout << m_back->m_data << endl;
	m_size--;
}

//remove specified node
template<typename T>
void LinkedList<T>::remove(LLNode<T>* pos){
	LLNode<T>* temp; //to point to the position where the node is to be removed
	LLNode<T>* current = m_head;
	bool flag = false;
	while(current->m_next != NULL){
		if(current->m_next == pos){	
			flag = true;
			temp = current->m_next;
			current->m_next = current->m_next->m_next;
			delete temp;
			m_size--;
			break;
		}
		current = current->m_next;
	}
	if(!flag){
		cout << "! ERROR ! Position was not found!" << endl;
	}
}

/*
	COMPLEX OPERATIONS
*/
//operator==
template<typename T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const{
	if(m_size != rhs.m_size){
		return false;
	}
	LLNode<T>* current = m_head;
	const LLNode<T>* rhsCurrent = rhs.getFirstPtr();
	while(current->m_next != NULL ){
		if(current->m_data != rhsCurrent->m_data){
			return false;
		}
		current = current->m_next;
		rhsCurrent = rhsCurrent->m_next;
	}
	return true;
}

//determine whether parameter x is in list
template<typename T>
LLNode<T>* LinkedList<T>::find(const T& x){
	LLNode<T>* current = m_head;
	bool flag = false;

	//look through list for element with matching data
	while(current->m_next != NULL){
		if(current->m_data == x){
			flag = true;
			return current;
		}
		current = current->m_next;
	}

	//if not found
	if(!flag){
		cout << "! ERROR ! element was not found" << endl;
		return NULL;
	}
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
	if(!list.isEmpty()){
		const LLNode<T>* current = list.getFirstPtr();
		while(current->m_next != NULL){
			out << current->m_data << ", ";
			current = current->m_next;
			
		}
		out << current->m_data << ", ";
	}
	out << "]";
	/*out << "\nThe problem with the out function, and many other functions in this class, \nis that current->m_next is always null on the last element in the list.\npls fix";*/
	return out;
}