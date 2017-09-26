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

    const char*                 filename;

    std::fstream                file_stream;

    std::string                 trim_string(char* str);

    bool                        file_exists(const std::string& filename);

//    virtual bool                create_file(const char* filename) = 0;
    virtual std::fstream        get_or_create_file(const char* filename) = 0;
//    virtual void                delete_file(const char* filename) = 0;
};



std::string FileManager::trim_string(char* string)
{
    std::string str(string);
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}


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
