#ifndef FIRST_CARD_STATE_H
#define FIRST_CARD_STATE_H
#include "include/memory_state.h"

//State for the first card
class First_Card_State : public Memory_State
{
public:
    First_Card_State(Memory *memory);
    void turn(int row, int column);
};

#endif // FIRST_CARD_STATE_H
