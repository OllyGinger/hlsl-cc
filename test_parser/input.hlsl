

struct VS_OUT_MSAA
{
    float4 ProjPos  : POSITION;
    float2 Tex0     : TEXCOORD0;
};

struct VS_OUT_UI
{
    float4 ProjPos  : SV_Position;
    float4 Colour	: COLOR0;
    float2 Tex0     : TEXCOORD0;
};

VS_OUT_UI VShadeUI ( const float3 ObjPos: POSITION,
						const float4 Colour: COLOR0,
						const float2 UVs: TEXCOORD0 )
{
    VS_OUT_UI Out;

	Out.ProjPos = mul(float4(ObjPos, 1.0f), g_matWorldViewProj_VSC);   
	Out.ProjPos.w = ObjPos.z;
	Out.ProjPos.xyz *= Out.ProjPos.w;
	
	Out.Colour.xyz = pow(Colour.xyz, 2.2);
	Out.Colour.w = Colour.w;

    Out.Tex0 = UVs;
    return Out;
}
