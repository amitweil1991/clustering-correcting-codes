cmake_minimum_required(VERSION 3.10)
project(clustering_correcting_codes_project)

set(CMAKE_CXX_STANDARD 11)

add_executable(clustering_correcting_codes_project main.cpp strand.h encoding_algorithim.h encoded_strand.h)