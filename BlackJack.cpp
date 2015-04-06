//name:21game
//funtion:p2--a pocker game
//author:Chandler
//date:2015-4-1

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//function statements
int deal(int deck[52]);
double val(int card);
void printcard(int xcard[21], int xnum);

int main()
{	srand(time(NULL));
	
	int deck[52]={0};//the deck of pocker cards, 
	//1 for out of deck, 0 for in the deck
	int pcard[21]={0}, ccard[21]={0};//player's cards, com's cards
	int pnum=0, cnum=0;//the number of player's and computer's cards
	double psum=0, csum=0;//the sum of player's and com's cards
	char flag = '0', flagout = '0';	//flag:mark wether need a new card
	//flagout:mark wether need a new game
	bool outsign = false;
	
	//the main loop procedure of the game
	while (true) {
	//initialization of variables
	deck[52] = {0};
	pcard[21] = {0};
	ccard[21] = {0};
	pnum = 0;
	cnum = 0;
	psum = 0;
	csum = 0;
	outsign = false;
	
	//the turn of the player
	//first two cards
	cout<<"player turn: "<<endl;
	pcard[0] = deal(deck);
	psum += val(pcard[pnum]);
	pnum += 1;
	pcard[1] = deal(deck);
	psum += val(pcard[pnum]);
	pnum += 1;
	cout << "player get cards: ";
	printcard(pcard,pnum);
	//external cards
	while (true) {
		flag = '0';
		while (flag!='y'&&flag!='Y'&&flag!='n'&&flag!='N') {
			cout<<"do you want another card?(y/n):";
			cin>>flag;
		}
		if (flag == 'n'||flag == 'N') break;
		pcard[pnum] = deal(deck);
		psum += val(pcard[pnum]);
		pnum += 1;
		cout<<"get another card: ";
		printcard(pcard,pnum);
		if (psum > 21) {
			cout<<"player lose"<<endl;
			outsign = true;			
			break;
		}
	}
	//asking wether need a new game
	if (outsign) {
		flagout = '0';
		while (flagout!='y'&&flagout!='Y'&&flagout!='n'&&flagout!='N') {
			cout<<"continue?(y/n):";
			cin>>flagout;
		}
		if (flagout=='n'||flagout=='N') break;
		else continue;
	}
	
	//the turn of the com		
	cout<<"com turn:"<<endl;
	ccard[0] = deal(deck);
	csum += val(ccard[cnum]);
	cnum += 1;
	ccard[1] = deal(deck);
	csum += val(ccard[cnum]);
	cnum += 1;
	cout<<"com get cards: ";
	printcard(ccard,cnum);
	while (true)
	{
		if ((csum > psum)||((csum==psum)&&(cnum<pnum))) {
			cout<<"player lose"<<endl;
			outsign = true;
			break;
		}
		ccard[cnum] = deal(deck);
		csum += val(ccard[cnum]);
		cnum += 1;
		cout<<"get another card: ";
		printcard(ccard,cnum);
		if (csum > 21) {
			cout<<"player win"<<endl;
			outsign = true;
			break;
		}		
	}
	if (outsign) {
		flagout = '0';
		while (flagout!='y'&&flagout!='Y'&&flagout!='n'&&flagout!='N') {
			cout<<"continue?(y/n):";
			cin>>flagout;
		}
		if (flagout=='n'||flagout=='N') break;
		else continue;
	}
	}
}

//function:deal
//usage:deal(deck)
//deal one card from the deck passed
int deal(int deck[52])
{
	int card;
	while(true){
		card = rand() % 52;
		if (deck[card]==0) {
			deck[card] = 1;
			return card;
		}
	}
}

//funtion:value convert
//usage:value(card)
//convert the card to its corresponding value
double val(int card)
{
	switch (card % 13){
		case 10: 
		case 11:
		case 12: return 0.5; break;
		default: return ((card % 13) + 1);
	}
}

//function:printcard
//usage:print(xcard,xnum)
//receive a card array and its size and then print its name consecutively
void printcard(int xcard[21], int xnum)
{
	int i = 0;
	for (i=0 ; i<xnum; ++i) {
		switch (xcard[i]/13) {
			case 0: cout<<"spade"; break;
			case 1: cout<<"heart"; break;
			case 2: cout<<"club"; break;
			case 3: cout<<"dimond"; break;
		}
		switch (xcard[i]%13) {
			case 10: cout<<"J "; break;
			case 11: cout<<"Q "; break;
			case 12: cout<<"K "; break;
			default: cout<<((xcard[i] % 13) + 1)<<' '; break;
		}
	}
	cout<<endl;
}

