#include "include/card.h"

Card::Card()
{
}

Card::Card(std::string filename, int id) :
    _filename(filename),
    _ID(id)
{
}

void Card::set_filename(std::string filename)
{
    _filename = filename;
}

std::string Card::get_filename()
{
    return _filename;
}

void Card::set_ID(int id)
{
    _ID = id;
}

int Card::get_ID()
{
    return _ID;
}
