# include <iostream>
# include <cstring>
using namespace std;



bool check_op_in_series (string expression){
    // check if has pattern like '++'
    for(int i=0; i<expression.length(); i++){
        
    }
}

bool check_paranthesss (string expression){
    int left=0;
    int right=0;
    for(int i=0; i<expression.length(); i++){
        if(expression[i])=='(')
            left += 1;
        if(expression[i]==')')
            right += 1;
    }
    return left == right;
}