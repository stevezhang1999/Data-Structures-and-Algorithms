# include <iostream>
using namespace std;

template <class type>
class Queue{
    public:
        type* data;
        int max_size;
        int front = 0;
        int rear = 0;
        Queue(){
            this->front = 0;
            this->rear = 0;
        }
        Queue(int data_size){
        	this->max_size = data_size+1; 
            this->data = new type[max_size];
            this->max_size = data_size+1; 
            this->front = 0;
            this->rear = 0;
        }
        ~Queue(){
            delete[] this->data;
        }
        bool put(type val){
            if((this->rear + 1) % this->max_size == this->front){
                cout << "Queue Full." << endl;
                return false;
            }
            this->data[this->rear] = val;
            this-> rear = (this->rear + 1) % this->max_size;
        }
        type get(){
            if(this->front == this->rear){
                cout << "Queue Empty" << endl;
                return type();
            }
            this->front += 1;
            return this->data[this->front-1];
        }
        type view_top(){
            if(this->front == this->rear){
                cout << "Queue Empty" << endl;
                return type();
            }
            return this->data[this->front];
        }
        bool empty(){
             if(this->front == this->rear) return true;
             else return false;
        }
        int length(){
            return this->rear - this->front;
        }
};

