//
// Created by nanotex426 on 28.09.17.
//

#ifndef TSDB_FIELD_METRIC_H
#define TSDB_FIELD_METRIC_H

#include "field.h"
#include "field_uuid.h"
#include "field_time.h"
#include "field_name.h"

class FieldMetric: protected Field
{
public:
    //constructor
    FieldMetric();
    explicit FieldMetric(char* metric_name);
    explicit FieldMetric(char* metric_name, uuids::uuid metric_uuid, std::time_t creation_time);

    // UUID setters and getters
    uuids::uuid                     get_metric_uuid() const;
    void                            set_metric_uuid(boost::uuids::uuid metric_uuid);

    // Timestamp setters and getters
    std::time_t                     get_creation_time() const;
    void                            set_creation_time(std::time_t creation_time);

    char*                          get_metric_name();
    void                            set_metric_name(char* metric_name);

    static ssize_t                  get_size();

private:
    FieldUUID                       metric_uuid;

    FieldTime                       creation_time;

    FieldName                       metric_name;

};


FieldMetric::FieldMetric()
{
    this->metric_name = FieldName();
}


FieldMetric::FieldMetric(char* metric_name)
{
    this->metric_name = FieldName(metric_name);
    this->metric_uuid = FieldUUID(uuids::basic_random_generator<boost::mt19937>()());
    this->creation_time = FieldTime(std::time(nullptr));
}


FieldMetric::FieldMetric(char* metric_name, uuids::uuid metric_uuid, std::time_t creation_time)
{
    this->metric_name = FieldName(metric_name);
    this->metric_uuid = FieldUUID(metric_uuid);
    this->creation_time = FieldTime(creation_time);
}


uuids::uuid FieldMetric::get_metric_uuid() const
{
    return this->metric_uuid.get_uuid_value();
}

void FieldMetric::set_metric_uuid(boost::uuids::uuid metric_uuid)
{
    this->metric_uuid = FieldUUID(metric_uuid);
}
std::time_t FieldMetric::get_creation_time() const
{
    return this->creation_time.get_m_time();
}

void FieldMetric::set_creation_time(std::time_t creation_time)
{
    this->creation_time = FieldTime(creation_time);
}

char* FieldMetric::get_metric_name()
{
    return this->metric_name.get_name();
}

void FieldMetric::set_metric_name(char* metric_name)
{
    this->metric_name.set_metric_name(metric_name);
}


ssize_t FieldMetric::get_size()
{
    return sizeof(FieldMetric);
}

#endif //TSDB_FIELD_METRIC_H
