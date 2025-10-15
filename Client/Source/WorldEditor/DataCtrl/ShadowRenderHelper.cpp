// Find @@ bool CShadowRenderHelper::StartRenderingPhase (BYTE byPhase)
			STATEMANAGER.SetTextureStageState (1, D3DTSS_COLOROP,	D3DTOP_DISABLE);
			STATEMANAGER.SetTextureStageState (1, D3DTSS_ALPHAOP,	D3DTOP_DISABLE);

// Add below
			/* - DYNAMIC_TREE_SHADOWS ------------------------------ */
			/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
			STATEMANAGER.SaveRenderState(D3DRS_ZENABLE, FALSE);
			STATEMANAGER.SaveRenderState(D3DRS_ZWRITEENABLE, FALSE);
			STATEMANAGER.SaveRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
			STATEMANAGER.SaveRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
			/* ----------------------------------------------------- */

// Find @@ void CShadowRenderHelper::EndRenderingPhase (BYTE byPhase)
		case 1:
		{

// Add below
			/* - DYNAMIC_TREE_SHADOWS ------------------------------ */
			/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
			STATEMANAGER.RestoreRenderState(D3DRS_ZENABLE);
			STATEMANAGER.RestoreRenderState(D3DRS_ZWRITEENABLE);
			STATEMANAGER.RestoreRenderState(D3DRS_SRCBLEND);
			STATEMANAGER.RestoreRenderState(D3DRS_DESTBLEND);
			/* ----------------------------------------------------- */