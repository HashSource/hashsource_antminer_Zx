void __fastcall __noreturn sub_3BC80(unsigned __int8 *a1)
{
  pthread_t v1; // r0
  int v2; // r3
  int v3; // r2
  int v4; // r3
  void **v5; // r6
  void *v6; // r4
  int v7; // r4
  _WORD *v8; // r2
  int v9; // r1
  unsigned int v10; // r3
  int v11; // t1
  int v12; // r4
  unsigned __int8 *v13; // r5
  int v14; // r3
  int v15; // r10
  int v16; // r2
  int i; // r3
  int v18; // r3
  char *v19; // r2
  unsigned int v20; // r1
  int v21; // r1
  _BYTE *v22; // r12
  unsigned int v23; // r2
  char *v24; // r0
  unsigned int v25; // r3
  char v26; // r6
  char v27; // lr
  int v28; // [sp+10h] [bp-94Ch]
  void **src; // [sp+30h] [bp-92Ch]
  int v31; // [sp+34h] [bp-928h]
  int *v32; // [sp+48h] [bp-914h]
  struct timeval v33; // [sp+54h] [bp-908h] BYREF
  struct timeval v34; // [sp+5Ch] [bp-900h] BYREF
  char v35[80]; // [sp+64h] [bp-8F8h] BYREF
  char v36[4]; // [sp+B4h] [bp-8A8h] BYREF
  _BYTE v37[20]; // [sp+F0h] [bp-86Ch] BYREF
  _WORD v38[42]; // [sp+104h] [bp-858h] BYREF
  char v39[2052]; // [sp+158h] [bp-804h] BYREF

  v1 = pthread_self();
  pthread_detach(v1);
  if ( !byte_630C1 )
  {
    v28 = a1[156];
    v32 = *(int **)(a1 + 703);
    v31 = v28 + 40;
    goto LABEL_10;
  }
  if ( byte_632F0 || byte_630C0 || dword_60964 > 6 )
  {
    strcpy(v39, "Start To Fill Work!");
    sub_38438(7, v39, 0);
    v2 = a1[156];
    v32 = *(int **)(a1 + 703);
    if ( !byte_630C1 )
      goto LABEL_9;
    if ( byte_632F0 || byte_630C0 )
    {
LABEL_54:
      v28 = v2;
      v31 = v2 + 40;
      snprintf(v39, 0x800u, "Start To Fill Work!ChainIndex:[%d]", v2);
      sub_38438(7, v39, 0);
      goto LABEL_10;
    }
  }
  else
  {
    v2 = a1[156];
    v32 = *(int **)(a1 + 703);
  }
  if ( dword_60964 <= 6 )
  {
LABEL_9:
    v28 = v2;
    v31 = v2 + 40;
LABEL_10:
    if ( !byte_63150 )
      goto LABEL_50;
    while ( 1 )
    {
      sub_2B13C(&v33);
      v3 = v33.tv_sec - v34.tv_sec;
      v4 = v33.tv_usec - v34.tv_usec;
      if ( v33.tv_usec - v34.tv_usec < 0 )
      {
        --v3;
        v4 += 1000000;
      }
      if ( !byte_630C8[v28] && v4 / 1000 + 1000 * v3 < (unsigned int)(1000 * LODWORD(flt_C4BEC)) )
      {
LABEL_50:
        sub_2B21C();
        goto LABEL_10;
      }
      sub_2B13C(&v34);
      do
      {
        pthread_mutex_lock(&stru_63138);
        v5 = (void **)sub_244C4((int)v32, *v32);
        pthread_mutex_unlock(&stru_63138);
      }
      while ( !v5 );
      v6 = v5[85];
      byte_630C8[v28] = 0;
      src = v5;
      memset(v38, 0, 0x52u);
      v7 = (unsigned __int8)v6 & 0x7F;
      memcpy(v35, v5, sizeof(v35));
      sub_2F560(v35, 80);
      memcpy(&v38[2], &v35[4], 0x4Cu);
      v8 = v38;
      v9 = 32;
      v10 = 0xFFFF;
      LOBYTE(v38[1]) = v7;
      qmemcpy(v38, " P", 2);
      while ( 1 )
      {
        v10 = (unsigned __int16)(*(_WORD *)&aBitmainL3Detec_0[2 * (v9 ^ (v10 >> 8)) + 928] ^ ((_WORD)v10 << 8));
        if ( v8 == (_WORD *)((char *)&v38[39] + 1) )
          break;
        v11 = *((unsigned __int8 *)v8 + 1);
        v8 = (_WORD *)((char *)v8 + 1);
        v9 = v11;
      }
      v12 = v7 + 46;
      v13 = &a1[4 * v12];
      v38[40] = (v10 >> 8) | ((_WORD)v10 << 8);
      pthread_mutex_lock(&stru_63138);
      if ( *(_DWORD *)(v13 + 7) )
      {
        sub_152B8(*(void ***)(v13 + 7));
        v14 = *((_DWORD *)v13 + 2);
        v13[7] = 0;
        *((_DWORD *)v13 + 2) = v14 & 0xFF000000;
      }
      *(_DWORD *)&a1[4 * v12 + 7] = sub_19E18((int)v5, 0);
      pthread_mutex_unlock(&stru_63138);
      if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
      {
        snprintf(v39, 0x800u, "ChainID[%d] Wirte Work", v28);
        sub_38438(7, v39, 0);
      }
      v15 = 0;
      sub_3BBBC(*(_DWORD *)&a1[4 * v31 + 1], v38, 0x52u);
      byte_630F8 = 1;
      do
      {
        v16 = 1;
        for ( i = 0; i != 60 && i != 77; ++i )
        {
          if ( i == 78 )
          {
            v37[18] = 0;
          }
          else
          {
            v36[i] = 32;
            if ( v16 == 80 )
              goto LABEL_36;
          }
LABEL_33:
          ++v16;
        }
        v36[i] = 124;
        if ( v16 != 80 )
          goto LABEL_33;
LABEL_36:
        v18 = 28;
        v19 = &v35[79];
        do
        {
          v20 = (unsigned int)(v15 * 2) >> v18;
          v18 -= 4;
          *++v19 = aBitmainL3Detec_0[(v20 & 0xF) + 1480];
        }
        while ( v18 != -4 );
        v21 = 0;
        v22 = v37;
        v23 = 0;
        do
        {
          v24 = &v39[(v23 >> 3) + 2048 + v21];
          v21 += 3;
          if ( v23 + v15 * 2 > 0x51 )
            break;
          v25 = *((unsigned __int8 *)&v38[v15] + v23++);
          v26 = aBitmainL3Detec_0[(v25 & 0xF) + 1480];
          v27 = aBitmainL3Detec_0[(v25 >> 4) + 1480];
          if ( v25 - 32 > 0x5E )
            LOBYTE(v25) = 46;
          *(v24 - 2200) = v26;
          *(v24 - 2201) = v27;
          *++v22 = v25;
        }
        while ( v23 != 16 );
        if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
        {
          snprintf(v39, 0x800u, "%s", v36);
          sub_38438(7, v39, 0);
        }
        v15 += 8;
      }
      while ( v15 != 48 );
      sub_2B13C((struct timeval *)&dword_63154);
      sub_2B21C();
      sub_152B8(src);
      if ( !byte_63150 )
        goto LABEL_50;
    }
  }
  goto LABEL_54;
}
