#include "pars.h"

Parser::Parser(int argc, char **argv){
    opt = new AnyOption();
    opt->addUsage( "" );
    opt->addUsage( "Usage: " );
    opt->addUsage( "" );
    opt->addUsage( " -h  --help печать сообщения со списком параметров программы и завершение работы " );
    opt->addUsage( " -s  --space имя текстового файла с описанием пространства default: space.txt" );
    opt->addUsage( " -o  --out - итоговый текстовый файл с маршрутом default: route.txt" );
    opt->addUsage( " -l  --limit - число максимальная длина дистанции." );
    opt->addUsage( "				Если маршрут достигает данной длины он отбрасывается default: 1000" );
    opt->addUsage( " -t  --topology - перечисление которое определяет топологию пространства. Default: planar. " );
    opt->addUsage( " 					Возможные значения: " );
    opt->addUsage( "					 planar - плоский лист " );
    opt->addUsage( "					 cylinder - файл содержит разрезанный цилиндр " );
    opt->addUsage( "					 tor - файл содержит развернутый тор" );


    opt->setFlag("help", 'h');
    opt->setOption("space", 's' );
    opt->setOption("out", 'o' );
    opt->setOption("limit", 'l' );
    opt->setOption("topology", 't');

    opt->processFile( "/home/user/.options" );
    opt->processCommandArgs( argc, argv );

    space = "space.txt";
    out = "route.txt";
    limit = 1000;
    topology = "planar";

    if( opt->getFlag( "help" ) || opt->getFlag( 'h' ) ){
        opt->printUsage();
    }
    if((opt->getValue( 's' )!=NULL)  || (opt->getValue( "space" )!=NULL)){
        space = opt->getValue('s');
    }
    if((opt->getValue( 'o' )!=NULL)  || (opt->getValue( "out" )!=NULL)){
        out = opt->getValue('o');
    }
    if((opt->getValue( 'l' )!=NULL)  || (opt->getValue( "limit" )!=NULL)){
        limit = atoi(opt->getValue('l'));
    }
    if((opt->getValue( 't' )!=NULL)  || (opt->getValue( "topology" )!=NULL)){
        topology = opt->getValue('t');
    }
}

Parser::Parser(){
    throw BadParametrs();
}

Parser::Parser(const Parser & prs){
    delete opt;
    opt = prs.opt;
    space = prs.space;
    out = prs.out;
    limit = prs.limit;
    topology = prs.topology;
}

Parser& Parser::operator=(const Parser& right){
    if (this == &right){
        return *this;
    }
    delete opt;
    opt = right.opt;
    space = right.space;
    out = right.out;
    limit = right.limit;
    topology = right.topology;
    return *this;
}

Parser::~Parser(){
    delete opt;
}

const std::string & Parser::get_space() const{
    return space;
}
const std::string & Parser::get_out() const{
    return out;
}
const int Parser::get_limit() const{
    return limit;
}
const std::string & Parser::get_topology() const{
    return topology;
}

