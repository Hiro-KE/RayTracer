#pragma once

#include "vec4.h"
#include "ray.h"
#include <RayTracer/hittable_list.h>

class render
{

public:

    render();

    void init();

    color ray_color(const ray& r, const hittable& world);

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

    hittable_list world;
};