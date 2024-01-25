#include <iostream>
#define size 20
#include<string>
using namespace std;

/*
class Stack {
private:
    int top=-1;
    string StackData[size];
public:
    Stack(){ top =-1;}
    bool IsEmpty (){
        if (top == -1)
            return true;
        else
            return false;
    }
    bool IsFull(){
        if (top ==size-1)
            return true;
        else
            return false;
    }
    void show(){
        if (top ==-10)
            cout<< "The Stack is Empty";
        else{
            for(int i=top;i>=0;i--){
                cout<< StackData [i]<<"\n";
        }}}
    void push (string val){
        if (! IsFull())
            StackData[++top]=val;
        else
            cout<<"Stack is Full \n";
    }
    void pop(){
        if (IsEmpty())
            cout<<"Stack is empty \n";
        else
            cout << StackData[top--]<<"\n";
    }

};*/
/*
 bool IsBalanced(string statement){
     Stack open_brackets;
     for (int i=0; i<statement.length();i++){
            if (statement[i] == '(' || statement[i] == '{' || statement[i] == '[')
                    open_brackets.push(statement[i]);
            else


        }
    }*/


class STACK{
private:
    int top;
    int data[size];
public:
    STACK(){
        top=-1;
    }
    bool isFull(){
        if (top==size-1)
            return true;
        else
            return false;
    }
    bool isEmpty(){
        if (top==-1)
            return true;
        else
            return false;
    }
    void push(int val){
        if (!isFull())
            data[++top]=val;
        else
            cout<<"The Stack is full";

    }
    void pop(){
        if (!isEmpty())
            cout<<data[--top];
        else
            cout<<"The stack is empty";
    }
    void display (){
        if (!isEmpty()){
        for(int i=top;i>=0;i--)
            cout<< data[i];
    }
    else
        cout<<"The stack is empty";}
    int top_value(){
        return data[top];
    }

};
int periority(char op){
    if (op=='+'||op=='-')
        return 1;
    else if (op=='*'||op=='/')
        return 2;
    else if(op=='^')
        return 3;
    else
        return 0;
};
string prefix2suffix(string input){
    string output ="";
    STACK S;
    for (int i=0;i<input.length();i++){
        if (input[i]=='(')
            S.push(input[i]);
        else if (isalpha(input[i])||isdigit(input[i])){
            output += input[i];
        }
        else if (input[i]==')'){
            while(S.top_value()!='('){
                output += S.top_value();
                S.pop();
            }
            S.pop();
        }

        else {
            if (periority(input[i]) > periority(S.top_value()))
                S.push(input[i]);
            else {
                while(periority(input[i]) <= periority(S.top_value())){
                    output+=S.top_value();
                    S.pop();
                }
                S.push(input[i]);
            }
        }

    }
    while (!S.isEmpty()){
        output+=S.top_value();
        S.pop();
    }
    cout<<endl<<endl<<endl;
    return output;

}
string decimal2binary(int val){
    string output="";
    int remind=0;
    STACK ss;
    while(val!=0){
        remind= val %2;
        val/=2;
        ss.push(char(remind+0x30));
    }

    cout<< endl<<endl<<endl;
    ss.display();
    return output;

}

void evaluation (string exp){
STACK s1;
int res=0;
int n1;
int n2;
for(int i=0;i<exp.length();i++){
    if (isdigit(exp [i]))
        s1.push(float(exp[i]));

    else{
        switch(exp[i]){
            case '+':
                n1=s1.top_value();
                s1.pop();
                n2=s1.top_value();
                res=n1+n2;
                s1.push(res);
            case '-':
                n1=s1.top_value();
                s1.pop();
                n2=s1.top_value();
                res=n1-n2;
                s1.push(res);
            case '*':
                n1=s1.top_value();
                s1.pop();
                n2=s1.top_value();
                res=n1*n2;
                s1.push(res);
            case '/':
                n1=s1.top_value();
                s1.pop();
                n2=s1.top_value();
                res=n1/n2;
                s1.push(res);

    }}
}
s1.display();
}

int main()
{
    //string input="((A+B)*C-D)*E";
    //cout<<prefix2suffix(input);
/*
cout<<decimal2binary(16);
*/
evaluation("71+");
    return 0;
}
