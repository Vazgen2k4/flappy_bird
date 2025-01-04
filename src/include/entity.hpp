#pragma once
#include "raylib.h"

class Entity {
 protected:
  Rectangle hit_box;

 public:
  Entity();
  virtual float getX() const;
  virtual float getY() const;
  virtual float getWidth() const;
  virtual float getHeight() const;
  virtual Vector2 getCoords() const;
  virtual Rectangle getHitBox() const;
  virtual void setHitBox(Rectangle rect);
  virtual void setX(float value);
  virtual void setY(float value);
  virtual void setHeight(float value);
  virtual void setWidth(float value);
  
};
