#include <iostream>
#include <string> // for string class
using namespace std;


class player{
    string name;
    int id;
    int position;
    public:
    player(string name_,int id_)
    {
        name = name_;
        id = id_;
        position =0;
    }

    void set_pos(int pos)
    {
        position = pos;
    }
    int get_pos()
    {
        return position;
    }
    int get_id()
    {
        return id;
    }
    string get_name()
    {
        return name;
    }

};
