//
// Created by nanotex426 on 26.09.17.
//

#ifndef TSDB_FILE_MANAGER_H
#define TSDB_FILE_MANAGER_H

#include <fstream>

class FileManager
{
protected:

    const char*                 filename;

    std::fstream                file_stream;

    std::string                 trim_string(char* str);

    virtual std::fstream        get_or_create_file(const char* filename) = 0;
//    virtual void                delete_file(const char* filename);
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


#endif //TSDB_FILE_MANAGER_H
