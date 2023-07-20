#include <iostream>
#include <stdlib.h>
#include "RTPixel.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(RES_W, RES_H, 32), "RTTest");

    sf::Uint8* pixels = new sf::Uint8[RES_W * RES_H * 4];

    for (register int i = 0; i < RES_W * RES_H * 4; i += 4) {
        int xIndex = (i / 4) % RES_W;
        int yIndex = (i / 4) / RES_H;
        RTPixel pixel(xIndex, yIndex);
        pixels[i] = (sf::Uint8)pixel.getR();
        pixels[i + 1] = (sf::Uint8)pixel.getG();
        pixels[i + 2] = (sf::Uint8)pixel.getB();
        pixels[i + 3] = (sf::Uint8)pixel.getA();
    }

    system("cls");
    std::cout << "Done!\n";

    sf::Texture texture;
    texture.create(RES_W, RES_H);
    texture.update(pixels);

    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}