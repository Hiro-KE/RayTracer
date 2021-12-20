#pragma once

#include <RayTracer/utility.h>
#include <RayTracer/common.h>

class camera
{

public:

    camera();

    camera( const location look_from, const location look_at, const vec3 vup, 
            const double vfov, const double aspect_ratio, const double aperture,
            const double focus_dist);

    ray get_ray(const double s, const double t) const;

private:

    location origin;

    location lower_left_corner;

    vec3 horizontal, vertical;

    vec3 u, v, w;

    double lens_radius;
};