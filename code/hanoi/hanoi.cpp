# include <iostream>
using namespace std;

void hanoi(int num, int start, int mid, int destination){
    if(num == 1){
        cout << start << "->" << destination << endl;
    }
    else{
        hanoi(num-1, start, destination, mid);
        cout << start << "->" << destination << endl;
        hanoi(num-1, mid, start, destination);
    }
}

int main(){
    int num = 3;
    cin >> num;
    hanoi(num, 1, 2, 3);

    system("Pause");
    return 0;
}