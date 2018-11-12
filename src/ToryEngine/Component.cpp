#include "Component.h"
#include "Object.h"
namespace toryengine
{
	std::shared_ptr<Root> Component::GetRoot()
	{
		return GetObject()->GetRoot();
	}

}