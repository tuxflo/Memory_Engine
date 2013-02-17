#include "include/memory.h"

Memory::Memory():
    _num_cards(0)
{
}

bool Memory::set_folder_path(std::string folder_path)
{
    //Return false if given folder does not exist or is not readable
    DIR *dir;
    struct dirent *ent;
    std::string file;
    bool cover; //For checking if a cover file exists
    if ((dir = opendir (folder_path.c_str())) == NULL)
    {
        std::cerr << "Error: Folder " << folder_path << " does not exist" << std::endl;
        return false;
    }
    while ((ent = readdir (dir)) != NULL)
    {
        file = ent->d_name;
        std::string cover_string = "cover";
        std::string extension = folder_path.substr(folder_path.length()-3);
        cover_string.append(".");
        cover_string.append(extension);
        if(cover_string.compare(file) == 0)
            cover = true;
        //Check if the fileextension matches with the given folder (like txt or svg)
        if(file.find(extension) != std::string::npos)
        {
            //std::cerr << ent->d_name << std::endl;
            _num_cards++;
        }
    }
    if(!cover)
    {
        std::cerr << "Error: No cover file found!" << std::endl;
        return false;
    }

    //Set _num_cards -1 for the cover file
    _num_cards--;

    //Just for debugging
    std::cerr << "Number of cards: " <<_num_cards << std::endl;

    if(!_num_cards)
    {
        std::cerr << "Error: Folder " << folder_path << " is empty!" << std::endl;
        return false;
    }
    closedir (dir);
    return true;
}

bool Memory::set_number_of_cards(int rows, int columns)
{
    if(!(rows * columns)%2)
    {
        std::cerr << "Error: number of cards is uneven!" << std::endl;
        return false;
    }

    if((rows * columns) > _num_cards)
    {
        std::cerr << "Error: not enough cards in the given folder." << std::endl;
        std::cerr << "Use different folder or set a smaller number of cards." << std::endl;
        return false;
    }
    //Return true if number of cards is equal or less then files in the folder
    return true;
}

bool Memory::add_player(std::string name)
{
}

bool Memory::remove_player(std::string name)
{
}

bool Memory::remove_player(int index)
{
}

std::vector<std::string> Memory::list_players()
{
}

int Memory::get_player_score(int index)
{
}

std::string Memory::get_player_name(int index)
{
}

void Memory::turn(int row, int column)
{
}
