//
// Created by nanotex426 on 28.09.17.
//

#ifndef TSDB_FIELD_TIME_H
#define TSDB_FIELD_TIME_H

#include <ctime>
#include "field.h"

class FieldTime: protected Field // TODO: add inheritance from Field model
{
public:

    FieldTime();
    explicit FieldTime(std::time_t time);

    ~FieldTime();

    void                        set_m_time(std::time_t time);
    std::time_t                 get_m_time() const;

    static ssize_t              get_size();

private:

    std::time_t                 m_time;

};

FieldTime::FieldTime():
    m_time(std::time(nullptr))
{
}

FieldTime::FieldTime(std::time_t time)
{
    this->m_time = time;
}

FieldTime::~FieldTime()
{
}


void FieldTime::set_m_time(std::time_t time)
{
    this->m_time = time;
}

std::time_t FieldTime::get_m_time() const
{
    return this->m_time;
}

ssize_t FieldTime::get_size()
{
    return sizeof(FieldTime);
}

#endif //TSDB_FIELD_TIME_H
