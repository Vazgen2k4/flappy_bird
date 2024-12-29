#include "bird.hpp"

#include <gtest/gtest.h>

#include "consts.hpp"
#include "raylib.h"

const char* birdTexturePath = "assets/images/bird-01.png";

TEST(BirdTest, Constructor) {
  InitRaylibForTests();

  Bird bird(birdTexturePath);

  EXPECT_GE(bird.getX(), 0);
  EXPECT_GE(bird.getY(), 0);
  EXPECT_GT(bird.getWidth(), 0);
  EXPECT_GT(bird.getHeight(), 0);

  CloseRaylibAfterTests();
}

TEST(BirdTest, Update) {
  InitRaylibForTests();

  Bird bird(birdTexturePath);

  float initialX = bird.getX();
  float initialY = bird.getY();

  bird.Update();
  EXPECT_NE(bird.getY(), initialY);
  EXPECT_EQ(bird.getX(), initialX);

  CloseRaylibAfterTests();
}

TEST(BirdTest, Reset) {
  Bird bird(Images::BIRD.c_str());

  float initialX = bird.getX();
  float initialY = bird.getY();

  bird.Update();

  float updatedX = bird.getX();
  float updatedY = bird.getY();

  bird.Reset();

  EXPECT_EQ(bird.getX(), initialX);
  EXPECT_EQ(bird.getY(), initialY);
}

TEST(BirdTest, Getters) {
  InitRaylibForTests();

  Bird bird(birdTexturePath);

  EXPECT_GE(bird.getX(), 0);
  EXPECT_GE(bird.getY(), 0);
  EXPECT_GT(bird.getWidth(), 0);
  EXPECT_GT(bird.getHeight(), 0);

  Rectangle hitBox = bird.getHitBox();
  EXPECT_FLOAT_EQ(hitBox.x, bird.getX());
  EXPECT_FLOAT_EQ(hitBox.y, bird.getY());
  EXPECT_GT(hitBox.width, 0);
  EXPECT_GT(hitBox.height, 0);

  CloseRaylibAfterTests();
}