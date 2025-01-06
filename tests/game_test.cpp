#include "game.hpp"
#include <gtest/gtest.h>
#include "raylib.h"
#include "bird.hpp"
#include "pipe_controller.hpp"

#include "test_constants.hpp"

class GameTest : public ::testing::Test {
protected:
  Game* game;
  Bird* bird;
  PipeController* pipeController;

  void SetUp() override {
    game = new Game(Images::BIRD, "Test Game", 60);
    bird = new Bird(birdTexturePath);
    pipeController = new PipeController();
    game->Init(bird, pipeController);
  }

  void TearDown() override {
    delete game;
    delete bird;
    delete pipeController;
  }
};

TEST_F(GameTest, Initialization) {
  EXPECT_FALSE(game->isStarted());
  EXPECT_FALSE(game->isGameOver());
  EXPECT_EQ(game->getScore(), 0);
}

TEST_F(GameTest, RestartGame) {
  game->RestartGame();
  EXPECT_FALSE(game->isStarted());
  EXPECT_FALSE(game->isGameOver());
  EXPECT_EQ(game->getScore(), 0);
}

TEST_F(GameTest, ReadBestScore) {
  int bestScore = game->ReadBestScore();
  EXPECT_GE(bestScore, 0);
}

TEST_F(GameTest, WriteBestScore) {
  int newBestScore = 100;
  game->WriteBestScore(newBestScore);
  int bestScore = game->ReadBestScore();
  EXPECT_EQ(bestScore, newBestScore);
}