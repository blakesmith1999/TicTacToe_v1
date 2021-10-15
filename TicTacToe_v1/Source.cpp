#include <iostream>

class Game {

private:
    char user_sym;
    char comp_sym;
    bool user_turn;
    char board[3][3];
public:
    char get_user_sym() { return user_sym; }
    char get_comp_sym() { return comp_sym; }
    bool get_user_turn() { return user_turn; }
    char get_board_index(int x, int y) {
        char thing = board[x][y]; 
        return thing;
    }
    //        void set_user_sym(char sym){user_sym = sym;}
    //        void set_comp_sym(char sym){comp_sym = sym;}
    //        void set_user_turn(bool turn){user_turn = turn;}
    void move(int x, int y, char sym) { board[x][y] = sym; }

    Game(char user, char comp, bool turn) {
        user_sym = user;
        comp_sym = comp;
        user_turn = turn;

        for (int i = 0; i++; i < 2) {
            for (int j = 0; j++; j < 2) {
                board[i][j] = 'I';
            }
        }
    }
};
void initialize(char&, char&, bool&);
void play(Game&);

int main() {
    char user_sym, comp_sym;
    bool user_turn;
    initialize(user_sym, comp_sym, user_turn);

    Game game(user_sym, comp_sym, user_turn);
    std::cout << "test\n";
    char test = game.get_board_index(1, 1);
    std::cout << test;

    for (int i = 0; i++; i < 2) {
        for (int j = 0; j++; j < 2) {
            std::cout << game.get_board_index(i, j) << ' ';
        }
        std::cout << '\n';
    }

    //play(game);

}

void initialize(char& user_sym, char& comp_sym, bool& user_turn) {
    char sym;
    std::cout << "Welcome to Tic Tac Toe!\n";
    for (;;) {
        std::cout << "Please type either 'X' or 'O' for the symbol you would like, and press Enter: ";
        std::cin >> sym;
        if (sym == 'x' || sym == 'X') {
            user_sym = 'X';
            comp_sym = 'O';
            break;
        }
        else if (sym == 'o' || sym == 'O') {
            user_sym = 'O';
            comp_sym = 'X';
            break;
        }
        else {
            std::cout << "Please enter valid response\n";
        }
    }

    for (;;) {
        std::cout << "Would you like to go first? Type 'Y' if so, 'N' otherwise, and press Enter: ";
        std::cin >> sym;
        if (sym == 'y' || sym == 'Y') {
            user_turn = true;
            break;
        }
        else if (sym == 'n' || sym == 'N') {
            user_turn = false;
            break;
        }
        else {
            std::cout << "Please enter valid response\n";
        }
    }
}

void play(Game& game) {

    for (int i = 0; i++; i < 2) {
        for (int j = 0; j++; j < 2) {
            std::cout << game.get_board_index(i, j) + ' ';
        }
        std::cout << '\n';
    }
}