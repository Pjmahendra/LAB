#include<iostream>
#include<stdlib.h>

using namespace std;

class tree {
    private:
        typedef struct node {
            int data;
            struct node *lnext;
            struct node *rnext;
        }sn;
        
        sn* createNode(int data) {
            sn* newNode = new sn;
            newNode->data = data;
            newNode->rnext = nullptr;
            newNode->lnext=NULL;
            return newNode;
        }
    public:
        sn*head=NULL;
        sn* insert(int data){
                sn *temp = head, *p = nullptr;
                if(head == NULL) {
                    head = createNode(data);
                    return head;
                } else {
                    while(temp!=NULL){
                        p=temp;
                        if(data>temp->data) {
                            temp = temp->rnext;
                        } else if(data<temp->data) {
                            temp = temp->lnext;
                        } else {
                            cout << "Data already exists." << endl;
                            return temp;
                            
                        }
                    } temp= new sn;
                    temp->data = data;
                    temp->lnext = nullptr;
                    temp->rnext = nullptr;
                    if(data > p->data) {
                        p->rnext = temp;
                    } else {
                        p->lnext = temp;
                    }
            }return head;
        }
        sn* createBST(int n){
            if(n==0) return NULL;int data;
            cout << "Enter data for tree of: "<< n << " nodes: ";
            for(int i=0;i<n;i++){
                cin >> data;
                head = insert(data);
            }return head;
        }
        void inorder(sn* root) {
            if(root != NULL) {
                inorder(root->lnext);
                cout << root->data << " ";
                inorder(root->rnext);
            }
        }
        sn * insucc(sn *p){
            while ((p && p->lnext!=NULL)){
                p=p->lnext;
            }
            return p;
        }
        sn* inpre(sn *p){
            while ((p && p->rnext!=NULL)){
                p=p->rnext;
            }
            return p;
        }
        int height(sn *p){
            if(p==NULL) return 0;
            int lheight = height(p->lnext);
            int rheight = height(p->rnext);
            return (lheight > rheight ? lheight : rheight) + 1;
        }
        sn * del(sn* p,int key){
            sn  *q=NULL;
            if(p==NULL){
                return NULL;
            }else if(p->data==key &&p->lnext==NULL &&p->rnext==NULL){
                if(p==head)
                    head=NULL;
                delete p;
                return NULL;
            }
            if(key<p->data){
                p->lnext=del(p->lnext,key);
            }else if(key>p->data){
                p->rnext=del(p->rnext,key);
            }else{
                if(height(p->lnext)>height(p->rnext)){
                    q=inpre(p->lnext);
                    p->data=q->data;
                    p->lnext=del(p->lnext,q->data);
                }else{
                    q=insucc(p->rnext);
                    p->data=q->data;
                    p->rnext=del(p->rnext,q->data);
                }
            }
            return p;
        }
};
int main(){
    int n,data;
    tree t1;
    cout << "Enter the number of nodes in tree t1: ";
    cin >> n;
    t1.createBST(n);
    cout << "Inorder traversal of tree t1: ";
    t1.inorder(t1.head);
    cout << endl;
    int x;
    cout << "enter 1 if you want to insert a node and 0 if you want to delete a node or enter any other number to exit: ";
    cout <<endl;
    while(1){
        cout << "enter your choice:";
        cin>> x;
        switch (x)
        {
            case 0 :
                cout << "Enter the data to be deleted from tree t1: ";
                cin >> data;
                t1.head = t1.del(t1.head, data);
                cout << "Inorder traversal after deletion: ";
                t1.inorder(t1.head);
                cout << endl;
                break;
            case 1:
                cout << "Enter the data to be inserted into tree t1: ";
                cin >> data;
                t1.insert(data);
                cout << "Inorder traversal after insertion: ";
                t1.inorder(t1.head);
                cout << endl;
                break;
        default:
            return 0;
            break;
        }
    
    }
    return 0;
}
