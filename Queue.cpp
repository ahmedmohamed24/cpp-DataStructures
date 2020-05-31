#include <iostream>
using namespace std;
const int SIZE=10;
class Queue{
	private:
		int front,rear;
		int queueArr[SIZE];
	public:
		Queue(){
			front=rear=-1;
		}
		bool isEmpty(){
			return front==-1;
		}
		bool isFull(){
			if ((front == 0 && rear == SIZE - 1)||(front == rear + 1))//circular queue for more efficient
				return true;
			return false;
		}
		void enQueue(int element){
			if(isFull())
				cout<<"this queue is full"<<endl;
			else{
				if(isEmpty())
					front=0;
				rear = (rear + 1) % SIZE;
				queueArr[rear]=element;	
			}
		} 
		void deQueue(){
			if(isEmpty())
				cout<<"this queue is empty"<<endl;
			else{
				if(front==rear)
					front=rear=-1;
				else
				front=(front+1)%SIZE;				
				
			}
		}
		void getFront()  
		{  
		    if (isEmpty())  
		        cout<<"this queue is empty"<<endl;
			else
				cout<<queueArr[front]<<endl;  
		}  
		void getRear()  
		{  
		    if (isEmpty())  
		        cout<<"this queue is empty"<<endl;
			else
				cout<<queueArr[rear]<<endl;  
		}  	
		void print(){
			if(isEmpty())
				cout<<"this queue is empty"<<endl;
			else{
				for(int i=front; i!=rear; i=(i+1)%SIZE){
						cout << queueArr[i]<<endl;	
				}
				cout<<queueArr[rear]<<endl;// for printing the rear itself (the current value)
			}
		}
};
int main(){
	
	return 0;
};