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
    explicit MetricData(__long_double_t metric_value);
    explicit MetricData(std::time_t timestamp, __long_double_t metric_value);
    explicit MetricData(const MetricData &obj);

    ~MetricData();

    // operator override
    std::string             operator()();

    // setters and getters

    void                        set_timestamp(std::time_t timestamp);
    std::time_t                 get_timestamp();

    void                        set_metric_value(__long_double_t metric_value);
    __long_double_t             get_metric_value();

private:

    std::time_t                 timestamp;

    __long_double_t             metric_value;
};

MetricData::MetricData(__long_double_t metric_value):
        timestamp(std::time(nullptr)),
        metric_value(metric_value)
{
}

MetricData::MetricData(std::time_t timestamp, __long_double_t metric_value):
    timestamp(timestamp),
    metric_value(metric_value)
{
}

MetricData::MetricData(const MetricData &obj)
{
    timestamp = obj.timestamp;
    metric_value = obj.metric_value;
}

MetricData::~MetricData()
{
    this->timestamp = NULL;
    this->metric_value = NULL;
}


std::string MetricData::operator()()
{
    std::string result;

    result = std::to_string(this->timestamp)
            .append("|")
            .append(std::to_string(this->metric_value));

    return result;
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

__long_double_t MetricData::get_metric_value()
{
    return this->metric_value;
}

#endif //TSDB_METRIC_DATA_H
