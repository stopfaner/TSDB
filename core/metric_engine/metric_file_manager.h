//
// Created by nanotex426 on 25.09.17.
//

#ifndef TSDB_METRIC_FILE_MANAGER_H
#define TSDB_METRIC_FILE_MANAGER_H

#include <fstream>
#include <boost/lexical_cast.hpp>
#include "../types/field_metric.h"
#include "../file_manager.h"
#include "size_const.h"


extern const uint32_t METRIC_TIMESTAMP_OFFSET;

using namespace boost;


class MetricFileManager: protected FileManager
{
public:

    // constructor
    explicit MetricFileManager(const char* filename);


    std::map<std::string, Metric>*        load_metrics_from_file();

    void                                  upload_metrics_to_file(std::map<std::string, Metric>* new_metric);

private:

    int32_t                     get_metric_file_size();

    std::fstream*                get_or_create_stream() override;


};

MetricFileManager::MetricFileManager(const char *filename)
{
    this->filename = filename;
    this->file_stream = this->get_or_create_stream();
}


std::map<std::string, Metric>* MetricFileManager::load_metrics_from_file()
{
    std::map<std::string, Metric>* loaded_metrics = new std::map<std::string, Metric>();

    if (this->file_stream = this->get_or_create_stream())
    {
        int32_t file_size = this->get_metric_file_size();

        if (file_size == -1 || file_size == 0)
        {
            cout << "File is empty or does not exists" << endl;

            return NULL;
        }

        // Count of FieldMetric objects in file
        int32_t file_length = file_size / (int32_t) FieldMetric::get_size();

        for (uint32_t i = 0; i < (uint32_t) file_length; i++)
        {
            FieldMetric* field_metric = new FieldMetric();
            this->file_stream->seekg(i * FieldMetric::get_size());
            this->file_stream->read((char*) field_metric, FieldMetric::get_size());

            Metric metric(field_metric);

            loaded_metrics->insert(std::pair<std::string, Metric>
                                           (field_metric->get_metric_name(), metric));
        }
    }

    return loaded_metrics;
}

void MetricFileManager::upload_metrics_to_file(std::map<std::string, Metric>* new_metric)
{
    if (this->file_stream = get_or_create_stream())
    {
        if (new_metric->size() == 0)
            return;

        for (auto& t : *new_metric)
        {
            // Getting Metric data
            FieldMetric* field = t.second.get_metric_field();

            this->file_stream->write((char*) field, FieldMetric::get_size());
        }
    }

    this->file_stream->close();
}

int32_t MetricFileManager::get_metric_file_size()
{
    if (this->file_stream->is_open())
    {
        this->file_stream->seekg(0, std::ios_base::end);
        return (int32_t)file_stream->tellg();
    }

    return (int32_t) -1;
}

std::fstream* MetricFileManager::get_or_create_stream()
{
    if (this->file_stream == NULL)
        this->file_stream = new fstream();

    if (this->file_stream->is_open())
        return this->file_stream;

    this->file_stream->open(filename,
                            std::ios::out | std::ios::binary | std::ios::in | std::ios::app);

    return this->file_stream;
}


#endif //TSDB_METRIC_FILE_MANAGER_H
