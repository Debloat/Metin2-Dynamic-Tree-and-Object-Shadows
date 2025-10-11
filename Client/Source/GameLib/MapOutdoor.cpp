// Find and delete
DWORD CMapOutdoor::GetShadowMapColor (float fx, float fy)
{
	if (fy < 0)
	{
		fy = -fy;
	}

	float fTerrainSize = (float) (CTerrainImpl::TERRAIN_XSIZE);
	float fXRef = fx - (float) (m_lCurCoordStartX);
	float fYRef = fy - (float) (m_lCurCoordStartY);

	CTerrain * pTerrain;

	if (fYRef < -fTerrainSize)
	{
		return 0xFFFFFFFF;
	}
	else if (fYRef >= -fTerrainSize && fYRef < 0.0f)
	{
		if (fXRef < -fTerrainSize)
		{
			return 0xFFFFFFFF;
		}
		else if (fXRef >= -fTerrainSize && fXRef < 0.0f)
		{
			if (GetTerrainPointer (0, &pTerrain))
			{
				return pTerrain->GetShadowMapColor (fXRef + fTerrainSize, fYRef + fTerrainSize);
			}
			else
			{
				return 0xFFFFFFFF;
			}
		}
		else if (fXRef >= 0.0f && fXRef < fTerrainSize)
		{
			if (GetTerrainPointer (1, &pTerrain))
			{
				return pTerrain->GetShadowMapColor (fXRef, fYRef + fTerrainSize);
			}
			else
			{
				return 0xFFFFFFFF;
			}
		}
		else if (fXRef >= fTerrainSize && fXRef < 2.0f * fTerrainSize)
		{
			if (GetTerrainPointer (2, &pTerrain))
			{
				return pTerrain->GetShadowMapColor (fXRef - fTerrainSize, fYRef + fTerrainSize);
			}
			else
			{
				return 0xFFFFFFFF;
			}
		}
		else
		{
			return 0xFFFFFFFF;
		}
	}
	else if (fYRef >= 0.0f && fYRef < fTerrainSize)
	{
		if (fXRef < -fTerrainSize)
		{
			return 0xFFFFFFFF;
		}
		else if (fXRef >= -fTerrainSize && fXRef < 0.0f)
		{
			if (GetTerrainPointer (3, &pTerrain))
			{
				return pTerrain->GetShadowMapColor (fXRef + fTerrainSize, fYRef);
			}
			else
			{
				return 0xFFFFFFFF;
			}
		}
		else if (fXRef >= 0.0f && fXRef < fTerrainSize)
		{
			if (GetTerrainPointer (4, &pTerrain))
			{
				return pTerrain->GetShadowMapColor (fXRef, fYRef);
			}
			else
			{
				return 0xFFFFFFFF;
			}
		}
		else if (fXRef >= fTerrainSize && fXRef < 2.0f * fTerrainSize)
		{
			if (GetTerrainPointer (5, &pTerrain))
			{
				return pTerrain->GetShadowMapColor (fXRef - fTerrainSize, fYRef);
			}
			else
			{
				return 0xFFFFFFFF;
			}
		}
		else
		{
			return 0xFFFFFFFF;
		}
	}
	else if (fYRef >= fTerrainSize && fYRef < 2.0f * fTerrainSize)
	{
		if (fXRef < -fTerrainSize)
		{
			return 0xFFFFFFFF;
		}
		else if (fXRef >= -fTerrainSize && fXRef < 0.0f)
		{
			if (GetTerrainPointer (6, &pTerrain))
			{
				return pTerrain->GetShadowMapColor (fXRef + fTerrainSize, fYRef - fTerrainSize);
			}
			else
			{
				return 0xFFFFFFFF;
			}
		}
		else if (fXRef >= 0.0f && fXRef < fTerrainSize)
		{
			if (GetTerrainPointer (7, &pTerrain))
			{
				return pTerrain->GetShadowMapColor (fXRef, fYRef - fTerrainSize);
			}
			else
			{
				return 0xFFFFFFFF;
			}
		}
		else if (fXRef >= fTerrainSize && fXRef < 2.0f * fTerrainSize)
		{
			if (GetTerrainPointer (8, &pTerrain))
			{
				return pTerrain->GetShadowMapColor (fXRef - fTerrainSize, fYRef - fTerrainSize);
			}
			else
			{
				return 0xFFFFFFFF;
			}
		}
		else
		{
			return 0xFFFFFFFF;
		}
	}
	else
	{
		return 0xFFFFFFFF;
	}

	return 0xFFFFFFFF;
}