#ifndef VECTOR2_H
#define VECTOR2_H


template <class TYPE>
class Vector2 {
public:
	TYPE x, y;
	Vector2(TYPE xVal, TYPE yVal) : x(xVal), y(yVal) {}
	Vector2(const Vector2<TYPE>& vec) {
	  x = vec.x;
	  y = vec.y;
	}
};


#endif
