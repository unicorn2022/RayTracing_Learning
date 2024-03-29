﻿#pragma once

#include "Vec3.h"

class Ray {
public:
	__host__ __device__ Ray() {};
	__host__ __device__ Ray(const Point3& orig, const Vec3& dir) :origin(orig), direction(dir) {}

	__host__ __device__ Point3 Origin() const { return origin; }
	__host__ __device__ Vec3 Direction() const { return direction; }

	// P(t) = origin + t * direction
	__host__ __device__ Point3 At(double t) const {
		return origin + t * direction;
	}


private:
	Point3 origin;
	Vec3 direction;
};