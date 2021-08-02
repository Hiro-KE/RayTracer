#pragma once

#include "ray.h"

struct hit_record
{
    location p;
    vec4 normal;
    double t;
};

class hittable
{

public:

    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;

};
