#pragma once
#include <SFML/Graphics.hpp>

const int RES_W = 1920;
const int RES_H = 1080;
const double SQUISH_RATIO = 3.15752575523;
const double ZOOM_LEVEL = 22.82;

class RTPixel {
private: 

       double xValue;
       double yValue;
       int xPos;
       int yPos;
       double R;
       double G;
       double B;
       double A;

       void stageA();
       void stageB(double h, double u, double v);
       void stageC(double h, double u, double v);
       void stageD();
       void stageE();

public:

       RTPixel(int x, int y);
       int getXPos();
       int getYPos();
       int getR();
       int getG();
       int getB();
       int getA();

};