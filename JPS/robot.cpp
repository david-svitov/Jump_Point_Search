#include "robot.h"


//===================================================================ROBOT===========================================================


Robot::Robot(): map_arr(NULL), topology("planar"){
}

Robot::Robot(Map * map_p, const std::string & topo): map_arr(map_p), topology(topo){
	pos.x = map_arr->get_start().x;
	pos.y = map_arr->get_start().y;
}

int Robot::move(Direction d) throw (BadMove){
	if(Direction::left == d){
		add_x(pos.x, -1);
	}
	if(Direction::right == d){
		add_x(pos.x, 1);
	}
	if(Direction::forward == d){
		add_y(pos.y, -1);
	}
	if(Direction::back == d){
		add_y(pos.y, 1);
	}

	if(Direction::left_forward == d){
		add_x(pos.x, -1);
		add_y(pos.y, -1);
	}
	if(Direction::right_back == d){
		add_x(pos.x, 1);
		add_y(pos.y, 1);
	}
	if(Direction::left_back == d){
		add_y(pos.y, 1);
		add_x(pos.x, -1);
	}
	if(Direction::right_forward == d){
		add_y(pos.y, -1);
		add_x(pos.x, 1);
	}
	return h(pos);
}

int Robot::lookup(Direction d){
	POINT p =  pos;
	if(Direction::none == d){
		return h(p);
	}
	if(Direction::left == d){
		add_x(p.x, -1);
		if('#' == map_arr->get_value(p)){
			throw BadMove();
		}
		return h(p);
	}
	if(Direction::right == d){
		add_x(p.x, 1);
		if('#' == map_arr->get_value(p)){
			throw BadMove();
		}
		return h(p);
	}
	if(Direction::forward == d){
		add_y(p.y, -1);
		if('#' == map_arr->get_value(p)){
			throw BadMove();
		}
		return h(p);
	}
	if(Direction::back == d){
		add_y(p.y, 1);
		if('#' == map_arr->get_value(p)){
			throw BadMove();
		}
		return h(p);
	}

	if(Direction::left_forward == d){
		add_x(pos.x, -1);
		add_y(pos.y, -1);
		if('#' == map_arr->get_value(pos)){
			throw BadMove();
		}
		return h(p);
	}
	if(Direction::right_back == d){
		add_x(pos.x, 1);
		add_y(pos.y, 1);
		if('#' == map_arr->get_value(pos)){
			throw BadMove();
		}
		return h(p);
	}
	if(Direction::left_back == d){
		add_y(pos.y, 1);
		add_x(pos.x, -1);
		if('#' == map_arr->get_value(pos)){
			throw BadMove();
		}
		return h(p);
	}
	if(Direction::right_forward == d){
		add_y(pos.y, -1);
		add_x(pos.x, 1);
		if('#' == map_arr->get_value(pos)){
			throw BadMove();
		}
		return h(p);
	}
	return 0;
}

int Robot::jump(const POINT &p){
	pos = p;
	return h(pos);
}

int Robot::jump(int x, int y){
	POINT p;
	p.x = x;
	p.y = y;
	pos = p;
    return jump(pos);
}

bool Robot::seewall(const POINT & p){

    if(p.x < 0){
        return true;
    }
    if(p.x >= map_arr->get_width()){
        return true;
    }
    if(p.y < 0){
        return true;
    }
    if(p.y >= map_arr->get_height()){
        return true;
    }
    if('#' == map_arr->get_value(p)){
            return true;
    }
	return false;
}

bool Robot::seewall(int x, int y){
	POINT p;
	p.x = x;
	p.y = y;
	return seewall(p);
}

const POINT Robot::position() const{
	return pos;
}

void Robot::set_map(Map * map_p){
	map_arr = map_p;
}

int my_abs(int x){
	if(x < 0) x*=-1;
	return x;
}

int Robot::h(POINT p){
	int x_ma = my_abs((p.x)-(map_arr->get_finish().x));
	int y_ma = my_abs((p.y)-(map_arr->get_finish().y));

	if(("cylinder" == topology) || ("tor" == topology)){
		int smal_x = map_arr->get_width() - x_ma;
		if(my_abs(smal_x) < my_abs(x_ma)){
			x_ma = smal_x;
		}
	}

	if("tor" == topology){
		int smal_y = map_arr->get_height() - y_ma;
		if(my_abs(smal_y) < my_abs(y_ma)){
			y_ma = smal_y;
		}
	}
    return x_ma + y_ma;
}

void Robot::add_x(int & x, int t){
	int tmp_x = x;
	tmp_x += t;
	if(("cylinder" == topology) || ("tor" == topology)){
		if(tmp_x >= map_arr->get_width()){ 
            tmp_x = 0;
		}
		if(tmp_x < 0){ 
            tmp_x = map_arr->get_width()-1;
		}
	}
    x = tmp_x;
}

void Robot::add_y(int & y, int t){
	int tmp_y = y;
	tmp_y += t;
	if("tor" == topology){
		if(tmp_y >= map_arr->get_height()){ 
            tmp_y = 0;
		}
		if(tmp_y < 0){ 
            tmp_y = map_arr->get_height()-1;
		}
    }
	y = tmp_y;
}

int Robot::add_X(int x, int t){
    int p = x;
    add_x(p, t);
    return p;
}

int Robot::add_Y(int y, int t){
    int p = y;
    add_y(p, t);
    return p;
}
