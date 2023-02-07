#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;
int main(){
    while(true){
        int a [] = { 0, 0, 0, 0, 0, 0, 0, 0};
        vector<int> myVec;
        string ans;
        getline(cin, ans);
        
        stringstream ss(ans);
        int num;
        while(ss >> num){
            myVec.push_back(num);
        }
        for(int i=0; i<myVec.size(); i++){
            a[i] = myVec[i];
        }
        int place = rand() % 8;
        while (a[place] == 0){
            place = rand() % 8;
        }
        a[place] = rand() % a[place];
        for(int i : a){
            cout << i << " ";
        }
        
///
        int count = 0;
        for(int i=0; i<8; i++){
            if(a[i] == 0){
                count++;
            }
        }
        
        if(count == 8){
            cout << "\n\n---- You lost the game ----\n\n";
            break;
        }
///
        cout << endl << endl;
    }
        return 0;
   
}


