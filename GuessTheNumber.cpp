#include <iostream>
#include <string>

using namespace std;

static int ComputerRandChoice(int difficulty)
{
    int computer_choice = rand() % difficulty + 1;
    return computer_choice;
}

static int DifficultyChooser()
{
    int difficult_choise{};
    cout << "Choose the difficulty" << endl;
    cout << "1. Heads and Tails | 2. Easy (1-5) | 3. Medium (1-10) | 4. Hard (1-40) | 5. Oracle tests (1-100)" << endl;
    cout << "Your choice: ";
    cin >> difficult_choise;

    switch (difficult_choise)
    {
    case 1:
        return 2;
    case 2:
        return 5;
    case 3:
        return 10;
    case 4:
        return 40;
    case 5:
        return 100;
    default:
        cout << "!!!Error: unexpected choice!!!";
        return 0;
    }
}

static bool YourAttempt(int computer_choice)
{
    string numbers = "1234567890";
    string your_choice;
    cout << "Your attempt: ";
    cin >> your_choice;

    for (size_t i = 0; i < your_choice.length(); i++) {
        if (numbers.find(your_choice[i]) == string::npos) {
            your_choice.erase(i, 1);
            i--;
        }
    }

    int your_choice_int = stoi(your_choice);

    if (your_choice_int == computer_choice)
    {
        cout << "Yes, it IS!" << endl;
        return true;
    }
    else
    {
        cout << "No, it isn't" << endl;
        return false;
    }
}

static int Attempts(int difficulty)
{
    size_t attempts = 1;

    if (difficulty > 2)
    {
        cout << "Choose attempts quantity: ";
        cin >> attempts;
    }
    return attempts;
}

static void GuessTheNumber()
{
    int difficulty = DifficultyChooser();
    int computer_choice = ComputerRandChoice(difficulty);
    size_t attempts = Attempts(difficulty);
    bool result = false;

    while ( (attempts != 0) and result != true)
    {
        cout << "You have " << attempts << " attempts" << endl;
        attempts--;
        result = YourAttempt(computer_choice);
    }

    if (result == true)
    {
        cout << "You WIN!";
    }
    else
    {
        cout << "Unfortunately, you lose, the number was - " << computer_choice << endl;
    }
}

int main()
{
    cout << "Welcome to the GuessRandomNumber" << endl;

    GuessTheNumber();

    return 0;
}
