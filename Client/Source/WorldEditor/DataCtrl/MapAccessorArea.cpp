// Find
void CAreaAccessor::RenderToShadowMap()
{
	...
}

// Add below
/* - DYNAMIC_OBJECT_SHADOWS ---------------------------- */
void CAreaAccessor::RenderShadowObjects()
{
	for (CGraphicThingInstance* pInst : m_ShadowThingCloneInstaceVector)
		if (pInst && pInst->isShow())
			pInst->RenderToShadowMap();
}
/* ----------------------------------------------------- */