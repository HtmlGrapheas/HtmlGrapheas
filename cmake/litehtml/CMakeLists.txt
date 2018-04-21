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

project(litehtml CXX)
set(lh_LIB_NAME "litehtml")

set(SOURCE_LITEHTML
  ${LITEHTML_SRC_DIR}/src/background.cpp
  ${LITEHTML_SRC_DIR}/src/box.cpp
  ${LITEHTML_SRC_DIR}/src/context.cpp
  ${LITEHTML_SRC_DIR}/src/css_length.cpp
  ${LITEHTML_SRC_DIR}/src/css_selector.cpp
  ${LITEHTML_SRC_DIR}/src/document.cpp
  ${LITEHTML_SRC_DIR}/src/el_anchor.cpp
  ${LITEHTML_SRC_DIR}/src/el_base.cpp
  ${LITEHTML_SRC_DIR}/src/el_before_after.cpp
  ${LITEHTML_SRC_DIR}/src/el_body.cpp
  ${LITEHTML_SRC_DIR}/src/el_break.cpp
  ${LITEHTML_SRC_DIR}/src/el_cdata.cpp
  ${LITEHTML_SRC_DIR}/src/el_comment.cpp
  ${LITEHTML_SRC_DIR}/src/el_div.cpp
  ${LITEHTML_SRC_DIR}/src/element.cpp
  ${LITEHTML_SRC_DIR}/src/el_font.cpp
  ${LITEHTML_SRC_DIR}/src/el_image.cpp
  ${LITEHTML_SRC_DIR}/src/el_link.cpp
  ${LITEHTML_SRC_DIR}/src/el_para.cpp
  ${LITEHTML_SRC_DIR}/src/el_script.cpp
  ${LITEHTML_SRC_DIR}/src/el_space.cpp
  ${LITEHTML_SRC_DIR}/src/el_style.cpp
  ${LITEHTML_SRC_DIR}/src/el_table.cpp
  ${LITEHTML_SRC_DIR}/src/el_td.cpp
  ${LITEHTML_SRC_DIR}/src/el_text.cpp
  ${LITEHTML_SRC_DIR}/src/el_title.cpp
  ${LITEHTML_SRC_DIR}/src/el_tr.cpp
  ${LITEHTML_SRC_DIR}/src/html.cpp
  ${LITEHTML_SRC_DIR}/src/html_tag.cpp
  ${LITEHTML_SRC_DIR}/src/iterators.cpp
  ${LITEHTML_SRC_DIR}/src/media_query.cpp
  ${LITEHTML_SRC_DIR}/src/style.cpp
  ${LITEHTML_SRC_DIR}/src/stylesheet.cpp
  ${LITEHTML_SRC_DIR}/src/table.cpp
  ${LITEHTML_SRC_DIR}/src/utf8_strings.cpp
  ${LITEHTML_SRC_DIR}/src/web_color.cpp
)

add_library(${lh_LIB_NAME} ${SOURCE_LITEHTML})
set_target_properties(${lh_LIB_NAME} PROPERTIES
  CXX_STANDARD 11
  C_STANDARD 11
)
# Export litehtml includes.
target_include_directories(${lh_LIB_NAME} PUBLIC ${LITEHTML_SRC_DIR}/src)
target_include_directories(${lh_LIB_NAME} PUBLIC ${LITEHTML_SRC_DIR}/include)

# Gumbo
target_link_libraries(${lh_LIB_NAME} PUBLIC gumbo)
