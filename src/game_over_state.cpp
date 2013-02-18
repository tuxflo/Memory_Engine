#include "include/game_over_state.h"
#include "include/memory.h"
Game_Over_State::Game_Over_State(Memory *memory) :
    Memory_State(memory)
{
}

void Game_Over_State::turn(int row, int column)
{
    std::cerr << "In Game over State" << std::endl;

    //Find the winner, show his/her score and create highscore

    exit(0);
}
