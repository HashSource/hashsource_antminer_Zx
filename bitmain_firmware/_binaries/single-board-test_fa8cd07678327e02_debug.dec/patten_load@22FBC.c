void __cdecl patten_load(char *root_path)
{
  char fname[128]; // [sp+24h] [bp+Ch] BYREF
  char buff[4096]; // [sp+A4h] [bp+8Ch] BYREF
  char *tmp; // [sp+10A4h] [bp+108Ch]
  uint8_t *cur_patten; // [sp+10A8h] [bp+1090h]
  FILE *fp_patten; // [sp+10ACh] [bp+1094h]
  int one_patten_bin_len; // [sp+10B0h] [bp+1098h]
  int which_patten; // [sp+10B4h] [bp+109Ch]
  int which_core; // [sp+10B8h] [bp+10A0h]
  int which_asic; // [sp+10BCh] [bp+10A4h]

  one_patten_bin_len = g_patten.sol_bin_len + g_patten.work_bin_len + g_patten.nonce_bin_len;
  for ( which_asic = 0; g_patten.asic_num > which_asic; ++which_asic )
  {
    for ( which_core = 0; g_patten.core_num > which_core; ++which_core )
    {
      memset(fname, 0, sizeof(fname));
      sprintf(
        fname,
        "%s/%s/%s/%s-0x%02x/%s-0x%02x.txt",
        root_path,
        g_patten.dir_root,
        g_patten.dir_algo,
        g_patten.dir_asic,
        which_asic,
        g_patten.file_core,
        which_core);
      printf("fname %s\n", fname);
      fp_patten = fopen(fname, "r");
      if ( !fp_patten )
      {
        printf("open %s failed\n", fname);
        exit(1);
      }
      for ( which_patten = 0; g_patten.patten_num > which_patten; ++which_patten )
      {
        cur_patten = &g_patten.patten_start[one_patten_bin_len * which_core * g_patten.patten_num
                                          + one_patten_bin_len * g_patten.patten_num * which_asic * g_patten.core_num
                                          + one_patten_bin_len * which_patten];
        memset(buff, 0, sizeof(buff));
        fgets(buff, 4096, fp_patten);
        tmp = strstr(buff, "work");
        hex2bin(cur_patten, tmp + 5, g_patten.work_bin_len);
        tmp = strstr(buff, "nonce");
        hex2bin(&cur_patten[g_patten.work_bin_len], tmp + 6, g_patten.nonce_bin_len);
        tmp = strstr(buff, "sol");
        hex2bin(&cur_patten[g_patten.nonce_bin_len + g_patten.work_bin_len], tmp + 4, g_patten.sol_bin_len);
      }
      fclose(fp_patten);
    }
  }
  puts("Load Patten Done");
}
