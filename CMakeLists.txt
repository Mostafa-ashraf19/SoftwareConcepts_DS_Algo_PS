cmake_minimum_required(VERSION 3.28.3)

project(DSA VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(STACK_DIR ${CMAKE_SOURCE_DIR}/Stack)
set(QUEUE_DIR ${CMAKE_SOURCE_DIR}/Queue)

set(Trees_DIR ${CMAKE_SOURCE_DIR}/Trees)
set(LinkedList_DIR ${CMAKE_SOURCE_DIR}/LinkedList)

# TODO: Can use loop here to build all file.
add_executable(stack_array ${STACK_DIR}/stack_array.cpp)
add_executable(stack_list ${STACK_DIR}/stack_linkedList.cpp)

add_executable(queue_array ${QUEUE_DIR}/queue_array.cpp)
add_executable(queue_list ${QUEUE_DIR}/queue_array.cpp)

set_target_properties(stack_array PROPERTIES 
# Directory where static libraries will be stored (if any).
ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Stack
# Directory where shared libraries will be stored (if any). {.DLL, .SO}
LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Stack
# Directory where executables will be stored.
RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Stack
)

set_target_properties(stack_list PROPERTIES 
# Directory where static libraries will be stored (if any).
ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Stack
# Directory where shared libraries will be stored (if any). {.DLL, .SO}
LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Stack
# Directory where executables will be stored.
RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Stack
)

set_target_properties(queue_array PROPERTIES 
# Directory where static libraries will be stored (if any).
ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Queue
# Directory where shared libraries will be stored (if any). {.DLL, .SO}
LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Queue
# Directory where executables will be stored.
RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Queue
)

set_target_properties(queue_list PROPERTIES 
# Directory where static libraries will be stored (if any).
ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Queue
# Directory where shared libraries will be stored (if any). {.DLL, .SO}
LIBRARY_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Queue
# Directory where executables will be stored.
RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Queue
)