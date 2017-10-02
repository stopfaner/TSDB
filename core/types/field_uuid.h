//
// Created by nanotex426 on 28.09.17.
//

#ifndef TSDB_FIELD_UUID_H
#define TSDB_FIELD_UUID_H

#include "field.h"

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

using namespace boost;

class FieldUUID: protected Field
{
public:

    FieldUUID();
    explicit FieldUUID(uuids::uuid uuid_value);

    ~FieldUUID();


    void                        set_uuid_value(uuids::uuid uuid_value);
    uuids::uuid                 get_uuid_value() const;

    static ssize_t              get_size();


private:
    uuids::uuid                 uuid_value;

};

FieldUUID::FieldUUID()
{
}

FieldUUID::FieldUUID(uuids::uuid uuid_value)
{
    this->uuid_value = uuid_value;
}

FieldUUID::~FieldUUID()
{
}


void FieldUUID::set_uuid_value(uuids::uuid uuid_value)
{
    this->uuid_value = uuid_value;
}

uuids::uuid FieldUUID::get_uuid_value() const
{
    return this->uuid_value;
}

ssize_t FieldUUID::get_size()
{
    return sizeof(FieldUUID);
}

#endif //TSDB_FIELD_UUID_H
