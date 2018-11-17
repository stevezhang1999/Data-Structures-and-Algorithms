# include <iostream>
# include "list.hpp"

int main(){
    EventList mylist;
    mylist.head->data.time_stamp=0;
    mylist.head->data.event_type=0;
    Event event;

    event.event_type=1;
    event.time_stamp=10;
    mylist.add_by_time(event);

    event.event_type=1;
    event.time_stamp=30;
    mylist.add_by_time(event);

    event.event_type=1;
    event.time_stamp=20;
    mylist.add_by_time(event);

    mylist.print_lsit();

    system("Pause");
    return 0;

}