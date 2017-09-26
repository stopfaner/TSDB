//
// Created by nanotex426 on 26.09.17.
//

#ifndef TSDB_METRIC_DATA_H
#define TSDB_METRIC_DATA_H

#include <ctime>

class MetricData
{
public:

    //constructor
    MetricData();
    explicit MetricData(std::time_t timestamp, __long_double_t metric_value);

    // operator override
    std::string             operator()();

    // setters and getters

    void                        set_timestamp(std::time_t timestamp);
    std::time_t                 get_timestamp();

    void                        set_metric_value(__long_double_t metric_value);
    __long_double_t             get_mertric_value();

private:

    std::time_t                 timestamp;

    __long_double_t             metric_value;
};


MetricData::MetricData()
{

}

MetricData::MetricData(std::time_t timestamp, __long_double_t metric_value):
    timestamp(timestamp),
    metric_value(metric_value)
{
}

std::string MetricData::operator()()
{

}

void MetricData::set_timestamp(std::time_t timestamp)
{
    this->timestamp = timestamp;
}

std::time_t MetricData::get_timestamp()
{
    return this->timestamp;
}

void MetricData::set_metric_value(__long_double_t metric_value)
{
    this->metric_value = metric_value;
}

__long_double_t MetricData::get_mertric_value()
{
    return this->metric_value;
}

#endif //TSDB_METRIC_DATA_H
