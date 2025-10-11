// Find @@ void CMapOutdoor::__HardwareTransformPatch_RenderPatchSplat (long patchnum, WORD
		D3DXMATRIX matShadowTexTransform;
		D3DXMatrixMultiply (&matShadowTexTransform, &matTexTransform, &m_matStaticShadow);

		STATEMANAGER.SetTransform (D3DTS_TEXTURE0, &matShadowTexTransform);
		STATEMANAGER.SetTexture (0, pTerrain->GetShadowTexture());

		STATEMANAGER.SetTextureStageState (0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
		STATEMANAGER.SetTextureStageState (0, D3DTSS_COLORARG2, D3DTA_CURRENT);
		STATEMANAGER.SetTextureStageState (0, D3DTSS_COLOROP,   D3DTOP_MODULATE);
		STATEMANAGER.SetTextureStageState (0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
		STATEMANAGER.SetTextureStageState (0, D3DTSS_ALPHAARG2, D3DTA_CURRENT);
		STATEMANAGER.SetTextureStageState (0, D3DTSS_ALPHAOP,   D3DTOP_DISABLE);
		STATEMANAGER.SetTextureStageState (0, D3DTSS_ADDRESSU,	D3DTADDRESS_CLAMP);
		STATEMANAGER.SetTextureStageState (0, D3DTSS_ADDRESSV,	D3DTADDRESS_CLAMP);

// Change
		/* - DYNAMIC_TREE_SHADOWS ------------------------------ */
		/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
		// Stage 0: just pass current color
		STATEMANAGER.SetTexture(0, nullptr);
		STATEMANAGER.SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_CURRENT);
		STATEMANAGER.SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
		/* ----------------------------------------------------- */