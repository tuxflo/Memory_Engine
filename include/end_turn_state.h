#ifndef END_TURN_STATE_H
#define END_TURN_STATE_H
#include "include/memory_state.h"

//State for checking if the cards match and set the next player active
class End_Turn_State : public Memory_State
{
public:
    End_Turn_State(Memory *memory);
    void turn(int row, int column);
private:
    bool check_game_over();
};

#endif // END_TURN_STATE_H
