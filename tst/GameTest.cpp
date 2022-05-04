#include "gtest/gtest.h"
#include "game.h"
#include "game.cpp"


TEST(GameTest, TestWinner) {
    //arrange
    Game game;
    //act
    game.points_player1 = 20;
    game.points_player2 = 10;
    game.check_winner();
    int value = game.determine_winner();
    //assert
    EXPECT_EQ(value,  1);

}
TEST(GameTest, TestLooser) {
    //arrange
    Game game;
    //act
    game.points_player1 = 20;
    game.points_player2 = 10;
    game.check_winner();
    int value = game.determine_winner(); 
    //assert
    EXPECT_NE(value,  2);

}
TEST(GameTest, TestPunishement){
    //arrange
    Game game;
    //act
    int currentPlayer = 1;
    game.points_player1 = 20;
    game.points_player2 = 10;
    game.player1_wins = 2;
    game.check_powerups(currentPlayer);
    int punishedPlayer = game.f_punish_player();
    int punishedPoints = game.f_punish_points();
    //assert
    EXPECT_EQ(punishedPlayer, 2);
    EXPECT_EQ(punishedPoints, 5);

}
TEST(GameTest, TestDoublePoints){
    //arrange
    Game game;
    //act
    int currentPlayer = 1;
    game.points_player1 = 20;
    game.points_player2 = 10;
    game.player1_wins = 3;
    game.check_powerups(currentPlayer);
    int value = game.points_player1;
    //assert
    ASSERT_EQ(value, 25);

}
TEST(GameTest, AssignPoints){
    //arrange
    Game game;
    //act
    game.current_player = 2;
    game.points_player1 = 20;
    game.points_player2 = 10;
    game.player2_wins = 0;
    int gotPoints = 1;
    //assert
    ASSERT_EQ(game.assign_points(gotPoints), 15);
}

TEST(GameTest, NotAssignPoints){
    //arrange
    Game game;
    //act
    game.current_player = 1;
    game.points_player1 = 20;
    game.points_player2 = 10;
    game.player1_wins = 0;
    int gotPoints = 0;
    //assert
    ASSERT_EQ(game.assign_points(gotPoints), 20);
}