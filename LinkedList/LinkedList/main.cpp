#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
};
class LinkedList{
private:
    node* head;
public:
    LinkedList(){
    head=NULL;};
    void show(){
        node* temp=head;
        if (temp == NULL)
            cout<<"EMPTY"<<endl;
        else{
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
    };
    void InsertNew(int dat){
        node* temp =head;
        node* p=new node;
        if (head==NULL){
            head=p;
        }else{
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=p;}
        p->next=NULL;
        p->data=dat;
    };
    void InsertAtFront(int dat){
        node* n=new node;
        n->next=head;
        head=n;
        n->data=dat;
    };
    void AtAnyPos(int dat, int pos){
        node* temp=head;
        node* x=new node;
        if(pos==0){InsertAtFront(dat);}
        else{
        pos--;
        while(pos!=0){
            temp=temp->next;
            pos--;
        }
        x->next=temp->next;
        temp->next=x;
        x->data=dat;}
    };
    void DeleteFirst(){
        node* temp=head;
        head=temp->next;
        delete(temp);
    };
    void DeleteLast(){
        node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        node* b=temp->next;
        delete(b);
        temp->next=NULL;
    };
    void DeleteAny(int pos){
        if (pos==0){DeleteFirst();}
        else{
            pos--;
            node* temp=head;
            while(pos!=0){
                temp=temp->next;
                pos--;
            }
         node* b=temp->next;
         temp->next=b->next;
         delete(b);
        }
    };
    void revers(){
        node* pre=NULL;
        node* curr=head;
        node* nex=head;
        while(nex!=NULL){
            nex=nex->next;
            curr->next=pre;
            pre=curr;
            curr=nex;
        }
        head=pre;
    };

};
#define size 5
class stackk{
private:
    node* top;
public:
    stackk(){
    top=NULL;};
    bool isEmpty(){
        if(top==NULL)
            return true;
        return false;
    };
    void push(int val){
        node* x=new node;
        x->data=val;
        if (top==NULL){
            top=x;
            x->next=NULL;
        }
        else{
            x->next=top;
            top=x;
        }
        }
    void show(){
        node* temp=top;
        while(temp!=NULL){
            cout<<temp->data;
            temp=temp->next;
        }
    };
    int pop(){
        int x=top->data;
        top=top->next;
        return x;
    };
};



class Queuee{
private:
    node* rear;
    node* frontt;
public:
    Queuee(){
    rear=NULL;
    frontt=NULL;};
    void Enqueu(int val){
        node* n=new node;
        n->data=val;
        n->next=NULL;
        if ((rear==NULL )&& (frontt==NULL)){
                frontt=n;
                rear=n;
        }
        else{
            rear->next=n;
            rear=n;
        }
    };
    void show(){
        node* temp=frontt;
        while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;

        }
    };
    void Dequeu(){
        if (frontt==NULL){cout<<"EMPTY";}
        else{
            node* temp =frontt;
            frontt=temp->next;
            delete(temp);
        }
    };


};
int main()
{
    Queuee q;
    q.Enqueu(5);
    q.Enqueu(7);
    q.show();
    q.Dequeu();
    q.show();
    return 0;
}
