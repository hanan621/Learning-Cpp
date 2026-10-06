#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enGameChoice { stone = 1, paper = 2, Scissors = 3 };
enum enWinner { player1 = 1, computer = 2, Draw = 3 };

struct stRoundInfo
{
    short RandomNumber = 0;
    enGameChoice player1Choice;
    enGameChoice  computerChoice;
    enWinner Winner;
    string WinnerName;
};

struct stGameResult
{
    short GameRound = 0;
    short Player1WinTime = 0;          
    short ComputerWinTime = 0;
    short DrawTime = 0;
    enWinner GameWinner ;
    string WinnerName = "";
};

int RandomNumber(int From, int To)
{
    int randnum = rand() % (To - From + 1) + From;
    return randnum;

}

string winnerName(enWinner winner)
{
    string arrwinnerName[3] = { "player1","computer","No winner (Draw)" };
    return arrwinnerName[winner - 1];
}

string ChoiceName(enGameChoice choice)
{
    string arrGameChoice[3] = { " Stone","Paper","Scissors" };
    return arrGameChoice[choice - 1];
} 

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.player1Choice == RoundInfo.computerChoice)
        return enWinner::Draw;

    switch (RoundInfo.player1Choice)
    {
    case enGameChoice::stone:

        if (RoundInfo.computerChoice == enGameChoice::paper)
        {
            return enWinner::computer;
        }
        break;

    case enGameChoice::paper:
        if (RoundInfo.computerChoice == enGameChoice::Scissors)
        {
            return enWinner::computer;
        }
        break;

    case enGameChoice::Scissors:
        if (RoundInfo.computerChoice == enGameChoice::stone)
        {
            return enWinner::computer;
        }
        break;
    }
    return enWinner::player1;
}

enWinner WhoWonTheGame(short player1WonTime,short computerWonTimee )
{
    if (player1WonTime > computerWonTimee)
    {
        return enWinner::player1;
    }   
    else if (computerWonTimee > player1WonTime)
    {
        return enWinner::computer;
    }
    else
    {
        return enWinner::Draw;
    }
}

enGameChoice GetcomputerChoice()
{
    return (enGameChoice)RandomNumber(1,3);
}

enGameChoice ReadPlayer1Choice()
{
    short choice;
     do 
     {
         cout << "\n Your choice : [1] Stone , [2] Paper , [3] Scissors ?  ";
         cin >> choice;
               
      } while (choice < 1 || choice > 3);
     return (enGameChoice)choice;

}

void SetWinnerScreenColor(enWinner winner)
{
    switch (winner)
    {
    case enWinner::player1:
        system("Color 2F");
        break;

    case enWinner::computer:
        system("Color 4F");
        cout << "\a";
        break;

    default:
        system("Color 6F");
        break;
    }

}

void PrintRoundResult(stRoundInfo RoundInfo)
{
  cout << "------------- Round [" << RoundInfo.RandomNumber << "]-------------\n\n";

  cout << " Player 1 choice :"  << ChoiceName(RoundInfo.player1Choice) << endl;
  cout << " Computer choice :"  << ChoiceName(RoundInfo.computerChoice) << endl;
  cout << " Round Winner    : [" << RoundInfo.WinnerName << "]\n";
  cout << "-----------------------------------\n" << endl;

   SetWinnerScreenColor(RoundInfo.Winner);

}
stGameResult FillGameResult(int GameRound,short player1WonTime,short computerWonTimee,short DrawTime)
{
    stGameResult GameResult; 
    GameResult.GameRound       = GameRound;
    GameResult.Player1WinTime  = player1WonTime;
    GameResult.ComputerWinTime = computerWonTimee;
    GameResult.DrawTime        = DrawTime;
    GameResult.GameWinner      = WhoWonTheGame(player1WonTime,computerWonTimee);
    GameResult.WinnerName      = winnerName(GameResult.GameWinner);
    return GameResult;
}

stGameResult PlayGame(short HowManyRoundss)
{
    stRoundInfo RoundInfo;
    short player1WonTime = 0,computerWonTimee = 0,DrawTime = 0;

    for (short GameRound = 1;GameRound <= HowManyRoundss;GameRound++)
    {
        cout << "\n Round [" << GameRound << "] begins: \n";
        RoundInfo.RandomNumber  = GameRound;
        RoundInfo.player1Choice = ReadPlayer1Choice();
        RoundInfo.computerChoice = GetcomputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = winnerName(RoundInfo.Winner);


        if (RoundInfo.Winner == enWinner::player1)
            player1WonTime++;
        else if (RoundInfo.Winner == enWinner::computer)
            computerWonTimee++;
        else
            DrawTime++;


        PrintRoundResult(RoundInfo);

    }
    return FillGameResult(HowManyRoundss,player1WonTime,computerWonTimee,DrawTime);

}

string Tabs(short NumberOfTabs)
{
    string t = "";
    for (int i = 1; i < NumberOfTabs; i++)
    {
        t = t + "\t";
        cout << t;
    }
    return t;
}
 
void ShowGameOverOnScreen()
{
    cout << Tabs(2) << "----------------------------------------------------\n\n";
    cout << Tabs(2) << "                 +++ G a m e O v e r +++  \n";
    cout << Tabs(2) << "----------------------------------------------------\n\n";

}

void ShowFinalGameResult(stGameResult GameResult)
{
   cout << Tabs(2) << "-------------------------[Game Result]-----------------\n\n";
   cout << Tabs(2) << " Game Round : " << GameResult.GameRound << endl;
   cout << Tabs(2) << " Player1 Won Time : " << GameResult.Player1WinTime << endl;
   cout << Tabs(2) << " Computer Won Time : " << GameResult.ComputerWinTime << endl;
   cout << Tabs(2) << " Draw Time : " << GameResult.DrawTime << endl;
   cout << Tabs(2) << " Final Winner : " << GameResult.WinnerName << endl;
   cout << Tabs(2) << "----------------------------------------------------\n\n";

    SetWinnerScreenColor(GameResult.GameWinner);
}

void ResetScreen()
{
    system("Cls");
    system("Color 0F");

}
short ReadHowManyRoundss()
{
    short GameRound = 1;

    do
    {
       cout << " How Many Round From 1 To 10 ? " << endl;
       cin >> GameRound;

    } while (GameRound < 1 || GameRound > 10);

    return GameRound;

}

void StartGame()
{
    char PlayAgain = 'y';

    do
    {
       ResetScreen();
       stGameResult GameResult = PlayGame(ReadHowManyRoundss());
       ShowGameOverOnScreen();
       ShowFinalGameResult(GameResult);

       cout << endl << Tabs(3) << "Do You Want To Play Again Y/N ? \n";
       cin >> PlayAgain;


    } while (PlayAgain == 'Y' || PlayAgain == 'y');


}
int main()
{

    srand((unsigned)time(NULL));

    StartGame();

    return 0;


}

 
