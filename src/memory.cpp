#include "include/memory.h"

Memory::Memory():
    _num_cards(0)
{
}

bool Memory::set_folder_path(std::string folder_path)
{
    DIR *dir;
    struct dirent *ent;
    std::string file;
    bool cover; //For checking if a cover file exists
    _filename_extension = folder_path.substr(folder_path.length()-3);
    std::string cover_string = "cover";
    cover_string.append(".");
    cover_string.append(_filename_extension);
    //First check if cover file exists
    if ((dir = opendir (folder_path.c_str())) == NULL)
    {
        std::cerr << "Error: Folder " << folder_path << " does not exist!" << std::endl;
        return false;
    }
    while ((ent = readdir (dir)) != NULL)
    {
        file = ent->d_name;
        if(cover_string.compare(file) == 0)
            cover = true;
    }
    closedir(dir);
    if(!cover)
    {
        std::cerr << "Error: No cover file found!" << std::endl;
        return false;
    }

    _folder_path = folder_path;

    //Check the subfolders
    folder_path.append("/1");
    int first = _get_num_files(folder_path, _filename_extension);
    if(!first)
    {
        return false;
    }
    folder_path.replace(folder_path.length()-1, 1, "2");
    int second = _get_num_files(folder_path, _filename_extension);
    if(!second)
    {
        return false;
    }
    if(first > second)
        _num_cards = second;
    else
        _num_cards = first;

    //Just for debugging
    std::cerr << "Number of cards in Folder " << _folder_path << " : " << _num_cards << std::endl;
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
    _rows = rows;
    _columns = columns;

    //Just for debugging
    std::cerr << "Number of cards choosen by player: " << _rows * _columns << std::endl;
    return true;
}

void Memory::set_cards()
{
    int count = _rows*_columns;
    //Array for the filenames numbers (Randomly from 1- number of cards/2)
    int *filenames = _unique_numbers(count/2, 1, _num_cards);

    std::stringstream directory_name;
    std::string *cards_array = new std::string [count];
    for(int i=0; i<count/2; i++)
    {
        directory_name << _folder_path << "/1/" << filenames[i] << "." << _filename_extension;
        cards_array[i] = directory_name.str();
        directory_name.str("");
    }
    int tmp=0;
    for(int j=count/2; j<count; j++)
    {
        directory_name << _folder_path << "/2/" << filenames[tmp] << "." << _filename_extension;
        cards_array[j] = directory_name.str();
        directory_name.str("");
        tmp++;
    }
    cards_array = _shuffle_array(cards_array, count);

    delete [] filenames;
    delete [] cards_array;
}

bool Memory::add_player(std::string name)
{
    _players.push_back(Player(name));
    std::cerr << "Added Player: " << name << std::endl;
    return true;
}

bool Memory::remove_player(std::string name)
{
    if(_players.empty())
    {
        std::cerr << "Could not remove Player because Player list is empty" << std::endl;
        return false;
    }
    for(std::vector<Player>::iterator it = _players.begin(); it != _players.end(); ++it)
    {
        if(!name.compare(it->get_name()))
        {
            std::cerr << "Removed Player: " << it->get_name() << std::endl;
            _players.erase(it);
            return true;
        }
    }
    std::cerr << "Could not find Player " << name << std::endl;
    return false;
}

bool Memory::remove_player(int index)
{

    if(_players.empty())
    {
        std::cerr << "Could not remove Player because Player list is empty" << std::endl;
        return false;
    }
    std::cerr << "Removed Player: " << _players.at(index).get_name() << std::endl;
    _players.erase(_players.begin()+index);
    return true;
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

int Memory::_get_num_files(std::string folder_path, std::string file_extension)
{
    DIR *dir;
    struct dirent *ent;
    int tmp = 0;
    std::string file;

    if ((dir = opendir (folder_path.c_str())) == NULL)
    {
        std::cerr << "Error: Folder " << folder_path << " does not exist!" << std::endl;
        return 0;
    }
    while ((ent = readdir(dir)) != NULL)
    {
        //Check if the fileextension matches with the given folder (like txt or svg)
        file = ent->d_name;
        if(file.find(file_extension) != std::string::npos)
        {
            tmp++;
        }
    }
    if(!tmp)
    {
        std::cerr << "Error: Folder " << folder_path << " is empty!" << std::endl;
    }
    return tmp;
}

int *Memory::_unique_numbers(int array_size, int min, int max)
{
    //Set time for randomizing
    srand((unsigned)time(0));
    int range = (max-min)+1;
    int number;
    int *array = new int [array_size];
    for(int c=0; c< array_size; c++)
        array[c] = 0;

    for(int i=0; i< array_size; i++)
    {
        do{
            number = (rand()% max) +1;
        }
        while(_check_number(array, array_size, number));
        array[i] = number;
    }
    return array;
}

bool Memory::_check_number(int *array, int array_size, int number)
{
    //Returns false if the number is not in the array
    for(int i=0; i < array_size; i++)
    {
        if(array[i] == number)
            return true;
    }
    return false;
}
std::string *Memory::_shuffle_array(std::string *array, int array_size)
{
    for(int i=0;i<array_size-1; i++)
    {
        int c = i +(rand() % (array_size-i));
        //Swap values
        std::string tmp = array[i];
        array[i] = array[c];
        array[c] = tmp;
    }
    return array;
}
