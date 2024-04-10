#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>

#include <SFML/Graphics.hpp>

#include "Astro.hh"
#include "Estrella.hh"

#define SCREEN_HEIGHT 1000
#define SCREEN_WIDTH 1000

#define ORBIT_DISTANCE 50

int main()
{
    srand(time(NULL));

    // Create an instance of sf::RenderWindow instead of sf::Window
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Hello World");

    // Crear el vector para almacenar todos los astros
    std::vector<Astro> planetas;
    Estrella sol = Estrella(SCREEN_WIDTH / 2 - 20, SCREEN_HEIGHT / 2 - 20, 20.0f, 253, 184, 19);


    // Añadir cosas al vector de planetas

    // Mercury
    float random = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (4)));
    planetas.push_back(Astro(10.0f, 183, 184, 185, sol, 88, ORBIT_DISTANCE, random));

    // Venus
    random = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (4)));
    planetas.push_back(Astro(10.0f, 165, 124, 27, sol, 255, ORBIT_DISTANCE * 2, random));

    // Earth
    random = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (4)));
    planetas.push_back(Astro(10.0f, 107, 147, 214, sol, 365, ORBIT_DISTANCE * 3, random));

    // Mars
    random = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (4)));
    planetas.push_back(Astro(10.0f, 193, 68, 14, sol, 365 + 321, ORBIT_DISTANCE * 4, random));

    // Jupiter
    random = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (4)));
    planetas.push_back(Astro(10.0f, 80, 121, 146, sol, 11 * 365 + 315, ORBIT_DISTANCE * 5, random));

    // Saturn
    random = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (4)));
    planetas.push_back(Astro(10.0f, 206, 184, 184, sol, 29 * 365 + 167, ORBIT_DISTANCE * 6, random));

    // Uranus
    random = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (4)));
    planetas.push_back(Astro(10.0f, 172, 229, 238, sol, 84 * 365, ORBIT_DISTANCE * 7, random));

    // Neptune
    random = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (4)));
    planetas.push_back(Astro(10.0f, 120, 192, 168, sol, 164 * 365 + 280, ORBIT_DISTANCE * 8, random));

    // Create a circle shape
    std::vector<sf::CircleShape> shapes;
    for (auto it : planetas)
    {
        sf::CircleShape shape_ow(it.radius);
        shape_ow.setFillColor(sf::Color(it.red, it.green, it.blue));
        shapes.push_back(shape_ow);
    }

    // Añadir la shape del sol

    sf::CircleShape sol_shape(sol.radius);
    sol_shape.setFillColor(sf::Color(sol.red, sol.green, sol.blue));
    sol_shape.setPosition(sol.x, sol.y);
    shapes.push_back(sol_shape);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window
        window.clear();

        for (auto it : planetas)
        {
            it.recalculate_position(elapsed);

            sf::CircleShape shape(it.radius);
            shape.setFillColor(sf::Color(it.red, it.green, it.blue));
            shape.setPosition(it.x, it.y);
            window.draw(shape);
        }

        window.draw(sol_shape);

        // Display what was drawn
        window.display();
    }

    return 0;
}