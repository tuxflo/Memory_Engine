#ifndef MEMORY_H
#define MEMORY_H
#include <dirent.h>
#include <iostream>

#include "include/i_memory.h"


//Implementation of local playing Memory with multiple Players
class Memory : public I_Memory
{
public:
    Memory();
    bool set_folder_path(std::string folder_path);
    bool set_number_of_cards(int rows, int columns);

    bool add_player(std::string name);
    bool remove_player(std::string name);
    bool remove_player(int index);
    std::vector<std::string> list_players();
    int get_player_score(int index);
    std::string get_player_name(int index);

    void turn(int row, int column);
protected:

private:
    //Maximum number of cards in given directory
    int _num_cards;
};

#endif // MEMORY_H
