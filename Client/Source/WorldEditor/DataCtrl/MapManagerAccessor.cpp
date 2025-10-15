// Find and delete
		pTerrainAccessor->ReloadShadowTexture (m_pMapAccessor->GetName());

// Find @@ void CMapManagerAccessor::UpdateTerrainShadowMap()
	{
		CSpeedTreeForestDirectX8::Instance().Render (Forest_RenderAll | Forest_RenderToShadow);
		m_pMapAccessor->RenderToShadowMap();

// Add below
		/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
		m_pMapAccessor->RenderObjectShadowsToTexture();
		/* ----------------------------------------------------- */