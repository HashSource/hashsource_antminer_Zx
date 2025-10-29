int __cdecl pattern_test(runtime_base_t *runtime, int freq, int *nonce)
{
  char tmp42[1024]; // [sp+14h] [bp+14h] BYREF
  char golden[20]; // [sp+414h] [bp+414h] BYREF
  char result[20]; // [sp+428h] [bp+428h] BYREF
  bm174x_reg pt_result_reg; // [sp+43Ch] [bp+43Ch]
  uint8_t header_bin[140]; // [sp+440h] [bp+440h] BYREF
  reg_list_item_t item; // [sp+4CCh] [bp+4CCh] BYREF
  char *header; // [sp+4D8h] [bp+4D8h]
  int read_timeout_limit; // [sp+4DCh] [bp+4DCh]
  int chainid; // [sp+4E0h] [bp+4E0h]
  int read_timeout_counter; // [sp+4E4h] [bp+4E4h]
  FILE *fpr; // [sp+4E8h] [bp+4E8h]
  FILE *fpg; // [sp+4ECh] [bp+4ECh]
  int match_num; // [sp+4F0h] [bp+4F0h]
  int i; // [sp+4F4h] [bp+4F4h]

  chainid = runtime->chain_id;
  read_timeout_limit = 15;
  match_num = 0;
  fpg = 0;
  fpr = 0;
  remove("./pattern_result.txt");
  runtime->set_pt_ctrl(runtime->chain_status[chainid].fd, 0, 0);
  usleep(0x186A0u);
  runtime->set_ticket_mask(runtime->chain_status[chainid].fd, 5);
  usleep(0x186A0u);
  runtime->set_core_timeout(runtime->chain_status[chainid].fd, 45000);
  usleep(0x186A0u);
  runtime->set_txn_data(runtime->chain_status[chainid].fd, 0);
  usleep(0x186A0u);
  runtime->set_frequency(runtime->chain_status[chainid].fd, freq);
  usleep(0x186A0u);
  runtime->set_pt_ctrl(runtime->chain_status[chainid].fd, 2047, 1);
  usleep(0x186A0u);
  header = "010203042cb3d32b0b61304401cbe540448a4cacd7e98421a850503e2f0d102f1d3454151484151215484aa0ca1932037525e2eb9a22d"
           "3d3ff1502b320f8d9ca56377f56494b2cacf3377482ccd34188c1b25e04187ccf70af6e2244c3c96e5e2e3a6015d32fe451ad000e771e"
           "ccb5c5e3d6beb470359446494d25e15f87df87c3119ebd9ca813a400000000";
  memset(header_bin, 0, sizeof(header_bin));
  hex2bin(
    header_bin,
    "010203042cb3d32b0b61304401cbe540448a4cacd7e98421a850503e2f0d102f1d3454151484151215484aa0ca1932037525e2eb9a22d3d3ff15"
    "02b320f8d9ca56377f56494b2cacf3377482ccd34188c1b25e04187ccf70af6e2244c3c96e5e2e3a6015d32fe451ad000e771eccb5c5e3d6beb4"
    "70359446494d25e15f87df87c3119ebd9ca813a400000000",
    0x8Cu);
  user_send_work(runtime, header_bin, 0, 0);
  sleep(3u);
  item.age = 3;
  item.chainid = 0;
  item.chip_addr = 0;
  item.reg_addr = 96;
  read_timeout_counter = 0;
  while ( read_timeout_counter < read_timeout_limit )
  {
    runtime->read_register(runtime->chain_status[chainid].fd, 1, 0, 96);
    if ( read_reg_item(&item, 500) <= 0 )
    {
      if ( use_syslog || opt_log_output || opt_log_level >= 0 )
      {
        strcpy(tmp42, "REG_PT_RESULT read timeout\n");
        applog(0, tmp42, 0);
      }
      ++read_timeout_counter;
    }
    else
    {
      pt_result_reg.chip_addr = (bm174x_chip_addr)item.reg_data;
      if ( (HIWORD(item.reg_data) & 0xFFF) == 0x800 )
      {
        if ( use_syslog || opt_log_output || opt_log_level > 1 )
        {
          strcpy(tmp42, "pattern test finished\n");
          applog(2, tmp42, 0);
        }
        break;
      }
      if ( opt_debug && (use_syslog || opt_log_output || opt_log_level > 3) )
      {
        snprintf(
          tmp42,
          0x400u,
          "REG_PT_RESULT cur num = %d < 0x800, check again\n",
          *((_WORD *)&pt_result_reg.hash_rate + 1) & 0xFFF);
        applog(4, tmp42, 0);
      }
      ++read_timeout_counter;
    }
    sleep(1u);
  }
  if ( read_timeout_counter < read_timeout_limit )
  {
    if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      strcpy(tmp42, "pattern test finished, read out nonce\n");
      applog(0, tmp42, 0);
    }
    for ( i = 0; i <= 15; ++i )
    {
      runtime->set_pt_result(runtime->chain_status[chainid].fd, i, 1);
      usleep(0x30D40u);
    }
    if ( use_syslog || opt_log_output || opt_log_level > 1 )
    {
      strcpy(tmp42, "Compare golden nonce and current nonce\n");
      applog(2, tmp42, 0);
    }
    fpr = fopen("./pattern_result.txt", "r");
    if ( fpr )
    {
      fpg = fopen("./pattern_golden.txt", "r");
      if ( fpg )
      {
LABEL_52:
        while ( !feof(fpr) )
        {
          memset(result, 0, sizeof(result));
          fgets(result, 1024, fpr);
          fseek(fpg, 0, 0);
          while ( !feof(fpg) )
          {
            memset(golden, 0, sizeof(golden));
            fgets(golden, 1024, fpg);
            if ( !strncmp(golden, result, 0x10u) && golden[0] )
            {
              ++match_num;
              goto LABEL_52;
            }
          }
        }
      }
      else if ( use_syslog || opt_log_output || opt_log_level >= 0 )
      {
        strcpy(tmp42, "open failed pattern_golden.txt\n");
        applog(0, tmp42, 0);
      }
    }
    else if ( use_syslog || opt_log_output || opt_log_level >= 0 )
    {
      strcpy(tmp42, "open failed pattern_result.txt\n");
      applog(0, tmp42, 0);
    }
  }
  else if ( use_syslog || opt_log_output || opt_log_level > 1 )
  {
    strcpy(tmp42, "patten test timeout\n");
    applog(2, tmp42, 0);
  }
  if ( fpg )
    fclose(fpg);
  if ( fpr )
    fclose(fpr);
  *nonce = match_num;
  return 0;
}
