#include <iostream>
using namespace std;

enum rcp
{
    scissor = 1, rock, paper
};

class game
{
public:
    int comp, mine;

    game();
    game(int _my_choice);
    void getResult();
};

game::game() : comp(0), mine(0) {}

game::game(int _my_choice)
{
    comp = rand() % 3 + 1;
    mine = _my_choice;
}
void game::getResult()
{
    cout << "Computer : ";
    if(comp == 1)
        cout << "Scissor";
    else if(comp == 2)
        cout << "Rock";
    else if(comp == 3)
        cout << "Paper";

    cout << "\nYou : ";
    if(mine == 1)
        cout << "Scissor";
    else if(mine == 2)
        cout << "Rock";
    else if(mine == 3)
        cout << "Paper";
    cout << endl;
    
    if(comp == mine)
        cout << "[Draw]" << endl;
    else if((comp == 1 && mine == 3) || (comp == 2 && mine == 1) || (comp == 3 && mine == 2))
        cout << "[Loose]" << endl;
    else if((comp == 1 && mine == 2) || (comp == 2 && mine == 3) || (comp == 3 && mine == 1))
        cout << "[Win]" << endl;
}

int main()
{
    int my_choice;
    char choice;
    do
    {
        cout << "\n\n\t\t***Scissor / Rock / Paper Game***\n" << endl;
        cout << "Scissors(1) / Rock(2) / Paper(3)" << endl;
        cout << "Your Choice : ";

        cin >> my_choice;
        game g(my_choice);
        
        g.getResult();

        cout << "Play one more round?(Y/y) / Exit(Any Key) ";
        cin >> choice;
        system("read");
    }while(choice == 'Y' || choice == 'y');


    return 0;
}

