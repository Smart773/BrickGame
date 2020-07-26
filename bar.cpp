#include <iostream>
#include <conio.h>
#include "ScreenEdit.cpp"
using namespace std;
class Bar
{
private:
    int location[2];
    int move;
    bool collide;
    string bar;
    string wipe;
public:
    Bar(){
        location[0]=63;    
        location[1]=75/2;
        bar="##########";    
        wipe="          ";    
    }

    void genrateBar(){
        gotoxy(location[0],location[1]);
        cout<<bar;
    }

    void control(){
        if(kbhit())
        switch (getch())
        {
        case 'a':
        case 'A':
            //move left .....
            break;
        case 's':
        case 'S':
            //move Right .....
            break;
        default:
            break;
        }
    }

};



int main(){


    return(0);
}