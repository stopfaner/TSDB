//
// Created by nanotex426 on 02.10.17.
//

#ifndef TSDB_FIELD_TAG_H
#define TSDB_FIELD_TAG_H

#include "field.h"

class FieldTag: public Field
{
public:

private:
    char                    tag_name[32];

    char*                   trim_string(char* string);
};

#endif //TSDB_FIELD_TAG_H
