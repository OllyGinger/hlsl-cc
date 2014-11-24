cbuffer constants : register(b0)
{
	float4x4 g_matWorldViewProj_VSC	: packoffset(c0);  // World-view-projection matrix
}