# Install script for directory: /Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/CMake

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/install")
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
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/Garfield/cmake/GarfieldTargets.cmake")
    file(DIFFERENT _cmake_export_file_changed FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/Garfield/cmake/GarfieldTargets.cmake"
         "/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/build/CMake/CMakeFiles/Export/e3c6bd7f06c54b40d25a270fb0f2c196/GarfieldTargets.cmake")
    if(_cmake_export_file_changed)
      file(GLOB _cmake_old_config_files "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/Garfield/cmake/GarfieldTargets-*.cmake")
      if(_cmake_old_config_files)
        string(REPLACE ";" ", " _cmake_old_config_files_text "${_cmake_old_config_files}")
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/share/Garfield/cmake/GarfieldTargets.cmake\" will be replaced.  Removing files [${_cmake_old_config_files_text}].")
        unset(_cmake_old_config_files_text)
        file(REMOVE ${_cmake_old_config_files})
      endif()
      unset(_cmake_old_config_files)
    endif()
    unset(_cmake_export_file_changed)
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/Garfield/cmake" TYPE FILE FILES "/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/build/CMake/CMakeFiles/Export/e3c6bd7f06c54b40d25a270fb0f2c196/GarfieldTargets.cmake")
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/Garfield/cmake" TYPE FILE FILES "/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/build/CMake/CMakeFiles/Export/e3c6bd7f06c54b40d25a270fb0f2c196/GarfieldTargets-release.cmake")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/Garfield/cmake" TYPE FILE FILES
    "/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/build/CMake/GarfieldConfig.cmake"
    "/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/build/CMake/GarfieldConfigVersion.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/Garfield" TYPE FILE FILES
    "/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/build/setupGarfield.sh"
    "/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/build/setupGarfield.csh"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3.12/site-packages/Garfield" TYPE DIRECTORY FILES "/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/garfieldpp/build/Garfield/")
endif()

