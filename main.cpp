#include <iostream>
#include <graphics.h>
#include <unistd.h>

const int pixelSize = 40;

//Created with/for SDL_bgi

int pixel(int x, int y) {
    setfillstyle(SOLID_FILL, RED);
    //rectangle(x*pixelSize, ((getmaxy() - y)*pixelSize), (x*pixelSize) + pixelSize, (((getmaxy()) - y)*pixelSize) - pixelSize);
    floodfill(x*pixelSize+1, (getmaxy() - y*pixelSize) - 1, WHITE);
    return 0;
}

int midpointError(int dx, int dy) {
    int ey = dy;
    int ex = 0;
    if (dy % 2 == 0) {ex = dx;};
    if (dx % 2 == 0) {
        ey = 2*dy;
        if (dy % 2 == 0) { ex = 2*dx; };
    };
    return ey - ex;
}

int brese(int x0, int y0, int x1, int y1, bool mirror = false, bool midpoint = false) {
    int dy = abs(y1 - y0);
    int dx = abs(x1 - x0);
    const int cx = x0 < x1 ? 1 : -1;
    const int cy = y0 < y1 ? 1 : -1;
    int error;
    //int delay = round(abs(dx)/4);
    int delay;
    bool flip = false;
    if (dy > dx) {
        flip = true;
        int temp = dx;
        dx = dy;
        dy = temp;
    };
    if (!midpoint) {
        error = 2*dy - dx;
        if (mirror) {delay = round(abs(dx)/4);} else {delay = abs(dx);}
    } else {
        error = midpointError(abs(dx), abs(dy));
        if (mirror) {delay = round(abs(dx/4));} else {delay = abs(dx);}
    };
    for(int i = 0; i <= delay; i++) {
        pixel(x0, y0);
        //pixel(x1, y1);
        if (error >= 0) {
            error += (2 * dy - 2 * dx);
            x0 += cx;
            y0 += cy;
            if (mirror) {
                x1 -= cx;
                y1 -= cx;
            }
        } else {
            error += (2 * dy);
            if (flip) {
                y0 += cy;
                if (mirror) {y1 -= cy;};
            } else {
                x0 += cx;
                if (mirror) {x1 -= cx;};
            }
        };
    }
    return 0;
}

int main() {
    //initiate window to correct size
    int size = 32;
    int resolution = pixelSize * size;
    initwindow(resolution, resolution);
    //grid creation
    for (int i = 0; i <= resolution; i += pixelSize) {
        rectangle(i, 0, i, resolution);
        rectangle(0, i, resolution, i);
    };
    brese(0, 0, 31, 5, false);
    //write changes to screen
    refresh();
    //wait until a character is pressed
    getch();
    return 0;
};

int quadLine(int x0, int y0, int x1, int y1) {
    //int dy = abs(y1 - y0);
    //int dx = abs(x1 - x0);
    //brese(x0, y0, x1, y1, pixelSize, true);
    return 0;
}