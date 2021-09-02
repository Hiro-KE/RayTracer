#include <engine.h>

engine::engine() 
{
    origin = vec4(0.f); 
    horizontal = vec4(viewport_width, 0., 0.);
    vertical = vec4(0., viewport_height, 0.);
    lower_left_corner = origin - horizontal/2. - vertical/2. - vec4(0., 0., focal_length);
}

void engine::init() 
{
    
}

double engine::hit_sphere(const location &center, const double radius, const ray& r) 
{
    vec4 oc = r.origin() - center;
    double a = r.direction().length_squared();
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - radius * radius;
    double discriminant = half_b*half_b - a*c;
    return (discriminant < 0) ? -1. : (-half_b -sqrt(discriminant)) / a;
}

color engine::ray_color(const ray& r) 
{
    double t = hit_sphere(location(0, 0, -1), 0.5, r);
    if (t > 0.)
    {
        vec4 N = unit_vector(r.at(t) - vec4(0., 0., -1.));
        return .5 * color(N.x() + 1., N.y() + 1., N.z() + 1.);
    }
    vec4 unit_direction = unit_vector(r.direction());
    t  = .5 * (unit_direction.y() + 1.);
    return (1.-t) * color(1., 1., 1.) + t * color(.5, .7, 1.);
}