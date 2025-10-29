int __fastcall sub_5A0C0(__int64 a1, __int64 a2)
{
  __int64 v2; // kr00_8
  __int64 v3; // kr08_8
  int v4; // r4
  unsigned int v5; // r6
  unsigned int v6; // r9
  __int64 v7; // r10
  unsigned int v8; // r3
  unsigned int v9; // r5
  int v10; // r0
  unsigned int v11; // r3
  unsigned int v12; // r2
  int v13; // r8
  unsigned int v14; // r0
  unsigned int v15; // r10
  unsigned int v16; // r7
  unsigned int v17; // r12
  unsigned int v18; // r6
  int v19; // r12
  unsigned int v20; // r3
  unsigned int v21; // r7
  int v22; // r5
  unsigned int v23; // r8
  unsigned int v24; // r7
  int v25; // r0
  unsigned int v26; // r3
  unsigned int v27; // r2
  int v28; // r11
  unsigned int v29; // r0
  unsigned int v30; // r1
  unsigned int v31; // r9
  unsigned int v32; // r5
  unsigned int v33; // r8
  int v34; // r0
  unsigned int v35; // r3
  unsigned int v36; // r2
  int v37; // r7
  unsigned int v38; // r0
  unsigned int v39; // r10
  unsigned int v40; // r9
  unsigned int v41; // r12
  unsigned int v42; // r6
  unsigned int v43; // r10
  bool v44; // cf
  unsigned int v45; // r6
  unsigned int v46; // r7
  unsigned int v47; // r9
  int v48; // r0
  unsigned int v49; // r1
  unsigned int v50; // r2
  int v51; // r3
  unsigned int v52; // r0
  unsigned int v53; // r1
  unsigned int v54; // r11
  unsigned int v55; // r12
  unsigned int v56; // r11
  unsigned __int64 v57; // r2
  bool v58; // r3
  __int64 v59; // r0
  unsigned int v61; // [sp+4h] [bp-8h]

  v2 = a1;
  v3 = a2;
  if ( a1 < 0 )
  {
    v4 = -1;
    v2 = -a1;
  }
  else
  {
    v4 = 0;
  }
  if ( a2 < 0 )
  {
    v4 = ~v4;
    v3 = -a2;
  }
  v5 = v3;
  v6 = HIDWORD(v2);
  LODWORD(v7) = v2;
  if ( !HIDWORD(v3) )
  {
    if ( (unsigned int)v3 > HIDWORD(v2) )
    {
      v8 = __clz(v3);
      if ( v8 )
      {
        v5 = (_DWORD)v3 << v8;
        LODWORD(v7) = (_DWORD)v2 << v8;
        v6 = ((unsigned int)v2 >> (32 - v8)) | (HIDWORD(v2) << v8);
      }
      v9 = HIWORD(v5);
      v10 = v6 / HIWORD(v5);
      v11 = WORD1(v7) | ((v6 % HIWORD(v5)) << 16);
      v12 = (unsigned __int16)v5 * v10;
      if ( v11 < v12 )
      {
        v44 = __CFADD__(v11, v5);
        v11 += v5;
        v13 = v10 - 1;
        if ( !v44 && v11 < v12 )
        {
          v13 = v10 - 2;
          v11 += v5;
        }
      }
      else
      {
        v13 = v6 / v9;
      }
      v14 = (v11 - v12) / v9;
      v15 = (unsigned __int16)v7 | (((v11 - v12) % v9) << 16);
      v16 = (unsigned __int16)v5 * v14;
      if ( v15 < v16 )
      {
        v44 = __CFADD__(v15, v5);
        v18 = v15 + v5;
        v17 = v14 - 1;
        if ( !v44 && v18 < v16 )
          v17 = v14 - 2;
      }
      else
      {
        v17 = (v11 - v12) / v9;
      }
      v19 = v17 | (v13 << 16);
      goto LABEL_70;
    }
    if ( !(_DWORD)v3 )
      v5 = 1 / 0u;
    v20 = __clz(v5);
    if ( v20 )
    {
      v5 <<= v20;
      HIDWORD(v7) = HIDWORD(v2) >> (32 - v20);
      v23 = HIWORD(v5);
      v24 = ((unsigned int)v2 >> (32 - v20)) | (HIDWORD(v2) << v20);
      LODWORD(v7) = (_DWORD)v2 << v20;
      v25 = HIDWORD(v7) / HIWORD(v5);
      v26 = HIWORD(v24) | ((HIDWORD(v7) % HIWORD(v5)) << 16);
      v27 = (unsigned __int16)v5 * v25;
      if ( v26 < v27 )
      {
        v44 = __CFADD__(v26, v5);
        v26 += v5;
        v28 = v25 - 1;
        if ( !v44 && v26 < v27 )
        {
          v28 = v25 - 2;
          v26 += v5;
        }
      }
      else
      {
        v28 = HIDWORD(v7) / v23;
      }
      v29 = (v26 - v27) / v23;
      v30 = (unsigned __int16)v24 | (((v26 - v27) % v23) << 16);
      v31 = (unsigned __int16)v5 * v29;
      if ( v30 < v31 )
      {
        v44 = __CFADD__(v30, v5);
        v30 += v5;
        v32 = v29 - 1;
        if ( !v44 && v30 < v31 )
        {
          v32 = v29 - 2;
          v30 += v5;
        }
      }
      else
      {
        v32 = (v26 - v27) / v23;
      }
      v21 = v30 - v31;
      v22 = v32 | (v28 << 16);
    }
    else
    {
      v21 = HIDWORD(v2) - v5;
      v22 = 1;
    }
    v33 = HIWORD(v5);
    v34 = v21 / HIWORD(v5);
    HIDWORD(v7) = v21 % HIWORD(v5);
    v35 = v7 >> 16;
    v36 = (unsigned __int16)v5 * v34;
    if ( v35 < v36 )
    {
      v44 = __CFADD__(v35, v5);
      v35 += v5;
      v37 = v34 - 1;
      if ( !v44 && v35 < v36 )
      {
        v37 = v34 - 2;
        v35 += v5;
      }
    }
    else
    {
      v37 = v21 / v33;
    }
    v38 = (v35 - v36) / v33;
    v39 = (unsigned __int16)v7 | (((v35 - v36) % v33) << 16);
    v40 = (unsigned __int16)v5 * v38;
    if ( v39 < v40 )
    {
      v44 = __CFADD__(v39, v5);
      v42 = v39 + v5;
      v41 = v38 - 1;
      if ( !v44 && v42 < v40 )
        v41 = v38 - 2;
    }
    else
    {
      v41 = (v35 - v36) / v33;
    }
    v19 = v41 | (v37 << 16);
    goto LABEL_73;
  }
  if ( HIDWORD(v3) > HIDWORD(v2) )
  {
    v22 = 0;
LABEL_72:
    v19 = 0;
    goto LABEL_73;
  }
  v43 = __clz(HIDWORD(v3));
  if ( !v43 )
  {
    v44 = HIDWORD(v2) >= HIDWORD(v3);
    if ( HIDWORD(v2) <= HIDWORD(v3) )
      v44 = (unsigned int)v2 >= (unsigned int)v3;
    if ( v44 )
    {
      v19 = 1;
      v22 = 0;
      goto LABEL_73;
    }
    v22 = 0;
    goto LABEL_72;
  }
  v45 = ((unsigned int)v3 >> (32 - v43)) | (HIDWORD(v3) << v43);
  v46 = ((unsigned int)v2 >> (32 - v43)) | (HIDWORD(v2) << v43);
  v47 = HIWORD(v45);
  v61 = HIDWORD(v2) >> (32 - v43);
  v48 = v61 / HIWORD(v45);
  v49 = HIWORD(v46) | ((v61 % HIWORD(v45)) << 16);
  v50 = (unsigned __int16)v45 * v48;
  if ( v49 < v50 )
  {
    v44 = __CFADD__(v49, v45);
    v49 += v45;
    v51 = v48 - 1;
    if ( !v44 && v49 < v50 )
    {
      v51 = v48 - 2;
      v49 += v45;
    }
  }
  else
  {
    v51 = v61 / v47;
  }
  v52 = (v49 - v50) / v47;
  v53 = (unsigned __int16)v46 | (((v49 - v50) % v47) << 16);
  v54 = (unsigned __int16)v45 * v52;
  if ( v53 < v54 )
  {
    v44 = __CFADD__(v53, v45);
    v53 += v45;
    v55 = v52 - 1;
    if ( !v44 && v53 < v54 )
    {
      v55 = v52 - 2;
      v53 += v45;
    }
  }
  else
  {
    v55 = v52;
  }
  v19 = v55 | (v51 << 16);
  v56 = v53 - v54;
  v57 = (unsigned int)v19 * (unsigned __int64)(unsigned int)((_DWORD)v3 << v43);
  if ( HIDWORD(v57) > v56
    || ((v58 = HIDWORD(v57) == v56, (unsigned int)v57 > (_DWORD)v2 << v43) ? (v22 = v58) : (v22 = 0), v22) )
  {
    --v19;
LABEL_70:
    v22 = 0;
  }
LABEL_73:
  LODWORD(v59) = v19;
  if ( v4 )
    return -__SPAIR64__(v22, v19);
  return v59;
}
