// Find
		TraceError (" CMapOutdoor::LoadArea(%d, %d) LoadShadowMap ERROR", wAreaCoordX, wAreaCoordY);

// Change (I'm not sure if this was a typo, why would they write loadShadowMap for loading area fail)
		TraceError (" CMapOutdoor::LoadArea(%d, %d) ERROR", wAreaCoordX, wAreaCoordY);

// Find and delete
	char szShadowTexName[64 + 1];
	char szShadowMapName[64 + 1];

// Find and delete
	_snprintf (szShadowTexName, sizeof (szShadowTexName), "%s\\%06u\\shadowmap.dds", GetMapDataDirectory().c_str(), ulID);
	_snprintf (szShadowMapName, sizeof (szShadowMapName), "%s\\%06u\\shadowmap.raw", GetMapDataDirectory().c_str(), ulID);

// Find and delete
	pTerrain->LoadShadowTexture (szShadowTexName);

	if (!pTerrain->LoadShadowMap (szShadowMapName))
	{
		TraceError (" CMapOutdoor::LoadTerrain(%d, %d) LoadShadowMap ERROR", wTerrainCoordX, wTerrainCoordY);
	}

// Find and delete
	D3DXMatrixScaling (&m_matStaticShadow,
					   +m_fTerrainTexCoordBase * ((float) CTerrainImpl::PATCH_XSIZE / static_cast<float> (CTerrainImpl::XSIZE)),
					   -m_fTerrainTexCoordBase * ((float) CTerrainImpl::PATCH_YSIZE / static_cast<float> (CTerrainImpl::XSIZE)),
					   0.0f);
	m_matStaticShadow._41 = 0.0f;
	m_matStaticShadow._42 = 0.0f;