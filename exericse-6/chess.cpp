//
// Created by Trym Hamer Gudvangen on 10/1/23.
//

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ChessBoard {
public:
    enum class Color { WHITE,
        BLACK };

    class Piece {
    public:
        explicit Piece(Color color, char symbol) : color(color), symbol(symbol) {}
        virtual ~Piece() = default;

        Color color;
        char symbol;
        std::string color_string() const {
            if (color == Color::WHITE)
                return "white";
            else
                return "black";
        }

        /// Return color and type of the chess piece
        virtual std::string type() const = 0;

        /// Returns true if the given chess piece move is valid
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    };

    class King : public Piece {
    public:
        explicit King(Color color) : Piece(color, 'K') {}
        std::string type() const override{
            return this->color_string() + " king";
        }

        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return ::abs(from_x - to_x) <= 1 && ::abs(from_y - to_y) <= 1;
        }
    };

    class Knight : public Piece {
    public:
        explicit Knight(Color color): Piece(color, '7') {}
        std::string type() const override{
            return this->color_string() + " knight";
        }
        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            if (::abs(from_x - to_x) == 2){
                return ::abs(from_y - to_y) == 1;
            }
            else if (::abs(from_y - to_y) == 2) {
                return ::abs(from_x - to_x) == 1;
            }
            else {
                return false;
            }
        }
    };

    ChessBoard() {
        // Initialize the squares stored in 8 columns and 8 rows:
        squares.resize(8);
        for (auto &square_column : squares)
            square_column.resize(8);
    }

    /// 8x8 squares occupied by 1 or 0 chess pieces
    vector<vector<unique_ptr<Piece>>> squares;

    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move;
    function<void(const Piece &piece, const string &square)> on_piece_removed;
    function<void(Color color)> on_lost_game;
    function<void(const Piece &piece, const string &from, const string &to)> on_piece_move_invalid;
    function<void(const string &square)> on_piece_move_missing;
    function<void()> after_piece_move;

    /// Move a chess piece if it is a valid move.
    /// Does not test for check or checkmate.
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string() + from[1]) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string() + to[1]) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from) {
            if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
                if(on_piece_move){
                    on_piece_move(*piece_from, from, to);
                }
                auto &piece_to = squares[to_x][to_y];
                if (piece_to) {
                    if (piece_from->color != piece_to->color) {
                        if(on_piece_removed)
                            on_piece_removed(*piece_to, to);
                        if (auto king = dynamic_cast<King *>(piece_to.get())){
                            if(on_lost_game)
                                on_lost_game(king->color);
                        }
                    } else {
                        if(on_piece_move_invalid)
                            on_piece_move_invalid(*piece_from, from, to);
                        return false;
                    }
                }
                piece_to = std::move(piece_from);
                after_piece_move();
                return true;
            } else {
                if(on_piece_move_invalid)
                    on_piece_move_invalid(*piece_from, from, to);
                return false;
            }
        } else {
            if(on_piece_move_missing)
                on_piece_move_missing(from);
            return false;
        }
    }



};

class ChessBoardPrint {
public:
    char chessboard_print[2 * 8 + 2][6 * 8 + 3] = {
            {' ', ' ', ' ', ' ', ' ',  'A',  ' ', ' ', ' ', ' ', ' ', 'B',  ' ', ' ', ' ', ' ', ' ', 'C',  ' ', ' ', ' ', ' ', ' ', 'D',  ' ', ' ', ' ', ' ', ' ', 'E',  ' ', ' ', ' ', ' ', ' ', 'F',  ' ', ' ', ' ', ' ', ' ', 'G',  ' ', ' ', ' ', ' ', ' ', 'H', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ',  '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' ', ' '},
            {'8', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|'},
            {' ', ' ', ' ', ' ', ' ',  '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' '},
            {'7', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|'},
            {' ', ' ', ' ', ' ', ' ',  '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' '},
            {'6', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|'},
            {' ', ' ', ' ', ' ', ' ',  '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' '},
            {'5', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|'},
            {' ', ' ', ' ', ' ', ' ',  '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' '},
            {'4', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|'},
            {' ', ' ', ' ', ' ', ' ',  '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' '},
            {'3', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|'},
            {' ', ' ', ' ', ' ', ' ',  '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' '},
            {'2', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|'},
            {' ', ' ', ' ', ' ', ' ',  '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' '},
            {'1', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|', ' ', ' ', ' ', ' ', ' ', '|'},
            {' ', ' ', ' ', ' ', ' ',  '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-',  ' ', ' ', ' ', ' ', ' ', '-', ' ', ' ', ' '},

    };
    explicit ChessBoardPrint(ChessBoard &chessBoard){
        chessBoard.on_piece_move = [](const ChessBoard::Piece &piece, const string &from, const string &to){
            cout << piece.type() << " is moving from " << from << " to " << to << endl;
        };
        chessBoard.on_piece_removed = [](const ChessBoard::Piece &piece_to, const std::string &square){
            cout << piece_to.type() << " is being removed from " << square << endl;
        };
        chessBoard.on_lost_game = [](const ChessBoard::Color color) {
            if (color == ChessBoard::Color::WHITE)
                cout << "white" << " lost the game" << endl;
            else
                cout << "black" << " lost the game" << endl;
        };
        chessBoard.on_piece_move_missing = [](const string &square){
            cout << "no piece at " << square << endl;
        };
        chessBoard.on_piece_move_invalid = [](const ChessBoard::Piece &piece, const string &from, const string &to){
            cout << "can not move " << piece.type() << " from " << from << " to " << to << endl;
        };
        chessBoard.after_piece_move = [&chessBoard, this]() {
            for(int i = 0; i < chessBoard.squares.size(); i++) {
                for(int j = 0; j < chessBoard.squares[0].size(); j++) {
                    if(chessBoard.squares[j][i] != nullptr){
                        this->chessboard_print[2 + 2 * i][5 + j * 6] = chessBoard.squares[j][i]->symbol;
                    }
                }
            }

            for (auto& row : this->chessboard_print) {
                for(auto& column : row){
                    std::cout << column;
                }
                std::cout << '\n';
            }
        };
    }

//    void print_board() {
//        for(int i = 0; i < squares.size(); i++) {
//            for(int j = 0; j < squares[0].size(); j++) {
//                if(squares[j][i] != nullptr){
//                    this->chessboard[2 + 2 * i][5 + j * 6] = squares[j][i]->symbol;
//                }
//            }
//        }
//
//        for (auto& row : this->chessboard) {
//            for(auto& column : row){
//                std::cout << column;
//            }
//            std::cout << '\n';
//        }
//    }

};

int main() {
    ChessBoard board;
    ChessBoardPrint print(board);

    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
    board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    cout << "Invalid moves:" << endl;
    board.move_piece("e3", "e2");
    board.move_piece("e1", "e3");
    board.move_piece("b1", "b2");
    cout << endl;

    cout << "A simulated game:" << endl;
    board.move_piece("e1", "e2");
    board.move_piece("g8", "h6");
    board.move_piece("b1", "c3");
    board.move_piece("h6", "g8");
    board.move_piece("c3", "d5");
    board.move_piece("g8", "h6");
    board.move_piece("d5", "f6");
    board.move_piece("h6", "g8");
    board.move_piece("f6", "e8");
}