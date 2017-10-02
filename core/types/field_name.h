//
// Created by nanotex426 on 28.09.17.
//

#ifndef TSDB_FIELD_NAME_H
#define TSDB_FIELD_NAME_H

#include <string>
#include <stdio.h>
#include <cstring>
#include "field.h"

using namespace std;

class FieldName: protected Field
{
public:
    FieldName();
    explicit FieldName(char* name);


    void                    set_metric_name(char* name);
    char*                   get_name();

    static ssize_t          get_size();

private:
    char                    metric_name[32];

    char*                   trim_string(char* string);
};


FieldName::FieldName()
{
}

FieldName::FieldName(char* name)
{
    this->set_metric_name(name);
}

void FieldName::set_metric_name(char* name)
{
    if (strlen(name) > 32)
        return;

    strcpy(this->metric_name, name);
}

char* FieldName::get_name()
{
    return this->metric_name;
}

ssize_t FieldName::get_size()
{
    return sizeof(FieldName);
}


char* FieldName::trim_string(char* string)
{
    std::string str(string);
    size_t first = str.find_first_not_of(' ');

    if (std::string::npos == first)
    {
        return string;
    }
    size_t last = str.find_last_not_of(' ');

    return (char*) str.substr(first, (last - first + 1)).c_str();
}

#endif //TSDB_FIELD_NAME_H
