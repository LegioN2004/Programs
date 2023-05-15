#include <iostream>
#include <cmath>
#include <chrono>
#include <thread>

const int Width = 80;
const int Height = 24;
const double Scale = 0.04;
const std::chrono::milliseconds AnimationDelay(50);

char grayScaleToChar(int gray) {
    const std::string chars = "@%#*+=-:. ";
    if (gray < 0) {
        gray = 0;
    }
    if (gray >= chars.length()) {
        gray = chars.length() - 1;
    }
    return chars[gray];
}

int main() {
    while (true) {
        for (int i = 0; i < Height; i++) {
            for (int j = 0; j < Width; j++) {
                double x = static_cast<double>(j) * 0.5;
                double y = static_cast<double>(i) * 0.2;

                double z1 = std::sin(x * Scale) + std::cos(y * Scale);
                double z2 = std::sin((x + 1) * Scale) + std::cos(y * Scale);
                double z3 = std::sin(x * Scale) + std::cos((y + 1) * Scale);
                double z4 = std::sin((x + 1) * Scale) + std::cos((y + 1) * Scale);

                double average = (z1 + z2 + z3 + z4) / 4.0;
                int gray = static_cast<int>(average * 10.0 + 10.0);

                std::cout << grayScaleToChar(gray);
            }
            std::cout << std::endl;
        }

        std::this_thread::sleep_for(AnimationDelay);
        std::cout << "\033[H\033[2J"; // Clear the terminal screen
    }

    return 0;
}

