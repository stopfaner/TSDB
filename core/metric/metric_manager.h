//
// Created by nanotex426 on 25.09.17.
//

#ifndef TSDB_METRIC_MANAGER_H
#define TSDB_METRIC_MANAGER_H

#include <cstdio>
#include <vector>
#include <fcntl.h>
#include "size_const.h"

class MetricManager
{
public:
    MetricManager();

    explicit MetricManager(const char* filename);

    void insert_metric(const char* metric_name, double_t metric_value);

private:
    const char* filename;

    int32_t file_descriptor;

    std::vector<Metric>* metric_list;

    off_t file_length;

    Metric* seek_for_metric(const char* metric_name);

};

MetricManager::MetricManager():
        filename("metric.db")
{

    this->file_descriptor = open(this->filename,
                                 O_RDWR |
                                 O_CREAT,
                                 S_IWUSR |
                                 S_IRUSR);

    if (this->file_descriptor == -1)
        std::cout << "File cannot be opened" << std::endl;

    this->metric_list = new std::vector<Metric>();
//    this->file_length = lseek(this->file_descriptor, 0, SEEK_END);
}

MetricManager::MetricManager(const char* filename):
    filename(filename)
{


}

void MetricManager::insert_metric(const char* metric_name, double_t metric_value)
{

    Metric* metric = new Metric(metric_name);

    this->metric_list->push_back(*metric);

    if (this->seek_for_metric(metric_name) != NULL)
    {

    } else
    {
        ssize_t bytes_written =
                write(this->file_descriptor, (*metric)(), METRIC_ROW_SIZE);

        if (bytes_written <= 0)
        {
            std::cout << "Error writing into file" << std::endl;
        }
    }

//    ssize_t bytes_written =
//            write(this->)


//    ssize_t bytes_written =
//            write(this->file_descriptor, , METRIC_ROW_SIZE);
}

Metric* MetricManager::seek_for_metric(const char* metric_name)
{
    return NULL;
}

#endif //TSDB_METRIC_MANAGER_H
