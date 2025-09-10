#include <iostream>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
namespace start_coords{
    using list = std::vector<std::pair<int, int>>;
    list z_coords = {{0, 0}, {1, 0}, {1, 1}, {2, 1}};
    list i_coords = {{}};
}
const int figure_start_place_x = 0;
const int figure_start_place_y = 0;

class AbstractToken {
public:
    std::vector<std::pair<int, int>>& GiveCoords() {
        return coords_;
    }
    virtual void rotate() = 0;
    std::vector<std::pair<int, int>> coords_;
    int location = 1;
private:

};
class ZToken : public AbstractToken {
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
    IToken() {

    }
};


class View {
public:
    std::vector<std::vector<int>> matrix;
    View() : matrix(10, std::vector<int>(10, 0)) {
    }
    void Demo() {
        for (int i = 0; i < 1; ++i) {
            for (int j = 0; j < 10; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    View view;
    view.Demo();
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Пауза на 1 секунду
        view.matrix[i][i] = 1;
        system("clear");
        view.Demo();
    }
}