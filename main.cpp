#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <random>
namespace utils {
    bool is_normal_location(std::vector<std::pair<int, int>>& coords, std::vector<std::vector<int>>& matrix) {
        for (auto& coord : coords) {
            if (coord.first < 0 || coord.first >= matrix.size() || coord.second < 0 || coord.second >= matrix[0].size()) {
                return false;
            }
            if (matrix[coord.first][coord.second] != 0) {
                return false;
            }
        }   
        return true;
    }
    AbstractToken* create_random_token() {
        static std::mt19937 random_number_generator(std::random_device{}());
        std::uniform_int_distribution<int> token_choice_distribution(0, 1);
        const int token_choice = token_choice_distribution(random_number_generator);
        if (token_choice == 0) {
            return new ZToken();
        }
        return new IToken();
    }
}
namespace start_coords{
    using list = std::vector<std::pair<int, int>>;
    list z_coords = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
    list i_coords = {{0, 0}, {1, 0}, {2, 0}, {3, 0}};
}
const int figure_start_place_x = 0;
const int figure_start_place_y = 0;

class AbstractToken {   
public:
    std::vector<std::pair<int, int>>& GiveCoords() {
        return coords_;
    }
    virtual void rotate() = 0;
    virtual ~AbstractToken() {}
    std::vector<std::pair<int, int>> coords_;
    int location = 1;
private:

};
class ZToken : public AbstractToken {
public:
    ZToken() {
        coords_ = start_coords::z_coords;
        location = 1;
    }
    void rotate() override {
        if (location == 1) {
            ++coords_[0].first;
            ++coords_[1].second;
            ++coords_[2].first;
            ++coords_[3].second;
        } else if (location == 2) {
        }
    }

};
class IToken : public AbstractToken {
public:
    IToken() {
        coords_ = start_coords::i_coords;
        location = 1;
    }
    void rotate() override {
        if (location == 1) {
            ++coords_[0].first;
        }
    }
};


class View {
public:
    static std::vector<std::vector<int>> matrix;
    View() {
    }
    void Demo() {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }

};

// Static storage and initialization for View::matrix
std::vector<std::vector<int>> View::matrix(10, std::vector<int>(10, 0));

class Game {
public:
    Game() {
        view_ = new View();
    }
    ~Game() {
        delete view_;
    }
    void Start() {
        while (true) {
            view_->Demo();
            std::this_thread::sleep_for(std::chrono::seconds(1));
            
        }
        view_->Demo();
    }
private:
    View* view_;

};

int main() {
    View view;
    view.Demo();
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    for (auto& i : v) {
        i++;
    }
    for (auto& i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Пауза на 1 секунду
        view.matrix[i][i] = 1;
        system("clear");
        view.Demo();
    }
}