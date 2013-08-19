#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
#include<string>
using namespace std;
int randomto(int n);
void startup();
void checkscore();
void gameplay();
void computer();
void draw();
int height[7], start=0, input, c, win, num, cf;
char *g[10][10];
string play1, play2;
int main(){
    startup();
    while(1){
        win=0;
        draw();
        checkscore();
        if(win==0){
            start=1;
            if(((num==1 && cf==0 && c%2==0)==0) && num!=0){
                cin >> input;
                gameplay();
            }
            if(num==1 || num==0){
                computer();
            }
        } else {
            cout << "Enter 1 to replay, enter 2 to restart the game, or enter 0 to exit." << endl;
            cin >> input;
            if(input==0){
                break;
            } else if(input==1){
                start=0;
            } else if(input==2){
                start=0;
                startup();
            }
        }
    }
    return 0;
}
int randomto(int n) {
return rand() % n;
}
void startup(){
    system("CLS");
    srand(time(NULL));
    cout << "Welcome to the game!  Press the number keys and ENTER to move." << endl;
    cout << "Number of players (0-2): ";
    cin >> num;
    if(num==1){
        cf=randomto(2);
        if(cf==0){
            cout << "Computer is player one (X)." << endl;
            play1 = "Computer";
            cout << "Player two (#) name: ";
            cin >> play2;
        } else {
            cout << "Computer is player two (#)." << endl;
            play2 = "Computer";
            cout << "Player one (X) name: ";
            cin >> play1;
        }
    } else if(num==2) {
        cout << "Player one (X) name: ";
        cin >> play1;
        cout << "Player two (#) name: ";
        cin >> play2;
    } else if(num==0){
        play1="Computer 1";
        play2="Computer 2";
    }
    system("PAUSE");
}
void draw(){
    system("CLS");
    cout << "1234567" << endl;
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            if(start==0){
                g[i][j]="O";
                height[j]=0;
                c=0;
            }
            cout << g[i][j];
            if(j==6){
                cout << endl;
            }
        }
    }
}
void computer(){
    if(num==1 || num==0){
        input=randomto(8);
        gameplay();
    }
}
void gameplay(){
    for(int i=0;i<7;i++){
        if(input==i+1 && height[i]<6){
            if(c%2==0){
                g[5-height[i]][i]="X";
            } else {
                g[5-height[i]][i]="#";
            }
            height[i]+=1;
            c+=1;
        }
    }

}
void checkscore(){
    for(int i=0;i<6;i++){
        for(int j=0;j<7;j++){
            if(g[i][j]==g[i][j+1] && g[i][j+1]==g[i][j+2] && g[i][j+2]==g[i][j+3] && g[i][j]!="O"){
                win=1;
            }
            if(g[i][j]==g[i+1][j] && g[i+1][j]==g[i+2][j] && g[i+2][j]==g[i+3][j] && g[i][j]!="O"){
                win=1;
            }
            if(g[i][j]==g[i+1][j+1] && g[i+1][j+1]==g[i+2][j+2] && g[i+2][j+2]==g[i+3][j+3] && g[i][j]!="O"){
                win=1;
            }
            if(g[i][j]==g[i+1][j-1] && g[i+1][j-1]==g[i+2][j-2] && g[i+2][j-2]==g[i+3][j-3] && g[i][j]!="O"){
                win=1;
            }
            if(win==1){
                if(g[i][j]=="X"){
                    cout << play1 << " won!" << endl;
                } else {
                    cout << play2 << " won!" << endl;
                }
                return;
            }
        }
    }
}
