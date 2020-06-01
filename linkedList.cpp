#include <iostream>
using namespace std;
struct Node{
	int data;
	Node*next;//we could use typedef for Node*
};
class LinkedList{
	private:
		Node *head;
		Node *tail;
		int length;
	public:
		LinkedList(){//constructor
			head=tail=NULL;
			length=0;
		}
		bool isEmpty(){
			return head==NULL;
		}
		void append(int element){
			//inserting new element in the last position
			Node*newNode=new Node;
			newNode->data=element;
			if(isEmpty()){
			//adding for the first time
				head=tail=newNode;
				newNode->next=NULL;
			}else{
				tail->next=newNode;
				tail=newNode;
				newNode->next=NULL;
			}
			
		}
		void prepend(int element){
			//inserting new element in the first position
			Node*newNode=new Node;
			newNode->data=element;
			if(isEmpty()){
			//adding for the first time
				head=tail=newNode;
				newNode->next=NULL;
			}else{
				newNode->next=head;
				head=newNode;
			}
		}
		void insert(int element, int position){
				Node*newNode=new Node;
				newNode->data=element;
				if(isEmpty()){
					//checking if the position is only the first
				head=tail=newNode;
				newNode->next=NULL;
			}
		}
		void print(){
			if(isEmpty())
				cout<<"this linked list is empty"<<endl;
			else{
				Node*temp= new Node;
				temp=head;
				while(temp->data!=NULL){
					cout<<temp->data<<endl;
					temp=temp->next;
				}
				delete(temp);
			}
		}
		void deleteFirst(){
			if(isEmpty())
				cout<<"NO nodes to be deleted"<<endl;
			else{
				cout<<"the deleted value is :"<<head->data<<endl;
				Node*temp = head;
				head = temp->next;
				delete(temp);
			}
		}
		void deleteLast(){
			if(isEmpty())
				cout<<"NO nodes to be deleted"<<endl;
			else{
				cout<<"the deleted value is :"<<tail->data<<endl;	
				//loop over the list again to detect the new tail
				Node*temp=head;
				while(temp->next!=tail){//to detect the node before the tail
					temp=temp->next;
				}
				temp->next=NULL;
				delete(tail);
				tail=temp;
			}
		}
		void deleteNode(int index){
			if(isEmpty())
				cout<<"NO nodes to be deleted"<<endl;
			else if(index<0)
				cout<<"please enter a valid index"<<endl;
			else if(index==0)
				this->deleteFirst();
			else{
				int counter=1;
				Node*temp=head->next;//for looping from head->next to tail
				Node*prevTempNode=head;//for getting the previos node when matching
				while(temp != tail){
					if(counter==index){
						//delete this node
						prevTempNode->next=prevTempNode->next->next;
						break;
						
					}else{
						temp=temp->next;
						prevTempNode=prevTempNode->next;
						counter++;
					}
						
						
				}
				if(temp==tail)
					this->deleteLast();
				delete(temp);
			}
			
		}
	
};
int main(){
	return 0;
};