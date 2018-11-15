cmake_minimum_required(VERSION 3.10)
project(NLFB)

set(CMAKE_CXX_STANDARD 17)
include_directories(.)
include_directories(/usr/bin/include)
add_executable(NLFB
        main.cpp
        tools/test.cpp
        tools/test.h
        object/object.h
        object/client.cpp
        object/client.h
        object/ap.cpp
        object/ap.h
        tools/timer.cpp
        tools/timer.h
        process/process.h
        object/wifi.cpp
        object/wifi.h
        process/client_send.cpp
        process/client_send.h
        process/ap_receive_from_client.cpp
        process/ap_receive_from_client.h
        object/object.cpp process/ap_send_to_producer.cpp process/ap_send_to_producer.h object/producer.cpp object/producer.h process/ap_receive_from_producer.cpp process/ap_receive_from_producer.h process/ap_send_to_client.cpp process/ap_send_to_client.h process/client_receive.cpp process/client_receive.h object/multi_ap.cpp object/multi_ap.h process/add_client.cpp process/add_client.h)