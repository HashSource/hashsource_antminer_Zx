int *__fastcall sub_49DEC(int *a1)
{
  pthread_t v2; // r0
  int v3; // r5
  int v4; // r4
  int v5; // r12
  int *result; // r0
  signed int v7; // r0
  char *v8; // r3
  char v9; // t1
  int v10; // r7
  int v11; // r5
  char *v12; // r12
  unsigned __int8 *v13; // r2
  int v14; // r3
  char v15; // r1
  char *v16; // r3
  char v17; // r2
  char *v18; // r3
  char v19; // r2
  char *v20; // r3
  char v21; // r2
  int v22; // [sp+Ch] [bp-149E8h]
  char *v23; // [sp+Ch] [bp-149E8h]
  char *v24; // [sp+Ch] [bp-149E8h]
  char *v25; // [sp+Ch] [bp-149E8h]
  int v26; // [sp+10h] [bp-149E4h]
  int v27; // [sp+18h] [bp-149DCh]
  _BYTE v28[3]; // [sp+23h] [bp-149D1h] BYREF
  unsigned __int8 v29; // [sp+26h] [bp-149CEh] BYREF
  char v30; // [sp+27h] [bp-149CDh] BYREF
  _BYTE v31[95]; // [sp+28h] [bp-149CCh] BYREF
  char v32; // [sp+87h] [bp-1496Dh] BYREF
  _BYTE s[1488]; // [sp+88h] [bp-1496Ch] BYREF
  int v34; // [sp+658h] [bp-1439Ch] BYREF
  _BYTE v35[4352]; // [sp+1640h] [bp-133B4h] BYREF
  char v36[74404]; // [sp+2750h] [bp-122A4h] BYREF

  memset(s, 0, sizeof(s));
  v26 = *a1;
  v2 = pthread_self();
  pthread_detach(v2);
  if ( byte_77B70 || byte_75C48 || dword_73504 > 4 )
  {
    snprintf(v36, 0x1000u, "Start A New Asic Response.Chain Id:[%d]", v26);
    sub_385C8(5, v36, 0);
  }
  if ( byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
  {
    snprintf(v36, 0x1000u, "%s %d", "get_asic_response", v26);
    sub_385C8(7, v36, 0);
  }
  memset(v36, 0, (size_t)&loc_122A0);
  v3 = 0;
  memset(v31, 0, 0x5Du);
  v4 = 0;
  v5 = -84428;
LABEL_10:
  while ( 1 )
  {
    result = dword_75C50;
    if ( !*((_BYTE *)&dword_75C50[194] + v26) )
      return result;
    v22 = v5;
    sub_2A8AC();
    v7 = sub_3C2F4((unsigned __int8)v26, s, 0x5D0u);
    v5 = v22;
    if ( v7 > 0 )
    {
      v8 = &v32;
      do
      {
        v9 = *++v8;
        v36[v3++] = v9;
        if ( v3 > 74399 )
          v3 = 0;
      }
      while ( v8 != &s[v7 - 1] );
    }
    if ( v3 != v4 )
    {
      v10 = v4 >= v3 ? 74400 - v4 + v3 : v3 - v4;
      if ( v10 > 2 )
      {
        v27 = v3;
        v11 = v22;
        v12 = &v31[8];
        while ( 1 )
        {
          v13 = v28;
          v29 = 0;
          v14 = v4;
          *(_WORD *)&v36[v11 + 74400] = 0;
          do
          {
            v15 = v36[v14++];
            *++v13 = v15;
            if ( v14 > 74399 )
              v14 = 0;
          }
          while ( v13 != &v29 );
          if ( (unsigned __int8)v36[v11 + 74400] == 170 && v28[2] == 85 )
          {
            if ( (v29 & 0xF0) == 0xE0 )
            {
              if ( v10 <= 92 )
                goto LABEL_29;
              v18 = &v30;
              do
              {
                v19 = v36[v4++];
                *++v18 = v19;
                if ( v4 > 74399 )
                  v4 = 0;
              }
              while ( v18 != &v31[92] );
              v24 = v12;
              sub_49464((int)&v34, (int)v35, (int)v31, 93, v26);
              v10 -= 93;
              v12 = v24;
            }
            else if ( v29 == 204 )
            {
              if ( v10 <= 8 )
              {
LABEL_29:
                v5 = v11;
                v3 = v27;
                goto LABEL_10;
              }
              v20 = &v30;
              do
              {
                v21 = v36[v4++];
                *++v20 = v21;
                if ( v4 > 74399 )
                  v4 = 0;
              }
              while ( v20 != v12 );
              v10 -= 9;
              v25 = v12;
              sub_49A18(v31, 9, (unsigned __int8)v26);
              v12 = v25;
            }
            else
            {
              if ( v10 <= 8 )
                goto LABEL_29;
              v16 = &v30;
              do
              {
                v17 = v36[v4++];
                *++v16 = v17;
                if ( v4 > 74399 )
                  v4 = 0;
              }
              while ( v16 != v12 );
              v10 -= 9;
              v23 = v12;
              sub_49B74((int)v31, 9, v26);
              v12 = v23;
            }
          }
          else
          {
            ++v4;
            --v10;
            if ( v4 > 74399 )
              v4 = 0;
          }
          if ( v10 <= 2 )
            goto LABEL_29;
        }
      }
    }
  }
}
