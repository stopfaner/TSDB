//
// Created by nanotex426 on 25.09.17.
//

#ifndef TSDB_CREDENTIAL_MANAGER_H
#define TSDB_CREDENTIAL_MANAGER_H

#include <cstdio>

class CredentialManager
{
public:
    CredentialManager();
private:

    FILE* credential_storage_file;



};

CredentialManager::CredentialManager():
        credential_storage_file(fopen("cred.dat", "w"))
{

}

#endif //TSDB_CREDENTIAL_MANAGER_H
