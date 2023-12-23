#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    srand(time(0));
    int x = rand()%9;
    string grade;
    if (x == 0)
        grade = "A";
    else if (x == 1)
        grade ="B+";
    else if (x == 2)
        grade ="B";
    else if (x == 3)
        grade ="C+";
    else if (x == 4)
        grade ="C";
    else if (x == 5)
        grade ="D+";
    else if (x == 6)
        grade ="D";
    else if (x == 7)
        grade ="F";
    else
        grade ="W";
    
    cout << "Press Enter 3 times to reveal your future. \n";
    cin.get(); 
    cin.get(); 
    cin.get();
    cout << "You will get " << grade << " in this 261102.";

    return 0;
}

