#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
    {int user_choice,randno,i;
    cout<<"WELCOME TO THE GAME"<<endl<<"RULES OF THE GAME"<<endl<<"1.YOU HAVE 5 ATTEMPTS"<<endl<<"2.YOU WILL BE GIVEN THE HINT ABOUT HOW CLOSE TO THE NUMBER YOU ARE"<<endl;
    srand(time(0)); randno=rand()%(100-1)+1;
    for(i=1;i<=5;i++)
    {cout<<"enter the number ranging from 1-100"<<endl;
    cin>>user_choice;
    if(user_choice==randno)
    {cout<<"you have won the game"<<endl;break;}
    else
    if(user_choice<randno)
    cout<<"the choosen number is less than the real value"<<endl;
    else
    cout<<"the choosen number is greater than the real value"<<endl;}
    if(user_choice==randno)
    cout<<"end of the game"<<endl;
    else
    { cout<<randno<<endl;
    cout<<"you have lost the game.end"<<endl;}}