

#include <iostream>


class Punto{
private:

    int lat; // Latitud
    int lon; // Longitud

public:
    Punto(int lat=0, int lon=0) : lat(lat), lon(lon) {}
    Punto(const Punto& rhs){if((*this)!= rhs ){ this->lat = rhs.lat; this->lon = rhs.lon};}
    Punto& operator=(const Punto& rhs){this->lat = rhs.lat; this->lon = rhs.lon;}
    Punto GetPunto(){return (*this);}

};
