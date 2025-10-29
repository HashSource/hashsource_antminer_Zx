void *__fastcall get_asic_response(void *arg)
{
  int v1; // r7
  uint32_t v3; // r9
  pthread_t v4; // r0
  int v5; // r8
  int v6; // r4
  signed int v7; // r0
  uint8_t *v8; // r3
  char v9; // t1
  unsigned __int8 *v10; // r2
  int v11; // r3
  char v12; // r1
  uint8_t *v13; // r3
  char v14; // r2
  uint8_t *v15; // r3
  char v16; // r2
  uint8_t *v17; // r3
  char v18; // r2
  unsigned __int8 header[3]; // [sp+14h] [bp-149D0h] BYREF
  char v21; // [sp+17h] [bp-149CDh] BYREF
  uint8_t tmp[96]; // [sp+18h] [bp-149CCh] BYREF
  uint8_t receive_buf[1488]; // [sp+78h] [bp-1496Ch] BYREF
  nonce_rb_format g_nonce[3][1]; // [sp+648h] [bp-1439Ch] BYREF
  uint8_t g_nonce_list[3][1][16][91]; // [sp+1630h] [bp-133B4h] BYREF
  char tmp42[74404]; // [sp+2740h] [bp-122A4h] BYREF

  memset(receive_buf, 0, sizeof(receive_buf));
  v3 = *(_DWORD *)arg;
  v4 = pthread_self();
  pthread_detach(v4);
  if ( use_syslog || opt_log_output || opt_log_level > 4 )
  {
    snprintf(tmp42, 0x1000u, "Start A New Asic Response.Chain Id:[%d]", v3);
    applog(5, tmp42, 0);
    if ( !opt_debug )
      goto LABEL_5;
    if ( use_syslog || opt_log_output )
    {
LABEL_30:
      snprintf(tmp42, 0x1000u, "%s %d", "get_asic_response", v3);
      applog(7, tmp42, 0);
      goto LABEL_5;
    }
LABEL_53:
    if ( opt_log_level <= 6 )
      goto LABEL_5;
    goto LABEL_30;
  }
  if ( opt_debug )
    goto LABEL_53;
LABEL_5:
  v5 = 0;
  memset(tmp42, 0, (size_t)&loc_122A0);
  memset(tmp, 0, 0x5Du);
  v6 = 0;
LABEL_6:
  while ( *((_BYTE *)&axi_fpga_addr + v3 + 776) )
  {
    cgsleep_us(500);
    v7 = uart_receive(v3, receive_buf, 0x5D0u);
    if ( v7 > 0 )
    {
      v8 = receive_buf;
      do
      {
        v9 = *v8++;
        tmp42[v5++] = v9;
        if ( v5 > (int)&loc_1229C + 3 )
          v5 = 0;
      }
      while ( &receive_buf[v7] != v8 );
    }
    if ( v5 != v6 )
    {
      if ( v5 > v6 )
        v1 = v5 - v6;
      else
        v8 = (uint8_t *)&loc_122A0;
      if ( v5 <= v6 )
        v1 = (int)&v8[v5 - v6];
      while ( v1 > 2 )
      {
        v10 = header;
        v11 = v6;
        memset(header, 0, sizeof(header));
        do
        {
          v12 = tmp42[v11++];
          if ( v11 > (int)&loc_1229C + 3 )
            v11 = 0;
          *v10++ = v12;
        }
        while ( &v21 != (char *)v10 );
        if ( header[0] == 170 && header[1] == 85 )
        {
          if ( (header[2] & 0xF0) == 0xE0 )
          {
            if ( v1 <= 92 )
              goto LABEL_6;
            v17 = (uint8_t *)&v21;
            do
            {
              v18 = tmp42[v6++];
              if ( v6 > (int)&loc_1229C + 3 )
                v6 = 0;
              *++v17 = v18;
            }
            while ( &tmp[92] != v17 );
            v1 -= 93;
            nonce_handle(g_nonce, g_nonce_list, tmp, 93, v3);
          }
          else if ( header[2] == 204 )
          {
            if ( v1 <= 8 )
              goto LABEL_6;
            v15 = (uint8_t *)&v21;
            do
            {
              v16 = tmp42[v6++];
              if ( v6 > (int)&loc_1229C + 3 )
                v6 = 0;
              *++v15 = v16;
            }
            while ( v15 != &tmp[8] );
            v1 -= 9;
            pm_handle(tmp, 9, v3);
          }
          else
          {
            if ( v1 <= 8 )
              goto LABEL_6;
            v13 = (uint8_t *)&v21;
            do
            {
              v14 = tmp42[v6++];
              if ( v6 > (int)&loc_1229C + 3 )
                v6 = 0;
              *++v13 = v14;
            }
            while ( &tmp[8] != v13 );
            v1 -= 9;
            reg_handle(tmp, 9, v3);
          }
        }
        else
        {
          ++v6;
          --v1;
          if ( v6 > (int)&loc_1229C + 3 )
            v6 = 0;
        }
      }
    }
  }
  return 0;
}
