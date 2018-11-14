# include <iostream>
# include <cmath>
using namespace std;

typedef struct Node* List;
struct Node {
    float pow=0;
    float coef=0;
    Node* next=NULL; 
};

List AddNode(List list, float pow, float coef){
    if (list->pow==0 && list->coef==0 && list->next ==NULL){
        list->pow = pow;
        list->coef = coef;
        return list;
    }

    Node* new_node = new Node;
    Node* current = list;

    while(current->next != NULL){
        current = current->next;  
    }

    new_node->coef=coef;
    new_node->pow=pow;
    new_node->next=NULL;

    current->next=new_node;
    return list;
}

List LinkList(List list1, List list2){
    Node* current = list1;
    while(current->next != NULL){
        current = current->next;  
    }
    current->next = list2;
    return list1;
}

List ListAdd(List list1, List list2){
    Node* node1 = list1;
    Node* node2 = list2;
    Node* temp = new Node;
    List new_list = new Node;

    while(node1 != NULL && node2 != NULL ){
        if(node1->pow < node2->pow){
            new_list = AddNode(new_list, node1->pow, node1->coef);
            node1 = node1->next;
        }
        
        else if (node1->pow == node2->pow){
            new_list = AddNode(new_list, node1->pow, node1->coef + node2->coef);
            node1 = node1->next;
            node2 = node2->next;
        }
        
        else if (node1->pow > node2->pow){
            new_list = AddNode(new_list, node2->pow, node2->coef);
            node2 = node2->next;
        } 
    }

    if(node1 == NULL && node2 != NULL){
        new_list = LinkList(new_list, node2);
    }

    if(node2 == NULL && node1 != NULL){
        new_list = LinkList(new_list, node1);
    }

    if (new_list->pow == 0 && new_list->coef == 0)
        new_list = new_list->next;
    return new_list;
        
}

void display_poly(List list){
    Node* current = list;
    while(current->next!=NULL){
    cout << current->coef << "x^" << current->pow << " + ";
    current = current->next;
    }
    cout << current->coef << "x^" <<current->pow << endl;
}

float calculate(List list, float value){
    float result=0.0;
    Node* current = list;
    while(current->next!=NULL){
    result += current->coef * pow(value ,current->pow);
    current = current->next;
    }
    result += current->coef * pow(value ,current->pow);

    cout << fixed <<"result: " << result << endl;

    return result;
}

int main(){
    List list1 = new Node;
    List list2 = new Node;
    List result = new Node;

    // list1 = AddNode(list1, 3, 5);
    // list1 = AddNode(list1, 5, 7);
    // list1 = AddNode(list1, 7, 8);

    // list2 = AddNode(list2, 2, 4);
    // list2 = AddNode(list2, 3, 9);
    // list2 = AddNode(list2, 8, 3);

    float in_pow, in_coef;
    cout << "(Enter -999 to terminate) Please enter coefs and pows of the first polynomial: " << endl;
    while(true){
        cin >> in_coef;
        if (in_coef == -999)
            break;
        cin >> in_pow;
        if (in_pow == -999)
            break;
        list1 = AddNode(list1, in_pow, in_coef);
    }

    cout << "(Enter -999 to terminate) Please enter coefs and pows of the second polynomial: " << endl;
    while(true){
        cin >> in_coef;
        if (in_coef == -999)
            break;
        cin >> in_pow;
        if (in_pow == -999)
            break;
        list2 = AddNode(list2, in_pow, in_coef);
    }


    result = ListAdd(list1, list2) ;

    List tmp=result;
    // while(true){        
    //     cout << "coef: " << tmp->coef << endl;
    //     cout << "pow: " << tmp->pow <<endl;
    //     if (tmp->next != NULL)
    //         tmp = tmp->next;
    //     else
    //         break;
    // }

    tmp=result;
    display_poly(tmp);

    float cal_result, value;
    cout << "Please enter the value:";
    cin >> value;
    tmp=result;
    cal_result = calculate(tmp, value);

    system("Pause");
    return 0;
}