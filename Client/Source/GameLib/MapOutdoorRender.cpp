// Find
void CMapOutdoor::RenderTree()
{
	if (IsVisiblePart (PART_TREE))
	{
		CSpeedTreeForestDirectX8::Instance().Render();
	}
}

// Change
/* - DYNAMIC_TREE_SHADOWS ------------------------------ */
void CMapOutdoor::RenderTree(unsigned long flags)
{
	if (IsVisiblePart (PART_TREE))
	{
		CSpeedTreeForestDirectX8::Instance().Render(flags);
	}
}
/* ----------------------------------------------------- */

/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
void CMapOutdoor::RenderObjectShadowsToTexture()
{
	for (int i = 0; i < AROUND_AREA_NUM; ++i)
	{
		CArea* pArea;
		if (GetAreaPointer(i, &pArea) && pArea)
			pArea->RenderShadowObjects();
	}
}
/* ----------------------------------------------------- */

// Find
	RenderTree();

// Change
	/* - DYNAMIC_TREE_SHADOWS ------------------------------ */
	RenderTree(Forest_RenderAll);
	/* ----------------------------------------------------- */

// Find (Again)
	RenderTree();

// Change (Again)
	/* - DYNAMIC_TREE_SHADOWS ------------------------------ */
	RenderTree(Forest_RenderAll);
	/* ----------------------------------------------------- */

// Find and delete
	D3DXMatrixMultiply (&matTexTransform, &matTexTransform, &m_matStaticShadow);