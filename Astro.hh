#ifndef ASTRO_HH
#define ASTRO_HH

#include "Estrella.hh"

#include <SFML/Graphics.hpp>

class Astro {
    public:
        int x;
        int y;
        int distancia_orbital;
        float radius;
        int red;
        int green;
        int blue;
        float angulo_inicial;

        double periodo;
        Estrella estrella_orbitada;

        Astro(float radius, int red, int green, int blue, Estrella estrella, double periodo, int distancia_orbital, float angulo_inicial);
        ~Astro(){};

        void recalculate_position(sf::Time time_since_start);
};

#endif