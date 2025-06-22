#include<iostream>
#include<fstream>
#include<cmath>
#include<string>

const int WIDTH = 1920;
const int HEIGTH = 1080;
const int MAX_COLOR_COMPONENT = 255;

template<int TopLeftX, int TopLeftY, int Width, int Height>
bool rectFigure(int x, int y) {
    return (x >= TopLeftX && x < TopLeftX + Width && y >= TopLeftY && y < TopLeftY + Height);
}


template<int CenterX, int CenterY, int Radius>
bool circleFigure(int x, int y) {
    int dx = x - CenterX;
    int dy = y - CenterY;
    return dx*dx + dy*dy <= Radius*Radius;
}


template<int F1X, int F1Y, int F2X, int F2Y, int MajorAxisLength>
bool ellipseFigure(int x, int y) {
    int dx1 = x - F1X;
    int dy1 = y - F1Y;
    int dx2 = x - F2X;
    int dy2 = y - F2Y;
    double distToF1 = std::sqrt(dx1*dx1 + dy1*dy1);
    double distToF2 = std::sqrt(dx2*dx2 + dy2*dy2);
    return (distToF1 + distToF2) <= MajorAxisLength;
}


int main() {
    std::string outputFile("task2.ppm");

    std::ofstream file(outputFile, std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    file << "P3\n" << WIDTH << " " << HEIGTH << "\n" <<MAX_COLOR_COMPONENT << "\n";

    for (int y = 0; y < HEIGTH; y++) {
        for (int x = 0; x < WIDTH; x++) {
            bool inside = rectFigure<100, 100, 400, 300>(x, y) || 
            circleFigure<1600, 300, 200>(x, y) || 
            ellipseFigure<650, 800, 1270, 800, 1000>(x, y);

            if (inside) {
                file << 0 << " " << 0 << " " << 128 << "\t";
            } else {
                file << 128 << " " << 128 << " " << 128 << "\t";
            }
        }
        file << "\n";
    }
    return 0;
}
