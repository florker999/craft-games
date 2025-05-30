#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "./models/Terrain/Terrain.h"
#include "./models/Ground/Ground.h"
#include "./models/Map/Map.h"
#include "./models/Player/Player.h"
#include "./models/Wall/Wall.h"

int main()
{
    sf::Texture grassTexture{"assets/terrain/grass_1.png"};
    sf::Texture waterTexture{"assets/terrain/water.png"};
    sf::Texture playerTexture{"assets/players/maciek/Maciek_n.png"};
    sf::Texture cobelWallTexture{"assets/cobel.png"};
    Player player{playerTexture};
    Map map{Map::testMap, grassTexture, cobelWallTexture, static_cast<int>(grassTexture.getSize().x)};
    map.placePlayer({4, 4}, player);
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
            else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::W)
                {
                    player.move(Tile::Direction::Up);
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::D)
                {
                    player.move(Tile::Direction::Right);
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::S)
                {
                    player.move(Tile::Direction::Down);
                }
                else if (keyPressed->scancode == sf::Keyboard::Scancode::A)
                {
                    player.move(Tile::Direction::Left);
                }
            }
        }

        window.clear();
        map.draw(window);
        window.draw(player);
        window.display();
    }
}
