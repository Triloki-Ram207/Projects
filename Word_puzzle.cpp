#include<iostream>
#include<vector>
#include<string>
#include<algorithm>   //random_shuffle
#include<cstdlib>    //srand()
#include<ctime>
#include<iterator>   //iterator
#include<conio.h>    //getch()
using namespace std;

int print_puzzle_question(string word,int score);    //declaration of function

template< class T>

void shuffles(vector<T>&v)       // making this function a template for different data types
{

    random_shuffle(v.begin(),v.end());    // calling random_shuffle() function
}

string upr(string wd)                    // converting a string into uppercase
{
    for(int i=0;i<wd.length();i++)
    {
        if(wd[i]>='a' && wd[i]<='z')
            {
                wd[i]=wd[i]-32;

            }
    }
    return wd;
}

string shuffle_word(string word)   // To shuffle letters of a word
{
    vector<char>v;
    for(int i=0;i<word.length();i++)
    {
        v.push_back(word[i]);
    }
    shuffles<char>(v);             //calling shuffles()
    word="";
    for(int i=0;i<v.size();i++)
    {
        word.push_back(v[i]);
    }
    return word;
}

int print_puzzle_question(string word,int score,string name)       // function that will show the jumbled/shuffled word to user
{                                                      // and take his/her answer and check it
    system("cls");
    string problem_word=shuffle_word(word);
    cout<<" WORD PUZZLE "<<endl;
    cout<<"-------------"<<endl;
    name=upr(name);
    cout<<"Player Name:"<<name<<endl<<endl;
    cout<<"Arrange the letters to form a valid word:"<<endl<<endl;

    cout<<"The letters are: "<<problem_word<<"   ";

    string user_word;
    cout<<"Type your answer: ";
    cin>>user_word;
    if(word.compare(upr(user_word))==0)  //comparing user's entered word with original word
    {
        cout<<endl<<"Correct answer"<<endl;
        score++;                        //incrementing score if word formed correctly
    }
    else
    {
        cout<<endl<<"Wrong answer"<<endl;
        score--;                        //decrementing score if word formed wrong
    }
    cout<<endl<<"Press 'N' or 'n' to see the next jumble word"<<endl<<endl;
    cout<<"                      OR                      "<<endl;
    cout<<endl<<"Press 'E' or 'e' to exit the game           "<<endl;
    return score;
}

int main()
{
    string name;
    cout<<"Enter your name:";
    getline(cin,name);
    int score=0;                        // To store score of user
    srand(time(NULL));                  //for random number generator
    vector<string>v;                    // creating vector
    v.push_back("FATHER");              // pushing values into vector
    v.push_back("BREAK");
    v.push_back("COUNTRY");
    v.push_back("BEAUTY");
    v.push_back("ALONE");
    vector<string>::iterator it;        // iterator to iterate over vector

    shuffles<string>(v);                //calling shuffles() function to shuffle the vector's elements

    for(int i=0;i<v.size();i++)        // passing the strings one by one
    {
        score=print_puzzle_question(v[i],score,name);
        char ch=getch();
        if('e'==ch || 'E'==ch)                    //breaking the loop if the user wants to exit
            break;
    }
    cout<<endl<<"Game Over "<<endl<<"Score:"<<score<<endl;            //showing Score of the User
    return 0;
}
