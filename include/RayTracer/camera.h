#pragma once

#include <RayTracer/utility.h>
#include <RayTracer/common.h>

class camera
{

public:

    camera();

    ray get_ray(double u, double v) const;

private:

    location origin;

    location lower_left_corner;

    vec4 horizontal;

    vec4 vertical;

};