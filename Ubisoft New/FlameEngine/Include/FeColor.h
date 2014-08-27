#pragma once
#include<d3dx9.h>

//FeColor Defintions used in Blending
enum FeColor
{
	FeColor_AliceBlue = 0xFFF0F8FF,

	FeColor_AntiqueWhite = 0xFFFAEBD7,

	FeColor_Aqua = 0xFF00FFFF,

	FeColor_Aquamarine = 0xFF7FFFD4,

	FeColor_Azure = 0xFFF0FFFF,

	FeColor_Beige = 0xFFF5F5DC,

	FeColor_Bisque = 0xFFFFE4C4,

	FeColor_Black = 0xFF000000,

	FeColor_BlanchedAlmond = 0xFFFFEBCD,

	FeColor_Blue = 0xFF0000FF,

	FeColor_BlueViolet = 0xFF8A2BE2,

	FeColor_Brown = 0xFFA52A2A,

	FeColor_BurlyWood = 0xFFDEB887,

	FeColor_CadetBlue = 0xFF5F9EA0,

	FeColor_Chartreuse = 0xFF7FFF00,

	FeColor_Chocolate = 0xFFD2691E,

	FeColor_Coral = 0xFFFF7F50,

	FeColor_CornflowerBlue = 0xFF6495ED,

	FeColor_Cornsilk = 0xFFFFF8DC,

	FeColor_Crimson = 0xFFDC143C,

	FeColor_Cyan = 0xFF00FFFF,

	FeColor_DarkBlue = 0xFF00008B,

	FeColor_DarkCyan = 0xFF008B8B,

	FeColor_DarkGoldenrod = 0xFFB8860B,

	FeColor_DarkGray = 0xFFA9A9A9,

	FeColor_DarkGreen = 0xFF006400,

	FeColor_DarkKhaki = 0xFFBDB76B,

	FeColor_DarkMagenta = 0xFF8B008B,

	FeColor_DarkOliveGreen = 0xFF556B2F,

	FeColor_DarkOrange = 0xFFFF8C00,

	FeColor_DarkOrchid = 0xFF9932CC,

	FeColor_DarkRed = 0xFF8B0000,

	FeColor_DarkSalmon = 0xFFE9967A,

	FeColor_DarkSeaGreen = 0xFF8FBC8F,

	FeColor_DarkSlateBlue = 0xFF483D8B,

	FeColor_DarkSlateGray = 0xFF2F4F4F,

	FeColor_DarkTurquoise = 0xFF00CED1,

	FeColor_DarkViolet = 0xFF9400D3,

	FeColor_DeepPink = 0xFFFF1493,

	FeColor_DeepSkyBlue = 0xFF00BFFF,

	FeColor_DimGray = 0xFF696969,

	FeColor_DodgerBlue = 0xFF1E90FF,

	FeColor_Firebrick = 0xFFB22222,

	FeColor_FloralWhite = 0xFFFFFAF0,

	FeColor_ForestGreen = 0xFF228B22,

	FeColor_Fuchsia = 0xFFFF00FF,

	FeColor_Gainsboro = 0xFFDCDCDC,

	FeColor_GhostWhite = 0xFFF8F8FF,

	FeColor_Gold = 0xFFFFD700,

	FeColor_Goldenrod = 0xFFDAA520,

	FeColor_Gray = 0xFF808080,

	FeColor_Green = 0xFF008000,

	FeColor_GreenYellow = 0xFFADFF2F,

	FeColor_Honeydew = 0xFFF0FFF0,

	FeColor_HotPink = 0xFFFF69B4,

	FeColor_IndianRed = 0xFFCD5C5C,

	FeColor_Indigo = 0xFF4B0082,

	FeColor_Ivory = 0xFFFFFFF0,

	FeColor_Khaki = 0xFFF0E68C,

	FeColor_Lavender = 0xFFE6E6FA,

	FeColor_LavenderBlush = 0xFFFFF0F5,

	FeColor_LawnGreen = 0xFF7CFC00,

	FeColor_LemonChiffon = 0xFFFFFACD,

	FeColor_LightBlue = 0xFFADD8E6,

	FeColor_LightCoral = 0xFFF08080,

	FeColor_LightCyan = 0xFFE0FFFF,

	FeColor_LightGoldenrodYellow = 0xFFFAFAD2,

	FeColor_LightGray = 0xFFD3D3D3,

	FeColor_LightGreen = 0xFF90EE90,

	FeColor_LightPink = 0xFFFFB6C1,

	FeColor_LightSalmon = 0xFFFFA07A,

	FeColor_LightSeaGreen = 0xFF20B2AA,

	FeColor_LightSkyBlue = 0xFF87CEFA,

	FeColor_LightSlateGray = 0xFF778899,

	FeColor_LightSteelBlue = 0xFFB0C4DE,

	FeColor_LightYellow = 0xFFFFFFE0,

	FeColor_Lime = 0xFF00FF00,

	FeColor_LimeGreen = 0xFF32CD32,

	FeColor_Linen = 0xFFFAF0E6,

	FeColor_Magenta = 0xFFFF00FF,

	FeColor_Maroon = 0xFF800000,

	FeColor_MediumAquamarine = 0xFF66CDAA,

	FeColor_MediumBlue = 0xFF0000CD,

	FeColor_MediumOrchid = 0xFFBA55D3,

	FeColor_MediumPurple = 0xFF9370DB,

	FeColor_MediumSeaGreen = 0xFF3CB371,

	FeColor_MediumSlateBlue = 0xFF7B68EE,

	FeColor_MediumSpringGreen = 0xFF00FA9A,

	FeColor_MediumTurquoise = 0xFF48D1CC,

	FeColor_MediumVioletRed = 0xFFC71585,

	FeColor_MidnightBlue = 0xFF191970,

	FeColor_MintCream = 0xFFF5FFFA,

	FeColor_MistyRose = 0xFFFFE4E1,

	FeColor_Moccasin = 0xFFFFE4B5,

	FeColor_NavajoWhite = 0xFFFFDEAD,

	FeColor_Navy = 0xFF000080,

	FeColor_OldLace = 0xFFFDF5E6,

	FeColor_Olive = 0xFF808000,

	FeColor_OliveDrab = 0xFF6B8E23,

	FeColor_Orange = 0xFFFFA500,

	FeColor_OrangeRed = 0xFFFF4500,

	FeColor_Orchid = 0xFFDA70D6,

	FeColor_PaleGoldenrod = 0xFFEEE8AA,

	FeColor_PaleGreen = 0xFF98FB98,

	FeColor_PaleTurquoise = 0xFFAFEEEE,

	FeColor_PaleVioletRed = 0xFFDB7093,

	FeColor_PapayaWhip = 0xFFFFEFD5,

	FeColor_PeachPuff = 0xFFFFDAB9,

	FeColor_Peru = 0xFFCD853F,

	FeColor_Pink = 0xFFFFC0CB,

	FeColor_Plum = 0xFFDDA0DD,

	FeColor_PowderBlue = 0xFFB0E0E6,

	FeColor_Purple = 0xFF800080,

	FeColor_Red = 0xFFFF0000,

	FeColor_RosyBrown = 0xFFBC8F8F,

	FeColor_RoyalBlue = 0xFF4169E1,

	FeColor_SaddleBrown = 0xFF8B4513,

	FeColor_Salmon = 0xFFFA8072,

	FeColor_SandyBrown = 0xFFF4A460,

	FeColor_SeaGreen = 0xFF2E8B57,

	FeColor_SeaShell = 0xFFFFF5EE,

	FeColor_Sienna = 0xFFA0522D,

	FeColor_Silver = 0xFFC0C0C0,

	FeColor_SkyBlue = 0xFF87CEEB,

	FeColor_SlateBlue = 0xFF6A5ACD,

	FeColor_SlateGray = 0xFF708090,

	FeColor_Snow = 0xFFFFFAFA,

	FeColor_SpringGreen = 0xFF00FF7F,

	FeColor_SteelBlue = 0xFF4682B4,

	FeColor_Tan = 0xFFD2B48C,

	FeColor_Teal = 0xFF008080,

	FeColor_Thistle = 0xFFD8BFD8,

	FeColor_Tomato = 0xFFFF6347,

	FeColor_Turquoise = 0xFF40E0D0,

	FeColor_Violet = 0xFFEE82EE,

	FeColor_Wheat = 0xFFF5DEB3,

	FeColor_White = 0xFFFFFFFF,

	FeColor_WhiteSmoke = 0xFFF5F5F5,

	FeColor_Yellow = 0xFFFFFF00,

	FeColor_YellowGreen = 0xFF9ACD32
};