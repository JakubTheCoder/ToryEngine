#include "Object.h"

namespace toryengine
{
	std::shared_ptr<Root> Object::GetRoot()
	{
		return root.lock();	//creates a shared ptr to Root (to go up hierarchy)
	}
	
	void Object::Update()
	{
		//Go Through all the components on a object and update them. 
		for (std::vector<std::shared_ptr<Component>>::iterator i = components.begin();i != components.end(); i++)
		{
			if (!(*i)->began)
			{
				(*i)->OnBegin();
				(*i)->began = true;
			}
			(*i)->OnUpdate();

		}
	}

	void Object::Draw()
	{
		//Go through all components and draw them
		for (std::vector<std::shared_ptr<Component>>::iterator i = components.begin(); i != components.end(); i++)
		{
			(*i)->OnDraw();
		}
	}
}