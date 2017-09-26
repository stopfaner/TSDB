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

    void                        insert_metric(MetricData& metric_data);
    void                        insert_metric(std::vector<MetricData>* metrics);

private:

    std::fstream                get_or_create_file(const char* filename) override;

};

MetricDataFileManager::MetricDataFileManager(const char *filename)
{
    this->filename = filename;

    file_stream.open(this->filename,std::ios::out |
                                     std::ios::app |
                                     std::ios::in |
                                     std::ifstream::ate |
                                     std::ifstream::binary);

}


void MetricDataFileManager::insert_metric(MetricData& metric_data)
{
    if (this->file_stream.is_open())
    {
        std::string metric = metric_data();

        this->file_stream.write(metric.c_str(), metric.length());
        this->file_stream.write("\n", 1);
        this->file_stream.close();
    }
}

void MetricDataFileManager::insert_metric(std::vector<MetricData>* metrics)
{

}


std::fstream MetricDataFileManager::get_or_create_file(const char* filename)
{
    this->filename = filename;

    std::fstream file_stream;

    if (!this->file_exists(this->filename))
    {
        // creating new file
        file_stream.open(this->filename, std::ios::out |
                                                std::ios::app |
                                                std::ios::in |
                                                std::ifstream::ate |
                                                std::ifstream::binary);
        file_stream.close();
    }

    //open new file
    file_stream.open(this->filename, std::ios::out |
                                            std::ios::app |
                                            std::ios::in |
                                            std::ifstream::ate |
                                            std::ifstream::binary);

    return file_stream;
}


#endif //TSDB_METRIC_DATA_FILE_MANAGER_H
