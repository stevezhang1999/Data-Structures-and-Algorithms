# include <iostream>
using namespace std;

typedef struct HString{
    char* ch;
    int length;
};

int InitString(HString* string, char ch[]);
HString* CreateString(int length, char ch[]);

void display_string(HString* string){
    for(int i=1; i<=string->length; i++){
        cout << string->ch[i];
    }
    cout << endl;
}

int kmp(HString* string, HString* pstring){
    int i=1;
    int j=1;
    int next[pstring->length+1];
    //get_next(pstring, next);
    while(i <= string->length && j<= pstring->length){
        if(string->ch[i] == pstring->ch[j] || j==0) {i++; j++;}
        else j=next[j];
    }
    if(j > pstring->length)
        return i-pstring->length;
    else return 0;
}

void get_next(HString* pstring, int next[]){
    next[0]=NULL;       // position 0 will not be used
    next[1]=0;
    int i=1;
    int j=0;
    while(i<pstring->length){
        if(j==0 || pstring->ch[i] == pstring->ch[j]){++i; ++j; next[i]=j;}
        else j=next[j];
    }

    
}

HString* CreateString(int length, char str[]){
    HString* new_string;
    new_string = new HString;
    new_string->length = length;
    
    int status;
    status = InitString(new_string, str);
    if(status)
        return new_string;
    else{
        cout << "String created but not initialized" << endl;
    }
}

int InitString(HString* string, char str[]){
    string->ch = new char[string->length+1];
    int i=0;
    while(str[i]!='\0'){
        string->ch[i+1] = str[i];
        ++i;
    }

    if (string->ch == NULL) 
        return 0;
    else
        return 1;
}

int main(){
    char str[7] = "String";
    char pstr[4] = "ing";
    HString* string;
    HString* pstring;
    string = CreateString(6, str);
    pstring = CreateString(3, pstr); 
    cout << string->length << endl;
    display_string(string);
    display_string(pstring);
    
    cout << kmp(string, pstring) << endl;

    system("Pause");
    
    return 0;
}
