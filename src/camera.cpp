#include <RayTracer/camera.h>

camera::camera() 
{
}

camera::camera(const location look_from, const location look_at, const vec3 vup, const double vfov, const double aspect_ratio) 
{
    auto theta = degree_to_redians(vfov);
    auto h = tan(theta/2);
    auto viewport_height = 2.0 * h;
    auto viewport_width = aspect_ratio * viewport_height;

    auto w = unit_vector(look_from - look_at);
    auto u = unit_vector(cross(vup, w));
    auto v = cross(w, u);

    origin = look_from;
    horizontal = viewport_width * u;
    vertical = viewport_height * v;
    lower_left_corner = origin - horizontal/2 - vertical/2 - w;
}

ray camera::get_ray(const double s, const double t) const
{
    return ray(origin, lower_left_corner + s*horizontal + t*vertical - origin);
}