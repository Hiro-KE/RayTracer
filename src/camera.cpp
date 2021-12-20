#include <RayTracer/camera.h>

camera::camera() 
{
}

camera::camera( const location look_from, const location look_at, const vec3 vup, 
                const double vfov, const double aspect_ratio, const double aperture, 
                const double focus_dist)
{
    auto theta = degree_to_redians(vfov);
    auto h = tan(theta/2);
    auto viewport_height = 2.0 * h;
    auto viewport_width = aspect_ratio * viewport_height;

    w = unit_vector(look_from - look_at);
    u = unit_vector(cross(vup, w));
    v = cross(w, u);

    origin = look_from;
    horizontal = focus_dist * viewport_width * u;
    vertical = focus_dist * viewport_height * v;
    lower_left_corner = origin - horizontal/2 - vertical/2 - focus_dist*w;

    lens_radius = aperture / 2;
}

ray camera::get_ray(const double s, const double t) const
{
    vec3 rd = lens_radius * random_in_unit_disk();
    vec3 offset = u * rd.x() + v * rd.y();

    return ray(origin + offset, lower_left_corner + s*horizontal + t*vertical - origin - offset);
}