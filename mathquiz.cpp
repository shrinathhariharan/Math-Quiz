#include <iostream>
#include <cmath>
#include "program.h"

namespace Global
{
    int score{0};

    int totalQuestions{0};
}

void answerChecker(double answer, double userAnswer)
{
    ++Global::totalQuestions;

    if (answer == userAnswer)
    {
        std::cout << "Correct!\n";
        ++Global::score;
            
        std::cout << "Score: " << Global::score << '/' << Global::totalQuestions << '\n';
        return;
    }
    else
    {
        std::cout << "Sorry, the correct answer was " << answer << '\n';
        std::cout << "Score: " << Global::score << '/' << Global::totalQuestions << '\n';
        return;
    }

}

int mainMenu()
{
    while (true)
    {
        std::cout << "1. Instructions\n2. Start!\n";
        int option{};
        std::cin >> option;
        switch(option)
        {
        case 1:
        case 2:
            return option;
        default:
            std::cout << "That is invalid! Choose a number to continue.\n";
        }
    }
    
}

void startGame()
{
    int questionType{Random::get(1, 11)};

    int num1{Random::get(1, 25)};
    int num2{Random::get(1, 15)};

    std::cout << "What is ";
    
    if (questionType <= 3)
    {
        std::cout << num1 << " + " << num2 << "?\n"; //addition

        auto answer{num1 + num2};
        double userAnswer{};
        std::cin >> userAnswer;

        answerChecker(answer, userAnswer);  
    } 
    else if (questionType <= 6)
    {
        std::cout << num1 << " - " << num2 << "?\n"; //subtraction

        auto answer{num1 - num2};
        double userAnswer{};
        std::cin >> userAnswer;

        answerChecker(answer, userAnswer);
    } 
    else if (questionType <= 8)
    {
        std::cout << num1 << " x " << num2 << "?\n"; //multiplication

        auto answer{num1 * num2};
        double userAnswer{};
        std::cin >> userAnswer;

        answerChecker(answer, userAnswer);
    }
    else if (questionType <= 10)
    {
        std::cout << "the remainder of " << num1 << " / " << num2 << "?\n"; //modulo

        int answer{(num1) % (num2)};
        double userAnswer{};
        std::cin >> userAnswer;

        answerChecker(answer, userAnswer);
    }
    else if (questionType == 11)
    {
        std::cout << num1 << " squared?\n"; //sqares

        double answer{std::pow(num1, 2)};
        double userAnswer{};
        std::cin >> userAnswer;

        answerChecker(answer, userAnswer);
    }

    return;
}

bool playAgain()
{
    while (true)
    {
        std::cout << "Do you want to play again? (y / n)\n";
        char input{};
        std::cin >> input;

        switch(input)
        {
        case 'y':
            Global::score = 0;
            Global::totalQuestions = 0;
            return true;

        case 'n':
            return false;
        }
    }

}

int main()
{
    bool quitProgram{false};

    do 
    {
        switch(mainMenu())
        {
        case 1: 
            std::cout << "\nThis gives you ten math questions and you should try to answer as many of them right!\n At the end, you get a score of how well you did.\n\n";
            break;
        case 2:
        {
            for (int i{0}; i < 10; ++i)
            {
                startGame();
            }
            
            std::cout << "Good job! You got " << (static_cast<double>(Global::score) / Global::totalQuestions) * 100 << "%!\n";
            quitProgram = !playAgain();
        }
        }
    } while (!quitProgram);

    std::cout << "thank you\n";

    return 0;
}
