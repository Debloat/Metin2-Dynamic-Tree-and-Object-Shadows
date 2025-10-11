// Find and delete
void CTerrain::LoadShadowTexture (const char* ShadowFileName)
{
	DWORD dwStart = ELTimer_GetMSec();
	CGraphicImage * pImage = (CGraphicImage*) CResourceManager::Instance().GetResourcePointer (ShadowFileName);
	m_ShadowGraphicImageInstance.SetImagePointer (pImage);

	if (!m_ShadowGraphicImageInstance.GetTexturePointer()->IsEmpty())
	{
		m_lpShadowTexture = m_ShadowGraphicImageInstance.GetTexturePointer()->GetD3DTexture();
	}
	else
	{
		TraceError (" CTerrain::LoadShadowTexture - ShadowTexture is Empty");
		m_lpShadowTexture = NULL;
	}
	Tracef ("CTerrain::LoadShadowTexture %d ms\n", ELTimer_GetMSec() - dwStart);
}

bool CTerrain::LoadShadowMap (const char* c_pszFileName)
{
	DWORD dwStart = ELTimer_GetMSec();
	Tracef ("LoadShadowMap %s ", c_pszFileName);

	CMappedFile file;
	LPCVOID c_pvData;

	if (!CEterPackManager::Instance().Get (file, c_pszFileName, &c_pvData))
	{
		TraceError (" CTerrain::LoadShadowMap - %s OPEN ERROR", c_pszFileName);
		return false;
	}

	DWORD dwShadowMapSize = sizeof (WORD) * 256 * 256;

	if (file.Size() != dwShadowMapSize)
	{
		TraceError (" CTerrain::LoadShadowMap - %s SIZE ERROR", c_pszFileName);
		return false;
	}

	memcpy (m_awShadowMap, c_pvData, dwShadowMapSize);

	Tracef ("%d ms\n", ELTimer_GetMSec() - dwStart);
	return true;
}