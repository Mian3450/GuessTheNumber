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

static bool YourAttempt(int computer_choice, int difficulty, bool more_less_mode)
{
    string numbers = "1234567890";
    string your_choice;
    string more_or_less_output;


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
        more_or_less_output = your_choice_int > computer_choice ? "More than guessed number" : "Less than guessed number";

        if (more_less_mode) 
        {
                cout << more_or_less_output << endl;
        }

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

static bool MoreOrLossMode(int difficulty)
{
    string yes_no_answer{};
    bool more_less_mode = false;

    if (difficulty == 100)
    {
        cout << "Enable Less or More mode? (yes or no): ";
        cin >> yes_no_answer;

        if (yes_no_answer == "yes")
        {
            more_less_mode = true;
        }
        else if (yes_no_answer == "no")
        {
            more_less_mode = false;
        }
        else
        {
            cout << "Error: unexpected answer" << endl;
        }
    }

    return more_less_mode;
}

static void GuessTheNumber()
{
    int difficulty = DifficultyChooser();
    int computer_choice = ComputerRandChoice(difficulty);
    size_t attempts = Attempts(difficulty);
    bool more_less_mode = MoreOrLossMode(difficulty);
    bool result = false;

    while ( (attempts != 0) and result != true)
    {
        cout << "You have " << attempts << " attempts" << endl;
        attempts--;
        result = YourAttempt(computer_choice, difficulty, more_less_mode);
    }

    if (result == true)
    {
        cout << "You WIN!" << endl;
    }
    else
    {
        cout << "Unfortunately, you lose, the number was - " << computer_choice << endl;
    }
}

int main()
{
    bool retry = false;
    string yes_or_no_answer{};

    while (!retry)
    {
        srand(time(0));
        cout << "Welcome to the GuessRandomNumber" << endl;

        GuessTheNumber();

        cout << "Do you want retry? (yes or no): ";
        cin >> yes_or_no_answer;

        if (yes_or_no_answer == "yes")
        {
            retry = false;
        } 
        else if (yes_or_no_answer == "no")
        {
            retry = true;
        }
        else
        {
            cout << "Error: unexpected input" << endl;
        }
    }

    return 0;
}
