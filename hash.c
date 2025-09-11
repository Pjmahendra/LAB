#include <stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*hash[10]={NULL};
int insert(int val){
    int r=val%10;
    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->data=val;
    n->next=NULL;
    if(hash[r]==NULL){
        hash[r]=n;
        return 1;
    }else{
        struct node* temp=hash[r];
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
        return 1;
    }
}
int delete(int val){
    int r=val%10;
    if(hash[r]==NULL){
        return 0;
    }else{
        struct node* temp=hash[r];
        if(temp->data==val){
            hash[r]=temp->next;
            free(temp);
            return 1;
        }
        while(temp->next!=NULL && temp->next->data!=val){
            temp=temp->next;
        }
        if(temp->next==NULL){
            return 0;
        }else{
            struct node* todelete=temp->next;
            temp->next=temp->next->next;
            free(todelete);
            return 1;
        }
    }
}
void search(int val){
    int r=val%10;
    if(hash[r]==NULL){
        printf("Not found\n");
        return;
    }else{
        struct node* temp=hash[r];
        while(temp!=NULL){
            if(temp->data==val){
                printf("Found\n");
                return;
            }
            temp=temp->next;
        }
        printf("Not found\n");
        return;
    }
}
void display(){
    for(int i=0;i<10;i++){
        struct node* temp=hash[i];
        printf("%d: ",i);
        while(temp!=NULL){
            printf("%d -> ",temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
int main(){
    int choice; int val;
    printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d",&val);
                if(insert(val)){
                    printf("Inserted\n");
                }else{
                    printf("Not Inserted\n");
                }
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d",&val);
                if(delete(val)){
                    printf("Deleted\n");
                }else{
                    printf("Not Deleted\n");
                }
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d",&val);
                search(val);            
                break;
            case 4:
                display();
                break;
            default:
                exit(0);
                break;
            }
        }
        
    return 0;
}