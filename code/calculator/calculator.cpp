# include <iostream>
# include <cstring>
# include <cmath>
# include "stack.hpp"
using namespace std;

int calculate(string expression);
int calc_with_op (int num1, int num2, char op);
int get_priority(char op);
int compare(char op1, char op2);
string preprocess(string expression);
int factorial(int num); 

int main(){

    int result;
    string expression;
    
    cout << "Please enter an expression: " << endl;

    while(true){
    cout << ">> ";
    cin >> expression;

    if(expression == "exit")
        break;

    expression = preprocess(expression);

    if(expression == "terminate")
        continue;
    else 
        result = calculate(expression);

    cout << result << endl;
    }
    system("Pause");
    return 0;
}

int calculate(string expression){

    Stack<int> number_stack = Stack<int>();
    Stack<char> operator_stack = Stack<char>();

    int number=0;
    int num1, num2;
    char op;
    string temp_num_str;
    int priority;

    operator_stack.push('#');

    for(int i=0; i<expression.length(); i++){
        
        // a number? (end of a number)
        if(expression[i]>='0' && expression[i]<='9'){
            temp_num_str += expression[i];
        }
        // not a number (an operator.)
        else{
            if(!temp_num_str.empty()) number_stack.push(stoi(temp_num_str));
            temp_num_str.clear();
            
            // 1:>, 0:=, -1:<
            while(true){

                if(expression[i]=='('){
                    operator_stack.push('(');
                    break;
                }

                if(expression[i]=='!'){
                    num1 = number_stack.pop();
                    number_stack.push(factorial(num1));
                    break;
                }

                priority = compare(expression[i], operator_stack.get_top());

                if(priority == 1){
                    operator_stack.push(expression[i]);
                    break;
                }

                else if (priority==0)
                {
                    operator_stack.pop();
                    break;
                }
                
                else if (priority == -1)
                {
                    num1 = number_stack.pop();
                    num2 = number_stack.pop();
                    op = operator_stack.pop();
                    number_stack.push(calc_with_op(num1, num2, op));
                }
            }
        }
    }
    return number_stack.pop();
}

int compare(char op1, char op2){
    if(op1=='(' && op2==')') return 0;
    if(op1==')' && op2=='(') return 0;
    if(op1=='#' && op2=='#') return 0;
    if(get_priority(op1) > get_priority(op2)) return 1;
    if(get_priority(op1) == get_priority(op2)) return -1;
    if(get_priority(op1) < get_priority(op2)) return -1;
}

int get_priority(char op){
    if(op == '!')
        return 10;
    if(op == '^')
        return 5;
    if(op == ')')
        return 0;
    if(op == '*' || op == '/')
        return 2;
    if(op == '+' || op == '-')
        return 1;
    if(op == '(')
        return 0;
    if(op == '#')
        return -1;
}

int calc_with_op (int num1, int num2, char op){
    if(op=='*') return num1 * num2;
    if(op=='/' && num1==0){
        cout << "Error: Division by zero." << endl;
        cout << "Calculation terminate at: ";
        return 0;
    }
    if(op=='/') return num2 / num1;
    if(op=='+') return num1 + num2;
    if(op=='-') return num2 - num1;
    if(op=='^') return pow(num2, num1);
    
    cout << "Invalid Expression." << endl;
    cout << "Calculation terminate at: ";
    return 0;
}

string preprocess(string expression){
    char expression_last;
    char expression_first;

    expression_first = expression[0];
    expression_last = expression[expression.length()-1];

    if((expression_last <'0' || expression_last >'9') && expression_last!=')' && expression_last!='!')
        {
        cout << "Ivalid expression!" << endl;
        return "terminate";
        }

    if(expression_first != '(' 
        && expression_first != '+' 
        && expression_first != '-' 
        && (expression_first <'0' || expression_first >'9')) 
        {
        cout << "Ivalid expression!" << endl;
        return "terminate";
        }
    if(expression_first == '+' || expression_first == '-') 
        expression = '0' + expression;
    if(expression_last != '#')
        expression += '#';

    return expression;
}

int factorial(int num){
    int result=1;
    while(num>0){
        result *= num;
        --num;
    }
}