#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Garfield::magboltz" for configuration "Release"
set_property(TARGET Garfield::magboltz APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Garfield::magboltz PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libmagboltz.11.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libmagboltz.11.dylib"
  )

list(APPEND _cmake_import_check_targets Garfield::magboltz )
list(APPEND _cmake_import_check_files_for_Garfield::magboltz "${_IMPORT_PREFIX}/lib/libmagboltz.11.dylib" )

# Import target "Garfield::degrade" for configuration "Release"
set_property(TARGET Garfield::degrade APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Garfield::degrade PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libdegrade.3.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libdegrade.3.dylib"
  )

list(APPEND _cmake_import_check_targets Garfield::degrade )
list(APPEND _cmake_import_check_files_for_Garfield::degrade "${_IMPORT_PREFIX}/lib/libdegrade.3.dylib" )

# Import target "Garfield::Garfield" for configuration "Release"
set_property(TARGET Garfield::Garfield APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Garfield::Garfield PROPERTIES
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libGarfield.0.3.0.dylib"
  IMPORTED_SONAME_RELEASE "@rpath/libGarfield.0.3.0.dylib"
  )

list(APPEND _cmake_import_check_targets Garfield::Garfield )
list(APPEND _cmake_import_check_files_for_Garfield::Garfield "${_IMPORT_PREFIX}/lib/libGarfield.0.3.0.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
