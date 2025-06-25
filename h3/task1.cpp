#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

struct Vector3 {
    float _x, _y, _z;
    Vector3(float x=0, float y=0, float z=0) : _x(x), _y(y), _z(z) {}

    Vector3 getNormalized() const {
        float len = length();
        return Vector3(_x / len, _y / len, _z / len);
    }
    void normalize() {
        float len = length();
        _x /= len;
        _y /= len;
        _z /= len;
    }

    float dotProduct(const Vector3& other) const {
        return _x * other._x + _y * other._y + _z * other._z;
    }
    float length() const {
        return std::sqrt( this -> dotProduct( *this ) );
    }
};


int main() {
    std::string outputFile("3_task1.ppm");

    const unsigned int IMAGE_WIDTH = 1920, IMAGE_HEIGTH = 1080, MAX_COLOR_COMPONENT = 255;
    const float ASPECT = float(IMAGE_WIDTH) / IMAGE_HEIGTH;


    std::ofstream file(outputFile ,  std::ios::out | std::ios::binary);
    if (!file) {
        std::cerr << "Error: Unable to open file.\n";
        return 1;
    }

    file << "P3\n";
    file << IMAGE_WIDTH << " " << IMAGE_HEIGTH << "\n"; 
    file << MAX_COLOR_COMPONENT << "\n";

    for(size_t rowIdx = 0; rowIdx < IMAGE_HEIGTH; rowIdx++){
        for(size_t colIdx = 0; colIdx < IMAGE_WIDTH; colIdx++){
            float x = (float(colIdx) + 0.5) / IMAGE_WIDTH;
            float y = (float(rowIdx) + 0.5) / IMAGE_HEIGTH;
            x = (2.0 * x) - 1.0;
            y = 1.0 - (2.0 * y);
            x *= ASPECT;

            Vector3 vec(x , y, 0);
            vec.normalize();

            /*
            My representation for the colors is to shift them from [-1 , 1] 
            to [0 , 1] and multiply by 255
            */
            int r = ((vec._x + 1) / 2) * MAX_COLOR_COMPONENT;
            int g = ((vec._y + 1) / 2) * MAX_COLOR_COMPONENT;
            int b = ((vec._z + 1) / 2) * MAX_COLOR_COMPONENT;
            file << r << " " << g << " " << b << "\n";
        }

    }

    file.close();
}
