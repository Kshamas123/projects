#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
int user_choice,comp_choice;
cout<<"welcome to the game."<<endl<<"instructions-*command 1 stands foe scissors"<<endl<<"*command 2 stand for stone"<<endl<<"*command 3 stand for paper"<<endl;
cout<<"enter your choice"<<endl;
cin>>user_choice;
srand(time(0));
comp_choice=rand()%(3-1)+1;
if(user_choice==comp_choice)
{cout<<"IT'S A TIE";
cout<<comp_choice<<" was the choice of the computer"<<endl;}
else
if(user_choice==1 && comp_choice==2 )
{cout<<"SORRY YOU LOST"<<endl;
cout<<comp_choice<<" was the choice of the computer"<<endl;}
else
if(user_choice==2 && comp_choice==1 )
{cout<<"CONGRATS YOU WON"<<endl;
cout<<comp_choice<<" was the choice of the computer"<<endl;}
else
if(user_choice==1 && comp_choice==3 )
{cout<<"CONGRATS YOU WON"<<endl;
cout<<comp_choice<<" was the choice of the computer"<<endl;}
else
if(user_choice==3 && comp_choice==1 )
{cout<<"SORRY YOU LOST"<<endl;
cout<<comp_choice<<" was the choice of the computer"<<endl;}
else
if(user_choice==2 && comp_choice==3 )
{cout<<"SORRY YOU LOST"<<endl;
cout<<comp_choice<<" was the choice of the computer"<<endl;}
else
{cout<<"cCONGRTAS YOU WON"<<endl;
cout<<comp_choice<<" was the choice of the computer"<<endl;}
cout<<"end of the game";
}
//easy way or another method is to combine all the user winning chance of the userand within another else part computer chance of winning and last else part tie condition.