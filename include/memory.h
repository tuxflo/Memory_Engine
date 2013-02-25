#ifndef MEMORY_H
#define MEMORY_H
#include <dirent.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <list>
#include <math.h>

#include "include/i_memory.h"
#include "include/player.h"
#include "include/card.h"

#include "include/first_card_state.h"
#include "include/second_card_state.h"
#include "include/end_turn_state.h"
#include "include/game_over_state.h"

//Implementation of local playing Memory with multiple Players
class Memory : public I_Memory
{
    friend class First_Card_State;
    friend class Second_Card_State;
    friend class End_Turn_State;
    friend class Game_Over_State;

public:
    Memory();
    bool set_folder_path(std::string folder_path);
    bool set_number_of_cards(int rows, int columns);
    bool set_number_of_cards(int number);
    int get_possible_num_cards();
    void set_cards();
    Card *get_card(int row, int column);
    int get_rows();
    int get_columns();
    std::string get_cover() const;

    bool add_player(std::string name);
    bool add_player(Player *player);
    bool remove_player(std::string name);
    bool remove_player(int index);
    int get_player_score(int index);
    std::string get_player_name(int index);
    Player *get_active_player();

    void turn(int row, int column);


    //Debugging
    void view_cards();
protected:

private:
    //Player handeling
    std::list<Player*> _players;
    Player *_active_player;
    //File handeling maybe put this stuff in a shared lib?
    int get_num_files(std::string folder_path, std::string file_extension);
    std::string _folder_path;
    std::string _filename_extension;
    //For generating unique random numbers if specific range
    int *_unique_numbers(int array_size, int max);
    bool _check_number(int *array, int array_size, int number);

    int _get_num_files(std::string folder_path, std::string file_extension);

    //Maximum number of cards in given directory
    int _num_cards; //Attention the cards availible for playing is _num_cards * 2
    int _rows;
    int _columns;
    std::string _cover;

    //States
    First_Card_State _first_card_state;
    Second_Card_State _second_card_state;
    End_Turn_State _end_turn_state;
    Game_Over_State _game_over_state;

    //Cards
    Card ***_cards;

    //Pointer for the current cards
    Card *_first_card;
    Card *_second_card;
};

#endif // MEMORY_H
