#include "Component.h"
#include "Object.h"
#include "Root.h"
namespace toryengine
{
	std::shared_ptr<Root> Component::GetRoot()
	{
		return GetObject()->GetRoot();
	}
	std::shared_ptr<Resources> Component::GetResources()
	{
		return GetRoot()->GetResources();
	}
}