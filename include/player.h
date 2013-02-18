#ifndef PLAYER_H
#define PLAYER_H
#include <string>

//Basic Player class
class Player
{
public:
    Player();
    Player(std::string name);

    void set_name(std::string name);
    std::string get_name();

    void add_points(int points);
    int get_score();
protected:

private:
    std::string _name;
    int _score;
};

#endif // PLAYER_H
