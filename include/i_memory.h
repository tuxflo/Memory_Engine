#ifndef I_MEMORY_H
#define I_MEMORY_H
#include <string>
#include <vector>

#include "include/memory_state.h"
#include "include/memory_view.h"
#include "include/player.h"
#include "include/card.h"

//Interface class for the Memory Engine
class I_Memory
{
public:
    //Set up the game
    virtual bool set_folder_path(std::string folder_path)=0;
    virtual bool set_number_of_cards(int rows, int columns)=0;
    virtual bool set_number_of_cards(int number)=0;
    virtual void set_cards()=0;
    virtual Card* get_card(int row, int column)=0;
    virtual int get_possible_num_cards()=0;
    virtual int get_rows()=0;
    virtual int get_columns()=0;

    //Players stuff
    virtual bool add_player(std::string name)=0;
    virtual bool add_player(Player *player)=0;
    virtual bool remove_player(std::string name)=0;
    virtual bool remove_player(int index)=0;
    virtual int get_player_score(int index)=0;
    virtual Player *get_active_player()=0;
    virtual std::string get_player_name(int index)=0;

    //Playing
    virtual void turn(int row, int column)=0;
    void set_view(Memory_View *view);
protected:
    Memory_View *_view;
    Memory_State *_state;
};

#endif // I_MEMORY_H
