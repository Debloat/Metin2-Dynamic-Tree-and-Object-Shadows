// Find and delete
		DWORD			GetShadowMapColor (float fx, float fy);

// Find
		void			RenderTree();

// Change
		/* - DYNAMIC_TREE_SHADOWS ------------------------------ */
		void			RenderTree(unsigned long flags = 0);
		/* ----------------------------------------------------- */

		/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
		void			RenderObjectShadowsToTexture();
		/* ----------------------------------------------------- */

// Find and delete
		D3DXMATRIX m_matStaticShadow;