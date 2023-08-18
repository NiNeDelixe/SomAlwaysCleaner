# Install script for directory: C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/blds/zlib/src/v1.2.13-f30d2a168d.clean

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/pkgs/zlib_x86-windows")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "OFF")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/pkgs/zlib_x86-windows/lib/zlib.lib")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/pkgs/zlib_x86-windows/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/blds/zlib/x86-windows-rel/zlib.lib")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/pkgs/zlib_x86-windows/bin/zlib1.dll")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/pkgs/zlib_x86-windows/bin" TYPE SHARED_LIBRARY FILES "C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/blds/zlib/x86-windows-rel/zlib1.dll")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/pkgs/zlib_x86-windows/include/zconf.h;C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/pkgs/zlib_x86-windows/include/zlib.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/pkgs/zlib_x86-windows/include" TYPE FILE FILES
    "C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/blds/zlib/x86-windows-rel/zconf.h"
    "C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/blds/zlib/src/v1.2.13-f30d2a168d.clean/zlib.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/alkor/source/repos/SomAlwaysCleaner/SomAlwaysCleaner/vcpkg_installed/vcpkg/blds/zlib/x86-windows-rel/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
