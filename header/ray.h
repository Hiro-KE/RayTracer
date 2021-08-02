#pragma once

#include "vec4.h"

class ray
{

public:

    ray(){};
    ray(const location& origin, const vec4& direction)
        : orig(origin), dir(direction)
    {}

    inline location origin() const {return orig;}
    inline vec4 direction() const {return dir;}

    inline location at(double t) const
    {
        return orig + t*dir;
    }

public:

    location orig;
    vec4 dir;
};