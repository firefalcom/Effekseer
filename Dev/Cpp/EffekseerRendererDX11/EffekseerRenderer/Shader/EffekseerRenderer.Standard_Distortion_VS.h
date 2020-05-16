#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tvs_4_0 /EVS /D __EFFEKSEER_BUILD_VERSION16__=1 /Fh
//    Shader/EffekseerRenderer.Standard_Distortion_VS.h
//    Shader/standard_renderer_distortion_VS.fx
//
//
// Buffer Definitions: 
//
// cbuffer VS_ConstantBuffer
// {
//
//   float4x4 mCamera;                  // Offset:    0 Size:    64
//   float4x4 mProj;                    // Offset:   64 Size:    64
//   float4 mUVInversed;                // Offset:  128 Size:    16
//   float4 mflipbookParameter;         // Offset:  144 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// VS_ConstantBuffer                 cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// POSITION                 0   xyz         0     NONE  float   xyz 
// NORMAL                   0   xyzw        1     NONE  float   xyzw
// TEXCOORD                 0   xy          2     NONE  float   xy  
// NORMAL                   1   xyz         3     NONE  float   xyz 
// NORMAL                   2   xyz         4     NONE  float   xyz 
// TEXCOORD                 1   xy          5     NONE  float   xy  
// TEXCOORD                 2   x           6     NONE  float   x   
// TEXCOORD                 3   x           7     NONE  float   x   
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float   xyzw
// COLOR                    0   xyzw        1     NONE  float   xyzw
// TEXCOORD                 0   xy          2     NONE  float   xy  
// TEXCOORD                 4     zw        2     NONE  float     zw
// TEXCOORD                 1   xyzw        3     NONE  float   xyzw
// TEXCOORD                 2   xyzw        4     NONE  float   xyzw
// TEXCOORD                 3   xyzw        5     NONE  float   xyzw
// TEXCOORD                 5   x           6     NONE  float   x   
// TEXCOORD                 6    yz         6     NONE  float    yz 
// TEXCOORD                 7      w        6     NONE  float      w
//
vs_4_0
dcl_constantbuffer cb0[10], immediateIndexed
dcl_input v0.xyz
dcl_input v1.xyzw
dcl_input v2.xy
dcl_input v3.xyz
dcl_input v4.xyz
dcl_input v5.xy
dcl_input v6.x
dcl_input v7.x
dcl_output_siv o0.xyzw, position
dcl_output o1.xyzw
dcl_output o2.xy
dcl_output o2.zw
dcl_output o3.xyzw
dcl_output o4.xyzw
dcl_output o5.xyzw
dcl_output o6.x
dcl_output o6.yz
dcl_output o6.w
dcl_temps 6
add r0.xyz, v0.xyzx, v3.xyzx
add r1.xyz, v0.xyzx, v4.xyzx
mul r2.xyzw, r0.yyyy, cb0[1].xyzw
mad r2.xyzw, cb0[0].xyzw, r0.xxxx, r2.xyzw
mad r0.xyzw, cb0[2].xyzw, r0.zzzz, r2.xyzw
add r0.xyzw, r0.xyzw, cb0[3].xyzw
mul r2.xyzw, r1.yyyy, cb0[1].xyzw
mad r2.xyzw, cb0[0].xyzw, r1.xxxx, r2.xyzw
mad r1.xyzw, cb0[2].xyzw, r1.zzzz, r2.xyzw
add r1.xyzw, r1.xyzw, cb0[3].xyzw
mul r2.xyzw, v0.yyyy, cb0[1].xyzw
mad r2.xyzw, cb0[0].xyzw, v0.xxxx, r2.xyzw
mad r2.xyzw, cb0[2].xyzw, v0.zzzz, r2.xyzw
add r2.xyzw, r2.xyzw, cb0[3].xyzw
div r2.xyzw, r2.xyzw, r2.wwww
div r0.xyzw, r0.xyzw, r0.wwww
div r1.xyzw, r1.xyzw, r1.wwww
add r0.xyzw, -r2.xyzw, r0.xyzw
dp4 r3.x, r0.xyzw, r0.xyzw
rsq r3.x, r3.x
mad r0.xyzw, r0.xyzw, r3.xxxx, r2.xyzw
add r1.xyzw, -r2.xyzw, r1.xyzw
dp4 r3.x, r1.xyzw, r1.xyzw
rsq r3.x, r3.x
mad r1.xyzw, r1.xyzw, r3.xxxx, r2.xyzw
mul r3.xyzw, r2.yyyy, cb0[5].xyzw
mad r3.xyzw, cb0[4].xyzw, r2.xxxx, r3.xyzw
mad r3.xyzw, cb0[6].xyzw, r2.zzzz, r3.xyzw
mad r2.xyzw, cb0[7].xyzw, r2.wwww, r3.xyzw
mul r3.xyzw, r0.yyyy, cb0[5].xyzw
mad r3.xyzw, cb0[4].xyzw, r0.xxxx, r3.xyzw
mad r3.xyzw, cb0[6].xyzw, r0.zzzz, r3.xyzw
mad r0.xyzw, cb0[7].xyzw, r0.wwww, r3.xyzw
mul r3.xyzw, r1.yyyy, cb0[5].xyzw
mad r3.xyzw, cb0[4].xyzw, r1.xxxx, r3.xyzw
mad r3.xyzw, cb0[6].xyzw, r1.zzzz, r3.xyzw
mad r1.xyzw, cb0[7].xyzw, r1.wwww, r3.xyzw
div o4.xyzw, r0.xyzw, r0.wwww
div o5.xyzw, r1.xyzw, r1.wwww
div o3.xyzw, r2.xyzw, r2.wwww
mad r0.y, cb0[8].y, v2.y, cb0[8].x
mad o2.w, cb0[8].y, v5.y, cb0[8].x
lt r0.z, l(0.000000), cb0[9].x
if_nz r0.z
  frc r1.x, v6.x
  round_ni r3.x, v6.x
  add r0.z, v6.x, l(1.000000)
  eq r0.w, cb0[9].y, l(0.000000)
  if_nz r0.w
    mul r0.w, cb0[9].w, cb0[9].z
    ge r0.w, r0.z, r0.w
    mad r3.w, cb0[9].z, cb0[9].w, l(-1.000000)
    add r3.z, v6.x, l(1.000000)
    movc r3.xy, r0.wwww, r3.wwww, r3.xzxx
  else 
    mul r0.w, cb0[9].w, cb0[9].z
    mul r3.z, r0.w, r0.z
    ge r3.z, r3.z, -r3.z
    movc r3.z, r3.z, r0.w, -r0.w
    div r3.w, l(1.000000, 1.000000, 1.000000, 1.000000), r3.z
    mul r3.w, r0.z, r3.w
    frc r3.w, r3.w
    mul r3.z, r3.w, r3.z
    eq r4.xy, cb0[9].yyyy, l(1.000000, 2.000000, 0.000000, 0.000000)
    round_ni r3.w, r0.z
    div r3.w, r3.w, r0.w
    add r4.z, r3.w, r3.w
    ge r4.z, r4.z, -r4.z
    movc r4.zw, r4.zzzz, l(0,0,2.000000,0.500000), l(0,0,-2.000000,-0.500000)
    mul r3.w, r3.w, r4.w
    frc r3.w, r3.w
    mul r3.w, r3.w, r4.z
    eq r3.w, r3.w, l(1.000000)
    round_z r4.z, r0.z
    mul r4.w, r0.w, r4.z
    ge r4.w, r4.w, -r4.w
    movc r0.w, r4.w, r0.w, -r0.w
    div r4.w, l(1.000000, 1.000000, 1.000000, 1.000000), r0.w
    mul r4.z, r4.w, r4.z
    frc r4.z, r4.z
    mul r4.w, r0.w, r4.z
    mad r5.x, cb0[9].z, cb0[9].w, l(-1.000000)
    mad r0.w, -r0.w, r4.z, r5.x
    movc r0.w, r3.w, r0.w, r4.w
    movc r0.z, r4.y, r0.w, r0.z
    movc r3.y, r4.x, r3.z, r0.z
  endif 
  ftoi r0.zw, r3.xxxy
  ftoi r3.xy, cb0[9].zwzz
  and r3.zw, r0.zzzw, l(0, 0, 0x80000000, 0x80000000)
  imax r4.xy, r0.zwzz, -r0.zwzz
  imax r4.zw, r3.xxxy, -r3.xxxy
  udiv null, r5.xy, r4.xyxx, r4.zzzz
  ineg r5.zw, r5.xxxy
  movc r3.xz, r3.zzwz, r5.zzwz, r5.xxyx
  itof r5.xy, r3.xzxx
  xor r0.zw, r0.zzzw, r3.yyyy
  udiv r3.xy, null, r4.xyxx, r4.wwww
  ineg r3.zw, r3.xxxy
  and r0.zw, r0.zzzw, l(0, 0, 0x80000000, 0x80000000)
  movc r0.zw, r0.zzzw, r3.zzzw, r3.xxxy
  itof r5.zw, r0.zzzw
  div r0.zw, l(1.000000, 1.000000, 1.000000, 1.000000), cb0[9].zzzw
  mul r3.xy, r0.zwzz, r5.ywyy
  mov r0.x, v2.x
  mad r3.zw, -r5.xxxz, r0.zzzw, r0.xxxy
  mul r3.zw, r3.zzzw, cb0[9].zzzw
  mad r1.yz, r3.zzwz, r0.zzwz, r3.xxyx
else 
  mov r1.xyz, l(0,0,0,0)
endif 
mov o0.xyzw, r2.xyzw
mov o1.xyzw, v1.xyzw
mov o2.x, v2.x
mov o2.y, r0.y
mov o2.z, v5.x
mov r1.w, v7.x
mov o6.xyzw, r1.xyzw
ret 
// Approximately 119 instruction slots used
#endif

const BYTE g_VS[] =
{
     68,  88,  66,  67, 134,  41, 
    234, 148, 104,  85,  37, 125, 
    102, 242,  55,  30, 115, 239, 
     69,  47,   1,   0,   0,   0, 
      8,  19,   0,   0,   5,   0, 
      0,   0,  52,   0,   0,   0, 
    132,   1,   0,   0, 112,   2, 
      0,   0, 140,   3,   0,   0, 
    140,  18,   0,   0,  82,  68, 
     69,  70,  72,   1,   0,   0, 
      1,   0,   0,   0,  80,   0, 
      0,   0,   1,   0,   0,   0, 
     28,   0,   0,   0,   0,   4, 
    254, 255,  16,   1,   0,   0, 
     23,   1,   0,   0,  60,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   1,   0,   0,   0, 
     86,  83,  95,  67, 111, 110, 
    115, 116,  97, 110, 116,  66, 
    117, 102, 102, 101, 114,   0, 
    171, 171,  60,   0,   0,   0, 
      4,   0,   0,   0, 104,   0, 
      0,   0, 160,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 200,   0,   0,   0, 
      0,   0,   0,   0,  64,   0, 
      0,   0,   2,   0,   0,   0, 
    208,   0,   0,   0,   0,   0, 
      0,   0, 224,   0,   0,   0, 
     64,   0,   0,   0,  64,   0, 
      0,   0,   2,   0,   0,   0, 
    208,   0,   0,   0,   0,   0, 
      0,   0, 230,   0,   0,   0, 
    128,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    244,   0,   0,   0,   0,   0, 
      0,   0,   4,   1,   0,   0, 
    144,   0,   0,   0,  16,   0, 
      0,   0,   2,   0,   0,   0, 
    244,   0,   0,   0,   0,   0, 
      0,   0, 109,  67,  97, 109, 
    101, 114,  97,   0,   3,   0, 
      3,   0,   4,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 109,  80, 114, 111, 
    106,   0, 109,  85,  86,  73, 
    110, 118, 101, 114, 115, 101, 
    100,   0, 171, 171,   1,   0, 
      3,   0,   1,   0,   4,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0, 109, 102, 108, 105, 
    112,  98, 111, 111, 107,  80, 
     97, 114,  97, 109, 101, 116, 
    101, 114,   0,  77, 105,  99, 
    114, 111, 115, 111, 102, 116, 
     32,  40,  82,  41,  32,  72, 
     76,  83,  76,  32,  83, 104, 
     97, 100, 101, 114,  32,  67, 
    111, 109, 112, 105, 108, 101, 
    114,  32,  57,  46,  50,  57, 
     46,  57,  53,  50,  46,  51, 
     49,  49,  49,   0,  73,  83, 
     71,  78, 228,   0,   0,   0, 
      8,   0,   0,   0,   8,   0, 
      0,   0, 200,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   7,   7, 
      0,   0, 209,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,  15,  15, 
      0,   0, 216,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   3,   3, 
      0,   0, 209,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      3,   0,   0,   0,   7,   7, 
      0,   0, 209,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      4,   0,   0,   0,   7,   7, 
      0,   0, 216,   0,   0,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      5,   0,   0,   0,   3,   3, 
      0,   0, 216,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      6,   0,   0,   0,   1,   1, 
      0,   0, 216,   0,   0,   0, 
      3,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      7,   0,   0,   0,   1,   1, 
      0,   0,  80,  79,  83,  73, 
     84,  73,  79,  78,   0,  78, 
     79,  82,  77,  65,  76,   0, 
     84,  69,  88,  67,  79,  79, 
     82,  68,   0, 171, 171, 171, 
     79,  83,  71,  78,  20,   1, 
      0,   0,  10,   0,   0,   0, 
      8,   0,   0,   0, 248,   0, 
      0,   0,   0,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,   4,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   1,   0,   0,   0, 
     15,   0,   0,   0,  10,   1, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
      3,  12,   0,   0,  10,   1, 
      0,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   2,   0,   0,   0, 
     12,   3,   0,   0,  10,   1, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   3,   0,   0,   0, 
     15,   0,   0,   0,  10,   1, 
      0,   0,   2,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   4,   0,   0,   0, 
     15,   0,   0,   0,  10,   1, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   5,   0,   0,   0, 
     15,   0,   0,   0,  10,   1, 
      0,   0,   5,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
      1,  14,   0,   0,  10,   1, 
      0,   0,   6,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
      6,   9,   0,   0,  10,   1, 
      0,   0,   7,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   6,   0,   0,   0, 
      8,   7,   0,   0,  83,  86, 
     95,  80,  79,  83,  73,  84, 
     73,  79,  78,   0,  67,  79, 
     76,  79,  82,   0,  84,  69, 
     88,  67,  79,  79,  82,  68, 
      0, 171,  83,  72,  68,  82, 
    248,  14,   0,   0,  64,   0, 
      1,   0, 190,   3,   0,   0, 
     89,   0,   0,   4,  70, 142, 
     32,   0,   0,   0,   0,   0, 
     10,   0,   0,   0,  95,   0, 
      0,   3, 114,  16,  16,   0, 
      0,   0,   0,   0,  95,   0, 
      0,   3, 242,  16,  16,   0, 
      1,   0,   0,   0,  95,   0, 
      0,   3,  50,  16,  16,   0, 
      2,   0,   0,   0,  95,   0, 
      0,   3, 114,  16,  16,   0, 
      3,   0,   0,   0,  95,   0, 
      0,   3, 114,  16,  16,   0, 
      4,   0,   0,   0,  95,   0, 
      0,   3,  50,  16,  16,   0, 
      5,   0,   0,   0,  95,   0, 
      0,   3,  18,  16,  16,   0, 
      6,   0,   0,   0,  95,   0, 
      0,   3,  18,  16,  16,   0, 
      7,   0,   0,   0, 103,   0, 
      0,   4, 242,  32,  16,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   1,   0, 
      0,   0, 101,   0,   0,   3, 
     50,  32,  16,   0,   2,   0, 
      0,   0, 101,   0,   0,   3, 
    194,  32,  16,   0,   2,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   3,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   4,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   5,   0, 
      0,   0, 101,   0,   0,   3, 
     18,  32,  16,   0,   6,   0, 
      0,   0, 101,   0,   0,   3, 
     98,  32,  16,   0,   6,   0, 
      0,   0, 101,   0,   0,   3, 
    130,  32,  16,   0,   6,   0, 
      0,   0, 104,   0,   0,   2, 
      6,   0,   0,   0,   0,   0, 
      0,   7, 114,   0,  16,   0, 
      0,   0,   0,   0,  70,  18, 
     16,   0,   0,   0,   0,   0, 
     70,  18,  16,   0,   3,   0, 
      0,   0,   0,   0,   0,   7, 
    114,   0,  16,   0,   1,   0, 
      0,   0,  70,  18,  16,   0, 
      0,   0,   0,   0,  70,  18, 
     16,   0,   4,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     86,   5,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
    166,  10,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   8, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     86,   5,  16,   0,   1,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   6,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
    166,  10,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   8, 242,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     86,  21,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   6,  16,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   2,   0,   0,   0, 
    166,  26,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   8, 242,   0,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
     14,   0,   0,   7, 242,   0, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0, 246,  15,  16,   0, 
      2,   0,   0,   0,  14,   0, 
      0,   7, 242,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  14,   0,   0,   7, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0, 246,  15, 
     16,   0,   1,   0,   0,   0, 
      0,   0,   0,   8, 242,   0, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16, 128,  65,   0, 
      0,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   0,   0, 
      0,   0,  17,   0,   0,   7, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
     68,   0,   0,   5,  18,   0, 
     16,   0,   3,   0,   0,   0, 
     10,   0,  16,   0,   3,   0, 
      0,   0,  50,   0,   0,   9, 
    242,   0,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      0,   0,   0,   0,   6,   0, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0,   0,   0,   0,   8, 
    242,   0,  16,   0,   1,   0, 
      0,   0,  70,  14,  16, 128, 
     65,   0,   0,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  17,   0, 
      0,   7,  18,   0,  16,   0, 
      3,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   1,   0, 
      0,   0,  68,   0,   0,   5, 
     18,   0,  16,   0,   3,   0, 
      0,   0,  10,   0,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,   9, 242,   0,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   1,   0,   0,   0, 
      6,   0,  16,   0,   3,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  56,   0, 
      0,   8, 242,   0,  16,   0, 
      3,   0,   0,   0,  86,   5, 
     16,   0,   2,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   5,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   4,   0,   0,   0, 
      6,   0,  16,   0,   2,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      6,   0,   0,   0, 166,  10, 
     16,   0,   2,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   2,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   7,   0, 
      0,   0, 246,  15,  16,   0, 
      2,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,   8, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     86,   5,  16,   0,   0,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   5,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   4,   0, 
      0,   0,   6,   0,  16,   0, 
      0,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   3,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   6,   0,   0,   0, 
    166,  10,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      0,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      7,   0,   0,   0, 246,  15, 
     16,   0,   0,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  56,   0,   0,   8, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  86,   5,  16,   0, 
      1,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      5,   0,   0,   0,  50,   0, 
      0,  10, 242,   0,  16,   0, 
      3,   0,   0,   0,  70, 142, 
     32,   0,   0,   0,   0,   0, 
      4,   0,   0,   0,   6,   0, 
     16,   0,   1,   0,   0,   0, 
     70,  14,  16,   0,   3,   0, 
      0,   0,  50,   0,   0,  10, 
    242,   0,  16,   0,   3,   0, 
      0,   0,  70, 142,  32,   0, 
      0,   0,   0,   0,   6,   0, 
      0,   0, 166,  10,  16,   0, 
      1,   0,   0,   0,  70,  14, 
     16,   0,   3,   0,   0,   0, 
     50,   0,   0,  10, 242,   0, 
     16,   0,   1,   0,   0,   0, 
     70, 142,  32,   0,   0,   0, 
      0,   0,   7,   0,   0,   0, 
    246,  15,  16,   0,   1,   0, 
      0,   0,  70,  14,  16,   0, 
      3,   0,   0,   0,  14,   0, 
      0,   7, 242,  32,  16,   0, 
      4,   0,   0,   0,  70,  14, 
     16,   0,   0,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0,  14,   0,   0,   7, 
    242,  32,  16,   0,   5,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0, 246,  15, 
     16,   0,   1,   0,   0,   0, 
     14,   0,   0,   7, 242,  32, 
     16,   0,   3,   0,   0,   0, 
     70,  14,  16,   0,   2,   0, 
      0,   0, 246,  15,  16,   0, 
      2,   0,   0,   0,  50,   0, 
      0,  11,  34,   0,  16,   0, 
      0,   0,   0,   0,  26, 128, 
     32,   0,   0,   0,   0,   0, 
      8,   0,   0,   0,  26,  16, 
     16,   0,   2,   0,   0,   0, 
     10, 128,  32,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
     50,   0,   0,  11, 130,  32, 
     16,   0,   2,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,   8,   0,   0,   0, 
     26,  16,  16,   0,   5,   0, 
      0,   0,  10, 128,  32,   0, 
      0,   0,   0,   0,   8,   0, 
      0,   0,  49,   0,   0,   8, 
     66,   0,  16,   0,   0,   0, 
      0,   0,   1,  64,   0,   0, 
      0,   0,   0,   0,  10, 128, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  31,   0, 
      4,   3,  42,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
      0,   5,  18,   0,  16,   0, 
      1,   0,   0,   0,  10,  16, 
     16,   0,   6,   0,   0,   0, 
     65,   0,   0,   5,  18,   0, 
     16,   0,   3,   0,   0,   0, 
     10,  16,  16,   0,   6,   0, 
      0,   0,   0,   0,   0,   7, 
     66,   0,  16,   0,   0,   0, 
      0,   0,  10,  16,  16,   0, 
      6,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     24,   0,   0,   8, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     26, 128,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  31,   0,   4,   3, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   9, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  58, 128,  32,   0, 
      0,   0,   0,   0,   9,   0, 
      0,   0,  42, 128,  32,   0, 
      0,   0,   0,   0,   9,   0, 
      0,   0,  29,   0,   0,   7, 
    130,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     50,   0,   0,  11, 130,   0, 
     16,   0,   3,   0,   0,   0, 
     42, 128,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
     58, 128,  32,   0,   0,   0, 
      0,   0,   9,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128, 191,   0,   0,   0,   7, 
     66,   0,  16,   0,   3,   0, 
      0,   0,  10,  16,  16,   0, 
      6,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128,  63, 
     55,   0,   0,   9,  50,   0, 
     16,   0,   3,   0,   0,   0, 
    246,  15,  16,   0,   0,   0, 
      0,   0, 246,  15,  16,   0, 
      3,   0,   0,   0, 134,   0, 
     16,   0,   3,   0,   0,   0, 
     18,   0,   0,   1,  56,   0, 
      0,   9, 130,   0,  16,   0, 
      0,   0,   0,   0,  58, 128, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  56,   0, 
      0,   7,  66,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  29,   0,   0,   8, 
     66,   0,  16,   0,   3,   0, 
      0,   0,  42,   0,  16,   0, 
      3,   0,   0,   0,  42,   0, 
     16, 128,  65,   0,   0,   0, 
      3,   0,   0,   0,  55,   0, 
      0,  10,  66,   0,  16,   0, 
      3,   0,   0,   0,  42,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  14,   0,   0,  10, 
    130,   0,  16,   0,   3,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,  42,   0, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   3,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,  26,   0, 
      0,   5, 130,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,   7,  66,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   3,   0, 
      0,   0,  42,   0,  16,   0, 
      3,   0,   0,   0,  24,   0, 
      0,  11,  50,   0,  16,   0, 
      4,   0,   0,   0,  86, 133, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,   2,  64, 
      0,   0,   0,   0, 128,  63, 
      0,   0,   0,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
     65,   0,   0,   5, 130,   0, 
     16,   0,   3,   0,   0,   0, 
     42,   0,  16,   0,   0,   0, 
      0,   0,  14,   0,   0,   7, 
    130,   0,  16,   0,   3,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0,   0,   7,  66,   0, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   3,   0, 
      0,   0,  58,   0,  16,   0, 
      3,   0,   0,   0,  29,   0, 
      0,   8,  66,   0,  16,   0, 
      4,   0,   0,   0,  42,   0, 
     16,   0,   4,   0,   0,   0, 
     42,   0,  16, 128,  65,   0, 
      0,   0,   4,   0,   0,   0, 
     55,   0,   0,  15, 194,   0, 
     16,   0,   4,   0,   0,   0, 
    166,  10,  16,   0,   4,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,  64, 
      0,   0,   0,  63,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0, 192,   0,   0,   0, 191, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   3,   0, 
      0,   0,  58,   0,  16,   0, 
      4,   0,   0,   0,  26,   0, 
      0,   5, 130,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   3,   0, 
      0,   0,  42,   0,  16,   0, 
      4,   0,   0,   0,  24,   0, 
      0,   7, 130,   0,  16,   0, 
      3,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
    128,  63,  67,   0,   0,   5, 
     66,   0,  16,   0,   4,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  56,   0, 
      0,   7, 130,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   4,   0, 
      0,   0,  29,   0,   0,   8, 
    130,   0,  16,   0,   4,   0, 
      0,   0,  58,   0,  16,   0, 
      4,   0,   0,   0,  58,   0, 
     16, 128,  65,   0,   0,   0, 
      4,   0,   0,   0,  55,   0, 
      0,  10, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16, 128, 
     65,   0,   0,   0,   0,   0, 
      0,   0,  14,   0,   0,  10, 
    130,   0,  16,   0,   4,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63,  58,   0, 
     16,   0,   0,   0,   0,   0, 
     56,   0,   0,   7,  66,   0, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   4,   0, 
      0,   0,  42,   0,  16,   0, 
      4,   0,   0,   0,  26,   0, 
      0,   5,  66,   0,  16,   0, 
      4,   0,   0,   0,  42,   0, 
     16,   0,   4,   0,   0,   0, 
     56,   0,   0,   7, 130,   0, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      4,   0,   0,   0,  50,   0, 
      0,  11,  18,   0,  16,   0, 
      5,   0,   0,   0,  42, 128, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  58, 128, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,   1,  64, 
      0,   0,   0,   0, 128, 191, 
     50,   0,   0,  10, 130,   0, 
     16,   0,   0,   0,   0,   0, 
     58,   0,  16, 128,  65,   0, 
      0,   0,   0,   0,   0,   0, 
     42,   0,  16,   0,   4,   0, 
      0,   0,  10,   0,  16,   0, 
      5,   0,   0,   0,  55,   0, 
      0,   9, 130,   0,  16,   0, 
      0,   0,   0,   0,  58,   0, 
     16,   0,   3,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  58,   0,  16,   0, 
      4,   0,   0,   0,  55,   0, 
      0,   9,  66,   0,  16,   0, 
      0,   0,   0,   0,  26,   0, 
     16,   0,   4,   0,   0,   0, 
     58,   0,  16,   0,   0,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  55,   0, 
      0,   9,  34,   0,  16,   0, 
      3,   0,   0,   0,  10,   0, 
     16,   0,   4,   0,   0,   0, 
     42,   0,  16,   0,   3,   0, 
      0,   0,  42,   0,  16,   0, 
      0,   0,   0,   0,  21,   0, 
      0,   1,  27,   0,   0,   5, 
    194,   0,  16,   0,   0,   0, 
      0,   0,   6,   4,  16,   0, 
      3,   0,   0,   0,  27,   0, 
      0,   6,  50,   0,  16,   0, 
      3,   0,   0,   0, 230, 138, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,   1,   0, 
      0,  10, 194,   0,  16,   0, 
      3,   0,   0,   0, 166,  14, 
     16,   0,   0,   0,   0,   0, 
      2,  64,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0, 128,   0,   0, 
      0, 128,  36,   0,   0,   8, 
     50,   0,  16,   0,   4,   0, 
      0,   0, 230,  10,  16,   0, 
      0,   0,   0,   0, 230,  10, 
     16, 128,  65,   0,   0,   0, 
      0,   0,   0,   0,  36,   0, 
      0,   8, 194,   0,  16,   0, 
      4,   0,   0,   0,   6,   4, 
     16,   0,   3,   0,   0,   0, 
      6,   4,  16, 128,  65,   0, 
      0,   0,   3,   0,   0,   0, 
     78,   0,   0,   8,   0, 208, 
      0,   0,  50,   0,  16,   0, 
      5,   0,   0,   0,  70,   0, 
     16,   0,   4,   0,   0,   0, 
    166,  10,  16,   0,   4,   0, 
      0,   0,  40,   0,   0,   5, 
    194,   0,  16,   0,   5,   0, 
      0,   0,   6,   4,  16,   0, 
      5,   0,   0,   0,  55,   0, 
      0,   9,  82,   0,  16,   0, 
      3,   0,   0,   0, 166,  11, 
     16,   0,   3,   0,   0,   0, 
    166,  11,  16,   0,   5,   0, 
      0,   0,   6,   1,  16,   0, 
      5,   0,   0,   0,  43,   0, 
      0,   5,  50,   0,  16,   0, 
      5,   0,   0,   0, 134,   0, 
     16,   0,   3,   0,   0,   0, 
     87,   0,   0,   7, 194,   0, 
     16,   0,   0,   0,   0,   0, 
    166,  14,  16,   0,   0,   0, 
      0,   0,  86,   5,  16,   0, 
      3,   0,   0,   0,  78,   0, 
      0,   8,  50,   0,  16,   0, 
      3,   0,   0,   0,   0, 208, 
      0,   0,  70,   0,  16,   0, 
      4,   0,   0,   0, 246,  15, 
     16,   0,   4,   0,   0,   0, 
     40,   0,   0,   5, 194,   0, 
     16,   0,   3,   0,   0,   0, 
      6,   4,  16,   0,   3,   0, 
      0,   0,   1,   0,   0,  10, 
    194,   0,  16,   0,   0,   0, 
      0,   0, 166,  14,  16,   0, 
      0,   0,   0,   0,   2,  64, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0, 128,   0,   0,   0, 128, 
     55,   0,   0,   9, 194,   0, 
     16,   0,   0,   0,   0,   0, 
    166,  14,  16,   0,   0,   0, 
      0,   0, 166,  14,  16,   0, 
      3,   0,   0,   0,   6,   4, 
     16,   0,   3,   0,   0,   0, 
     43,   0,   0,   5, 194,   0, 
     16,   0,   5,   0,   0,   0, 
    166,  14,  16,   0,   0,   0, 
      0,   0,  14,   0,   0,  11, 
    194,   0,  16,   0,   0,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0, 128,  63,   0,   0, 
    128,  63,   0,   0, 128,  63, 
      0,   0, 128,  63, 166, 142, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  56,   0, 
      0,   7,  50,   0,  16,   0, 
      3,   0,   0,   0, 230,  10, 
     16,   0,   0,   0,   0,   0, 
    214,   5,  16,   0,   5,   0, 
      0,   0,  54,   0,   0,   5, 
     18,   0,  16,   0,   0,   0, 
      0,   0,  10,  16,  16,   0, 
      2,   0,   0,   0,  50,   0, 
      0,  10, 194,   0,  16,   0, 
      3,   0,   0,   0,   6,   8, 
     16, 128,  65,   0,   0,   0, 
      5,   0,   0,   0, 166,  14, 
     16,   0,   0,   0,   0,   0, 
      6,   4,  16,   0,   0,   0, 
      0,   0,  56,   0,   0,   8, 
    194,   0,  16,   0,   3,   0, 
      0,   0, 166,  14,  16,   0, 
      3,   0,   0,   0, 166, 142, 
     32,   0,   0,   0,   0,   0, 
      9,   0,   0,   0,  50,   0, 
      0,   9,  98,   0,  16,   0, 
      1,   0,   0,   0, 166,  11, 
     16,   0,   3,   0,   0,   0, 
    166,  11,  16,   0,   0,   0, 
      0,   0,   6,   1,  16,   0, 
      3,   0,   0,   0,  18,   0, 
      0,   1,  54,   0,   0,   8, 
    114,   0,  16,   0,   1,   0, 
      0,   0,   2,  64,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,  21,   0, 
      0,   1,  54,   0,   0,   5, 
    242,  32,  16,   0,   0,   0, 
      0,   0,  70,  14,  16,   0, 
      2,   0,   0,   0,  54,   0, 
      0,   5, 242,  32,  16,   0, 
      1,   0,   0,   0,  70,  30, 
     16,   0,   1,   0,   0,   0, 
     54,   0,   0,   5,  18,  32, 
     16,   0,   2,   0,   0,   0, 
     10,  16,  16,   0,   2,   0, 
      0,   0,  54,   0,   0,   5, 
     34,  32,  16,   0,   2,   0, 
      0,   0,  26,   0,  16,   0, 
      0,   0,   0,   0,  54,   0, 
      0,   5,  66,  32,  16,   0, 
      2,   0,   0,   0,  10,  16, 
     16,   0,   5,   0,   0,   0, 
     54,   0,   0,   5, 130,   0, 
     16,   0,   1,   0,   0,   0, 
     10,  16,  16,   0,   7,   0, 
      0,   0,  54,   0,   0,   5, 
    242,  32,  16,   0,   6,   0, 
      0,   0,  70,  14,  16,   0, 
      1,   0,   0,   0,  62,   0, 
      0,   1,  83,  84,  65,  84, 
    116,   0,   0,   0, 119,   0, 
      0,   0,   6,   0,   0,   0, 
      0,   0,   0,   0,  18,   0, 
      0,   0,  57,   0,   0,   0, 
      4,   0,   0,   0,   5,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  16,   0,   0,   0, 
      9,   0,   0,   0,  11,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0
};
