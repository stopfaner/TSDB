//
// Created by nanotex426 on 24.09.17.
//

#ifndef TSDB_METRIC_H
#define TSDB_METRIC_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include "metric_data_file_manager.h"

using namespace boost;

extern const uint32_t METRIC_NAME_SIZE;
extern const uint32_t METRIC_UUID_SIZE;
extern const uint32_t METRIC_TIMESTAMP_SIZE;
extern const uint32_t METRIC_ROW_SIZE;

class Metric {

private:
    uuids::uuid                     metric_uuid;

    std::time_t                     creation_time;

    char                            metric_name[32];

    std::vector<MetricData>         metrics_list;

    MetricDataFileManager*          m_data_file_manager;

public:

    //constructor
    Metric();
    explicit Metric(const char* metric_name);
    explicit Metric(const char* metric_name, uuids::uuid metric_uuid, std::time_t creation_time);
    ~Metric();

    void                            append_metric(MetricData &metric_data);

    // UUID setters and getters
    uuids::uuid                     get_metric_uuid() const;
    void                            set_metric_uuid(boost::uuids::uuid metric_uuid);
    uint32_t                        get_metric_uuid_size() const;

    // Timestamp setters and getters
    std::time_t                     get_creation_time() const;
    void                            set_creation_time(std::time_t creation_time);
    uint32_t                        get_creation_time_size() const;

    char*                           get_metric_name();
    void                            set_metric_name(const char* metric_name);
    uint32_t                        get_metric_name_size() const;

    // operators overriding
};

Metric::Metric()
{

}


Metric::Metric(const char* metric_name):
        metric_uuid(uuids::basic_random_generator<boost::mt19937>()()),
        creation_time(std::time(nullptr))
{
    if (strlen(metric_name) < METRIC_NAME_SIZE) {
        strcpy(this->metric_name, metric_name);
    }

    this->m_data_file_manager = new MetricDataFileManager(uuids::to_string(this->metric_uuid).c_str());
}


Metric::Metric(const char* metric_name, uuids::uuid metric_uuid, std::time_t creation_time)
{
    if (strlen(metric_name) < METRIC_NAME_SIZE) {
        strcpy(this->metric_name, metric_name);
    }

    this->metric_uuid = metric_uuid;
    this->creation_time = creation_time;


    this->m_data_file_manager = new MetricDataFileManager(uuids::to_string(this->metric_uuid).c_str());
}

Metric::~Metric()
{
    this->metrics_list.clear();

    delete[] m_data_file_manager;
}


void Metric::append_metric(MetricData &metric_data)
{
//    this->metrics_list.push_back(*metric_data);
    if (this->m_data_file_manager)
    {

        this->m_data_file_manager->insert_metric(metric_data);
    } else
    {
        this->m_data_file_manager = new MetricDataFileManager(uuids::to_string(this->metric_uuid).c_str());
        this->m_data_file_manager->insert_metric(metric_data);
    }
}



uuids::uuid Metric::get_metric_uuid() const
{
    return this->metric_uuid;
}

void Metric::set_metric_uuid(boost::uuids::uuid metric_uuid)
{
    this->metric_uuid = metric_uuid;
}

uint32_t Metric::get_metric_uuid_size() const
{
    return METRIC_UUID_SIZE;
}


std::time_t Metric::get_creation_time() const
{
    return this->creation_time;
}

void Metric::set_creation_time(std::time_t creation_time)
{
    this->creation_time = creation_time;
}

uint32_t Metric::get_creation_time_size() const
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

uint32_t Metric::get_metric_name_size() const
{
    return METRIC_NAME_SIZE;
}

#endif //TSDB_METRIC_H
