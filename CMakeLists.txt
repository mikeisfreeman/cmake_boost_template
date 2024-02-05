cmake_minimum_required(VERSION 3.0.0)
project(CmakeBoostTemplate VERSION 0.1.0 LANGUAGES C CXX)

#include(CTest)
include(FindBoost)
find_package(Boost 1.74.0 REQUIRED program_options)


enable_testing()

# Function to prepend the subdirectory to source files in subdirectories
# I don't remmeber where I snagged this from, but it's not my original work.
function(PREPEND var )
   set(listVar "")
   foreach(f ${${var}})
       list(APPEND listVar "${CMAKE_CURRENT_SOURCE_DIR}/${f}")
   endforeach(f)
   set(${var} "${listVar}" PARENT_SCOPE)
endfunction(PREPEND)



add_subdirectory(src)
add_subdirectory(include)



add_executable(CmakeBoostTemplate ${CmakeBoostTemplate_CPP} ${CmakeBoostTemplate_H})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)