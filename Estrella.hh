#ifndef ESTRELLA_HH 
#define ESTRELLA_HH 

class Estrella {
    public:
        int x;
        int y;
        float radius;
        int red;
        int green;
        int blue;
        Estrella(int x, int y, float radius, int red, int green, int blue);
        ~Estrella(){};
};

#endif