#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int simpleRandom(int i = 0)
{
	return rand() % i;
}

class Deck
{
public:
	Deck(int decksNumber = 1)
	{
		for (int i = 0; i < decksNumber; i++)
		{
			createCards();
		}
		shuffleDeck();
	}

	enum suits
	{
		hearts,
		spades,
		clubs,
		diamonds,
		MAX
	};

	struct card
	{
		int value;
		suits suit;
		string name;
		string suitName;

		static void printCard(card card)
		{
			cout << card.name << " of " << card.suitName << ", value of " << card.value << endl;
		}

		card(int value, int suitId) : value(value)
		{
			switch (value)
			{
			case 1:
				name = "Ace";
				break;
			case 11:
				name = "Jack";
				break;
			case 12:
				name = "Queen";
				break;
			case 13:
				name = "King";
				break;
			default:
				name = to_string(value);
				break;
			}
			if (value > 10)
			{
				value = 10;
			}
			switch (suitId)
			{
			case 0:
				suit = suits::hearts;
				suitName = "Hearts";
				break;
			case 1:
				suit = suits::spades;
				suitName = "Spades";
				break;
			case 2:
				suit = suits::clubs;
				suitName = "Clubs";
				break;
			case 3:
				suit = suits::diamonds;
				suitName = "Diamonds";
				break;
			default:
				break;
			}
		}
	};

	vector<card> deck;

	void printDeck()
	{
		for (size_t i = 0; i < deck.size(); i++)
		{
			card::printCard(deck[i]);
		}
	}

	card drawCard()
	{
		card card = deck[0];
		deck.erase(deck.begin());
		return card;
	}

private:
	int decksNumber;
	int cardsPerSuit = 13;

	void shuffleDeck()
	{
		random_shuffle(deck.begin(), deck.end(), simpleRandom);
	}

	void createCards()
	{
		for (size_t i = 0; i < suits::MAX; i++)
		{

			for (int j = 1; j <= cardsPerSuit; j++)
			{
				card tempCard(j, i);
				deck.push_back(tempCard);
			}
		}
	}
};

class Player
{
public:
	vector<Deck::card> hand;

	void drawCard(Deck &deck)
	{
		Deck::card drawnCard = deck.drawCard();
		hand.push_back(drawnCard);
		if (!isDealer)
		{
			cout << "You have drawn ";
		}
		else
		{
			cout << "The dealer has drawn ";
		}
		cout << drawnCard.name << "!" << endl;
	}
	void readHand()
	{
		if (!isDealer)
		{
			cout << "In your hand you currently hold: " << endl;
		}
		else
		{
			cout << "The dealer currently holds: " << endl;

		}

		for (size_t i = 0; i < hand.size(); i++)
		{
			Deck::card::printCard(hand[i]);

			if (i == hand.size() - 1)
			{
				cout << "." << endl;
			}
			else if (i == hand.size() - 2)
			{
				cout << " and ";
			}
			else
			{
				cout << ", ";
			}
		}
	}
private:
	bool isDealer;
};

//bool playerActionPrompt(vector<int> playerHand)
//{
//	string userInput;
//	cout << "Would you like a new card?" << endl
//		<< "y/n" << endl
//		<< "To look at your hand type 'hand'" << endl;
//	cin >> userInput;
//	while (userInput != "y" && userInput != "n" && userInput != "hand")
//	{
//		cout << "Please enter 'y' for a new card, 'n' for ending your turn, or 'hand' to see your hand" << endl;
//		cin >> userInput;
//	}
//	if (userInput == "hand")
//	{
//		readPlayerHand(playerHand);
//		playerActionPrompt(playerHand);
//	}
//	else if (userInput == "y")
//	{
//		return true;
//	}
//	else if (userInput == "n")
//	{
//		return false;
//	}
//}
//
//int getHandTotal(vector<int> hand)
//{
//	int total = 0;
//	sort(hand.begin(), hand.end(), greater<int>());
//	for (size_t i = 0; i < hand.size(); i++)
//	{
//		switch (hand[i])
//		{
//		case (11):
//			total += 10;
//			break;
//		case (12):
//			total += 10;
//			break;
//		case (13):
//			total += 10;
//			break;
//		case (1):
//			if (total > 10)
//			{
//				total += 1;
//			}
//			else
//			{
//				total += 11;
//			}
//			break;
//		default:
//			total += hand[i];
//			break;
//		}
//	}
//	return total;
//}
//
//bool playerTurn(vector<int> &deck, vector<int> &playerHand)
//{
//	bool player = true;
//	playerHand = drawCard(deck, player, playerHand);
//	playerHand = drawCard(deck, player, playerHand);
//
//	int handTotal = getHandTotal(playerHand);
//	bool drawMore = playerActionPrompt(playerHand);
//	while (drawMore)
//	{
//		playerHand = drawCard(deck, player, playerHand);
//		handTotal = getHandTotal(playerHand);
//		if (handTotal > 21)
//		{
//			cout << "You have overdrawn. You lose!" << endl;
//			return false;
//		}
//		drawMore = playerActionPrompt(playerHand);
//	}
//	cout << "You have scored " << handTotal << "!" << endl;
//	cout << "Dealers turn..." << endl;
//	return true;
//}
//
//void dealerTurn(vector<int> &deck, vector<int> playerHand)
//{
//	bool player = false;
//	vector<int> dealerHand;
//	dealerHand = drawCard(deck, player, dealerHand);
//	dealerHand = drawCard(deck, player, dealerHand);
//
//	int playerHandTotal = getHandTotal(playerHand);
//	int dealerHandTotal = getHandTotal(dealerHand);
//	while (playerHandTotal > dealerHandTotal && dealerHandTotal < 21)
//	{
//		dealerHand = drawCard(deck, player, dealerHand);
//		dealerHandTotal = getHandTotal(dealerHand);
//	}
//	if (dealerHandTotal > 21)
//	{
//		cout << "The dealer has overdrawn. You win!" << endl;
//	}
//	else if (dealerHandTotal == playerHandTotal)
//	{
//		cout << "The dealer has scored " << dealerHandTotal << "." << endl;
//		cout << "Both you and the dealer have the same score. Tie!" << endl;
//	}
//	else if (dealerHandTotal > playerHandTotal)
//	{
//		cout << "The dealer has scored " << dealerHandTotal << "." << endl;
//		cout << "The dealer has beaten your score! You lose!" << endl;
//	}
//}
//
//bool newGamePrompt()
//{
//	string userInput;
//	cout << "Would you like to play a new game with the same deck?" << endl
//		<< "y/n" << endl;
//	cin >> userInput;
//	while (userInput != "y" && userInput != "n")
//	{
//		cout << "Please enter 'y' for another game, or 'n' for ending the game." << endl;
//		cin >> userInput;
//	}
//	if (userInput == "y")
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//void playGame(vector<int> &deck, vector<int> &playerHand)
//{
//	if (playerTurn(deck, playerHand))
//	{
//		dealerTurn(deck, playerHand);
//	}
//	if (newGamePrompt())
//	{
//		playerHand.clear();
//		playGame(deck, playerHand);
//	}
//}

int main()
{
	srand(unsigned(time(0)));

	//vector<int> deck = createDeck();
	//vector<int> playerHand;
	//playGame(deck, playerHand);

	Deck myDeck;
	Player Tihana;
	Tihana.drawCard(myDeck);
	Tihana.drawCard(myDeck);
	Tihana.readHand();

	system("pause");

	return 0;
}