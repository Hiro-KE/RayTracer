#pragma once

#include "ray.h"

struct hit_record
{
    location p;
    vec4 normal;
    double t;
    bool front_face;

    inline void set_face_normal(const ray& r, const vec4& outword_normal)
    {
        front_face = dot(r.direction(), outword_normal) < 0;
        normal = front_face ? outword_normal : -outword_normal;
    }
};

class hittable
{

public:

    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;

};
