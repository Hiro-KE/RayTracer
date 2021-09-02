#include <vec4.h>
#include <RayTracer/color.h>
#include <RayTracer/ray.h>

double hit_sphere(const location &center, const double radius, const ray& r)
{
    vec4 oc = r.origin() - center;
    double a = r.direction().length_squared();
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - radius * radius;
    double discriminant = half_b*half_b - a*c;
    return (discriminant < 0) ? -1. : (-half_b -sqrt(discriminant)) / a;
}

color ray_color(const ray& r)
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

int main()
{
    // Image
    const float aspect_ratio = 16.f / 9.f;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    
    // Camera

    float viewport_height = 2.f;
    float viewport_width = aspect_ratio * viewport_height;
    float focal_length = 1.f;

    location origin(0., 0., 0.);
    vec4 horizontal = vec4(viewport_width, 0., 0.);
    vec4 vertical = vec4(0., viewport_height, 0.);
    vec4 lower_left_corner = origin - horizontal/2. - vertical/2. - vec4(0., 0., focal_length);

    // Write to a file
    freopen("output.ppm","w",stdout);

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) 
    {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            
            // Set up UV
            double u = double(i) / (image_width - 1.);
            double v = double(j) / (image_height - 1.);
    
            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            color pixel_color(ray_color(r));
            write_color_ppm(std::cout, pixel_color);
        }
    }

    return 0;
};