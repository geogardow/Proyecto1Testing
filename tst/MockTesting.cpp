//#include "clientMock.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>
#include "server.h"

using namespace std;
using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

class client {
public:
    client();
    bool START = true;
    string imageReceived;
    int sockfd; 
    struct sockaddr_in servaddr;
    struct message* sendRequest(struct message* request);
    int instruction = 0;
    int size = 0;

private:
    struct message buf_tx;      
    struct message buf_rx;
};

#define SERVER_ADDRESS  "192.168.25.206"
#define PORT            8080 

client::client(){
    
}

struct message*  client::sendRequest(struct message* request){ 

    /* Socket creation */
    buf_tx = ((struct message )*request);
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) 
    { 
        cout<<"[CLIENT-error]: socket creation failed...\n"<<endl;
    } 
    
    /* memory space cleaning */
    memset(&servaddr, 0, sizeof(servaddr));

    /* assign IP, PORT */
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = inet_addr( SERVER_ADDRESS ); 
    servaddr.sin_port = htons(PORT); 
  
    /* try to connect the client socket to server socket */
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) 
    { 
        cout<<"[CLIENT-error]: connection with the server failed...\n"<<endl;
    } 

    if (START)
    {   
        read(sockfd, (struct message *)&buf_rx, sizeof(buf_rx)); //CLIENT: RECEIVES THE FIRST PLAYER
        this->START = false;
        struct message* answer;
        answer = ((struct message *)&buf_rx); //CLIENT: RETURNED THE STRUCT WITH THE DATA
        close(sockfd); 
        return answer;
    }

    write(sockfd, (struct message *)&buf_tx, sizeof(buf_tx)); //CLIENT: ID SENT, WAITING FOR SIZE OF THE NEXT PACKAGE    

    read(sockfd, (struct message *)&buf_rx, sizeof(buf_rx)); //CLIENT: SIZE AND INSTRUCTION OF PACKAGE RECEIVED

    imageReceived.clear();
    size = buf_rx.ID;
    instruction = buf_rx.instruction;
    
    char* temp = (char*)malloc(sizeof(char) * size);
    read(sockfd, temp, size); //CLIENT: WAITING FOR PACKAGE WITH THE IMAGE
    for(int i = 0; i < size; i++){
        imageReceived.push_back(*(temp+i));
    }

    struct message* answer;
    answer = ((struct message *)&buf_rx); //CLIENT: RETURNED THE STRUCT WITH THE DATA
       
    /* close the socket */
    close(sockfd); 
    
    return answer;
} 

class clientMock : public client {
public:
    MOCK_METHOD((struct message*), sendRequest, (struct message* request));
};

TEST(TestMockObject , sendRequestFirstCard){
    clientMock mock; 
    server serverToTest = server();
    serverToTest.start();
    int turn = serverToTest.turn;
    struct message* request = (struct message *)malloc(sizeof(struct message *));
    request->ID = 22;
    request->instruction = 0; 
    EXPECT_CALL(mock, sendRequest(request)).WillOnce(Return(request)); 
    serverToTest.buff_rx = (struct message)(*(mock.sendRequest(request)));
    // serverToTest.buff_rx = request;
    serverToTest.actualCardID = serverToTest.buff_rx.ID;
    serverToTest.start();
    serverToTest.matchedCards();
    serverToTest.checkWinner();
    EXPECT_TRUE(serverToTest.turn != turn && serverToTest.buff_rx.ID == request->ID && serverToTest.buff_tx.instruction == -1);

}

TEST(TestMockObject , sendRequestSecondCardMatched){
    clientMock mock; 
    server serverToTest = server();
    serverToTest.start();
    int turn = serverToTest.turn;
    struct message* request = (struct message *)malloc(sizeof(struct message *));
    request->ID = 22;
    request->instruction = 0; 
    EXPECT_CALL(mock, sendRequest(request)).WillOnce(Return(request));
    serverToTest.buff_rx = (struct message)(*mock.sendRequest(request));
    serverToTest.actualCardID = serverToTest.buff_rx.ID;
    serverToTest.start();
    serverToTest.matchedCards();
    serverToTest.checkWinner();
    serverToTest.start();
    serverToTest.matchedCards();
    serverToTest.checkWinner();
    EXPECT_TRUE(serverToTest.turn == turn && serverToTest.buff_rx.ID == request->ID && serverToTest.buff_tx.instruction == -1);
}

TEST(TestMockObject , sendRequestSecondCardNotMatched){
    clientMock mock; 
    server serverToTest = server();
    serverToTest.start();
    int turn = serverToTest.turn;
    struct message* request = (struct message *)malloc(sizeof(struct message *));
    request->ID = 22;
    request->instruction = 0;   
    EXPECT_CALL(mock, sendRequest(request)).WillOnce(Return(request));
    serverToTest.buff_rx = (struct message)(*mock.sendRequest(request));
    serverToTest.actualCardID = serverToTest.buff_rx.ID;
    serverToTest.start();
    serverToTest.matchedCards();
    serverToTest.checkWinner();
    request->ID = 88;
    serverToTest.buff_rx.ID = request->ID;
    serverToTest.actualCardID = request->ID;
    serverToTest.start();
    serverToTest.matchedCards();
    serverToTest.checkWinner();
    EXPECT_TRUE(serverToTest.turn == turn && serverToTest.buff_rx.ID == request->ID && serverToTest.buff_tx.instruction == -1);

}