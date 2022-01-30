cmake_minimum_required(VERSION 3.11)

project(zia)

add_definitions("-g3")
add_definitions("-fPIC")
# add_definitions("-std=c++2a") si jamais, on a des problemes avec la compile linux
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
ELSE()
    message(FATAL_ERROR "No conanbuildinfo.cmake file found")
ENDIF()

#########   SRCS   #########

set(SRCS_MAIN
    main.cpp
    )

### SERVER ###

set(SRCS_SERVER
    Server/src/ConnexionHTTP.cpp
    Server/src/ClientHTTP.cpp
    Server/src/Server.cpp
    Server/src/ConnexionHTTPS.cpp
    Server/src/ClientHTTPS.cpp
    Server/src/RequestHandler.cpp
    Server/src/RequestList.cpp
    Server/src/RequestParser.cpp
    Config/src/ConfigHandler.cpp
    Config/src/Config.cpp
    Config/src/Module.cpp
    Server/modules/PhpModule/PhpModule.cpp
    )

set(HEADERS_SERVER
    Server/include/ConnexionHTTP.hpp
    Server/include/ClientHTTP.hpp
    Server/include/Server.hpp
    Server/include/ConnexionHTTPS.hpp
    Server/include/ClientHTTPS.hpp
    Server/include/RequestHandler.hpp
    Server/include/RequestList.hpp
    Server/include/RequestParser.hpp
    Server/include/Request.hpp
    Server/include/Response.hpp
    Config/include/ConfigHandler.hpp
    Config/include/Config.hpp
    Config/include/Module.hpp
    Server/interfaces/IModule.hpp
    Server/interfaces/IClient.hpp
    Server/interfaces/IConnexion.hpp
    Server/modules/PhpModule/PhpModule.hpp
    )


### UNITS TESTS ###

set(SRCS_UNIT_TEST
    Test_Unitaire/testUnitaire.cpp
    Test_Unitaire/Config.cpp
    Test_Unitaire/Core.cpp
    Test_Unitaire/Php.cpp
    Test_Unitaire/Security.cpp
    )

### THREADS ###

set(SRCS_THREAD
    Server/ThreadPool/src/ThreadPool.cpp
    Server/ThreadPool/src/CondVar.cpp
    Server/ThreadPool/src/Mutex.cpp
    Server/ThreadPool/src/Threads.cpp
    )

set(HEADERS_THREAD
    Server/ThreadPool/include/CondVar.hpp
    Server/ThreadPool/include/Mutex.hpp
    Server/ThreadPool/include/Threads.hpp
    Server/ThreadPool/include/ThreadPool.hpp
    Server/ThreadPool/interfaces/IMutex.hpp
    Server/ThreadPool/interfaces/ICondVar.hpp
    )

### PHP MODULE ###

set(PHP_MODULE
    Server/modules/PhpModule/PhpModule.cpp
    Server/modules/PhpModule/PhpModule.hpp
    )

#add_library(php SHARED ${PHP_MODULE})

### HTTP MODULE ###

set(HTTP_MODULE
    Server/src/Server.cpp
    Server/include/Server.hpp
    Server/src/ConnexionHTTP.cpp
    Server/include/ConnexionHTTP.hpp
    Server/src/ClientHTTP.cpp
    Server/include/ClientHTTP.hpp
    )

#add_library(http SHARED ${HTTP_MODULE})

### HTTPS MODULE ###

set(HTTPS_MODULE
    Server/src/Server.cpp
    Server/include/Server.hpp
    Server/src/ConnexionHTTPS.cpp
    Server/include/ConnexionHTTPS.hpp
    Server/src/ClientHTTPS.cpp
    Server/include/ClientHTTPS.hpp
    )

#add_library(https SHARED ${HTTPS_MODULE})


#########   EXECUTABLES   #########

add_executable(zia_server ${SRCS_MAIN} ${SRCS_SERVER} ${SRCS_THREAD} ${HEADERS_SERVER} ${HEADERS_THREAD} )
#add_executable(zia_server_test_unitaire ${SRCS_UNIT_TEST} ${SRCS_SERVER} ${SRCS_THREAD} ${HEADERS_SERVER} ${HEADERS_THREAD} )

conan_basic_setup(TARGETS)

#target_link_libraries(zia_server PRIVATE php)
target_link_libraries(zia_server PRIVATE CONAN_PKG::nlohmann_json)
target_link_libraries(zia_server PRIVATE CONAN_PKG::boost)
target_link_libraries(zia_server PRIVATE CONAN_PKG::OpenSSL)
#target_link_libraries(zia_server_test_unitaire PRIVATE CONAN_PKG::nlohmann_json)
#target_link_libraries(zia_server_test_unitaire PRIVATE CONAN_PKG::boost)
#target_link_libraries(zia_server_test_unitaire PRIVATE CONAN_PKG::OpenSSL)

include_directories(${CMAKE_INCLUDE_PATH})

execute_process(COMMAND openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout localhost.pem -out localhost.pem
                COMMAND chmod 777 localhost.pem)

execute_process(COMMAND openssl dhparam -out dhparam.pem 2048
                COMMAND chmod 777 dhparam.pem)