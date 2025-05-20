#include <SFML/Graphics.hpp>
#include <vector>
#include "./models/Terrain/Terrain.h"
#include "./models/Map/Map.h"
#include "./models/Player/Player.h"
#include <iostream>

int main()
{
    sf::Texture grass{"assets/terrain/grass_1.png"};
    sf::Texture playerTexture{"assets/players/maciek/Maciek_n.png"};
    Player player{playerTexture};
    Map map{20, 20, static_cast<int>(grass.getSize().x), playerTexture};
    map.fill(Terrain{grass, {0, 0}});
    map.placePlayer({10, 10}, player);
    auto window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(144);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (event->is<sf::Event::KeyPressed>())
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
                {
                    player.move(Tile::Direction::Up);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::D))
                {
                    player.move(Tile::Direction::Right);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
                {
                    player.move(Tile::Direction::Down);
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::A))
                {
                    player.move(Tile::Direction::Left);
                }
            }
        }

        window.clear();
        map.draw(window);
        player.draw(window);
        window.display();
    }
}
