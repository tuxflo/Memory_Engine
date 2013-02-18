#include "include/card.h"

Card::Card() :
    _turned(false),
    _points(100)
{
}

Card::Card(std::string filename, int id) :
    _filename(filename),
    _ID(id),
    _turned(false),
    _points(100)
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

void Card::set_turned(bool turned)
{
    _turned = turned;
}

bool Card::get_turned()
{
    return _turned;
}

void Card::decrease_points()
{
    //For each "wrong" turn the points decrease by 10
    _points -= 10;
}

int Card::get_points()
{
    return _points;
}
