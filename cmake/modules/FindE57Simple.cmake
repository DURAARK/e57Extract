###############################################################################
# Find E57Simple
#
# This sets the following variables:
# E57SIMPLE_FOUND - True if E57Simple was found.
# E57SIMPLE_INCLUDE_DIRS - Directories containing the E57Simple include files.
# E57SIMPLE_LIBRARY_DIRS - Directories containing the E57Simple library.
# E57SIMPLE_LIBRARIES - E57Simple library files.

find_path(E57SIMPLE_INCLUDE_DIR e57
    HINTS "/usr/include" "/usr/local/include" "$ENV{PROGRAMFILES}")

find_library(E57SIMPLE_LIBRARY_PATH E57SimpleImpl HINTS "/usr/lib" "/usr/local/lib")

if(EXISTS ${E57SIMPLE_LIBRARY_PATH})
get_filename_component(E57SIMPLE_LIBRARY ${E57SIMPLE_LIBRARY_PATH} NAME)
find_path(E57SIMPLE_LIBRARY_DIR ${E57SIMPLE_LIBRARY} HINTS "/usr/lib" "/usr/local/lib")
endif()

set(E57SIMPLE_INCLUDE_DIRS ${E57SIMPLE_INCLUDE_DIR})
set(E57SIMPLE_LIBRARY_DIRS ${E57SIMPLE_LIBRARY_DIR})
set(E57SIMPLE_LIBRARIES ${E57SIMPLE_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(E57Simple DEFAULT_MSG E57SIMPLE_INCLUDE_DIR E57SIMPLE_LIBRARY E57SIMPLE_LIBRARY_DIR)

mark_as_advanced(E57SIMPLE_INCLUDE_DIR)
mark_as_advanced(E57SIMPLE_LIBRARY_DIR)
mark_as_advanced(E57SIMPLE_LIBRARY)
mark_as_advanced(E57SIMPLE_LIBRARY_PATH)
