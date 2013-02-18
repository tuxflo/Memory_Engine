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
    std::string extension = folder_path.substr(folder_path.length()-3);
    std::string cover_string = "cover";
    cover_string.append(".");
    cover_string.append(extension);
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

    //Check the subfolders
    folder_path.append("/1");
    int first = get_num_files(folder_path, extension);
    int first = _get_num_files(folder_path, extension);
    if(!first)
    {
        return false;
    }
    folder_path.replace(folder_path.length()-1, 1, "2");
    int second = get_num_files(folder_path, extension);
    int second = _get_num_files(folder_path, extension);
    if(!second)
    {
        return false;
    }
    if(first > second)
        _num_cards = second;
    else
        _num_cards = first;

    //Just for debugging
    std::cerr << "Number of cards: " <<_num_cards << std::endl;

    set_cards();
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

    _unique_numbers(rows*columns, 1, _num_cards);
    return true;
}

void Memory::set_cards()
{
    //use _num_cards array for randomizing the cards
    int *cards = new int[_num_cards];
    std::stringstream directory_name;
    std::string *array = new std::string [_num_cards];
    std::string *_cards_array = new std::string [_rows*_columns];
    int tmp = 1;
    //Fill the array in the right order
    for(int i=0; i< _num_cards; i++)
    {
        if(i == _num_cards/2)
            tmp = 1;

        cards[i] = tmp;
    }


        directory_name << tmp;
        array[i] = directory_name.str();
        directory_name.str("");
        tmp++;
    }
    array = _shuffle_array(array, _num_cards);
    for(int j=0; j< (_rows*_columns)/2; j++)
    {
        _cards_array[j] = array[j];
    }
    int bla=0;
    for(int k=(_rows*_columns)/2; k<_rows*_columns; k++)
    {

        _cards_array[k] = array[bla];
        bla++;
    }

    _cards_array = _shuffle_array(_cards_array, _rows*_columns);

    for(int l=0; l<_rows*_columns; l++)
    {
        std::cerr << _cards_array[l] << std::endl;
    }
>>>>>>> Sample_files
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

std::vector<int> *Memory::_unique_numbers(int array_size, int min, int max)
{
    srand(0);
    int range = (max-min)+1;
    int number;
    std::vector<int> array;
    for(int i=0; i< array_size; i++)
    {
        do{

            number = min+int(range*rand()/(RAND_MAX + 1.0));

        }while(std::find(array.begin(), array.end(), number)== array.end());
        array.at(i) = number;
    }
std::string *Memory::_shuffle_array(std::string *array, int array_size)
{
    //Set time for randomizing
    srand((unsigned)time(0));

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
