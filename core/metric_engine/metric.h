//
// Created by nanotex426 on 24.09.17.
//

#ifndef TSDB_METRIC_H
#define TSDB_METRIC_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <iostream>
#include "../types/field_metric.h"

using namespace boost;

class Metric {

private:
    FieldMetric* m_metric;

public:

    //constructor
    explicit Metric(char* metric_name);
    explicit Metric(FieldMetric* metric);


    FieldMetric*                get_metric_field() const;

};


Metric::Metric(char* metric_name)
{
    this->m_metric = new FieldMetric(metric_name);
}

Metric::Metric(FieldMetric* metric)
{
    this->m_metric = metric;
}


FieldMetric* Metric::get_metric_field() const
{
    return this->m_metric;
}


#endif //TSDB_METRIC_H
