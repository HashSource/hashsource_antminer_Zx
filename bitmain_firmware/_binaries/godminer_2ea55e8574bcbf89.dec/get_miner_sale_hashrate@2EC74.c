int get_miner_sale_hashrate()
{
  double v0; // d0
  int v1; // r4
  char *all_created_runtime; // r5
  double v3; // d8
  int v4; // r7
  char *v5; // r5
  int v6; // t1
  int result; // r0
  char *v8; // r4
  char *v9; // r3
  int v11; // r0
  unsigned int v12; // r4
  int v13; // [sp+0h] [bp-94h] BYREF
  unsigned int v14; // [sp+4h] [bp-90h]
  double v15; // [sp+8h] [bp-8Ch] BYREF
  char v16[12]; // [sp+18h] [bp-7Ch] BYREF
  _WORD v17[8]; // [sp+24h] [bp-70h] BYREF
  char v18; // [sp+35h] [bp-5Fh]
  char v19; // [sp+46h] [bp-4Eh] BYREF
  char v20[2]; // [sp+56h] [bp-3Eh] BYREF
  char v21[24]; // [sp+58h] [bp-3Ch] BYREF

  v1 = 0;
  v13 = 0;
  all_created_runtime = (char *)get_all_created_runtime(&v13);
  v14 = 1;
  get_miner_elapsed_time();
  v3 = v0;
  get_miner_6060info_status(v17);
  v15 = 0.0;
  if ( v13 > 0 )
  {
    v5 = all_created_runtime - 4;
    v4 = 0;
    do
    {
      v6 = *((_DWORD *)v5 + 1);
      v5 += 4;
      ++v1;
      v4 |= (*(int (**)(void))(v6 + 136))();
    }
    while ( v13 > v1 );
  }
  else
  {
    v4 = 0;
  }
  read_system_status_from_monitor((int)v21);
  freq_scan_status = 1;
  if ( (unsigned int)(opt_algo - 6) <= 1 )
    v3 = v0 - 2700.0;
  if ( v3 < 1.0 )
  {
    freq_scan_status = 0;
    return 0;
  }
  if ( !v4 )
  {
    if ( !LOBYTE(v17[0]) )
      goto LABEL_11;
LABEL_42:
    freq_scan_status = 2;
    strcpy((char *)search_failed_info, "P:1");
    if ( !v18 )
      goto LABEL_12;
    goto LABEL_41;
  }
  freq_scan_status = 2;
  strcpy((char *)search_failed_info, "R:1");
  if ( LOBYTE(v17[0]) )
    goto LABEL_42;
LABEL_11:
  if ( v18 )
  {
LABEL_41:
    freq_scan_status = 2;
    strcpy((char *)search_failed_info, "F:1");
  }
LABEL_12:
  v8 = &v19;
  do
  {
    while ( 1 )
    {
      v9 = &v8[-34 - (_DWORD)v17];
      if ( *v8++ )
        break;
      if ( v8 == v20 )
        goto LABEL_16;
    }
    freq_scan_status = 2;
    strcpy((char *)search_failed_info, "R:1");
    snprintf((char *)search_failed_info, 0x100u, "J%d:1", v9);
  }
  while ( v8 != v20 );
LABEL_16:
  v11 = frontend_runtime_instance();
  format_hashrate_double(*(const char **)(*(_DWORD *)(v11 + 72) + 16), &v15, v16);
  v12 = v14;
  result = sub_12DBE0((int)v15, v14) * v12;
  switch ( opt_algo )
  {
    case 6:
      result -= 50;
      if ( result > 3729 )
        return 3780;
LABEL_28:
      if ( (unsigned int)(result - 3630) <= 0x63 )
        return 3680;
      if ( (unsigned int)(result - 3530) <= 0x63 )
        return 3580;
      if ( (unsigned int)(result - 3430) <= 0x63 )
        return 3480;
      if ( (unsigned int)(result - 3330) <= 0x63 )
        return 3380;
      if ( (unsigned int)(result - 3230) <= 0x63 )
        return 3280;
      if ( (unsigned int)(result - 3130) <= 0x63 )
        return 3180;
      return sub_12DBE0(result, v12) * v12;
    case 7:
      result = sub_12DBE0(result, v12) * v12 - 50;
      if ( result > 3729 )
        return 3780;
      goto LABEL_28;
    case 9:
      if ( result >= 860 )
        return 860;
      if ( (unsigned int)(result - 840) <= 0x13 )
        return 840;
      if ( (unsigned int)(result - 820) <= 0x13 )
        return 820;
      if ( (unsigned int)(result - 800) <= 0x13 )
        return 800;
      if ( (unsigned int)(result - 780) <= 0x13 )
        return 780;
      return sub_12DBE0(result, v12) * v12;
    case 1:
      if ( result > 65999 )
        return (int)&elf_hash_bucket[5];
      if ( (unsigned int)(result - 63500) <= 0x9C3 )
        return 63500;
      if ( (unsigned int)(result - 60500) <= 0xBB7 )
        return 60500;
      if ( (unsigned int)(result - 58000) <= 0x9C3 )
        return 58000;
      return sub_12DBE0(result, v12) * v12;
    case 2:
      if ( result > 172999 )
        return (int)&loc_2A3C8;
      if ( (unsigned int)(result - 166000) <= 0x1B57 )
        return (int)sub_28870;
      return sub_12DBE0(result, v12) * v12;
    case 5:
      if ( result <= 1859 )
      {
        if ( (unsigned int)(result - 1770) <= 0x59 )
          return 1770;
        return sub_12DBE0(result, v12) * v12;
      }
      return 1860;
  }
  return result;
}
