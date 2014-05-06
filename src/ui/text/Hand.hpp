#ifndef Hand_hpp
#define Hand_hpp

#include "../Observer.hpp"

namespace ui
{
    namespace text
    {
        class Hand : public Observer
        {
        public:
            Hand(const ::Hand & hand) {
            	cards = hand.getHand();
            }    
        private:
        	void printHand()
            const std::list<Card> & cards;
        
        };
    }
}


#endif
