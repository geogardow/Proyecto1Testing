#include "gtest/gtest.h"
#include "server.h"

TEST(serverTest, testingRandomTurn) {
    //arrange
    server serverToTest = server();

    //act
    serverToTest.randomTurn();
    int turn = serverToTest.turn;

    //assert
    EXPECT_TRUE (turn == 1 || turn == 2);
}

TEST(serverTest, testingRandomTurnFlagOff) {
    //arrange
    server serverToTest = server();

    //act
    serverToTest.randomTurn();
    int flag = serverToTest.START;

    //assert
    EXPECT_EQ (flag,  false);
}

TEST(serverTest, testingCardAnalysisFirstCard) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 1;
    serverToTest.cardAnalysis();
    int cardsClicked = serverToTest.idCard1;

    //assert
    EXPECT_NE (cardsClicked,0);
}

TEST(serverTest, testingCardAnalysisSecondCard) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.idCard1 = 12;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 1;
    serverToTest.cardAnalysis();
    int cardsClicked = serverToTest.idCard1;

    //assert
    EXPECT_EQ (cardsClicked,0);
}

TEST(serverTest, testingMatchedCardsMatched) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 0;
    serverToTest.idPic1 = 5;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 5;
    serverToTest.matchedCards();
    int instruction = serverToTest.buff_tx.instruction;

    //assert
    EXPECT_EQ (instruction,-1);
}

TEST(serverTest, testingMatchedCardsDouble) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 5;
    serverToTest.idPic1 = 2;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 2;
    serverToTest.matchedCards();
    int points = serverToTest.pointsP1;

    //assert
    EXPECT_EQ (points, 12);
}

TEST(serverTest, testingMatchedCardsDoubleHIT) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.HIT1 = true;
    serverToTest.HIT2 = true;
    serverToTest.pointsP1 = 5;
    serverToTest.idPic1 = 2;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 2;
    serverToTest.matchedCards();
    int points = serverToTest.pointsP1;

    //assert
    EXPECT_EQ (points, 14);
}

TEST(serverTest, testingMatchedCardsDoubleSwitchPlayer) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 5;
    serverToTest.idPic1 = 2;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 2;
    serverToTest.matchedCards();
    int turn = serverToTest.turn;

    //assert
    EXPECT_EQ (turn, 2);
}

TEST(serverTest, testingMatchedCardsBonus) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 5;
    serverToTest.idPic1 = 1;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 1;
    serverToTest.matchedCards();
    int points = serverToTest.pointsP1;

    //assert
    EXPECT_EQ (points, 6);
}

TEST(serverTest, testingMatchedCardsBonusHIT) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.HIT1 = true;
    serverToTest.HIT2 = true;
    serverToTest.pointsP1 = 5;
    serverToTest.idPic1 = 1;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 1;
    serverToTest.matchedCards();
    int points = serverToTest.pointsP1;

    //assert
    EXPECT_EQ (points, 7);
}

TEST(serverTest, testingMatchedCardsBonusSwitchPlayer) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 5;
    serverToTest.idPic1 = 1;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 1;
    serverToTest.matchedCards();
    int turn = serverToTest.turn;

    //assert
    EXPECT_EQ (turn, 1);
}

TEST(serverTest, testingMatchedCardsNotSP) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 5;
    serverToTest.idPic1 = 3;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 3;
    serverToTest.matchedCards();
    int points1 = serverToTest.pointsP1;
    int points2 = serverToTest.pointsP2;

    //assert
    EXPECT_TRUE (points1 == 6 && points2 == 0 );
}

TEST(serverTest, testingMatchedCardsSP) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 2;
    serverToTest.pointsP1 = 5;
    serverToTest.idPic1 = 3;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 3;
    serverToTest.matchedCards();
    int points1 = serverToTest.pointsP1;
    int points2 = serverToTest.pointsP2;

    //assert
    EXPECT_TRUE (points1 == 0 && points2 == 6 );
}

TEST(serverTest, testingMatchedCardsNotSPHIT) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.HIT1 = true;
    serverToTest.HIT2 = true;
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 5;
    serverToTest.idPic1 = 3;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 3;
    serverToTest.matchedCards();
    int points1 = serverToTest.pointsP1;
    int points2 = serverToTest.pointsP2;

    //assert
    EXPECT_TRUE (points1 == 7 && points2 == 0 );
}

TEST(serverTest, testingMatchedCardsSPHIT) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.HIT1 = true;
    serverToTest.HIT2 = true;
    serverToTest.turn = 2;
    serverToTest.pointsP1 = 5;
    serverToTest.idPic1 = 3;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 3;
    serverToTest.matchedCards();
    int points1 = serverToTest.pointsP1;
    int points2 = serverToTest.pointsP2;

    //assert
    EXPECT_TRUE (points1 == 1 && points2 == 6 );
}

TEST(serverTest, testingMatchedCardsSPSwitchPlayer) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 5;
    serverToTest.idPic1 = 3;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 3;
    serverToTest.matchedCards();
    int turn = serverToTest.turn;

    //assert
    EXPECT_EQ (turn, 2);
}

TEST(serverTest, testingMatchedCardsSkullP1) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 5;
    serverToTest.pointsP2 = 5;
    serverToTest.idPic1 = 4;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 4;
    serverToTest.matchedCards();
    int points1 = serverToTest.pointsP1;
    int points2 = serverToTest.pointsP2;

    //assert
    EXPECT_TRUE(points1 == 6 && points2 ==4);
}

TEST(serverTest, testingMatchedCardsSkullHITP1) {
    //arrange
    server serverToTest = server();
    
        //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 5;
    serverToTest.pointsP2 = 5;
    serverToTest.idPic1 = 4;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 4;
    serverToTest.HIT1 = true;
    serverToTest.HIT2 = true;
    serverToTest.matchedCards();
    int points1 = serverToTest.pointsP1;
    int points2 = serverToTest.pointsP2;

    //assert
    EXPECT_TRUE(points1 == 7 && points2 ==4);
}

TEST(serverTest, testingMatchedCardsSkullP2) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 2;
    serverToTest.pointsP1 = 5;
    serverToTest.pointsP2 = 5;
    serverToTest.idPic1 = 4;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 4;
    serverToTest.matchedCards();
    int points1 = serverToTest.pointsP1;
    int points2 = serverToTest.pointsP2;

    //assert
    EXPECT_TRUE(points1 == 4 && points2 ==6);
}

TEST(serverTest, testingMatchedCardsSkullHITP2) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 2;
    serverToTest.pointsP1 = 5;
    serverToTest.pointsP2 = 5;
    serverToTest.idPic1 = 4;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 4;
    serverToTest.HIT1 = true;
    serverToTest.HIT2 = true;
    serverToTest.matchedCards();
    int points1 = serverToTest.pointsP1;
    int points2 = serverToTest.pointsP2;

    //assert
    EXPECT_TRUE(points1 == 4 && points2 == 7);
}

TEST(serverTest, testingMatchedCardsSkullSwitchPlayer) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 5;
    serverToTest.idPic1 = 4;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 4;
    serverToTest.matchedCards();
    int turn = serverToTest.turn;

    //assert
    EXPECT_EQ (turn, 2);
}

TEST(serverTest, testingMatchedCardsNotMatched) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 0;
    serverToTest.idPic1 = 5;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 6;
    serverToTest.matchedCards();
    int instruction = serverToTest.buff_tx.instruction;

    //assert
    EXPECT_EQ (instruction,-2);
}

TEST(serverTest, testingMatchedCardsHIT) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 0;
    serverToTest.idPic1 = 5;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 5;
    serverToTest.HIT1 = true;
    serverToTest.HIT2 = true;
    serverToTest.matchedCards();
    int points = serverToTest.pointsP1;

    //assert
    EXPECT_EQ (points, 2);
}

TEST(serverTest, testingMatchedCardsNotHIT) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 0;
    serverToTest.idPic1 = 5;
    serverToTest.actualCardID = 11;
    serverToTest.actualPicID = 5;
    serverToTest.HIT1 = true;
    serverToTest.HIT2 = false;
    serverToTest.matchedCards();
    int points = serverToTest.pointsP1;

    //assert
    EXPECT_EQ (points, 1);
}

TEST(serverTest, testingCheckWinnerP1) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.pointsP1 = 1;
    serverToTest.pointsP2 = 0;
    serverToTest.WINNER = true;
    serverToTest.checkWinner();
    int winner = serverToTest.buff_tx.winner;

    //assert
    EXPECT_EQ (winner, 1);
}

TEST(serverTest, testingCheckWinnerP2) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.pointsP1 = 0;
    serverToTest.pointsP2 = 1;
    serverToTest.WINNER = true;
    serverToTest.checkWinner();
    int winner = serverToTest.buff_tx.winner;

    //assert
    EXPECT_EQ (winner, 2);
}

TEST(serverTest, testingCheckWinnerTie) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.pointsP1 = 1;
    serverToTest.pointsP2 = 1;
    serverToTest.WINNER = true;
    serverToTest.checkWinner();
    int winner = serverToTest.buff_tx.winner;

    //assert
    EXPECT_EQ (winner, 3);
}

TEST(serverTest, testingAddPointsP1) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 0;
    serverToTest.addPoints();
    int points = serverToTest.pointsP1;

    //assert
    EXPECT_EQ (points, 1);
}

TEST(serverTest, testingAddPointsP2) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 2;
    serverToTest.pointsP2 = 0;
    serverToTest.addPoints();
    int points = serverToTest.pointsP2;

    //assert
    EXPECT_EQ (points, 1);
}

TEST(serverTest, testingSubsPointsP1) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 1;
    serverToTest.subsPoints();
    int points = serverToTest.pointsP1;

    //assert
    EXPECT_EQ (points, 0);
}

TEST(serverTest, testingSubsPointsP2) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 2;
    serverToTest.pointsP2 = 1;
    serverToTest.subsPoints();
    int points = serverToTest.pointsP2;

    //assert
    EXPECT_EQ (points, 0);
}

TEST(serverTest, testingSwitchPlayers) {
    //arrange
    server serverToTest = server();

    //act
    serverToTest.turn = 1;
    serverToTest.switchPlayers();
    int turn = serverToTest.turn;

    //assert
    EXPECT_EQ (turn, 2);
}

TEST(serverTest, testingDoublePoints) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.turn = 1;
    serverToTest.pointsP1 = 5;
    serverToTest.doublePoints();
    int points = serverToTest.pointsP1;

    //assert
    EXPECT_EQ (points, 10);
}

TEST(serverTest, testingSwitchPoints) {
    //arrange
    server serverToTest = server();
    
    //act
    serverToTest.pointsP1 = 7;
    serverToTest.pointsP2 = 3;
    serverToTest.switchPoints();
    int points1 = serverToTest.pointsP1;
    int points2 = serverToTest.pointsP2;

    //assert
    EXPECT_TRUE (points1 == 3 && points2 == 7 );
}
