//Ethan Quinn and Chris Reinholtz

#include "chaos_game.h"

int main()
{
    sf::VideoMode vm(1920, 1080);
    sf::RenderWindow window(vm, "Chaos Game", sf::Style::Default);

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(40);
    text.setPosition(100, 100);

    Chaos_Game simulation;

    simulation.input(window, text);
    window.clear();
    simulation.print(window, text);
}
