#pragma once

namespace LiME
{
	class Component
	{
	private:
		int entityID;
	public:
		Component(int id);
		virtual ~Component();
		//virtual void Update() = 0;
		int GetID() const;
	};
}