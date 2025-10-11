// Find and delete
DWORD CMapManager::GetShadowMapColor (float fx, float fy)
{
	if (!IsMapReady())
	{
		return 0xFFFFFFFF;
	}

	CMapOutdoor& rkMap = GetMapOutdoorRef();
	return rkMap.GetShadowMapColor (fx, fy);
}