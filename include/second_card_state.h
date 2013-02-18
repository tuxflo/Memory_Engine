#ifndef SECOND_CARD_STATE_H
#define SECOND_CARD_STATE_H
#include "include/memory_state.h"

//State for the second card
class Second_Card_State : public Memory_State
{
public:
    Second_Card_State(Memory *memory);
    void turn(int row, int column);
};

#endif // SECOND_CARD_STATE_H
