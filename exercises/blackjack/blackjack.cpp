/*
Napraviti pojednostavljenu simulaciju kartaske igre blackjack. Korisnika se pita hoce li uzeti kartu, y znaci da, n znaci ne. Ukoliko se korisnik odluci za kartu, dodaje mu se ta karta. Cilj je skupiti zbroj 21 ili sto blize tom broju. Ukoliko korisnik ima zbroj veci od 21, automatski gubi igru. Nakon korisnika racunalo bira karte, racunalo ce odustati tj. nece vise uzimati karte ukoliko ili ima bolji zbroj od igraca ili je u rasponu 13-21.
*/

// #include "stdafx.h"
#include <iostream>
#include <vector>
// #include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int simpleRandom(int i)
{
  return rand() % i;
}

vector<int> createDeck()
{
  vector<int> deck;
  for (size_t i = 0; i < 4; i++)
  {

    for (size_t j = 1; j < 14; j++)
    {
      deck.push_back(j);
    }
  }
  random_shuffle(deck.begin(), deck.end(), simpleRandom);
  return deck;
}

string getCardName(int card)
{

  switch (card)
  {
  case (1):
    return "an Ace";
    break;

  case (11):
    return "a Jack";
    break;

  case (12):
    return "a Queen";
    break;

  case (13):
    return "a King";
    break;

  default:
    return "a " + to_string(card);
    break;
  }
}

void readPlayerHand(vector<int> playerHand)
{
  cout << "In your hand you currently hold: " << endl;

  for (size_t i = 0; i < playerHand.size(); i++)
  {
    string cardName = getCardName(playerHand[i]);
    cout << cardName;
    if (i == playerHand.size() - 1)
    {
      cout << "." << endl;
    }
    else if (i == playerHand.size() - 2)
    {
      cout << " and ";
    }
    else
    {
      cout << ", ";
    }
  }
}

vector<int> addCardtoHand(int card, vector<int> hand)
{
  hand.push_back(card);
  return hand;
}

vector<int> drawCard(vector<int> &deck, bool player, vector<int> hand)
{
  int card = deck[0];
  deck.erase(deck.begin());

  if (player)
  {
    cout << "You have drawn ";
  }
  else
  {
    cout << "The dealer has drawn ";
  }
  string cardName = getCardName(card);
  cout << cardName << "!" << endl;
  return addCardtoHand(card, hand);
}

bool playerActionPrompt(vector<int> playerHand)
{
  string userInput;
  cout << "Would you like a new card?" << endl
       << "y/n" << endl
       << "To look at your hand type 'hand'" << endl;
  cin >> userInput;
  while (userInput != "y" && userInput != "n" && userInput != "hand")
  {
    cout << "Please enter 'y' for a new card, 'n' for ending your turn, or 'hand' to see your hand" << endl;
    cin >> userInput;
  }
  if (userInput == "hand")
  {
    readPlayerHand(playerHand);
    playerActionPrompt(playerHand);
  }
  else if (userInput == "y")
  {
    return true;
  }
  else if (userInput == "n")
  {
    return false;
  }
}

int getHandTotal(vector<int> hand)
{
  int total = 0;
  sort(hand.begin(), hand.end(), greater<int>());
  for (size_t i = 0; i < hand.size(); i++)
  {
    switch (hand[i])
    {
    case (11):
      total += 10;
      break;
    case (12):
      total += 10;
      break;
    case (13):
      total += 10;
      break;
    case (1):
      if (total > 10)
      {
        total += 1;
      }
      else
      {
        total += 11;
      }
      break;
    default:
      total += hand[i];
      break;
    }
  }
  return total;
}

bool playerTurn(vector<int> &deck, vector<int> &playerHand)
{
  bool player = true;
  playerHand = drawCard(deck, player, playerHand);
  playerHand = drawCard(deck, player, playerHand);

  int handTotal = getHandTotal(playerHand);
  bool drawMore = playerActionPrompt(playerHand);
  while (drawMore)
  {
    playerHand = drawCard(deck, player, playerHand);
    handTotal = getHandTotal(playerHand);
    if (handTotal > 21)
    {
      cout << "You have overdrawn. You lose!" << endl;
      return false;
    }
    drawMore = playerActionPrompt(playerHand);
  }
  cout << "You have scored " << handTotal << "!" << endl;
  cout << "Dealers turn..." << endl;
  return true;
}

void dealerTurn(vector<int> &deck, vector<int> playerHand)
{
  bool player = false;
  vector<int> dealerHand;
  dealerHand = drawCard(deck, player, dealerHand);
  dealerHand = drawCard(deck, player, dealerHand);

  int playerHandTotal = getHandTotal(playerHand);
  int dealerHandTotal = getHandTotal(dealerHand);
  while (playerHandTotal > dealerHandTotal && dealerHandTotal < 21)
  {
    dealerHand = drawCard(deck, player, dealerHand);
    dealerHandTotal = getHandTotal(dealerHand);
  }
  if (dealerHandTotal > 21)
  {
    cout << "The dealer has overdrawn. You win!" << endl;
  }
  else if (dealerHandTotal == playerHandTotal)
  {
    cout << "The dealer has scored " << dealerHandTotal << "." << endl;
    cout << "Both you and the dealer have the same score. Tie!" << endl;
  }
  else if (dealerHandTotal > playerHandTotal)
  {
    cout << "The dealer has scored " << dealerHandTotal << "." << endl;
    cout << "The dealer has beaten your score! You lose!" << endl;
  }
}

bool newGamePrompt()
{
  string userInput;
  cout << "Would you like to play a new game with the same deck?" << endl
       << "y/n" << endl;
  cin >> userInput;
  while (userInput != "y" && userInput != "n")
  {
    cout << "Please enter 'y' for another game, or 'n' for ending the game." << endl;
    cin >> userInput;
  }
  if (userInput == "y")
  {
    return true;
  }
  else
  {
    return false;
  }
}

void playGame(vector<int> &deck, vector<int> &playerHand)
{
  if (playerTurn(deck, playerHand))
  {
    dealerTurn(deck, playerHand);
  }
  if (newGamePrompt())
  {
    playerHand.clear();
    playGame(deck, playerHand);
  }
}

int main()
{
  std::srand(unsigned(std::time(0)));
  vector<int> deck = createDeck();
  vector<int> playerHand;
  playGame(deck, playerHand);
  return 0;
}