#include "entity.hpp"

Entity::Entity() { hit_box = {0, 0, 0, 0}; }

float Entity::getX() const { return hit_box.x; }
float Entity::getY() const { return hit_box.y; }

float Entity::getWidth() const { return hit_box.width; }
float Entity::getHeight() const { return hit_box.height; }
Vector2 Entity::getCoords() const { return {hit_box.x, hit_box.y}; }
Rectangle Entity::getHitBox() const { return hit_box; }

void Entity::setHitBox(Rectangle rect) { hit_box = rect; }

void Entity::setX(float value) { hit_box.x = value; }

void Entity::setY(float value) { hit_box.y = value; }

void Entity::setHeight(float value) {
  if (value < 0) {
    return;
  }

  hit_box.height = value;
}

void Entity::setWidth(float value) {
  if (value < 0) {
    return;
  }

  hit_box.width = value;
}
