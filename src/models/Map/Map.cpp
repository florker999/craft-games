#include "Map.h"
#include "../Player/Player.h"

Map::Map(int width, int height, int tileSize, sf::Texture &playerTexture)
{
    int x = 0,
        y = 0;

    this->tiles = std::vector<std::vector<Tile>>{};
    this->tiles.reserve(height);
    for (int i = 0; i < height; i++)
    {
        std::vector<Tile> row{};
        row.reserve(width);
        for (int j = 0; j < width; j++)
        {
            row.push_back(Tile{sf::Vector2f(x, y)});
            x += tileSize;
        }
        this->tiles.push_back(row);
        x = 0;
        y += tileSize;
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            Tile &tile{this->tiles[i][j]};
            if (i > 0)
            {
                tile.topNeighbour = &this->tiles[i - 1][j];
            }
            if (j < width - 1)
            {
                tile.rightNeighbour = &this->tiles[i][j + 1];
            }
            if (i < height - 1)
            {
                tile.botNeighbour = &this->tiles[i + 1][j];
            }
            if (j > 0)
            {
                tile.leftNeighbour = &this->tiles[i][j - 1];
            }
        }
    }
}

Map::~Map()
{
}

void Map::fill(Terrain base)
{
    for (auto &row : this->tiles)
    {
        for (auto &tile : row)
        {
            tile.addLayer(base);
        }
    }
}

void Map::draw(sf::RenderWindow &window)
{
    for (auto &row : this->tiles)
    {
        for (auto &tile : row)
        {
            tile.draw(window);
        }
    }
}

void Map::movePlayer(Direction direction)
{
    auto player = this->tiles[this->playerY][this->playerX].popLayer();
    switch (direction)
    {
    case Direction::Up:
        this->playerY--;
        break;

    case Direction::Right:
        this->playerX++;
        break;

    case Direction::Down:
        this->playerY++;
        break;

    case Direction::Left:
        this->playerX--;
        break;

    default:
        break;
    }

    this->tiles[this->playerY][this->playerX].addLayer(player);
}

void Map::placePlayer(sf::Vector2f position, Player &player)
{
    Tile *playerTile{&this->tiles[position.y][position.x]};
    player.setTile(playerTile);
    this->playerX = position.x;
    this->playerY = position.y;
}
