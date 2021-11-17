#include<iostream>
#include<conio.h>
#include"ScreenEdit.cpp"
using namespace std;
int menu(string m);
int main(){
    SetWindow(XX,YY);
    menu("start list menu start list menu ");
    system("pause");
    return 0;
}
int menu(string m){
    int count=0;
    string point="->";
    string wipe ="  ";
    char c;
    int curr=0,pre;
    for (int i = 0;m[i]!='\0'; i++)if(m[i]==' ')count++;
    string menuu[count];
    int X,Y;
    X=((XX/2)-5);
    Y=15-count;
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
