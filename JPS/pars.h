#ifndef PARS_LIB
#define PARS_LIB

#include <string>
#include <cstdlib>
#include <exception>
#include "anyoption.h"

class BadParametrs: public std::exception{};

class Parser{
	AnyOption *opt;
	std::string space;
	std::string out;
    int limit;
	std::string topology;
public:
	Parser();
	Parser(int argc, char **argv);
	virtual ~Parser();

	Parser(const Parser & prs);
	Parser& operator=(const Parser& right);
	const std::string & get_space() const;
	const std::string & get_out() const;
    const int get_limit() const;
	const std::string & get_topology() const;
};


#endif
