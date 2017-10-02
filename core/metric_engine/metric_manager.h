//
// Created by nanotex426 on 25.09.17.
//

#ifndef TSDB_METRIC_MANAGER_H
#define TSDB_METRIC_MANAGER_H

#include <cstdio>
#include <vector>
#include <fstream>
#include <map>
#include "metric_file_manager.h"
#include "../action_manager.h"

class MetricManager: public ActionManager
{
public:
    //constructor
    MetricManager();

    ~MetricManager();


    void                                    insert_metric(char* metric_name);
    void                                    create_metric(char* metric_name);
    void                                    delete_metric(std::string metric_name);

    std::map<std::string, Metric>*          get_loaded_map()
    {
        return this->loaded_metrics;
    };

    std::map<std::string, Metric>*          get_new_map()
    {
        return this->new_metrics;
    };

private:
    const char*                             filename;

    std::map<std::string, Metric>*          loaded_metrics;

    std::map<std::string, Metric>*          new_metrics;

    MetricFileManager*                      m_file_manager;

    void                                    load_metrics();
    void                                    upload_metrics();
};

MetricManager::MetricManager():
        filename("metric.db")
{
    m_file_manager = new MetricFileManager(this->filename);
    loaded_metrics = new std::map<std::string, Metric>();
    new_metrics = new std::map<std::string, Metric>();

    this->load_metrics();
}

MetricManager::~MetricManager()
{
    this->upload_metrics();

    delete loaded_metrics;
    delete new_metrics;
    delete m_file_manager;
}

void MetricManager::insert_metric(char* metric_name)
{
    if (strlen(metric_name) > 32)
        return;
}

void MetricManager::create_metric(char* metric_name)
{

    if (strlen(metric_name) > 32)
        return;

    if (loaded_metrics->find(metric_name) != loaded_metrics->end())
        return;

    Metric* metric = new Metric(metric_name);

    // Insert new metric_engine into cache
    new_metrics->insert(std::pair<std::string, Metric>(metric_name, *metric));
}

void MetricManager::delete_metric(std::string metric_name)
{

}

void MetricManager::load_metrics()
{
    this->loaded_metrics = m_file_manager->load_metrics_from_file();
}

void MetricManager::upload_metrics()
{
    this->m_file_manager->upload_metrics_to_file(new_metrics);
}

#endif //TSDB_METRIC_MANAGER_H
