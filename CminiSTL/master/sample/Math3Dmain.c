#include "3dmath/c_Vector.h"
#include "3dmath/c_VecCalculate.h"

#include "sample/sample.h"


void Math3Dmain() {
	c_Vec2f vec21 = { 5, 0 };
	c_Vec2f vec22 = { 10, 8 };

	printf("dit: %.3f\n", vec2fDistance(vec22, vec21));
	printf("dit: %.3f\n", vec2fDistance(vec21, vec22));
}