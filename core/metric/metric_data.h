//
// Created by nanotex426 on 26.09.17.
//

#ifndef TSDB_METRIC_DATA_H
#define TSDB_METRIC_DATA_H

#include <ctime>

class MetricData
{
public:

private:

    std::time_t         timestamp;

    __long_double_t     metric_value;
};

#endif //TSDB_METRIC_DATA_H
