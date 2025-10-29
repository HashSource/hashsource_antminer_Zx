void print_summary()
{
  int v0; // r4
  int v1; // r2
  int v2; // r6
  int v3; // r11
  double v4; // d10
  double v5; // d8
  int *v6; // r12
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r0
  int v12; // r1
  int v13; // r2
  int v14; // r3
  int v15; // r12
  const char *v16; // r2
  const char *v17; // r2
  int v18; // r3
  double v19; // d7
  const char *v20; // r2
  const char *v21; // r2
  const char *v22; // r2
  const char *v23; // r2
  const char *v24; // r2
  const char *v25; // r2
  int64_t v26; // r6
  const char *v27; // r2
  int v28; // r3
  const char *v29; // r2
  int v30; // r3
  const char *v31; // r2
  const char *v32; // r2
  const char *v33; // r2
  const char *v34; // r2
  const char *v35; // r2
  const char *v36; // r2
  char *v37; // r2
  char *v38; // r1
  int v39; // r8
  pool *v40; // r6
  const char *v41; // r2
  const char *v42; // r2
  const char *v43; // r2
  int64_t accepted; // r10
  __int64 v45; // r0
  const char *v46; // r2
  const char *v47; // r2
  int *v48; // r7
  int v49; // r0
  int v50; // r1
  int v51; // r2
  int v52; // r3
  int v53; // r0
  int v54; // r1
  int v55; // r2
  int v56; // r3
  int v57; // r7
  void (*v58)(char *, size_t, cgpu_info *); // r11
  void (*v59)(char *, size_t, cgpu_info *); // r10
  const char *v60; // r9
  int v61; // r5
  cgpu_info *devices; // r0
  int v63; // r1
  int v64; // r3
  double v65; // d7
  const char *v66; // r2
  const char *v67; // r2
  const char *v68; // r2
  char *v69; // [sp+1Ch] [bp-1110h]
  char *format; // [sp+20h] [bp-110Ch]
  char v71[256]; // [sp+28h] [bp-1104h] BYREF
  char tmp42[4096]; // [sp+128h] [bp-1004h] BYREF

  v0 = total_tv_end.tv_sec - total_tv_start.tv_sec;
  LOWORD(v1) = -30583;
  if ( total_tv_end.tv_usec - total_tv_start.tv_usec < 0 )
    --v0;
  HIWORD(v1) = -30584;
  v2 = v0 - 60 * (((int)(v0 + ((unsigned __int64)(v0 * (__int64)v1) >> 32)) >> 5) - (v0 >> 31));
  v3 = ((int)(v0 % 3600 + ((unsigned __int64)(v0 % 3600 * (__int64)v1) >> 32)) >> 5) - ((v0 % 3600) >> 31);
  v4 = (double)total_accepted / total_secs * 60.0;
  v5 = (double)total_diff1 / total_secs * 60.0;
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
    goto LABEL_133;
  LOWORD(v6) = -180;
  HIWORD(v6) = (unsigned int)"RROR ON LOCK! errno=%d in %s %s():%d" >> 16;
  v7 = *v6;
  v8 = v6[1];
  v9 = v6[2];
  v10 = v6[3];
  v6 += 4;
  *(_DWORD *)tmp42 = v7;
  *(_DWORD *)&tmp42[4] = v8;
  *(_DWORD *)&tmp42[8] = v9;
  *(_DWORD *)&tmp42[12] = v10;
  v11 = *v6;
  v12 = v6[1];
  v13 = v6[2];
  v14 = v6[3];
  v15 = v6[4];
  *(_DWORD *)&tmp42[16] = v11;
  *(_DWORD *)&tmp42[20] = v12;
  *(_DWORD *)&tmp42[24] = v13;
  *(_DWORD *)&tmp42[28] = v14;
  tmp42[32] = v15;
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
  {
LABEL_133:
    if ( total_pools == 1 )
      goto LABEL_154;
LABEL_8:
    if ( use_syslog || opt_log_output )
      goto LABEL_10;
    goto LABEL_135;
  }
  LOWORD(v16) = -144;
  HIWORD(v16) = (unsigned int)"" >> 16;
  snprintf(tmp42, 0x1000u, v16, datestamp);
  applog(4, tmp42, 0);
  if ( total_pools != 1 )
    goto LABEL_8;
  if ( use_syslog || opt_log_output )
    goto LABEL_155;
LABEL_154:
  if ( opt_log_level > 3 )
  {
LABEL_155:
    LOWORD(v68) = -128;
    HIWORD(v68) = (unsigned int)"runtime statistics:\n" >> 16;
    snprintf(tmp42, 0x1000u, v68, (*pools)->rpc_url);
    applog(4, tmp42, 0);
    goto LABEL_8;
  }
LABEL_135:
  if ( opt_log_level <= 3 )
  {
    v19 = total_mhashes_done / total_secs;
    goto LABEL_137;
  }
LABEL_10:
  LOWORD(v17) = -116;
  HIWORD(v17) = (unsigned int)"istics:\n" >> 16;
  snprintf(tmp42, 0x1000u, v17, v0 / 3600, v3, v2);
  applog(4, tmp42, 0);
  v18 = (int)&total_mhashes_done;
  v19 = total_mhashes_done / total_secs;
  if ( use_syslog || (v18 = opt_log_output) != 0 )
  {
LABEL_12:
    LOWORD(v20) = -80;
    HIWORD(v20) = (unsigned int)"" >> 16;
    snprintf(tmp42, 0x1000u, v20, v18, v19);
    applog(4, tmp42, 0);
    if ( use_syslog || opt_log_output )
      goto LABEL_14;
    goto LABEL_187;
  }
LABEL_137:
  v18 = opt_log_level;
  if ( opt_log_level > 3 )
    goto LABEL_12;
LABEL_187:
  if ( opt_log_level <= 3 )
    goto LABEL_188;
LABEL_14:
  LOWORD(v21) = -48;
  HIWORD(v21) = (unsigned int)"%d secs" >> 16;
  snprintf(tmp42, 0x1000u, v21, found_blocks);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output )
  {
LABEL_188:
    if ( opt_log_level <= 3 )
      goto LABEL_156;
  }
  LOWORD(v22) = -28;
  HIWORD(v22) = (unsigned int)"rate: %.1f Mhash/s" >> 16;
  snprintf(tmp42, 0x1000u, v22, best_share);
  applog(4, tmp42, 0);
  if ( use_syslog || opt_log_output )
  {
LABEL_18:
    snprintf(tmp42, 0x1000u, "Share submissions: %lld", total_accepted + total_rejected);
    applog(4, tmp42, 0);
    if ( use_syslog || opt_log_output )
      goto LABEL_20;
    goto LABEL_157;
  }
LABEL_156:
  if ( opt_log_level > 3 )
    goto LABEL_18;
LABEL_157:
  if ( opt_log_level <= 3 )
    goto LABEL_158;
LABEL_20:
  snprintf(tmp42, 0x1000u, "Accepted shares: %lld", total_accepted);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output )
  {
LABEL_158:
    if ( opt_log_level <= 3 )
      goto LABEL_159;
  }
  LOWORD(v23) = 48;
  HIWORD(v23) = (unsigned int)"bmissions: %lld" >> 16;
  snprintf(tmp42, 0x1000u, v23, &total_rejected, total_rejected);
  applog(4, tmp42, 0);
  if ( use_syslog || opt_log_output )
  {
LABEL_24:
    LOWORD(v24) = 72;
    HIWORD(v24) = (unsigned int)" shares: %lld" >> 16;
    snprintf(tmp42, 0x1000u, v24, &total_diff_accepted, total_diff_accepted);
    applog(4, tmp42, 0);
    if ( use_syslog || opt_log_output )
      goto LABEL_26;
    goto LABEL_160;
  }
LABEL_159:
  if ( opt_log_level > 3 )
    goto LABEL_24;
LABEL_160:
  if ( opt_log_level <= 3 )
  {
    v26 = total_accepted;
    if ( total_accepted )
      goto LABEL_162;
    goto LABEL_54;
  }
LABEL_26:
  LOWORD(v25) = 108;
  HIWORD(v25) = (unsigned int)"d" >> 16;
  snprintf(tmp42, 0x1000u, v25, &total_diff_rejected, total_diff_rejected);
  applog(4, tmp42, 0);
  v26 = total_accepted;
  if ( total_accepted )
  {
    if ( !use_syslog )
      goto LABEL_28;
LABEL_29:
    snprintf(tmp42, 0x1000u, "Reject ratio: %.1f%%", (double)(100 * total_rejected) / (double)(total_rejected + v26));
    applog(4, tmp42, 0);
LABEL_30:
    if ( use_syslog || opt_log_output )
      goto LABEL_32;
    goto LABEL_143;
  }
LABEL_54:
  if ( !total_rejected )
    goto LABEL_30;
  v26 = 0;
  if ( use_syslog )
    goto LABEL_29;
LABEL_28:
  if ( opt_log_output )
    goto LABEL_29;
LABEL_162:
  if ( opt_log_level > 3 )
    goto LABEL_29;
LABEL_143:
  if ( opt_log_level <= 3 )
    goto LABEL_144;
LABEL_32:
  LOWORD(v27) = 168;
  HIWORD(v27) = (unsigned int)"shares: %1.f" >> 16;
  snprintf(tmp42, 0x1000u, v27, hw_errors);
  applog(4, tmp42, 0);
  v28 = use_syslog;
  if ( !use_syslog )
  {
    v28 = opt_log_output;
    if ( !opt_log_output )
    {
      v28 = opt_log_level;
      if ( opt_log_level <= 3 )
      {
LABEL_144:
        v30 = opt_log_level;
        if ( opt_log_level <= 3 )
          goto LABEL_145;
        goto LABEL_36;
      }
    }
  }
  LOWORD(v29) = 188;
  HIWORD(v29) = (unsigned int)"ct ratio: %.1f%%" >> 16;
  snprintf(tmp42, 0x1000u, v29, v28, v4);
  applog(4, tmp42, 0);
  v30 = use_syslog;
  if ( !use_syslog )
  {
    v30 = opt_log_output;
    if ( !opt_log_output )
    {
      v30 = opt_log_level;
      if ( opt_log_level <= 3 )
      {
LABEL_145:
        if ( opt_log_level <= 3 )
          goto LABEL_146;
        goto LABEL_38;
      }
    }
  }
LABEL_36:
  LOWORD(v31) = 232;
  HIWORD(v31) = (unsigned int)"ity (accepted shares / min): %.2f/min" >> 16;
  snprintf(tmp42, 0x1000u, v31, v30, v5);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
  {
LABEL_146:
    if ( opt_log_level <= 3 )
      goto LABEL_147;
    goto LABEL_40;
  }
LABEL_38:
  LOWORD(v32) = 284;
  HIWORD(v32) = (unsigned int)" (diff1 shares solved / min): %.2f/min\n" >> 16;
  snprintf(tmp42, 0x1000u, v32, &total_stale, total_stale);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
  {
LABEL_147:
    if ( opt_log_level <= 3 )
      goto LABEL_148;
    goto LABEL_42;
  }
LABEL_40:
  LOWORD(v33) = 336;
  HIWORD(v33) = (unsigned int)"sions discarded due to new blocks: %lld" >> 16;
  snprintf(tmp42, 0x1000u, v33, total_go);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
  {
LABEL_148:
    if ( opt_log_level <= 3 )
      goto LABEL_149;
    goto LABEL_44;
  }
LABEL_42:
  LOWORD(v34) = 384;
  HIWORD(v34) = (unsigned int)"o get work from server occasions: %d" >> 16;
  snprintf(tmp42, 0x1000u, v34, local_work);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
  {
LABEL_149:
    if ( opt_log_level <= 3 )
      goto LABEL_150;
    goto LABEL_46;
  }
LABEL_44:
  LOWORD(v35) = 420;
  HIWORD(v35) = (unsigned int)"" >> 16;
  snprintf(tmp42, 0x1000u, v35, total_ro);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
  {
LABEL_150:
    if ( total_pools <= 1 )
      goto LABEL_139;
    goto LABEL_47;
  }
LABEL_46:
  LOWORD(v36) = 468;
  HIWORD(v36) = (unsigned int)"ng work remotely delay occasions: %d" >> 16;
  snprintf(tmp42, 0x1000u, v36, new_blocks);
  applog(4, tmp42, 0);
  if ( total_pools > 1 )
  {
LABEL_47:
    LOWORD(v37) = 820;
    LOWORD(v38) = 772;
    v39 = 0;
    HIWORD(v37) = (unsigned int)"to get work from server occasions: %d" >> 16;
    HIWORD(v38) = (unsigned int)"ssions discarded due to new blocks: %d" >> 16;
    v69 = v37;
    format = v38;
    while ( 1 )
    {
      v40 = pools[v39];
      if ( use_syslog || opt_log_output || opt_log_level > 3 )
        break;
      if ( v40->solved )
        goto LABEL_52;
LABEL_61:
      if ( !opt_log_output )
      {
LABEL_108:
        if ( opt_log_level <= 3 )
          goto LABEL_109;
      }
LABEL_62:
      LOWORD(v43) = 524;
      HIWORD(v43) = (unsigned int)"ted on network: %d\n" >> 16;
      snprintf(
        tmp42,
        0x1000u,
        v43,
        (_DWORD)((unsigned __int64)(v40->accepted + v40->rejected) >> 32),
        v40->accepted + v40->rejected);
      applog(4, tmp42, 0);
      if ( use_syslog || opt_log_output )
      {
LABEL_64:
        snprintf(tmp42, 0x1000u, " Accepted shares: %lld", v40->accepted);
        applog(4, tmp42, 0);
        if ( use_syslog || opt_log_output )
          goto LABEL_66;
        goto LABEL_110;
      }
LABEL_109:
      if ( opt_log_level > 3 )
        goto LABEL_64;
LABEL_110:
      if ( opt_log_level <= 3 )
        goto LABEL_111;
LABEL_66:
      snprintf(tmp42, 0x1000u, " Rejected shares: %lld", v40->rejected);
      applog(4, tmp42, 0);
      if ( !use_syslog && !opt_log_output )
      {
LABEL_111:
        if ( opt_log_level <= 3 )
          goto LABEL_112;
      }
      snprintf(tmp42, 0x1000u, " Accepted difficulty shares: %1.f", v40->diff_accepted);
      applog(4, tmp42, 0);
      if ( use_syslog || opt_log_output )
      {
LABEL_70:
        snprintf(tmp42, 0x1000u, " Rejected difficulty shares: %1.f", v40->diff_rejected);
        applog(4, tmp42, 0);
        accepted = v40->accepted;
        if ( accepted )
          goto LABEL_73;
        goto LABEL_71;
      }
LABEL_112:
      if ( opt_log_level > 3 )
        goto LABEL_70;
      accepted = v40->accepted;
      if ( accepted )
      {
        if ( opt_log_level <= 3 )
          goto LABEL_115;
        goto LABEL_75;
      }
LABEL_71:
      if ( v40->rejected )
      {
        accepted = 0;
LABEL_73:
        if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
        {
LABEL_115:
          if ( opt_log_level <= 3 )
            goto LABEL_116;
          goto LABEL_78;
        }
LABEL_75:
        HIDWORD(v45) = (unsigned __int64)(3 * v40->rejected) >> 32;
        LODWORD(v45) = 96 * LODWORD(v40->rejected);
        snprintf(
          tmp42,
          0x1000u,
          " Reject ratio: %.1f%%",
          (double)(__int64)(__PAIR64__((unsigned __int64)(96 * v40->rejected) >> 32, 3 * LODWORD(v40->rejected))
                          + v45
                          + v40->rejected)
        / (double)(v40->rejected + accepted));
        applog(4, tmp42, 0);
      }
      if ( !use_syslog && !opt_log_output )
        goto LABEL_115;
LABEL_78:
      LOWORD(v46) = 696;
      HIWORD(v46) = (unsigned int)" shares: %1.f" >> 16;
      snprintf(tmp42, 0x1000u, v46, v40->works);
      applog(4, tmp42, 0);
      if ( use_syslog || opt_log_output )
      {
LABEL_80:
        LOWORD(v47) = 720;
        HIWORD(v47) = (unsigned int)"ratio: %.1f%%" >> 16;
        snprintf(tmp42, 0x1000u, v47, v40->stale_shares);
        applog(4, tmp42, 0);
        if ( use_syslog || opt_log_output )
          goto LABEL_82;
        goto LABEL_117;
      }
LABEL_116:
      if ( opt_log_level > 3 )
        goto LABEL_80;
LABEL_117:
      if ( opt_log_level <= 3 )
        goto LABEL_118;
LABEL_82:
      snprintf(tmp42, 0x1000u, format, v40->getfail_occasions);
      applog(4, tmp42, 0);
      if ( !use_syslog && !opt_log_output )
      {
LABEL_118:
        if ( opt_log_level <= 3 )
          goto LABEL_85;
      }
      snprintf(tmp42, 0x1000u, v69, v40->remotefail_occasions);
      applog(4, tmp42, 0);
LABEL_85:
      if ( total_pools <= ++v39 )
        goto LABEL_86;
    }
    LOWORD(v41) = -128;
    HIWORD(v41) = (unsigned int)"runtime statistics:\n" >> 16;
    snprintf(tmp42, 0x1000u, v41, v40->rpc_url);
    applog(4, tmp42, 0);
    if ( v40->solved )
    {
      if ( !use_syslog && !opt_log_output )
      {
LABEL_52:
        if ( opt_log_level <= 3 )
          goto LABEL_108;
      }
      LOWORD(v42) = 504;
      HIWORD(v42) = (unsigned int)"" >> 16;
      snprintf(tmp42, 0x1000u, v42);
      applog(4, tmp42, 0);
    }
    if ( use_syslog )
      goto LABEL_62;
    goto LABEL_61;
  }
LABEL_86:
  if ( use_syslog || opt_log_output )
    goto LABEL_88;
LABEL_139:
  if ( opt_log_level > 3 )
  {
LABEL_88:
    LOWORD(v48) = 868;
    HIWORD(v48) = (unsigned int)"ing work remotely delay occasions: %d\n" >> 16;
    v49 = *v48;
    v50 = v48[1];
    v51 = v48[2];
    v52 = v48[3];
    v48 += 4;
    *(_DWORD *)tmp42 = v49;
    *(_DWORD *)&tmp42[4] = v50;
    *(_DWORD *)&tmp42[8] = v51;
    *(_DWORD *)&tmp42[12] = v52;
    v53 = *v48;
    v54 = v48[1];
    v55 = v48[2];
    v56 = v48[3];
    v57 = v48[4];
    *(_DWORD *)&tmp42[16] = v53;
    *(_DWORD *)&tmp42[20] = v54;
    *(_DWORD *)&tmp42[24] = v55;
    *(_DWORD *)&tmp42[28] = v56;
    *(_WORD *)&tmp42[32] = v57;
    tmp42[34] = BYTE2(v57);
    applog(4, tmp42, 0);
  }
  if ( total_devices > 0 )
  {
    LOWORD(v58) = 20621;
    LOWORD(v59) = 30181;
    LOWORD(v60) = 20752;
    v61 = 0;
    do
    {
      devices = get_devices(v61++);
      HIWORD(v58) = ((unsigned int)&loc_1503A + 3) >> 16;
      devices->drv->get_statline_before = v58;
      HIWORD(v59) = (unsigned int)&loc_17594 >> 16;
      devices->drv->get_statline = v59;
      get_statline(v71, 0xFFu, devices);
      if ( use_syslog || opt_log_output || opt_log_level > 3 )
      {
        HIWORD(v60) = (unsigned int)"mcast join failed (%s)%s" >> 16;
        snprintf(tmp42, 0x1000u, v60, v71);
        applog(4, tmp42, 0);
      }
    }
    while ( total_devices > v61 );
  }
  v63 = opt_shares;
  v64 = use_syslog;
  if ( opt_shares )
  {
    v65 = total_diff_accepted;
    if ( !use_syslog )
    {
      v64 = (int)&opt_log_output;
      if ( !opt_log_output && opt_log_level <= 3 )
      {
        if ( (double)opt_shares <= total_diff_accepted )
          goto LABEL_141;
        goto LABEL_101;
      }
    }
    LOWORD(v66) = 904;
    HIWORD(v66) = (unsigned int)"d\n" >> 16;
    snprintf(tmp42, 0x1000u, v66, v64, total_diff_accepted, opt_shares);
    applog(4, tmp42, 0);
    v65 = total_diff_accepted;
    v63 = opt_shares;
    v64 = use_syslog;
    if ( (double)opt_shares > total_diff_accepted )
    {
      if ( use_syslog )
      {
LABEL_103:
        LOWORD(v67) = 948;
        HIWORD(v67) = (unsigned int)"d %.0f accepted shares of %d requested\n" >> 16;
        snprintf(tmp42, 0x1000u, v67, v64, v65, v63);
        applog(4, tmp42, 0);
        v64 = use_syslog;
        goto LABEL_104;
      }
LABEL_101:
      v64 = opt_log_output;
      if ( !opt_log_output )
      {
        v64 = opt_log_level;
        if ( opt_log_level <= 3 )
        {
LABEL_141:
          if ( opt_log_level <= 3 )
            goto LABEL_107;
          goto LABEL_106;
        }
      }
      goto LABEL_103;
    }
  }
LABEL_104:
  if ( !v64 && !opt_log_output )
    goto LABEL_141;
LABEL_106:
  strcpy(tmp42, " ");
  applog(4, tmp42, 0);
LABEL_107:
  fflush((FILE *)stderr);
  fflush((FILE *)stdout);
}
