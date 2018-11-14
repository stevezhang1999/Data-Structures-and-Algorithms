# include <iostream>
using namespace std;

template <class type>
class Stack{
    public:
        type data[15];
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
        type pop(){
            if( this->top == -1){
                cout << "Stack Empty" << endl;
                return NULL;
            }
            this->top -= 1;
            return this->data[this->top+1];
        }
        type get_top(){
            if( this->top == -1){
                cout << "Stack Empty" << endl;
                return NULL;
            }
            return this->data[this->top];
        }
};