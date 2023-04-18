#include "chaos_game.h"

void Chaos_Game::input(sf::RenderWindow& window, sf::Text& text)
{
    bool input = true;
    std::cout << "Enter number of vertices." << std::endl;
    std::cin >> num_vertex;
    last_vertex = rand() % num_vertex;
    while(input && window.isOpen())
    {
        if(vertices.size() < num_vertex) 
            text.setString("Click to set the " + std::to_string(vertices.size() + 1) +  " vertex.");
        else if(vertices.size() == num_vertex)
            text.setString("Click to start simulation.");
        
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::MouseButtonPressed)
            {
                if(vertices.size() == num_vertex)
                {
                    points.push_back(std::make_pair(event.mouseButton.x, event.mouseButton.y));
                    input = false;
                }
                else
                {
                    vertices.push_back(std::make_pair(event.mouseButton.x, event.mouseButton.y));
                }
            }
            else if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        window.clear();
        window.draw(text);
        for(int i = 0; i < vertices.size(); i++)
        {
            sf::RectangleShape rectangle(sf::Vector2f(5, 5));
            rectangle.setPosition(vertices.at(i).first, vertices.at(i).second);
            window.draw(rectangle);
        }
        window.display();
    }
    std::cout << vertices.size() << std::endl;
}
void Chaos_Game::print(sf::RenderWindow& window, sf::Text& text)
{
    while(window.isOpen())
    {
        for(int i = 0; i < 1000; i++)
        {   
            int verticeIndex;
            if(num_vertex == 3)
                verticeIndex = rand() % num_vertex;
            else
            {
                do
                {
                    verticeIndex =  rand() % num_vertex;
                }
                while(verticeIndex == last_vertex);
                last_vertex = verticeIndex;
            }
            int pointIndex = points.size() - 1;
            points.push_back(std::make_pair((points.at(pointIndex).first + vertices.at(verticeIndex).first) / 2, 
                            (points.at(pointIndex).second + vertices.at(verticeIndex).second) / 2));
        }
        
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed || event.type == sf::Event::MouseButtonPressed)
            {
                window.close();
            }
        }
        
        window.clear();
        text.setString("Click to exit simulation.");
        window.draw(text);
        for(int i = 0; i < vertices.size(); i++)
        {
            sf::RectangleShape rectangle(sf::Vector2f(5, 5));
            rectangle.setPosition(vertices.at(i).first, vertices.at(i).second);
            window.draw(rectangle);
        }
        for(int i = 0; i < points.size(); i++)
        {
            sf::RectangleShape rectangle(sf::Vector2f(1, 1));
            rectangle.setPosition(points.at(i).first, points.at(i).second);
            window.draw(rectangle);
        }
        window.display();
    }
}