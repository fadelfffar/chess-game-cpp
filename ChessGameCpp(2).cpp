#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>

class ChessBoard {
public:
    // Constructor
    ChessBoard();

    // Functions for moving pieces
    void movePiece(int fromRow, int fromCol, int toRow, int toCol);
    void capturePiece(int row, int col);
    bool isSquareAttacked(int row, int col, char player);

    // Functions for checking for wins or draws
    bool isKingInCheck(char player);
    bool isGameOver();

private:
    // The chess board represented as a 2D vector of characters
    std::vector<std::vector<char>> board;

    // The current player (either 'x' or 'o')
    char player;

    // Functions for updating the board and player after a move
    void updateBoard(int fromRow, int fromCol, int toRow, int toCol);
    void updatePlayer();
};

class ChessPiece {
public:
    // Constructor
    ChessPiece(char player, int row, int col);

    // Functions for moving the piece on the board
    void move(int toRow, int toCol);
    void capture(int row, int col);

    // Functions for checking if the piece is in check
    bool isInCheck(char player);

private:
    // The player that the piece belongs to ('x' or 'o')
    char player;

    // The row and column of the piece on the board
    int row, col;

    // Functions for updating the row and column of the piece
    void updatePosition(int row, int col);
};

class ChessGame {
public:
    // Constructor
    ChessGame();

    // Functions for making a move
    void makeMove(int row, int col);
    void resign();

    // Functions for checking if the game is over
    bool isGameOver();

    // Functions for getting the current board state and player
    std::vector<std::vector<char>> getBoardState();
    char getPlayer();

private:
    // The chess board
    ChessBoard board;

    // The current player
    char player;

    // A list of moves made in the game
    std::vector<std::string> moves;

    // Functions for making a move and updating the game state
    void updateBoard(int row, int col);
    void updatePlayer();
    void updateMoves(int row, int col);
};

// Function to print the chess board
void printBoard(ChessBoard board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << board.board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to draw the chess board on the screen
void drawBoard(sf::RenderWindow& window, ChessBoard board) {
    // Clear the window
    window.clear();

    // Draw the chess board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            // Draw the square
            sf::RectangleShape square(sf::Vector2f(50, 50));
            square.setPosition(j * 50, i * 50);
            if (board.board[i][j] == ' ') {
                square.setFillColor(sf::Color::White);
            } else if (board.board[i][j] == 'x') {
                square.setFillColor(sf::Color::Red);
            } else if (board.board[i][j] == 'o') {
                square.setFillColor(sf::Color::Blue);
            }
            window.draw(square);

            // Draw the piece
            if (board.board[i][j] == 'k') {
                sf::CircleShape king(30);
                king.setPosition(j * 50 + 25, i * 50 + 25);
                king.setFillColor(sf::Color::Black);
                window.draw(king);
            } else if (board.board[i][j] == 'q') {
                sf::CircleShape queen(30);
                queen.setPosition(j * 50 + 25, i *
            }