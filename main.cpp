#include<iostream>
#include<string>
#include<ctime>
#include<cstDlib>
using namespace std;
void draw_line(int n,char symbol)
{
	for(int i=0;i<=n;i++)
		cout<<symbol;
	cout<<"\n";
}
void random(int guess,bool var)
{
	srand(time(0));
	int random_number=rand()%14+0;
	if(guess==random_number)
	{
		cout<<"\n\n<<Yo!You have won!!";
		var=true;
	}
	else
	{
		cout<<"\n\n"<<"Better luck next time";
		cout<<"\n"<<"The winning number was:"<<random_number;
		var=false;
	}
}
int main()
{
	int betting_money,guess;
	bool var;
	char choice;
	draw_line(60,'-');
	cout<<"\n\n\n\t\t\t"<<"CASINO GAME"<<"\n\n\n";
	draw_line(60,'-');
	string name;
	cout<<"\n"<<"Enter your name:";
	cin>>name;
	cout<<"Enter deposit amount to play the game:";
	int money;
	cin>>money;
	do{
		system("cls");
		draw_line(60,'*');
		cout<<"\n\n\t\t"<<"The rules of the game are:"<<"\n\n";
		cout<<"You get to choose a number between 0 and 13"<<"\n";
		cout<<"If you win you get money worth 10 times your betting money"<<"\n";
		cout<<"Else"<<"\n";
		cout<<"You will loose the betting money"<<"\n\n\n";
		draw_line(60,'*');
		cout<<"\n\n"<<"Your current balance is:"<<money;
		do{
			cout<<"\n\n"<<"Enter the betting money:";
			cin>>betting_money;
			if(betting_money>money)
				cout<<"\n\n"<<"Its insufficient"<<"\n"<<"Renter the data";
		}while(betting_money>money);
		do{
			cout<<"\n"<<"Enter the guess:";
			cin>>guess;
			if(guess<0||guess>13)
				cout<<"\n"<<"Invalid guess"<<" Renter it";
		}while(guess<0||guess>13);
		random(guess,var);
		if(var==true)
		{
			money=money+(10+betting_money);
			cout<<"\n"<<"Your balance amount is:"<<money;
		}
		else
		{
			money=money-betting_money;
			cout<<"\n"<<"Your balance amount is:"<<money;
		}
		if(money==0)
		{
			cout<<"\n"<<"You dont have enough money to play";
			break;
		}
		cout<<"\n\n-->Do you want to play again(y/n)? ";
        cin>>choice;
	}while(choice=='Y'||choice=='y');
	cout<<"\n\n\n";
    draw_line(70,'=');
    cout<<"\n\nThanks for playing game. Your balance amount is $ "<<money<<"\n\n";
    draw_line(70, '=');
	return 0;
}
