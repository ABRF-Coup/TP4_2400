#include <iostream>
#include "Yogourt/YogourtNature.h"
#include "Yogourt/YogourtGrec.h"
#include "ui/ConsoleColors.h"

int main()
{
    std::unique_ptr<Yogourt> yNature = std::make_unique<YogourtNature>();
    std::unique_ptr<Yogourt> yGrec = std::make_unique<YogourtGrec>();


    std::cout << ConsoleColor::yellow << yNature->obtenirDescription() << ConsoleColor::reset << std::endl;
    std::cout << ConsoleColor::cyan << yGrec->obtenirDescription() << ConsoleColor::reset << std::endl;
   
    /*std::cout << ConsoleColor::cyan << "Je suis Pattern1 :  " << p1.getValue() << ConsoleColor::reset << std::endl;
    std::cout << ConsoleColor::cyan << "Je suis Pattern2 :  " << p2.getValue() << ConsoleColor::reset << std::endl;
    std::cout << ConsoleColor::magenta << "Bon TP a tous :) " << ConsoleColor::reset << std::endl;*/

    return 0;
};