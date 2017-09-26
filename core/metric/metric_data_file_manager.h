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

    void                        insert_metric(MetricData* metric_data);
    void                        insert_metric(std::vector<MetricData>* metrics);

private:

    std::fstream                get_or_create_file(const char* filename) override;

};

MetricDataFileManager::MetricDataFileManager(const char *filename)
{
    this->file_stream = this->get_or_create_file(filename);
}


void MetricDataFileManager::insert_metric(MetricData* metric_data)
{
    this->file_stream = get_or_create_file(this->filename);


}

void MetricDataFileManager::insert_metric(std::vector<MetricData>* metrics)
{

}


std::fstream MetricDataFileManager::get_or_create_file(const char* filename)
{
    this->filename = filename;

    if (!this->file_exists(this->filename))
    {
        std::fstream fs;
        fs.open(this->filename, std::ios::out);
        fs.close();
    }

    return std::fstream(filename, std::ios::in | std::ios::out);
}


#endif //TSDB_METRIC_DATA_FILE_MANAGER_H
