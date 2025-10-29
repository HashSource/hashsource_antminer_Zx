void __noreturn sub_21364()
{
  int v0; // r2
  int v1; // r5
  int v2; // r4
  __int64 v3; // r10
  double v4; // r0
  double v5; // d16
  double v6; // d16
  int v7; // r9
  _DWORD *v8; // r3
  _DWORD *v9; // r2
  int v10; // r11
  int v11; // r3
  int v12; // r9
  int v13; // r5
  int v14; // r3
  _DWORD *v15; // r3
  int v16; // r12
  int v17; // r3
  const char *v18; // r9
  int v19; // r10
  int v20; // r11
  int v21; // r3
  int v22; // r9
  int v23; // r5
  int v24; // r4
  int v25; // r1
  int **v26; // r3
  int v27; // r0
  int *v28; // r12
  bool v29; // zf
  int v30; // r1
  int v31; // r0
  int v32; // r0
  int v33; // r1
  int v34; // r1
  int v35; // r3
  __int64 v36; // r2
  void **v37; // [sp+10h] [bp-824h]
  int v38; // [sp+14h] [bp-820h]
  pthread_mutex_t *mutex; // [sp+18h] [bp-81Ch]
  pthread_mutex_t *mutexa; // [sp+18h] [bp-81Ch]
  int v41; // [sp+1Ch] [bp-818h]
  struct timeval v42; // [sp+20h] [bp-814h] BYREF
  struct timeval v43; // [sp+28h] [bp-80Ch] BYREF
  char s[2052]; // [sp+30h] [bp-804h] BYREF

  pthread_setcanceltype(1, 0);
  sub_2F02C("Watchpool");
  sub_11C4C();
  v38 = 0;
  while ( 1 )
  {
    sub_2B13C(&v42);
    v0 = v38 + 1;
    if ( v38 + 1 > 20 )
      v0 = 0;
    v38 = v0;
    if ( dword_63740 > 0 )
    {
      v1 = 0;
      while ( 1 )
      {
        v2 = *(_DWORD *)(dword_639E0 + 4 * v1);
        if ( byte_615C9 || dword_612AC )
          goto LABEL_11;
        mutex = (pthread_mutex_t *)(v2 + 188);
        sub_2B13C(&v43);
        if ( pthread_mutex_lock((pthread_mutex_t *)(v2 + 188)) )
          sub_B4E4("reap_curl", 9507);
        v8 = *(_DWORD **)(v2 + 344);
        v9 = v8 - 1;
        v10 = *v8 - 4;
        if ( (_DWORD *)(v2 + 344) == v8 )
        {
          v12 = 0;
          if ( pthread_mutex_unlock(mutex) )
            goto LABEL_95;
        }
        else
        {
          v11 = *(_DWORD *)(v2 + 288);
          v12 = 0;
          if ( v11 > 1 )
          {
            v41 = v1;
            v13 = 0;
            do
            {
              if ( v43.tv_sec - v9[3] > 300 )
              {
                *(_DWORD *)(v2 + 288) = v11 - 1;
                v15 = (_DWORD *)v9[2];
                v16 = v9[1];
                ++v13;
                *(_DWORD *)(v16 + 4) = v15;
                *v15 = v16;
                v9[1] = 0;
                v9[2] = 0;
                free(v9);
              }
              v9 = (_DWORD *)v10;
              v14 = v10 + 4;
              v10 = *(_DWORD *)(v10 + 4) - 4;
              if ( v2 + 344 == v14 )
                break;
              v11 = *(_DWORD *)(v2 + 288);
            }
            while ( v11 > 1 );
            v12 = v13;
            v1 = v41;
          }
          if ( pthread_mutex_unlock(mutex) )
LABEL_95:
            sub_B694("reap_curl", 9521);
        }
        off_60178();
        if ( v12 && byte_630C1 && (byte_632F0 || byte_630C0 || dword_60964 > 6) )
        {
          v17 = v12;
          if ( v12 == 1 )
            v18 = "";
          else
            v18 = "s";
          snprintf(s, 0x800u, "Reaped %d curl%s from pool %d", v17, v18, *(_DWORD *)v2);
          sub_38438(7, s, 0);
        }
        mutexa = (pthread_mutex_t *)time(0);
        if ( pthread_mutex_lock(&stru_612DC) )
          sub_B4E4("prune_stratum_shares", 9536);
        v19 = dword_612F4;
        if ( !dword_612F4 )
        {
          v20 = 0;
          goto LABEL_81;
        }
        v21 = v1;
        v22 = *(_DWORD *)(dword_612F4 + 8);
        v23 = v2;
        v20 = 0;
        v24 = v21;
        while ( v23 != *(_DWORD *)(*(_DWORD *)(v19 + 36) + 260) || (int)mutexa <= *(_DWORD *)(v19 + 44) + 120 )
        {
          if ( !v22 )
            goto LABEL_80;
LABEL_56:
          v19 = v22;
          v22 = *(_DWORD *)(v22 + 8);
        }
        v25 = *(_DWORD *)(v19 + 4);
        if ( v25 || *(_DWORD *)(v19 + 8) )
        {
          v26 = (int **)dword_612F4;
          v27 = *(_DWORD *)dword_612F4;
          v28 = *(int **)(*(_DWORD *)dword_612F4 + 20);
          if ( v19 == *(_DWORD *)(*(_DWORD *)dword_612F4 + 16) - (_DWORD)v28 )
          {
            *(_DWORD *)(v27 + 16) = (char *)v28 + v25;
            v25 = *(_DWORD *)(v19 + 4);
          }
          v29 = v25 == 0;
          if ( v25 )
          {
            v28 = *v26;
            v27 = *(_DWORD *)(v19 + 8);
          }
          else
          {
            v25 = *(_DWORD *)(v19 + 8);
          }
          if ( v29 )
          {
            v26 = (int **)v25;
            dword_612F4 = v25;
          }
          else
          {
            v25 += v28[5];
          }
          if ( !v29 )
          {
            *(_DWORD *)(v25 + 8) = v27;
            v25 = *(_DWORD *)(v19 + 8);
          }
          if ( v25 )
            *(_DWORD *)(v25 + (*v26)[5] + 4) = *(_DWORD *)(v19 + 4);
          v30 = 3 * (((*v26)[1] - 1) & *(_DWORD *)(v19 + 28));
          v31 = **v26 + 12 * (((*v26)[1] - 1) & *(_DWORD *)(v19 + 28));
          --*(_DWORD *)(v31 + 4);
          v32 = **v26;
          if ( v19 == *(_DWORD *)(v32 + 4 * v30) )
            *(_DWORD *)(v32 + 4 * v30) = *(_DWORD *)(v19 + 16);
          v33 = *(_DWORD *)(v19 + 12);
          if ( v33 )
            *(_DWORD *)(v33 + 16) = *(_DWORD *)(v19 + 16);
          v34 = *(_DWORD *)(v19 + 16);
          if ( v34 )
            *(_DWORD *)(v34 + 12) = *(_DWORD *)(v19 + 12);
          --(*v26)[3];
        }
        else
        {
          v37 = (void **)dword_612F4;
          free(**(void ***)dword_612F4);
          free(*v37);
          dword_612F4 = 0;
        }
        ++v20;
        sub_152B8(*(void ***)(v19 + 36));
        *(_DWORD *)(v19 + 36) = 0;
        free((void *)v19);
        if ( v22 )
          goto LABEL_56;
LABEL_80:
        v35 = v24;
        v2 = v23;
        v1 = v35;
LABEL_81:
        if ( pthread_mutex_unlock(&stru_612DC) )
          sub_B694("prune_stratum_shares", 9547);
        off_60178();
        if ( v20 )
        {
          if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
          {
            snprintf(s, 0x800u, "Lost %d shares due to no stratum share response from pool %d", v20, *(_DWORD *)v2);
            sub_38438(4, s, 0);
          }
          v36 = *(_QWORD *)&dword_64220;
          *(_DWORD *)(v2 + 120) += v20;
          *(_QWORD *)&dword_64220 = v36 + v20;
        }
LABEL_11:
        if ( v38 == 20 )
        {
          v3 = *(_QWORD *)(v2 + 40);
          LODWORD(v4) = sub_493DC(v3 - *(int *)(v2 + 152));
          v5 = *(double *)(v2 + 144);
          *(_DWORD *)(v2 + 152) = v3;
          v6 = (v5 + v4 * 0.63) / 1.63;
          *(double *)(v2 + 144) = v6;
          *(_DWORD *)(v2 + 156) = (int)v6;
        }
        if ( !*(_DWORD *)(v2 + 100) || *(_BYTE *)(v2 + 284) )
          goto LABEL_8;
        if ( !*(_BYTE *)(v2 + 97) )
        {
LABEL_7:
          if ( !dword_611AC )
          {
            v7 = *(_DWORD *)(v2 + 4);
            if ( v7 < sub_1F70C() && v42.tv_sec - *(_DWORD *)(v2 + 136) > 300 )
            {
              if ( byte_632F0 || byte_630C0 || dword_60964 > 3 )
              {
                snprintf(s, 0x800u, "Pool %d %s stable for 5 mins", *(_DWORD *)v2, *(const char **)(v2 + 164));
                sub_38438(4, s, 0);
              }
              sub_195D4(0);
            }
          }
          goto LABEL_8;
        }
        if ( v42.tv_sec - *(_DWORD *)(v2 + 136) <= 30 )
        {
LABEL_8:
          if ( dword_63740 <= ++v1 )
            break;
        }
        else
        {
          if ( sub_182A0((_DWORD *)v2, 1) && sub_1822C(v2, (_BYTE *)(v2 + 97)) )
            sub_1F7C4((_DWORD *)v2);
          else
            sub_2B13C((struct timeval *)(v2 + 136));
          if ( !*(_BYTE *)(v2 + 97) )
            goto LABEL_7;
          if ( dword_63740 <= ++v1 )
            break;
        }
      }
    }
    if ( *(_BYTE *)(sub_1D644() + 97) )
    {
      sub_195D4(0);
      if ( dword_611AC != 2 )
        goto LABEL_24;
    }
    else if ( dword_611AC != 2 )
    {
      goto LABEL_24;
    }
    if ( v42.tv_sec - stru_615CC.tv_sec > 60 * dword_63AF8 )
    {
      sub_2B13C(&stru_615CC);
      sub_195D4(0);
    }
LABEL_24:
    sub_2B21C();
  }
}
