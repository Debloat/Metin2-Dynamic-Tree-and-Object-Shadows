// Find and delete
	char szShadowTexName[64 + 1];
	char szShadowMapName[64 + 1];

// Find and delete
	_snprintf (szShadowTexName, sizeof (szShadowTexName), "%s\\%06u\\shadowmap.dds", c_rStrMapName.c_str(), dwID);
	_snprintf (szShadowMapName, sizeof (szShadowMapName), "%s\\%06u\\shadowmap.raw", c_rStrMapName.c_str(), dwID);

// Find and delete
	Sleep (g_iLoadingDelayTime);
	pTerrain->LoadShadowTexture (szShadowTexName);
	Sleep (g_iLoadingDelayTime);
	pTerrain->LoadShadowMap (szShadowMapName);