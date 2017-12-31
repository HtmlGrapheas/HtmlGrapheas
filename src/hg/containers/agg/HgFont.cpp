#include "HgFont.h"

#include <cstring>

namespace hg
{
HgFont::HgFont()
{
  mFcConfig = FcInitLoadConfigAndFonts();
}

HgFont::~HgFont()
{
  FcConfigDestroy(mFcConfig);
}

std::string HgFont::getFontFilePath(const std::string& name,
    int pixelSize,
    int weight,
    litehtml::font_style fontStyle,
    uint_least8_t* result)
{
  std::string ret = "";

  const FcChar8* fcFamily = reinterpret_cast<const FcChar8*>(name.c_str());
  int fcSlant = fontStyleToFcSlant(fontStyle);
  int fcWeight = weightToFcWeight(weight);

  FcPattern* pat = FcPatternCreate();
  FcPatternAddString(pat, FC_FAMILY, fcFamily);
  FcPatternAddInteger(pat, FC_SLANT, fcSlant);
  FcPatternAddInteger(pat, FC_PIXEL_SIZE, pixelSize);
  FcPatternAddInteger(pat, FC_WEIGHT, fcWeight);

  FcConfigSubstitute(mFcConfig, pat, FcMatchPattern);
  FcDefaultSubstitute(pat);

  // Find the font.
  FcResult fcResult;
  FcPattern* fontPat = FcFontMatch(mFcConfig, pat, &fcResult);
  if(fontPat) {
    if(FcResultMatch == fcResult) {
      FcChar8* file = nullptr;
      if(FcPatternGetString(fontPat, FC_FILE, 0, &file) == FcResultMatch) {
        // Found the font file, this might be a fallback font.
        ret = reinterpret_cast<char*>(file);

        if(result) {
          FcChar8* retFamily = nullptr;
          int retSlant = -1;
          int retPixelSize = -1;
          int retWeight = -1;
          *result = FontMatches::allMatched;

          if(FcPatternGetString(fontPat, FC_FAMILY, 0, &retFamily)
                  == FcResultMatch
              && 0 != strcmp(reinterpret_cast<const char*>(retFamily),
                          reinterpret_cast<const char*>(fcFamily))) {
            *result |= FontMatches::notMatchedFaceName;
          }
          if(FcPatternGetInteger(fontPat, FC_SLANT, 0, &retSlant)
                  == FcResultMatch
              && retSlant != fcSlant) {
            *result |= FontMatches::notMatchedFontStyle;
          }
          if(FcPatternGetInteger(fontPat, FC_PIXEL_SIZE, 0, &retPixelSize)
                  == FcResultMatch
              && retPixelSize != pixelSize) {
            *result |= FontMatches::notMatchedPixelSize;
          }
          if(FcPatternGetInteger(fontPat, FC_WEIGHT, 0, &retWeight)
                  == FcResultMatch
              && retWeight != fcWeight) {
            *result |= FontMatches::notMatchedWeight;
          }
        }
      }
    }
    FcPatternDestroy(fontPat);
  }
  FcPatternDestroy(pat);

  return ret;
}

}  // namespace hg
