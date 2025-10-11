// Find @@ void CPythonBackground::RenderCharacterShadowToTexture()
			else
			{
				rkChrMgr.RenderShadowAllInstances();

// Add below
				/* - DYNAMIC_TREE_SHADOWS ------------------------------ */
				/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
				STATEMANAGER.SaveRenderState(D3DRS_ZENABLE, FALSE);
				STATEMANAGER.SaveRenderState(D3DRS_ZWRITEENABLE, FALSE);
				STATEMANAGER.SaveRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
				STATEMANAGER.SaveRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
				STATEMANAGER.SaveRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
				/* ----------------------------------------------------- */

				/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
				rkMap.RenderObjectShadowsToTexture();
				/* ----------------------------------------------------- */

				/* - DYNAMIC_TREE_SHADOWS ------------------------------ */
				D3DXVECTOR3 vSunDir;
				if (GetLightDirection(vSunDir))
				{
					const float vCamDir[3] =
					{ -vSunDir.x,
					  -vSunDir.y,
					  -vSunDir.z
					};
					const D3DXVECTOR3 vEye(0.0f, 0.0f, 0.0f);
					CSpeedTreeRT::SetCamera(vEye, vCamDir);
				}
				CSpeedTreeForestDirectX8::Instance().Render(Forest_RenderBranches | Forest_RenderLeaves | Forest_RenderFronds | Forest_RenderToShadow);
				/* ----------------------------------------------------- */

				/* - DYNAMIC_TREE_SHADOWS ------------------------------ */
				/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
				STATEMANAGER.RestoreRenderState(D3DRS_ZENABLE);
				STATEMANAGER.RestoreRenderState(D3DRS_ZWRITEENABLE);
				STATEMANAGER.RestoreRenderState(D3DRS_ALPHABLENDENABLE);
				STATEMANAGER.RestoreRenderState(D3DRS_SRCBLEND);
				STATEMANAGER.RestoreRenderState(D3DRS_DESTBLEND);
				/* ----------------------------------------------------- */