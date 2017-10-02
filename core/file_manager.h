//
// Created by nanotex426 on 26.09.17.
//

#ifndef TSDB_FILE_MANAGER_H
#define TSDB_FILE_MANAGER_H

#include <fstream>
#include <sys/stat.h>

class FileManager
{
protected:

    std::string                 filename;

    std::fstream*               file_stream;

    bool                        file_exists(const std::string& filename);

    virtual std::fstream*       get_or_create_stream() = 0;
};


bool FileManager::file_exists(const std::string& filename)
{
    struct stat buf;
    if (stat(filename.c_str(), &buf) != -1)
    {
        return true;
    }
    return false;
}

#endif //TSDB_FILE_MANAGER_H
