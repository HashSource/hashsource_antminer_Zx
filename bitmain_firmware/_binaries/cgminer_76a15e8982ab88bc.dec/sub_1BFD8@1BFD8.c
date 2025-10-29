int sub_1BFD8()
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
  int v30; // [sp+18h] [bp-1114h]
  char v31[256]; // [sp+28h] [bp-1104h] BYREF
  char s[4100]; // [sp+128h] [bp-1004h] BYREF

  v0 = dword_73F80 - dword_73F08;
  if ( dword_73F84 - dword_73F0C < 0 )
    --v0;
  v1 = dbl_72438;
  v2 = v0 / 3600;
  v3 = v0 % 60;
  v4 = v0 % 3600 / 60;
  LODWORD(v5) = sub_59F1C(qword_78248);
  v6 = v5 / v1 * 60.0;
  LODWORD(v7) = sub_59F1C(*(__int64 *)&dword_77F28);
  v8 = v7 / v1 * 60.0;
  if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
  {
    strcpy(s, "\nSummary of runtime statistics:\n");
    sub_385C8(4, s, 0);
    if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
    {
      snprintf(s, 0x1000u, "Started at %s", byte_74098);
      sub_385C8(4, s, 0);
    }
  }
  if ( dword_77FC0 == 1 )
  {
    if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 3 )
      goto LABEL_28;
    snprintf(s, 0x1000u, "Pool: %s", *(const char **)(*(_DWORD *)dword_78260 + 196));
    sub_385C8(4, s, 0);
  }
  if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
  {
    snprintf(s, 0x1000u, "Runtime: %d hrs : %d mins : %d secs", v2, v4, v3);
    sub_385C8(4, s, 0);
    if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
    {
      snprintf(s, 0x1000u, "Average hashrate: %.1f Mhash/s", dbl_77AE8 / dbl_72438);
      sub_385C8(4, s, 0);
      if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
      {
        snprintf(s, 0x1000u, "Solved blocks: %d", dword_786E0);
        sub_385C8(4, s, 0);
        if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
        {
          snprintf(s, 0x1000u, "Best share difficulty: %s", (const char *)&dword_72C04);
          sub_385C8(4, s, 0);
          if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
          {
            snprintf(s, 0x1000u, "Share submissions: %lld", qword_78520 + qword_78248);
            sub_385C8(4, s, 0);
            if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
            {
              snprintf(s, 0x1000u, "Accepted shares: %lld", qword_78248);
              sub_385C8(4, s, 0);
              if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
              {
                snprintf(s, 0x1000u, "Rejected shares: %lld", qword_78520);
                sub_385C8(4, s, 0);
                if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
                {
                  snprintf(s, 0x1000u, "Accepted difficulty shares: %1.f", dbl_78410);
                  sub_385C8(4, s, 0);
                  if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
                  {
                    snprintf(s, 0x1000u, "Rejected difficulty shares: %1.f", dbl_78498);
                    sub_385C8(4, s, 0);
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
  v9 = qword_78248;
  if ( qword_78248 || qword_78520 )
  {
    if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 3 )
      goto LABEL_50;
    v10 = qword_78520;
    LODWORD(v12) = sub_59F1C(100 * qword_78520);
    HIDWORD(v12) = v11;
    LODWORD(v13) = sub_59F1C(v9 + v10);
    snprintf(s, 0x1000u, "Reject ratio: %.1f%%", v12 / v13);
    sub_385C8(4, s, 0);
  }
  if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
  {
    snprintf(s, 0x1000u, "Hardware errors: %d", dword_786CC);
    sub_385C8(4, s, 0);
    if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
    {
      snprintf(s, 0x1000u, "Utility (accepted shares / min): %.2f/min", v6);
      sub_385C8(4, s, 0);
      if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
      {
        snprintf(s, 0x1000u, "Work Utility (diff1 shares solved / min): %.2f/min\n", v8);
        sub_385C8(4, s, 0);
        if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
        {
          snprintf(s, 0x1000u, "Stale submissions discarded due to new blocks: %lld", *(_QWORD *)&dword_78AA8);
          sub_385C8(4, s, 0);
          if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
          {
            snprintf(s, 0x1000u, "Unable to get work from server occasions: %d", dword_78264);
            sub_385C8(4, s, 0);
            if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
            {
              snprintf(s, 0x1000u, "Work items generated locally: %d", dword_782F4);
              sub_385C8(4, s, 0);
              if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
              {
                snprintf(s, 0x1000u, "Submitting work remotely delay occasions: %d", dword_77C90);
                sub_385C8(4, s, 0);
                if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
                {
                  snprintf(s, 0x1000u, "New blocks detected on network: %d\n", dword_78944);
                  sub_385C8(4, s, 0);
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_50:
  if ( dword_77FC0 > 1 )
  {
    v30 = 0;
    while ( 1 )
    {
      v14 = *(_DWORD *)(dword_78260 + 4 * v30);
      if ( !byte_77B70 && !byte_75C48 && dword_73504 <= 3 )
        break;
      snprintf(s, 0x1000u, "Pool: %s", *(const char **)(v14 + 196));
      sub_385C8(4, s, 0);
      v15 = *(_DWORD *)(v14 + 32);
      v16 = (unsigned __int8)byte_77B70;
      if ( !v15 )
        goto LABEL_103;
      if ( !byte_77B70 )
        goto LABEL_59;
LABEL_100:
      v29 = "S";
      if ( v15 <= 1 )
        v29 = "";
      snprintf(s, 0x1000u, "SOLVED %d BLOCK%s!", v15, v29);
      sub_385C8(4, s, 0);
      v16 = (unsigned __int8)byte_77B70;
LABEL_103:
      if ( !v16 )
      {
LABEL_104:
        if ( !byte_75C48 && dword_73504 <= 3 )
          goto LABEL_61;
      }
      snprintf(s, 0x1000u, " Share submissions: %lld", *(_QWORD *)(v14 + 16) + *(_QWORD *)(v14 + 8));
      sub_385C8(4, s, 0);
      if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
      {
        snprintf(s, 0x1000u, " Accepted shares: %lld", *(_QWORD *)(v14 + 8));
        sub_385C8(4, s, 0);
        if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
        {
          snprintf(s, 0x1000u, " Rejected shares: %lld", *(_QWORD *)(v14 + 16));
          sub_385C8(4, s, 0);
          if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
          {
            snprintf(s, 0x1000u, " Accepted difficulty shares: %1.f", *(double *)(v14 + 104));
            sub_385C8(4, s, 0);
            if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
            {
              snprintf(s, 0x1000u, " Rejected difficulty shares: %1.f", *(double *)(v14 + 112));
              sub_385C8(4, s, 0);
            }
          }
        }
      }
LABEL_61:
      if ( !*(_QWORD *)(v14 + 8) && !*(_QWORD *)(v14 + 16) )
        goto LABEL_67;
      if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
      {
        v17 = *(_QWORD *)(v14 + 16);
        v18 = *(_QWORD *)(v14 + 8);
        LODWORD(v20) = sub_59F1C(100 * v17);
        HIDWORD(v20) = v19;
        LODWORD(v21) = sub_59F1C(v18 + v17);
        snprintf(s, 0x1000u, " Reject ratio: %.1f%%", v20 / v21);
        sub_385C8(4, s, 0);
LABEL_67:
        if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
        {
          snprintf(s, 0x1000u, " Items worked on: %d", *(_DWORD *)(v14 + 68));
          sub_385C8(4, s, 0);
          if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
          {
            snprintf(s, 0x1000u, " Stale submissions discarded due to new blocks: %d", *(_DWORD *)(v14 + 152));
            sub_385C8(4, s, 0);
            if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
            {
              snprintf(s, 0x1000u, " Unable to get work from server occasions: %d", *(_DWORD *)(v14 + 160));
              sub_385C8(4, s, 0);
              if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
              {
                snprintf(s, 0x1000u, " Submitting work remotely delay occasions: %d\n", *(_DWORD *)(v14 + 164));
                sub_385C8(4, s, 0);
              }
            }
          }
        }
      }
      if ( dword_77FC0 <= ++v30 )
        goto LABEL_77;
    }
    v15 = *(_DWORD *)(v14 + 32);
    if ( !v15 )
      goto LABEL_104;
LABEL_59:
    if ( !byte_75C48 && dword_73504 <= 3 )
      goto LABEL_61;
    goto LABEL_100;
  }
LABEL_77:
  if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
  {
    strcpy(s, "Summary of per device statistics:\n");
    sub_385C8(4, s, 0);
  }
  if ( dword_78548 > 0 )
  {
    v22 = 0;
    do
    {
      v23 = v22++;
      v24 = sub_1B1A8(v23);
      *(_DWORD *)(*(_DWORD *)(v24 + 4) + 20) = nullsub_2;
      *(_DWORD *)(*(_DWORD *)(v24 + 4) + 24) = nullsub_4;
      sub_1767C(v31, 0xFFu, v24);
      if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
      {
        snprintf(s, 0x1000u, "%s", v31);
        sub_385C8(4, s, 0);
      }
    }
    while ( dword_78548 > v22 );
  }
  v25 = dword_740C0;
  if ( !dword_740C0 )
    goto LABEL_95;
  if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
  {
    snprintf(s, 0x1000u, "Mined %.0f accepted shares of %d requested\n", dbl_78410, dword_740C0);
    sub_385C8(4, s, 0);
    v25 = dword_740C0;
    v26 = dbl_78410;
    v27 = (unsigned __int8)byte_77B70;
    if ( (double)dword_740C0 <= dbl_78410 )
      goto LABEL_96;
    if ( byte_77B70 )
      goto LABEL_94;
  }
  else
  {
    v26 = dbl_78410;
    if ( (double)dword_740C0 <= dbl_78410 )
    {
LABEL_97:
      if ( !byte_75C48 && dword_73504 <= 3 )
        goto LABEL_99;
LABEL_98:
      strcpy(s, " ");
      sub_385C8(4, s, 0);
      goto LABEL_99;
    }
  }
  if ( byte_75C48 || dword_73504 > 3 )
  {
LABEL_94:
    snprintf(s, 0x1000u, "WARNING - Mined only %.0f shares of %d requested.", v26, v25);
    sub_385C8(4, s, 0);
LABEL_95:
    v27 = (unsigned __int8)byte_77B70;
LABEL_96:
    if ( v27 )
      goto LABEL_98;
    goto LABEL_97;
  }
LABEL_99:
  fflush((FILE *)stderr);
  return fflush((FILE *)stdout);
}
