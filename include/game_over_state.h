#ifndef GAME_OVER_STATE_H
#define GAME_OVER_STATE_H
#include "include/memory_state.h"

//Game over if all cards are turned
class Game_Over_State : public Memory_State
{
public:
    Game_Over_State();
};

#endif // GAME_OVER_STATE_H
