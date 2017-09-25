//
// Created by nanotex426 on 24.09.17.
//

#ifndef TSDB_METRIC_VALUE_H
#define TSDB_METRIC_VALUE_H


#include <ctime>
#include <cstring>
#include "metric.h"

template <class T>
class MetricValue {
private:

    std::time_t metric_time;

    T metric_value;

public:

    MetricValue();

};


#endif //TSDB_METRIC_VALUE_H
