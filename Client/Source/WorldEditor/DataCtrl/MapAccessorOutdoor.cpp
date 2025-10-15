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