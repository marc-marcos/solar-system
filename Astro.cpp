#include "Astro.hh"
#include <cmath>
#include <iostream>

// One day is one second
#define TIME_SCALE 24*3600*100


Astro::Astro(float radius, int red, int green, int blue, Estrella estrella, double periodo, int distancia_orbital, float angulo_inicial)
    : radius(radius), red(red), green(green), blue(blue), estrella_orbitada(estrella), periodo(periodo), distancia_orbital(distancia_orbital), angulo_inicial(angulo_inicial) {
        x = y = 0;
}

void Astro::recalculate_position(sf::Time time_elapsed) {
    float velocidad_angular = TIME_SCALE * 4 * M_PI * (1/(periodo*24*3600));

    float angulo = velocidad_angular * time_elapsed.asSeconds() + angulo_inicial;

    x = this->estrella_orbitada.x + this->estrella_orbitada.radius + std::sin(angulo)*this->distancia_orbital - this->radius;
    y = this->estrella_orbitada.y + this->estrella_orbitada.radius + std::cos(angulo)*this->distancia_orbital - this->radius;
}