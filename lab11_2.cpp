#include<iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	int x = rand()%13 + 1;
	return x;
}

int calScore(int x,int y,int z){
	int s = cardScores[x] + cardScores[y] + cardScores[z];
	int fs = s - (s/10)*10;
	return fs;
}

int findYugiAction(int s){	
	if(s == 9) return 2;
	else if(s < 6) return 1;
	else{
		if (rand()%100 <= 30) return 2;
		else return 1;
	}
}

void checkWinner(int p, int y){

	cout << "\n---------------------------------\n";
	if (y == p)
	cout <<   "|             Draw!!!           |";
	else if (p > y)
	cout <<   "|         Player wins!!!        |";
	else if (p < y)
	cout <<   "|          Yugi wins!!!         |";
	else 
	cout << "error";
	cout << "\n---------------------------------\n";
}

int main(){	
    srand(time(0));

	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0};
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 && playerAction != 2);
	if(playerAction == 1){
		int x = drawCard();
  		playerScore = calScore(playerCards[0],playerCards[1],x);
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " << cardNames[x] << "\n";
		cout << "Your new score: " << playerScore << "\n";
	}
	cout << "------------ Turn end -------------------\n\n";
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]] << "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		int x = drawCard();
		yugiScore = calScore(yugiCards[0],yugiCards[1],x);
		cout << "Yugi draws the 3rd card!!!\n";
		cout << "Yugi's 3rd card: " << cardNames[x] << "\n";
		cout << "Yugi's new score: " << yugiScore <<"\n";
	}
	cout << "------------ Turn end -------------------\n";
	
	
	checkWinner(playerScore,yugiScore);
	return 0;
}
