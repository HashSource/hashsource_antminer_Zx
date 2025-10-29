void print_summary()
{
  int v0; // r4
  int v1; // r2
  int v2; // r6
  int v3; // r11
  double v4; // d10
  double v5; // d8
  double v6; // d7
  int64_t v7; // r6
  int v8; // r8
  pool *v9; // r6
  int solved; // r3
  const char *v11; // r1
  int64_t accepted; // r10
  __int64 v13; // r0
  int v14; // r5
  cgpu_info *devices; // r0
  int v16; // r1
  _BOOL4 v17; // r3
  double v18; // d7
  char v19[256]; // [sp+28h] [bp-1104h] BYREF
  char tmp42[4100]; // [sp+128h] [bp-1004h] BYREF

  v0 = total_tv_end.tv_sec - total_tv_start.tv_sec;
  LOWORD(v1) = -30583;
  if ( total_tv_end.tv_usec - total_tv_start.tv_usec < 0 )
    --v0;
  HIWORD(v1) = -30584;
  v2 = v0 - 60 * (((int)(v0 + ((unsigned __int64)(v0 * (__int64)v1) >> 32)) >> 5) - (v0 >> 31));
  v3 = ((int)(v0 % 3600 + ((unsigned __int64)(v0 % 3600 * (__int64)v1) >> 32)) >> 5) - ((v0 % 3600) >> 31);
  v4 = (double)total_accepted / total_secs * 60.0;
  v5 = (double)total_diff1 / total_secs * 60.0;
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3
    || (strcpy(tmp42, "\nSummary of runtime statistics:\n"), applog(4, tmp42, 0), !use_syslog)
    && !opt_log_output
    && opt_log_level <= 3 )
  {
    if ( total_pools == 1 )
      goto LABEL_156;
LABEL_8:
    if ( use_syslog || opt_log_output )
      goto LABEL_10;
    goto LABEL_137;
  }
  snprintf(tmp42, 0x1000u, "Started at %s", datestamp);
  applog(4, tmp42, 0);
  if ( total_pools != 1 )
    goto LABEL_8;
  if ( use_syslog || opt_log_output )
    goto LABEL_157;
LABEL_156:
  if ( opt_log_level > 3 )
  {
LABEL_157:
    snprintf(tmp42, 0x1000u, "Pool: %s", (*pools)->rpc_url);
    applog(4, tmp42, 0);
    goto LABEL_8;
  }
LABEL_137:
  if ( opt_log_level <= 3 )
  {
    v6 = total_mhashes_done / total_secs;
    goto LABEL_139;
  }
LABEL_10:
  snprintf(tmp42, 0x1000u, "Runtime: %d hrs : %d mins : %d secs", v0 / 3600, v3, v2);
  applog(4, tmp42, 0);
  v6 = total_mhashes_done / total_secs;
  if ( use_syslog || opt_log_output )
  {
LABEL_12:
    snprintf(tmp42, 0x1000u, "Average hashrate: %.1f Mhash/s", v6);
    applog(4, tmp42, 0);
    if ( use_syslog || opt_log_output )
      goto LABEL_14;
    goto LABEL_189;
  }
LABEL_139:
  if ( opt_log_level > 3 )
    goto LABEL_12;
LABEL_189:
  if ( opt_log_level <= 3 )
    goto LABEL_190;
LABEL_14:
  snprintf(tmp42, 0x1000u, "Solved blocks: %d", found_blocks);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output )
  {
LABEL_190:
    if ( opt_log_level <= 3 )
      goto LABEL_158;
  }
  snprintf(tmp42, 0x1000u, "Best share difficulty: %s", best_share);
  applog(4, tmp42, 0);
  if ( use_syslog || opt_log_output )
  {
LABEL_18:
    snprintf(tmp42, 0x1000u, "Share submissions: %lld", total_accepted + total_rejected);
    applog(4, tmp42, 0);
    if ( use_syslog || opt_log_output )
      goto LABEL_20;
    goto LABEL_159;
  }
LABEL_158:
  if ( opt_log_level > 3 )
    goto LABEL_18;
LABEL_159:
  if ( opt_log_level <= 3 )
    goto LABEL_160;
LABEL_20:
  snprintf(tmp42, 0x1000u, "Accepted shares: %lld", total_accepted);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output )
  {
LABEL_160:
    if ( opt_log_level <= 3 )
      goto LABEL_161;
  }
  snprintf(tmp42, 0x1000u, "Rejected shares: %lld", total_rejected);
  applog(4, tmp42, 0);
  if ( use_syslog || opt_log_output )
  {
LABEL_24:
    snprintf(tmp42, 0x1000u, "Accepted difficulty shares: %1.f", total_diff_accepted);
    applog(4, tmp42, 0);
    if ( use_syslog || opt_log_output )
      goto LABEL_26;
    goto LABEL_162;
  }
LABEL_161:
  if ( opt_log_level > 3 )
    goto LABEL_24;
LABEL_162:
  if ( opt_log_level <= 3 )
  {
    v7 = total_accepted;
    if ( total_accepted )
      goto LABEL_164;
    goto LABEL_54;
  }
LABEL_26:
  snprintf(tmp42, 0x1000u, "Rejected difficulty shares: %1.f", total_diff_rejected);
  applog(4, tmp42, 0);
  v7 = total_accepted;
  if ( total_accepted )
  {
    if ( !use_syslog )
      goto LABEL_28;
LABEL_29:
    snprintf(tmp42, 0x1000u, "Reject ratio: %.1f%%", (double)(100 * total_rejected) / (double)(total_rejected + v7));
    applog(4, tmp42, 0);
LABEL_30:
    if ( use_syslog || opt_log_output )
      goto LABEL_32;
    goto LABEL_145;
  }
LABEL_54:
  if ( !total_rejected )
    goto LABEL_30;
  v7 = 0;
  if ( use_syslog )
    goto LABEL_29;
LABEL_28:
  if ( opt_log_output )
    goto LABEL_29;
LABEL_164:
  if ( opt_log_level > 3 )
    goto LABEL_29;
LABEL_145:
  if ( opt_log_level <= 3 )
    goto LABEL_146;
LABEL_32:
  snprintf(tmp42, 0x1000u, "Hardware errors: %d", hw_errors);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
  {
LABEL_146:
    if ( opt_log_level <= 3 )
      goto LABEL_147;
    goto LABEL_36;
  }
  snprintf(tmp42, 0x1000u, "Utility (accepted shares / min): %.2f/min", v4);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
  {
LABEL_147:
    if ( opt_log_level <= 3 )
      goto LABEL_148;
    goto LABEL_38;
  }
LABEL_36:
  snprintf(tmp42, 0x1000u, "Work Utility (diff1 shares solved / min): %.2f/min\n", v5);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
  {
LABEL_148:
    if ( opt_log_level <= 3 )
      goto LABEL_149;
    goto LABEL_40;
  }
LABEL_38:
  snprintf(tmp42, 0x1000u, "Stale submissions discarded due to new blocks: %lld", total_stale);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
  {
LABEL_149:
    if ( opt_log_level <= 3 )
      goto LABEL_150;
    goto LABEL_42;
  }
LABEL_40:
  snprintf(tmp42, 0x1000u, "Unable to get work from server occasions: %d", total_go);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
  {
LABEL_150:
    if ( opt_log_level <= 3 )
      goto LABEL_151;
    goto LABEL_44;
  }
LABEL_42:
  snprintf(tmp42, 0x1000u, "Work items generated locally: %d", local_work);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
  {
LABEL_151:
    if ( opt_log_level <= 3 )
      goto LABEL_152;
    goto LABEL_46;
  }
LABEL_44:
  snprintf(tmp42, 0x1000u, "Submitting work remotely delay occasions: %d", total_ro);
  applog(4, tmp42, 0);
  if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
  {
LABEL_152:
    if ( total_pools <= 1 )
      goto LABEL_141;
    goto LABEL_47;
  }
LABEL_46:
  snprintf(tmp42, 0x1000u, "New blocks detected on network: %d\n", new_blocks);
  applog(4, tmp42, 0);
  if ( total_pools > 1 )
  {
LABEL_47:
    v8 = 0;
    while ( 1 )
    {
      v9 = pools[v8];
      if ( use_syslog || opt_log_output || opt_log_level > 3 )
        break;
      solved = v9->solved;
      if ( solved )
        goto LABEL_52;
LABEL_63:
      if ( !opt_log_output )
      {
LABEL_110:
        if ( opt_log_level <= 3 )
          goto LABEL_111;
      }
LABEL_64:
      snprintf(tmp42, 0x1000u, " Share submissions: %lld", v9->accepted + v9->rejected);
      applog(4, tmp42, 0);
      if ( use_syslog || opt_log_output )
      {
LABEL_66:
        snprintf(tmp42, 0x1000u, " Accepted shares: %lld", v9->accepted);
        applog(4, tmp42, 0);
        if ( use_syslog || opt_log_output )
          goto LABEL_68;
        goto LABEL_112;
      }
LABEL_111:
      if ( opt_log_level > 3 )
        goto LABEL_66;
LABEL_112:
      if ( opt_log_level <= 3 )
        goto LABEL_113;
LABEL_68:
      snprintf(tmp42, 0x1000u, " Rejected shares: %lld", v9->rejected);
      applog(4, tmp42, 0);
      if ( !use_syslog && !opt_log_output )
      {
LABEL_113:
        if ( opt_log_level <= 3 )
          goto LABEL_114;
      }
      snprintf(tmp42, 0x1000u, " Accepted difficulty shares: %1.f", v9->diff_accepted);
      applog(4, tmp42, 0);
      if ( use_syslog || opt_log_output )
      {
LABEL_72:
        snprintf(tmp42, 0x1000u, " Rejected difficulty shares: %1.f", v9->diff_rejected);
        applog(4, tmp42, 0);
        accepted = v9->accepted;
        if ( accepted )
          goto LABEL_75;
        goto LABEL_73;
      }
LABEL_114:
      if ( opt_log_level > 3 )
        goto LABEL_72;
      accepted = v9->accepted;
      if ( accepted )
      {
        if ( opt_log_level <= 3 )
          goto LABEL_117;
        goto LABEL_77;
      }
LABEL_73:
      if ( v9->rejected )
      {
        accepted = 0;
LABEL_75:
        if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
        {
LABEL_117:
          if ( opt_log_level <= 3 )
            goto LABEL_118;
          goto LABEL_80;
        }
LABEL_77:
        HIDWORD(v13) = (unsigned __int64)(3 * v9->rejected) >> 32;
        LODWORD(v13) = 96 * LODWORD(v9->rejected);
        snprintf(
          tmp42,
          0x1000u,
          " Reject ratio: %.1f%%",
          (double)(__int64)(__PAIR64__((unsigned __int64)(96 * v9->rejected) >> 32, 3 * LODWORD(v9->rejected))
                          + v13
                          + v9->rejected)
        / (double)(v9->rejected + accepted));
        applog(4, tmp42, 0);
      }
      if ( !use_syslog && !opt_log_output )
        goto LABEL_117;
LABEL_80:
      snprintf(tmp42, 0x1000u, " Items worked on: %d", v9->works);
      applog(4, tmp42, 0);
      if ( use_syslog || opt_log_output )
      {
LABEL_82:
        snprintf(tmp42, 0x1000u, " Stale submissions discarded due to new blocks: %d", v9->stale_shares);
        applog(4, tmp42, 0);
        if ( use_syslog || opt_log_output )
          goto LABEL_84;
        goto LABEL_119;
      }
LABEL_118:
      if ( opt_log_level > 3 )
        goto LABEL_82;
LABEL_119:
      if ( opt_log_level <= 3 )
        goto LABEL_120;
LABEL_84:
      snprintf(tmp42, 0x1000u, " Unable to get work from server occasions: %d", v9->getfail_occasions);
      applog(4, tmp42, 0);
      if ( !use_syslog && !opt_log_output )
      {
LABEL_120:
        if ( opt_log_level <= 3 )
          goto LABEL_87;
      }
      snprintf(tmp42, 0x1000u, " Submitting work remotely delay occasions: %d\n", v9->remotefail_occasions);
      applog(4, tmp42, 0);
LABEL_87:
      if ( total_pools <= ++v8 )
        goto LABEL_88;
    }
    snprintf(tmp42, 0x1000u, "Pool: %s", v9->rpc_url);
    applog(4, tmp42, 0);
    solved = v9->solved;
    if ( solved )
    {
      if ( !use_syslog && !opt_log_output )
      {
LABEL_52:
        if ( opt_log_level <= 3 )
          goto LABEL_110;
      }
      v11 = "S";
      if ( solved <= 1 )
        v11 = &byte_59398;
      snprintf(tmp42, 0x1000u, "SOLVED %d BLOCK%s!", solved, v11);
      applog(4, tmp42, 0);
    }
    if ( use_syslog )
      goto LABEL_64;
    goto LABEL_63;
  }
LABEL_88:
  if ( use_syslog || opt_log_output )
    goto LABEL_90;
LABEL_141:
  if ( opt_log_level > 3 )
  {
LABEL_90:
    strcpy(tmp42, "Summary of per device statistics:\n");
    applog(4, tmp42, 0);
  }
  if ( total_devices > 0 )
  {
    v14 = 0;
    do
    {
      devices = get_devices(v14++);
      devices->drv->get_statline_before = blank_get_statline_before;
      devices->drv->get_statline = (void (*)(char *, size_t, cgpu_info *))noop_get_statline;
      get_statline(v19, 0xFFu, devices);
      if ( use_syslog || opt_log_output || opt_log_level > 3 )
      {
        snprintf(tmp42, 0x1000u, "%s", v19);
        applog(4, tmp42, 0);
      }
    }
    while ( total_devices > v14 );
  }
  v16 = opt_shares;
  v17 = use_syslog;
  if ( opt_shares )
  {
    v18 = total_diff_accepted;
    if ( !use_syslog && !opt_log_output && opt_log_level <= 3 )
    {
      if ( (double)opt_shares <= total_diff_accepted )
        goto LABEL_143;
      goto LABEL_103;
    }
    snprintf(tmp42, 0x1000u, "Mined %.0f accepted shares of %d requested\n", total_diff_accepted, opt_shares);
    applog(4, tmp42, 0);
    v18 = total_diff_accepted;
    v16 = opt_shares;
    v17 = use_syslog;
    if ( (double)opt_shares > total_diff_accepted )
    {
      if ( use_syslog )
      {
LABEL_105:
        snprintf(tmp42, 0x1000u, "WARNING - Mined only %.0f shares of %d requested.", v18, v16);
        applog(4, tmp42, 0);
        v17 = use_syslog;
        goto LABEL_106;
      }
LABEL_103:
      if ( !opt_log_output && opt_log_level <= 3 )
      {
LABEL_143:
        if ( opt_log_level <= 3 )
          goto LABEL_109;
        goto LABEL_108;
      }
      goto LABEL_105;
    }
  }
LABEL_106:
  if ( !v17 && !opt_log_output )
    goto LABEL_143;
LABEL_108:
  strcpy(tmp42, " ");
  applog(4, tmp42, 0);
LABEL_109:
  fflush((FILE *)stderr);
  fflush((FILE *)stdout);
}
