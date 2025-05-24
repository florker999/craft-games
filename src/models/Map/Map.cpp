#include "Map.h"
#include "../Player/Player.h"
#include "../Ground/Ground.h"
#include "../Wall/Wall.h"
/*
Map::Map(int width, int height, int tileSize)
{
    this->transparentTexture = sf::Texture{sf::Vector2u{32, 32}};
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
            row.push_back(Tile{this->transparentTexture, sf::Vector2f(x, y)});
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
*/

Map::Map(const std::vector<std::vector<GroundType>> &mapTemplate, const sf::Texture &grassTexture, const sf::Texture &wallTexture, int tileSize) : tiles{std::vector<std::vector<Tile *>>(mapTemplate.size())}
{
    int x = 0;
    for (int columnIndex = 0; columnIndex < this->tiles.size(); columnIndex++)
    {
        int y = 0;
        std::vector<Tile *> &tileColumn = this->tiles[columnIndex];
        const std::vector<GroundType> &templateColumn = mapTemplate[columnIndex];

        tileColumn.reserve(templateColumn.size());
        for (GroundType groundType : templateColumn)
        {
            switch (groundType)
            {
            case GroundType::Grass:
                tileColumn.push_back(new Ground{grassTexture, sf::Vector2f(x, y)});
                break;

            case GroundType::Wall:
                tileColumn.push_back(new Wall{wallTexture, sf::Vector2f(x, y)}); // water is now walkable

            default:
                break;
            }
            y += tileSize;
        }
        x += tileSize;
    }

    int width = this->tiles.size(),
        height = this->tiles[0].size();
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            Tile &tile{*this->tiles[x][y]};
            if (x > 0)
            {
                tile.leftNeighbour = this->tiles[x - 1][y];
            }
            if (y < height - 1)
            {
                tile.botNeighbour = this->tiles[x][y + 1];
            }
            if (x < width - 1)
            {
                tile.rightNeighbour = this->tiles[x + 1][y];
            }
            if (y > 0)
            {
                tile.topNeighbour = this->tiles[x][y - 1];
            }
        }
    }
}

Map::~Map()
{
}

/* void Map::fill(Tile *fillingTile, Tile *fillingTile2)
{
    for (auto &row : this->tiles)
    {
        int j{0};
        for (auto &tile : row)
        {
            const sf::Vector2f position = tile.getPosition();
            Tile nextTile = j == 3 ? *fillingTile2 : *fillingTile;
            nextTile.botNeighbour = tile.botNeighbour;
            nextTile.leftNeighbour = tile.leftNeighbour;
            nextTile.rightNeighbour = tile.rightNeighbour;
            nextTile.topNeighbour = tile.topNeighbour;
            nextTile.setPosition(position);
            tile = nextTile;
            j++;
        }
    }
}
 */

void Map::draw(sf::RenderWindow &window)
{
    for (std::vector<Tile *> column : this->tiles)
    {
        for (Tile *tile : column)
        {
            window.draw(*tile);
        }
    }
}

void Map::placePlayer(sf::Vector2f position, Player &player)
{
    Tile *playerTile{this->tiles[position.y][position.x]};
    player.setTile(playerTile);
    this->playerX = position.x;
    this->playerY = position.y;
}

const std::vector<std::vector<Map::GroundType>> Map::testMap = {
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
        Map::GroundType::Wall,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
    {
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
        Map::GroundType::Grass,
    },
};
