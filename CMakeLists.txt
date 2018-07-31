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

cmake_minimum_required(VERSION 3.3)

project(HtmlGrapheas CXX)
set(lib_NAME "hgraph")

include(GNUInstallDirs)


#-----------------------------------------------------------------------
# Configure external libs directories
#-----------------------------------------------------------------------

set(EXTERNAL_SRC_DIR "${CMAKE_CURRENT_LIST_DIR}/external")
if(NOT EXTERNAL_BIN_DIR)
  set(EXTERNAL_BIN_DIR "${PROJECT_BINARY_DIR}/external/build")
endif()
if(NOT EXTERNAL_INSTALL_DIR)
  set(EXTERNAL_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}")
  set(CMAKE_INSTALL_PREFIX "${EXTERNAL_INSTALL_DIR}")
endif()


#-----------------------------------------------------------------------
# Configure to find_package()
#-----------------------------------------------------------------------

# Set CMake's search path for find_*() commands.
list(APPEND CMAKE_PREFIX_PATH "${EXTERNAL_INSTALL_DIR}")

if(ANDROID)
  list(APPEND CMAKE_FIND_ROOT_PATH "${EXTERNAL_INSTALL_DIR}")
endif()


#-----------------------------------------------------------------------
# Set path to LibCMaker root
#-----------------------------------------------------------------------

if(NOT LIBCMAKER_SRC_DIR)
  message(FATAL_ERROR
    "Please set LIBCMAKER_SRC_DIR with path to LibCMaker root.")
endif()

list(APPEND CMAKE_MODULE_PATH
#  "${CMAKE_CURRENT_LIST_DIR}/cmake"
  "${LIBCMAKER_SRC_DIR}/cmake/modules"
)


#-----------------------------------------------------------------------
# Set vars to HtmlGrapheas
#-----------------------------------------------------------------------

# Standard CMake vars.
#set(BUILD_SHARED_LIBS ON)

# Library specific vars.


#-----------------------------------------------------------------------
# LiteHtml
#-----------------------------------------------------------------------

if(WIN32 OR WINCE)
  set(LITEHTML_UTF8 "LITEHTML_UTF8")
  add_definitions(-D${LITEHTML_UTF8})
endif()

set(LITEHTML_SRC_DIR      "${EXTERNAL_SRC_DIR}/litehtml")
set(LITEHTML_BUILD_DIR    "${EXTERNAL_BIN_DIR}/build_litehtml")
set(LITEHTML_EXPORT_FILE  "${LITEHTML_BUILD_DIR}/export-litehtml.cmake")

if(NOT EXISTS ${LITEHTML_EXPORT_FILE})
  cmr_print_message("litehtml is not built, build it.")

  add_subdirectory(${LITEHTML_SRC_DIR} ${LITEHTML_BUILD_DIR})
  
  export(
    TARGETS gumbo litehtml
    FILE ${LITEHTML_EXPORT_FILE}
    EXPORT_LINK_INTERFACE_LIBRARIES
  )

else()
  cmr_print_message("litehtml is built, skip its building.")
  include(${LITEHTML_EXPORT_FILE})
endif()


#-----------------------------------------------------------------------
# find_package()
#-----------------------------------------------------------------------


#-----------------------------------------------------------------------
# HtmlGrapheas
#-----------------------------------------------------------------------

set(private_src_DIR "${CMAKE_CURRENT_LIST_DIR}/src")
set(interface_src_DIR "${CMAKE_INSTALL_INCLUDEDIR}")
set(build_src_DIR
  "$<BUILD_INTERFACE:${private_src_DIR}>"
)
set(install_src_DIR
  "$<INSTALL_INTERFACE:${interface_src_DIR}>"
)
set(public_src_DIR "${build_src_DIR}${install_src_DIR}")

add_library(${lib_NAME} "")
set_target_properties(${lib_NAME} PROPERTIES
  CXX_STANDARD 11
  C_STANDARD 11
)
if(LITEHTML_UTF8)
  target_compile_definitions(${lib_NAME} PUBLIC -D${LITEHTML_UTF8})
endif()
# Export HtmlGrapheas include dirs.
target_include_directories(${lib_NAME} PUBLIC ${public_src_DIR})

target_sources(${lib_NAME}
  PRIVATE
    # TODO: remove it from disk.
    ${private_src_DIR}/hgraph/stub.cpp

  PUBLIC
    # TODO: place public headers here.
)


#-----------------------------------------------------------------------
# Link to the libraries
#-----------------------------------------------------------------------

# LiteHtml
target_link_libraries(${lib_NAME} PUBLIC litehtml)
