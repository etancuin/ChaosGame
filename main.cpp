//Ethan and Chris

#include <utility>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace sf;

/*  

So I wrote a decent bit of the program but I haven't actually been able to test it since Mac sucks...hopefully it kinda works 

Also, we might need to make it actually OOP and use some functions

We may also need to adjust the font, size and postion of the text

*/

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Chaos Game", Style::Fullscreen);
    std::vector<std::pair<int, int>> vertices;
    std::vector<std::pair<int, int>> points;
    
    Font font;
    font.loadFromFile("arial.ttf");

    Text text;
    text.setFont(font);
    text.setCharacterSize(40);
    text.setPosition(100, 100);

    bool input = true;
    while(input && window.isOpen())
    {
        if(vertices.size() == 0) 
            text.setString("Click to set first vertex.");
        else if(vertices.size() == 1)
            text.setString("Click to set second vertex.");
        else if(vertices.size() == 2)
            text.setString("Click to set third vertex.");
        else
            text.setString("Click to start simulation.");
        
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::MouseButtonPressed)
            {
                if(vertices.size() == 3)
                {
                    points.push_back(std::make_pair(event.mouseButton.x, event.mouseButton.y));
                    input = false;
                }
                else
                {
                    vertices.push_back(std::make_pair(event.mouseButton.x, event.mouseButton.y));
                }
            }
            else if(event.type == Event::Closed)
            {
                window.close();
            }
        }
        
        window.clear();
        window.draw(text);
        for(int i = 0; i < vertices.size(); i++)
        {
            RectangleShape rectangle(Vector2f(2, 2));
            rectangle.setPosition(vertices.at(i).first, vertices.at(i).second);
            window.draw(rectangle);
        }
        window.display();
    }
    window.clear();
    
    while(window.isOpen())
    {
        text.setString("Click to exit simulation.");
        int verticeIndex = rand() % 3;
        int pointIndex = points.size() - 1;
        points.push_back(std::make_pair((points.at(pointIndex).first + vertices.at(verticeIndex).first) / 2, 
                          (points.at(pointIndex).second + vertices.at(verticeIndex).second) / 2));
        
        Event event;
        while(window.pollEvent(event))
        {
            if(event.type == Event::Closed || event.type == Event::MouseButtonPressed)
            {
                window.close();
            }
        }
        
        window.clear();
        window.draw(text);
        for(int i = 0; i < vertices.size(); i++)
        {
            RectangleShape rectangle(Vector2f(2, 2));
            rectangle.setPosition(vertices.at(i).first, vertices.at(i).second);
            window.draw(rectangle);
        }
        for(int i = 0; i < points.size(); i++)
        {
            RectangleShape rectangle(Vector2f(2, 2));
            rectangle.setPosition(points.at(i).first, points.at(i).second);
            window.draw(rectangle);
        }
        window.display();
    }
}
