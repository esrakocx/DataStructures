#include <iostream>
using namespace std;

class Stack{
	public:
		Stack(int size = 10); //constructor
		~Stack(){
			delete [] values; //destructor
		}
		bool IsEmpty(){
			if(top == -1)
				return true;
			else
				return false;
		}
		bool IsFull(){
			if(top == maxTop)
				return true;
			else
				return false;
		}
		double Top();
		void Push(const double x);
		double Pop();
		void DisplayStack();
	
	private:
		int maxTop;
		int top;
		double* values;
};

Stack::Stack(int size){
	top = -1;
	maxTop = size - 1;
	values = new double[size];
}

void Stack::Push(const double x){
	if(IsFull())
		cout << "Error: The Stack is full!" << endl;
	else{
		top++;
		values[top] = x;
	}
}

double Stack::Pop(){
	if(IsEmpty()){
		cout << "Stack is empty!" <<endl;
		return -1;
	}
		
	else
		return values[top--];
}

double Stack::Top(){
	if(IsEmpty()){
		cout << "Stack is empty!" <<endl;
		return -1;
	}
	else
		return values[top];
}

void Stack::DisplayStack(){
	cout << "Top -->";
	for(int i = top; i >= 0; i--)
		cout<<"\t|\t" << values[i] << "\t|" << endl;
	cout << "\t|---------------|" << endl; 
} 

int main(void){
	
	Stack stack(5);
	stack.Push(5.0);
	stack.Push(6.4);
	stack.Push(3.2);
	stack.Push(-9.0);
	stack.Push(2.4);
	stack.DisplayStack();
	cout << "Top: " << stack.Top() << endl;
	
	stack.Pop();
	cout << "Top: " << stack.Top() << endl;
	
	while(!stack.IsEmpty())
		stack.Pop();
	
	stack.DisplayStack();
	
	return 0;
}
