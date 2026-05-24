#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

const int WIDTH  = 1920;
const int HEIGHT = 1080;

const double X_MIN = -10.00f;
const double Y_MIN = -10.00f;
const double X_MAX = 10.00f;
const double Y_MAX = 10.00f;

double fn(double x) {
    return sin(x);
}

int main() {
    vector<unsigned char> image(WIDTH * HEIGHT * 3, 255);

    auto setPixel = [&](int x, int y, int r, int g, int b) {
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
            int index        = (y * WIDTH + x) * 3;
            image[index]     = r;
            image[index + 1] = g;
            image[index + 2] = b;
        }
    };

    int xAxis = (int) ((0 - Y_MIN) / (Y_MAX - Y_MIN) * (HEIGHT - 1));
    int yAxis = (int) ((0 - X_MIN) / (X_MAX - X_MIN) * (WIDTH - 1));

    for (int x = 0; x < WIDTH; x++) {
        setPixel(x, HEIGHT - 1 - xAxis, 0, 0, 0);
    }

    for (int y = 0; y < HEIGHT; y++) setPixel(yAxis, y, 0, 0, 0);

    for (int i = 0; i < WIDTH; i++) {
        double x = X_MIN + i * (X_MAX - X_MIN) / (WIDTH - 1);
        double y = fn(x);

        int pixelY = (int) ((y - Y_MIN) / (Y_MAX - Y_MIN) * (HEIGHT - 1));
        pixelY     = HEIGHT - 1 - pixelY;

        setPixel(i, pixelY, 255, 0, 0);
    }

    ofstream file("graph.ppm");
    file << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

    for (int i = 0; i < WIDTH * HEIGHT * 3; i += 3) {
        file << (int) image[i] << " " << (int) image[i + 1] << " "
             << (int) image[i + 2] << "\n";
    }

    file.close();

    cout << "Graph saved as graph.ppm\n";

    return 0;
}
