#pragma once
#include "../c_DataTypedef.h"
typedef struct {
	c_FLOAT x;
	c_FLOAT y;
} c_Vec2f;
typedef struct {
	c_FLOAT x;
	c_FLOAT y;
	c_FLOAT z;
} c_Vec3f;
typedef struct {
	c_FLOAT x;
	c_FLOAT y;
	c_FLOAT z;
	c_FLOAT w;
} c_Vec4f;

//Set Value
inline static c_Vec2f vec2fSetValue(c_FLOAT value) {
	c_Vec2f result = { value, value };
	return result;
}
inline static c_Vec3f vec3fSetValue(c_FLOAT value) {
	c_Vec3f result = { value, value, value };
	return result;
}
inline static c_Vec4f vec4fSetValue(c_FLOAT value) {
	c_Vec4f result = { value, value, value, value };
	return result;
}

//Up
inline static c_Vec3f vec2fUpVec3f(c_Vec2f vec2, c_FLOAT z) {
	c_Vec3f result = { vec2.x, vec2.y, z };
	return result;
}
inline static c_Vec4f vec2fUpVec4f(c_Vec2f vec2, c_FLOAT z, c_FLOAT w) {
	c_Vec4f result = { vec2.x, vec2.y, z, w };
	return result;
}
inline static c_Vec4f vec3fUpVec4f(c_Vec3f vec3, c_FLOAT w) {
	c_Vec4f result = { vec3.x, vec3.y, vec3.z, w };
	return result;
}

//Add
inline static c_Vec2f vec2fAddValue(c_Vec2f vec, c_FLOAT value) {
	c_Vec2f result = { vec.x + value, vec.y + value };

	return result;
}
inline static c_Vec3f vec3fAddValue(c_Vec3f vec, c_FLOAT value) {
	c_Vec3f result = { vec.x + value, vec.y + value, vec.z + value };

	return result;
}
inline static c_Vec4f vec4fAddValue(c_Vec4f vec, c_FLOAT value) {
	c_Vec4f result = { vec.x + value, vec.y + value, vec.z + value, vec.w + value };

	return result;
}
inline static c_Vec2f vec2fAdd(c_Vec2f first, c_Vec2f second) {
	c_Vec2f result = { first.x + second.x, first.y + second.y };

	return result;
}
inline static c_Vec3f vec3fAdd(c_Vec3f first, c_Vec3f second) {
	c_Vec3f result = { first.x + second.x, first.y + second.y, first.z + second.z };

	return result;
}
inline static c_Vec4f vec4fAdd(c_Vec4f first, c_Vec4f second) {
	c_Vec4f result = { first.x + second.x, first.y + second.y, first.z + second.z, first.w + second.w };

	return result;
}

//Sub
inline static c_Vec2f vec2fSubValue(c_Vec2f vec, c_FLOAT value) {
	c_Vec2f result = { vec.x - value, vec.y - value };

	return result;
}
inline static c_Vec3f vec3fSubValue(c_Vec3f vec, c_FLOAT value) {
	c_Vec3f result = { vec.x - value, vec.y - value, vec.z - value };

	return result;
}
inline static c_Vec4f vec4fSubValue(c_Vec4f vec, c_FLOAT value) {
	c_Vec4f result = { vec.x - value, vec.y - value, vec.z - value, vec.w - value };

	return result;
}
inline static c_Vec2f vec2fSub(c_Vec2f first, c_Vec2f second) {
	c_Vec2f result = { first.x - second.x, first.y - second.y };

	return result;
}
inline static c_Vec3f vec3fSub(c_Vec3f first, c_Vec3f second) {
	c_Vec3f result = { first.x - second.x, first.y - second.y, first.z - second.z };

	return result;
}
inline static c_Vec4f vec4fSub(c_Vec4f first, c_Vec4f second) {
	c_Vec4f result = { first.x - second.x, first.y - second.y, first.z - second.z, first.w - second.w };

	return result;
}

//Mul
inline static c_Vec2f vec2fMulValue(c_Vec2f vec, c_FLOAT value) {
	c_Vec2f result = { vec.x * value, vec.y * value };

	return result;
}
inline static c_Vec3f vec3fMulValue(c_Vec3f vec, c_FLOAT value) {
	c_Vec3f result = { vec.x * value, vec.y * value, vec.z * value };

	return result;
}
inline static c_Vec4f vec4fMulValue(c_Vec4f vec, c_FLOAT value) {
	c_Vec4f result = { vec.x * value, vec.y * value, vec.z * value, vec.w * value };

	return result;
}
inline static c_Vec2f vec2fMul(c_Vec2f first, c_Vec2f second) {
	c_Vec2f result = { first.x * second.x, first.y * second.y };

	return result;
}
inline static c_Vec3f vec3fMul(c_Vec3f first, c_Vec3f second) {
	c_Vec3f result = { first.x * second.x, first.y * second.y, first.z * second.z };

	return result;
}
inline static c_Vec4f vec4fMul(c_Vec4f first, c_Vec4f second) {
	c_Vec4f result = { first.x * second.x, first.y * second.y, first.z * second.z, first.w * second.w };

	return result;
}

//Div
inline static c_Vec2f vec2fDivValue(c_Vec2f vec, c_FLOAT value) {
	c_Vec2f result = { vec.x / value, vec.y / value };

	return result;
}
inline static c_Vec3f vec3fDivValue(c_Vec3f vec, c_FLOAT value) {
	c_Vec3f result = { vec.x / value, vec.y / value, vec.z / value };

	return result;
}
inline static c_Vec4f vec4fDivValue(c_Vec4f vec, c_FLOAT value) {
	c_Vec4f result = { vec.x / value, vec.y / value, vec.z / value, vec.w / value };

	return result;
}
inline static c_Vec2f vec2fDiv(c_Vec2f first, c_Vec2f second) {
	c_Vec2f result = { first.x / second.x, first.y / second.y };

	return result;
}
inline static c_Vec3f vec3fDiv(c_Vec3f first, c_Vec3f second) {
	c_Vec3f result = { first.x / second.x, first.y / second.y, first.z / second.z };

	return result;
}
inline static c_Vec4f vec4fDiv(c_Vec4f first, c_Vec4f second) {
	c_Vec4f result = { first.x / second.x, first.y / second.y, first.z / second.z, first.w / second.w };

	return result;
}

