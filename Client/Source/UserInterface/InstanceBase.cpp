// Find and delete
DWORD CInstanceBase::__GetShadowMapColor (float x, float y)
{
	CPythonBackground& rkBG = CPythonBackground::Instance();
	return rkBG.GetShadowMapColor (x, y);
}

// Find and delete
		// SetMaterialColor
		{
			DWORD dwMtrlColor = __GetShadowMapColor (kPPosCur.x, kPPosCur.y);
			m_GraphicThingInstance.SetMaterialColor (dwMtrlColor);
		}