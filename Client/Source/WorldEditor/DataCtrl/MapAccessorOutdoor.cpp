// Find and delete
	D3DXMatrixMultiply (&matTexTransform, &matTexTransform, &m_matStaticShadow);

// Find and delete
	char szShadowTexName[64];
	char szShadowMapName[64];

// Find and delete
	_snprintf (szShadowTexName,	64, "%s\\%06u\\shadowmap.dds", m_strName.c_str(), ulID);
	_snprintf (szShadowMapName,	64, "%s\\%06u\\shadowmap.raw", m_strName.c_str(), ulID);

// Find and delete
	pTerrainAccessor->LoadShadowTexture (szShadowTexName);
	pTerrainAccessor->LoadShadowMap (szShadowMapName);

// Find
// Shadow Map
void CMapOutdoorAccessor::RenderToShadowMap()
{
	...
}

// Add below
/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
void CMapOutdoorAccessor::RenderObjectShadowsToTexture()
{
	for (int i = 0; i < AROUND_AREA_NUM; ++i)
	{
		CAreaAccessor* pAreaAccessor;
		if (GetAreaPointer(i, (CArea**)&pAreaAccessor) && pAreaAccessor)
			pAreaAccessor->RenderShadowObjects();
	}
}
/* ----------------------------------------------------- */