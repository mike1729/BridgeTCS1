#include "Deal.hpp"
#include "Deck.hpp"

namespace bridge {

void Deal::dealCards()
{
	Standard52Deck deck;
	for (int currentPlayer = firstCaller; deck.cardsLeft(); currentPlayer = (currentPlayer+1) % 4)
		hands[currentPlayer].insert(deck.dealCard());
		currentPlayer = (currentPlayer+1) % 4;
	}
	sigModified(*this);
}

Contract Deal::performBidding() 
{
	bidding.reset(new Bidding(firstCaller));
	sigModified(*this);
	for (int currentCaller = firstCaller; !bidding->Done(); currentCaller = (currentCaller+1)%4)
	{
		Call currentCall = arbiters[currentCaller].getCall();
		wasSuccessful = bidding->makeCall(currentCall);
	}
	contract = bidding->getContract();
	sigModified(*this);
	return contract;
}

DealResult Deal::performPlay()
{
	play.reset(new Play(contract.denomination, contract.declarer));
	result.contract = contract;
	sigModified(*this);
	int currentPlayer = contract.declarer;
	for (int trick = 0; trick < 13; trick++)
	{
		for (int i = 0; i < 4; i++)
		{
			play->add(arbiters[currentPlayer].getCard());
			currentPlayer = (currentPlayer+1)%4;
		}
		currentPlayer = play->getLastTrickWinner();
	}
	result.declarerTakenTricks = play->getTricksTaken();
	sigModified(*this);
	return result;
};

}
