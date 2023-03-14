
#include<iostream>
#include<vector>
#include "box.cpp"
#include "player.cpp"
using namespace std;
class snak_and_ladar{

    int box_count ;
    int snak_count;
    int ladar_count;
    int players_count;
    public:
        vector<player> players;
        vector<box> boxes;
    snak_and_ladar()
    {
        box_count = 100;
        snak_count =5;
        ladar_count = 5;
        players_count =2;
    }
    void set_box_count(int x)
    {
        box_count = x;
    }
    void set_snak_count(int x )
    {
        snak_count = x;
    }
    void set_ladar_count(int x)
    {
        ladar_count = x;
    }
    void set_player_count(int x)
    {
        players_count = x;
    }
    void create_grid()
    {

        int num = 100;
        for(int i=1;i<=num;i++)
        {
             box bb(i,i);
            boxes.push_back(bb);
        }


    }
    void _set_snak(int start, int end)
    {
        boxes[start].set_snak(end);
    }
    void _set_lader(int start,int end)
    {
        boxes[start].set_ladar(end);
    }
    void get_details()
    {
        cout<<"enter_num_of_boxes     ";
        cin>>box_count;
        cout<<"enter_num_of_snaks     ";
        cin>>snak_count;
        cout<<"enter_num_of_laders    ";
        cin>>ladar_count;
        cout<<"enter_num_of_players   ";
        cin>>players_count;

         create_grid();

        cout<<endl<<endl;
        cout<<"lets initialise the snaks"<<endl;

        for(int i= 0;i<snak_count;i++)
        {
            int start =0;
            int end =0;
            cout<<"enter snak "<<i+1<<"  of "<<snak_count <<" snak start ";
            cin>>start;
            cout<<"enter snak "<<i+1<<"  of "<<snak_count<<" snak end    ";
            cin>>end;
            _set_snak(start-1,end);

        }

        cout<<endl<<endl;
        cout<<"lets initialise the lader "<<endl;

        for(int i=0;i<ladar_count;i++)
        {
            int start =0;
            int end =0;
            cout<<"enter lader "<<i+1<<"  of "<<ladar_count <<" lader start ";
            cin>>start;
            cout<<"enter lader "<<i+1<<"  of "<<ladar_count<<" lader end    ";
            cin>>end;
            _set_lader(start-1,end);
        }
        }

        void create_players(int num)
        {
            for(int i=0;i<num;i++)
            {

                string name;
                cout<<"enter_player_ "<<i+1<<" name  ";
                cin>>name;
                player play(name,i+1);
                players.push_back(play);

            }
           // players.push_back()
        }
        void print_the_grid()
        {
            cout<<endl<<endl<<endl;
            for(int i=0;i<box_count;i++)
            {
                cout<<"box num : "<<i+1;
                if(boxes[i].snak())
                 cout<<"  here there is a snak to : "<<boxes[i].snak_pos()<<endl;
                 else if(boxes[i].ladar())
                 cout<<"here there is a lader to : "<<boxes[i].lader_pos()<<endl;
                 else
                 cout<<" **************************nothing************************"<<endl;
            }
        }
       int  is_any_one_won()
        {
            for(int i=0;i<players_count;i++)
            {
                if(players[i].get_pos() == box_count)
                 {
                    cout<<endl<<"player : "<<i+1<<"  "<<players[i].get_name()<<" *****won the game******"<<endl;
                   return players[i].get_id();
                 }
                  else if (players[i].get_pos()>100)
                 {

                    cout<<endl<<"*******  **game over*************"<<endl;
                    return 1;
                 }
                else
                  return 0;
            }
        }
       void print_player_pos()
        {
            cout<<endl;
             for(int i=0;i<players_count;i++)
            {
              cout << " player "<<i+1<<"  "<< players[i].get_name()<<"   pos is : "<<players[i].get_pos()<<endl;
            }
        }

        void main_game_fun()
        {
            cout<<"************  lets start the game  **************"<<endl;
            while(! is_any_one_won())
            {
                     print_player_pos();

                     for(int i=0;i<players_count;i++)
                     {
                        int num =0;
                        int players_curent_pos =0;
                        cout<<"now player "<<i+1<<" : "<< players[i].get_name()<<" trun enter number 1to 6 ";
                        cin>>num;
                        //here use the condition check to full fill the game
                        while((num>6||num<1))
                        {
                            cout<<"please enter the num between 1 to 6 ";
                             cin>>num;

                        }
                        num-=1;
                        players_curent_pos = players[i].get_pos()+ num;
                        if(boxes[players_curent_pos].snak())
                        players_curent_pos = boxes[players_curent_pos].snak_pos();
                        else if(boxes[players_curent_pos].ladar())
                        players_curent_pos = boxes[players_curent_pos].lader_pos();
                        else
                            players_curent_pos+=1;


                        players[i].set_pos(players_curent_pos);

                     }
                 //    print_player_pos();

            }
        }



    void start_your_game()
    {
        get_details();
        create_players(players_count);
        main_game_fun();

    }

};



int main()
{
    snak_and_ladar snk;

    snk.start_your_game();
    snk.print_the_grid();

    cout<<" this is a snak game  defnetly you can buid it";

    return 0;
}

