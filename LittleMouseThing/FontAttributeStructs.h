#pragma once

#include <string>

namespace LM
{
	struct FontMetrics
	{
		int maxHeight;
		int maxAscent;
		int maxDescent;
		int lineSkip;
	};

	struct FaceAttributes
	{
		int numFaces;
		bool faceIsFixedWidth;
		std::string faceFamilyName;
		std::string faceStyleName;
	};

	struct GlyphMetrics
	{
		int minXOffset;
		int maxXOffset;
		int minYOffset;
		int maxYOffset;
		int advanceOffset;
	};
}