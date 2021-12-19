#pragma once

#include "vec3.h"
#include "ray.h"
#include <RayTracer/camera.h>
#include <RayTracer/hittable_list.h>

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
    const int image_width = 1270;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 250;
    const int max_depth = 100;

    // World

    hittable_list world;

    // Camera

    camera cam = camera(location(-2, 2, 1), location(0, 0, -1), vec3(0, 1, 0), 50., aspect_ratio);
};