# include "queue.hpp"
# include <iostream>
using namespace std;

int main(){
    int tmp;
    Queue<int> my_queue = Queue<int>(3);
    cout << "Trying putting 3, 1, 4, 5 " << endl;
    my_queue.put(3);
    my_queue.put(1);
    my_queue.put(4);
    my_queue.put(5);
    
    cout << "Trying dequeue 4 times" << endl;
    for (int i=0; i<4; i++){
        tmp=my_queue.get();
        cout << tmp << endl;
    }
    system("Pause");
    return 0;
}