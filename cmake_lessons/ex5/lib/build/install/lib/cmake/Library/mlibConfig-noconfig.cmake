#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Library::mlib" for configuration ""
set_property(TARGET Library::mlib APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(Library::mlib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_NOCONFIG "CXX"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libmlib.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS Library::mlib )
list(APPEND _IMPORT_CHECK_FILES_FOR_Library::mlib "${_IMPORT_PREFIX}/lib/libmlib.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
