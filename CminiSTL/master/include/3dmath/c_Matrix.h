/* 
	2019-4-29: 13:14
	矩阵都是行式存储
*/
#pragma once
#include "../c_DataTypedef.h"
#include "c_Vector.h"

typedef union {
	c_Vec2f v[2];
	c_FLOAT m[2][2];
} c_Matrix2x2f;

typedef union {
	c_Vec3f v[3];
	c_FLOAT m[3][3];
} c_Matrix3x3f;

typedef union {
	c_Vec4f v[4];
	c_FLOAT m[4][4];
} c_Matrix4x4f;

//Create DiagonalMat
inline static c_Matrix2x2f mat2fCreateDiag(c_FLOAT value) {
	c_Matrix2x2f result = { value, 0, 
		                    0, value };

	return result;
}
inline static c_Matrix3x3f mat3fCreateDiag(c_FLOAT value) {
	c_Matrix3x3f result = { value, 0, 0,
	                        0, value, 0,
	                        0, 0, value };

	return result;
}
inline static c_Matrix4x4f mat4fCreateDiag(c_FLOAT value) {
	c_Matrix4x4f result = { value, 0, 0, 0,
	                        0, value, 0, 0,
	                        0, 0, value, 0,
	                        0, 0, 0, value };

	return result;
}
inline static c_Matrix2x2f mat2fCreateAll(c_FLOAT value) {
	c_Matrix2x2f result = { value, value,
							value, value };

	return result;
}
inline static c_Matrix3x3f mat3fCreateAll(c_FLOAT value) {
	c_Matrix3x3f result = { value, value, value,
							value, value, value,
							value, value, value };

	return result;
}
inline static c_Matrix4x4f mat4fCreateAll(c_FLOAT value) {
	c_Matrix4x4f result = { value, value, value, value,
							value, value, value, value,
							value, value, value, value,
							value, value, value, value };

	return result;
}
inline static c_Matrix2x2f mat2fCreateVec2x2(c_Vec2f const*const vec1, c_Vec2f const*const vec2) {
	c_Matrix2x2f result = { *vec1, *vec2 };
	return result;
}
inline static c_Matrix3x3f mat3fCreateVec3x3(c_Vec3f const*const vec1, c_Vec3f const*const vec2, c_Vec3f const*const vec3) {
	c_Matrix3x3f result = { *vec1, *vec2, *vec3 };
	return result;
}
inline static c_Matrix4x4f mat4fCreateVec4x4(c_Vec4f const*const vec1, c_Vec4f const*const vec2, c_Vec4f const*const vec3, c_Vec4f const*const vec4) {
	c_Matrix4x4f result = { *vec1, *vec2, *vec3, *vec4 };
	return result;
}
//Add
inline static c_Matrix2x2f mat2x2fAdd(c_Matrix2x2f const*const mat1, c_Matrix2x2f const*const mat2) {
	c_Matrix2x2f result = { mat1->m[0][0] + mat2->m[0][0], mat1->m[0][1] + mat2->m[0][1],
						    mat1->m[1][0] + mat2->m[1][0], mat1->m[1][1] + mat2->m[1][1] };

	return result;
}
inline static c_Matrix3x3f mat3x3fAdd(c_Matrix3x3f const*const mat1, c_Matrix3x3f const*const mat2) {
	c_Matrix3x3f result = { mat1->m[0][0] + mat2->m[0][0], mat1->m[0][1] + mat2->m[0][1], mat1->m[0][2] + mat2->m[0][2],
							mat1->m[1][0] + mat2->m[1][0], mat1->m[1][1] + mat2->m[1][1], mat1->m[1][2] + mat2->m[1][2],
							mat1->m[2][0] + mat2->m[2][0], mat1->m[2][1] + mat2->m[2][1], mat1->m[2][2] + mat2->m[2][2]
	};

	return result;
}
inline static c_Matrix4x4f mat4x4fAdd(c_Matrix4x4f const*const mat1, c_Matrix4x4f const*const mat2) {
	c_Matrix4x4f result = { mat1->m[0][0] + mat2->m[0][0], mat1->m[0][1] + mat2->m[0][1], mat1->m[0][2] + mat2->m[0][2], mat1->m[0][3] + mat2->m[0][3],
							mat1->m[1][0] + mat2->m[1][0], mat1->m[1][1] + mat2->m[1][1], mat1->m[1][2] + mat2->m[1][2], mat1->m[1][3] + mat2->m[1][3],
							mat1->m[2][0] + mat2->m[2][0], mat1->m[2][1] + mat2->m[2][1], mat1->m[2][2] + mat2->m[2][2], mat1->m[2][3] + mat2->m[2][3],
							mat1->m[3][0] + mat2->m[3][0], mat1->m[3][1] + mat2->m[3][1], mat1->m[3][2] + mat2->m[3][2], mat1->m[3][3] + mat2->m[3][3],
	};

	return result;
}
inline static c_Matrix2x2f mat2x2fAddVec2(c_Matrix2x2f const*const mat1, c_Vec2f const*const vec) {
	c_Matrix2x2f result = { mat1->m[0][0] + vec->x, mat1->m[0][1] + vec->y,
							mat1->m[1][0] + vec->x, mat1->m[1][1] + vec->y };

	return result;
}
inline static c_Matrix3x3f mat3x3fAddVec3(c_Matrix3x3f const*const mat1, c_Vec3f const*const vec) {
	c_Matrix3x3f result = { mat1->m[0][0] + vec->x, mat1->m[0][1] + vec->y, mat1->m[0][2] + vec->z,
							mat1->m[1][0] + vec->x, mat1->m[1][1] + vec->y, mat1->m[1][2] + vec->z,
						    mat1->m[2][0] + vec->x, mat1->m[2][1] + vec->y, mat1->m[2][2] + vec->z };

	return result;
}
inline static c_Matrix4x4f mat4x4fAddVec4(c_Matrix4x4f const*const mat1, c_Vec4f const*const vec) {
	c_Matrix4x4f result = { mat1->m[0][0] + vec->x, mat1->m[0][1] + vec->y, mat1->m[0][2] + vec->z, mat1->m[0][3] + vec->w,
							mat1->m[1][0] + vec->x, mat1->m[1][1] + vec->y, mat1->m[1][2] + vec->z, mat1->m[1][3] + vec->w,
							mat1->m[2][0] + vec->x, mat1->m[2][1] + vec->y, mat1->m[2][2] + vec->z, mat1->m[2][3] + vec->w,
							mat1->m[3][0] + vec->x, mat1->m[3][1] + vec->y, mat1->m[3][2] + vec->z, mat1->m[3][3] + vec->w  };

	return result;
}

//Sub
inline static c_Matrix2x2f mat2x2fSub(c_Matrix2x2f const*const mat1, c_Matrix2x2f const*const mat2) {
	c_Matrix2x2f result = { mat1->m[0][0] - mat2->m[0][0], mat1->m[0][1] - mat2->m[0][1],
							mat1->m[1][0] - mat2->m[1][0], mat1->m[1][1] - mat2->m[1][1] };

	return result;
}
inline static c_Matrix3x3f mat3x3fSub(c_Matrix3x3f const*const mat1, c_Matrix3x3f const*const mat2) {
	c_Matrix3x3f result = { mat1->m[0][0] - mat2->m[0][0], mat1->m[0][1] - mat2->m[0][1], mat1->m[0][2] - mat2->m[0][2],
							mat1->m[1][0] - mat2->m[1][0], mat1->m[1][1] - mat2->m[1][1], mat1->m[1][2] - mat2->m[1][2],
							mat1->m[2][0] - mat2->m[2][0], mat1->m[2][1] - mat2->m[2][1], mat1->m[2][2] - mat2->m[2][2]
	};

	return result;
}
inline static c_Matrix4x4f mat4x4fSub(c_Matrix4x4f const*const mat1, c_Matrix4x4f const*const mat2) {
	c_Matrix4x4f result = { mat1->m[0][0] - mat2->m[0][0], mat1->m[0][1] - mat2->m[0][1], mat1->m[0][2] - mat2->m[0][2], mat1->m[0][3] - mat2->m[0][3],
							mat1->m[1][0] - mat2->m[1][0], mat1->m[1][1] - mat2->m[1][1], mat1->m[1][2] - mat2->m[1][2], mat1->m[1][3] - mat2->m[1][3],
							mat1->m[2][0] - mat2->m[2][0], mat1->m[2][1] - mat2->m[2][1], mat1->m[2][2] - mat2->m[2][2], mat1->m[2][3] - mat2->m[2][3],
							mat1->m[3][0] - mat2->m[3][0], mat1->m[3][1] - mat2->m[3][1], mat1->m[3][2] - mat2->m[3][2], mat1->m[3][3] - mat2->m[3][3],
	};

	return result;
}
inline static c_Matrix2x2f mat2x2fSubVec2(c_Matrix2x2f const*const mat1, c_Vec2f const*const vec) {
	c_Matrix2x2f result = { mat1->m[0][0] - vec->x, mat1->m[0][1] - vec->y,
							mat1->m[1][0] - vec->x, mat1->m[1][1] - vec->y };

	return result;
}
inline static c_Matrix3x3f mat3x3fSubVec3(c_Matrix3x3f const*const mat1, c_Vec3f const*const vec) {
	c_Matrix3x3f result = { mat1->m[0][0] - vec->x, mat1->m[0][1] - vec->y, mat1->m[0][2] - vec->z,
							mat1->m[1][0] - vec->x, mat1->m[1][1] - vec->y, mat1->m[1][2] - vec->z,
							mat1->m[2][0] - vec->x, mat1->m[2][1] - vec->y, mat1->m[2][2] - vec->z };

	return result;
}
inline static c_Matrix4x4f mat4x4fSubVec4(c_Matrix4x4f const*const mat1, c_Vec4f const*const vec) {
	c_Matrix4x4f result = { mat1->m[0][0] - vec->x, mat1->m[0][1] - vec->y, mat1->m[0][2] - vec->z, mat1->m[0][3] - vec->w,
							mat1->m[1][0] - vec->x, mat1->m[1][1] - vec->y, mat1->m[1][2] - vec->z, mat1->m[1][3] - vec->w,
							mat1->m[2][0] - vec->x, mat1->m[2][1] - vec->y, mat1->m[2][2] - vec->z, mat1->m[2][3] - vec->w,
							mat1->m[3][0] - vec->x, mat1->m[3][1] - vec->y, mat1->m[3][2] - vec->z, mat1->m[3][3] - vec->w };

	return result;
}

//Mul
inline static c_Matrix2x2f mat2x2fMul(c_Matrix2x2f const*const mat1, c_Matrix2x2f const*const mat2) {
	c_Matrix2x2f result = { mat2->m[0][0] * mat1->m[0][0] + mat2->m[0][1] * mat1->m[1][0],
							mat2->m[0][0] * mat1->m[0][1] + mat2->m[0][1] * mat1->m[1][1],

							mat2->m[1][0] * mat1->m[0][0] + mat2->m[1][1] * mat1->m[1][0],
							mat2->m[1][0] * mat1->m[0][1] + mat2->m[1][1] * mat1->m[1][1]
	};

	return result;
}
inline static c_Matrix3x3f mat3x3fMul(c_Matrix3x3f const*const mat1, c_Matrix3x3f const*const mat2) {
	c_Matrix3x3f result = { mat2->m[0][0] * mat1->m[0][0] + mat2->m[0][1] * mat1->m[1][0] + mat2->m[0][2] * mat1->m[2][0],
							mat2->m[0][0] * mat1->m[0][1] + mat2->m[0][1] * mat1->m[1][1] + mat2->m[0][2] * mat1->m[2][1],
							mat2->m[0][0] * mat1->m[0][2] + mat2->m[0][1] * mat1->m[1][2] + mat2->m[0][2] * mat1->m[2][2],

							mat2->m[1][0] * mat1->m[0][0] + mat2->m[1][1] * mat1->m[1][0] + mat2->m[1][2] * mat1->m[2][0],
							mat2->m[1][0] * mat1->m[0][1] + mat2->m[1][1] * mat1->m[1][1] + mat2->m[1][2] * mat1->m[2][1],
							mat2->m[1][0] * mat1->m[0][2] + mat2->m[1][1] * mat1->m[1][2] + mat2->m[1][2] * mat1->m[2][2],

							mat2->m[2][0] * mat1->m[0][0] + mat2->m[2][1] * mat1->m[1][0] + mat2->m[2][2] * mat1->m[2][0],
							mat2->m[2][0] * mat1->m[0][1] + mat2->m[2][1] * mat1->m[1][1] + mat2->m[2][2] * mat1->m[2][1],
							mat2->m[2][0] * mat1->m[0][2] + mat2->m[2][1] * mat1->m[1][2] + mat2->m[2][2] * mat1->m[2][2]
	};

	return result;
}
inline static c_Matrix4x4f mat4x4fMul(c_Matrix4x4f const*const mat1, c_Matrix4x4f const*const mat2) {
	c_Matrix4x4f result = { mat2->m[0][0] * mat1->m[0][0] + mat2->m[0][1] * mat1->m[1][0] + mat2->m[0][2] * mat1->m[2][0] + mat2->m[0][3] * mat1->m[3][0],
							mat2->m[0][0] * mat1->m[0][1] + mat2->m[0][1] * mat1->m[1][1] + mat2->m[0][2] * mat1->m[2][1] + mat2->m[0][3] * mat1->m[3][1],
							mat2->m[0][0] * mat1->m[0][2] + mat2->m[0][1] * mat1->m[1][2] + mat2->m[0][2] * mat1->m[2][2] + mat2->m[0][3] * mat1->m[3][2],
							mat2->m[0][0] * mat1->m[0][3] + mat2->m[0][1] * mat1->m[1][3] + mat2->m[0][2] * mat1->m[2][3] + mat2->m[0][3] * mat1->m[3][3],

							mat2->m[1][0] * mat1->m[0][0] + mat2->m[1][1] * mat1->m[1][0] + mat2->m[1][2] * mat1->m[2][0] + mat2->m[1][3] * mat1->m[3][0],
							mat2->m[1][0] * mat1->m[0][1] + mat2->m[1][1] * mat1->m[1][1] + mat2->m[1][2] * mat1->m[2][1] + mat2->m[1][3] * mat1->m[3][1],
							mat2->m[1][0] * mat1->m[0][2] + mat2->m[1][1] * mat1->m[1][2] + mat2->m[1][2] * mat1->m[2][2] + mat2->m[1][3] * mat1->m[3][2],
							mat2->m[1][0] * mat1->m[0][3] + mat2->m[1][1] * mat1->m[1][3] + mat2->m[1][2] * mat1->m[2][3] + mat2->m[1][3] * mat1->m[3][3],

							mat2->m[2][0] * mat1->m[0][0] + mat2->m[2][1] * mat1->m[1][0] + mat2->m[2][2] * mat1->m[2][0] + mat2->m[2][3] * mat1->m[3][0],
							mat2->m[2][0] * mat1->m[0][1] + mat2->m[2][1] * mat1->m[1][1] + mat2->m[2][2] * mat1->m[2][1] + mat2->m[2][3] * mat1->m[3][1],
							mat2->m[2][0] * mat1->m[0][2] + mat2->m[2][1] * mat1->m[1][2] + mat2->m[2][2] * mat1->m[2][2] + mat2->m[2][3] * mat1->m[3][2],
							mat2->m[2][0] * mat1->m[0][3] + mat2->m[2][1] * mat1->m[1][3] + mat2->m[2][2] * mat1->m[2][3] + mat2->m[2][3] * mat1->m[3][3],

							mat2->m[3][0] * mat1->m[0][0] + mat2->m[3][1] * mat1->m[1][0] + mat2->m[3][2] * mat1->m[2][0] + mat2->m[3][3] * mat1->m[3][0],
							mat2->m[3][0] * mat1->m[0][1] + mat2->m[3][1] * mat1->m[1][1] + mat2->m[3][2] * mat1->m[2][1] + mat2->m[3][3] * mat1->m[3][1],
							mat2->m[3][0] * mat1->m[0][2] + mat2->m[3][1] * mat1->m[1][2] + mat2->m[3][2] * mat1->m[2][2] + mat2->m[3][3] * mat1->m[3][2],
							mat2->m[3][0] * mat1->m[0][3] + mat2->m[3][1] * mat1->m[1][3] + mat2->m[3][2] * mat1->m[2][3] + mat2->m[3][3] * mat1->m[3][3]
	};

	return result;
}
inline static c_Matrix2x2f mat2x2fMulVec2(c_Matrix2x2f const*const mat1, c_Vec2f const*const vec) {
	c_Matrix2x2f result = { mat1->m[0][0] * vec->x, mat1->m[0][1] * vec->y,
							mat1->m[1][0] * vec->x, mat1->m[1][1] * vec->y };

	return result;
}
inline static c_Matrix3x3f mat3x3fMulVec3(c_Matrix3x3f const*const mat1, c_Vec3f const*const vec) {
	c_Matrix3x3f result = { mat1->m[0][0] * vec->x, mat1->m[0][1] * vec->y, mat1->m[0][2] * vec->z,
							mat1->m[1][0] * vec->x, mat1->m[1][1] * vec->y, mat1->m[1][2] * vec->z,
							mat1->m[2][0] * vec->x, mat1->m[2][1] * vec->y, mat1->m[2][2] * vec->z,
	                      };

	return result;
}
inline static c_Matrix4x4f mat4x4fMulVec4(c_Matrix4x4f const*const mat1, c_Vec4f const*const vec) {
	c_Matrix4x4f result = { mat1->m[0][0] * vec->x, mat1->m[0][1] * vec->y, mat1->m[0][2] * vec->z, mat1->m[0][3] * vec->w,
							mat1->m[1][0] * vec->x, mat1->m[1][1] * vec->y, mat1->m[1][2] * vec->z, mat1->m[1][3] * vec->w,
							mat1->m[2][0] * vec->x, mat1->m[2][1] * vec->y, mat1->m[2][2] * vec->z, mat1->m[2][3] * vec->w,
							mat1->m[3][0] * vec->x, mat1->m[3][1] * vec->y, mat1->m[3][2] * vec->z, mat1->m[3][3] * vec->w
	};

	return result;
}