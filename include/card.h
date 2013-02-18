#ifndef CARD_H
#define CARD_H
#include <string>
//Base Card class
class Card
{
public:
    Card();
    Card(std::string filename, int id);
protected:
    //Filename for the card item (./Pictures/txt/1.txt)
    void set_filename(std::string filename);
    std::string get_filename();

    //ID is used for identifying the cards (not the filename because different files can have the same ID)
    void set_ID(int id);
    int get_ID();
private:
    std::string _filename;
    int _ID;
};

#endif // CARD_H
