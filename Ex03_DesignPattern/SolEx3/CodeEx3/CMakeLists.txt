cmake_minimum_required(VERSION 3.13.1)
project(solex3)
add_executable(patternex main.cpp 
                         Application/buttonmanager.cpp 
                         Application/factory.cpp 
                         Board/button.cpp                              
              )
