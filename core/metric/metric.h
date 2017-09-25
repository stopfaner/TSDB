//
// Created by nanotex426 on 24.09.17.
//

#ifndef TSDB_METRIC_H
#define TSDB_METRIC_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>

using namespace boost;

const uint32_t NAME_SIZE = 32;
extern const uint32_t METRIC_ROW_SIZE;

class Metric {

private:
    uuids::uuid metric_uuid;

    std::time_t creation_time;

    char metric_name[NAME_SIZE + 1];


public:

    Metric();

    explicit Metric(const char* metric_name);

    uuids::uuid get_metric_uuid();

    std::time_t get_creation_time();

    char* get_metric_name();

    void set_metric_name(char* metric_name);

    char* operator()();
};


Metric::Metric():
        metric_uuid(boost::uuids::basic_random_generator<boost::mt19937>()()),
        creation_time(std::time(nullptr))
{

}

Metric::Metric(const char* metric_name):
        metric_uuid(boost::uuids::basic_random_generator<boost::mt19937>()()),
        creation_time(std::time(nullptr))
{
    if (strlen(metric_name) < NAME_SIZE) {
        strcpy(this->metric_name, metric_name);
    }
}



uuids::uuid Metric::get_metric_uuid()
{
    return this->metric_uuid;
}


std::time_t Metric::get_creation_time()
{
    return this->creation_time;
}


char* Metric::get_metric_name()
{
    return this->metric_name;
}


void Metric::set_metric_name(char* metric_name)
{
    if (strlen(metric_name) < NAME_SIZE) {
        strcpy(this->metric_name, metric_name);
    }
}

char* Metric::operator()()
{
    auto row = (char*) malloc(METRIC_ROW_SIZE);
//    return uuids::to_string(this->metric_uuid).c_str() +
//            std::to_string(this->creation_time).c_str()

    strcpy(row, uuids::to_string(this->metric_uuid).c_str());
    strcpy(row, std::to_string(this->creation_time).c_str());
    strcpy(row, metric_name);

    std::cout<<uuids::to_string(this->metric_uuid).c_str();
    return row;
}

#endif //TSDB_METRIC_H
