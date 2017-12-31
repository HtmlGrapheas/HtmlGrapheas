/*****************************************************************************
 * Project:  HtmlGrapheas
 * Purpose:  HTML text editor library
 * Author:   NikitaFeodonit, nfeodonit@yandex.com
 *****************************************************************************
 *   Copyright (c) 2017-2018 NikitaFeodonit
 *
 *    This file is part of the HtmlGrapheas project.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published
 *    by the Free Software Foundation, either version 3 of the License,
 *    or (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *    See the GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program. If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#include "AggContainer.h"

namespace hg
{
AggContainer::AggContainer(void)
{
}

AggContainer::~AggContainer(void)
{
}

litehtml::uint_ptr AggContainer::create_font(const litehtml::tchar_t* faceName,
    int size,
    int weight,
    litehtml::font_style italic,
    unsigned int decoration,
    litehtml::font_metrics* fm)
{
  return nullptr;
}

void AggContainer::delete_font(litehtml::uint_ptr hFont)
{
}

int AggContainer::text_width(
    const litehtml::tchar_t* text, litehtml::uint_ptr hFont)
{
  return 0;
}

void AggContainer::draw_text(litehtml::uint_ptr hdc,
    const litehtml::tchar_t* text,
    litehtml::uint_ptr hFont,
    litehtml::web_color color,
    const litehtml::position& pos)
{
}

int AggContainer::pt_to_px(int pt)
{
  return 0;
}

int AggContainer::get_default_font_size() const
{
  return 0;
}

const litehtml::tchar_t* AggContainer::get_default_font_name() const
{
  return "Times New Roman";
}

void AggContainer::draw_list_marker(
    litehtml::uint_ptr hdc, const litehtml::list_marker& marker)
{
}

void AggContainer::load_image(const litehtml::tchar_t* src,
    const litehtml::tchar_t* baseurl,
    bool redraw_on_ready)
{
}

void AggContainer::get_image_size(const litehtml::tchar_t* src,
    const litehtml::tchar_t* baseurl,
    litehtml::size& sz)
{
}

void AggContainer::draw_background(
    litehtml::uint_ptr hdc, const litehtml::background_paint& bg)
{
}

void AggContainer::draw_borders(litehtml::uint_ptr hdc,
    const litehtml::borders& borders,
    const litehtml::position& draw_pos,
    bool root)
{
}

void AggContainer::set_caption(const litehtml::tchar_t* caption)
{
}

void AggContainer::set_base_url(const litehtml::tchar_t* base_url)
{
}

void AggContainer::link(const std::shared_ptr<litehtml::document>& ptr,
    const litehtml::element::ptr& el)
{
}

void AggContainer::on_anchor_click(
    const litehtml::tchar_t* url, const litehtml::element::ptr& el)
{
}

void AggContainer::set_cursor(const litehtml::tchar_t* cursor)
{
}

void AggContainer::transform_text(
    litehtml::tstring& text, litehtml::text_transform tt)
{
}

void AggContainer::import_css(litehtml::tstring& text,
    const litehtml::tstring& url,
    litehtml::tstring& baseurl)
{
}

void AggContainer::set_clip(const litehtml::position& pos,
    const litehtml::border_radiuses& bdr_radius,
    bool valid_x,
    bool valid_y)
{
}

void AggContainer::del_clip()
{
}

void AggContainer::get_client_rect(litehtml::position& client) const
{
}

std::shared_ptr<litehtml::element> AggContainer::create_element(
    const litehtml::tchar_t* tag_name,
    const litehtml::string_map& attributes,
    const std::shared_ptr<litehtml::document>& doc)
{
  return nullptr;
}

void AggContainer::get_media_features(litehtml::media_features& media) const
{
}

void AggContainer::get_language(
    litehtml::tstring& language, litehtml::tstring& culture) const
{
  language = _t("en");
  culture = _t("");
}

//virtual litehtml::tstring AggContainer::resolve_color(
//    const litehtml::tstring& color) const
//{
//  return litehtml::tstring();
//}

}  // namespace hg
