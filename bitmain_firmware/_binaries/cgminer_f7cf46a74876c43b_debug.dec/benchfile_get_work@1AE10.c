bool __fastcall benchfile_get_work(work *work)
{
  char *v2; // r4
  bool v3; // r4
  int v4; // r5
  FILE *v6; // r0
  char *v7; // r0
  char **v8; // r11
  int v9; // r9
  char *v10; // r0
  int v11; // r12
  char *v12; // r3
  int length; // lr
  int v14; // r9
  _BOOL4 v15; // r1
  size_t v16; // r0
  size_t v17; // r10
  char *v18; // r9
  char *v19; // r5
  char *v20; // r8
  const char *v21; // r2
  char *v22; // r9
  char *v23; // r5
  char *v24; // r8
  const char *v25; // r2
  int v26; // r0
  unsigned __int8 *v27; // r1
  char **v28; // r2
  unsigned int v29; // t1
  uint32_t v30; // r1
  uint32_t v31; // r2
  uint32_t v32; // r3
  uint32_t v33; // r1
  uint32_t v34; // r2
  uint32_t v35; // r3
  char *nptr; // [sp+14h] [bp-1508h]
  char *commas[5]; // [sp+1Ch] [bp-1500h] BYREF
  unsigned __int8 message[8]; // [sp+30h] [bp-14ECh] BYREF
  int v39; // [sp+6Ch] [bp-14B0h] BYREF
  sha256_ctx ctx; // [sp+70h] [bp-14ACh] BYREF
  char buf[1024]; // [sp+118h] [bp-1404h] BYREF
  char tmp42[4100]; // [sp+518h] [bp-1004h] BYREF

  if ( !benchfile_in )
  {
    if ( !opt_benchfile )
    {
      strcpy(tmp42, "BENCHFILE Invalid benchfile NULL");
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
        v7 = buf;
        v8 = commas;
        v9 = 0;
        commas[0] = buf;
        do
        {
          v10 = strchr(v7, 44);
          v11 = v9 + 1;
          v12 = v10;
          v8[1] = v10;
          if ( !v10 )
          {
            snprintf(
              tmp42,
              0x1000u,
              "BENCHFILE Invalid input file line %d - field count is %d but should be %d",
              v4,
              v9 + 1,
              5);
            goto LABEL_32;
          }
          ++v8;
          length = benchfile_data[v9].length;
          v14 = 8 * v9;
          v15 = length != v10 - *(v8 - 1);
          if ( !length )
            v15 = 0;
          if ( v15 )
          {
            snprintf(
              tmp42,
              0x1000u,
              "BENCHFILE Invalid input file line %d field %d (%s) length is %d but should be %d",
              v4,
              v11,
              *(const char **)&_func___16862[v14 + 272],
              v10 - *(v8 - 1),
              length);
            goto LABEL_32;
          }
          v7 = v10 + 1;
          v9 = v11;
          *v12 = 0;
          *v8 = v12 + 1;
        }
        while ( v11 != 4 );
        nptr = commas[4];
        v16 = strlen(commas[4]);
        if ( v16 > 9 )
        {
          sprintf(tmp42, "0000000%c", (unsigned __int8)*commas[0]);
          v17 = strlen(tmp42);
          v18 = &tmp42[v17];
          v19 = commas[2] + 56;
          v20 = commas[2] - 8;
          do
          {
            v21 = v19;
            v19 -= 8;
            sprintf(v18, "%.8s", v21);
            v18 += 8;
          }
          while ( v20 != v19 );
          v22 = &tmp42[v17 + 64];
          v23 = commas[1] + 56;
          v24 = commas[1] - 8;
          do
          {
            v25 = v23;
            v23 -= 8;
            sprintf(v22, "%.8s", v25);
            v22 += 8;
          }
          while ( v24 != v23 );
          v26 = strtol(nptr, 0, 10);
          sprintf(&tmp42[v17 + 128], "%08lx", v26);
          strcpy(&tmp42[v17 + 136], commas[3]);
          memset(work, 0, sizeof(work));
          hex2bin(work->data, tmp42, (int)(v17 + 144) >> 1);
          v27 = &work[-1].device_target[35];
          v28 = &commas[4];
          do
          {
            v29 = *((_DWORD *)v27 + 1);
            v27 += 4;
            v28[1] = (char *)bswap32(v29);
            ++v28;
          }
          while ( &v39 != (int *)v28 );
          sha256_init(&ctx);
          sha256_update(&ctx, message, 0x40u);
          v30 = ctx.h[1];
          v31 = ctx.h[2];
          v32 = ctx.h[3];
          ++benchfile_work;
          *(_DWORD *)work->midstate = ctx.h[0];
          *(_DWORD *)&work->midstate[4] = v30;
          *(_DWORD *)&work->midstate[8] = v31;
          *(_DWORD *)&work->midstate[12] = v32;
          v33 = ctx.h[5];
          v34 = ctx.h[6];
          v35 = ctx.h[7];
          *(_DWORD *)&work->midstate[16] = ctx.h[4];
          *(_DWORD *)&work->midstate[20] = v33;
          *(_DWORD *)&work->midstate[24] = v34;
          *(_DWORD *)&work->midstate[28] = v35;
          return (char)v2;
        }
        snprintf(
          tmp42,
          0x1000u,
          "BENCHFILE Invalid input file line %d field %d (%s) length is %d but should be least %d",
          v4,
          5,
          "NonceTime",
          v16,
          10);
      }
      else
      {
        snprintf(tmp42, 0x1000u, "BENCHFILE Failed to read benchfile '%s'", opt_benchfile);
      }
    }
    else
    {
      snprintf(tmp42, 0x1000u, "BENCHFILE Failed to open benchfile '%s'", opt_benchfile);
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
    snprintf(tmp42, 0x1000u, "BENCHFILE No work in benchfile '%s'", opt_benchfile);
    goto LABEL_32;
  }
  fclose(benchfile_in);
  benchfile_in = (FILE *)v2;
  LOBYTE(v2) = benchfile_get_work(work);
  return (char)v2;
}
