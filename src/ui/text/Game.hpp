#ifndef UI_TEXT_GAME_HPP
#define UI_TEXT_GAME_HPP

#include <iostream>
#include "bridge/Game.hpp"
#include "ui/text/Deal.hpp"

namespace ui
{
namespace text
{

class Game
{
public:
	void showScore(const bridge::Game & game);
	void registerDeal(const bridge::Game & game);
	Game(bridge::PlayerID id) : id(id), dealView(id) {}
private:
	bridge::PlayerID id;
	ui::text::Deal dealView;
};


} // namespace text
} // namespace ui

#endif
