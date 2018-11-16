/*
#include "Collision.h"

namespace toryengine
{
	bool Collision::IsColliding(glm::vec3 boxCentre, glm::vec3 boxHalfSize, Triangle t)
	{
		float bc[3] = { boxCentre.x,boxCentre.y,boxCentre.z };
		float hs[3] = { boxHalfSize.x,boxHalfSize.y,boxHalfSize.z };
		float triVerts[3][3] = { 0 };

		triVerts[0][0] = t.a.x;
		triVerts[0][1] = t.a.y;
		triVerts[0][2] = t.a.z;

		triVerts[1][0] = t.b.x;
		triVerts[1][1] = t.b.y;
		triVerts[1][2] = t.b.z;
		
		triVerts[2][0] = t.c.x;
		triVerts[2][1] = t.c.y;
		triVerts[2][2] = t.c.z;

		int res = triBoxOverlap(bc, hs, triVerts);

		if (res == 0)
		{
			return false;
		}
		return true;
	}
	
	bool BoxCollision()//first box, second box)
	{
		//First box X min = x;
		//first box X max = X + box width
		//first box Y min = y;
		//first box y max = y + box height
		//first box z min = z;
		first box z max = z + depth
		//get same for box 2
		//OR  dont use temp vars and use width / height / depth 

		//check  if (boxX1 max < boxX2 min || box1Xmin > x2Max)return false;
		//if (boxY1 max  <y2min || y1min > y2max) return false;
		//if (boxZ1 max < boxZ2min || boxZ1min > boxZ2max) return false;
		//return true;

	}
}
*/