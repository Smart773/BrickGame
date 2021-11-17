#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include "ScreenEdit.cpp"
char wall=219;
char reverseV(char input);
char reverseH(char input);
void ScoreView();
void createWall();
void LevelClear();
void gameOVer();
using namespace std;
bool isAtoZ(string check);
int menu(string m);
void LOGO();


class Ball
{
private:
    int location[2];
    bool collide,space;
    char ball;
    char wipe;
    char move,removee,drop;
public:

    Ball(){
        location[0]=((XX-12)/2)+8;    
        location[1]=YY-4;
        ball=2;    
        move='e';
        wipe=' ';
        drop=space=false;
        
    }
    bool getspace(){return space;}
    bool getdrop(){return drop;}
    bool setspace(bool a){space=a;}
    bool setdrop(bool a){drop=a;}
    bool setrev(bool a){removee=a;}
    char getrev(){return removee;}
    void genrateball(){
        gotoxy(location[0],location[1]);
        color(6);
        cout<<ball;
        color(7);
    }
    void reset(){
        location[0]=((XX-12)/2)+8;    
        location[1]=YY-4;  
        move='e';
        drop=space=false;
    }
    void reapper(){
        gotoxy(location[0],location[1]);
        cout<<" ";
        location[0]=((XX-12)/2)+8;    
        location[1]=YY-4;
        genrateball();
    }
    
    void moveH(int p){
    if(1<=location[0]+p && (XX-1)>=location[0]+p){
    gotoxy(location[0],location[1]);
    cout<<wipe;
    location[0]+=p;
    gotoxy(location[0],location[1]);
    color(6);
    cout<<ball;
    color(7);
    }
    }


    void moveV(int p){
    if(0<=location[1]+p && (YY)>=location[1]+p){
    gotoxy(location[0],location[1]);
    cout<<wipe;
    location[1]+=p;
    gotoxy(location[0],location[1]);
    color(6);
    cout<<ball;
    color(7);
    if((YY-1)<=location[1]+p)drop=true;
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


      
        bool self(){
        char temp=move;
        if(kbhit())
        switch (getch())
        {
        case '4':
            //move left .....
            move='a';
            moveH(-1);
        return false;
            break;
        case '6':
            move='d';
            moveH(+1);
            //move Right .....
        return false;
            break;
        case '8':
            move='w';
            //move up .....
            moveV(-1);
        return false;
            break;
        case '2':
            move='s';
            moveV(+1);
            //move Down .....
        return false;
            break;

        case '7':
            //move left and up .....
            move='q';
            moveH(-1);
            moveV(-1);
        return false;
            break;
        case '9':
            move='e';
            moveH(+1);
            moveV(-1);
            //move Right and up .....
        return false;
            break;
        case '1':
            //move left and down.....
            move='z';
            moveV(+1);
            moveH(-1);
        return false;
            break;
        case '3':
            move='c';
            moveV(+1);
            moveH(+1);
        return false;
            //move Down and right .....
            break;
        case '*':
        return true;
        default:
            move=temp;
        return false;
            break;
        }
    }

        bool isObject(int p){
            gotoxy(location[0],location[1]+p);
            if(getCursorChar()==-37||getCursorChar()==-78)return true;

            gotoxy(location[0]+p,location[1]+p);
            if(getCursorChar()==-37||getCursorChar()==-78)return true;

            gotoxy(location[0]+(p*-1),location[1]+p);
            if(getCursorChar()==-37||getCursorChar()==-78)return true;

            gotoxy(location[0]+p,location[1]);
            if(getCursorChar()==-37||getCursorChar()==-78)return true;

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
                removee=true;
            return;
            };
            gotoxy(location[0]+p,location[1]+p);
            if(getCursorChar()==-37){
                for(int i=1;getCursorChar()==-37;i++){
                cout<<" ";
                gotoxy(location[0]+p+i,location[1]+p);
                }
                gotoxy(location[0]+p-1,location[1]+p);
                for(int i=-2;getCursorChar()==-37;i--){
                cout<<" ";
                gotoxy(location[0]+p+i,location[1]+p);
                }
                removee=true;
                return;
            }

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
                removee=true;
                return;
            }

           

        }



        bool collideV(int p){
                if(((1<=location[0]+p && (XX-1)>=location[0]+p)&&(2==location[1]+p||(YY)==location[1]+p))||(isObject(p)))return true;
                return false;
        }

        bool collideH(int p){
                if(((3<=location[1]+p && (YY)>=location[1]+p)&&(1==location[0]+p||(XX-1)==location[0]+p))||(isObject(p)))return true;
                return false;
        }
        
        bool barcount(int p){
            int left,right;
            left=right=0;
            gotoxy(location[0],location[1]+p);
            if(getCursorChar()==-78){
                for(int i=1;getCursorChar()==-78;i++){
                right++;
                gotoxy(location[0]+i,location[1]+p);
                }
                gotoxy(location[0]-1,location[1]+p);
                for(int i=-2;getCursorChar()==-78;i--){
                left++;
                gotoxy(location[0]+i,location[1]+p);
                }
            if(left==right)move='a';
            else if(left<right)move='e';
            else if(left>right)move='q';
                return true;
            }
            return false;

        }


        char moveFreely(){
            if(space){if(collideV(+1)){
              if(barcount(+1))goto checkpoint;
              move=reverseV(move); remove(+1);
            }
            else if(collideV(-1)){
                if(barcount(+1))goto checkpoint;
                move=reverseV(move); remove(-1);
            }
            else if(collideH(+1)){
                if(barcount(+1))goto checkpoint;
                move=reverseH(move); remove(+1);  
            }
            else if(collideH(-1)){
                if(barcount(+1))goto checkpoint;
                move=reverseH(move); remove(-1);  
            }
            checkpoint:
            control(move);

            Sleep(100);
            }

        }

};


class Bar
{
private:
    int location[2];
    bool collide,cont,leave;
    string bar;
    string wipe;
public:
    Bar(){
        location[0]=(XX-12)/2;    
        location[1]=YY-3;
        bar="################";
        for (int i = 0; bar[i]!='\0'; i++)
        bar[i]=178;
            
        wipe="                ";  

        cont=true;  
        leave=false; 
    }
    void reset(){
         location[0]=(XX-12)/2;    
        location[1]=YY-3;
       
        cont=true; 
        leave=false; 
    }
    bool getcont(){return cont;}
    bool getleave(){return leave;}
    void setcont(bool a){ cont=a;}
    void genrateBar(){
        gotoxy(location[0],location[1]);
    color(4);
        cout<<bar;
    color(7);
    }

    void reapper(){
        gotoxy(location[0],location[1]);
        cout<<"                ";
        location[0]=(XX-12)/2;    
        location[1]=YY-3;
        genrateBar();
    } 
    
    void move(int p){
    if(1<=location[0]+p && (XX-17)>=location[0]+p){
    gotoxy(location[0],location[1]);
    cout<<wipe;
    if(1<=location[0]+p+p+p && (XX-17)>=location[0]+p+p+p)
    location[0]+=(p+p+p);
    else location[0]+=(p);
    gotoxy(location[0],location[1]);
    color(4);
    cout<<bar;
    color(7);
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
        case '/':
            cont=false;
            break;
        case 27:
            leave=true;
            break;
        default:
            break;
        }
    }

};

class Wall{
    private:
    int location[2];
    int wall[8]; 
    int count;
    string levelFile,level;
    public:
    Wall(){
        for (int  i = 0; i < 8; i++)wall[i]=219;
        count=0;
        level="1";
        levelFile="lvl";
        levelFile=levelFile+level+".txt";
    }

    int getcount(){return count;}
    void setWallLevel(string l ){level=l;}
    void genrateWall(){
        int jj=6;
        ifstream in(levelFile.c_str(),ios::in);
        in>>count;
        while (in>>location[0]>>location[1])
        {
            gotoxy(location[0],location[1]);
            for (int  i = 0; i < 8; i++)
            {
                color(jj);
                cout<<(char)wall[i];
            
            }
                color(7);
            if(jj==6)jj=7;
            else jj=6;
            cout<<"  ";
        }
        
        in.close();
    }
    void UpdateLevel(){
        level[0]++;
        levelFile="lvl";
        levelFile=levelFile+level+".txt";
        cout<<levelFile;
    }

};

class status{
    private:
        int level;
        int life;
        int Score;
        int breaked;
    public:
    status(){
        level=1;
        life=3;
        Score=breaked=0;
    }
    void reset(){
        life=3;
        Score=breaked=0;
    }

        int getlevel(){return level;}
        int getlife(){return life;}
        int getScore(){return Score;}
        int getbreaked(){return breaked;}

        void setlevel(int a){ level=a;}
        void setlife(int a){ life=a;}
        void setScore(int a){ Score=a;}
        void setbreaked(int a){ breaked=a;}


        
    void ScoreView(){
        gotoxy(2,0);
        cout<<"Score:"<<Score;
        gotoxy(30,0);
        cout<<"level "<<level;
        gotoxy(60,0);
        cout<<"life= % % % ";
        gotoxy(95,0);
        cout<<"WallBreaked= "<<breaked;
        gotoxy(0,1);
        for (int i = 0; i < 115; i++)cout<<wall;
    }

    void updateLife(){
    int a=life*2;
    gotoxy(64+a,0);
    cout<<" ";
    life--;
    }

    void updateScore(){
        for (int  i = 0; i < 10; i++){
        gotoxy(8,0);
            
            cout<<++Score;}

    }

    void updatewall(){
        gotoxy(108,0);
        cout<<++breaked;
    }

};

struct player{
    string name;
    int level;
    int score;
    player* adrs;
};

class playerlist{
    private: 
    player *head ,*next, *cur; 
    public:
    playerlist(){
        ofstream out("playerScore.txt",ios::app);
        out.close();
        head=next=cur=NULL;
    }

        void SortAccendingLibrary()
		{
			player *temp,*temp2;
			temp=new player;
			temp2=new player;
			cur=head;
			
            while(cur!=NULL)
			{
				temp=cur->adrs;
				while(temp!=NULL)
				{
					if(cur->score<temp->score)
					{
						temp2->score=cur->score;
						temp2->level=cur->level;
						temp2->name=cur->name;

						cur->score=temp->score;
						cur->level=temp->level;
						cur->name=temp->name;
						
                        temp->score=temp2->score;
						temp->level=temp2->level;
						temp->name=temp2->name;
                        
					}
					temp=temp->adrs;
				}
				cur=cur->adrs;
				}
		}





    void writeFile(){
        cout<<"hereh";
        ofstream out("playerScore.txt",ios::out);
        if(head!=NULL){
            SortAccendingLibrary();
			cur=head;
			for(;cur!=NULL;){
				out<<cur->level<<" ";
				out<<cur->score<<" ";
				out<<cur->name<<"\n";
				cur=cur->adrs;
			}
			}
        out.close();
    }

    void readfile(){
        int s,l;
        string n;
        head=NULL;
        ifstream in("playerScore.txt",ios::in);
        if(in.is_open()){
			while(in>>l>>s>>n){
				if(head==NULL){
					head= new player;
					head->score=s;
					head->name=n;
					head->level=l;

					head->adrs=NULL;
					cur=next=head;
				}
				else{
					next= new player;
					next->score=s;
					next->name=n;
					next->level=l;

					cur->adrs=next;
					next->adrs=NULL;
					cur=next;
				}
			}
		}
        in.close();

    }

    void printRecord(int level){
        readfile();
        if(head!=NULL)
        {
            cur=head;
            cout<<"\n\t\t\tl E V E L  "<<level ;
            color(6);
            cout<<"     ------------------------R E C O O R D\n";
            color(7);
            for(int i=0,j=0;cur!=NULL;i++){
            if(cur->level==level)
            {gotoxy(15,3+j);
            cout<<cur->name;
            gotoxy(15+20,3+j);
            cout<<"....................L E V E L ";
            color(6);
            cout<<level;
            color(7);
            cout<<" ................... "<<cur->score<<endl;
            j++;
		    }
            cur=cur->adrs;
	        }
        }
        else {
            cout<<"no record to Show";
        }
    }

    void getrecord(int level,int Score){
     system("cls");
      string a;
      readfile();
      if(head!=NULL){
	  	cur=head;
		while(cur->adrs!=NULL)cur=cur->adrs;
	  }
	  next= new player;
	  next->level=level;
	  next->score=Score;
	  next->adrs=NULL;
      if(head==NULL)head=next;
	  else cur->adrs=next;
	  
        gotoxy((XX/2-15),4);
        cout<<"---------------|  "<<level<<"  |-----------------";
        gotoxy((XX/2-15),5);
	    color(6);
        cout<< "________________________________________";
        gotoxy((XX/2-15),6);
	    cout<< "______________L e v e l_________________";
	    color(7);

        gotoxy((XX/2-15),9);
        cout<<"---------------|  "<<Score<<"  |-----------------";
	    color(6);
        gotoxy((XX/2-15),10);
	    cout<< "________________________________________";
        gotoxy((XX/2-15),11);
	    cout<< "______________S c o r e_________________";
        gotoxy((XX/2-15),15);
	    color(7);
	    
            int i=0;
        do{
            gotoxy((XX/2-15),15+i);
					cout<<"Enter Name: ";
					cin >>next->name;
                    i++;
					if(!isAtoZ(next->name))
            {gotoxy((XX/2-12),15+i);
                    cout<<"re-";}
	    }while(!isAtoZ(next->name));
        
        writeFile();
        system("pause");
        system("cls");
        // cout<< "________________________________________";
	    // cout<< "________________N a m e_________________";




    }






};



int main(){
    
    Wall w; 
    Bar b1;
    Ball b;
    status s;
    playerlist p;
    bool flag=false;
    char temp;
    SetWindow(XX,YY);
    // p.getrecord(1,555);

C:
while(true){
    system("cls");

    switch (menu("START Check-Scores Exit "))
    {
    case '1':
        
    A:
    system("cls");
    SetWindow(XX,YY);
     s.ScoreView();
     w.genrateWall();
     b1.genrateBar();
     b.genrateball();
    while (1)
    {
        if(!b.getspace()&&kbhit()){
        if(getch()==32)b.setspace(true);}
        b.moveFreely();
        if(b.getspace())
        if(b1.getcont())
        b1.control();
        if(!b1.getcont())
        b1.setcont(b.self());
        if(b1.getleave()){
            s.reset();
            b1.reset();
            b.reset();
            goto C;
        }

        if(b.getdrop()){
          b.setspace(false);
          b.setdrop(false);
          b.reapper();
          b1.reapper();
          s.updateLife();
        }

        if(b.getrev()){
            s.updatewall();
            s.updateScore();
            b.setrev(false);
        }

        if(s.getlife()<=0){
            //game over
            gameOVer();
            flag=false;
            p.getrecord(s.getlevel(),s.getScore());
            p.printRecord(s.getlevel());
            s.reset();
            b1.reset();
            b.reset();
            break;
        }

        if(w.getcount()==s.getbreaked()){
            // level cleared
            LevelClear();
            flag=true;
            p.getrecord(s.getlevel(),s.getScore());
            p.printRecord(s.getlevel());
            w.UpdateLevel();
            s.reset();
            b1.reset();
            b.reset();
            if(s.getlevel()==5){
            s.setlevel(1);
             w.setWallLevel("1");
             goto C;
            }
            else
            s.setlevel(s.getlevel()+1);
            break;

        }


    }

    system("pause");
    system("cls");

    if(flag)temp=menu("NextLEVEL GOBACKtoMENU ");
    else if(!flag)temp=menu("RE-PLay GOBACKtoMENU ");
    if(temp!='2')goto A ;
    


        break;

    case '2':
            while(1){
            system("cls");

            switch (menu("Level#1 Level#2 Level#3 Level#4 Level#5 GotoBACKMenu "))
            {
            case '1':
            p.printRecord(1);
                break;
            case '2':
            p.printRecord(2);
                break;
            case '3':
            p.printRecord(3);
                break;
            case '4':
            p.printRecord(4);
                break;
            case '5':
            p.printRecord(5);
                break;
            case '6':
                goto B;
                break;
            
            default:
                cout<<"invalid input\n";
                break;
            }
           system("pause");
           if(0)B: break;
            
                }
        break;
    case '3':
            exit(0);
        // Quit
        break;
    
    default:
        cout<<"Invalid INput";
        break;
    system("pause");
    }
}
  
    return(0);
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

bool isAtoZ(string check){

    for ( int i =0 ; check[i]!='\0'; i++)if((!(check[i]>='A'&&check[i]<='Z'))&&(!(check[i]>='a'&&check[i]<='z'))) return false;
    return true;
}

    void gameOVer(){
        system("cls");
        gotoxy((XX/2)-10,7);
        cout<<"G A M E   O V E R";
        gotoxy((XX/2)-10,10);
        system("pause");
        system("cls");
    }
    void LevelClear(){
        system("cls");
        gotoxy((XX/2)-10,7);
        cout<<"S t a g e  C l e a r";
        gotoxy((XX/2)-10,10);
        system("pause");
        system("cls");
    }



int menu(string m){
    int count=0;
    string point="->";
    string wipe ="  ";
    char c;
    int curr=0,pre;
    LOGO();
    for (int i = 0;m[i]!='\0'; i++)if(m[i]==' ')count++;
    string menuu[count];
    int X,Y;
    X=((XX/2)-7);
    Y=17;
       int j=0;
        for (int i = 0; i < count; i++){
            gotoxy(X,Y+i+i);
            for (; m[j]!=' '; j++)cout<<m[j]<<" ";
            j++;
        }
        j=0;
        for (int i = 0; i < count; i++){
            for (; m[j]!=' '; j++){
                menuu[i]=menuu[i]+m[j]+" ";
            }
            j++;
        }
    while(true){
        gotoxy(X,Y+curr+curr);
        color(6);
        cout<<menuu[curr];
        color(7);
        pre=curr;
       do{
            c=getch();
        }while(c!='w'&&c!='s'&&c!=13);
            
            if(c=='W'||c=='w')
            {if(curr==0) curr=count-2;
            else curr=curr-2;}
            else if(c=='s'||c=='S');
            {if(curr==count-1) curr=0;
            else curr++;}
        if(c==13){
            system("cls");
            return pre+49;}
        gotoxy(X,Y+pre+pre);
        cout<<menuu[pre];

    }
    



}


    void LOGO(){
        char W=219;
       cout<<" "<<W<<W<<W<<W<<W<<W<<"     "<<W<<W<<W<<W<<W<<W<<"     "<<W<<W<<W<<W<<W<<"      "<<W<<W<<W<<W<<W<<"      "<<W<<"     "<<W<<"  \n";
       cout<<" "<<W<<"     "<<W<<"    "<<W<<"     "<<W<<"      "<<W<<"       "<<W<<"           "<<W<<"   "<<W<<"    \n";
       cout<<" "<<W<<W<<W<<W<<W<<W<<"     "<<W<<W<<W<<W<<W<<W<<"       "<<W<<"      "<<W<<"            "<<W<<" "<<W<<"      \n";
       cout<<" "<<W<<"     "<<W<<"    "<<W<<"   "<<W<<"        "<<W<<"       "<<W<<"           "<<W<<"   "<<W<<"    \n";
       cout<<" "<<W<<W<<W<<W<<W<<W<<"     "<<W<<"    "<<W<<"     "<<W<<W<<W<<W<<W<<"      "<<W<<W<<W<<W<<W<<"      "<<W<<"     "<<W<<"  \n\n\n";

        color(6);

        cout<<"\t\t\t\t\t     "<<W<<W<<W<<W<<W<<W<<"   "<<W<<W<<W<<W<<W<<W<<"   "<<W<<W<<W<<W<<W<<W<<"   "<<W<<W<<W<<W<<W<<W<<W<<"   "<<W<<"     "<<W<<"  "<<W<<W<<W<<W<<W<<W<<"   "<<W<<W<<W<<W<<W<<W<<" \n";
        cout<<"\t\t\t\t\t     "<<W<<"     "<<W<<"  "<<W<<"     "<<W<<"  "<<W<<"        "<<W<<"     "<<W<<"   "<<W<<"   "<<W<<"    "<<W<<"        "<<W<<"     "<<W<<" \n";
        cout<<"\t\t\t\t\t     "<<W<<W<<W<<W<<W<<W<<"   "<<W<<W<<W<<W<<W<<W<<"   "<<W<<W<<W<<W<<W<<W<<"   "<<W<<W<<W<<W<<W<<W<<W<<"   "<<W<<" "<<W<<"      "<<W<<W<<W<<W<<W<<W<<"   "<<W<<W<<W<<W<<W<<W<<" \n";
        cout<<"\t\t\t\t\t     "<<W<<"     "<<W<<"  "<<W<<"   "<<W<<"    "<<W<<"        "<<W<<"     "<<W<<"   "<<W<<"   "<<W<<"    "<<W<<"        "<<W<<"   "<<W<<"  \n";
        cout<<"\t\t\t\t\t     "<<W<<W<<W<<W<<W<<W<<"   "<<W<<"    "<<W<<"   "<<W<<W<<W<<W<<W<<W<<"   "<<W<<"     "<<W<<"   "<<W<<"     "<<W<<"  "<<W<<W<<W<<W<<W<<W<<"   "<<W<<"    "<<W<<" \n";

        color(7);

    }


		        //  "-------|						|-------"
	            //  "________________________________________"




