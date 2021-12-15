#pragma once

#include "vec4.h"
#include "ray.h"
#include <RayTracer/hittable_list.h>
#include <RayTracer/camera.h>

class render
{

public:

    render();

    void init();

    void process();

    color ray_color(const ray& r, const hittable& world, const int depth);

private:

    // Image
    const float aspect_ratio = 16.f / 9.f;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 200;
    const int max_depth = 50;

    // World

    hittable_list world;

    // Camera

    camera cam;
};