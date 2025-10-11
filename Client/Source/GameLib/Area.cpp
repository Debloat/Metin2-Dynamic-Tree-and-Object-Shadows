// Find
void CArea::Refresh()

// Add above
/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
void CArea::RenderShadowObjects()
{
	for (CGraphicThingInstance* pInst : m_ShadowThingCloneInstaceVector)
		if (pInst && pInst->isShow())
			pInst->RenderToShadowMap();    // depth-only, alpha-tested
}
/* ----------------------------------------------------- */