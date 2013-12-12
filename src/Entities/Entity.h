#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
#include "SharedDefines.h"

class Game;
class Map;
class Unit;

class Entity
{
public:
    Entity(Game* _game, std::string model);
    virtual ~Entity();

    virtual void Update(sf::Time const diff);
    virtual void Draw();

    virtual void LoadTexture();
    virtual void LoadMoveTexture(int type) { };

    virtual TypeId GetTypeId() const { return Type; }

    virtual float GetPositionX() const { return Position.x; }
    virtual float GetPositionY() const { return Position.y; }
    virtual float GetWidth() const { return sprite.getGlobalBounds().width; }
    virtual float GetHeight() const { return sprite.getGlobalBounds().height; }

    virtual void SetPosition(sf::Vector2f pos);

    virtual bool IsInAir() const { return inAir; };

    virtual void AddToMap(Map* _map) { map = _map; }

    virtual void StopHorizontalMovement();
    virtual void StopVerticalMovement();

    virtual bool IsUnit() { return false; }
    
    Unit* ToUnit();
    sf::Vector2f NewPosition;
    sf::Vector2f Position;
    
    std::string TextureName; // Original texture name

    sf::Vector2f Velocity;
    sf::Vector2f Acceleration;
protected:
    bool inAir;
    Map* map;
    TypeId Type;
    Game* game;
    sf::Texture texture;
    sf::Sprite sprite;
};
#endif