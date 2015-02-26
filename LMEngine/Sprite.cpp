#include "Sprite.h"

namespace LiME
{
	Sprite::Sprite(std::shared_ptr<LM::SDLTexture> texture) : texture(texture) {}

	Sprite::~Sprite() {}

	LM::Point2 Sprite::GetPosition()
	{
		return position;
	}
}
