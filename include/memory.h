#ifndef MEMORY_H
#define MEMORY_H
#include "include/i_memory.h"

//Implementation of local playing Memory with multiple Players
class Memory : public I_Memory
{
public:
    Memory();
    bool set_folder_path(std::string folder_path);
    bool set_number_of_cards(int rows, int columns);
};

#endif // MEMORY_H
