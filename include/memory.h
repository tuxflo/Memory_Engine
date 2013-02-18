#ifndef MEMORY_H
#define MEMORY_H
#include <dirent.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <sstream>

#include "include/i_memory.h"


//Implementation of local playing Memory with multiple Players
class Memory : public I_Memory
{
public:
    Memory();
    bool set_folder_path(std::string folder_path);
    bool set_number_of_cards(int rows, int columns);
    void set_cards();

    bool add_player(std::string name);
    bool remove_player(std::string name);
    bool remove_player(int index);
    std::vector<std::string> list_players();
    int get_player_score(int index);
    std::string get_player_name(int index);

    void turn(int row, int column);
protected:

private:
    //File handeling
    int get_num_files(std::string folder_path, std::string file_extension);
    std::string _folder_path;
    std::string _filename_extension;
    //For generating unique random numbers if specific range
    int *_unique_numbers(int array_size, int min, int max);
    bool _check_number(int *array, int array_size, int number);

    int _get_num_files(std::string folder_path, std::string file_extension);
    std::string *_shuffle_array(std::string *array, int array_size);
    //Maximum number of cards in given directory
    int _num_cards;
    int _rows;
    int _columns;
};

#endif // MEMORY_H
