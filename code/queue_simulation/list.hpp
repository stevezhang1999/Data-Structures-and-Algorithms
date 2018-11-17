# include <iostream>
using namespace std;

struct Customer{
    int arrival_time=0;
    int durarion=0;
};

struct Event{
    int event_type = NULL;
    int time_stamp = NULL;
};

template <class type>
class Node{
    public:
	    type data;
	    Node* next = NULL;
};

template <class type>
class List{
    public:
        Node<Event>* head = new Node<Event>;

        bool add_by_time(Event event){
        Node<Event>* new_node = new Node<Event>;
        Node<Event>* current_node = new Node<Event>;
        Node<Event>* prev_node = new Node<Event>;

        current_node = this->head;
        prev_node->next = this->head;

        new_node->data = event;
        
        // if(current_node==this->head && this->head->next==NULL){
        //     if(current_node->data.time_stamp <= new_node->data.time_stamp){
        //         current_node->next = new_node;
        //         return true;
        //     }
        //     else if(current_node->data.time_stamp > new_node->data.time_stamp){
        //         new_node->next=current_node;
        //         this->head = new_node;
        //         return true;
        //     }
        // }
            if(! this->head){
                this->head = new_node;
                return true;
            }

            while(current_node->data.time_stamp <= new_node->data.time_stamp){
                if(current_node->next!=NULL){
                    prev_node = prev_node->next;
                    current_node = current_node->next;
                }
                else{
                    //clear 
                    current_node->next=new_node;
                    return true;
                }
            }
            if(prev_node->next != this->head){
            prev_node->next = new_node;
            new_node->next = current_node;
            }
            else{
                new_node->next = current_node;
                this->head = new_node;
            }
            return true;
    	}

        Event get_event(){
            Event event = this->head->data;
            this->head = this->head->next;
            return event;
        }      
        void print_lsit(){
            Node<Event>*  current_node = new Node<Event>;
            current_node = this->head; 
            cout << "********" << endl;
            while(true){
                cout << current_node->data.time_stamp << " " <<current_node->data.event_type << endl;
                if(current_node->next!=NULL){
                    current_node = current_node->next;
                }
                else break;
            }
            cout << "********" << endl; 
        }
};

typedef struct List<Event> EventList;
