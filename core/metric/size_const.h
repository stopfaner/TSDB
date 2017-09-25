//
// Created by nanotex426 on 25.09.17.
//

#ifndef TSDB_SIZE_CONST_H
#define TSDB_SIZE_CONST_H


#include <cstdint>
#include "metric.h"

#define size_of_attribute(Class, Attribute) sizeof(((Class*)0)->Attribute)

const uint32_t METRIC_UUID_SIZE = sizeof("906348b4-91c1-43a1-b5a0-f7245410ed3b");
const uint32_t METRIC_TIMESTAMP_SIZE = size_of_attribute(Metric, get_creation_time());
const uint32_t METRIC_NAME_SIZE = size_of_attribute(Metric, get_metric_name());\

const uint32_t METRIC_UUID_OFFSET = 0;
const uint32_t METRIC_TIMESTAMP_OFFSET = METRIC_UUID_OFFSET + METRIC_UUID_SIZE;
const uint32_t METRIC_NAME_OFFSET = METRIC_TIMESTAMP_OFFSET + METRIC_TIMESTAMP_SIZE;
const uint32_t METRIC_ROW_SIZE = METRIC_UUID_SIZE + METRIC_TIMESTAMP_SIZE + METRIC_NAME_SIZE;



#endif //TSDB_SIZE_CONST_H
