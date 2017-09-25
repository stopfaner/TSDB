//
// Created by nanotex426 on 25.09.17.
//

#ifndef TSDB_ROW_H
#define TSDB_ROW_H


#include <boost/uuid/uuid.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include "const.h"
#include "sha256/sha256.h"
#include <string>
#include <iostream>

class Row
{

public:
    Row();

    void add_user(std::string username, std::string password);

private:

    // UUID4 of user
    boost::uuids::uuid user_uuid;

    std::string username;

    std::string password_hash;

    std::string get_password_hash(std::string password);

};

Row::Row():
    user_uuid(boost::uuids::basic_random_generator<boost::mt19937>()())
{

}

void Row::add_user(std::string username, std::string password)
{
    std::cout << username << std::endl << this->get_password_hash(password) << std::endl;
}

std::string Row::get_password_hash(std::string password)
{
    return sha256(password);
}

#endif //TSDB_ROW_H
