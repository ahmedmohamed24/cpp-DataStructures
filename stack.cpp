#include <iostream>
using namespace std;
const int MAX_SIZE=100;
class stack{
private:
    int top;
    int arr[MAX_SIZE];
public:
    stack(){
        top=-1;
    }
    bool  isEmpty(){
        return top<0;
    }
    bool  isFull(){
       return top >= MAX_SIZE;
    }
    void  getTop(){
        if(isEmpty())
            cout<< "this stack is empty"<<endl;
        else
            cout<<arr[top]<<endl;
    }
    void push(int val){
        if(isFull())
            cout<<"this stack is full"<<endl;
        else
            arr[++top]=val;

    };
    void  pop(){
        if(isEmpty())
            cout<<"this function is empty"<<endl;
        else
            top--;
    };
    void pop(int&element){
    	//this is a princible in OOP called function overloading 
         if(isEmpty())
            cout<<"this function is empty"<<endl;
        else
            element = arr[top--];
        
    };
    void print(){
    	if(isEmpty())
   		cout<<"this stack is empty"<<endl;
   		else{
	    	int temp=0;
	    	while(temp<=top){
		    	cout<<arr[temp]<<endl;
		    	temp++;
		    }
		}
    }
};

int main(){
	
	return 0;
};