#include "include/first_card_state.h"
#include "include/memory.h"


First_Card_State::First_Card_State(Memory *memory) :
    Memory_State(memory)
{
}

void First_Card_State::turn(int row, int column)
{
    std::cerr << "Active Player: " << _memory->_active_player->get_name() << std::endl;
    std::cerr << "In First_Card_state" << std::endl;

    //This is the first card
    if(_memory->cards[row * _memory->_rows + column].get_turned())
        //The card is already turned, so do nothing
        return;
    _memory->_first_card = &_memory->cards[row * _memory->_rows + column];
    _memory->_first_card->set_turned(true);

    //First card is turned so switch to the second card state
    _memory->_state = &_memory->_second_card_state;
}
