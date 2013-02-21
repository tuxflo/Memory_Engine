#include <iostream>

#include "include/i_memory.h"
#include "include/memory.h"
using namespace std;

int main()
{
    I_Memory *game =  new Memory;
    game->add_player("tuxflo");
    game->add_player("anne");
    game->add_player("vader");


    if(!game->set_folder_path("/home/tuxflo/workspace/Memory_Qt_GUI/Pictures/Capitols_of_Latin_America/svg"))
    {
        cerr << "Error while setting folder path!" << endl;
        return -1;
    }

    if(!game->set_number_of_cards(2,2))
    {
        cerr << "Error while setting number of cards!" << endl;
        return -1;
    }
    game->set_cards();

    game->turn(0, 0);
    game->turn(0,1);

    game->turn(0, 0);
    game->turn(1,0);

    game->turn(0,0);
    game->turn(1,1);

    game->turn(0, 1);
    game->turn(1,1);


    return 0;
}

