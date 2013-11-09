#ifndef ROBOT_LIB
#define ROBOT_LIB

#include <iostream>
#include <vector>
#include <QList>
#include <exception>
#include <cmath>
#include <string>
#include <functional> 
#include <queue> 
#include <algorithm>
#include "anyoption.h"
#include "map.h"
#include "point.h"

template<
    class T,
    class Container = std::vector<T>,
    class Compare = std::less<typename Container::value_type>
> class MyQueue : public std::priority_queue<T, Container, Compare>
{
public:
    typedef typename
        std::priority_queue<
        T,
        Container,
        Compare>::container_type::const_iterator const_iterator;

    const_iterator find(const T&val) const
    {
        auto first = this->c.cbegin();
        auto last = this->c.cend();
        while (first!=last) {
            if (*first==val) return first;
            ++first;
        }
        return last;
    }

    const_iterator end() const
    {
        return this->c.cend();
    }
};

class ComparePoint{
public:
	bool operator()(POINT x, POINT y){
		return x.f > y.f;
	}
};


class BadMove: public std::exception{};

//interface
class Surface{
public:
    virtual int move(Direction d) throw (BadMove) = 0; //move robot
    virtual int add_X(int x, int t) = 0;
    virtual int add_Y(int y, int t) = 0;
	virtual int lookup(Direction d) = 0;	// see distanetion
    virtual int jump(const POINT & p) = 0;	//go to POINT
	virtual int jump(int x, int y) = 0;	//go to X, Y
    virtual bool seewall(const POINT & p) = 0; //return true if position have wall
	virtual bool seewall(int x, int y) = 0; //return true if position have wall
	virtual const POINT position() const = 0;	//see position robot in map
};

//class for robot
class Robot: public Surface
{

	POINT pos;
	Map * map_arr;
	std::string topology;

	int h(POINT p);
    void add_x(int & x, int t);
    void add_y(int & y, int t);
public:
	Robot();
	Robot(Map * map_p, const std::string & topo = "planar");
	virtual int move(Direction d) throw (BadMove);
	virtual int lookup(Direction d);
    virtual int jump(const POINT & p);
	virtual int jump(int x, int y);
    virtual bool seewall(const POINT & p);
	virtual bool seewall(int x, int y); 
	virtual const POINT position() const;
    virtual int add_X(int x, int t);
    virtual int add_Y(int y, int t);

	void set_map(Map * map_p);
};


//class for search algorithm
class Search
{
	Surface * robot;
    bool contain(const QList<POINT> & v, const POINT & x);
public:
	Search(Surface * surf);
    QList<POINT> find();
    QList<POINT> prune(const POINT & pos, Direction d);
    QList<POINT> prune(Direction d);
    QList<POINT> get_neighbors(const POINT & pos);
	int get_dx(Direction d);
	int get_dy(Direction d);
    QList<POINT> get_success(const POINT & pos, Direction d);
    POINT jump(POINT & pos, Direction d, int g);
    Direction get_der(int dx, int dy);
};

#endif
