#include <iostream>
#include <conio.h>
#include "ScreenEdit.cpp"
using namespace std;
char reverseV(char input);
char reverseH(char input);
char wall=219;
void ScoreView()
{
    gotoxy(2,0);
    cout<<"Score:0";
    gotoxy(50,0);
    cout<<"life= % % % ";
    gotoxy(95,0);
    cout<<"WallBreaked= 000 ";
    gotoxy(0,1);
    for (int i = 0; i < 115; i++)cout<<(char)220;

}
void createWall(){
    int x=5;
    int y=3;
        for (int  i = 0; i < 6; i=i+2)
        {
        gotoxy(x,y);
            for (int j = 0; j < 9; j++)
            {
                cout<<wall<<wall<<wall<<wall<<wall<<wall<<wall<<wall<<"   ";
            }
            y++;
            y++;
            y++;
            y++;
            y++;
            y++;
        }
}
class Ball
{
private:
    int location[2];
    bool collide,space;
    char ball;
    char wipe;
    char move,fixed;
public:
    Ball(){
        location[0]=((XX-12)/2)+8;    
        location[1]=YY-4;
        ball=2;    
        move='e';
        wipe='\0';
        space=false;
    }
    bool getspace(){return space;}
    bool setspace(bool a){space=a;}

    void genrateball(){
        gotoxy(location[0],location[1]);
        cout<<ball;
    }
    
    void moveH(int p){
    if(0<=location[0]+p && (XX)>=location[0]+p){
    gotoxy(location[0],location[1]);
    cout<<wipe;
    location[0]+=p;
    gotoxy(location[0],location[1]);
    cout<<ball;
    }
    }
    void moveFIX(int p){
    if(8<=location[0]+p && (XX-(16+4))>=location[0]+p){
    gotoxy(location[0],location[1]);
    cout<<wipe;
    location[0]+=p;
    gotoxy(location[0],location[1]);
    cout<<ball<<"here";
    }
    }
    void moveV(int p){
    if(0<=location[1]+p && (YY)>=location[1]+p){
    gotoxy(location[0],location[1]);
    cout<<wipe;
    location[1]+=p;
    gotoxy(location[0],location[1]);
    cout<<ball;
    }
    }

       

    void control(char z){
        switch (z)
        {
        case 'a':
        case 'A':
            //move left .....
            moveH(-1);
            break;
        case 'd':
        case 'D':
            moveH(+1);
            //move Right .....
            break;
        case 'w':
        case 'W':
            //move up .....
            moveV(-1);
            break;
        case 's':
        case 'S':
            moveV(+1);
            //move Down .....
            break;

        case 'q':
        case 'Q':
            //move left and up .....
            moveH(-1);
            moveV(-1);
            break;
        case 'e':
        case 'E':
            moveH(+1);
            moveV(-1);
            //move Right and up .....
            break;
        case 'Z':
        case 'z':
            //move left and down.....
            moveV(+1);
            moveH(-1);
            break;
        case 'c':
        case 'C':
            moveV(+1);
            moveH(+1);
            //move Down and right .....
            break;
        default:
            break;
        }
    }


        void self(){
        char temp=move;
        if(kbhit())
        switch (move=getch())
        {
        case 'a':
        case 'A':
            //move left .....
            moveH(-1);
            break;
        case 'd':
        case 'D':
            moveH(+1);
            //move Right .....
            break;
        case 'w':
        case 'W':
            //move up .....
            moveV(-1);
            break;
        case 's':
        case 'S':
            moveV(+1);
            //move Down .....
            break;

        case 'q':
        case 'Q':
            //move left and up .....
            moveH(-1);
            moveV(-1);
            break;
        case 'e':
        case 'E':
            moveH(+1);
            moveV(-1);
            //move Right and up .....
            break;
        case 'Z':
        case 'z':
            //move left and down.....
            moveV(+1);
            moveH(-1);
            break;
        case 'c':
        case 'C':
            moveV(+1);
            moveH(+1);
            //move Down and right .....
            break;
        default:
            move=temp;
            break;
        }
    }

        bool isObject(int p){
            gotoxy(location[0],location[1]+p);
            if(getCursorChar()==-37)return true;

            gotoxy(location[0]+p,location[1]+p);
            if(getCursorChar()==-37)return true;

            gotoxy(location[0]+(p*-1),location[1]+p);
            if(getCursorChar()==-37)return true;

            gotoxy(location[0]+p,location[1]);
            if(getCursorChar()==-37)return true;

            return false;
        }

        void remove(int p){
            gotoxy(location[0]+p,location[1]);
            if(getCursorChar()==-37){
                for(int i=1*p;getCursorChar()==-37;){
                cout<<" ";
                gotoxy(location[0]+p+i,location[1]);
                if(1+p==0)i--;
                else i++;

                }
            return;
            };
            gotoxy(location[0],location[1]+p);
            if(getCursorChar()==-37){
                for(int i=1;getCursorChar()==-37;i++){
                cout<<" ";
                gotoxy(location[0]+i,location[1]+p);
                }
                gotoxy(location[0]-1,location[1]+p);
                for(int i=-2;getCursorChar()==-37;i--){
                cout<<" ";
                gotoxy(location[0]+i,location[1]+p);
                }
                return;
            }

           

        }



        bool collideV(int p){
                if(((0<=location[0]+p && (XX)>=location[0]+p)&&(2==location[1]+p||(YY)==location[1]+p))||(isObject(p)))return true;
                return false;
        }

        bool collideH(int p){
                if(((3<=location[1]+p && (YY)>=location[1]+p)&&(0==location[0]+p||(XX)==location[0]+p))||(isObject(p)))return true;
                return false;
        }
        void fixwithbar(){
            if(kbhit())
            switch (getch())
            {
            case 'd':
                moveFIX(+1);
                fixed='d';
                break;
            case 'a':
                moveFIX(-1);
                fixed='a';
                break;
            
            default:
                break;
            }
        }
        char moveFreely(){
            if(space){if(collideV(+1)){move=reverseV(move); remove(+1);  }
            else if(collideV(-1)){move=reverseV(move); remove(-1);  }
            else if(collideH(+1)){move=reverseH(move); remove(+1);  }
            else if(collideH(-1)){move=reverseH(move); remove(-1);  }
            
            control(move);

            Sleep(100);
            }
            else{
                fixwithbar();
            }
        }





};

int main(){
    Ball b;
    SetWindow(XX,YY);
    ScoreView();
    createWall();
    b.genrateball();
    while (1)
    {
        if(kbhit()&&!b.getspace()){
        if(getch()==32)b.setspace(true);}
        b.moveFreely();
        // b.self();


    }
    

    return 0;
}


char reverseV(char input){
    if(input=='a')return 'd';
    if(input=='d')return 'a';
    if(input=='w')return 's';
    if(input=='s')return 'w';

    if(input=='z')return 'q';
    if(input=='q')return 'z';
    if(input=='e')return 'c';
    if(input=='c')return 'e';
}

char reverseH(char input){
    if(input=='a')return 'd';
    if(input=='d')return 'a';
    if(input=='w')return 's';
    if(input=='s')return 'w';

    if(input=='z')return 'c';
    if(input=='c')return 'z';
    if(input=='e')return 'q';
    if(input=='q')return 'e';
}

