#include <RayTracer/camera.h>

camera::camera() 
{
    auto aspect_ratio = 16. / 9.;
    auto viewport_height = 2.;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.;

    origin = location(0.);
    horizontal = vec4(viewport_width, 0., 0.);
    vertical = vec4(0., viewport_height, 0.);
    lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec4(0., 0., focal_length);
}

camera::camera(const double vfov, const double aspect_ratio) 
{
    auto theta = degree_to_redians(vfov);
    auto h = tan(theta/2.);
    auto viewport_height = 2. * h;
    auto viewport_width = aspect_ratio * viewport_height;
    
    auto focal_length = 1.;

    origin = location(0.);
    horizontal = vec4(viewport_width, 0., 0.);
    vertical = vec4(0., viewport_height, 0.);
    lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec4(0., 0., focal_length);
}

ray camera::get_ray(double u, double v) const
{
    return ray(origin, lower_left_corner + u*horizontal + v*vertical - origin);
}