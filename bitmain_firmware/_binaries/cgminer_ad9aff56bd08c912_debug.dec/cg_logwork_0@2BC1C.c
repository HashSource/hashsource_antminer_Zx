// Alternative name is 'cg_logwork.part.9'
// local variable allocation has failed, the output may be wrong!
void __fastcall cg_logwork_0(work *work, unsigned __int8 *nonce_bin, bool ok)
{
  int v5; // r1
  int v6; // r2
  int v7; // r3
  int v8; // r1
  int v9; // r2
  int v10; // r3
  unsigned __int8 *v11; // r7
  unsigned __int8 *v12; // r5
  int v13; // r1
  int v14; // r2
  int v15; // r1
  int v16; // r3
  int v17; // r2
  int v18; // r1
  int v19; // r2
  int v20; // r3
  unsigned __int8 v21; // r3
  unsigned __int8 v22; // t1
  unsigned __int8 v23; // t1
  unsigned __int8 *v24; // r2
  unsigned __int8 *v25; // r3
  unsigned __int8 v26; // t1
  unsigned __int8 v27; // r0
  unsigned __int8 *v28; // r3
  _BYTE *v29; // r2
  char v30; // r1
  char v31; // t1
  unsigned __int8 v32; // t1
  unsigned __int8 *v33; // r3
  char *v34; // r2
  char v35; // r1
  char v36; // t1
  unsigned __int8 v37; // t1
  char *v38; // r5
  char *v39; // r7
  char *v40; // r8
  char *v41; // r11
  char *v42; // r9
  uint32_t id; // r3
  int v44; // r2
  const char *v45; // r1
  size_t v46; // r0
  const void *v47; // r0
  const char *v48; // r1
  int v49; // r4
  size_t v50; // r0
  const void *v51; // r0
  uint64_t v52; // r2
  int i; // r4
  const char *v54; // r1
  size_t v55; // r0
  const void *v56; // r0
  int v57; // r2
  const char *v58; // r1
  size_t v59; // r0
  const void *v60; // r0
  const char *v61; // r1
  size_t v62; // r0
  const void *v63; // r0
  const char *v64; // r1
  size_t v65; // r0
  const void *v66; // r0
  int v67; // [sp+14h] [bp-14D8h]
  char *sznonce5; // [sp+24h] [bp-14C8h]
  _BOOL4 v69; // [sp+28h] [bp-14C4h]
  uint64_t v70; // [sp+2Ch] [bp-14C0h]
  bool *v71; // [sp+34h] [bp-14B8h] BYREF
  unsigned __int8 midstate_tmp[32]; // [sp+38h] [bp-14B4h] BYREF
  unsigned __int8 data_tmp[32]; // [sp+58h] [bp-1494h] BYREF
  unsigned __int8 hash_tmp[32]; // [sp+78h] [bp-1474h] BYREF
  _BYTE nonce[80]; // [sp+98h] [bp-1454h] OVERLAPPED BYREF
  char szmsg[1024]; // [sp+E8h] [bp-1404h] BYREF
  char tmp42[4100]; // [sp+4E8h] [bp-1004h] BYREF

  v69 = ok;
  memset(szmsg, 0, sizeof(szmsg));
  memset(&data_tmp[12], 0, 20);
  memset(nonce, 0, sizeof(nonce));
  v5 = *(_DWORD *)&work->midstate[4];
  v6 = *(_DWORD *)&work->midstate[8];
  v7 = *(_DWORD *)&work->midstate[12];
  *(_DWORD *)midstate_tmp = *(_DWORD *)work->midstate;
  *(_DWORD *)&midstate_tmp[4] = v5;
  *(_DWORD *)&midstate_tmp[8] = v6;
  *(_DWORD *)&midstate_tmp[12] = v7;
  v8 = *(_DWORD *)&work->midstate[20];
  v9 = *(_DWORD *)&work->midstate[24];
  v10 = *(_DWORD *)&work->midstate[28];
  *(_DWORD *)&midstate_tmp[16] = *(_DWORD *)&work->midstate[16];
  *(_DWORD *)&midstate_tmp[20] = v8;
  *(_DWORD *)&midstate_tmp[24] = v9;
  *(_DWORD *)&midstate_tmp[28] = v10;
  v11 = data_tmp;
  v12 = (unsigned __int8 *)&v71 + 3;
  v13 = *(_DWORD *)&work->data[68];
  v14 = *(_DWORD *)&work->data[72];
  *(_DWORD *)data_tmp = *(_DWORD *)&work->data[64];
  *(_DWORD *)&data_tmp[4] = v13;
  *(_DWORD *)&data_tmp[8] = v14;
  v15 = *(_DWORD *)&work->hash[4];
  v16 = *(_DWORD *)&work->hash[12];
  v17 = *(_DWORD *)&work->hash[8];
  *(_DWORD *)hash_tmp = *(_DWORD *)work->hash;
  *(_DWORD *)&hash_tmp[4] = v15;
  *(_DWORD *)&hash_tmp[8] = v17;
  *(_DWORD *)&hash_tmp[12] = v16;
  v18 = *(_DWORD *)&work->hash[20];
  v19 = *(_DWORD *)&work->hash[24];
  v20 = *(_DWORD *)&work->hash[28];
  *(_DWORD *)&hash_tmp[16] = *(_DWORD *)&work->hash[16];
  *(_DWORD *)&hash_tmp[20] = v18;
  *(_DWORD *)&hash_tmp[24] = v19;
  *(_DWORD *)&hash_tmp[28] = v20;
  do
  {
    v22 = *++v12;
    v21 = v22;
    v23 = *--v11;
    *v12 = v23;
    *v11 = v21;
  }
  while ( &midstate_tmp[15] != v12 );
  v24 = data_tmp;
  v25 = &data_tmp[12];
  do
  {
    v26 = *--v25;
    v27 = *v24;
    *v24++ = v26;
    *v25 = v27;
  }
  while ( &data_tmp[6] != v25 );
  v28 = &data_tmp[31];
  v29 = nonce;
  do
  {
    v31 = *++v28;
    v30 = v31;
    v32 = *--v29;
    *v28 = v32;
    *v29 = v30;
  }
  while ( &hash_tmp[15] != v28 );
  if ( opt_scrypt )
  {
    memcpy(nonce, work, sizeof(nonce));
    v33 = &hash_tmp[31];
    v34 = szmsg;
    do
    {
      v36 = *++v33;
      v35 = v36;
      v37 = *--v34;
      *v33 = v37;
      *v34 = v35;
    }
    while ( &nonce[39] != v33 );
    *(_DWORD *)nonce = bswap32(16 * bswap32(*(unsigned int *)nonce));
    v38 = bin2hex(nonce, 0x50u);
  }
  else
  {
    v38 = bin2hex(work->data, 0x80u);
  }
  v39 = bin2hex(midstate_tmp, 0x20u);
  v40 = bin2hex(data_tmp, 0xCu);
  v41 = bin2hex(nonce_bin, 4u);
  sznonce5 = bin2hex(nonce_bin, 5u);
  v42 = bin2hex(hash_tmp, 0x20u);
  v70 = share_ndiff(work);
  if ( !strcmp(opt_logwork_path, "screen") )
  {
    if ( v69 )
    {
      LOWORD(v61) = 19912;
      HIWORD(v61) = (unsigned int)" %s():%d" >> 16;
      sprintf(szmsg, v61, v38, v41);
      if ( use_syslog || opt_log_output || opt_log_level > 2 )
      {
        snprintf(tmp42, 0x1000u, szmsg);
        applog(3, tmp42, 0);
      }
      v62 = strlen(szmsg);
      fwrite(szmsg, v62, 1u, g_logwork_file);
      LOWORD(v63) = -28576;
      HIWORD(v63) = (unsigned int)"ck_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
      fwrite(v63, 1u, 1u, g_logwork_file);
      fflush(g_logwork_file);
    }
  }
  else
  {
    v71 = &use_syslog;
    if ( use_syslog || opt_log_output || opt_log_level > 2 )
    {
      snprintf(tmp42, 0x1000u, szmsg);
      applog(3, tmp42, 0);
    }
    if ( g_logwork_file )
    {
      id = work->id;
      if ( v69 )
      {
        LOWORD(v44) = 20064;
        LOWORD(v45) = 20000;
        HIWORD(v44) = (unsigned int)"tate %s data %s nonce %s hash %s" >> 16;
        HIWORD(v45) = (unsigned int)"mcpy %u bytes from %s %s():%d" >> 16;
        sprintf(szmsg, v45, v44, id, v38, v39, v40, sznonce5, v42, v67, v70);
        v46 = strlen(szmsg);
        fwrite(szmsg, v46, 1u, g_logwork_file);
        LOWORD(v47) = -28576;
        HIWORD(v47) = (unsigned int)"ck_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
        fwrite(v47, 1u, 1u, g_logwork_file);
        fflush(g_logwork_file);
        if ( g_logwork_asicnum == 1 )
        {
          LOWORD(v64) = 19932;
          HIWORD(v64) = (unsigned int)"o sem_timedwait errno=%d cgsem=0x%p in %s %s():%d" >> 16;
          sprintf(szmsg, v64, v39, v40, v41, v42);
          v65 = strlen(szmsg);
          fwrite(szmsg, v65, 1u, g_logwork_files[0]);
          LOWORD(v66) = -28576;
          HIWORD(v66) = (unsigned int)"ck_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
          fwrite(v66, 1u, 1u, g_logwork_files[0]);
          fflush(g_logwork_files[0]);
        }
        else if ( ((g_logwork_asicnum - 32) & 0xFFFFFFDF) == 0 )
        {
          LOWORD(v48) = 19932;
          HIWORD(v48) = (unsigned int)"o sem_timedwait errno=%d cgsem=0x%p in %s %s():%d" >> 16;
          sprintf(szmsg, v48, v39, v40, v41, v42);
          v49 = check_asicnum(g_logwork_asicnum, *nonce_bin);
          v50 = strlen(szmsg);
          fwrite(szmsg, v50, 1u, g_logwork_files[v49]);
          LOWORD(v51) = -28576;
          HIWORD(v51) = (unsigned int)"ck_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
          fwrite(v51, 1u, 1u, g_logwork_files[v49]);
          fflush(g_logwork_files[v49]);
        }
        if ( opt_logwork_diff )
        {
          v52 = v70;
          for ( i = 0; i != 64; ++i )
          {
            v52 >>= 1;
            if ( !v52 )
              break;
          }
          if ( opt_debug && (*v71 || opt_log_output || opt_log_level > 6) )
          {
            snprintf(tmp42, 0x1000u, "work diff %lld diffnum %d", v70, i);
            applog(7, tmp42, 0);
          }
          LOWORD(v54) = 19932;
          HIWORD(v54) = (unsigned int)"o sem_timedwait errno=%d cgsem=0x%p in %s %s():%d" >> 16;
          sprintf(szmsg, v54, v39, v40, v41, v42);
          v55 = strlen(szmsg);
          fwrite(szmsg, v55, 1u, g_logwork_diffs[i]);
          LOWORD(v56) = -28576;
          HIWORD(v56) = (unsigned int)"ck_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
          fwrite(v56, 1u, 1u, g_logwork_diffs[i]);
          fflush(g_logwork_diffs[i]);
        }
      }
      else
      {
        LOWORD(v57) = -23476;
        LOWORD(v58) = 20000;
        HIWORD(v57) = (unsigned int)"chain:%d local:%d remote:%d" >> 16;
        HIWORD(v58) = (unsigned int)"mcpy %u bytes from %s %s():%d" >> 16;
        sprintf(szmsg, v58, v57, id, v38, v39, v40, sznonce5, v42, v67, v70);
        v59 = strlen(szmsg);
        fwrite(szmsg, v59, 1u, g_logwork_file);
        LOWORD(v60) = -28576;
        HIWORD(v60) = (unsigned int)"ck_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n" >> 16;
        fwrite(v60, 1u, 1u, g_logwork_file);
        fflush(g_logwork_file);
      }
    }
  }
  if ( v38 )
    free(v38);
  if ( v39 )
    free(v39);
  if ( v40 )
    free(v40);
  if ( v41 )
    free(v41);
  if ( sznonce5 )
    free(sznonce5);
  if ( v42 )
    free(v42);
}
