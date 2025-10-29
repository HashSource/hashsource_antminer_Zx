unsigned int __fastcall sub_5D160(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // r4
  unsigned int v6; // r7
  unsigned int v7; // r10
  unsigned int v8; // r3
  unsigned int v9; // r5
  int v10; // r0
  unsigned int v11; // r3
  unsigned int v12; // r2
  int v13; // r6
  unsigned int v14; // r0
  unsigned int v15; // r7
  unsigned int v16; // r8
  unsigned int v17; // r3
  unsigned int v18; // r4
  unsigned int result; // r0
  unsigned int v20; // r3
  unsigned int v21; // r10
  unsigned int v22; // r6
  unsigned int v23; // r8
  unsigned int v24; // r0
  unsigned int v25; // r3
  unsigned int v26; // r2
  unsigned int v27; // r1
  unsigned int v28; // r10
  unsigned int v29; // r6
  int v30; // r0
  unsigned int v31; // r3
  unsigned int v32; // r2
  int v33; // r10
  unsigned int v34; // r0
  unsigned int v35; // r7
  unsigned int v36; // r8
  unsigned int v37; // r3
  unsigned int v38; // r4
  unsigned int v39; // r7
  bool v40; // cf
  unsigned int v41; // r11
  unsigned int v42; // r4
  unsigned int v43; // r5
  unsigned int v44; // r10
  int v45; // r0
  unsigned int v46; // r12
  unsigned int v47; // r3
  int v48; // r11
  unsigned int v49; // r0
  unsigned int v50; // r1
  unsigned int v51; // r9
  unsigned int v52; // r3
  unsigned int v53; // r9
  unsigned __int64 v54; // r2
  _BOOL4 v55; // r5

  v5 = a3;
  v6 = a1;
  v7 = a2;
  if ( !a4 )
  {
    if ( a3 <= a2 )
    {
      if ( !a3 )
        v5 = 1 / 0u;
      v20 = __clz(v5);
      if ( v20 )
      {
        v5 <<= v20;
        v6 = a1 << v20;
        v22 = HIWORD(v5);
        v23 = (a1 >> (32 - v20)) | (a2 << v20);
        v24 = (a2 >> (32 - v20)) / HIWORD(v5);
        v25 = HIWORD(v23) | (((a2 >> (32 - v20)) % HIWORD(v5)) << 16);
        v26 = (unsigned __int16)v5 * v24;
        if ( v25 < v26 )
        {
          v40 = __CFADD__(v25, v5);
          v25 += v5;
          if ( !v40 && v25 < v26 )
            v25 += v5;
        }
        v27 = (unsigned __int16)v23 | (((v25 - v26) % v22) << 16);
        v28 = (unsigned __int16)v5 * ((v25 - v26) / v22);
        if ( v27 < v28 )
        {
          v40 = __CFADD__(v27, v5);
          v27 += v5;
          if ( !v40 && v27 < v28 )
            v27 += v5;
        }
        v21 = v27 - v28;
      }
      else
      {
        v21 = a2 - v5;
      }
      v29 = HIWORD(v5);
      v30 = v21 / HIWORD(v5);
      v31 = HIWORD(v6) | ((v21 % HIWORD(v5)) << 16);
      v32 = (unsigned __int16)v5 * v30;
      if ( v31 < v32 )
      {
        v40 = __CFADD__(v31, v5);
        v31 += v5;
        v33 = v30 - 1;
        if ( !v40 && v31 < v32 )
        {
          v33 = v30 - 2;
          v31 += v5;
        }
      }
      else
      {
        v33 = v21 / v29;
      }
      v34 = (v31 - v32) / v29;
      v35 = (unsigned __int16)v6 | (((v31 - v32) % v29) << 16);
      v36 = (unsigned __int16)v5 * v34;
      if ( v35 < v36 )
      {
        v40 = __CFADD__(v35, v5);
        v38 = v35 + v5;
        v37 = v34 - 1;
        if ( !v40 && v38 < v36 )
          v37 = v34 - 2;
      }
      else
      {
        v37 = (v31 - v32) / v29;
      }
      return v37 | (v33 << 16);
    }
    else
    {
      v8 = __clz(a3);
      if ( v8 )
      {
        v5 = a3 << v8;
        v6 = a1 << v8;
        v7 = (a1 >> (32 - v8)) | (a2 << v8);
      }
      v9 = HIWORD(v5);
      v10 = v7 / HIWORD(v5);
      v11 = HIWORD(v6) | ((v7 % HIWORD(v5)) << 16);
      v12 = (unsigned __int16)v5 * v10;
      if ( v11 < v12 )
      {
        v40 = __CFADD__(v11, v5);
        v11 += v5;
        v13 = v10 - 1;
        if ( !v40 && v11 < v12 )
        {
          v13 = v10 - 2;
          v11 += v5;
        }
      }
      else
      {
        v13 = v7 / v9;
      }
      v14 = (v11 - v12) / v9;
      v15 = (unsigned __int16)v6 | (((v11 - v12) % v9) << 16);
      v16 = (unsigned __int16)v5 * v14;
      if ( v15 < v16 )
      {
        v40 = __CFADD__(v15, v5);
        v18 = v15 + v5;
        v17 = v14 - 1;
        if ( !v40 && v18 < v16 )
          v17 = v14 - 2;
      }
      else
      {
        v17 = (v11 - v12) / v9;
      }
      return v17 | (v13 << 16);
    }
  }
  if ( a4 > a2 )
    return 0;
  v39 = __clz(a4);
  if ( !v39 )
  {
    v40 = a2 >= a4;
    if ( a2 <= a4 )
      return a1 >= a3;
    return v40;
  }
  v41 = a2 >> (32 - v39);
  v42 = (a3 >> (32 - v39)) | (a4 << v39);
  v43 = (a1 >> (32 - v39)) | (a2 << v39);
  v44 = HIWORD(v42);
  v45 = v41 / HIWORD(v42);
  v46 = HIWORD(v43) | ((v41 % HIWORD(v42)) << 16);
  v47 = (unsigned __int16)v42 * v45;
  if ( v46 < v47 )
  {
    v40 = __CFADD__(v46, v42);
    v46 += v42;
    v48 = v45 - 1;
    if ( !v40 && v46 < v47 )
    {
      v48 = v45 - 2;
      v46 += v42;
    }
  }
  else
  {
    v48 = v41 / v44;
  }
  v49 = (v46 - v47) / v44;
  v50 = (unsigned __int16)v43 | (((v46 - v47) % v44) << 16);
  v51 = (unsigned __int16)v42 * v49;
  if ( v50 < v51 )
  {
    v40 = __CFADD__(v50, v42);
    v50 += v42;
    v52 = v49 - 1;
    if ( !v40 && v50 < v51 )
    {
      v52 = v49 - 2;
      v50 += v42;
    }
  }
  else
  {
    v52 = (v46 - v47) / v44;
  }
  result = v52 | (v48 << 16);
  v53 = v50 - v51;
  v54 = result * (unsigned __int64)(a3 << v39);
  if ( HIDWORD(v54) > v53 || ((unsigned int)v54 > a1 << v39 ? (v55 = HIDWORD(v54) == v53) : (v55 = 0), v55) )
    --result;
  return result;
}
