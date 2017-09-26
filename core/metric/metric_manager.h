//
// Created by nanotex426 on 25.09.17.
//

#ifndef TSDB_METRIC_MANAGER_H
#define TSDB_METRIC_MANAGER_H

#include <cstdio>
#include <vector>
#include <fstream>
#include "size_const.h"
#include "metric_file_manager.h"
#include "../action_manager.h"
#include "metric_data.h"

class MetricManager: public ActionManager
{
public:
    //constructor
    MetricManager();

    ~MetricManager();


    void                    insert_metric(const char* metric_name, MetricData* metric_data);
    void                    create_metric(const char* metric_name);
    void                    delete_metric(const char* metric_name);

private:
    const char*             filename;

    std::vector<Metric>     metrics_cache;

    MetricFileManager*      m_file_manager;
};

MetricManager::MetricManager():
        filename("metric.db")
{
    m_file_manager = new MetricFileManager(this->filename);
}

MetricManager::~MetricManager()
{
}

void MetricManager::insert_metric(const char* metric_name, MetricData* metric_data)
{
    Metric* metric;

    if (metric = this->m_file_manager->get_metric_by_name(metric_name))
    {
    } else {

        //Create new metric and write down it into db
        metric = new Metric(metric_name);

        this->m_file_manager->add_new_metric(metric_name);

    }
}

void MetricManager::create_metric(const char* metric_name)
{
    if (strlen(metric_name) > METRIC_NAME_SIZE)
        return;
//    if (this->m_file_manager->get_metric_by_name(metric_name))
//        return;
//
    this->m_file_manager->add_new_metric(metric_name);
}

void MetricManager::delete_metric(const char *metric_name)
{

}

#endif //TSDB_METRIC_MANAGER_H
