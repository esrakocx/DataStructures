#include <iostream>
using namespace std;

class Node{
	public:
		double data; //data of the node
		Node *next; //pointer to next node
};

class List{
	public:
		List(void){
			head =NULL; //constructor
		}
		~List(void); //destructor
		
		bool IsEmpty(){
			return head == NULL;
		}
		
		Node* InsertNode(int index, double data);
		int FindNode(double data);
		int DeleteNode(double data);
		void DisplayList(void);
		
	private:
		Node *head;
};

Node* List::InsertNode(int index, double data){
	
	if(index < 0) return NULL;
	
	int currIndex = 1;
	Node* currNode = head;
	
	while(currNode && index > currIndex){
		currNode = currNode->next;
		currIndex++;
	}
	if(index > 0 && currNode == NULL) return NULL;
	
	Node* newNode = new Node;
	newNode->data = data;
	
	if(index == 0){
		newNode->next = head;
		head = newNode;
	}
	
	else{
		newNode->next = currNode->next;
		currNode->next = newNode;
	}
	
	return newNode;
}

int List::FindNode(double data){
	Node* currNode = head;
	int currIndex = 1;
	
	while(currNode && currNode->data != data){
		currNode = currNode->next;
		currIndex++;
	}
	if(currNode) return currIndex;
	
	return 0;
}

int List::DeleteNode(double data){
	Node* prevNode = NULL;
	Node* currNode = head;
	int currIndex = 1;
	
	while(currNode && currNode->data != data){
		prevNode = currNode;
		currNode = currNode->next;
		currIndex++;
	}
	
	if(currNode){
		if(prevNode){
			prevNode->next = currNode->next;
			delete currNode;
		}
		else{
			head = currNode->next;
			delete currNode;
		}
		return currIndex;
	}
	return 0;
}

void List::DisplayList(){
	int count = 0;
	Node* currNode = head;
	
	while(currNode != NULL){
		cout << currNode->data << endl;
		currNode = currNode->next;
		count++;
	}
	cout << "Number of nodes int the list: " << count << endl;
}

List::~List(void){
	Node* currNode = head, *nextNode = NULL;
	while(currNode != NULL){
		nextNode = currNode->next;
		delete currNode;
		currNode = nextNode;
	}
}

int main(){
	
	List list;
	list.InsertNode(0, 7.0);
	list.InsertNode(1, 5.6);
	list.InsertNode(0,3.2);	
	
	list.DisplayList();
	
	if(list.FindNode(5.6) > 0) 
		cout << "5.6 found!" << endl;
	else
		cout << "5.6 not found!" <<endl;
		
	if(list.FindNode(4.0) > 0)
		cout << "4.0 found" << endl;
	else 
		cout << "4.0 not found" << endl;
	
	list.DeleteNode(3.2);
	list.DisplayList();
	
	return 0;
}
