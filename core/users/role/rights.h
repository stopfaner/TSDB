//
// Created by nanotex426 on 25.09.17.
//

#ifndef TSDB_RIGHTS_H
#define TSDB_RIGHTS_H

enum AdminRights
{
    CREATE_DB,
    DELETE_DB,
    UPDATE_DB
};

enum UserRights
{
    READ,
    WRITE,
    READ_WRITE
};

#endif //TSDB_RIGHTS_H
