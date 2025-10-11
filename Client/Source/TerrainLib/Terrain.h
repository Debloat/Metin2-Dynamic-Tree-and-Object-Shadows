// Find and delete
		LPDIRECT3DTEXTURE8		GetShadowTexture()
		{
			return m_lpShadowTexture;
		}

		DWORD					GetShadowMapColor (float fx, float fy);

// Find and delete
		//////////////////////////////////////////////////////////////////////////
		// Shadow Map
		LPDIRECT3DTEXTURE8		m_lpShadowTexture;
		WORD					m_awShadowMap[SHADOWMAP_YSIZE * SHADOWMAP_XSIZE];	// 16bit R5 G6 B5