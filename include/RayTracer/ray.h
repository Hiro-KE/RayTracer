#pragma once

#include "vec3.h"

class ray
{

public:

    ray(){};
    ray(const location& origin, const vec3& direction)
        : orig(origin), dir(direction)
    {}

    inline location origin() const {return orig;}
    inline vec3 direction() const {return dir;}

    inline location at(double t) const
    {
        return orig + t*dir;
    }

public:

    location orig;
    vec3 dir;
};