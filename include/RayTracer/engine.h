#pragma once

#include "vec4.h"
#include "ray.h"

class engine
{

public:

    engine();

    void init();

    double hit_sphere(const location &center, const double radius, const ray& r);

    color ray_color(const ray& r);

    // Image
    const float aspect_ratio = 16.f / 9.f;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    
    // Camera

    float viewport_height = 2.f;
    float viewport_width = aspect_ratio * viewport_height;
    float focal_length = 1.f;

    location origin;
    vec4 horizontal;
    vec4 vertical;
    vec4 lower_left_corner;
};