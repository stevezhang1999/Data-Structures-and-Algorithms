# include "queue.hpp"
# include "list.hpp"
# include <iostream>
using namespace std;

int main(){
    
    // Bank Open
    EventList event_list;
    int total_time =0;
    int customer_num = 0;
    int close_time = 480; // latest for queuing, arrived will be serviced.
    event_list.head->data.event_type = 0;
    event_list.head->data.time_stamp = 0;

    Queue<Customer> queue[4];
    for(int i=0; i<4; i++){
        queue[i] = Queue<Customer>(100);
    }
    // Dealing with events
    while(event_list.head){
        // if event type is arrival
        if(event_list.head->data.event_type == 0){
            // customer number +1
            customer_num += 1;
            // new arrival event for generation, and insert it.
            Event new_arrival;
            new_arrival.time_stamp = rand() % 10 + 1 + event_list.head->data.time_stamp;
            new_arrival.event_type = 0;
            //cout << new_arrival.time_stamp << endl;
            if(new_arrival.time_stamp < close_time)
                event_list.add_by_time(new_arrival);
            // create the customer
            Customer customer_event;
            customer_event.arrival_time = event_list.head->data.time_stamp;
            customer_event.durarion = rand() % 30 + 10;
            // delete first event
            event_list.head = event_list.head->next;
            // put the customer in queue;
            // first find shortest; if shortest None, then add a departure event.
            int min_index = 0;
            for(int i=0; i<4; i++){
                if(queue[i].length() < queue[min_index].length())
                    min_index = i;
                }

                queue[min_index].put(customer_event);

            if(queue[min_index].length()==1){
                Event departure;
                departure.event_type = min_index+1;
                departure.time_stamp = customer_event.arrival_time + customer_event.durarion;
                event_list.add_by_time(departure);
            }
        }
        // not 0,  (else departure)
        else{
            int queue_departure = event_list.head->data.event_type - 1;
            Customer customrer_departure = queue[queue_departure].get();
            total_time = total_time + event_list.head->data.time_stamp - customrer_departure.arrival_time;
            event_list.head = event_list.head->next;
            if(!queue[queue_departure].empty()){
                Event new_departure_event;
                new_departure_event.event_type = queue_departure + 1;
                new_departure_event.time_stamp = event_list.head->data.time_stamp + queue[queue_departure].view_top().durarion;
                event_list.add_by_time(new_departure_event);
            }
        }
    }
    cout << "Total Time: " << total_time << endl;
    cout << "Custimers: " << customer_num << endl;
    cout << "Average Waiting Time " << total_time / customer_num << endl;
    system ("Pause");
    return 0;
}
