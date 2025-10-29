bool __fastcall benchfile_get_work(work *work)
{
  char *v2; // r4
  bool v3; // r4
  int v4; // r5
  FILE *v6; // r0
  int v7; // r10
  char *v8; // r0
  char **v9; // r11
  int v10; // r9
  char *v11; // r0
  int v12; // r12
  char *v13; // r3
  int length; // lr
  int v15; // r9
  _BOOL4 v16; // r1
  size_t v17; // r0
  const char *v18; // r11
  size_t v19; // r10
  char *v20; // r9
  char *v21; // r5
  char *v22; // r8
  char *v23; // r2
  const char *v24; // r11
  char *v25; // r9
  char *v26; // r5
  char *v27; // r8
  char *v28; // r2
  int v29; // r0
  const char *v30; // r1
  unsigned __int8 *v31; // r1
  char **v32; // r2
  unsigned int v33; // t1
  uint32_t v34; // r1
  uint32_t v35; // r2
  uint32_t v36; // r3
  uint32_t v37; // r1
  uint32_t v38; // r2
  uint32_t v39; // r3
  const char *v40; // r2
  int *v41; // r4
  int v42; // r0
  int v43; // r1
  int v44; // r2
  int v45; // r3
  int v46; // r0
  int v47; // r1
  int v48; // r2
  int v49; // r3
  int v50; // r4
  const char *v51; // r2
  const char *v52; // r2
  const char *v53; // r2
  const char *v54; // r2
  int v55; // r1
  const char *v56; // r2
  char *nptr; // [sp+14h] [bp-1508h]
  char *commas[5]; // [sp+1Ch] [bp-1500h] BYREF
  unsigned __int8 message[8]; // [sp+30h] [bp-14ECh] BYREF
  int v60; // [sp+6Ch] [bp-14B0h] BYREF
  sha256_ctx ctx; // [sp+70h] [bp-14ACh] BYREF
  char buf[1024]; // [sp+118h] [bp-1404h] BYREF
  char tmp42[4096]; // [sp+518h] [bp-1004h] BYREF

  if ( !benchfile_in )
  {
    if ( !opt_benchfile )
    {
      LOWORD(v41) = -1568;
      HIWORD(v41) = (unsigned int)"n %s: %s" >> 16;
      v42 = *v41;
      v43 = v41[1];
      v44 = v41[2];
      v45 = v41[3];
      v41 += 4;
      *(_DWORD *)tmp42 = v42;
      *(_DWORD *)&tmp42[4] = v43;
      *(_DWORD *)&tmp42[8] = v44;
      *(_DWORD *)&tmp42[12] = v45;
      v46 = *v41;
      v47 = v41[1];
      v48 = v41[2];
      v49 = v41[3];
      v50 = v41[4];
      *(_DWORD *)&tmp42[16] = v46;
      *(_DWORD *)&tmp42[20] = v47;
      *(_DWORD *)&tmp42[24] = v48;
      *(_DWORD *)&tmp42[28] = v49;
      tmp42[32] = v50;
      applog(3, tmp42, 1);
      _quit(1, 1);
    }
    v6 = fopen(opt_benchfile, "r");
    benchfile_in = v6;
    if ( v6 )
    {
      benchfile_line = 0;
      if ( fgets(buf, 1024, v6) )
      {
        benchfile_work = 0;
        while ( 1 )
        {
LABEL_3:
          v3 = buf[0] != 35;
          v4 = benchfile_line + 1;
          if ( !buf[0] )
            v3 = 0;
          ++benchfile_line;
          v2 = (char *)(buf[0] != 47 && v3);
          if ( v2 )
            break;
          if ( !fgets(buf, 1024, benchfile_in) )
            goto LABEL_10;
        }
        LOWORD(v7) = -15028;
        v8 = buf;
        v9 = commas;
        v10 = 0;
        commas[0] = buf;
        do
        {
          v11 = strchr(v8, 44);
          v12 = v10 + 1;
          v13 = v11;
          v9[1] = v11;
          if ( !v11 )
          {
            LOWORD(v52) = -1416;
            HIWORD(v52) = (unsigned int)"%s'" >> 16;
            snprintf(tmp42, 0x1000u, v52, v4, v10 + 1, 5);
            goto LABEL_32;
          }
          ++v9;
          length = benchfile_data[v10].length;
          v15 = 8 * v10;
          v16 = length != v11 - *(v9 - 1);
          if ( !length )
            v16 = 0;
          if ( v16 )
          {
            HIWORD(v7) = (unsigned int)&loc_4C524 >> 16;
            LOWORD(v51) = -1340;
            HIWORD(v51) = (unsigned int)" - field count is %d but should be %d" >> 16;
            snprintf(tmp42, 0x1000u, v51, v4, v12, *(_DWORD *)(v7 + v15 + 272), v11 - *(v9 - 1), length);
            goto LABEL_32;
          }
          v8 = v11 + 1;
          v10 = v12;
          *v13 = 0;
          *v9 = v13 + 1;
        }
        while ( v12 != 4 );
        nptr = commas[4];
        v17 = strlen(commas[4]);
        if ( v17 > 9 )
        {
          LOWORD(v18) = -1144;
          sprintf(tmp42, "0000000%c", (unsigned __int8)*commas[0]);
          v19 = strlen(tmp42);
          v20 = &tmp42[v19];
          v21 = commas[2] + 56;
          v22 = commas[2] - 8;
          do
          {
            v23 = v21;
            HIWORD(v18) = (unsigned int)"ld be least %d" >> 16;
            v21 -= 8;
            sprintf(v20, v18, v23);
            v20 += 8;
          }
          while ( v22 != v21 );
          LOWORD(v24) = -1144;
          v25 = &tmp42[v19 + 64];
          v26 = commas[1] + 56;
          v27 = commas[1] - 8;
          do
          {
            v28 = v26;
            HIWORD(v24) = (unsigned int)"ld be least %d" >> 16;
            v26 -= 8;
            sprintf(v25, v24, v28);
            v25 += 8;
          }
          while ( v27 != v26 );
          v29 = strtol(nptr, 0, 10);
          LOWORD(v30) = -1136;
          HIWORD(v30) = (unsigned int)"ast %d" >> 16;
          sprintf(&tmp42[v19 + 128], v30, v29);
          strcpy(&tmp42[v19 + 136], commas[3]);
          memset(work, 0, sizeof(work));
          hex2bin(work->data, tmp42, (int)(v19 + 144) >> 1);
          v31 = &work[-1].device_target[35];
          v32 = &commas[4];
          do
          {
            v33 = *((_DWORD *)v31 + 1);
            v31 += 4;
            v32[1] = (char *)bswap32(v33);
            ++v32;
          }
          while ( &v60 != (int *)v32 );
          sha256_init(&ctx);
          sha256_update(&ctx, message, 0x40u);
          v34 = ctx.h[1];
          v35 = ctx.h[2];
          v36 = ctx.h[3];
          ++benchfile_work;
          *(_DWORD *)work->midstate = ctx.h[0];
          *(_DWORD *)&work->midstate[4] = v34;
          *(_DWORD *)&work->midstate[8] = v35;
          *(_DWORD *)&work->midstate[12] = v36;
          v37 = ctx.h[5];
          v38 = ctx.h[6];
          v39 = ctx.h[7];
          *(_DWORD *)&work->midstate[16] = ctx.h[4];
          *(_DWORD *)&work->midstate[20] = v37;
          *(_DWORD *)&work->midstate[24] = v38;
          *(_DWORD *)&work->midstate[28] = v39;
          return (char)v2;
        }
        LOWORD(v55) = -1168;
        HIWORD(v55) = (unsigned int)"s) length is %d but should be least %d" >> 16;
        LOWORD(v56) = -1256;
        HIWORD(v56) = (unsigned int)"d (%s) length is %d but should be %d" >> 16;
        snprintf(tmp42, 0x1000u, v56, v4, 5, v55, v17, 10);
      }
      else
      {
        LOWORD(v54) = -1492;
        HIWORD(v54) = (unsigned int)"BENCHFILE Failed to open benchfile '%s'" >> 16;
        snprintf(tmp42, 0x1000u, v54, opt_benchfile);
      }
    }
    else
    {
      LOWORD(v53) = -1532;
      HIWORD(v53) = (unsigned int)"%s" >> 16;
      snprintf(tmp42, 0x1000u, v53, opt_benchfile);
    }
LABEL_32:
    applog(3, tmp42, 1);
    _quit(1, 1);
  }
  v2 = fgets(buf, 1024, benchfile_in);
  if ( v2 )
    goto LABEL_3;
LABEL_10:
  if ( !benchfile_work )
  {
    LOWORD(v40) = -1452;
    HIWORD(v40) = (unsigned int)"BENCHFILE Failed to read benchfile '%s'" >> 16;
    snprintf(tmp42, 0x1000u, v40, opt_benchfile);
    goto LABEL_32;
  }
  fclose(benchfile_in);
  benchfile_in = (FILE *)v2;
  LOBYTE(v2) = benchfile_get_work(work);
  return (char)v2;
}
