#ifndef MAP_LIB
#define MAP_LIB

#include <iostream>
#include <vector>
#include <QList>
#include <string>
#include <fstream>

#include "point.h"

#define FINISH 'X'
#define START 'S'

class Map{
    QList<std::string> map_arr;
	POINT finish;
	POINT start;
public:
    Map();
	void Read();
    void Clean();
	friend std::ostream & operator<<(std::ostream & out, const Map & c);
    friend std::istream& operator>>(std::istream &in, Map &c);
	const POINT get_finish() const;
	const POINT get_start() const;
    void set_start(const POINT & t);
    void set_finish(const POINT & t);
    const int get_width() const;
    const int get_height() const;
    void set_width(int t);
    void set_height(int t);
	const char get_value(POINT p) const;
    const char get_value(int x, int y) const;
    void draw_path(QList<POINT> path);
    void clear_path();
	void set_value(POINT p, char c);
    void set_value(int x, int y, char c);
};

#endif
