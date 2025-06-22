#include<iostream>
#include<fstream>
#include<random>
#include<string>

int main() {
    std::string outputFile("task1.ppm");

    const unsigned int WIDTH = 1920;
    const unsigned int HEIGTH = 1080;
    const unsigned int MAX_COLOR_COMPONENT = 255;
    const int RECT_PER_ROW = 7;
    const int RECT_PER_COLUMN = 5;


    std::random_device rd;             
    std::default_random_engine engine(rd());
    std::uniform_int_distribution<int> random_gen(0, MAX_COLOR_COMPONENT);

    const int RECT_WIGTH = WIDTH / RECT_PER_ROW;
    const int RECT_HEIGTH = HEIGTH / RECT_PER_COLUMN;
    const int HALF_MAX_COLOR_COMPONENT = MAX_COLOR_COMPONENT / 2 ;

    std::ofstream file(outputFile ,  std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Error: Unable to open file.\n";
        return 1;
    }

    file << "P3\n";
    file << WIDTH << " " << HEIGTH << "\n"; 
    file << MAX_COLOR_COMPONENT << "\n";

    for (int y = 0; y < HEIGTH; y++) {
        unsigned int blockY = y / RECT_HEIGTH;
        for (int x = 0; x < WIDTH; x++) {

            unsigned int blockX = x / RECT_WIGTH;
            int main_color = (blockY * RECT_PER_ROW + blockX) % 3;

            int r = (main_color == 0) ? HALF_MAX_COLOR_COMPONENT/2 : random_gen(engine);
            int g = (main_color == 1) ? HALF_MAX_COLOR_COMPONENT/2 : random_gen(engine);
            int b = (main_color == 2) ? HALF_MAX_COLOR_COMPONENT/2 : random_gen(engine);
            file << r << " " << g << " " << b << "  ";
        }
        file << "\n";   
    }

    file.close();
}
