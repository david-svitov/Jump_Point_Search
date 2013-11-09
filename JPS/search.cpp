#include "robot.h"

//===================================================================SEARCH===========================================================
Search::Search(Surface * surf): robot(surf){
}

bool Search::contain(const QList<POINT> & v, const POINT & x){
	for (int i = 0; i < v.size(); ++i)
	{
		if((v[i].x == x.x)&&(v[i].y == x.y)){
			return true;
		}
	}
	return false;
}

int Search::get_dx(Direction d){
	if((Direction::left_forward == d) || (Direction::left == d) || (Direction::left_back == d)){
		return -1;
	}
	if((Direction::right_forward == d) || (Direction::right == d) || (Direction::right_back == d)){
		return 1;
	}
	return 0;
}
int Search::get_dy(Direction d){
	if((Direction::forward == d) || (Direction::left_forward == d) || (Direction::right_forward == d)){
		return -1;
	}
	if((Direction::back == d) || (Direction::left_back == d) || (Direction::right_back == d)){
		return 1;
	}
	return 0;
}

QList<POINT> Search::get_neighbors(const POINT & pos){
    QList<POINT> result;
    POINT p;

    if(!robot->seewall(robot->add_X(pos.x, - 1), pos.y)){
        p.x = robot->add_X(pos.x, -1);
        p.y = pos.y;
        p.d = get_der(-1, 0);
        result.push_back(p);
    }

    if(!robot->seewall(robot->add_X(pos.x, 1), pos.y)){
        p.x = robot->add_X(pos.x, 1);
        p.y = pos.y;
        p.d = get_der(1, 0);
        result.push_back(p);
    }

    if(!robot->seewall(pos.x, robot->add_Y(pos.y, - 1))){
        p.x = pos.x;
        p.y = robot->add_Y(pos.y, -1);
        p.d = get_der(0, -1);
        result.push_back(p);
    }

    if(!robot->seewall(pos.x, robot->add_Y(pos.y, 1))){
        p.x = pos.x;
        p.y = robot->add_Y(pos.y, 1);
        p.d = get_der(0, 1);
        result.push_back(p);
    }

    if(!robot->seewall(robot->add_X(pos.x, - 1), robot->add_Y(pos.y, - 1))){
        p.x = robot->add_X(pos.x, -1);
        p.y = robot->add_Y(pos.y, -1);
        p.d = get_der(-1, -1);
        result.push_back(p);
    }

    if(!robot->seewall(robot->add_X(pos.x, 1), robot->add_Y(pos.y, - 1))){
        p.x = robot->add_X(pos.x, 1);
        p.y = robot->add_Y(pos.y, -1);
        p.d = get_der(1, -1);
        result.push_back(p);
    }

    if(!robot->seewall(robot->add_X(pos.x, 1), robot->add_Y(pos.y, 1))){
        p.x = robot->add_X(pos.x, 1);
        p.y = robot->add_Y(pos.y, 1);
        p.d = get_der(1, 1);
        result.push_back(p);
    }

    if(!robot->seewall(robot->add_X(pos.x, - 1), robot->add_Y(pos.y, 1))){
        p.x = robot->add_X(pos.x, -1);
        p.y = robot->add_Y(pos.y, 1);
        p.d = get_der(-1, 1);
        result.push_back(p);
    }

	return result;
}

QList<POINT> Search::prune(Direction d){
	return prune(robot->position(), d);
}

Direction Search::get_der(int dx, int dy){
    if((dx != 0) && (dy != 0)){
        if((dx > 0) && (dy > 0)){
            return Direction::right_back;
        }
        if((dx > 0) && (dy < 0)){
            return Direction::right_forward;
        }
        if((dx < 0) && (dy > 0)){
            return Direction::left_back;
        }
        if((dx < 0) && (dy < 0)){
            return Direction::left_forward;
        }
    }else{
        if(dx != 0){
            if(dx > 0){
                return Direction::right;
            }
            if(dx < 0){
                return Direction::left;
            }
        }else{
            if(dy > 0){
                return Direction::back;
            }
            if(dy < 0){
                return Direction::forward;
            }
        }
    }
    return Direction::none;
}

QList<POINT> Search::prune(const POINT & pos, Direction d){
    QList<POINT> result;
    POINT p;

	int dx = get_dx(d);
    int dy = get_dy(d);

	if(Direction::none != d){
        if((0 != dx) && (0 != dy)){  //diagonal
            if(!robot->seewall(pos.x, robot->add_Y(pos.y, dy))){
                p.x = pos.x;
                p.y = robot->add_Y(pos.y, dy);
                p.d = get_der(0, dy);
                result.push_back(p);
            }
            if(!robot->seewall(robot->add_X(pos.x, dx), pos.y)){
                p.x = robot->add_X(pos.x, dx);
                p.y = pos.y;
                p.d = get_der(dx, 0);
                result.push_back(p);
            }
            if(!robot->seewall(pos.x, robot->add_Y(pos.y, dy)) || !robot->seewall(robot->add_X(pos.x, dx), pos.y)){
                p.x = robot->add_X(pos.x, dx);
                p.y = robot->add_Y(pos.y, dy);
                p.d = get_der(dx, dy);
                result.push_back(p);
            }
            if(robot->seewall(robot->add_X(pos.x, -dx), pos.y) && !robot->seewall(pos.x, robot->add_Y(pos.y, dy))){
                p.x = robot->add_X(pos.x, - dx);
                p.y = robot->add_Y(pos.y, dy);
                p.d = get_der(-dx, dy);
                result.push_back(p);
            }
            if(robot->seewall(pos.x, robot->add_Y(pos.y, - dy)) && !robot->seewall(robot->add_X(pos.x, dx), pos.y)){
                p.x = robot->add_X(pos.x, dx);
                p.y = robot->add_Y(pos.y, - dy);
                p.d = get_der(dx, -dy);
                result.push_back(p);
            }
		}else{ // horizontall/verticall
            if(0 == dx){ //verticall
                if(!robot->seewall(pos.x, robot->add_Y(pos.y, dy))){
                    p.x = pos.x;
                    p.y = robot->add_Y(pos.y, dy);
                    p.d = get_der(0, dy);
                    result.push_back(p);

                    if(robot->seewall(robot->add_X(pos.x, 1), pos.y)){
                        p.x = robot->add_X(pos.x, 1);
                        p.y = robot->add_Y(pos.y, dy);
                        p.d = get_der(1, dy);
                        result.push_back(p);
                    }
                    if(robot->seewall(robot->add_X(pos.x, - 1), pos.y)){
                        p.x = robot->add_X(pos.x, -1);
                        p.y = robot->add_Y(pos.y, dy);
                        p.d = get_der(-1, dy);
                        result.push_back(p);
                    }
                }
            }else{ // horizontall
                if(!robot->seewall(robot->add_X(pos.x, dx), pos.y)){
                    p.x = robot->add_X(pos.x, dx);
                    p.y = pos.y;
                    p.d = get_der(dx, 0);
                    result.push_back(p);

                    if(robot->seewall(pos.x, robot->add_Y(pos.y, 1))){
                        p.x = robot->add_X(pos.x, dx);
                        p.y = robot->add_Y(pos.y, 1);
                        p.d = get_der(dx, 1);
                        result.push_back(p);
                    }
                    if(robot->seewall(pos.x, robot->add_Y(pos.y, - 1))){
                        p.x = robot->add_X(pos.x, dx);
                        p.y = robot->add_Y(pos.y, - 1);
                        p.d = get_der(dx, -1);
                        result.push_back(p);
                    }
                }
			}
		}
	}else{
		return get_neighbors(pos);
	}
	return result;
}


POINT Search::jump(POINT & pos, Direction d, int g){
	POINT null_p;
	null_p.x = -100;
	null_p.y = -100;
    int dx = get_dx(d);
    int dy = get_dy(d);
    g++;
    if((robot->seewall(pos.x, pos.y)) || g > 300){
		return null_p;
	}
    robot->jump(pos);
	if(0 == robot->lookup(Direction::none)){
        pos.g = g;
        pos.d = d;
        return pos;
	}
	if(dx != 0 && dy != 0){ //diagonal test
        if ((!robot->seewall(robot->add_X(pos.x, - dx), robot->add_Y(pos.y, dy)) && robot->seewall(robot->add_X(pos.x, - dx), pos.y)) ||
            (!robot->seewall(robot->add_X(pos.x, dx), robot->add_Y(pos.y, - dy)) && robot->seewall(pos.x, robot->add_Y(pos.y, - dy)))){
                pos.g = g;
                pos.d = d;
                return pos;
        }
	}else{
		if(dx != 0) { // horizontall
            if((!robot->seewall(robot->add_X(pos.x, dx), robot->add_Y(pos.y, 1)) && robot->seewall(pos.x, robot->add_Y(pos.y, 1))) ||
               (!robot->seewall(robot->add_X(pos.x, dx), robot->add_Y(pos.y, - 1)) && robot->seewall(pos.x, robot->add_Y(pos.y, - 1)))){
                    pos.g = g;
                    pos.d = d;
                    return pos;
            }
        }
        else {
            if((!robot->seewall(robot->add_X(pos.x, 1), robot->add_Y(pos.y, dy)) && robot->seewall(robot->add_X(pos.x, 1), pos.y)) ||
               (!robot->seewall(robot->add_X(pos.x, - 1), robot->add_Y(pos.y, dy)) && robot->seewall(robot->add_X(pos.x, - 1), pos.y))){
                    pos.g = g;
                    pos.d = d;
                    return pos;
            }
        }
	}
	//diagonal go test
	if ((dx != 0) && (dy != 0)){
        POINT p;
        p.x = robot->add_X(pos.x, dx);
        p.y = pos.y;
        Direction nd;
        if(dx > 0){
            nd = Direction::right;
        }
        else{
            nd = Direction::left;
        }
        POINT test_x = jump(p, nd, g);

        p.x = pos.x;
        p.y = robot->add_Y(pos.y, dy);
        if(dy > 0){
            nd = Direction::back;
        }
        else{
            nd = Direction::forward;
        }
        POINT test_y = jump(p, nd, g);

        if ((test_x.x >= 0) || (test_y.x >= 0)){
            pos.g = g;
            pos.d = d;
            return pos;
        }
    }
    //recursion
    if (!robot->seewall(robot->add_X(pos.x, dx), pos.y) || !robot->seewall(pos.x, robot->add_Y(pos.y, dy))){
        POINT p;
        p.x = robot->add_X(pos.x, dx);
        p.y = robot->add_Y(pos.y, dy);
        return jump(p, d, g);
    } else {
        return null_p;
    }
	return null_p;    
}

QList<POINT> Search::get_success(const POINT & pos, Direction d){
    QList<POINT> successors;
    successors.clear();
    QList<POINT> neighbours = prune(pos, d);
	POINT n;
	for (int i = 0; i < neighbours.size(); ++i)
	{
        n = jump(neighbours[i], neighbours[i].d, 0);
        if(n.x >= 0){
			successors.push_back(n);
		}
	}	
	return successors;
}


QList<POINT> Search::find(){
    MyQueue<POINT, QList<POINT>, ComparePoint> openset;
    QList<POINT> neighbours;
    QList<POINT> closed;
    QList<POINT> path;
    QList<POINT> map;
	POINT pos = robot->position();
	pos.g = 0;
	pos.h = robot->lookup(Direction::none);
	pos.f = pos.g + pos.h;
	pos.come_x = pos.x;
	pos.come_y = pos.y;
    pos.d = Direction::none;
	openset.push(pos);
	POINT start = pos;

	while(!openset.empty()){
		POINT x = openset.top();
		for(int j = 0; j < map.size(); ++j)
		{
			if(map[j] == x){
				x = map[j];	
			}
		}
		openset.pop();
        robot->jump(x);
		if(0 == robot->lookup(Direction::none)){
			POINT point_go = x;
			while(!(point_go == start)){
                path.push_back(point_go);

				point_go.x = point_go.come_x;
				point_go.y = point_go.come_y;
				for(int j = 0; j < map.size(); ++j)
				{
					if(map[j] == point_go){
						point_go = map[j];	
					}
				}
			}

			path.push_back(point_go);
			return path;
		}
		closed.push_back(x);

		neighbours.clear();
        neighbours = get_success(x, x.d);
        //none
        for (int i = 0; i < neighbours.size(); ++i)
		{
			if(std::find(closed.begin(), closed.end(), neighbours[i]) != closed.end()){
				continue;
            }
            int ten_g = x.g + neighbours[i].g;
			for(int j = 0; j < map.size(); ++j)
			{
				if(map[j] == neighbours[i]){
					neighbours[i] = map[j];	
				}
			}
			bool flag = false;
			bool put = false;
			if(openset.find(neighbours[i]) == openset.end()){
					flag = true;
					put = true;
			}else{
				if(ten_g < neighbours[i].g){
					flag = true;
				}else{
					flag = false;
				}
			}
			if(true == flag){
				neighbours[i].come_x = x.x;
				neighbours[i].come_y = x.y;
				neighbours[i].g = ten_g;
				robot->jump(neighbours[i]);
				neighbours[i].h = robot->lookup(Direction::none);
				neighbours[i].f = neighbours[i].g + neighbours[i].h;

				if(true == put){
					openset.push(neighbours[i]);
					map.push_back(neighbours[i]);
				}else{
					for (int j = 0; j < map.size(); ++j)
					{
						if(map[j] == neighbours[i]){
							map[j] = neighbours[i];	
						}
					}
				}
			}
		}
	}
	return path;
}
