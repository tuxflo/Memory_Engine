#ifndef CARD_H
#define CARD_H
#include <string>
//Base Card class
class Card
{
public:
    Card();
    Card(std::string filename, int id);
    //Filename for the card item (./Pictures/txt/1.txt)
    void set_filename(std::string filename);
    std::string get_filename();

    //ID is used for identifying the cards (not the filename because different files can have the same ID)
    void set_ID(int id);
    int get_ID();

    //Is the card turned or not
    void set_turned(bool turned);
    bool get_turned();

    //Each card has points, start value is 100
    void decrease_points();
    int get_points();
protected:

private:
    std::string _filename;
    int _ID;
    bool _turned;
    int _points;
};

#endif // CARD_H
