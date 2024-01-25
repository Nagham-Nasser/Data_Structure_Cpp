#include <iostream>
#include<string>
#define size 10
using namespace std;

class Queue{
private:
    int Rear=-1;
    int Front=-1;
    int data[size];
public:

    bool isFull(){
        if ((Rear==size-1&&Front == 0)||(Front==Rear+1))
            return true;
        else
            return false;
    }
    bool isEmpty(){
        if (Rear==-1)
            return true;
        else
            return false;
    }
    void enqueue(int val){
        if (!isFull()){
            if (Front==-1)
                Front=0;
            Rear=(Rear+1)%size;
            data[Rear]=val;
        }
        else{
            cout<<"The queue is full"<< endl;}
    }
    void dequeue(){
        if (!isEmpty()){
            cout << data[Front];
            if (Rear==Front)
                Rear,Front=-1;
            else
                Front=(Front+1)%size;
        }
        else
            cout<<"The Queue is Empty"<< endl;
    }
    void display(){
        if (isEmpty())
            cout<<"The queue is empty"<<endl;
        else{
            for (int i=Front;;i=(i+1)%size){
                cout<< data[i]<<endl;
                if (i==Rear)
                    break;

            }
        }
    }
    void show(){
        cout<< Rear<<endl<<Front;
    }
};

int main()
{

Queue q;
q.enqueue(1);
q.enqueue(1);
q.enqueue(1);
q.enqueue(1);
q.enqueue(1);
q.enqueue(1);
q.enqueue(1);
q.enqueue(1);
q.enqueue(1);
q.enqueue(1);
q.dequeue();
q.dequeue();
q.dequeue();
q.dequeue();
cout<<endl;
cout<<endl;
q.enqueue(100);

cout<<endl;
q.display();

    return 0;
}
