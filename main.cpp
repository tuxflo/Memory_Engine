#include <iostream>

#include "include/i_memory.h"
#include "include/memory.h"
using namespace std;

int main()
{
    I_Memory *game =  new Memory;
    if(!game->set_folder_path("./Pictures/txt"))
        cerr << "Error while setting folder path!" << endl;

    if(!game->set_number_of_cards(2,2))
        cerr << "Error while setting number of cards!" << endl;

    return 0;
}

