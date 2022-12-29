#include "version.h"
#include "config.h"



namespace ex{
    int getVersion(){
        return (PROJECT_VERSION_PATCH);
    }
    std::string getVersionS(){
        return std::to_string(PROJECT_VERSION_PATCH);
    }
}