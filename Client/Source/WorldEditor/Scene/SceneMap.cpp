// Find @@ void CSceneMap::OnRender (BOOL bClear)
	{
		m_pMapAccessor->BeginRenderCharacterShadowToTexture();

// Add below
		/* - DYNAMIC_TREE_SHADOWS ------------------------------ */
		/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
		STATEMANAGER.SaveRenderState(D3DRS_ZENABLE, FALSE);
		STATEMANAGER.SaveRenderState(D3DRS_ZWRITEENABLE, FALSE);
		STATEMANAGER.SaveRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
		STATEMANAGER.SaveRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		STATEMANAGER.SaveRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		m_pMapAccessor->RenderObjectShadowsToTexture();
		const TEnvironmentData* pEnvironmentData;
		m_pMapManagerAccessor->GetEnvironmentData(&pEnvironmentData);
		if (pEnvironmentData)
		{
			D3DXVECTOR3 vSunDir;
			vSunDir.x = pEnvironmentData->DirLights[ENV_DIRLIGHT_BACKGROUND].Direction.x;
			vSunDir.y = pEnvironmentData->DirLights[ENV_DIRLIGHT_BACKGROUND].Direction.y;
			vSunDir.z = pEnvironmentData->DirLights[ENV_DIRLIGHT_BACKGROUND].Direction.z;

			const float vCamDir[3] = { -vSunDir.x, -vSunDir.y, -vSunDir.z };
			const D3DXVECTOR3 vEye(0.0f, 0.0f, 0.0f);
			CSpeedTreeRT::SetCamera(vEye, vCamDir);
		}
		CSpeedTreeForestDirectX8::Instance().Render(Forest_RenderBranches | Forest_RenderLeaves | Forest_RenderFronds | Forest_RenderToShadow);

		STATEMANAGER.RestoreRenderState(D3DRS_ZENABLE);
		STATEMANAGER.RestoreRenderState(D3DRS_ZWRITEENABLE);
		STATEMANAGER.RestoreRenderState(D3DRS_ALPHABLENDENABLE);
		STATEMANAGER.RestoreRenderState(D3DRS_SRCBLEND);
		STATEMANAGER.RestoreRenderState(D3DRS_DESTBLEND);
		/* ----------------------------------------------------- */

// Find
void CSceneMap::SetObjectShadowRendering (bool bOn)
{
	m_pMapAccessor->SetDrawShadow (bOn);

// Add below
	/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
	/* - DYNAMIC_TREE_SHADOWS ------------------------------ */
	m_pMapAccessor->SetDrawCharacterShadow(bOn);
	/* ----------------------------------------------------- */