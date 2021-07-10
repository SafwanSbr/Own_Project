#include<bits/stdc++.h>
#include<cstdlib>
#include<time.h>

using namespace std;

char square[10] = {'o','1','2','3','4','5','6','7','8','9'};

//for display
void board()
{
    system("cls");
    system("color 0a");

    cout << "\n\n\t  Tic Tac Toe\n\n";

    cout << "     HUMAN (X)  -  COMPUTER (O)" << endl << endl;
    cout << endl;

    cout << "\t     |     |     " << endl;
    cout << "\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;

    cout << "\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "\t_____|_____|_____" << endl;
    cout << "\t     |     |     " << endl;

    cout << "\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "\t     |     |     " << endl << endl;
}

int result()
{
    if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;

}

int computerMove()
{
    for(int i=1;i<9;i++)
    {
        int x = rand()%9 + 1;
        if( square[x] != 'X' && square[x] != 'O' ) return x;
        else if ( i == 8 ) return 1;
    }
}

int main()
{
    int checkPlayer=0, choice, win;
    char mark;

    while(1)
    {

        if ( checkPlayer == 0 ) board();
        checkPlayer++;

        if(checkPlayer%2==1) {

                cout<<"Enter your choice: ";
                cin>>choice;
                mark='X';
        }

        else {
            choice = computerMove();
            mark = 'O';
        }

        //set X or Y in box
        if      (choice == 1 && square[1] == '1') square[1] = mark;
        else if (choice == 2 && square[2] == '2') square[2] = mark;
        else if (choice == 3 && square[3] == '3') square[3] = mark;
        else if (choice == 4 && square[4] == '4') square[4] = mark;
        else if (choice == 5 && square[5] == '5') square[5] = mark;
        else if (choice == 6 && square[6] == '6') square[6] = mark;
        else if (choice == 7 && square[7] == '7') square[7] = mark;
        else if (choice == 8 && square[8] == '8') square[8] = mark;
        else if (choice == 9 && square[9] == '9') square[9] = mark;

        else
        {
            cout<<"Invalid move ";
            checkPlayer--;
            cin.ignore();
            cin.get();
        }

        //show the board after input
        board();

        //check who wins
        win = result();
        if(win == 1)//if anyone wins
        {
           if(checkPlayer % 2 == 1) cout<<"CONGRATULATIONS! You WON\n";
           else cout<<"Computer WON\n";
           return 0;
        }
        else if( win == 0)
        {
            cout<<"DROW X-O ";
            return 0;
        }
    }
}
