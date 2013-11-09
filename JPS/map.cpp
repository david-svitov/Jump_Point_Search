#include "map.h"

Map::Map(){
}

std::istream& operator>>(std::istream &in, Map &c){
    int j = 0;
    std::string str;
    while(in){
        in >> str;
        for (int i = 0; i < str.size(); ++i)
        {
            if(FINISH == str[i]){
                c.finish.x = i;
                c.finish.y = j;
            }
            if(START == str[i]){
                c.start.x = i;
                c.start.y = j;
            }
        }
        c.map_arr.push_back(str);
        j++;
    }
    c.map_arr.pop_back();
    return in;
}

std::ostream & operator<<(std::ostream & out, const Map & c){
	for (int i = 0; i < c.map_arr.size(); ++i)
	{
        out << c.map_arr[i];
        if(i < c.map_arr.size() - 1){
            out << "\n";
        }
	}
	return out;
}

const POINT Map::get_finish() const{
	return finish;
}
const POINT Map::get_start() const{
	return start;
}

void Map::set_start(const POINT & t){
    start = t;
}

void Map::set_finish(const POINT &t){
    finish = t;
}

const int Map::get_width() const{
    return map_arr[0].size();
}
const int Map::get_height() const{
	return map_arr.size();
}

const char Map::get_value(POINT p) const{
	return map_arr[p.y][p.x];
}
const char Map::get_value(int x, int y) const{
	return map_arr[y][x];
}

void Map::set_value(POINT p, char c){
	map_arr[p.y][p.x] = c;
}
void Map::set_value(int x, int y, char c){
	map_arr[y][x] = c;
}

void Map::draw_path(QList<POINT> path){
    if(0 >= path.size()) return;
    int prev_x = path[0].x;
    int prev_y = path[0].y;
    int dx = 0;
    int dy = 0;
    for(int i = 0; i < path.size(); ++i)
    {
        if(prev_x == path[i].x) dx = 0;
        if(prev_y == path[i].y) dy = 0;
        while((prev_x != path[i].x) || (prev_y != path[i].y)){

            if(FINISH != map_arr[prev_y][prev_x] && START != map_arr[prev_y][prev_x]){
                map_arr[prev_y][prev_x] = '?';
            }
            prev_x += dx;
            prev_y += dy;

            if(prev_x < 0){
                prev_x = get_width()-1;
            }else
            if(prev_x >= get_width()){
                prev_x = 0;
            }

            if(prev_y < 0){
                prev_y = get_height()-1;
            }else
            if(prev_y >= get_height()){
                prev_y = 0;
            }
        }

        prev_x = path[i].x;
        prev_y = path[i].y;

        dx = 0;
        if((Direction::left_forward == path[i].d) || (Direction::left == path[i].d) || (Direction::left_back == path[i].d)){
            dx = 1;
        }
        if((Direction::right_forward == path[i].d) || (Direction::right == path[i].d) || (Direction::right_back == path[i].d)){
            dx = -1;
        }

        dy = 0;
        if((Direction::forward == path[i].d) || (Direction::left_forward == path[i].d) || (Direction::right_forward == path[i].d)){
            dy = 1;
        }
        if((Direction::back == path[i].d) || (Direction::left_back == path[i].d) || (Direction::right_back == path[i].d)){
            dy = -1;
        }
    }
}

void Map::Clean(){
    map_arr.clear();
}

void Map::set_width(int t){
    int old_w = 0;
    for(int i = 0; i < map_arr.size(); ++i){
        old_w = map_arr[i].size();
        map_arr[i].resize(t);
        for(int j = old_w; j < map_arr[i].size(); ++j){
            map_arr[i][j] = '.';
        }
    }
}

void Map::set_height(int t){
    int old_h = map_arr.size();
    std::string put = "";
    for(int j = 0; j < map_arr[0].size(); ++j){
        put += ".";
    }
    if(t >= old_h){
        for(int i = old_h; i < t; i++){
            map_arr.push_back(put);
        }
    }else{
        for(int i = t; i < old_h; i++){
            map_arr.pop_back();
        }
    }
}

void Map::clear_path(){
    for (int i = 0; i < map_arr.size(); ++i)
    {
        for (int j = 0; j < map_arr[i].size(); ++j)
        {
            if('?' == map_arr[i][j]){
                map_arr[i][j] = '.';
            }
        }
    }
}
