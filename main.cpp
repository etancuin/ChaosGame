//Ethan and Chris

#include <utility>
#include <SMFL/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1920, 1080));
    std::vector<std::pair<int, int>> vertices;
    std::vector<std::pair<int, int>> points;
    
    Font font;
    font.loadFromFile("arial.ttf");

    Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setPosition(960, 540);

    while(true)
    {
        if(vertices.size() == 1) 
            text.setString("Click to set first vertex.");
        else if(vertices.size() == 2)
            text.setString("Click to set second vertex.");
        else if(vertices.size() == 3)
            text.setString("Click to set third vertex.");
        else
            text.setString("Click to start simulation.");

        Event event;
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if(vertices.size() == 4)
                    break;
                vertices.push_back({event.mouseButton.x, event.mouseButton.y});
            }
        }
        window.draw(text);
        for(int i = 0; i < vertices.size(); i++)
        {
            RectangleShape rectangle(Vector2f(2, 2));
            rectangle.setPosition(vertices.at(i).first, vertices.at(i).second);
            window.draw(rectangle);
        }
    }
}
