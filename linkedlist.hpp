/////////////////////////////////////////////////
//Matt Drajeske								   //
//CS 1575 A                                    //
//Assignment 3                                 //
//20 October 2019                              //
/////////////////////////////////////////////////

using namespace std;

//Default constructor
LinkedList(){
	m_head = NULL;
	m_back = NULL;
	m_size = 0;
}

/*
	BIG THREE
*/
//Destructor
~LinkedList(){
	delete m_head;
	delete m_back;
}

//operator=
const LinkedList<T>& operator=(const LinkedList<T>& rhs){
	
}

//Copy Constructor
LinkedList(const LinkedList<T>& rhs){

}

/*
	ACCESSOR FUNCTIONS
*/
//size
int size() const{

}

//if empty
bool isEmpty() const{

}

//first element
LLNode<T>* getFirstPtr(){

}

//constant version
const LLNode<T>* getFirstPtr() const{

}

//last element
LLNode<T>* getLastPtr(){

}

//any element
LLNode<T>* getAtPtr(int i){

}

/*
	MUTATOR FUNCTIONS
*/
//clear linked list
void clear(){

}

//insert element at the front of the list
void insert_front(const T& x){

}

//insert element at the back of the list
void insert_back(const T& x){

}

//insert element at specified node
void insert(const T& x, LLNode<T>* pos){

}

//remove element from front of list
void remove_front(){

}

//remove element from back of list
void remove_back(){

}

//remove specified node
void remove(LLNode<T>* pos){

}

/*
	COMPLEX OPERATIONS
*/
//operator==
bool operator==(const LinkedList<T> rhs) const{

}

//determine whether parameter x is in list
LLNode<T>* find(const T& x){

}

//reverse list
void reverse(){

}

//adds one list to another
void append(const LinkedList<T>& xlist){

}

//removes a section of a list
void clip(LLNode<T>* start, LLNode<T> stop){

}

//makes a list into a copy of a portion of the elements of another list
void slice(const LinkedList<T>& xlist, LLNode<T>* start, LLNode<T>* stop){

}

//Utility------------------------------------------------------------------
//Print Linked List
template <typename T>
ostream& operator<<(ostream& out, const LinkedList<T>& list){

}