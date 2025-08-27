//stackn using linked list
#include <iostream>
#include <cstdlib>
using namespace std;
class stack1 {
    private:
        struct node {
            int data;
            node* next;
        }*head=NULL;
    public:
        struct node* push(int data){
            if(head ==NULL){
                head = new node;
                head->data = data;
                head->next = NULL;
            } else {
                node* temp = new node;
                temp->data = data;
                temp->next = head;
                head = temp;
            }return head;
        }
        int pop(){
            struct node *temp=NULL;
            temp=head;int data;
            if(head==NULL){
                cout << "stack is empty " << endl;
                return -1;
            }else{
                head=head->next;
                data=temp->data;
                delete temp;
                return data;
            }
            
        }
        int display(){
            struct node *temp=head;
            if(temp==NULL){
                cout << "stack is empty " << endl;
                return -1;
            }
            cout << "stack elements are: ";
            while(temp!=NULL){
                cout << temp->data << " ";
                temp=temp->next;
            }
            cout << endl;
            return 0;
        }
        int top(){
            if(head==NULL){
                cout << "stack is empty " << endl;
                return -1;
            }
            else{
                return head->data;
            }
        }
        
        
};
int main(){
    stack1 s1;
    int choice,data;
    cout << "enter 1 to push data " << endl;
    cout << "enter 2 to pop data " << endl;
    cout << "enter 3 to get top data " << endl;
    cout << "enter 4 to display elements of the stack " << endl;
    cout << "enter any other number to exit " << endl;
    while(1){
        cout << "enter your choice: ";
        cin >> choice;
        data=-1;
        switch(choice){
            case 1:
                cout << "enter data to be pushed: ";
                cin >> data;
                s1.push(data);
                cout << "data pushed successfully " << endl;
                break;
            case 2:
                data = s1.pop();
                if(data != -1) {
                    cout << "popped data is: " << data << endl;
                }
                break;
            case 3:
                data = s1.top();
                if(data != -1) {
                    cout << "top data is: " << data << endl;
                }
                break;
            case 4:
                s1.display();
                break;
            default:
                cout << "....exiting your program..." << endl;
                return 0;break;
            }
    }
}
