int sub_1AECC()
{
  int v0; // r3
  double v1; // d9
  int v2; // r7
  int v3; // r5
  int v4; // r9
  double v5; // r0
  double v6; // d10
  double v7; // r0
  double v8; // d9
  __int64 v9; // r6
  __int64 v10; // r10
  int v11; // r1
  double v12; // d8
  double v13; // r0
  int v14; // r11
  int v15; // r1
  int v16; // r2
  __int64 v17; // r4
  __int64 v18; // kr08_8
  int v19; // r1
  double v20; // d8
  double v21; // r0
  int v22; // r4
  int v23; // r0
  int v24; // r0
  int v25; // r2
  double v26; // d16
  int v27; // r3
  const char *v29; // r2
  int v30; // [sp+18h] [bp-914h]
  char v31[256]; // [sp+28h] [bp-904h] BYREF
  char s[2052]; // [sp+128h] [bp-804h] BYREF

  v0 = dword_613E4 - dword_61370;
  if ( dword_613E8 - dword_61374 < 0 )
    --v0;
  v1 = dbl_5F898;
  v2 = v0 / 3600;
  v3 = v0 % 60;
  v4 = v0 % 3600 / 60;
  LODWORD(v5) = sub_493DC(qword_639C8);
  v6 = v5 / v1 * 60.0;
  LODWORD(v7) = sub_493DC(*(__int64 *)&dword_636A8);
  v8 = v7 / v1 * 60.0;
  if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
  {
    strcpy(s, "\nSummary of runtime statistics:\n");
    sub_38438(4, s, 0);
    if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
    {
      snprintf(s, 0x800u, "Started at %s", byte_613EC);
      sub_38438(4, s, 0);
    }
  }
  if ( dword_63740 == 1 )
  {
    if ( !byte_632F0 && !byte_630C0 && dword_60964 <= 3 )
      goto LABEL_28;
    snprintf(s, 0x800u, "Pool: %s", *(const char **)(*(_DWORD *)dword_639E0 + 164));
    sub_38438(4, s, 0);
  }
  if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
  {
    snprintf(s, 0x800u, "Runtime: %d hrs : %d mins : %d secs", v2, v4, v3);
    sub_38438(4, s, 0);
    if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
    {
      snprintf(s, 0x800u, "Average hashrate: %.1f Mhash/s", dbl_63268 / dbl_5F898);
      sub_38438(4, s, 0);
      if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
      {
        snprintf(s, 0x800u, "Solved blocks: %d", dword_63E58);
        sub_38438(4, s, 0);
        if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
        {
          snprintf(s, 0x800u, "Best share difficulty: %s", (const char *)&dword_60064);
          sub_38438(4, s, 0);
          if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
          {
            snprintf(s, 0x800u, "Share submissions: %lld", qword_63C98 + qword_639C8);
            sub_38438(4, s, 0);
            if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
            {
              snprintf(s, 0x800u, "Accepted shares: %lld", qword_639C8);
              sub_38438(4, s, 0);
              if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
              {
                snprintf(s, 0x800u, "Rejected shares: %lld", qword_63C98);
                sub_38438(4, s, 0);
                if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
                {
                  snprintf(s, 0x800u, "Accepted difficulty shares: %1.f", dbl_63B88);
                  sub_38438(4, s, 0);
                  if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
                  {
                    snprintf(s, 0x800u, "Rejected difficulty shares: %1.f", dbl_63C10);
                    sub_38438(4, s, 0);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_28:
  v9 = qword_639C8;
  if ( qword_639C8 || qword_63C98 )
  {
    if ( !byte_632F0 && !byte_630C0 && dword_60964 <= 3 )
      goto LABEL_50;
    v10 = qword_63C98;
    LODWORD(v12) = sub_493DC(100 * qword_63C98);
    HIDWORD(v12) = v11;
    LODWORD(v13) = sub_493DC(v9 + v10);
    snprintf(s, 0x800u, "Reject ratio: %.1f%%", v12 / v13);
    sub_38438(4, s, 0);
  }
  if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
  {
    snprintf(s, 0x800u, "Hardware errors: %d", dword_63E44);
    sub_38438(4, s, 0);
    if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
    {
      snprintf(s, 0x800u, "Utility (accepted shares / min): %.2f/min", v6);
      sub_38438(4, s, 0);
      if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
      {
        snprintf(s, 0x800u, "Work Utility (diff1 shares solved / min): %.2f/min\n", v8);
        sub_38438(4, s, 0);
        if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
        {
          snprintf(s, 0x800u, "Stale submissions discarded due to new blocks: %lld", *(_QWORD *)&dword_64220);
          sub_38438(4, s, 0);
          if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
          {
            snprintf(s, 0x800u, "Unable to get work from server occasions: %d", dword_639E4);
            sub_38438(4, s, 0);
            if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
            {
              snprintf(s, 0x800u, "Work items generated locally: %d", dword_63A70);
              sub_38438(4, s, 0);
              if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
              {
                snprintf(s, 0x800u, "Submitting work remotely delay occasions: %d", dword_63410);
                sub_38438(4, s, 0);
                if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
                {
                  snprintf(s, 0x800u, "New blocks detected on network: %d\n", dword_640BC);
                  sub_38438(4, s, 0);
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_50:
  if ( dword_63740 > 1 )
  {
    v30 = 0;
    while ( 1 )
    {
      v14 = *(_DWORD *)(dword_639E0 + 4 * v30);
      if ( !byte_632F0 && !byte_630C0 && dword_60964 <= 3 )
        break;
      snprintf(s, 0x800u, "Pool: %s", *(const char **)(v14 + 164));
      sub_38438(4, s, 0);
      v15 = *(_DWORD *)(v14 + 32);
      v16 = (unsigned __int8)byte_632F0;
      if ( !v15 )
        goto LABEL_103;
      if ( !byte_632F0 )
        goto LABEL_59;
LABEL_100:
      v29 = "S";
      if ( v15 <= 1 )
        v29 = "";
      snprintf(s, 0x800u, "SOLVED %d BLOCK%s!", v15, v29);
      sub_38438(4, s, 0);
      v16 = (unsigned __int8)byte_632F0;
LABEL_103:
      if ( !v16 )
      {
LABEL_104:
        if ( !byte_630C0 && dword_60964 <= 3 )
          goto LABEL_61;
      }
      snprintf(s, 0x800u, " Share submissions: %lld", *(_QWORD *)(v14 + 16) + *(_QWORD *)(v14 + 8));
      sub_38438(4, s, 0);
      if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
      {
        snprintf(s, 0x800u, " Accepted shares: %lld", *(_QWORD *)(v14 + 8));
        sub_38438(4, s, 0);
        if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
        {
          snprintf(s, 0x800u, " Rejected shares: %lld", *(_QWORD *)(v14 + 16));
          sub_38438(4, s, 0);
          if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
          {
            snprintf(s, 0x800u, " Accepted difficulty shares: %1.f", *(double *)(v14 + 72));
            sub_38438(4, s, 0);
            if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
            {
              snprintf(s, 0x800u, " Rejected difficulty shares: %1.f", *(double *)(v14 + 80));
              sub_38438(4, s, 0);
            }
          }
        }
      }
LABEL_61:
      if ( !*(_QWORD *)(v14 + 8) && !*(_QWORD *)(v14 + 16) )
        goto LABEL_67;
      if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
      {
        v17 = *(_QWORD *)(v14 + 16);
        v18 = *(_QWORD *)(v14 + 8);
        LODWORD(v20) = sub_493DC(100 * v17);
        HIDWORD(v20) = v19;
        LODWORD(v21) = sub_493DC(v18 + v17);
        snprintf(s, 0x800u, " Reject ratio: %.1f%%", v20 / v21);
        sub_38438(4, s, 0);
LABEL_67:
        if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
        {
          snprintf(s, 0x800u, " Items worked on: %d", *(_DWORD *)(v14 + 68));
          sub_38438(4, s, 0);
          if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
          {
            snprintf(s, 0x800u, " Stale submissions discarded due to new blocks: %d", *(_DWORD *)(v14 + 120));
            sub_38438(4, s, 0);
            if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
            {
              snprintf(s, 0x800u, " Unable to get work from server occasions: %d", *(_DWORD *)(v14 + 128));
              sub_38438(4, s, 0);
              if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
              {
                snprintf(s, 0x800u, " Submitting work remotely delay occasions: %d\n", *(_DWORD *)(v14 + 132));
                sub_38438(4, s, 0);
              }
            }
          }
        }
      }
      if ( dword_63740 <= ++v30 )
        goto LABEL_77;
    }
    v15 = *(_DWORD *)(v14 + 32);
    if ( !v15 )
      goto LABEL_104;
LABEL_59:
    if ( !byte_630C0 && dword_60964 <= 3 )
      goto LABEL_61;
    goto LABEL_100;
  }
LABEL_77:
  if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
  {
    strcpy(s, "Summary of per device statistics:\n");
    sub_38438(4, s, 0);
  }
  if ( dword_63CC0 > 0 )
  {
    v22 = 0;
    do
    {
      v23 = v22++;
      v24 = sub_1AB68(v23);
      *(_DWORD *)(*(_DWORD *)(v24 + 4) + 20) = nullsub_1;
      *(_DWORD *)(*(_DWORD *)(v24 + 4) + 24) = nullsub_3;
      sub_1715C(v31, 0xFFu, v24);
      if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
      {
        snprintf(s, 0x800u, "%s", v31);
        sub_38438(4, s, 0);
      }
    }
    while ( dword_63CC0 > v22 );
  }
  v25 = dword_61414;
  if ( !dword_61414 )
    goto LABEL_95;
  if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
  {
    snprintf(s, 0x800u, "Mined %.0f accepted shares of %d requested\n", dbl_63B88, dword_61414);
    sub_38438(4, s, 0);
    v25 = dword_61414;
    v26 = dbl_63B88;
    v27 = (unsigned __int8)byte_632F0;
    if ( (double)dword_61414 <= dbl_63B88 )
      goto LABEL_96;
    if ( byte_632F0 )
      goto LABEL_94;
  }
  else
  {
    v26 = dbl_63B88;
    if ( (double)dword_61414 <= dbl_63B88 )
    {
LABEL_97:
      if ( !byte_630C0 && dword_60964 <= 3 )
        goto LABEL_99;
LABEL_98:
      strcpy(s, " ");
      sub_38438(4, s, 0);
      goto LABEL_99;
    }
  }
  if ( byte_630C0 || dword_60964 > 3 )
  {
LABEL_94:
    snprintf(s, 0x800u, "WARNING - Mined only %.0f shares of %d requested.", v26, v25);
    sub_38438(4, s, 0);
LABEL_95:
    v27 = (unsigned __int8)byte_632F0;
LABEL_96:
    if ( v27 )
      goto LABEL_98;
    goto LABEL_97;
  }
LABEL_99:
  fflush((FILE *)stderr);
  return fflush((FILE *)stdout);
}
