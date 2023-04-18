#include <utility>
#include <cstdlib>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Chaos_Game
{
    public:
        void input(sf::RenderWindow& window, sf::Text& text);
        void print(sf::RenderWindow& window, sf::Text& text);
        int num_vertex;
        int last_vertex;
    private:
        std::vector<std::pair<int, int>> vertices;
        std::vector<std::pair<int, int>> points;
};