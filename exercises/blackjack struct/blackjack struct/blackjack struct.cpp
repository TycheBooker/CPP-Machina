#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct card
{
	int id;
	int value;
	string suit;
	string name;

	card(int id, int value, string suit, string name) :
		id(id), value(value), suit(suit), name(name)
	{}

	int operator +(card &nextCard)
	{
		return value + nextCard.value;
	}
};

vector<card> deck;
vector<string> cardNames = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
vector<string> suites = { "Hearts", "Spades", "Diamonds", "Clubs" };
vector<int> values = { 2, 3, 4, 5, 6, 7, 8, 9, 10 };

vector<card> populateDeck()
{
	int max = 10;
	int id = 0;
	vector<card> result;
	for (size_t i = 0; i < suites.size(); i++)
	{
		for (size_t j = 0; j < cardNames.size(); j++)
		{
			string currentName = cardNames[j];
			int tempValue = 0;
			if (currentName == "Jack" || currentName == "Queen" || currentName == "King")
			{
				tempValue = 10;
			}
			else if (currentName == "Ace")
			{
				tempValue = 11;
			}
			else
			{
				tempValue = j < values.size() ? values[j] : max;
			}
			card cardGiven(id, tempValue, suites[i], currentName);
			result.push_back(cardGiven);
			id++;
		}
	}
	return result;
}

struct player
{
	string name;
	vector<card> hand;
	double cash;
	int rank;
	int score;
	bool isInGame;

	player(string name, double cash, bool game) :
		name(name), cash(cash), isInGame(true)
	{
		rank = 0;
		score = 0;
		isInGame = game;
	}
};

struct comp
{
	string name;
	vector<card> hand;
	double cash;
	int rank;
	int score;
	bool isInGame;
	bool dealer;

	comp(string name, double cash, bool game, bool isDealer) :
		name(name), cash(cash), isInGame(true), dealer(false)
	{
		rank = 0;
		score = 0;
		isInGame = game;
		dealer = isDealer;
	}
};

void play()
{
	while (true)
	{
		//
		int playersNumber;
		cout << "Enter number of players: " << endl;
		cin >> playersNumber;
		if (cin.bad() || playersNumber <= 0)
		{
			return;
		}
		vector<player> players;
		for (size_t i = 0; i < playersNumber; i++)
		{
			string name;
			double cash;

			cout << "Enter name: " << endl;
			cin >> name;

			cout << "Enter amount of money: " << endl;
			cin >> cash;

			players.push_back(player(name, cash, true));
		}
		//
		char choice;
		vector<card> playerHand;
		vector<card> houseHand;
		//
		cout << "Do you wish to take another card?(y/n)" << endl;
		cin >> choice;
		return;
	}
}

int main()
{
	deck = populateDeck();
	for (size_t i = 0; i < deck.size(); i++)
	{
		cout << deck[i].value << "\t";
		cout << deck[i].id << "\t";
		cout << deck[i].name << "\t";
		cout << deck[i].suit << endl;
	}
	random_shuffle(deck.begin(), deck.end());
	play();
	cout << "Thanks for playing!" << endl;

	system("pause");
	return 0;
}
