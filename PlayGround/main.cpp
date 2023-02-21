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
    int amount;
    cout <<"enter the number of players: ";
    cin >> amount;
    cin.ignore();
    while(true){
        
        // getting the sequence of integers and storing them in array
        int a [8] = {0};
        vector<int> myVec;
        string ans;
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
            else if(a[i] == 2){
                twoInteger++;
                wordCount++;
            }
            else{
                wordCount++;
            }
        }
        
        //if there are two numbers(exclude 1,0), trace the other one or reduce one
        if(wordCount==2 && amount == 2)
        {
            bool firstNumberFound = false;
            int firstNumberPlace = 0;
            int secondNumberPlace = 0;
            for(int i=0; i<8; i++){
                if(a[i] != 0 && a[i] != 1){
                    if(!firstNumberFound){
                        firstNumberPlace = i;
                        firstNumberFound = true;
                    }
                    else{
                        secondNumberPlace = i;
                    }
                }
            }
            if(a[firstNumberPlace] < a[secondNumberPlace]){
                a[secondNumberPlace] = a[firstNumberPlace];
            }
            else if(a[firstNumberPlace] > a[secondNumberPlace]){
                a[firstNumberPlace] = a[secondNumberPlace];
            }
            else{
                a[firstNumberPlace]--;
            }
        }
        
        //if only one 1 number left, change it to 0
        else if (oneInteger == 1 && zeroCount == 7 && wordCount == 0){
            int place = rand() % 8;
            while(a[place] == 0){
                place = rand() % 8;
            }
            a[place] = 0;
        }
 
        //if more than one numbers are 1 and there are no numbers greater than 1, change one 1 to 0
        else if(oneInteger > 1 && wordCount == 0 ){
            int place = rand() % 8;
            while(a[place] == 0){
                place = rand() % 8;
            }
            a[place] = 0;
        }
        
        //if numbers of 1 equal number of players, change the number which is not 1 to 1
        else if(oneInteger == amount){
            int place = rand() % 8;
            while(a[place] == 0 || a[place] == 1){
                place = rand() % 8;
            }
            a[place] = 1;
        }
        
        // if only one number left, change it to 1
        else if (wordCount == 1 && zeroCount == 7){
            int place = rand() % 8;
            while(a[place] == 0){
                place = rand() % 8;
            }
            a[place] = 1;
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
                if (oneInteger % 2 == 0){
                    a[place] = 1;
                }
                else{
                    a[place] = 0;
                }
            }
        }
        
        
        
        //printing out 8 numbers
        for(int i : a){
            cout << i << " ";
        }
        
        //considering winning or losing
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
