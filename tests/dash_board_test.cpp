
#include "dash_board.hpp"

#include <gtest/gtest.h>

#include "consts.hpp"

TEST(DashBoardTest, Constructor) {
  InitRaylibForTests();
  DashBoard dashBoard;

  EXPECT_EQ(dashBoard.getMedalType(), MedalType::NONE);
  CloseRaylibAfterTests();
}

TEST(DashBoardTest, SetMedalByBestScores) {
  InitRaylibForTests();

  DashBoard dashBoard;

  EXPECT_TRUE(dashBoard.setMedalByBestScores(50));
  EXPECT_TRUE(dashBoard.setMedalByBestScores(150));
  EXPECT_TRUE(dashBoard.setMedalByBestScores(250));
  EXPECT_FALSE(dashBoard.setMedalByBestScores(0));
  CloseRaylibAfterTests();
}

TEST(DashBoardTest, SetMedalTexture) {
  InitRaylibForTests();

  DashBoard dashBoard;

  dashBoard.setMedalByBestScores(0);
  EXPECT_FALSE(dashBoard.setMedalTexture());

  dashBoard.setMedalByBestScores(10);
  EXPECT_TRUE(dashBoard.setMedalTexture());
  
  CloseRaylibAfterTests();
}

TEST(DashBoardTest, Draw) {
  InitRaylibForTests();

  DashBoard dashBoard;
  int testScore = 100;
  int bestScore = 150;

  EXPECT_NO_THROW(dashBoard.Draw(false, testScore, bestScore));
  EXPECT_NO_THROW(dashBoard.Draw(true, testScore, bestScore));

  CloseRaylibAfterTests();
}
