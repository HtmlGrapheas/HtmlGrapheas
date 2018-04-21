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

cmake_minimum_required(VERSION 3.2)

project(litehtml C)
set(gm_LIB_NAME "gumbo")

set(SOURCE_GUMBO
  ${GUMBO_SRC_DIR}/attribute.c
  ${GUMBO_SRC_DIR}/char_ref.c
  ${GUMBO_SRC_DIR}/error.c
  ${GUMBO_SRC_DIR}/parser.c
  ${GUMBO_SRC_DIR}/string_buffer.c
  ${GUMBO_SRC_DIR}/string_piece.c
  ${GUMBO_SRC_DIR}/tag.c
  ${GUMBO_SRC_DIR}/tokenizer.c
  ${GUMBO_SRC_DIR}/utf8.c
  ${GUMBO_SRC_DIR}/util.c
  ${GUMBO_SRC_DIR}/vector.c
)

add_library(${gm_LIB_NAME} ${SOURCE_GUMBO})
set_target_properties(${gm_LIB_NAME} PROPERTIES
  C_STANDARD 11
)
if(MSVC)
  # Export gumbo includes.
  target_include_directories(${gm_LIB_NAME} PRIVATE
    ${GUMBO_SRC_DIR}/visualc/include
  )
endif()
# Export gumbo includes.
target_include_directories(${gm_LIB_NAME} PUBLIC ${GUMBO_SRC_DIR})
