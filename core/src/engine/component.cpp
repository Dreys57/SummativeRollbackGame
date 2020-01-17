#include <engine/component.h>

namespace neko
{
static const std::set<NekoComponentType> componentTypeSet =
{
		NekoComponentType::POSITION2D,
		NekoComponentType::SCALE2D,
		NekoComponentType::ROTATION2D,
		NekoComponentType::POSITION3D,
		NekoComponentType::SCALE3D,
		NekoComponentType::ANGLE3D,
		NekoComponentType::SPRITE2D,
		NekoComponentType::SPINE_ANIMATION,
		NekoComponentType::SPINE_FOLLOW_BONE,
		NekoComponentType::BODY2D,
		NekoComponentType::BOX_COLLIDER2D,
		NekoComponentType::CONVEX_SHAPE2D
};
const std::set<NekoComponentType>& GetComponentTypeSet()
{
	return componentTypeSet;
}
}