#include "include/end_turn_state.h"
#include "include/memory.h"

End_Turn_State::End_Turn_State(Memory *memory) :
    Memory_State(memory)
{
}

void End_Turn_State::turn(int row, int column)
{
    std::cerr << "In End_Turn_state" << std::endl;
    //Check if the cards match
    if(_memory->_first_card->get_ID() == _memory->_second_card->get_ID())
    {
        //Cards match
        std::cerr << std::endl << "Cards Match!" << std::endl << std::endl;
        _memory->_active_player->add_points(_memory->_first_card->get_points());
        _memory->_active_player->add_points(_memory->_second_card->get_points());

        if(check_game_over())
        {
            //The game is over... do something in the game over state (for example show highscore)
            _memory->_state = &_memory->_game_over_state;
            _memory->turn(0, 0);
        }


    }
    else
    {
        //Cards do not match so decrease the points of the turned cards and turn them back
        _memory->_first_card->decrease_points();
        _memory->_second_card->decrease_points();

        _memory->_first_card->set_turned(false);
        _memory->_second_card->set_turned(false);

        //Find the next player and set him/her active
        if(_memory->_players.size() == 1)
            _memory->_active_player = &_memory->_players.front();
        else
        {
            for(std::vector<Player>::iterator it = _memory->_players.begin(); it != _memory->_players.end(); ++it)
            {
                //Check if active player is the last in the vector
                if(!it->get_name().compare(_memory->_players.back().get_name()))
                    _memory->_active_player = &_memory->_players.front();
                if(!it->get_name().compare(_memory->_active_player->get_name()))
                {
                    _memory->_active_player = &*it+1;
                    break;
                }
            }
        }

    }
    _memory->_state = &_memory->_first_card_state;
}

bool End_Turn_State::check_game_over()
{
    //Check if all cards are turned
    int tmp = 0;
    for(int i=0; i< _memory->_rows; i++)
    {
        for(int j=0; j<_memory->_columns;j++)
        {
            if(_memory->_cards[i][j]->get_turned())
                tmp++;
        }
    }
    if(tmp == _memory->_rows* _memory->_columns)
        return true;
    return false;
}
