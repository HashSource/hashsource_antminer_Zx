int __fastcall sub_182A0(_DWORD *a1, int a2)
{
  char *v4; // r1
  int v6; // r2
  int v7; // r1
  int v8; // r3
  const char *v9; // lr
  int v10; // r0
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int *v14; // lr
  int v15; // r0
  int v16; // r1
  int v17; // r2
  int v18; // r3
  int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r1
  int v24; // r2
  int v25; // r3
  struct timeval v26; // [sp+8h] [bp-810h] BYREF
  struct timeval v27; // [sp+10h] [bp-808h] BYREF
  _DWORD dest[512]; // [sp+18h] [bp-800h] BYREF

  if ( *((_BYTE *)a1 + 704) )
  {
    if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      snprintf((char *)dest, 0x800u, "Retrieving block template from pool %s", a1[41]);
      goto LABEL_64;
    }
  }
  else if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
  {
    snprintf((char *)dest, 0x800u, "Testing pool %s", a1[41]);
LABEL_64:
    sub_38438(7, (const char *)dest, 0);
  }
  if ( *((_BYTE *)a1 + 632) )
    goto LABEL_12;
  if ( !off_60078 )
  {
    if ( byte_632F0 || byte_630C0 || dword_60964 > 2 )
    {
      strcpy((char *)dest, "CURL initialisation failed");
      sub_38438(3, (const char *)dest, 0);
      return 0;
    }
    return 0;
  }
  if ( *((_BYTE *)a1 + 99) )
    goto LABEL_8;
  if ( !byte_630C1 )
  {
    *((_BYTE *)a1 + 99) = 0;
    goto LABEL_8;
  }
  if ( byte_632F0 || byte_630C0 || dword_60964 > 6 )
  {
    strcpy((char *)dest, "Probing for GBT support");
    sub_38438(7, (const char *)dest, 0);
    v7 = *((unsigned __int8 *)a1 + 704);
    v8 = (unsigned __int8)byte_630C1;
    *((_BYTE *)a1 + 99) = 0;
    if ( !v7 )
    {
      if ( !*((_BYTE *)a1 + 868) )
      {
        if ( !v8 )
          goto LABEL_8;
        goto LABEL_46;
      }
      if ( !v8 )
        goto LABEL_8;
LABEL_42:
      if ( byte_632F0 || byte_630C0 || dword_60964 > 6 )
      {
        strcpy((char *)dest, "GBT coinbase without append found, switching to GBT solo protocol");
        sub_38438(7, (const char *)dest, 0);
      }
      goto LABEL_8;
    }
    if ( !v8 )
      goto LABEL_8;
LABEL_35:
    if ( !byte_632F0 && !byte_630C0 && dword_60964 <= 6 )
      goto LABEL_8;
    v9 = "GBT coinbase + append support found, switching to GBT protocol";
    goto LABEL_39;
  }
  v6 = *((unsigned __int8 *)a1 + 704);
  *((_BYTE *)a1 + 99) = 0;
  if ( v6 )
    goto LABEL_35;
  if ( *((_BYTE *)a1 + 868) )
    goto LABEL_42;
LABEL_46:
  if ( byte_632F0 || byte_630C0 )
  {
    v9 = "No GBT coinbase + append support found, using getwork protocol";
LABEL_39:
    v10 = *(_DWORD *)v9;
    v11 = *((_DWORD *)v9 + 1);
    v12 = *((_DWORD *)v9 + 2);
    v13 = *((_DWORD *)v9 + 3);
    v14 = (int *)(v9 + 16);
    dest[0] = v10;
    dest[1] = v11;
    dest[2] = v12;
    dest[3] = v13;
    v15 = *v14;
    v16 = v14[1];
    v17 = v14[2];
    v18 = v14[3];
    v14 += 4;
    dest[4] = v15;
    dest[5] = v16;
    dest[6] = v17;
    dest[7] = v18;
    v19 = *v14;
    v20 = v14[1];
    v21 = v14[2];
    v22 = v14[3];
    v14 += 4;
    dest[8] = v19;
    dest[9] = v20;
    dest[10] = v21;
    dest[11] = v22;
    v23 = v14[1];
    v24 = v14[2];
    v25 = v14[3];
    dest[12] = *v14;
    dest[13] = v23;
    dest[14] = v24;
    LOWORD(dest[15]) = v25;
    BYTE2(dest[15]) = BYTE2(v25);
    sub_38438(7, (const char *)dest, 0);
    goto LABEL_8;
  }
  if ( dword_60964 > 6 )
  {
    v9 = "No GBT coinbase + append support found, using getwork protocol";
    goto LABEL_39;
  }
LABEL_8:
  sub_2B13C(&v26);
  sub_2B13C(&v27);
  v4 = (char *)a1[142];
  if ( v4 && !byte_612D8 )
  {
    if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      snprintf((char *)dest, 0x800u, "Testing pool %d stratum %s", *a1, (const char *)a1[142]);
      sub_38438(7, (const char *)dest, 0);
      v4 = (char *)a1[142];
    }
    sub_2B358((int)a1, v4);
    if ( sub_2B43C((const char *)a1[142], a1 + 148, (char **)a1 + 144) )
    {
      if ( sub_2C29C(a1) )
      {
        if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
        {
          snprintf((char *)dest, 0x800u, "Switching pool %d %s to %s", *a1, (const char *)a1[41], (const char *)a1[142]);
          sub_38438(7, (const char *)dest, 0);
        }
        if ( !a1[41] )
          a1[41] = _strdup((const char *)a1[142]);
        goto LABEL_11;
      }
    }
  }
  if ( !sub_2C29C(a1) )
  {
    if ( byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
    {
      snprintf((char *)dest, 0x800u, "FAILED to retrieve work from pool %u %s", *a1, (const char *)a1[41]);
      sub_38438(7, (const char *)dest, 0);
    }
    if ( !a2 && !*((_BYTE *)a1 + 97) && (byte_632F0 || byte_630C0 || dword_60964 > 3) )
    {
      snprintf((char *)dest, 0x800u, "Pool %u slow/down or URL or credentials invalid", *a1);
      sub_38438(4, (const char *)dest, 0);
    }
    return 0;
  }
LABEL_11:
  *((_BYTE *)a1 + 632) = 1;
LABEL_12:
  if ( sub_17E64((int)a1, (_BYTE *)a1 + 634) )
    return *((unsigned __int8 *)a1 + 633);
  if ( sub_2C29C(a1) && sub_2E9B0((pthread_mutex_t *)a1) )
  {
    sub_2C1C4((int)a1);
    byte_64219 = 1;
    if ( pthread_create(a1 + 166, 0, (void *(*)(void *))sub_21AB0, a1) )
    {
      strcpy((char *)dest, "Failed to create stratum sthread");
      sub_38438(3, (const char *)dest, 1);
      sub_16724(1);
    }
    if ( pthread_create(a1 + 167, 0, (void *(*)(void *))sub_1FC10, a1) )
    {
      strcpy((char *)dest, "Failed to create stratum rthread");
      sub_38438(3, (const char *)dest, 1);
      sub_16724(1);
    }
    return 1;
  }
  else
  {
    sub_2C1C4((int)a1);
    sub_1822C((int)a1, (_BYTE *)a1 + 634);
    return 0;
  }
}
