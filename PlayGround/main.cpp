#include<iostream>
#include<sstream>
#include<vector>
#include<string>
using namespace std;

/*
two inputs
    1. number of players
    2. sequence of integers

logic
    1. if number of players equal number of integers(exclude 0,1), don't change one of the numbers to 0 or 1
       else change one number(exclude 0,1) to 0
    2. if there are two numbers and one of them is 1, change the another one to 0
    3. if there is only one number change it to 1
*/
int main(){
    while(true){
        int a [8] = {0};
        int amount;
        vector<int> myVec;
        string ans;
        cout <<"enter the number of players: ";
        cin >> amount;
        cin.ignore();
        cout << "enter the integers: ";
        getline(cin, ans);
        
        stringstream ss(ans);
        int num;
        while(ss >> num){
            myVec.push_back(num);
        }
        for(int i=0; i<myVec.size(); i++){
            a[i] = myVec[i];
        }
        
        /*
         count for number of
            1. integers(exclude 0,1),
            2. oneInteger
            3. zeros
         */
        int wordCount = 0;
        int zeroCount = 0;
        int oneInteger = 0;
        int twoInteger = 0;
        for(int i=0; i<8; i++){
            if(a[i] == 0){
                zeroCount++;
            }
            else if(a[i] == 1){
                oneInteger++;
            }
            //update 3
            else if(a[i] == 2){
                twoInteger++;
                wordCount++;
            }
            //update 3
            else{
                wordCount++;
            }
        }
        
        //if only one 1 number left, change it to 0
        if (oneInteger == 1 && zeroCount == 7 && wordCount == 0){
            int place = rand() % 8;
            while(a[place] == 0){
                place = rand() % 8;
            }
            a[place] = 0;
        }
        //update 3
        else if (wordCount == 2 && twoInteger == 1){
            int place = rand() % 8;
            while(a[place] == 2 || a[place] == 0){
                place = rand() % 8;
            }
            a[place]--;
        }
        //update 3
   //update
        //if more than one numbers are 1 and there are no numbers greater than 1, change one 1 to 0
        else if(oneInteger > 1 && wordCount == 0 ){
            int place = rand() % 8;
            while(a[place] == 0){
                place = rand() % 8;
            }
            a[place] = 0;
        }
    //update
    //update 2
        //if numbers of 1 equal number of players, change the number which is not 1 to 1
        else if(oneInteger == amount){
            int place = rand() % 8;
            while(a[place] == 0 || a[place] == 1){
                place = rand() % 8;
            }
            a[place] = 1;
        }
    //update 2
        // if only one number left, change it to 1
        else if (wordCount == 1 && zeroCount == 7){
            int place = rand() % 8;
            while(a[place] == 0){
                place = rand() % 8;
            }
            a[place] = 1;
        }
        
        // if two numbers left and one number is 1, change the another to zero
        else if (wordCount == 2 && zeroCount == 6 && oneInteger == 1){
            int place = rand() % 8;
            while(a[place] == 0 || a[place] == 1){
                place = rand() % 8;
            }
            a[place] = 0;
        }
        
        //checking whether number of integers(exclude 0,1) equal number of players
        //if equal reduce just one
        //else change to zero
        else{
            int place = rand() % 8;
            while(a[place] == 0 || a[place] == 1){
                place = rand() % 8;
            }
            if( wordCount == amount ){
                a[place]--;
            }
            else {
                a[place] = 0;
            }
        }
        
        
        
        //printing out 8 numbers
        for(int i : a){
            cout << i << " ";
        }
        
        //checking whether all numbers are 0
        int count = 0;
        int oneCount = 0;
        for(int i=0; i<8; i++){
            if(a[i] == 0){
                count++;
            }
            else if(a[i] == 1){
                oneCount++;
            }
        }

        if(count == 8){
            cout << "\n\n---- I lose the game ----\n\n";
            break;
        }
        else if(count == 7 && oneCount == 1){
            cout << "\n\n---- I win the game ----\n\n";
            break;
        }

        cout << endl << endl;
    }
        return 0;
   
}
