#include "include/second_card_state.h"
#include "include/memory.h"
Second_Card_State::Second_Card_State(Memory *memory) :
    Memory_State(memory)
{
}

void Second_Card_State::turn(int row, int column)
{
    std::cerr << "In Second_Card_state" << std::endl;
    if(_memory->cards[row * _memory->_rows + column].get_turned())
        //Card is already turned so do nothing
        return;
    _memory->_second_card = &_memory->cards[row * _memory->_rows + column];
    _memory->_second_card->set_turned(true);

    _memory->_state = &_memory->_end_turn_state;
    _memory->turn(0,0);

}
