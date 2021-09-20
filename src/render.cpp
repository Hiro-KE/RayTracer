#include <RayTracer/render.h>
#include <RayTracer/utility.h>
#include <RayTracer/hittables/sphere.h>

render::render() 
{
    origin = vec4(0.f, 0.f, 0.f); 
    horizontal = vec4(viewport_width, 0., 0.);
    vertical = vec4(0., viewport_height, 0.);
    lower_left_corner = origin - horizontal/2. - vertical/2. - vec4(0., 0., focal_length);
}

void render::init() 
{
    world.add(make_shared<sphere>(location(0., 0., -1.), .5));
    world.add(make_shared<sphere>(location(0., -100.5, -1.), 100.));
}

color render::ray_color(const ray& r, const hittable& world) 
{
    hit_record rec;
    if (world.hit(r, 0, infinity, rec))
    {
        return .5 * (rec.normal + color(1, 1, 1));
    }
    vec4 unit_direction = unit_vector(r.direction());
    auto t  = .5 * (unit_direction.y() + 1.);
    return (1.-t) * color(1., 1., 1.) + t * color(.5, .7, 1.);
}