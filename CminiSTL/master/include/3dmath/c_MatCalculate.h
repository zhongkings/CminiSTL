#pragma once
#include "c_Matrix.h"
#include "c_VecCalculate.h"

/*Rotate
1弧度 = 180 / pai 度

1度 = pai / 180 弧度
*/

//Scale
inline static c_Matrix4x4f mat4ScaleXYZ(c_Matrix4x4f const*const m4f, c_FLOAT x, c_FLOAT y, c_FLOAT z) {
	c_Matrix4x4f result = *m4f;
	result.m[0][0] *= x;
	result.m[1][1] *= y;
	result.m[2][2] *= z;

	return result;
}
inline static c_Matrix4x4f mat4Scale(c_Matrix4x4f const*const m4f, c_Vec3f const*const vec) {
	return mat4ScaleXYZ(m4f, vec->x, vec->y, vec->z);
}
inline static c_Matrix4x4f mat4ScaleSetXYZ(c_Matrix4x4f const*const m4f, c_FLOAT x, c_FLOAT y, c_FLOAT z) {
	c_Matrix4x4f result = *m4f;
	result.m[0][0] = x;
	result.m[1][1] = y;
	result.m[2][2] = z;

	return result;
}
inline static c_Matrix4x4f mat4ScaleSet(c_Matrix4x4f const*const m4f, c_Vec3f const*const vec) {
	return mat4ScaleSetXYZ(m4f, vec->x, vec->y, vec->z);
}
//Translate
inline static c_Matrix4x4f mat4TranslateXYZ(c_Matrix4x4f const*const m4f, c_FLOAT x, c_FLOAT y, c_FLOAT z) {
	c_Matrix4x4f result = *m4f;
	result.v[3].x += x; 
	result.v[3].y += y;
	result.v[3].z += z;

	return result;
}
inline static c_Matrix4x4f mat4Translate(c_Matrix4x4f const*const m4f, c_Vec3f const*const vec) {
	return mat4TranslateXYZ(m4f, vec->x, vec->y, vec->z);
}
inline static c_Matrix4x4f mat4TranslateSetXYZ(c_Matrix4x4f const*const m4f, c_FLOAT x, c_FLOAT y, c_FLOAT z) {
	c_Vec4f temp1 = vec4fMulValue(&m4f->v[0], x);
	c_Vec4f temp2 = vec4fMulValue(&m4f->v[1], y);
	c_Vec4f temp3 = vec4fMulValue(&m4f->v[2], z);

	temp1 = vec4fAdd(&temp1, &temp2);
	temp1 = vec4fAdd(&temp1, &temp3);
	temp1 = vec4fAdd(&temp1, &m4f->v[3]);
	c_Matrix4x4f result = *m4f;
	result.v[3] = temp1;

	return result;
}
inline static c_Matrix4x4f mat4TranslateSet(c_Matrix4x4f const*const m4f, c_Vec3f const*const vec) {
	return mat4TranslateSetXYZ(m4f, vec->x, vec->y, vec->z);
}
//Rotate
inline static c_Matrix4x4f mat4RotateXYZ(c_Matrix4x4f const*const m4f, c_FLOAT angle, c_FLOAT x, c_FLOAT y, c_FLOAT z) {
	c_FLOAT c = (c_FLOAT)cos(angle);
	c_FLOAT s = (c_FLOAT)sin(angle);

	const c_Vec3f vec = { x, y, z };
	c_Vec3f axis = vec3fNormal(&vec);
	c_Vec3f temp = vec3fMulValue(&axis, (1.0f - c));

	c_Matrix4x4f rotate;
	rotate.m[0][0] = c + temp.x * axis.x;
	rotate.m[0][1] = temp.x * axis.y + s * axis.z;
	rotate.m[0][2] = temp.x * axis.z - s * axis.y;

	rotate.m[1][0] = temp.y * axis.x - s * axis.z;
	rotate.m[1][1] = c + temp.y * axis.y;
	rotate.m[1][2] = temp.y * axis.z + s * axis.x;

	rotate.m[2][0] = temp.z * axis.x + s * axis.y;
	rotate.m[2][1] = temp.z * axis.y - s * axis.x;
	rotate.m[2][2] = c + temp.z * axis.z;


	//Result
	c_Matrix4x4f result;
	c_Vec4f temp1 = vec4fMulValue(&m4f->v[0], rotate.m[0][0]);
	c_Vec4f temp2 = vec4fMulValue(&m4f->v[1], rotate.m[0][1]);
	c_Vec4f temp3 = vec4fMulValue(&m4f->v[2], rotate.m[0][2]);
	temp1 = vec4fAdd(&temp1, &temp2);
	temp1 = vec4fAdd(&temp1, &temp3);
	result.v[0] = temp1;

	temp1 = vec4fMulValue(&m4f->v[0], rotate.m[1][0]);
	temp2 = vec4fMulValue(&m4f->v[1], rotate.m[1][1]);
	temp3 = vec4fMulValue(&m4f->v[2], rotate.m[1][2]);
	temp1 = vec4fAdd(&temp1, &temp2);
	temp1 = vec4fAdd(&temp1, &temp3);
	result.v[1] = temp1;

	temp1 = vec4fMulValue(&m4f->v[0], rotate.m[2][0]);
	temp2 = vec4fMulValue(&m4f->v[1], rotate.m[2][1]);
	temp3 = vec4fMulValue(&m4f->v[2], rotate.m[2][2]);
	temp1 = vec4fAdd(&temp1, &temp2);
	temp1 = vec4fAdd(&temp1, &temp3);
	result.v[2] = temp1;
	result.v[3] = m4f->v[3];

	return result;
}
inline static c_Matrix4x4f mat4Rotate(c_Matrix4x4f const*const m4f, c_FLOAT angle, c_Vec3f const*const vec) {
	return mat4RotateXYZ(m4f, angle, vec->x, vec->y, vec->z);
}
//Mirror
inline static c_Matrix4x4f mat4MirrorXYZ(c_Matrix4x4f const*const m4f, c_FLOAT x, c_FLOAT y, c_FLOAT z) {
	c_Matrix4x4f result = *m4f;
	result.m[0][0] *= 1 + (-1 - 1) * x;
	result.m[0][1] *= (-1 - 1) * x * y;
	result.m[0][2] *= (-1 - 1) * x * z;

	result.m[1][0] *= (-1 - 1) * x * y;
	result.m[1][1] *= 1 + (-1 - 1) * y;
	result.m[1][2] *= (-1 - 1) * y * z;

	result.m[2][0] *= (-1 - 1) * x * z;
	result.m[2][1] *= (-1 - 1) * z * y;
	result.m[2][2] *= 1 + (-1 - 1) * z;
	return result;
}
inline static c_Matrix4x4f mat4Mirror(c_Matrix4x4f const*const m4f, c_Vec3f const*const vec) {
	return mat4MirrorXYZ(m4f, vec->x, vec->y, vec->z);
}
//Projection
inline static c_Matrix4x4f mat4Perspective(c_FLOAT fovy, c_FLOAT aspect, c_FLOAT znear, c_FLOAT zfar) {
	c_FLOAT const tanHalfFovy = (c_FLOAT)tan(fovy / 2.0f);
	c_Matrix4x4f result = mat4fCreateDiag(0.0f);
	result.m[0][0] = 1.0f / (aspect * tanHalfFovy);
	result.m[1][1] = 1.0f / tanHalfFovy;
	result.m[2][2] = -(zfar + znear) / (zfar - znear);
	result.m[2][3] = -1.0f;
	result.m[3][2] = -(2.0f * zfar * znear) / (zfar - znear);

	return result;
}
inline static c_Matrix4x4f mat4OrthoRH(c_FLOAT left, c_FLOAT right, c_FLOAT bottom, c_FLOAT top, c_FLOAT znear, c_FLOAT zfar) {
	c_Matrix4x4f result = mat4fCreateDiag(1.0f);
	result.m[0][0] = 2.0f / (right - left);
	result.m[1][1] = 2.0f / (top - bottom);
	result.m[2][2] = -2.0f / (zfar - znear);
	result.m[3][0] = -(right + left) / (right - left);
	result.m[3][1] = -(top + bottom) / (top - bottom);
	result.m[3][2] = -(zfar + znear) / (zfar - znear);

	return result;
}



