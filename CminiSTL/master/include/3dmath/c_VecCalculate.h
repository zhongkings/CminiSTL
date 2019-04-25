#pragma once
#include "c_Vector.h"
#include <math.h>

/*
length: (x² + y² + z²)srqt = length
normal: vec / length(vec)
cross:  vec3f1, vec3f2
		y1z2 - z1y2
		z1x2 - x1z2
		x1y2 - y1x2
*/

//length
inline static c_FLOAT vec2fLength(c_Vec2f vec) {
	c_FLOAT result = (c_FLOAT)sqrt(powf(vec.x, 2) + powf(vec.y, 2));

	return result;
}
inline static c_FLOAT vec3fLength(c_Vec3f vec) {
	c_FLOAT result = (c_FLOAT)sqrt(powf(vec.x, 2) + powf(vec.y, 2) + powf(vec.z, 2));

	return result;
}
inline static c_FLOAT vec4fLength(c_Vec4f vec) {
	c_FLOAT result = (c_FLOAT)sqrt(powf(vec.x, 2) + powf(vec.y, 2) + powf(vec.z, 2) + powf(vec.w, 2));

	return result;
}

//normal
inline static c_Vec2f vec2fNormal(c_Vec2f vec) {
	c_Vec2f result = vec2fDivValue(vec, vec2fLength(vec));

	return result;
}
inline static c_Vec3f vec3fNormal(c_Vec3f vec) {
	c_Vec3f result = vec3fDivValue(vec, vec3fLength(vec));

	return result;
}
inline static c_Vec4f vec4fNormal(c_Vec4f vec) {
	c_Vec4f result = vec4fDivValue(vec, vec4fLength(vec));

	return result;
}

//distance
inline static c_FLOAT vec2fDistance(c_Vec2f head, c_Vec2f tail) {
	c_FLOAT result = (c_FLOAT)sqrt(pow(head.x - tail.x, 2) + pow(head.y - tail.y, 2));

	return result;
}
inline static c_FLOAT vec3fDistance(c_Vec3f head, c_Vec3f tail) {
	c_FLOAT result = (c_FLOAT)sqrt(pow(head.x - tail.x, 2) + pow(head.y - tail.y, 2) + pow(head.z - tail.z, 2));

	return result;
}
inline static c_FLOAT vec4fDistance(c_Vec4f head, c_Vec4f tail) {
	c_FLOAT result = (c_FLOAT)sqrt(pow(head.x - tail.x, 2) + pow(head.y - tail.y, 2) + pow(head.z - tail.z, 2) + pow(head.w - tail.w, 2));

	return result;
}

//cross
inline static c_Vec3f vec3fCross(c_Vec3f v1, c_Vec3f v2) {
	c_Vec3f result = {
		(v1.y * v2.z) - (v1.z * v2.y),
		(v1.z * v2.x) - (v1.x * v2.z),
		(v1.x * v2.y) - (v1.y * v2.x)
	};

	return result;
}