// Find and delete @@ void CTerrainImpl::Initialize()
	memset (&m_awShadowMap, 0xFFFF, sizeof (m_awShadowMap));

// Find and delete @@ void CTerrainImpl::Initialize()
	m_lpShadowTexture = NULL;

// Find and delete
DWORD CTerrainImpl::GetShadowMapColor (float fx, float fy)
{
	float fMapSize = (float) (TERRAIN_XSIZE);
	float fooMapSize = 1.0f / fMapSize;
	if (fx < 0 || fy < 0 || fx >= fMapSize || fy >= fMapSize)
	{
		return 0xFFFFFFFF;
	}

	fx = fx * fooMapSize * (float) (SHADOWMAP_XSIZE - 1);
	fy = fy * fooMapSize * (float) (SHADOWMAP_YSIZE - 1);
	int ix, iy;
	PR_FLOAT_TO_INT (fx, ix);
	PR_FLOAT_TO_INT (fy, iy);

	WORD w = * (m_awShadowMap + (iy * SHADOWMAP_XSIZE) + ix);

	int b = w & 0x1f;
	w >>= 5;
	b <<= 3;
	int g = w & 0x1f;
	w >>= 5;
	g <<= 3;
	int r = w & 0x1f;
	r <<= 3;

	return (DWORD) (0xff << 24) | (g << 16) | (g << 8) | r;
}