#include <iostream>
#include <graphics.h>
#include <unistd.h>

//Created with/for SDL_bgi

int pixel(int x, int y, int pixelSize) {
    setfillstyle(SOLID_FILL, WHITE);
    rectangle(x, ((getmaxy() - y)), x + pixelSize, ((getmaxy()) - y) - pixelSize);
    floodfill(x+1, (getmaxy() - y) - 1, WHITE);
    return 0;
}

int brese(int x0, int y0, int x1, int y1, int pixelSize, bool midpoint = false) {
    int dy = abs(y1 - y0);
    int dx = abs(x1 - x0);
    const int cx = x0 < x1 ? 1 : -1;
    const int cy = y0 < y1 ? 1 : -1;
    int error;
    int delay = round(abs(dx)/4);
    int flip = 0;
    if (dy > dx) {
        flip = 1;
        int temp = dx;
        dx = dy;
        dy = temp;
    };
    if (midpoint == false) {
        error = 2*dy - dx;
    } else {
        delay++;
        int ey = dy;
        int ex = 0;
        if (dy % 2 == 0) {ex = dx;};
        if (dx % 2 == 0) {
            ey = 2*dy;
            if (dy % 2 == 0) {
                ex = 2*dx;
            };
        };
        error = ey - ex;
    };
    for(int i; i < delay; i++) {
    }
    pixel(0, 0, pixelSize);
    return 0;
}

int main() {
    //initiate window to correct size
    std::cout << "SUCCESSFUL";
    int size = 31;
    int pixelSize = 40;
    int resolution = pixelSize * size;
    initwindow(resolution, resolution);
    //grid creation
    for (int i = 0; i < resolution; i += pixelSize) {
        //std::cout << i << "\n";
        std::cout << "TEST";
        rectangle(i, 0, i, resolution);
        rectangle(0, i, resolution, i);
    };
    brese(0, 0, 10, 10, pixelSize, false);
    refresh();
    getch();
    return 0;
};

int errorCalc(int dx, int dy, int mode) {
    return 0;
}
int quadLine(int x0, int y0, int x1, int y1, int pixelSize) {
    //int dy = abs(y1 - y0);
    //int dx = abs(x1 - x0);
    //brese(x0, y0, x1, y1, pixelSize, true);
    return 0;
}