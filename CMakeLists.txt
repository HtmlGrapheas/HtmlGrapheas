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

cmake_minimum_required(VERSION 3.8)
# C++17 compiler:
#   GCC 8
#   Clang 8 (Android NDK r19)
#   Apple Clang 11.0.0, Xcode 11.0
#   MSVC 19.15, VS 2017 15.8
# See: https://en.cppreference.com/w/cpp/compiler_support


project(HtmlGrapheas CXX)
set(lib_NAME "hgraph")

include(GNUInstallDirs)


#-----------------------------------------------------------------------
# Set vars to HtmlGrapheas
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
  CXX_STANDARD 17
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
