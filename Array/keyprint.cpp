Q. Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.


#include<iostream>
using namespace std;

void keyprint(int num, string output){
    if(num == 0 ){
        cout<<output<<endl;
    }
    string key;
    switch(num % 10){
        case 2: key = "abc";
                break;
        case 3: key = "def";
                break;
        case 4: key = "ghi";
                break;
        case 5: key = "jkl";
                break;
        case 6: key = "mno";
                break;
        case 7: key = "pqrs";
                break;
        case 8: key = "tuv";
                break;
        case 9: key = "wxyz";
                break;
        default: break;
    }
    for(int i = 0; i < key.size(); i++){
        keyprint(num/10, output + key[i]);
    }
}

int main(){
    int num;
    cin>>num;
    string output;
    keyprint(num, output);
    return 0;
}
