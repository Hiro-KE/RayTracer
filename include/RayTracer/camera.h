#pragma once

#include <RayTracer/utility.h>
#include <RayTracer/common.h>

class camera
{

public:

    camera();

    camera(const double vfov, const double aspect_ratio);

    ray get_ray(double u, double v) const;

private:

    location origin;

    location lower_left_corner;

    vec4 horizontal;

    vec4 vertical;

};