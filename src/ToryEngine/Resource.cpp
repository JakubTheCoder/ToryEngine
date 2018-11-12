#include "Resource.h"

namespace toryengine
{
	std::shared_ptr<Root> Resource::GetRoot()
	{
		return root.lock();
	}

}