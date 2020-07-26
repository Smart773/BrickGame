#include <iostream>
#include <conio.h>
#include "ScreenEdit.cpp"
using namespace std;
class Bar
{
private:
    int location[2];
    bool collide;
    string bar;
    string wipe;
public:
    Bar(){
        location[0]=XX/2;    
        location[1]=YY-2;
        bar="##########";    
        wipe="          ";    
    }

    void genrateBar(){
        gotoxy(location[0],location[1]);
        cout<<bar;
    }
        void move(int p){
        if(0<=location[0]+p && (XX-10)>=location[0]+p){
        gotoxy(location[0],location[1]);
        cout<<wipe;
        location[0]+=p;
        gotoxy(location[0],location[1]);
        cout<<bar;
        }

        }
    void control(){
        if(kbhit())
        switch (getch())
        {
        case 'a':
        case 'A':
            //move left .....
            move(-1);
            break;
        case 'd':
        case 'D':
            move(+1);
            //move Right .....
            break;
        default:
            break;
        }
    }

};



