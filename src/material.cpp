#include <RayTracer/material.h>

material::material(/* args */)
{
}

material::~material()
{
}

bool lambertian::scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const
{
    auto scatter_direction = rec.normal + random_unit_vector();

    // Catch degenerate scatter direction 
    if (scatter_direction.near_zero())
    {
        scatter_direction = rec.normal;
    }
    
    scattered = ray(rec.p, scatter_direction);
    attenuation = albedo;
    return true;
}

bool metal::scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const 
{
    vec4 reflected_direction = reflect(unit_vector(r_in.direction()),rec.normal);
    scattered = ray(rec.p, reflected_direction + fuzz*random_in_unit_sphere());
    attenuation = albedo;
    return (dot(scattered.direction(), rec.normal) > 0); 
    // I think it should always be true, because even when the two vectors are parallel, 
    // I want the light to get back to the direction of the source while lowering the intensity over the distance traveled
}

bool dielectric::scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered) const 
{
    attenuation = color(1., 1., 1.);
    double refraction_ratio = rec.front_face ? (1./ir) : ir;

    vec4 unit_direction = unit_vector(r_in.direction());

    double cos_theta = fmin(dot(-unit_direction, rec.normal), 1.);
    double sin_theta = sqrt(1. - cos_theta*cos_theta);
    
    bool cannot_refract = refraction_ratio * sin_theta > 1.;
    vec4 direction;
    
    if (cannot_refract)
    {
        direction = reflect(unit_direction, rec.normal);
    }
    else
    {
           direction = refract(unit_direction, rec.normal, refraction_ratio);

    }
 
    scattered = ray(rec.p, direction);

    return true;
}