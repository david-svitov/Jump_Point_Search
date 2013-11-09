#ifndef POINT_LIB
#define POINT_LIB

enum Direction{
    none = 0, left, right, forward, back, left_forward, left_back, right_forward, right_back
};

struct POINT{
		int x;
		int y;

		int f;
		int g;
		int h;

		int come_x;
		int come_y;

        Direction d;

		POINT(): x(0), y(0), f(0), g(0), h(0){
		}
		friend bool operator==(const POINT& left, const POINT& right);
};

#endif
