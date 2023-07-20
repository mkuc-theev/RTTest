#include "RTPixel.h"

void RTPixel::stageA() {
    double u = this->xValue - 36.0;
    double v = 18.0 - this->yValue;
    double h = (u * u) + (v * v);
    if (h < 200) {
        stageB(h, u, v);
    }
    else if (v < 0) {
        stageC(h, u, v);
    }
    else {
        stageD();
    }
}

void RTPixel::stageB(double h, double u, double v) {
    this->R = 420.0;
    this->B = 520.0; 
    double t = 5000.0 + (8.0 * h);
    double p = (t * u) / 100.0;
    double q = (t * v) / 100.0;
    double s = 2.0 * q;
    double w = 1000.0 + p;
    w -= s;
    w /= 100.0;
    w += 8.0;
    if (w > 0) {
        this->R += w * w;
    }
    double o = s + 2200.0;
    this->R *= o;
    this->R /= 10000.0;
    this->B *= o;
    this->B /= 10000.0;
    if (p > -q) {
        w = (p + q) / 10.0;
        this->R += w;
        this->B += w;
    }
    stageE();
}

void RTPixel::stageC(double h, double u, double v) {
    this->R = 150.0 + (2.0 * v);
    this->B = 50.0;
    double p = h + (8.0 * v * v);
    double c = (240.0 * -v) - p;
    if (c > 1200) {
        double o = (6.0 * c) / 10.0;
        o = c * (1500.0 - o);
        o = (o / 100.0) - 8360.0;
        this->R *= o / 1000.0;
        this->B *= o / 1000.0;
    }
    double r = c + (u * v);
    double d = 3200.0 - h - (2 * r);
    if (d > 0) {
        this->R += d;
    }
    stageE();
}

void RTPixel::stageD() {
    double c = this->xValue + (4.0 * this->yValue);
    this->R = 132.0 + c;
    this->B = 192.0 + c;
    stageE();
}

void RTPixel::stageE() {
    if (this->R > 255) {
        this->R = 255.0;
    }
    if (this->B > 255) {
        this->B = 255.0;
    }
    this->G = (7.0 * this->R) + (3.0 * this->B);
    this->G /= 10;
}

RTPixel::RTPixel(int x, int y) {
    this->xPos = x;
    this->yPos = y;
    this->xValue = xPos * ZOOM_LEVEL / RES_W * SQUISH_RATIO;
    this->yValue = yPos * ZOOM_LEVEL / RES_H;
    this->A = 255.0;

    stageA();
}

int RTPixel::getXPos() {
    return this->xPos;
}

int RTPixel::getYPos() {
    return this->yPos;
}

int RTPixel::getR() {
    return (int)this->R;
}

int RTPixel::getG() {
    return (int)this->G;
}

int RTPixel::getB() {
    return (int)this->B;
}

int RTPixel::getA() {
    return (int)this->A;
}