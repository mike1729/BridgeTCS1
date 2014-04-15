#ifndef BIDDING_STATE_HPP
#define BIDDING_STATE_HPP

#include <vector>
#include "Call.hpp"
#include "Contract.hpp"


using History = std::vector<Call>;

class BiddingState
{
public:
	BiddingState(int firstCaller) : callNumber(firstCaller) {}

	bool makeCall(Call call);
	bool biddingDone()
	{
		return isFinished;
	}
	Contract getContract()
	{
		findDeclarer();
		return currentContract;
	}
private:
	Contract currentContract;
	int consecutivePasses = 0;
	bool isFinished = false;
	int lastBidder = 0;
	History history;
	int callNumber;

	void findDeclarer();
};
#endif