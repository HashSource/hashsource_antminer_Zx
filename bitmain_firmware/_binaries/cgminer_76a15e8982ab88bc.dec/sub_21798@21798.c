void __noreturn sub_21798()
{
  int v0; // r2
  int v1; // r6
  int v2; // r4
  __int64 v3; // r10
  double v4; // r0
  double v5; // d16
  double v6; // d16
  int v7; // r5
  _DWORD *v8; // r3
  _DWORD *v9; // r2
  int v10; // r5
  int v11; // r3
  int v12; // r10
  int v13; // r12
  int v14; // r6
  int v15; // r3
  _DWORD *v16; // r3
  int v17; // lr
  int v18; // r3
  const char *v19; // r10
  int v20; // r11
  int v21; // r10
  int v22; // r3
  int v23; // r5
  int v24; // r6
  int v25; // r4
  int v26; // r1
  int **v27; // r3
  int v28; // r0
  int *v29; // r12
  bool v30; // zf
  int v31; // r1
  int v32; // r0
  int v33; // r0
  int v34; // r1
  int v35; // r1
  int v36; // r3
  __int64 v37; // r2
  int v38; // [sp+10h] [bp-1024h]
  void **v39; // [sp+10h] [bp-1024h]
  int v40; // [sp+14h] [bp-1020h]
  pthread_mutex_t *mutex; // [sp+18h] [bp-101Ch]
  pthread_mutex_t *mutexa; // [sp+18h] [bp-101Ch]
  int v43; // [sp+1Ch] [bp-1018h]
  struct timeval v44; // [sp+20h] [bp-1014h] BYREF
  struct timeval v45; // [sp+28h] [bp-100Ch] BYREF
  char s[4048]; // [sp+30h] [bp-1004h] BYREF

  pthread_setcanceltype(1, 0);
  sub_2EF24("Watchpool");
  sub_1202C();
  v40 = 0;
  while ( 1 )
  {
    sub_2A7A4(&v44);
    v0 = v40 + 1;
    if ( v40 + 1 > 20 )
      v0 = 0;
    v40 = v0;
    if ( dword_77FC0 > 0 )
    {
      v1 = 0;
      while ( 1 )
      {
        v2 = *(_DWORD *)(dword_78260 + 4 * v1);
        if ( byte_74149 || dword_73E34 )
          goto LABEL_11;
        mutex = (pthread_mutex_t *)(v2 + 220);
        sub_2A7A4(&v45);
        if ( pthread_mutex_lock((pthread_mutex_t *)(v2 + 220)) )
          sub_B35C("reap_curl", 9490);
        v8 = *(_DWORD **)(v2 + 376);
        v9 = v8 - 1;
        v10 = *v8 - 4;
        if ( (_DWORD *)(v2 + 376) == v8 )
        {
          v12 = 0;
          if ( pthread_mutex_unlock(mutex) )
            goto LABEL_95;
        }
        else
        {
          v11 = *(_DWORD *)(v2 + 320);
          v12 = 0;
          if ( v11 > 1 )
          {
            v13 = 0;
            v43 = v1;
            v14 = 0;
            do
            {
              if ( v45.tv_sec - v9[3] > 300 )
              {
                *(_DWORD *)(v2 + 320) = v11 - 1;
                v16 = (_DWORD *)v9[2];
                v17 = v9[1];
                ++v14;
                *(_DWORD *)(v17 + 4) = v16;
                *v16 = v17;
                v9[1] = v13;
                v9[2] = v13;
                v38 = v13;
                free(v9);
                v13 = v38;
              }
              v9 = (_DWORD *)v10;
              v15 = v10 + 4;
              v10 = *(_DWORD *)(v10 + 4) - 4;
              if ( v2 + 376 == v15 )
                break;
              v11 = *(_DWORD *)(v2 + 320);
            }
            while ( v11 > 1 );
            v12 = v14;
            v1 = v43;
          }
          if ( pthread_mutex_unlock(mutex) )
LABEL_95:
            sub_B50C("reap_curl", 9504);
        }
        off_72D18();
        if ( v12 && byte_75C49 && (byte_77B70 || byte_75C48 || dword_73504 > 6) )
        {
          v18 = v12;
          if ( v12 == 1 )
            v19 = "";
          else
            v19 = "s";
          snprintf(s, 0x1000u, "Reaped %d curl%s from pool %d", v18, v19, *(_DWORD *)v2);
          sub_385C8(7, s, 0);
        }
        mutexa = (pthread_mutex_t *)time(0);
        if ( pthread_mutex_lock(&::mutex) )
          sub_B35C("prune_stratum_shares", 9519);
        v20 = dword_73E68;
        if ( !dword_73E68 )
        {
          v21 = 0;
          goto LABEL_81;
        }
        v22 = v1;
        v23 = *(_DWORD *)(dword_73E68 + 8);
        v24 = v2;
        v21 = 0;
        v25 = v22;
        while ( v24 != *(_DWORD *)(*(_DWORD *)(v20 + 36) + 1748) || (int)mutexa <= *(_DWORD *)(v20 + 44) + 120 )
        {
          if ( !v23 )
            goto LABEL_80;
LABEL_56:
          v20 = v23;
          v23 = *(_DWORD *)(v23 + 8);
        }
        v26 = *(_DWORD *)(v20 + 4);
        if ( v26 || *(_DWORD *)(v20 + 8) )
        {
          v27 = (int **)dword_73E68;
          v28 = *(_DWORD *)dword_73E68;
          v29 = *(int **)(*(_DWORD *)dword_73E68 + 20);
          if ( v20 == *(_DWORD *)(*(_DWORD *)dword_73E68 + 16) - (_DWORD)v29 )
          {
            *(_DWORD *)(v28 + 16) = (char *)v29 + v26;
            v26 = *(_DWORD *)(v20 + 4);
          }
          v30 = v26 == 0;
          if ( v26 )
          {
            v29 = *v27;
            v28 = *(_DWORD *)(v20 + 8);
          }
          else
          {
            v26 = *(_DWORD *)(v20 + 8);
          }
          if ( v30 )
          {
            v27 = (int **)v26;
            dword_73E68 = v26;
          }
          else
          {
            v26 += v29[5];
          }
          if ( !v30 )
          {
            *(_DWORD *)(v26 + 8) = v28;
            v26 = *(_DWORD *)(v20 + 8);
          }
          if ( v26 )
            *(_DWORD *)(v26 + (*v27)[5] + 4) = *(_DWORD *)(v20 + 4);
          v31 = 3 * (((*v27)[1] - 1) & *(_DWORD *)(v20 + 28));
          v32 = **v27 + 12 * (((*v27)[1] - 1) & *(_DWORD *)(v20 + 28));
          --*(_DWORD *)(v32 + 4);
          v33 = **v27;
          if ( v20 == *(_DWORD *)(v33 + 4 * v31) )
            *(_DWORD *)(v33 + 4 * v31) = *(_DWORD *)(v20 + 16);
          v34 = *(_DWORD *)(v20 + 12);
          if ( v34 )
            *(_DWORD *)(v34 + 16) = *(_DWORD *)(v20 + 16);
          v35 = *(_DWORD *)(v20 + 16);
          if ( v35 )
            *(_DWORD *)(v35 + 12) = *(_DWORD *)(v20 + 12);
          --(*v27)[3];
        }
        else
        {
          v39 = (void **)dword_73E68;
          free(**(void ***)dword_73E68);
          free(*v39);
          dword_73E68 = 0;
        }
        ++v21;
        sub_156B8(*(void ***)(v20 + 36));
        *(_DWORD *)(v20 + 36) = 0;
        free((void *)v20);
        if ( v23 )
          goto LABEL_56;
LABEL_80:
        v36 = v25;
        v2 = v24;
        v1 = v36;
LABEL_81:
        if ( pthread_mutex_unlock(&::mutex) )
          sub_B50C("prune_stratum_shares", 9530);
        off_72D18();
        if ( v21 )
        {
          if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
          {
            snprintf(s, 0x1000u, "Lost %d shares due to no stratum share response from pool %d", v21, *(_DWORD *)v2);
            sub_385C8(4, s, 0);
          }
          v37 = *(_QWORD *)&dword_78AA8;
          *(_DWORD *)(v2 + 152) += v21;
          *(_QWORD *)&dword_78AA8 = v37 + v21;
        }
LABEL_11:
        if ( v40 == 20 )
        {
          v3 = *(_QWORD *)(v2 + 40);
          LODWORD(v4) = sub_59F1C(v3 - *(int *)(v2 + 184));
          v5 = *(double *)(v2 + 176);
          *(_DWORD *)(v2 + 184) = v3;
          v6 = (v5 + v4 * 0.63) / 1.63;
          *(double *)(v2 + 176) = v6;
          *(_DWORD *)(v2 + 188) = (int)v6;
        }
        if ( !*(_DWORD *)(v2 + 132) || *(_BYTE *)(v2 + 316) )
          goto LABEL_8;
        if ( !*(_BYTE *)(v2 + 129) )
        {
LABEL_7:
          if ( !dword_73D34 )
          {
            v7 = *(_DWORD *)(v2 + 4);
            if ( v7 < sub_1FAC4() && v44.tv_sec - *(_DWORD *)(v2 + 168) > 300 )
            {
              if ( byte_77B70 || byte_75C48 || dword_73504 > 3 )
              {
                snprintf(s, 0x1000u, "Pool %d %s stable for 5 mins", *(_DWORD *)v2, *(const char **)(v2 + 196));
                sub_385C8(4, s, 0);
              }
              sub_1A600(0);
            }
          }
          goto LABEL_8;
        }
        if ( v44.tv_sec - *(_DWORD *)(v2 + 168) <= 30 )
        {
LABEL_8:
          if ( dword_77FC0 <= ++v1 )
            break;
        }
        else
        {
          if ( sub_18610((_DWORD *)v2, 1) && sub_18200(v2, (_BYTE *)(v2 + 129)) )
            sub_1FB7C((_DWORD *)v2);
          else
            sub_2A7A4((struct timeval *)(v2 + 168));
          if ( !*(_BYTE *)(v2 + 129) )
            goto LABEL_7;
          if ( dword_77FC0 <= ++v1 )
            break;
        }
      }
    }
    if ( *(_BYTE *)(sub_1D9A0() + 129) )
    {
      sub_1A600(0);
      if ( dword_73D34 != 2 )
        goto LABEL_24;
    }
    else if ( dword_73D34 != 2 )
    {
      goto LABEL_24;
    }
    if ( v44.tv_sec - stru_7414C.tv_sec > 60 * dword_78380 )
    {
      sub_2A7A4(&stru_7414C);
      sub_1A600(0);
    }
LABEL_24:
    sub_2A884();
  }
}
