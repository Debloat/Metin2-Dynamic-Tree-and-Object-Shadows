// Find and delete
PyObject* backgroundGetShadowMapcolor (PyObject * poSelf, PyObject * poArgs)
{
	float fx;
	if (!PyTuple_GetFloat (poArgs, 0, &fx))
	{
		return Py_BadArgument();
	}

	float fy;
	if (!PyTuple_GetFloat (poArgs, 1, &fy))
	{
		return Py_BadArgument();
	}

	DWORD dwColor = CPythonBackground::Instance().GetShadowMapColor (fx, fy);
	return Py_BuildValue ("i", dwColor);
}

// Find and delete
		{ "GetShadowMapColor",					backgroundGetShadowMapcolor,				METH_VARARGS },