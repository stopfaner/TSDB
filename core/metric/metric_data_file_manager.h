//
// Created by nanotex426 on 26.09.17.
//

#ifndef TSDB_METRIC_DATA_FILE_MANAGER_H
#define TSDB_METRIC_DATA_FILE_MANAGER_H

#include "../file_manager.h"
#include "metric_data.h"

class MetricDataFileManager:
        protected FileManager
{
public:

    // constructor
    explicit MetricDataFileManager(const char* filename);


private:

    std::fstream                get_or_create_file(const char* filename) override;

    void                        insert_metric(MetricData* metricData);
};

MetricDataFileManager::MetricDataFileManager(const char *filename)
{
    this->filename = filename;
}


void MetricDataFileManager::insert_metric(MetricData *metricData)
{

}


std::fstream MetricDataFileManager::get_or_create_file(const char *filename)
{

}


#endif //TSDB_METRIC_DATA_FILE_MANAGER_H
