#ifndef MODEL_PLAYER_HPP
#define MODEL_PLAYER_HPP

#include "Call.hpp"
#include "Card.hpp"
#include "Play.hpp"
#include "Hand.hpp"
#include "Bidding.hpp"

namespace model {

class IPlayer
{
public:
	virtual Card chooseCard(Play const &, Hand const &) = 0;
	virtual Call makeCall(Bidding const &) = 0;
};

class Player : public IPlayer
{
public:
	virtual Card chooseCard(Play const &, Hand const &);
	virtual Call makeCall(Bidding const &);
};

}
#endif
