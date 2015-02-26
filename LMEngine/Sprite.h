#pragma once
#include <memory>
#include "SDLTexture.h"

namespace LiME
{
	class Sprite
	{
	private:
		LM::Point2 position;
		std::shared_ptr<LM::SDLTexture> texture;
	public:
		LM::Point2 GetPosition();
		Sprite(std::shared_ptr<LM::SDLTexture> texture);
		~Sprite();
		void Draw(LM::Point2 position);
	};


}
