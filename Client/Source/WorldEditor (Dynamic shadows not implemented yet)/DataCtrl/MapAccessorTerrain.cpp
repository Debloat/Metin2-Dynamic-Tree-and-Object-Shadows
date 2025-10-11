// Find and delete
bool CTerrainAccessor::ReloadShadowTexture (const std::string & c_rstrMapName)
{
	char szFileName[256];
	DWORD ulID = (DWORD) (m_wX) * 1000L + (DWORD) (m_wY);
	sprintf (szFileName, "%s\\%06u\\shadowmap.dds", c_rstrMapName.c_str(), ulID);

	CGraphicImage * pImage = (CGraphicImage*) CResourceManager::Instance().GetResourcePointer (szFileName);
	m_ShadowGraphicImageInstance.ReloadImagePointer (pImage);

	if (!m_ShadowGraphicImageInstance.GetTexturePointer()->IsEmpty())
	{
		m_lpShadowTexture = m_ShadowGraphicImageInstance.GetTexturePointer()->GetD3DTexture();
	}
	else
	{
		m_lpShadowTexture = NULL;
	}

	return true;
}