#include <RayTracer/hittables/sphere.h>

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const 
{
    vec4 oc = r.origin() - center;
    double a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - std::pow(radius, 2);

    auto discriminant = half_b * half_b - a*c;
    if (discriminant < 0)
    {
        return false;
    }
    auto sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root)
    {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root)
        {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vec4 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    
    return true;
}