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

extern const uint32_t METRIC_NAME_SIZE;
extern const uint32_t METRIC_UUID_SIZE;
extern const uint32_t METRIC_TIMESTAMP_SIZE;
extern const uint32_t METRIC_ROW_SIZE;

class Metric {

private:
    uuids::uuid metric_uuid;

    std::time_t creation_time;

    char metric_name[32];


public:

    Metric();

    explicit Metric(const char* metric_name);

    // UUID setters and getters
    uuids::uuid get_metric_uuid();
    void set_metric_uuid(boost::uuids::uuid metric_uuid);
    uint32_t get_metric_uuid_size();

    std::time_t get_creation_time();
    void set_creation_time(std::time_t creation_time);
    uint32_t get_creation_time_size();

    char* get_metric_name();
    void set_metric_name(const char* metric_name);
    uint32_t get_metric_name_size();

    char* operator()();
};


Metric::Metric()
{

}

Metric::Metric(const char* metric_name):
        metric_uuid(boost::uuids::basic_random_generator<boost::mt19937>()()),
        creation_time(std::time(nullptr))
{
    if (strlen(metric_name) < METRIC_NAME_SIZE) {
        strcpy(this->metric_name, metric_name);
    }
}



uuids::uuid Metric::get_metric_uuid()
{
    return this->metric_uuid;
}

void Metric::set_metric_uuid(boost::uuids::uuid metric_uuid)
{
    this->metric_uuid = metric_uuid;
}

uint32_t Metric::get_metric_uuid_size()
{
    return METRIC_UUID_SIZE;
}


std::time_t Metric::get_creation_time()
{
    return this->creation_time;
}

void Metric::set_creation_time(std::time_t creation_time)
{
    this->creation_time = creation_time;
}

uint32_t Metric::get_creation_time_size()
{
    return METRIC_TIMESTAMP_SIZE;
}


char* Metric::get_metric_name()
{
    return this->metric_name;
}

void Metric::set_metric_name(const char* metric_name)
{
    if (strlen(metric_name) < METRIC_NAME_SIZE) {
        strcpy(this->metric_name, metric_name);
    }
}

uint32_t Metric::get_metric_name_size()
{
    return METRIC_NAME_SIZE;
}


char* Metric::operator()()
{

}

#endif //TSDB_METRIC_H
