#include <gtest/gtest.h>
#include "bridge/Hand.hpp"
#include "bridge/Deck.hpp"

namespace bridge {

class HandTest: public ::testing::Test
{
	public:
		Hand hand;
		Card c1 = Card(Rank::TWO, Suit::CLUBS);
		Card c2 = Card(Rank::TWO, Suit::DIAMONDS);
		Card c3 = Card(Rank::TWO, Suit::HEARTS);
		Card c4 = Card(Rank::TWO, Suit::SPADES);
		void SetUp()
		{
			hand.removeAll();
		}
		void TearDown()
		{
		}
};

TEST_F(HandTest, SimpleInsertRemove) 
{
	hand.insert(c1);
	Card c = hand.remove(0);
	EXPECT_EQ(c1.suit, c.suit);
	EXPECT_EQ(c1.rank, c.rank);
}


TEST_F(HandTest, SimpleInsertRemoveAll)
{
	hand.insert(c1);
	hand.insert(c2);
	hand.insert(c3);
	hand.insert(c4);
	hand.removeAll();
	EXPECT_EQ(0, hand.getCards().size());
}

}
