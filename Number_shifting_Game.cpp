#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void create_matrix(int mat[][4])  //Initializing matrix randomly
{
    int n=15;
    int arr[n];
    for(int i=0;i<n;i++)    //storing 1 to 15
    {
        arr[i]=i+1;
    }
    int last_index=n-1,index;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(last_index>=0)
             {
                 index=rand()%(last_index+1);   //range 1-14
                 mat[i][j]=arr[index];
                 arr[index]=arr[last_index--];
             }
        }
    }
  mat[3][3]=0;   // last element of the matrix
}
void show_matrix(int mat[][4])  // show the matrix
{
    cout<<"---------------------"<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(mat[i][j]==0)

               cout<<"| _  ";
            else
            {
              cout<<"| "<<mat[i][j]<<" ";
              if(mat[i][j]<10)
              cout<<" ";
            }
        }
        cout<<"|";
        cout<<endl;
    }
    cout<<"---------------------";
}
void Swap(int *p,int *q)   // for swapping two elements
{
    int r=*p;
    *p=*q;
    *q=r;
}
int shift_up(int mat[][4])  // for making an upward move
{
    int i,j,flag=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(mat[i][j]==0)
                {
                    flag=1;
                    break;
                }
        }
        if(flag==1)
            break;
    }
    if(i==3)
        return 0;
    Swap(&mat[i][j],&mat[i+1][j]);
    return 1;
}
int shift_down(int mat[][4])  // for making an downward move
{
    int i,j,flag=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(mat[i][j]==0)
               {
                   flag=1;
                   break;
               }
        }
        if(flag==1)
        {
            break;
        }
    }
    if(i==0)
        return 0;
    Swap(&mat[i][j],&mat[i-1][j]);
    return 1;
}
int shift_left(int mat[][4])   // for making left move
{
    int i,j,flag=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(mat[i][j]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(j==3)
        return 0;
    Swap(&mat[i][j],&mat[i][j+1]);
    return 1;
}
int shift_right(int mat[][4])    // for making right move
{
    int i,j,flag=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(mat[i][j]==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            break;
    }
    if(j==0)
        return 0;
    Swap(&mat[i][j],&mat[i][j-1]);
    return 1;
}
int winner(int mat[][4])    //checking the winning situation
{
    int k=1,i,j,flag=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            {
             if(mat[i][j]!=k)
              {
               flag=1;
               break;
              }
              k++;
             }
        if(flag==1)
            break;
    }
    if(k==16)
        return 1;
    else
        return 0;
}
void cursor_pos()              //Just for (fun) looking good
{
    HANDLE hpos=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos={60,23};
    SetConsoleCursorPosition(hpos,pos);
}
void game_rules(int mat[][4])     //Showing the rules of the game
{
    system("color 0C");           //Providing color to texts
    cout<<"                                                     |MATRIX PUZZLE|"<<endl<<endl;
    cout<<"                                                     RULES OF THIS GAME"<<endl;
    cout<<"                                                  #-----------------------#"<<endl<<endl;
    cout<<"                                      -> You can move only 1 step at a time using key"<<endl<<endl;
    cout<<"                                      -> To move up:Press W key"<<endl<<endl;;
    cout<<"                                      -> To move down:Press S key"<<endl<<endl;;
    cout<<"                                      -> To move left:Press A key"<<endl<<endl;
    cout<<"                                      -> To move right:Press D key"<<endl<<endl;;
    cout<<"                                      -> You can move numbers at empty place only"<<endl<<endl;
    cout<<"                                      -> For each valid move:Your total number of moves will be decreased by 1"<<endl<<endl;
    cout<<"                                      -> Winning situation: Numbers in the 4*4 matrix must be in order from 1 to 15"<<endl<<endl;
    cout<<"                                      -> You can exit the game at any time by pressing 'e' or 'E'"<<endl<<endl;

    int k=1;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
             mat[i][j]=k++;
    mat[3][3]=0;
    cout<<"                                      NEXT=>Press Enter key";
    cursor_pos();
    getchar();
    system("cls");
    cout<<"Winning Situation:";
    cout<<endl;
    show_matrix(mat);

}
int read_Entered_Key()  //Taking inputted character
{
   char ch;
   cin>>ch;
   int value=static_cast<int>(ch);   //returning ascii code of inputted character
   return value;
}
int main()
{
    int mat[4][4];                     //Creating 4 x 4 matrix
    srand(time(NULL));                 // for generating random number from rand() function
    int lb=50,ub=60;
    int max_try=(rand()%(ub-lb+1))+lb; // Generating total no of moves randomly
    string name;
    cout<<"ENTER PLAYER NAME:";
    getline(cin,name);                //Taking user name
    transform(name.begin(),name.end(),name.begin(),::toupper);  // built-in function to convert a string into uppercase
    system("cls");                    // clearing the screen
    char ch;
    while(1)
    {
        int flag=0;
        game_rules(mat);
        create_matrix(mat);
        cout<<"   # Press 'ENTER' key to start:";
        cout<<getchar();
        system("cls");
        show_matrix(mat);
        int key;
        while(1)
        {
            system("cls");

            if(winner(mat)==1)
               {
                   flag=2;
                   break;
               }
            if(max_try==0)
               {
                   flag=1;
                    break;
               }
               system("color 06");
            cout<<"Player Name:"<<name<<"  Total moves:"<<max_try<<endl<<endl;
            show_matrix(mat);
            cout<<endl<<"Make your move:";
            key=read_Entered_Key();
            switch(key)
            {
                case 101: // ascii of e and E
                case 69:
                     system("cls");
                    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                                   Thank you for playing!"<<endl<<endl;
                    return 0;
                case 119: // ascii of w
                   if(shift_up(mat))
                     max_try--;
                     break;
                case 115:  // ascii of s
                    if(shift_down(mat))
                        max_try--;
                        break;
                case 97:   // ascii of a
                    if(shift_left(mat))
                        max_try--;
                        break;
                case 100:  // ascii of d
                    if(shift_right(mat))
                        max_try--;
                        break;
                default:
                    cout<<"Invalid move"<<endl;
            }
        }
        system("color 02");
        if(flag==1)                  //Checking whether user won or lost
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                                   Y O U   L O S T"<<endl<<endl;
        else if(flag==2)
           cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"                                                   Y O U    W O N"<<endl<<endl;
        cout<<"                                                 Want to play again?"<<endl<<endl;
        cout<<"                                               Enter 'y' or 'Y' to play"<<endl<<endl;
        cout<<"                                                          OR"<<endl<<endl;
        cout<<"                                               Enter 'n' or 'N' to exit"<<endl;
        cin.ignore();
        cursor_pos();
        cin>>ch;
        cin.ignore();
        if(ch!='y' && ch!='Y')
           {
             break;
           }
           system("cls");
        max_try=(rand()%(ub-lb+1))+lb;
    }
    return 0;
}
