# ****************************************************************************
#  Project:  HtmlGrapheas
#  Purpose:  HTML text editor library
#  Author:   NikitaFeodonit, nfeodonit@yandex.com
# ****************************************************************************
#    Copyright (c) 2017-2018 NikitaFeodonit
#
#    This file is part of the HtmlGrapheas project.
#
#    This program is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published
#    by the Free Software Foundation, either version 3 of the License,
#    or (at your option) any later version.
#
#    This program is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#    See the GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with this program. If not, see <http://www.gnu.org/licenses/>.
# ****************************************************************************

cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(HtmlGrapheas CXX)
set(hg_LIB_NAME "htmlgrapheas")


#-----------------------------------------------------------------------
# Configure external libs directories.
#-----------------------------------------------------------------------

if(NOT EXTERNAL_BIN_DIR)
  set(EXTERNAL_BIN_DIR "${PROJECT_BINARY_DIR}/external/build")
endif()
if(NOT EXTERNAL_INSTALL_DIR)
  set(EXTERNAL_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}")
endif()


#-----------------------------------------------------------------------
# Configure to find_package.
#-----------------------------------------------------------------------

# Set CMake's search path for find_package(), find_program(), find_library(),
# find_file(), and find_path() commands.
list(APPEND CMAKE_PREFIX_PATH "${EXTERNAL_INSTALL_DIR}")

if(ANDROID)
  list(APPEND CMAKE_FIND_ROOT_PATH "${EXTERNAL_INSTALL_DIR}")
endif()


#-----------------------------------------------------------------------
# Set path to LibCMaker root.
#-----------------------------------------------------------------------

if(NOT LIBCMAKER_SRC_DIR)
  message(FATAL_ERROR
    "Please set LIBCMAKER_SRC_DIR with path to LibCMaker root")
endif()

list(APPEND CMAKE_MODULE_PATH
  "${PROJECT_SOURCE_DIR}/cmake"
  "${LIBCMAKER_SRC_DIR}/cmake/modules"
)


#-----------------------------------------------------------------------
# Set standard CMake vars for LibCMaker libs.
#-----------------------------------------------------------------------

#set(BUILD_SHARED_LIBS ON)

#set(SKIP_INSTALL_HEADERS ON)
#set(SKIP_INSTALL_LIBRARIES ON)
#set(SKIP_INSTALL_ALL ON)


#-----------------------------------------------------------------------
# Set common useful vars for LibCMaker libs.
#-----------------------------------------------------------------------

#set(cmr_PRINT_DEBUG ON)


#-----------------------------------------------------------------------
# LiteHtml
#-----------------------------------------------------------------------

if(WIN32 OR WINCE)
  set(LITEHTML_UTF8 "LITEHTML_UTF8")
  add_definitions(-D${LITEHTML_UTF8})
endif()

set(LITEHTML_CMAKE_DIR "${PROJECT_SOURCE_DIR}/cmake/litehtml")
set(LITEHTML_SRC_DIR "${PROJECT_SOURCE_DIR}/external/litehtml")
set(LITEHTML_BUILD_DIR "${EXTERNAL_BIN_DIR}/build_litehtml")
set(LITEHTML_EXPORT_FILE "${LITEHTML_BUILD_DIR}/export-litehtml.cmake")

if(NOT EXISTS ${LITEHTML_EXPORT_FILE})
  cmr_print_message("liteheml is not built, build it.")

  # TODO: replace LITEHTML_CMAKE_DIR with LITEHTML_SRC_DIR.
  #add_subdirectory(${LITEHTML_SRC_DIR} ${LITEHTML_BUILD_DIR})
  add_subdirectory(${LITEHTML_CMAKE_DIR} ${LITEHTML_BUILD_DIR})
  
  export(
    TARGETS litehtml
    FILE ${LITEHTML_EXPORT_FILE}
    EXPORT_LINK_INTERFACE_LIBRARIES
  )

else()
  cmr_print_message("liteheml is built, skip its building.")
  include(${LITEHTML_EXPORT_FILE})
endif()


#-----------------------------------------------------------------------
# find_package
#-----------------------------------------------------------------------


#-----------------------------------------------------------------------
# Link to the dependences.
#-----------------------------------------------------------------------

set(hg_HEADERS
)

set(hg_SOURCES
  ${PROJECT_SOURCE_DIR}/src/hgraph/dummy.cpp
)

# HtmlGrapheas
add_library(${hg_LIB_NAME} ${hg_SOURCES} ${hg_HEADERS})
set_target_properties(${hg_LIB_NAME} PROPERTIES
  CXX_STANDARD 11
  C_STANDARD 11
)
if(LITEHTML_UTF8)
  target_compile_definitions(${hg_LIB_NAME} PUBLIC -D${LITEHTML_UTF8})
endif()
# Export HtmlGrapheas includes.
target_include_directories(${hg_LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

# LiteHtml
# TODO: Change PUBLIC to PRIVATE for litehtml includes.
target_link_libraries(${hg_LIB_NAME} PUBLIC litehtml)
