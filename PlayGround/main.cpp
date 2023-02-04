#include<iostream>
using namespace std;
int main(){
    int num1, num2, num3, num4, num5, num6, num7, num8;     //declare 8 numbers
    cout << "assign eight numbers for the game" << endl;
    cin >> num1 >> num2 >> num3 >> num4 >> num5 >> num6 >> num7 >> num8;   //assign 8 numbers
    cout << "\n---- GAME BEGINS! ----\n\n";

    int numChoice, amount;     //variable for user's chosen number and amount
    while(true){
            cout << num1 <<" "<< num2 <<" "<< num3 <<" "<< num4 <<" "<< num5 <<" "<< num6 <<" "<< num7 <<" "<< num8 << endl;  //print out 8 numbers
            cout << "number and amount?" << endl;  //asking which number the user want to choose and which amount the user want to convert to
            cin >> numChoice >> amount;       //assign user's chosen number and amount
    while(amount < 0){    //checking whether the amount is negative or not
            cout << "\n----- You cannot change to negative number! TRY AGAIN -----\n\n";  //
            cout << num1 <<" "<< num2 <<" "<< num3 <<" "<< num4 <<" "<< num5 <<" "<< num6 <<" "<< num7 <<" "<< num8 << endl;  //print out 8 numbers
            cout << "number and amount?" << endl;
            cin >> numChoice >> amount;
    }
            switch(numChoice){ //switch case
                case 1:
                    if(amount < num1){    //if the value want to assign is less than previous
                        num1 = amount;    //assign the lesser value
                    }
                    else{
                        cout << endl << "---- Caution ! your input must be less than " << num1  << "TRY AGAIN ----" << endl;  //prompting message
                    }
                    break;
                case 2:
                    if(amount < num2){
                        num2 = amount;
                    }
                    else{
                        cout << endl << "---- Caution ! your input must be less than " << num2  << "TRY AGAIN ----" << endl;
                    }
                    break;
                case 3:
                    if(amount < num3){
                        num3 = amount;
                    }
                    else{
                        cout << endl << "---- Caution ! your input must be less than " << num3  << "TRY AGAIN ----" << endl;
                    }
                    break;
                case 4:
                    if(amount < num4){
                        num4 = amount;
                    }
                    else{
                        cout << endl << "---- Caution ! your input must be less than " << num4  << "TRY AGAIN ----" << endl;
                    }
                    break;
                case 5:
                    if(amount < num5){
                        num5 = amount;
                    }
                    else{
                        cout << endl << "---- Caution ! your input must be less than " << num5  << "TRY AGAIN ----" << endl;
                    }
                    break;
                case 6:
                    if(amount < num6){
                        num6 = amount;
                    }
                    else{
                        cout << endl << "---- Caution ! your input must be less than " << num6  << "TRY AGAIN ----" << endl;
                    }
                    break;
                case 7:
                    if(amount < num7){
                        num7 = amount;
                    }
                    else{
                        cout << endl << "---- Caution ! your input must be less than " << num7  << "TRY AGAIN ----" << endl;
                    }
                    break;
                case 8:
                    if(amount < num8){
                        num8 = amount;
                    }
                    else{
                        cout << endl << "---- Caution ! your input must be less than " << num8  << "TRY AGAIN ----" << endl;
                    }
                    break;
            }
        if (num1 == 0 && num2 ==0 && num3 ==0 && num4 ==0 && num5 ==0 && num6 == 0 && num7 == 0 && num8 == 0){      //checking if all numbers are zero
            cout << endl << num1 <<" "<< num2 <<" "<< num3 <<" "<< num4 <<" "<< num5 <<" "<< num6 <<" "<< num7 <<" "<< num8 << endl;  //print out 8 numbers
            cout<< "---- You lose the game! ----\n"<<endl;     //prompt the next player lose
            break;
        }
        cout << endl;
    }
    
    }
