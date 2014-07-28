###############################################################################
# Find E57Ref
#
# This sets the following variables:
# E57REF_FOUND - True if E57Ref was found.
# E57REF_INCLUDE_DIRS - Directories containing the E57Ref include files.
# E57REF_LIBRARY_DIRS - Directories containing the E57Ref library.
# E57REF_LIBRARIES - E57Ref library files.

find_path(E57REF_INCLUDE_DIR e57 HINTS "/usr/include" "/usr/local/include" "$ENV{LIBE57_ROOT}/include" "$ENV{PROGRAMFILES}")

find_library(E57REF_LIBRARY_PATH E57RefImpl HINTS "/usr/lib" "/usr/local/lib" "$ENV{LIBE57_ROOT}/lib")
if (NOT MSVC)
	find_library(TIMECONV_LIBRARY_PATH time_conversion HINTS "/usr/lib" "/usr/local/lib" "$ENV{LIBE57_ROOT}/lib")
endif(NOT MSVC)

if(MSVC)
	if(EXISTS ${E57REF_LIBRARY_PATH})# AND EXISTS ${TIMECONV_LIBRARY_PATH})
		get_filename_component(E57REF_LIBRARY ${E57REF_LIBRARY_PATH} NAME)
		find_path(E57REF_LIBRARY_DIR ${E57REF_LIBRARY} HINTS "/usr/lib" "/usr/local/lib" "$ENV{LIBE57_ROOT}/lib")
	endif()
else(MSVC)
	if(EXISTS ${E57REF_LIBRARY_PATH} AND EXISTS ${TIMECONV_LIBRARY_PATH})
		get_filename_component(E57REF_LIBRARY ${E57REF_LIBRARY_PATH} NAME)
		get_filename_component(TIMECONV_LIBRARY ${TIMECONV_LIBRARY_PATH} NAME)
		find_path(E57REF_LIBRARY_DIR ${E57REF_LIBRARY} HINTS "/usr/lib" "/usr/local/lib" "$ENV{LIBE57_ROOT}/lib")
	endif()
endif(MSVC)

set(E57REF_INCLUDE_DIRS ${E57REF_INCLUDE_DIR} "${E57REF_INCLUDE_DIR}/time_conversion")
set(E57REF_LIBRARY_DIRS ${E57REF_LIBRARY_DIR})
if (MSVC)
	set(E57REF_LIBRARIES ${E57REF_LIBRARY})# ${TIMECONV_LIBRARY})
else(MSVC)
	set(E57REF_LIBRARIES ${E57REF_LIBRARY} ${TIMECONV_LIBRARY})
endif(MSVC)

include(FindPackageHandleStandardArgs)
if (MSVC)
	find_package_handle_standard_args(E57Ref DEFAULT_MSG E57REF_INCLUDE_DIR E57REF_LIBRARY E57REF_LIBRARY_DIR) #TIMECONV_LIBRARY)
else(MSVC)
	find_package_handle_standard_args(E57Ref DEFAULT_MSG E57REF_INCLUDE_DIR E57REF_LIBRARY E57REF_LIBRARY_DIR TIMECONV_LIBRARY)
endif(MSVC)

mark_as_advanced(E57REF_INCLUDE_DIR)
mark_as_advanced(E57REF_LIBRARY_DIR)
mark_as_advanced(E57REF_LIBRARY)
#mark_as_advanced(TIMECONV_LIBRARY)
mark_as_advanced(E57REF_LIBRARY_PATH)
#mark_as_advanced(TIMECONV_LIBRARY_PATH)
