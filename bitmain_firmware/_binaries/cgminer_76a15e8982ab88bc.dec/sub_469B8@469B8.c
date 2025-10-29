int sub_469B8()
{
  unsigned __int64 v0; // d8
  _QWORD *v1; // r9
  int v2; // r11
  int i; // r10
  unsigned int v5; // r3
  int k; // r4
  unsigned int v8; // r3
  unsigned __int8 *v9; // r5
  int v10; // r4
  unsigned __int8 *v11; // r5
  __int64 v12; // r6
  int v13; // lr
  int j; // r4
  int v15; // t1
  int v16; // r12
  double v17; // r0
  unsigned __int8 *v18; // r5
  int v19; // lr
  int v20; // t1
  int v21; // r12
  double v22; // r0
  __int64 v23; // [sp+10h] [bp-1014h]
  char s[4100]; // [sp+20h] [bp-1004h] BYREF

  v0 = 0;
  v1 = &unk_75F90;
  v2 = 631471;
  for ( i = 0; i != 4; ++i )
  {
    while ( !*(unsigned __int8 *)++v2 )
    {
LABEL_7:
      ++i;
      ++v1;
      if ( i == 4 )
        return sub_467E4(v0, byte_759C0, 0x10u, 6, 0);
    }
    if ( !byte_75FB0[i] )
    {
      v5 = (unsigned __int8)(byte_75FB4[i] + 1);
      byte_75FB4[i] = v5;
      if ( v5 > 3 || byte_75C7C )
      {
        *v1 = 0;
        sub_467E4(0, &byte_78ED0[16 * i], 0x10u, 6, 1);
      }
      goto LABEL_7;
    }
    if ( byte_75FB0[i] > 2u )
    {
      v9 = &byte_75FB0[512 * i];
      v10 = (unsigned __int8)byte_739AC;
      if ( byte_739AC )
      {
        v11 = v9 + 516;
        v12 = 0;
        v13 = (unsigned __int8)byte_75C49;
        for ( j = 0; j != 3; ++j )
        {
          v15 = *((_DWORD *)v11 + 1);
          v11 += 4;
          v16 = v15 & 0x7FFFFFFF;
          v12 += v15 & 0x7FFFFFFF;
          if ( v13 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
          {
            snprintf(s, 0x1000u, "%s: RT g_HASH_RATE_reg_value[%d][%d] = 0x%08x", "calculate_hash_rate", i, j, v16);
            sub_385C8(7, s, 0);
            v13 = (unsigned __int8)byte_75C49;
          }
        }
        if ( v13 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
        {
          LODWORD(v17) = sub_59F08(v12);
          snprintf(s, 0x1000u, "%s: chain%d RT hash rate is %0.2fGHz/s", "calculate_hash_rate", i, v17 / 1000000.0);
          sub_385C8(7, s, 0);
        }
        byte_75FB4[i] = 0;
        *v1 = 1000000 * v12;
        sub_467E4(1000000 * v12, &byte_78ED0[16 * i], 0x10u, 6, 0);
        v0 += *v1;
      }
      else
      {
        v18 = v9 + 516;
        v19 = (unsigned __int8)byte_75C49;
        v23 = 0;
        do
        {
          v20 = *((_DWORD *)v18 + 1);
          v18 += 4;
          v21 = v20 & 0x7FFFFFFF;
          v23 += v20 & 0x7FFFFFFF;
          if ( v19 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
          {
            snprintf(s, 0x1000u, "%s: avg g_HASH_RATE_reg_value[%d][%d] = 0x%08x", "calculate_hash_rate", i, v10, v21);
            sub_385C8(7, s, 0);
            v19 = (unsigned __int8)byte_75C49;
          }
          ++v10;
        }
        while ( v10 != 3 );
        if ( v19 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
        {
          LODWORD(v22) = sub_59F08(v23);
          snprintf(s, 0x1000u, "%s: chain%d avg hash rate is %0.2fGHz/s", "calculate_hash_rate", i, v22 / 1000000.0);
          sub_385C8(7, s, 0);
        }
        v0 += *v1;
        byte_75FB4[i] = 0;
      }
    }
    else
    {
      for ( k = 0; k != 3; ++k )
      {
        if ( !byte_75FB4[128 * i + 4] && !byte_75C7C && byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
        {
          snprintf(
            s,
            0x1000u,
            "%s: Chain%d ASIC%d didn't send back HASH_RATE register value",
            "calculate_hash_rate",
            i,
            k);
          sub_385C8(7, s, 0);
        }
      }
      v8 = (unsigned __int8)(byte_75FB4[i] + 1);
      byte_75FB4[i] = v8;
      if ( v8 > 3 || byte_75C7C )
      {
        *v1 = 0;
        sub_467E4(0, &byte_78ED0[16 * i], 0x10u, 6, 1);
      }
      v0 += *v1;
    }
    ++v1;
  }
  return sub_467E4(v0, byte_759C0, 0x10u, 6, 0);
}
