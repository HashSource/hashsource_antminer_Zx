bool __fastcall bitmain_ZCASH_prepare(thr_info *thr)
{
  char *device_data; // r5
  const char *v2; // r1
  const char *v3; // r2
  int v4; // r3
  const char *v5; // r1
  const char *v6; // r2
  int v7; // r3
  init_config *p_ZCASH_config; // r2
  __int16 v9; // r3
  unsigned int v10; // r4
  int version; // t1
  uint32_t baud; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r1
  uint32_t reg_data; // r2
  int v17; // r3
  init_config ZCASH_config; // [sp+0h] [bp-24h] BYREF

  device_data = (char *)thr->cgpu->device_data;
  *(_DWORD *)(device_data + 630) = thr;
  if ( pthread_mutex_init((pthread_mutex_t *)(device_data + 1146), 0) )
    mutex_init_1((pthread_mutex_t *)0x1D77, v2, v3, v4);
  if ( pthread_mutex_init((pthread_mutex_t *)device_data, 0) )
    mutex_init_1((pthread_mutex_t *)0x1D78, v5, v6, v7);
  rwlock_init_1((pthread_rwlock_t *)(device_data + 24), v5, v6, v7);
  memset(&ZCASH_config, 0, sizeof(ZCASH_config));
  ZCASH_config.frequency = opt_bitmain_ZCASH_freq;
  ZCASH_config.token_type = 81;
  ZCASH_config.length = 24;
  *((_BYTE *)&ZCASH_config + 9) = 7;
  *(_WORD *)&ZCASH_config.chain_num = 774;
  ZCASH_config.temperature = 80;
  *(_WORD *)ZCASH_config.voltage = 9479;
  *(_WORD *)&ZCASH_config.chain_check_time_integer = 2570;
  *((_BYTE *)&ZCASH_config + 8) = (2 * opt_bitmain_fan_ctrl) | 0xFD;
  p_ZCASH_config = &ZCASH_config;
  ZCASH_config.fan_pwm_percent = opt_bitmain_fan_pwm;
  v9 = 19156;
  LOWORD(v10) = 255;
  ZCASH_config.chip_address = 4;
  while ( 1 )
  {
    v10 = (unsigned __int16)(v9 ^ ((_WORD)v10 << 8));
    if ( p_ZCASH_config == (init_config *)&ZCASH_config.reg_address )
      break;
    version = p_ZCASH_config->version;
    p_ZCASH_config = (init_config *)((char *)p_ZCASH_config + 1);
    v9 = *(_WORD *)&_FUNCTION___15596[2 * (version ^ (v10 >> 8)) + 100];
  }
  ZCASH_config.crc = v10;
  baud = ZCASH_config.baud;
  v13 = *((_DWORD *)&ZCASH_config + 2);
  v14 = *(_DWORD *)&ZCASH_config.chain_num;
  *(_DWORD *)(device_data + 1170) = *(_DWORD *)&ZCASH_config.token_type;
  *(_DWORD *)(device_data + 1174) = baud;
  *(_DWORD *)(device_data + 1178) = v13;
  *(_DWORD *)(device_data + 1182) = v14;
  v15 = *(_DWORD *)&ZCASH_config.chain_check_time_integer;
  reg_data = ZCASH_config.reg_data;
  v17 = *(_DWORD *)&ZCASH_config.chip_address;
  *(_DWORD *)(device_data + 1186) = *(_DWORD *)&ZCASH_config.frequency;
  *(_DWORD *)(device_data + 1190) = v15;
  *(_DWORD *)(device_data + 1194) = reg_data;
  *(_DWORD *)(device_data + 1198) = v17;
  bitmain_ZCASH_init((bitmain_ZCASH_info *)device_data);
  return 1;
}
