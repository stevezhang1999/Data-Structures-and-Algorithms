# include <iostream>
# include <cstring>
using namespace std;

class Stack_int{
    public:
        int data[15];
        int top=-1;
        int max_len=15;
        bool push(int num){
            if(top == max_len -1){
                cout << "Stack Full" << endl;
                return false;
            }
            this->top +=1 ;
            this->data[this->top] = num;
            return true;  
        }
        int pop(){
            if( this->top == -1){
                cout << "Stack Empty" << endl;
                return -999;
            }
            this->top -= 1;
            return this->data[this->top+1];
        }
        int get_top(){
            if( this->top == -1){
                cout << "Stack Empty" << endl;
                return -999;
            }
            return this->data[this->top];
        }
};

class Stack_str{
    public:
        char data[15];
        int top=-1;
        int max_len=15;
        bool push(int num){
            if(top == max_len -1){
                cout << "Stack Full" << endl;
                return false;
            }
            this->top +=1 ;
            this->data[this->top] = num;
            return true;  
        }
        char pop(){
            if( this->top == -1){
                cout << "Stack Empty" << endl;
                return 'N';
            }
            this->top -= 1;
            return this->data[this->top+1];
        }
        char get_top(){
            if( this->top == -1){
                cout << "Stack Empty" << endl;
                return 'N';
            }
            return this->data[this->top];
        }
};