//
// Created by nanotex426 on 25.09.17.
//

#ifndef TSDB_METRIC_FILE_MANAGER_H
#define TSDB_METRIC_FILE_MANAGER_H

#include <fstream>
#include <boost/lexical_cast.hpp>
#include "metric.h"
#include "../file_manager.h"
#include "size_const.h"


extern const uint32_t METRIC_TIMESTAMP_OFFSET;

using namespace boost;


class MetricFileManager: protected FileManager
{
public:

    // constructor
    explicit MetricFileManager(const char* filename);

    Metric*                 get_metric_by_name(const char* metric_name);

    Metric*                 add_new_metric(const char* metric_name);

private:

    int32_t                 metric_binary_search(uint32_t left, uint32_t right, const char* metric_name);

    uint32_t                get_metric_file_size();

    std::string             get_name_with_offset(uint32_t offset);
    std::string             get_uuid_with_offset(uint32_t offset);
    std::string             get_creation_with_offset(uint32_t offset);

    std::fstream            get_or_create_file(const char* filename) override;

};

MetricFileManager::MetricFileManager(const char *filename)
{
    this->filename = filename;

    file_stream.open(this->filename,
                     std::ios::out |
                             std::ios::app |
                             std::ios::in |
                             std::ifstream::ate |
                             std::ifstream::binary);

}


Metric* MetricFileManager::add_new_metric(const char* metric_name)
{

    //TODO: add
    // Generating new metric by name
    auto metric = new Metric(metric_name);

    this->file_stream.write(metric->get_metric_name(), metric->get_metric_name_size());
    this->file_stream.write(uuids::to_string(metric->get_metric_uuid()).c_str(), metric->get_metric_uuid_size());
    this->file_stream.write(std::to_string(metric->get_creation_time()).c_str(), metric->get_creation_time_size());
    this->file_stream.write("\n", 1);

    this->file_stream.close();

    return metric;
}


Metric* MetricFileManager::get_metric_by_name(const char* metric_name)
{
    uint32_t lines_count = this->get_metric_file_size() / (METRIC_ROW_SIZE + 1);
    if (lines_count == 0)
        return NULL;

    int32_t offset_index = this->metric_binary_search(0, lines_count - 1, metric_name);

    if (offset_index == -1)
        return NULL;

    uint32_t offset = offset_index * (METRIC_ROW_SIZE + 1);

    auto metric = new Metric(this->get_name_with_offset(offset).c_str(),
                             lexical_cast<uuids::uuid> (this->get_uuid_with_offset(offset)),
                             lexical_cast<std::time_t>(this->get_creation_with_offset(offset)));

    return metric;
}


int32_t MetricFileManager::metric_binary_search(uint32_t left, uint32_t right, const char* metric_name)
{

    if (left <= right)
    {
        uint32_t middle = left + (right - left) / 2;

        if (strcmp(this->get_name_with_offset(middle * (METRIC_ROW_SIZE + 1)).c_str(), metric_name) == 0)
            return middle;

        if (strcmp(this->get_name_with_offset(middle * (METRIC_ROW_SIZE + 1)).c_str(), metric_name) < 0)
            return this->metric_binary_search(middle + 1, right, metric_name);

        else
            return this->metric_binary_search(left, middle - 1, metric_name);
    }

    return -1;
}


std::string MetricFileManager::get_name_with_offset(uint32_t offset)
{
    auto name = (char*) malloc(METRIC_NAME_SIZE);

    if (this->file_stream.is_open()) {
        this->file_stream.seekg(offset);
        this->file_stream.read(name, METRIC_NAME_SIZE);

        return this->trim_string(name);
    }

    return NULL;
}

std::string MetricFileManager::get_uuid_with_offset(uint32_t offset)
{
    auto uuid = (char*) malloc(METRIC_UUID_SIZE);

    if (this->file_stream.is_open())
    {
        this->file_stream.seekg(offset + METRIC_UUID_OFFSET);
        this->file_stream.read(uuid, METRIC_UUID_SIZE);

        std::string uuid_str(uuid);

        return uuid_str;
    }

    return NULL;
}

std::string MetricFileManager::get_creation_with_offset(uint32_t offset)
{
    auto timestamp = (char*) malloc(METRIC_TIMESTAMP_SIZE);

    if (this->file_stream.is_open())
    {
        this->file_stream.seekg(offset + METRIC_TIMESTAMP_OFFSET);
        this->file_stream.read(timestamp, METRIC_TIMESTAMP_SIZE);


        return timestamp;
    }

    return NULL;
}

uint32_t MetricFileManager::get_metric_file_size()
{
    if (this->file_stream.is_open())
    {
        return (uint32_t)file_stream.tellg();
    }

    return (uint32_t)-1;
}


std::fstream MetricFileManager::get_or_create_file(const char* filename)
{

}


#endif //TSDB_METRIC_FILE_MANAGER_H
