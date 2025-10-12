// Decompiled: single-board-test_fa8cd07678327e02_debug


int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = call_weak_fn();
  return iVar1;
}




void _start(undefined4 param_1)

{
  undefined4 in_stack_00000000;
  
  __libc_start_main(0x174cd,in_stack_00000000,&stack0x00000004,0x33e75,0x33eb5,param_1);
                    /* WARNING: Subroutine does not return */
  abort();
}




/* WARNING: Removing unreachable block (ram,0x000112b4) */

void call_weak_fn(void)

{
  __gmon_start__();
  return;
}




/* WARNING: Removing unreachable block (ram,0x000112d4) */
/* WARNING: Removing unreachable block (ram,0x000112de) */

void deregister_tm_clones(void)

{
  return;
}




/* WARNING: Removing unreachable block (ram,0x00011304) */
/* WARNING: Removing unreachable block (ram,0x0001130e) */

void register_tm_clones(void)

{
  return;
}




void __do_global_dtors_aux(void)

{
  if (completed_9251 == '\0') {
    deregister_tm_clones();
    completed_9251 = '\x01';
  }
  return;
}




/* WARNING: Removing unreachable block (ram,0x0001134c) */

void frame_dummy(void)

{
  register_tm_clones();
  return;
}




uint8_t get_bt8d_from_baud(uint32_t baud)

{
  uint8_t uVar1;
  uint32_t baud_local;
  char tmp42 [1024];
  size_t max;
  size_t index;
  
  index = 0;
  while( true ) {
    if (4 < index) {
      if (index == 5) {
        if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
          builtin_strncpy(tmp42,"get bt8d value failed!!!,use default to continue",0x30);
          tmp42[0x30] = '\n';
          tmp42[0x31] = '\0';
          _applog(3,tmp42,false);
        }
        uVar1 = get_bt8d_from_baud(0x1c200);
      }
      else {
        uVar1 = 0xff;
      }
      return uVar1;
    }
    if (baud_BT8D_values[index].baud == baud) break;
    index = index + 1;
  }
  if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
    snprintf(tmp42,0x400,"get bt8d %d\n",(uint)baud_BT8D_values[index].bt8d);
    _applog(3,tmp42,false);
  }
  return baud_BT8D_values[index].bt8d;
}




void get_plldata(uint32_t freq,uint32_t *vil_data)

{
  uint32_t *vil_data_local;
  uint32_t freq_local;
  uint32_t i;
  
  for (i = 0; (i < 0x6e && (freq_pll[i].freq != freq)); i = i + 1) {
  }
  if (i == 0x6e) {
    i = 4;
  }
  *vil_data = freq_pll[i].vilpll;
  return;
}




int makeup_work_pkg(uint8_t *str,uint8_t *work_str)

{
  ushort uVar1;
  uint8_t *work_str_local;
  uint8_t *str_local;
  uint16_t crc16;
  work_input *work;
  
  work_str[2] = work_str[2] & 0x1f | 0x20;
  *work_str = 'U';
  work_str[1] = 0xaa;
  uVar1 = CRC16_v1(work_str + 2,0x8e);
  *(ushort *)(work_str + 0x90) = uVar1 >> 8 | uVar1 << 8;
  memcpy(str,work_str,0x92);
  return 0x92;
}




int makeup_set_address_cmd(uint8_t *str,uint32_t str_len,uint8_t chip_addr)

{
  byte bVar1;
  int iVar2;
  uint8_t chip_addr_local;
  uint32_t str_len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  set_address_cmd_t set_address_cmd;
  
  if (str_len < 7) {
    if (((use_syslog) || (opt_log_output)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s input param error: str length = %u\n","makeup_set_address_cmd",7);
      _applog(0,tmp42,false);
    }
    iVar2 = -1;
  }
  else {
    memset(&set_address_cmd,0,5);
    set_address_cmd.chip_addr = chip_addr;
    set_address_cmd._0_2_ = 0x540;
    bVar1 = CRC5_v1((uchar *)&set_address_cmd,' ');
    *str = 'U';
    str[1] = 0xaa;
    str[2] = set_address_cmd._0_1_;
    str[3] = set_address_cmd.length;
    str[4] = set_address_cmd.chip_addr;
    str[5] = set_address_cmd.reserve1;
    str[6] = set_address_cmd._4_1_ & 0xe0 | bVar1 & 0x1f;
    iVar2 = 7;
  }
  return iVar2;
}




int makeup_set_config_cmd(uint8_t *str,uint32_t str_len,uint8_t all,uint8_t chip_addr,uint8_t regaddr,uint32_t regdata)

{
  byte bVar1;
  int iVar2;
  uint8_t chip_addr_local;
  uint8_t all_local;
  uint32_t str_len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  uint32_t swap_reg;
  set_config_cmd_t set_config_cmd;
  
  if (str_len < 0xb) {
    if (((use_syslog) || (opt_log_output)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s input param error: str length = %u\n","makeup_set_config_cmd",0xb);
      _applog(0,tmp42,false);
    }
    iVar2 = -1;
  }
  else {
    memset(&set_config_cmd,0,9);
    set_config_cmd.length = '\t';
    set_config_cmd._0_1_ = (all & 1) << 4 | 0x41;
    set_config_cmd.chip_addr = chip_addr;
    set_config_cmd.regaddr = regaddr;
    set_config_cmd.regdata =
         (uint8_t  [4])
         (regdata << 0x18 | (regdata >> 8 & 0xff) << 0x10 | (regdata >> 0x10 & 0xff) << 8 | regdata >> 0x18);
    bVar1 = CRC5_v1((uchar *)&set_config_cmd,'@');
    *str = 'U';
    str[1] = 0xaa;
    str[2] = set_config_cmd._0_1_;
    str[3] = set_config_cmd.length;
    str[4] = set_config_cmd.chip_addr;
    str[5] = set_config_cmd.regaddr;
    *(uint8_t (*) [4])(str + 6) = set_config_cmd.regdata;
    str[10] = set_config_cmd._8_1_ & 0xe0 | bVar1 & 0x1f;
    iVar2 = 0xb;
  }
  return iVar2;
}




int makeup_get_status_cmd(uint8_t *str,uint32_t str_len,uint8_t all,uint8_t chip_addr,uint8_t regaddr)

{
  byte bVar1;
  int iVar2;
  uint8_t chip_addr_local;
  uint8_t all_local;
  uint32_t str_len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  get_status_cmd_t get_status_cmd;
  
  if (str_len < 7) {
    if (((use_syslog) || (opt_log_output)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s input param error: str length = %u\n","makeup_get_status_cmd",7);
      _applog(0,tmp42,false);
    }
    iVar2 = -1;
  }
  else {
    memset(&get_status_cmd,0,5);
    get_status_cmd.length = '\x05';
    get_status_cmd._0_1_ = (all & 1) << 4 | 0x42;
    get_status_cmd.chip_addr = chip_addr;
    get_status_cmd.regaddr = regaddr;
    bVar1 = CRC5_v1((uchar *)&get_status_cmd,' ');
    *str = 'U';
    str[1] = 0xaa;
    str[2] = get_status_cmd._0_1_;
    str[3] = get_status_cmd.length;
    str[4] = get_status_cmd.chip_addr;
    str[5] = get_status_cmd.regaddr;
    str[6] = get_status_cmd._4_1_ & 0xe0 | bVar1 & 0x1f;
    iVar2 = 7;
  }
  return iVar2;
}




int makeup_chain_inactive_cmd(uint8_t *str,uint32_t str_len)

{
  byte bVar1;
  int iVar2;
  uint32_t str_len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  chain_inactive_cmd_t chain_inactive_cmd;
  
  if (str_len < 7) {
    if (((use_syslog) || (opt_log_output)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s input param error: str length = %u\n","makeup_chain_inactive_cmd",7);
      _applog(0,tmp42,false);
    }
    iVar2 = -1;
  }
  else {
    memset(&chain_inactive_cmd,0,5);
    chain_inactive_cmd._0_2_ = 0x553;
    bVar1 = CRC5_v1((uchar *)&chain_inactive_cmd,' ');
    *str = 'U';
    str[1] = 0xaa;
    str[2] = chain_inactive_cmd._0_1_;
    str[3] = chain_inactive_cmd.length;
    str[4] = chain_inactive_cmd.reserve1;
    str[5] = chain_inactive_cmd.reserve2;
    str[6] = chain_inactive_cmd._4_1_ & 0xe0 | bVar1 & 0x1f;
    iVar2 = 7;
  }
  return iVar2;
}




int bm174x_pack_ioctl_pkg(uint8_t *str,uint32_t str_len,uint32_t oper_type,void *param)

{
  int iVar1;
  void *param_local;
  uint32_t oper_type_local;
  uint32_t str_len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  uint8_t *work_str;
  uint8_t *address;
  base_type_t *item_1;
  base_type_t *item;
  
  switch(oper_type) {
  case 0:
                    /* WARNING: Load size is inaccurate */
    iVar1 = makeup_get_status_cmd(str,str_len,*(uint8_t *)((int)param + 1),*param,*(uint8_t *)((int)param + 2));
    break;
  case 1:
                    /* WARNING: Load size is inaccurate */
    iVar1 = makeup_set_config_cmd
                      (str,str_len,*(uint8_t *)((int)param + 1),*param,*(uint8_t *)((int)param + 2),
                       *(uint32_t *)((int)param + 4));
    break;
  case 2:
    iVar1 = makeup_work_pkg(str,(uint8_t *)param);
    break;
  case 3:
                    /* WARNING: Load size is inaccurate */
    iVar1 = makeup_set_address_cmd(str,str_len,*param);
    break;
  case 4:
    iVar1 = makeup_chain_inactive_cmd(str,str_len);
    break;
  default:
    if (((use_syslog) || (opt_log_output)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,"unknow ioctl type %d\n",oper_type);
      _applog(0,tmp42,false);
    }
    iVar1 = 0;
  }
  return iVar1;
}




int bm174x_ioctl(int fd,uint32_t oper_type,void *param)

{
  uint length;
  void *param_local;
  uint32_t oper_type_local;
  int fd_local;
  uint8_t str [300];
  int len;
  
  memset(str,0,300);
  length = bm174x_pack_ioctl_pkg(str,300,oper_type,param);
  if (-1 < (int)length) {
    length = uart_send((uchar)fd,str,length);
  }
  return length;
}




void bm174x_read_register(int fd,int mode,uint8_t chip_addr,uint8_t reg_addr)

{
  uint8_t reg_addr_local;
  uint8_t chip_addr_local;
  int mode_local;
  int fd_local;
  base_type_t item;
  
  item.all = (uint8_t)mode;
  item.data = 0;
  item.chip_addr = chip_addr;
  item.addr = reg_addr;
  bm174x_ioctl(fd,0,&item);
  return;
}




void bm174x_write_register(int fd,int mode,uint8_t chip_addr,uint8_t reg_addr,uint32_t reg_data)

{
  uint8_t reg_addr_local;
  uint8_t chip_addr_local;
  int mode_local;
  int fd_local;
  base_type_t item;
  
  item.all = (uint8_t)mode;
  item.data = reg_data;
  item.chip_addr = chip_addr;
  item.addr = reg_addr;
  bm174x_ioctl(fd,1,&item);
  return;
}




void bm174x_set_ticket_mask(int fd,uint32_t tm)

{
  uint32_t tm_local;
  int fd_local;
  char tmp42 [1024];
  base_type_t item;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"Set ticket mask %u\n",tm);
    _applog(2,tmp42,false);
  }
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '\x14';
  reg_value.ticket_mask = tm;
  item.data = tm;
  bm174x_ioctl(fd,1,&item);
  return;
}




void bm174x_set_frequency(int fd,uint32_t freq)

{
  uint32_t freq_local;
  int fd_local;
  char tmp42 [1024];
  base_type_t item;
  uint32_t pll_value;
  
  pll_value = 0;
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"Set frequency %u\n",freq);
    _applog(2,tmp42,false);
  }
  get_plldata(freq,&pll_value);
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '\f';
  item.data = pll_value;
  reg_value.pll_parameter = pll_value;
  bm174x_ioctl(fd,1,&item);
  return;
}




void bm174x_set_io_drive_strength(int fd,uint32_t value)

{
  uint32_t value_local;
  int fd_local;
  base_type_t item;
  
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '0';
  reg_value.io_drive_strength = value;
  item.data = value;
  bm174x_ioctl(fd,1,&item);
  return;
}




void bm174x_set_baud(int fd,int baudrate)

{
  uint32_t uVar1;
  byte bVar2;
  int baudrate_local;
  int fd_local;
  base_type_t item;
  bm174x_reg reg_misc;
  
  uVar1 = reg_value.misc_control;
  bVar2 = get_bt8d_from_baud(baudrate);
  reg_misc.core_timeout.core_timeout._1_1_ = (undefined1)(uVar1 >> 8);
  reg_misc.core_timeout.core_timeout._2_2_ = (undefined2)(uVar1 >> 0x10);
  reg_misc.core_timeout.core_timeout._0_1_ = (undefined1)uVar1;
  reg_misc.core_timeout.core_timeout._1_1_ = reg_misc.core_timeout.core_timeout._1_1_ & 0xe0 | bVar2 & 0x1f;
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '\x1c';
  item.data = reg_misc.reg_bin;
  reg_value.misc_control = reg_misc.reg_bin;
  bm174x_ioctl(fd,1,&item);
  return;
}




void bm174x_chain_inactive(int fd)

{
  int fd_local;
  
  bm174x_ioctl(fd,4,(void *)0x0);
  return;
}




void bm174x_set_address(int fd,uint8_t address)

{
  uint8_t address_local;
  int fd_local;
  
  address_local = address;
  fd_local = fd;
  bm174x_ioctl(fd,3,&address_local);
  return;
}




void bm174x_set_core_timeout(int fd,uint32_t timeout)

{
  uint32_t timeout_local;
  int fd_local;
  char tmp42 [1024];
  base_type_t item;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"Set core timeout %u\n",timeout);
    _applog(2,tmp42,false);
  }
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '(';
  reg_value.core_timeout = timeout;
  item.data = timeout;
  bm174x_ioctl(fd,1,&item);
  return;
}




void bm174x_set_txn_data(int fd,uint32_t txn_data)

{
  uint32_t txn_data_local;
  int fd_local;
  base_type_t item;
  
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = 'X';
  reg_value.txn_data = txn_data;
  item.data = txn_data;
  bm174x_ioctl(fd,1,&item);
  return;
}




void bm174x_set_nonce_shift(int fd,uint32_t nonce_shift,uint32_t *outer_shift)

{
  uint32_t *outer_shift_local;
  uint32_t nonce_shift_local;
  int fd_local;
  base_type_t item;
  bm174x_reg nonce_shift_reg;
  
  nonce_shift_reg.core_timeout.core_timeout._0_1_ = (undefined1)reg_value.nonce_shift;
  nonce_shift_reg.core_timeout.core_timeout._1_3_ = (undefined3)(reg_value.nonce_shift >> 8);
  nonce_shift_reg.core_timeout.core_timeout._0_1_ =
       nonce_shift_reg.core_timeout.core_timeout._0_1_ & 0xe0 | (byte)nonce_shift & 0x1f;
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = 'P';
  item.data = nonce_shift_reg.reg_bin;
  bm174x_ioctl(fd,1,&item);
  *outer_shift = nonce_shift;
  return;
}




void bm174x_set_vmount(int fd,int vmount)

{
  int vmount_local;
  int fd_local;
  base_type_t item;
  bm174x_reg vmount_reg;
  
  vmount_reg.core_timeout.core_timeout._0_1_ = (undefined1)reg_value.analog_mux_control;
  vmount_reg.core_timeout.core_timeout._1_3_ = (undefined3)(reg_value.analog_mux_control >> 8);
  vmount_reg.core_timeout.core_timeout._0_1_ = vmount_reg.core_timeout.core_timeout._0_1_ & 0xf8 | (byte)vmount & 7;
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '@';
  item.data = vmount_reg.reg_bin;
  reg_value.analog_mux_control = vmount_reg.reg_bin;
  bm174x_ioctl(fd,1,&item);
  return;
}




void bm174x_set_pt_ctrl(int fd,int pt_num,int pt_en)

{
  bm174x_reg bVar1;
  int pt_en_local;
  int pt_num_local;
  int fd_local;
  base_type_t item;
  bm174x_reg pt_ctrl_reg;
  
  pt_ctrl_reg.core_timeout.core_timeout._0_1_ = (undefined1)reg_value.pt_ctrl;
  pt_ctrl_reg.core_timeout.core_timeout._1_3_ = (undefined3)(reg_value.pt_ctrl >> 8);
  pt_ctrl_reg.core_timeout.core_timeout._0_1_ = pt_ctrl_reg.core_timeout.core_timeout._0_1_ & 0xfe | (byte)pt_en & 1;
  bVar1 = pt_ctrl_reg;
  pt_ctrl_reg.core_timeout.core_timeout._2_2_ = (undefined2)(reg_value.pt_ctrl >> 0x10);
  pt_ctrl_reg.core_timeout.core_timeout._0_2_ = bVar1._0_2_;
  pt_ctrl_reg.core_timeout.core_timeout._2_2_ =
       pt_ctrl_reg.core_timeout.core_timeout._2_2_ & 0xf800 | (ushort)((uint)(pt_num << 0x15) >> 0x15);
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '\\';
  item.data = pt_ctrl_reg.reg_bin;
  bm174x_ioctl(fd,1,&item);
  return;
}




void bm174x_set_pt_result(int fd,int ptr_grp_num,int ptr_rd)

{
  int ptr_rd_local;
  int ptr_grp_num_local;
  int fd_local;
  base_type_t item;
  bm174x_reg pt_result_reg;
  
  pt_result_reg.core_timeout.core_timeout._1_1_ =
       pt_result_reg.core_timeout.core_timeout._1_1_ & 0xf0 | (byte)ptr_grp_num & 0xf;
  pt_result_reg.core_timeout.core_timeout._0_1_ =
       pt_result_reg.core_timeout.core_timeout._0_1_ & 0xfe | (byte)ptr_rd & 1;
  item.chip_addr = '\0';
  item.all = '\x01';
  item.addr = '`';
  item.data = pt_result_reg.reg_bin;
  bm174x_ioctl(fd,1,&item);
  return;
}




void bm174x_i2c_enable(int fd,uint8_t chip_addr)

{
  uint8_t chip_addr_local;
  int fd_local;
  base_type_t item;
  bm174x_reg misc_reg;
  
  misc_reg.reg_bin = reg_value.misc_control | 0x4060;
  item.all = '\0';
  item.addr = '\x1c';
  item.data = misc_reg.reg_bin;
  item.chip_addr = chip_addr;
  bm174x_ioctl(fd,1,&item);
  return;
}




void bm174x_i2c_status(int fd,uint8_t chip_addr)

{
  uint8_t chip_addr_local;
  int fd_local;
  base_type_t item;
  
  item.data = 0;
  item.all = '\0';
  item.chip_addr = chip_addr;
  item.addr = ' ';
  item._3_1_ = 0;
  bm174x_ioctl(fd,0,&item);
  return;
}




int bm174x_i2c_recv(int fd,uint8_t chip_addr,uint8_t i2c_dev_addr,uint8_t i2c_reg_addr,int len)

{
  uint8_t i2c_reg_addr_local;
  uint8_t i2c_dev_addr_local;
  uint8_t chip_addr_local;
  int fd_local;
  base_type_t item;
  bm174x_reg i2c_reg;
  int i;
  
  i2c_reg.core_timeout.core_timeout._0_2_ = CONCAT11(i2c_reg_addr,(undefined1)(char)reg_value.general_i2c_command);
  i2c_reg.reg_bin =
       CONCAT22(CONCAT11((char)(reg_value.general_i2c_command >> 0x18),i2c_dev_addr << 1),
                i2c_reg.core_timeout.core_timeout._0_2_) | 0x1000000;
  item.all = '\0';
  item.addr = ' ';
  item.data = i2c_reg.reg_bin;
  item.chip_addr = chip_addr;
  bm174x_ioctl(fd,1,&item);
  usleep(200000);
  for (i = 0; i < len; i = i + 1) {
    item.all = '\0';
    item.addr = ' ';
    item.data = 0;
    item.chip_addr = chip_addr;
    bm174x_ioctl(fd,0,&item);
    usleep(1000000);
  }
  return 0;
}




void bm174x_i2c_send(int fd,uint8_t chip_addr,uint8_t i2c_dev_addr,uint8_t i2c_reg_addr,uint8_t *reg_data,int len)

{
  uint8_t i2c_reg_addr_local;
  uint8_t i2c_dev_addr_local;
  uint8_t chip_addr_local;
  int fd_local;
  base_type_t item;
  bm174x_reg i2c_reg;
  int i;
  
  for (i = 0; i < len; i = i + 1) {
    i2c_reg.core_timeout.core_timeout._3_1_ = (undefined1)(reg_value.general_i2c_command >> 0x18);
    i2c_reg.reg_bin =
         CONCAT31(CONCAT21(CONCAT11(i2c_reg.core_timeout.core_timeout._3_1_,i2c_dev_addr << 1),i2c_reg_addr),reg_data[i]
                 ) | 0x1010000;
    item.all = '\0';
    item.addr = ' ';
    item.data = i2c_reg.reg_bin;
    item.chip_addr = chip_addr;
    bm174x_ioctl(fd,1,&item);
  }
  return;
}




void bm174x_send_work(int fd,uint8_t *buf)

{
  uint8_t *buf_local;
  int fd_local;
  
  bm174x_ioctl(fd,2,buf);
  return;
}




void bm174x_pm_handle(uint8_t *str,int len,uint8_t chainid)

{
  byte bVar1;
  uint8_t chainid_local;
  int len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  uint8_t crc5;
  pmonitor_respond *pm;
  
  bVar1 = CRC5_v1(str + 2,((char)len + -3) * '\b' + '\x03');
  if (bVar1 == (str[8] & 0x1f)) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"pmonitor[%02x] %02x %02x %02x %02x\n",(uint)str[7],(uint)str[3],(uint)str[4],(uint)str[5],
               (uint)str[6]);
      _applog(2,tmp42,false);
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s chain%d CRC error crc = %02x\n","bm174x_pm_handle",(uint)chainid,(uint)bVar1);
    _applog(0,tmp42,false);
  }
  return;
}




void bm174x_pt_handle(uint8_t *str,int len,uint8_t chainid)

{
  ushort uVar1;
  FILE *__stream;
  uint8_t chainid_local;
  int len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  FILE *fpt;
  uint16_t crc16;
  pattern_test_respond *pt;
  int i;
  
  uVar1 = CRC16_v1(str + 2,len + -4);
  uVar1 = uVar1 >> 8 | uVar1 << 8;
  if (uVar1 == *(ushort *)(str + 0x404)) {
    __stream = fopen("./pattern_result.txt","a+");
    if (__stream == (FILE *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        builtin_strncpy(tmp42,"open failed pattern_result.txt\n",0x20);
        _applog(2,tmp42,false);
      }
    }
    else {
      for (i = 0; i < 0x80; i = i + 1) {
        dump_str(__stream,(char *)0x0,str + i * 8 + 4,8);
      }
      fclose(__stream);
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s chainid=%d cal crc = %04x, chip crc = %04x\n","bm174x_pt_handle",(uint)chainid,(uint)uVar1,
             (uint)*(ushort *)(str + 0x404));
    _applog(2,tmp42,false);
  }
  return;
}




void bm174x_reg_handle(uint8_t *str,int len,uint8_t chainid)

{
  reg_list_item_t item;
  byte bVar1;
  uint8_t chainid_local;
  int len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  reg_list_item_t new_item;
  uint8_t crc5;
  reg_respond *reg;
  
  bVar1 = CRC5_v1(str + 2,((char)len + -3) * '\b' + '\x03');
  if (bVar1 == (str[8] & 0x1f)) {
    item.chip_addr = str[7];
    item.chainid = chainid;
    item.reg_addr = str[2];
    item._3_1_ = new_item._3_1_;
    item.reg_data = (uint)str[5] << 8 | (uint)str[3] << 0x18 | (uint)str[4] << 0x10 | (uint)str[6];
    item.age = 3;
    add_reg_item(item);
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s CRC error crc = %02x\n","bm174x_reg_handle",(uint)bVar1);
    _applog(0,tmp42,false);
  }
  return;
}




int bm174x_nonce_integrality(uint8_t chipid,uint8_t nonce_array_id,int chainid)

{
  ushort uVar1;
  int iVar2;
  int chainid_local;
  uint8_t nonce_array_id_local;
  uint8_t chipid_local;
  char tmp42 [1024];
  uint16_t crc16;
  uint8_t *nonce_p;
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    uVar1 = CRC16_v1(g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i],0x59);
    crc16 = uVar1 >> 8 | uVar1 << 8;
    iVar2 = memcmp(&crc16,g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][i] + 0x59,2);
    if (iVar2 != 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        snprintf(tmp42,0x400,"%s CRC error. cal-crc=%x, chip-crc=%02x%02x\n","bm174x_nonce_integrality",(uint)crc16,
                 (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][0x59],
                 (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][0x5a]);
        _applog(0,tmp42,false);
      }
      return -1;
    }
  }
  for (i = 0; i < 0x10; i = i + 1) {
    if ((g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][i][0] & 0xf) != i) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        snprintf(tmp42,0x400,"nonce is not continous i=%d\n",i);
        _applog(0,tmp42,false);
      }
      return -1;
    }
  }
  for (i = 0; i < 0xf; i = i + 1) {
    if (g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][1] !=
        g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i + 1][1]) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        snprintf(tmp42,0x400,"chip_addr is different %02x != %02x\n",
                 (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][1],
                 (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i + 1][1]);
        _applog(0,tmp42,false);
      }
      return -1;
    }
  }
  for (i = 0; i < 0xf; i = i + 1) {
    if (g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][2] !=
        g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i + 1][2]) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        snprintf(tmp42,0x400,"workID is different %02x != %02x\n",
                 (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][2],
                 (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i + 1][2]);
        _applog(0,tmp42,false);
      }
      return -1;
    }
  }
  i = 0;
  while( true ) {
    if (0xe < i) {
      nonce_p = (uint8_t *)(g_nonce + (uint)nonce_array_id + (uint)chipid);
      for (i = 0; i < 0xf; i = i + 1) {
        memcpy(nonce_p,g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][i] + 4,0x55);
        nonce_p = nonce_p + 0x55;
      }
      memcpy(nonce_p,g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf] + 4,0x45);
      memcpy(g_nonce[(uint)nonce_array_id + (uint)chipid][0].chip_nonce,
             g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf] + 0x55,4);
      g_nonce[(uint)nonce_array_id + (uint)chipid][0].chip_addr =
           g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf][1];
      g_nonce[(uint)nonce_array_id + (uint)chipid][0].work_id =
           g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf][2];
      g_nonce[(uint)nonce_array_id + (uint)chipid][0].nonce_id =
           g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf][3];
      g_nonce[(uint)nonce_array_id + (uint)chipid][0].diff0 =
           g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf][0x4c];
      memcpy(g_nonce[(uint)nonce_array_id + (uint)chipid][0].sha256,
             g_nonce_list[(uint)nonce_array_id + (uint)chipid][0][0xf] + 0x4d,4);
      g_nonce[(uint)nonce_array_id + (uint)chipid][0].chain_id = (uint8_t)chainid;
      return 0;
    }
    if (g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][3] !=
        g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i + 1][3]) break;
    i = i + 1;
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
    snprintf(tmp42,0x400,"nonceID is different %02x != %02x chipid=%d\n",
             (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i][3],
             (uint)g_nonce_list[(uint)chipid + (uint)nonce_array_id][0][i + 1][3],(uint)chipid);
    _applog(0,tmp42,false);
  }
  return -1;
}




int bm174x_nonce_handle(uint8_t *str,int len,uint32_t chainid,int addr_interval)

{
  byte bVar1;
  uint32_t uVar2;
  byte chipid_00;
  int iVar3;
  int addr_interval_local;
  uint32_t chainid_local;
  int len_local;
  uint8_t *str_local;
  char tmp42 [1024];
  int ret;
  uint8_t nonce_array_id;
  uint8_t nonceid;
  uint8_t chipid;
  uint8_t chipaddr;
  uint8_t index;
  
  bVar1 = str[2];
  chipid_00 = __aeabi_idiv(str[3],addr_interval);
  memcpy(g_nonce_list[chipid_00][0] + (bVar1 & 0xf),str + 2,len - 2);
  if ((bVar1 & 0xf) == 0xf) {
    iVar3 = bm174x_nonce_integrality(chipid_00,'\0',chainid);
    uVar2 = bm174x_nonce_handle::total_error;
    if (iVar3 < 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
        bm174x_nonce_handle::total_error = bm174x_nonce_handle::total_error + 1;
        snprintf(tmp42,0x400,"receive a error nonce. total = %u\n",uVar2);
        _applog(1,tmp42,false);
      }
      iVar3 = -1;
    }
    else {
      push_nonce(g_nonce[chipid_00]);
      iVar3 = 0;
    }
  }
  else {
    iVar3 = 1;
  }
  return iVar3;
}




int bm174x_init_asic(void *args)

{
  void *args_local;
  runtime_base_t *runtime;
  
  *(undefined4 *)((int)args + 0x90) = 0x10;
  *(undefined4 *)((int)args + 0x94) = 0x5d;
  *(undefined4 *)((int)args + 0x98) = 9;
  *(undefined4 *)((int)args + 0x9c) = 9;
  *(undefined4 *)((int)args + 0xa0) = 0x406;
  *(undefined4 *)((int)args + 0xa4) = 0x406;
  *(undefined4 *)((int)args + 0xa8) = 0x92;
  *(undefined4 *)((int)args + 0xb30) = 0x11bdd;
  *(undefined4 *)((int)args + 0xb34) = 0x11c1d;
  *(undefined4 *)((int)args + 0xb38) = 0x122a5;
  *(undefined4 *)((int)args + 0xb3c) = 0x11c5d;
  *(undefined4 *)((int)args + 0xb40) = 0x11e89;
  *(undefined4 *)((int)args + 0xb44) = 0x12019;
  *(undefined4 *)((int)args + 0xb48) = 0x1207d;
  *(undefined4 *)((int)args + 0xb4c) = 0x11f29;
  *(undefined4 *)((int)args + 0xb50) = 0x11ded;
  *(undefined4 *)((int)args + 0xb54) = 0x11e4d;
  *(undefined4 *)((int)args + 0xb58) = 0x11e69;
  *(undefined4 *)((int)args + 0xb5c) = 0x11cfd;
  *(undefined4 *)((int)args + 0xb60) = 0x11f65;
  *(undefined4 *)((int)args + 0xb64) = 0x11fbd;
  *(undefined4 *)((int)args + 0xb70) = 0x120d5;
  *(undefined4 *)((int)args + 0xb74) = 0x12125;
  *(undefined4 *)((int)args + 0xb6c) = 0x12159;
  *(undefined4 *)((int)args + 0xb68) = 0x12215;
  *(undefined4 *)((int)args + 0xb8c) = 0x125a5;
  *(undefined4 *)((int)args + 0xb90) = 0x12f95;
  *(undefined4 *)((int)args + 0xb88) = 0x12409;
  *(undefined4 *)((int)args + 0xb84) = 0x122c1;
  return 0;
}




void delay(int seconds)

{
  int seconds_local;
  char tmp42 [1024];
  int i;
  
  i = 0;
  while (i < seconds) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"remain %d seconds......\n",seconds - (i + 1));
      _applog(2,tmp42,false);
    }
    sleep(1);
    i = i + 1;
  }
  return;
}




void check_asic_num(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  reg_list_item_t item_r;
  int asicid;
  
  (*runtime->read_register)(runtime->chain_status[runtime->chain_id].fd,1,'\0','\0');
  item_r.chainid = (uint8_t)runtime->chain_id;
  item_r.chip_addr = '\0';
  item_r.reg_addr = '\0';
  item_r.reg_data = 0;
  item_r.age = 0;
  runtime->chain_status[runtime->chain_id].real_asic_num = 0;
  for (asicid = 0; asicid < app_conf->asic_num; asicid = asicid + 1) {
    iVar1 = read_reg_item(&item_r,500);
    if (0 < iVar1) {
      runtime->chain_status[runtime->chain_id].real_asic_num =
           runtime->chain_status[runtime->chain_id].real_asic_num + 1;
    }
  }
  return;
}




void set_asic_address(runtime_base_t *runtime,uchar chainid)

{
  uchar chainid_local;
  runtime_base_t *runtime_local;
  int i;
  
  (*runtime->chain_inactive)(runtime->chain_status[chainid].fd);
  for (i = 0; i < runtime->chain_status[chainid].design_asic_num; i = i + 1) {
    (*runtime->set_address)(runtime->chain_status[chainid].fd,(char)runtime->addr_interval * (char)i);
  }
  return;
}




int calc_asic_addr_interval(int actual_asic_number)

{
  int iVar1;
  int actual_asic_number_local;
  char tmp42 [1024];
  int i;
  
  if (actual_asic_number == 1) {
    i = 1;
  }
  else if (actual_asic_number == 2) {
    i = 2;
  }
  else if ((actual_asic_number < 3) || (4 < actual_asic_number)) {
    if ((actual_asic_number < 5) || (8 < actual_asic_number)) {
      if ((actual_asic_number < 9) || (0x10 < actual_asic_number)) {
        if ((actual_asic_number < 0x11) || (0x20 < actual_asic_number)) {
          if ((actual_asic_number < 0x21) || (0x40 < actual_asic_number)) {
            if ((actual_asic_number < 0x41) || (0x80 < actual_asic_number)) {
              if ((opt_debug) && (((use_syslog || (opt_log_output)) || (3 < opt_log_level)))) {
                snprintf(tmp42,0x400,"actual_asic_number = %d, but it is error\n",actual_asic_number);
                _applog(4,tmp42,false);
              }
              return -1;
            }
            i = 0x80;
          }
          else {
            i = 0x40;
          }
        }
        else {
          i = 0x20;
        }
      }
      else {
        i = 0x10;
      }
    }
    else {
      i = 8;
    }
  }
  else {
    i = 4;
  }
  iVar1 = __aeabi_idiv(0x100,i);
  return iVar1;
}




void user_i2c_enable(runtime_base_t *runtime,uchar chainid)

{
  uchar chainid_local;
  runtime_base_t *runtime_local;
  int i;
  
  for (i = 0; i < runtime->chain_status[runtime->chain_id].design_asic_num; i = i + 1) {
    (*runtime->i2c_enable)(runtime->chain_status[chainid].fd,(char)runtime->addr_interval * (char)i);
  }
  return;
}




int user_i2c_state(runtime_base_t *runtime,int chip_addr)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int chip_addr_local;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  reg_list_item_t item;
  int chainid;
  int check_loop;
  
  iVar3 = runtime->chain_id;
  check_loop = 3;
  do {
    (*runtime->i2c_status)(runtime->chain_status[iVar3].fd,(uint8_t)chip_addr);
    item.reg_data = 0;
    item.age = 0;
    item.chip_addr = (uint8_t)chip_addr;
    item.chainid = (uint8_t)runtime->chain_id;
    item.reg_addr = ' ';
    item._3_1_ = 0;
    iVar2 = read_reg_item(&item,1000);
    if (iVar2 < 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
        snprintf(tmp42,0x400,"chipaddr %02x - i2c no-response\n",chip_addr);
        _applog(1,tmp42,false);
      }
    }
    else {
      if (-1 < (int)item.reg_data) break;
      if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
        snprintf(tmp42,0x400,"chipaddr %02x - i2c is busy\n",chip_addr);
        _applog(1,tmp42,false);
      }
    }
    iVar2 = check_loop + -1;
    bVar1 = 0 < check_loop;
    check_loop = iVar2;
  } while (bVar1);
  if (check_loop < 1) {
    iVar3 = -1;
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}




int user_read_iic(runtime_base_t *runtime,int chip_addr,uint8_t i2c_dev_addr,uint8_t i2c_reg_addr,uint8_t *i2c_reg_data,
                 int len)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint8_t i2c_reg_addr_local;
  uint8_t i2c_dev_addr_local;
  int chip_addr_local;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  reg_list_item_t itemreg;
  int fd;
  int chainid;
  int i;
  int ret;
  
  ret = 1;
  iVar2 = runtime->chain_id;
  iVar3 = runtime->chain_status[iVar2].fd;
  iVar1 = user_i2c_state(runtime,chip_addr);
  if (iVar1 == 0) {
    iVar1 = (*runtime->i2c_recv)(iVar3,(uint8_t)chip_addr,i2c_dev_addr,i2c_reg_addr,len);
    if (iVar1 == 0) {
      itemreg.chainid = (uint8_t)iVar2;
      itemreg.reg_addr = ' ';
      itemreg.reg_data = 0;
      itemreg.age = 0;
      itemreg.chip_addr = (uint8_t)chip_addr;
      for (i = 0; i < len; i = i + 1) {
        iVar1 = read_reg_item(&itemreg,500);
        if ((iVar1 < 1) || ((itemreg.reg_data & 0xc0000000) != 0)) {
          if ((use_syslog != false) || ((opt_log_output != false || (0 < opt_log_level)))) {
            snprintf(tmp42,0x400,"Read i2c failed chipaddr=%02x, i2c-regaddr=%02x i2c-regdata=%08x\n",chip_addr,
                     (uint)i2c_reg_addr,itemreg.reg_data);
            _applog(1,tmp42,false);
          }
          ret = 1;
        }
        else {
          i2c_reg_data[i] = (uint8_t)itemreg.reg_data;
          ret = 0;
        }
      }
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
        snprintf(tmp42,0x400,"Read i2c failed chipaddr=%02x, i2c-regaddr=%02x\n",chip_addr,(uint)i2c_reg_addr);
        _applog(1,tmp42,false);
      }
      ret = 1;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"i2c state check failed\n",0x18);
      _applog(2,tmp42,false);
    }
    ret = 1;
  }
  return ret;
}




/* WARNING: Variable defined which should be unmapped: test_patten_local */
/* WARNING: Variable defined which should be unmapped: sno_valid_local */

void user_send_work(runtime_base_t *runtime,uint8_t *header,int sno_valid,int test_patten)

{
  int iVar1;
  int test_patten_local;
  int sno_valid_local;
  uint8_t *header_local;
  runtime_base_t *runtime_local;
  work_input work;
  int chainid;
  
  iVar1 = runtime->chain_id;
  memset(&work,0,0x92);
  work._2_1_ = work._2_1_ & 0xee | (byte)((sno_valid & 1U) << 4) | (byte)test_patten & 1;
  work.workid = runtime->total_work;
  runtime->total_work = work.workid + '\x01';
  memcpy(work.work,header,0x8c);
  work_list_insert(work.workid,work.work);
  (*runtime->send_work)(runtime->chain_status[iVar1].fd,&work.header_55);
  return;
}




void online_mining(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  int chainid;
  
  iVar1 = runtime->chain_id;
  (*runtime->set_ticket_mask)(runtime->chain_status[iVar1].fd,app_conf->ticket_mask);
  usleep(100000);
  (*runtime->set_core_timeout)(runtime->chain_status[iVar1].fd,app_conf->core_timeout);
  usleep(100000);
  (*runtime->set_frequency)(runtime->chain_status[iVar1].fd,app_conf->bringup_freq);
  usleep(100000);
  (*runtime->set_nonce_shift)(runtime->chain_status[iVar1].fd,0,&runtime->nonce_shift);
  usleep(100000);
  equihash_miner_start(runtime);
  equihash_miner_join();
  return;
}




int pattern_test(runtime_base_t *runtime,int freq,int *nonce)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *nonce_local;
  int freq_local;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  char golden [20];
  char result [20];
  bm174x_reg pt_result_reg;
  uint8_t header_bin [140];
  reg_list_item_t item;
  char *header;
  int read_timeout_limit;
  int chainid;
  int read_timeout_counter;
  FILE *fpr;
  FILE *fpg;
  int match_num;
  int i;
  
  iVar3 = runtime->chain_id;
  match_num = 0;
  fpg = (FILE *)0x0;
  fpr = (FILE *)0x0;
  remove("./pattern_result.txt");
  (*runtime->set_pt_ctrl)(runtime->chain_status[iVar3].fd,0,0);
  usleep(100000);
  (*runtime->set_ticket_mask)(runtime->chain_status[iVar3].fd,5);
  usleep(100000);
  (*runtime->set_core_timeout)(runtime->chain_status[iVar3].fd,45000);
  usleep(100000);
  (*runtime->set_txn_data)(runtime->chain_status[iVar3].fd,0);
  usleep(100000);
  (*runtime->set_frequency)(runtime->chain_status[iVar3].fd,freq);
  usleep(100000);
  (*runtime->set_pt_ctrl)(runtime->chain_status[iVar3].fd,0x7ff,1);
  usleep(100000);
  memset(header_bin,0,0x8c);
  hex2bin(header_bin,
          "010203042cb3d32b0b61304401cbe540448a4cacd7e98421a850503e2f0d102f1d3454151484151215484aa0ca1932037525e2eb9a22d3d3ff1502b320f8d9ca56377f56494b2cacf3377482ccd34188c1b25e04187ccf70af6e2244c3c96e5e2e3a6015d32fe451ad000e771eccb5c5e3d6beb470359446494d25e15f87df87c3119ebd9ca813a400000000"
          ,0x8c);
  user_send_work(runtime,header_bin,0,0);
  sleep(3);
  item.age = 3;
  item.chainid = '\0';
  item.chip_addr = '\0';
  item.reg_addr = '`';
  read_timeout_counter = 0;
  while (read_timeout_counter < 0xf) {
    (*runtime->read_register)(runtime->chain_status[iVar3].fd,1,'\0','`');
    iVar2 = read_reg_item(&item,500);
    uVar1 = tmp42._20_4_;
    if (iVar2 < 1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        builtin_strncpy(tmp42,"REG_PT_RESULT read timeout\n",0x1c);
        _applog(0,tmp42,false);
      }
    }
    else {
      pt_result_reg.core_timeout.core_timeout._2_2_ = (undefined2)(item.reg_data >> 0x10);
      if ((pt_result_reg.core_timeout.core_timeout._2_2_ & 0xfff) == 0x800) {
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          builtin_strncpy(tmp42,"pattern test finished\n",0x17);
          tmp42[0x17] = SUB41(uVar1,3);
          _applog(2,tmp42,false);
        }
        break;
      }
      if ((opt_debug != false) && (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
        snprintf(tmp42,0x400,"REG_PT_RESULT cur num = %d < 0x800, check again\n",
                 (ushort)pt_result_reg.core_timeout.core_timeout._2_2_ & 0xfff);
        _applog(4,tmp42,false);
      }
    }
    read_timeout_counter = read_timeout_counter + 1;
    sleep(1);
  }
  uVar1 = tmp42._36_4_;
  if (read_timeout_counter < 0xf) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      builtin_strncpy(tmp42,"pattern test finished, read out nonce\n",0x27);
      tmp42[0x27] = SUB41(uVar1,3);
      _applog(0,tmp42,false);
    }
    for (i = 0; i < 0x10; i = i + 1) {
      (*runtime->set_pt_result)(runtime->chain_status[iVar3].fd,i,1);
      usleep(200000);
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"Compare golden nonce and current nonce\n",0x28);
      _applog(2,tmp42,false);
    }
    fpr = (FILE *)fopen("./pattern_result.txt","r");
    if (fpr == (FILE *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        builtin_strncpy(tmp42,"open failed pattern_result.txt\n",0x20);
        _applog(0,tmp42,false);
      }
    }
    else {
      fpg = (FILE *)fopen("./pattern_golden.txt","r");
      if (fpg == (FILE *)0x0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
          builtin_strncpy(tmp42,"open failed pattern_golden.txt\n",0x20);
          _applog(0,tmp42,false);
        }
      }
      else {
LAB_000141b0:
        iVar3 = feof((FILE *)fpr);
        if (iVar3 == 0) {
          result[0] = '\0';
          result[1] = '\0';
          result[2] = '\0';
          result[3] = '\0';
          result[4] = '\0';
          result[5] = '\0';
          result[6] = '\0';
          result[7] = '\0';
          result[8] = '\0';
          result[9] = '\0';
          result[10] = '\0';
          result[0xb] = '\0';
          result[0xc] = '\0';
          result[0xd] = '\0';
          result[0xe] = '\0';
          result[0xf] = '\0';
          result[0x10] = '\0';
          result[0x11] = '\0';
          result[0x12] = '\0';
          result[0x13] = '\0';
          fgets(result,0x400,(FILE *)fpr);
          fseek((FILE *)fpg,0,0);
          do {
            iVar3 = feof((FILE *)fpg);
            if (iVar3 != 0) goto LAB_000141b0;
            golden[0] = '\0';
            golden[1] = '\0';
            golden[2] = '\0';
            golden[3] = '\0';
            golden[4] = '\0';
            golden[5] = '\0';
            golden[6] = '\0';
            golden[7] = '\0';
            golden[8] = '\0';
            golden[9] = '\0';
            golden[10] = '\0';
            golden[0xb] = '\0';
            golden[0xc] = '\0';
            golden[0xd] = '\0';
            golden[0xe] = '\0';
            golden[0xf] = '\0';
            golden[0x10] = '\0';
            golden[0x11] = '\0';
            golden[0x12] = '\0';
            golden[0x13] = '\0';
            fgets(golden,0x400,(FILE *)fpg);
            iVar3 = strncmp(golden,result,0x10);
          } while ((iVar3 != 0) || (golden[0] == '\0'));
          match_num = match_num + 1;
          goto LAB_000141b0;
        }
      }
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"patten test timeout\n",0x14);
    tmp42._20_4_ = tmp42._20_4_ & 0xffffff00;
    _applog(2,tmp42,false);
  }
  if (fpg != (FILE *)0x0) {
    fclose((FILE *)fpg);
  }
  if (fpr != (FILE *)0x0) {
    fclose((FILE *)fpr);
  }
  *nonce = match_num;
  return 0;
}




int pattern_test_mode2(runtime_base_t *runtime,int freq,int *nonce)

{
  bool bVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  int *nonce_local;
  int freq_local;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int counter_limit;
  int patten_check_interval;
  int is_match;
  int one_patten_bin_len;
  int chainid;
  int counter;
  int which_patten;
  int which_core;
  int which_asic;
  
  iVar4 = runtime->chain_id;
  clear_last_test_results();
  (*runtime->set_ticket_mask)(runtime->chain_status[iVar4].fd,app_conf->ticket_mask);
  usleep(100000);
  (*runtime->set_core_timeout)(runtime->chain_status[iVar4].fd,app_conf->core_timeout);
  usleep(100000);
  (*runtime->set_frequency)(runtime->chain_status[iVar4].fd,freq);
  usleep(100000);
  (*runtime->set_nonce_shift)(runtime->chain_status[iVar4].fd,0,&runtime->nonce_shift);
  iVar4 = g_patten.sol_bin_len + g_patten.work_bin_len + g_patten.nonce_bin_len;
  g_patten.start = 1;
  sleep(1);
  which_asic = 0;
  do {
    if (g_patten.asic_num <= which_asic) {
      g_patten.start = 0;
      *nonce = g_patten.recv_nonces;
      return 0;
    }
    for (which_core = 0; which_core < g_patten.core_num; which_core = which_core + 1) {
      for (which_patten = 0; which_patten < g_patten.patten_num; which_patten = which_patten + 1) {
        pthread_mutex_lock((pthread_mutex_t *)&g_patten.patten_mutex);
        g_patten.cur_work =
             g_patten.patten_start +
             iVar4 * which_core * g_patten.patten_num + iVar4 * g_patten.patten_num * which_asic * g_patten.core_num +
             iVar4 * which_patten;
        g_patten.cur_asic = which_asic;
        g_patten.cur_core = which_core;
        g_patten.cur_patten = which_patten;
        pthread_mutex_unlock((pthread_mutex_t *)&g_patten.patten_mutex);
        g_patten.cur_work[g_patten.work_bin_len + -1] = g_patten.cur_work[g_patten.work_bin_len + -1] + 0xff;
        user_send_work(runtime,g_patten.cur_work,1,0);
        iVar3 = __aeabi_idiv(app_conf->slt_work_interval_ms,0x32);
        counter = 0;
        do {
          usleep(50000);
          pthread_mutex_lock((pthread_mutex_t *)&g_patten.patten_mutex);
          uVar2 = g_patten.is_nonce_match
                  [g_patten.cur_patten +
                   g_patten.patten_num * (g_patten.core_num * g_patten.cur_asic + g_patten.cur_core)];
          pthread_mutex_unlock((pthread_mutex_t *)&g_patten.patten_mutex);
          if (uVar2 == '\x01') break;
          bVar1 = counter < iVar3;
          counter = counter + 1;
        } while (bVar1);
        if (uVar2 != '\x01') {
          if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
            snprintf(tmp42,0x400,"pattern id %d receive failed\n",which_patten);
            _applog(2,tmp42,false);
          }
          dump_str(stderr,(char *)0x0,g_patten.cur_work,g_patten.work_bin_len);
        }
      }
    }
    which_asic = which_asic + 1;
  } while( true );
}




int user_asic_init(runtime_base_t *runtime)

{
  int iVar1;
  int iVar2;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int chainid;
  int check_times;
  
  iVar2 = runtime->chain_id;
  check_times = 3;
  do {
    check_asic_num(runtime);
    if (0 < runtime->chain_status[iVar2].real_asic_num) break;
    sleep(1);
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"check again check_times = %d\n",check_times);
      _applog(2,tmp42,false);
    }
    check_times = check_times + -1;
  } while (0 < check_times);
  if (check_times < 1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      builtin_strncpy(tmp42,"check asic faile",0x10);
      tmp42[0x10] = 'd';
      tmp42[0x11] = '\n';
      tmp42[0x12] = '\0';
      _applog(0,tmp42,false);
    }
    iVar2 = -1;
  }
  else {
    runtime->start_recv = 0;
    if (runtime->baudrate != 0x1c200) {
      sleep(1);
      (*runtime->set_baud)(runtime->chain_status[iVar2].fd,runtime->baudrate);
      sleep(1);
      uart_exit(runtime->chain_status[iVar2].fd);
      sleep(1);
      iVar1 = uart_init(runtime->chain_status[iVar2].comport,runtime->baudrate);
      runtime->chain_status[iVar2].fd = iVar1;
      sleep(1);
    }
    runtime->start_recv = 1;
    iVar2 = 0;
  }
  return iVar2;
}




int user_check_communication(runtime_base_t *runtime)

{
  int iVar1;
  int iVar2;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  reg_list_item_t item;
  uint8_t regaddr;
  uint8_t chipaddr;
  int count_max;
  int chainid;
  int count;
  
  iVar2 = runtime->chain_id;
  count = 0;
  item.chainid = (uint8_t)iVar2;
  item.chip_addr = '\0';
  item.reg_addr = '\0';
  item.reg_data = 0;
  item.age = 0;
  do {
    (*runtime->read_register)(runtime->chain_status[iVar2].fd,1,'\0','\0');
    iVar1 = read_reg_item(&item,500);
    if (-1 < iVar1) {
      return count;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s  failed %d\n","user_check_communication",count);
      _applog(2,tmp42,false);
    }
    sleep(1);
    count = count + 1;
  } while (count < 3);
  return -1;
}




void env_init(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  int chainid;
  int sensorid;
  
  strcpy(runtime->asic_name,app_conf->name);
  iVar1 = calc_asic_addr_interval(app_conf->asic_num);
  runtime->addr_interval = iVar1;
  runtime->sensor_num = app_conf->sensor_num;
  for (sensorid = 0; sensorid < app_conf->sensor_num; sensorid = sensorid + 1) {
    runtime->sensor_pos[sensorid] = app_conf->sensor_pos[sensorid];
  }
  runtime->chain_num = app_conf->comport_num;
  for (chainid = 0; chainid < runtime->chain_num; chainid = chainid + 1) {
    runtime->chain_status[chainid].comport = app_conf->comport[chainid];
    runtime->chain_status[chainid].design_asic_num = app_conf->asic_num;
  }
  runtime->baudrate = app_conf->baudrate;
  runtime->nonce_shift = 0x14;
  bm174x_init_asic(runtime);
  equihash_init_algo(runtime);
  equihash_miner_init(runtime);
  return;
}




void randomize(void *p,int l)

{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  ssize_t sVar4;
  int l_local;
  void *p_local;
  char tmp42 [1024];
  int ret;
  int fd;
  char *fname;
  
  iVar1 = open("/dev/urandom",0);
  if (iVar1 == -1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x400,"open %s: %s\n","/dev/urandom",pcVar3);
      _applog(0,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  sVar4 = read(iVar1,p,l);
  if (sVar4 == -1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x400,"read %s: %s\n","/dev/urandom",pcVar3);
      _applog(0,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (sVar4 != l) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: short read %d bytes out of %d\n","/dev/urandom",sVar4,l);
      _applog(0,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  iVar1 = close(iVar1);
  if (iVar1 == -1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x400,"close %s: %s\n","/dev/urandom",pcVar3);
      _applog(0,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  return;
}




void set_blocking_mode(int fd,int block)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  int block_local;
  int fd_local;
  char tmp42 [1024];
  int f;
  
  uVar1 = fcntl(fd,3);
  if (uVar1 == 0xffffffff) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x400,"fcntl F_GETFL: %s\n",pcVar3);
      _applog(0,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (block == 0) {
    uVar1 = uVar1 | 0x800;
  }
  else {
    uVar1 = uVar1 & 0xfffff7ff;
  }
  iVar4 = fcntl(fd,4,uVar1);
  if (iVar4 == -1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x400,"fcntl F_SETFL: %s\n",pcVar3);
      _applog(0,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  return;
}




uint8_t hex2val(char *base,size_t off)

{
  byte bVar1;
  uint8_t uVar2;
  size_t off_local;
  char *base_local;
  char tmp42 [1024];
  char c;
  
  bVar1 = base[off];
  if ((bVar1 < 0x30) || (0x39 < bVar1)) {
    if ((bVar1 < 0x61) || (0x66 < bVar1)) {
      if ((bVar1 < 0x41) || (0x46 < bVar1)) {
        if ((use_syslog) || ((opt_log_output || (-1 < opt_log_level)))) {
          snprintf(tmp42,0x400,"Invalid hex char at offset %zd: ...%c...\n",off,(uint)bVar1);
          _applog(0,tmp42,false);
        }
        uVar2 = '\0';
      }
      else {
        uVar2 = bVar1 - 0x37;
      }
    }
    else {
      uVar2 = bVar1 + 0xa9;
    }
  }
  else {
    uVar2 = bVar1 - 0x30;
  }
  return uVar2;
}




char * s_hexdump(void *_a,uint32_t a_len)

{
  uint32_t a_len_local;
  void *_a_local;
  uint8_t *a;
  uint32_t i;
  
  for (i = 0; (i < a_len && (i + 2 < 0x1000)); i = i + 1) {
    sprintf(s_hexdump::buf + i * 2,"%02x",(uint)*(byte *)(i + (int)_a));
  }
  s_hexdump::buf[i * 2] = '\0';
  return s_hexdump::buf;
}




void hexdump(uchar *p,uint len)

{
  byte bVar1;
  uint uVar2;
  undefined1 auStack_98 [80];
  uint len_local;
  uchar *p_local;
  int pos;
  uchar v;
  uchar_0_ *line;
  undefined4 local_30;
  uint wordlen;
  uint addr;
  uint i;
  
  wordlen = 4;
  local_30 = 0x4f;
  line = auStack_98;
  len_local = len;
  p_local = p;
  for (addr = 0; addr < len_local; addr = addr + 0x10) {
    for (i = 0; i < 0x50; i = i + 1) {
      if (((wordlen + 0x1a) * 2 - i == 0) || (wordlen * 2 + 0x45 == i)) {
        line[i] = 0x7c;
      }
      else if ((wordlen + 0x23) * 2 - i == 0) {
        line[i] = 0;
      }
      else {
        line[i] = 0x20;
      }
    }
    for (i = 0; i <= wordlen * 2 && wordlen * 2 - i != 0; i = i + 1) {
      uVar2 = addr >> (((wordlen * 2 - i) + 0x3fffffff) * 4 & 0xff);
      v = (uchar)uVar2;
      line[i] = nibble[uVar2 & 0xf];
    }
    for (i = 0; (i < 0x10 && (pos = (i >> 3) + wordlen * 2 + 3, addr + i < len_local)); i = i + 1) {
      v = p_local[i + addr];
      line[i * 3 + pos] = nibble[v >> 4];
      line[pos + i * 3 + 1] = nibble[v & 0xf];
      if ((v < 0x20) || (bVar1 = v, 0x7e < v)) {
        bVar1 = 0x2e;
      }
      line[i + wordlen * 2 + 0x35] = bVar1;
    }
    fprintf(stderr,"%s\n",line);
  }
  return;
}




uint32_t print_solver_line(uint8_t *soln,uint8_t *header,int fixed_nonce_bytes,char *job_id)

{
  char *pcVar1;
  char *job_id_local;
  int fixed_nonce_bytes_local;
  uint8_t *header_local;
  uint8_t *soln_local;
  uint8_t buffer [1487];
  uint8_t *p;
  
  memcpy(buffer,header,0x8c);
  memcpy(buffer + 0x8c,&DAT_000346c4,3);
  memcpy(buffer + 0x8f,soln,0x540);
  printf("sol: %s ",job_id);
  printf("%02x%02x%02x%02x ",(uint)header[100],(uint)header[0x65],(uint)header[0x66],(uint)header[0x67]);
  pcVar1 = s_hexdump(header + fixed_nonce_bytes + 0x6c,0x20 - fixed_nonce_bytes);
  printf("%s ",pcVar1);
  pcVar1 = s_hexdump(buffer + 0x8f,0x540);
  printf("%s%s\n","fd4005",pcVar1);
  fflush(stdout);
  return 1;
}




void * memrchr(void *__s,int __c,size_t __n)

{
  size_t n_local;
  int c_local;
  void *s_local;
  char *start;
  char *end;
  
  end = (char *)(__n + (int)__s);
  do {
    end = end + -1;
    if (end < __s) {
      return (void *)0x0;
    }
  } while ((uint)(byte)*end != __c);
  return (byte *)end;
}




int read_last_line(char *buf,size_t len,int block)

{
  ssize_t sVar1;
  int *piVar2;
  char *pcVar3;
  void *pvVar4;
  int block_local;
  size_t len_local;
  char *buf_local;
  char tmp42 [1024];
  char *start;
  ssize_t n;
  size_t pos;
  
  pos = 0;
  set_blocking_mode(0,block);
LAB_00015218:
  sVar1 = read(0,buf + pos,len - pos);
  if (sVar1 == -1) {
    piVar2 = __errno_location();
    if (*piVar2 == 4) goto LAB_00015218;
  }
  if ((sVar1 == -1) && ((piVar2 = __errno_location(), *piVar2 == 0xb || (piVar2 = __errno_location(), *piVar2 == 0xb))))
  {
    if (pos == 0) {
      return 0;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      snprintf(tmp42,0x400,"strange: a partial line was read %s\n",pcVar3);
      _applog(1,tmp42,false);
    }
    set_blocking_mode(0,1);
  }
  else {
    if (sVar1 == -1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        piVar2 = __errno_location();
        pcVar3 = strerror(*piVar2);
        snprintf(tmp42,0x400,"read stdin: %s\n",pcVar3);
        _applog(0,tmp42,false);
      }
    }
    else if ((sVar1 == 0) && (((use_syslog != false || (opt_log_output != false)) || (-1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"%s EOF on stdin\n","read_last_line");
      _applog(0,tmp42,false);
    }
    pos = sVar1 + pos;
    if (buf[pos - 1] == '\n') {
      pvVar4 = memrchr(buf,10,pos - 1);
      if (pvVar4 != (void *)0x0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
          snprintf(tmp42,0x400,"%s strange: more than 1 line was read\n","read_last_line");
          _applog(1,tmp42,false);
        }
        pos = pos - ((int)pvVar4 + (1 - (int)buf));
        memmove(buf,(void *)((int)pvVar4 + 1),pos);
      }
      buf[pos - 1] = '\0';
      return 1;
    }
  }
  goto LAB_00015218;
}




void mining_parse_job(char *str,uint8_t *target,int target_len,char *job_id,int job_id_len,uint8_t *header,
                     int header_len,int *fixed_nonce_bytes)

{
  uint32_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  char *job_id_local;
  int target_len_local;
  uint8_t *target_local;
  char *str_local;
  char tmp42 [1024];
  uint32_t i;
  uint32_t str_i;
  
  str_i = 0;
  for (i = 0; i < (uint)target_len; i = i + 1) {
    uVar2 = hex2val(str,str_i);
    uVar3 = hex2val(str,str_i + 1);
    target[i] = uVar3 + uVar2 * '\x10';
    str_i = str_i + 2;
  }
  if (str[str_i] != ' ') {
                    /* WARNING: Subroutine does not return */
    __assert_fail("str[str_i] == \' \'","bm174x/equihash-miner.c",0x152,"mining_parse_job");
  }
  i = 0;
  uVar1 = str_i;
  while ((str_i = uVar1 + 1, i < (uint)job_id_len && (str[str_i] != ' '))) {
    job_id[i] = str[str_i];
    i = i + 1;
    uVar1 = str_i;
  }
  if (str[str_i] != ' ') {
                    /* WARNING: Subroutine does not return */
    __assert_fail("str[str_i] == \' \'","bm174x/equihash-miner.c",0x158,"mining_parse_job");
  }
  if ((uint)job_id_len <= i) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("i < job_id_len","bm174x/equihash-miner.c",0x159,"mining_parse_job");
  }
  job_id[i] = '\0';
  i = 0;
  while ((str_i = uVar1 + 2, i < (uint)header_len && (str[str_i] != ' '))) {
    uVar2 = hex2val(str,str_i);
    uVar3 = hex2val(str,uVar1 + 3);
    header[i] = uVar3 + uVar2 * '\x10';
    i = i + 1;
    uVar1 = str_i;
  }
  if (str[str_i] != ' ') {
                    /* WARNING: Subroutine does not return */
    __assert_fail("str[str_i] == \' \'","bm174x/equihash-miner.c",0x160,"mining_parse_job");
  }
  str_i = uVar1 + 3;
  *fixed_nonce_bytes = 0;
  while ((i < (uint)header_len && (str[str_i] != '\0'))) {
    uVar2 = hex2val(str,str_i);
    uVar3 = hex2val(str,str_i + 1);
    header[i] = uVar3 + uVar2 * '\x10';
    i = i + 1;
    str_i = str_i + 2;
    *fixed_nonce_bytes = *fixed_nonce_bytes + 1;
  }
  if (str[str_i] != '\0') {
                    /* WARNING: Subroutine does not return */
    __assert_fail("!str[str_i]","bm174x/equihash-miner.c",0x16b,"mining_parse_job");
  }
  if ((opt_debug != false) && (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
    snprintf(tmp42,0x400,"Randomizing %d bytes in nonce\n",(header_len - i) + -0xc);
    _applog(4,tmp42,false);
  }
  randomize(header + i,(header_len - i) + -0xc);
  memset(header + header_len + -0xc,0,0xc);
  return;
}




/* WARNING: Removing unreachable block (ram,0x000158a4) */

void * mining_mode(void *args)

{
  int iVar1;
  void *args_local;
  char line [4096];
  uint64_t i;
  runtime_base_t *runtime;
  
  puts("SILENTARMY mining mode ready");
  fflush(stdout);
  do {
    do {
      usleep(100000);
      iVar1 = read_last_line(line,0x1000,1);
    } while (iVar1 == 0);
    pthread_mutex_lock((pthread_mutex_t *)&g_work_info.work_info_mutex);
    mining_parse_job(line,g_work_info.target,0x20,g_work_info.job_id,0x100,g_work_info.header,0x8c,
                     &g_work_info.fixed_nonce_bytes);
    user_send_work((runtime_base_t *)args,g_work_info.header,0,0);
    pthread_mutex_unlock((pthread_mutex_t *)&g_work_info.work_info_mutex);
  } while( true );
}




/* WARNING: Unknown calling convention */

uint64_t miner_now(void)

{
  int iVar1;
  int iVar2;
  timeval tv;
  
  gettimeofday((timeval *)&tv,(__timezone_ptr_t)0x0);
  iVar1 = tv.tv_sec >> 0x1f;
  iVar2 = ((((iVar1 << 5 | (uint)tv.tv_sec >> 0x1b) - iVar1) - (uint)((uint)(tv.tv_sec * 0x20) < (uint)tv.tv_sec)) *
           0x200 | (uint)(tv.tv_sec * 0x1f) >> 0x17) + iVar1 + (uint)CARRY4(tv.tv_sec * 0x3e00,tv.tv_sec);
  return CONCAT44((tv.tv_usec >> 0x1f) +
                  iVar1 + (((iVar2 * 0x40 | (uint)(tv.tv_sec * 0x3e01) >> 0x1a) - iVar2) -
                          (uint)((uint)(tv.tv_sec * 0xf8040) < (uint)(tv.tv_sec * 0x3e01))) +
                          (uint)CARRY4(tv.tv_sec,tv.tv_sec * 999999) + (uint)CARRY4(tv.tv_usec,tv.tv_sec * 1000000),
                  tv.tv_usec + tv.tv_sec * 1000000);
}




void equihash_nonce_submit(uint8_t *nonce,uint8_t *verify,int fixed_nonce_bytes,char *job_id)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  uint64_t uVar4;
  char *job_id_local;
  int fixed_nonce_bytes_local;
  uint8_t *verify_local;
  uint8_t *nonce_local;
  char tmp42 [1024];
  
  iVar1 = equihash_nonce_submit::golden_nonce;
  bVar3 = 0xfffffffe < (uint)equihash_nonce_submit::total;
  equihash_nonce_submit::total._0_4_ = (uint)equihash_nonce_submit::total + 1;
  equihash_nonce_submit::total._4_4_ = equihash_nonce_submit::total._4_4_ + (uint)bVar3;
  if (((use_syslog) || (opt_log_output)) || (2 < opt_log_level)) {
    equihash_nonce_submit::golden_nonce = equihash_nonce_submit::golden_nonce + 1;
    snprintf(tmp42,0x400,"Golden Nonce Found! %d\n",iVar1);
    _applog(3,tmp42,false);
  }
  print_solver_line(nonce,verify,fixed_nonce_bytes,job_id);
  bVar3 = 0xfffffffe < (uint)equihash_nonce_submit::total_shares;
  equihash_nonce_submit::total_shares._0_4_ = (uint)equihash_nonce_submit::total_shares + 1;
  equihash_nonce_submit::total_shares._4_4_ = equihash_nonce_submit::total_shares._4_4_ + (uint)bVar3;
  uVar4 = miner_now();
  equihash_nonce_submit::t1._0_4_ = (uint)uVar4;
  equihash_nonce_submit::t1._4_4_ = (uint)(uVar4 >> 0x20);
  uVar2 = equihash_nonce_submit::status_period._4_4_ +
          equihash_nonce_submit::t0._4_4_ +
          CARRY4((uint)equihash_nonce_submit::status_period,(uint)equihash_nonce_submit::t0);
  bVar3 = equihash_nonce_submit::t1._4_4_ <= uVar2;
  if (uVar2 == equihash_nonce_submit::t1._4_4_) {
    bVar3 = (uint)equihash_nonce_submit::t1 <=
            (uint)equihash_nonce_submit::status_period + (uint)equihash_nonce_submit::t0;
  }
  if (!bVar3) {
    equihash_nonce_submit::t0._0_4_ = (uint)equihash_nonce_submit::t1;
    equihash_nonce_submit::t0._4_4_ = equihash_nonce_submit::t1._4_4_;
    equihash_nonce_submit::t1 = uVar4;
    printf("status: %lld %lld\n",(uint)equihash_nonce_submit::total,(uint)equihash_nonce_submit::total,
           equihash_nonce_submit::total._4_4_,(uint)equihash_nonce_submit::total_shares,
           equihash_nonce_submit::total_shares._4_4_);
    fflush(stdout);
    uVar4 = equihash_nonce_submit::t1;
  }
  equihash_nonce_submit::t1 = uVar4;
  return;
}




void equihash_miner_init(runtime_base_t *runtime)

{
  runtime_base_t *runtime_local;
  
  runtime->nonce_submit = (_func_void_uint8_t_ptr_uint8_t_ptr_int_char_ptr *)0x15995;
  return;
}




void equihash_miner_start(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  
  iVar1 = pthread_create(&p_miner,(pthread_attr_t *)0x0,(__start_routine *)0x15829,runtime);
  if (iVar1 == 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      builtin_strncpy(tmp42,"create mining mode thread successed\n",0x24);
      tmp42[0x24] = '\0';
      _applog(0,tmp42,false);
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
    builtin_strncpy(tmp42,"create mining mode thread failed\n",0x22);
    _applog(0,tmp42,false);
  }
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void equihash_miner_join(void)

{
  pthread_join(p_miner,(void **)0x0);
  return;
}




uint __bswap_32(uint __bsx)

{
  uint __bsx_local;
  
  return __bsx << 0x18 | (__bsx >> 8 & 0xff) << 0x10 | (__bsx >> 0x10 & 0xff) << 8 | __bsx >> 0x18;
}




void compressArray(uchar *in,size_t in_len,uchar *out,size_t out_len,size_t bit_len,size_t byte_pad)

{
  size_t sVar1;
  uint uVar2;
  size_t out_len_local;
  uchar *out_local;
  size_t in_len_local;
  uchar *in_local;
  uint32_t bit_len_mask;
  size_t in_width;
  size_t x;
  size_t i;
  size_t j;
  uint32_t acc_value;
  size_t acc_bits;
  
  if (bit_len < 8) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("bit_len >= 8","bm174x/equihash-verify.c",0x14,"compressArray");
  }
  if (0x20 < bit_len + 7) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("8 * sizeof(uint32_t) >= 7 + bit_len","bm174x/equihash-verify.c",0x15,"compressArray");
  }
  uVar2 = byte_pad + (bit_len + 7 >> 3);
  sVar1 = __udivsi3(in_len * bit_len,uVar2 * 8);
  if (sVar1 != out_len) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("out_len == bit_len * in_len / (8 * in_width)","bm174x/equihash-verify.c",0x18,"compressArray");
  }
  acc_bits = 0;
  acc_value = 0;
  j = 0;
  for (i = 0; i < out_len; i = i + 1) {
    if (acc_bits < 8) {
      acc_value = acc_value << (bit_len & 0xff);
      for (x = byte_pad; x < uVar2; x = x + 1) {
        acc_value = ((1 << (bit_len & 0xff)) - 1U >> (((uVar2 - x) + 0x1fffffff) * 8 & 0xff) & (uint)in[x + j]) <<
                    (((uVar2 - x) + 0x1fffffff) * 8 & 0xff) | acc_value;
      }
      j = uVar2 + j;
      acc_bits = bit_len + acc_bits;
    }
    acc_bits = acc_bits - 8;
    out[i] = (uchar)(acc_value >> (acc_bits & 0xff));
  }
  return;
}




void expandArray(uchar *in,size_t in_len,uchar *out,size_t out_len,size_t bit_len,size_t byte_pad)

{
  size_t sVar1;
  uint uVar2;
  size_t out_len_local;
  uchar *out_local;
  size_t in_len_local;
  uchar *in_local;
  uint32_t bit_len_mask;
  size_t out_width;
  size_t x_1;
  size_t x;
  size_t i;
  size_t j;
  uint32_t acc_value;
  size_t acc_bits;
  
  if (bit_len < 8) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("bit_len >= 8","bm174x/equihash-verify.c",0x3e,"expandArray");
  }
  if (0x20 < bit_len + 7) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("8 * sizeof(uint32_t) >= 7 + bit_len","bm174x/equihash-verify.c",0x3f,"expandArray");
  }
  uVar2 = byte_pad + (bit_len + 7 >> 3);
  sVar1 = __udivsi3(in_len * uVar2 * 8,bit_len);
  if (sVar1 != out_len) {
                    /* WARNING: Subroutine does not return */
    __assert_fail("out_len == 8 * out_width * in_len / bit_len","bm174x/equihash-verify.c",0x42,"expandArray");
  }
  acc_bits = 0;
  acc_value = 0;
  j = 0;
  for (i = 0; i < in_len; i = i + 1) {
    acc_value = acc_value << 8 | (uint)in[i];
    acc_bits = acc_bits + 8;
    if (bit_len <= acc_bits) {
      acc_bits = acc_bits - bit_len;
      for (x = 0; x < byte_pad; x = x + 1) {
        out[x + j] = '\0';
      }
      for (x_1 = byte_pad; x_1 < uVar2; x_1 = x_1 + 1) {
        out[x_1 + j] = (byte)((1 << (bit_len & 0xff)) - 1U >> (((uVar2 - x_1) + 0x1fffffff) * 8 & 0xff)) &
                       (byte)(acc_value >> (acc_bits + ((uVar2 - x_1) + 0x1fffffff) * 8 & 0xff));
      }
      j = uVar2 + j;
    }
  }
  return;
}




int getIndices(uint8_t *hash,size_t len,size_t lenIndices,size_t cBitLen,uint8_t *data,size_t maxLen)

{
  uint out_len;
  size_t cBitLen_local;
  size_t lenIndices_local;
  size_t len_local;
  uint8_t *hash_local;
  size_t bytePad;
  size_t minLen;
  
  if (cBitLen + 8 < 0x28) {
    out_len = lenIndices * (cBitLen + 1) >> 5;
    if (maxLen < out_len) {
      out_len = 0xffffffff;
    }
    else if (data != (uint8_t *)0x0) {
      compressArray(hash + len,lenIndices,data,out_len,cBitLen + 1,4 - (cBitLen + 8 >> 3));
    }
    return out_len;
  }
                    /* WARNING: Subroutine does not return */
  __assert_fail("((cBitLen + 1) + 7) / 8 <= sizeof(uint32_t)","bm174x/equihash-verify.c",0x6c,"getIndices");
}




int isZero(uint8_t *hash,size_t len)

{
  size_t len_local;
  uint8_t *hash_local;
  size_t i;
  
  i = 0;
  while( true ) {
    if (len <= i) {
      return 1;
    }
    if (hash[i] != '\0') break;
    i = i + 1;
  }
  return 0;
}




void generateHash(blake2b_state *S,uint32_t g,uint8_t *hash,size_t hashLen)

{
  size_t hashLen_local;
  uint8_t *hash_local;
  uint32_t g_local;
  blake2b_state *S_local;
  blake2b_state digest;
  uint32_t le_g;
  
  le_g = g;
  memcpy(&digest,S,0x168);
  blake2b_update(&digest,(uint8_t *)&le_g,4);
  blake2b_final(&digest,hash,(uint8_t)hashLen);
  return;
}




int compareSR(void *p1,void *p2)

{
  int iVar1;
  void *p2_local;
  void *p1_local;
  
  iVar1 = memcmp(p1,p2,compare_size);
  return iVar1;
}




void sort_pair(uint32_t *a,uint32_t len)

{
  bool bVar1;
  uint32_t uVar2;
  uint32_t len_local;
  uint32_t *a_local;
  uint32_t tmp;
  uint32_t *b;
  uint32_t i;
  uint32_t need_sorting;
  
  bVar1 = false;
  i = 0;
  do {
    if (len <= i) {
      return;
    }
    if ((bVar1) || (a[len + i] < a[i])) {
      bVar1 = true;
      uVar2 = a[i];
      a[i] = a[len + i];
      a[len + i] = uVar2;
    }
    else if (a[i] < a[len + i]) {
      return;
    }
    i = i + 1;
  } while( true );
}




int sortValidator(void *data,uchar *soln)

{
  uint8_t *puVar1;
  size_t bit_len;
  int iVar2;
  uint32_t uVar3;
  char *pcVar4;
  int extraout_r1;
  int extraout_r1_00;
  int iVar5;
  int iVar6;
  uint uVar7;
  blake2b_state *S;
  size_t out_len;
  int iVar8;
  int iVar9;
  uchar *soln_local;
  void *data_local;
  uint8_t tmpHash [50];
  int i_5;
  uint8_t hash_1 [30];
  uint8_t hash [30];
  uint8_t tmp_data [1344];
  uint32_t real_indices [512];
  uint8_t tmp_hash [30];
  uint8_t vHash [30];
  uint32_t indices [512];
  uint8_t *__tmp_1;
  uint8_t *__tmp;
  int i_1;
  char *hex_buff;
  int solnr;
  int equihashSolutionSize;
  int hashOutput;
  int indicesPerHashOutput;
  uint32_t hashLength;
  int collisionByteLength;
  int collisionBitLength;
  blake2b_state *digest;
  int k;
  int n;
  validData *v;
  uint32_t index_1;
  uint32_t j_4;
  int i_6;
  int j_3;
  int i_4;
  uint32_t level;
  int i_3;
  uint32_t index;
  size_t j_2;
  int i_2;
  uint32_t m;
  int j_1;
  int j;
  int i;
  uint32_t xc_size;
  uint8_t *xc;
  uint8_t *x;
  int err_type;
  uint32_t x_size;
  uint32_t indicesLen;
  
                    /* WARNING: Load size is inaccurate */
  iVar6 = *data;
  uVar7 = *(uint *)((int)data + 4);
  S = *(blake2b_state **)((int)data + 8);
  bit_len = __aeabi_idiv(iVar6,uVar7 + 1);
  iVar5 = bit_len + 0xe;
  if (-1 < (int)(bit_len + 7)) {
    iVar5 = bit_len + 7;
  }
  out_len = (iVar5 >> 3) * (uVar7 + 1);
  iVar2 = __aeabi_idiv(0x200,iVar6);
  iVar8 = iVar6 * iVar2;
  iVar5 = iVar8 + 7;
  if (-1 < iVar8) {
    iVar5 = iVar8;
  }
  iVar8 = __aeabi_idiv(iVar6,uVar7 + 1);
  iVar9 = iVar8 + 1 << (uVar7 & 0xff);
  iVar8 = iVar9 + 7;
  if (-1 < iVar9) {
    iVar8 = iVar9;
  }
  indicesLen = 4;
  x_size = 0x200;
  err_type = 0;
  compare_size = 3;
  expandArray(soln,iVar8 >> 3,(uchar *)indices,0x800,bit_len + 1,1);
  memset(vHash,0,0x1e);
  x = (uint8_t *)malloc(0x4400);
  xc = (uint8_t *)malloc(0x4400);
  memset(tmp_hash,0,0x1e);
  i = 0;
  do {
    j = i;
    if (0x1ff < i) {
      for (j_1 = 0; j_1 < 0x200; j_1 = j_1 + 1) {
        uVar7 = __bswap_32(indices[j_1]);
        uVar3 = __aeabi_idiv(uVar7,iVar2);
        generateHash(S,uVar3,tmpHash,iVar5 >> 3);
        __aeabi_idivmod(uVar7,iVar2);
        iVar9 = iVar6 * extraout_r1;
        iVar8 = iVar9 + 7;
        if (-1 < iVar9) {
          iVar8 = iVar9;
        }
        iVar9 = iVar6 + 7;
        if (-1 < iVar6) {
          iVar9 = iVar6;
        }
        expandArray(tmpHash + (iVar8 >> 3),iVar9 >> 3,hash,out_len,bit_len,0);
        for (m = 0; m < out_len; m = m + 1) {
          vHash[m] = hash[m] ^ vHash[m];
        }
        memcpy(x + j_1 * (out_len + 4),hash,out_len);
        memcpy(x + out_len + j_1 * (out_len + 4),indices + j_1,4);
      }
      iVar8 = isZero(vHash,0x1e);
      if (iVar8 == 0) {
        err_type = 2;
      }
      else {
        memset(vHash,0,0x1e);
        for (i_2 = 0; puVar1 = x, i_2 < 9; i_2 = i_2 + 1) {
          qsort(x,x_size,out_len + indicesLen,(__compar_fn_t)0x16055);
          xc_size = 0;
          for (j_2 = 0; j_2 < x_size; j_2 = j_2 + 2) {
            for (index = 0; index < out_len; index = index + 1) {
              tmp_hash[index] = x[index + (j_2 + 1) * (indicesLen + out_len)] ^ x[index + j_2 * (indicesLen + out_len)];
            }
            memcpy(xc + (j_2 >> 1) * (out_len + indicesLen * 2),tmp_hash,out_len);
            memcpy(xc + out_len + (j_2 >> 1) * (out_len + indicesLen * 2),x + out_len + j_2 * (indicesLen + out_len),
                   indicesLen);
            memcpy(xc + indicesLen + (j_2 >> 1) * (out_len + indicesLen * 2) + out_len,
                   x + out_len + (j_2 + 1) * (indicesLen + out_len),indicesLen);
            xc_size = xc_size + 1;
          }
          indicesLen = indicesLen << 1;
          x = xc;
          xc = puVar1;
          x_size = xc_size;
          compare_size = compare_size + 3;
        }
        for (i_3 = 0; i_3 < 0x200; i_3 = i_3 + 1) {
          uVar7 = __bswap_32(*(uint *)(x + out_len + i_3 * 4));
          real_indices[i_3] = uVar7;
        }
        for (level = 0; level < 9; level = level + 1) {
          for (i_4 = 0; i_4 < 0x200; i_4 = (2 << (level & 0xff)) + i_4) {
            sort_pair(real_indices + i_4,1 << (level & 0xff));
          }
        }
        indicesLen = 4;
        x_size = 0x200;
        for (j_3 = 0; j_3 < 0x200; j_3 = j_3 + 1) {
          i_5 = real_indices[j_3];
          uVar3 = __aeabi_idiv(i_5,iVar2);
          generateHash(S,uVar3,tmpHash,iVar5 >> 3);
          __aeabi_idivmod(i_5,iVar2);
          iVar9 = iVar6 * extraout_r1_00;
          iVar8 = iVar9 + 7;
          if (-1 < iVar9) {
            iVar8 = iVar9;
          }
          iVar9 = iVar6 + 7;
          if (-1 < iVar6) {
            iVar9 = iVar6;
          }
          expandArray(tmpHash + (iVar8 >> 3),iVar9 >> 3,hash_1,out_len,bit_len,0);
          i_5 = __bswap_32(real_indices[j_3]);
          memcpy(x + j_3 * (out_len + 4),hash_1,out_len);
          memcpy(x + out_len + j_3 * (out_len + 4),&i_5,4);
          pcVar4 = bin2hex(x + j_3 * (out_len + 4),0x22);
          free(pcVar4);
        }
        for (i_6 = 0; puVar1 = x, i_6 < 9; i_6 = i_6 + 1) {
          xc_size = 0;
          for (j_4 = 0; j_4 < x_size; j_4 = j_4 + 2) {
            for (index_1 = 0; index_1 < out_len; index_1 = index_1 + 1) {
              tmp_hash[index_1] =
                   x[index_1 + (j_4 + 1) * (indicesLen + out_len)] ^ x[index_1 + j_4 * (indicesLen + out_len)];
            }
            memcpy(xc + (j_4 >> 1) * (out_len + indicesLen * 2),tmp_hash,out_len);
            memcpy(xc + out_len + (j_4 >> 1) * (out_len + indicesLen * 2),x + out_len + j_4 * (indicesLen + out_len),
                   indicesLen);
            memcpy(xc + indicesLen + (j_4 >> 1) * (out_len + indicesLen * 2) + out_len,
                   x + out_len + (j_4 + 1) * (indicesLen + out_len),indicesLen);
            xc_size = xc_size + 1;
          }
          indicesLen = indicesLen << 1;
          x = xc;
          xc = puVar1;
          x_size = xc_size;
          compare_size = compare_size + 3;
        }
        getIndices(x,out_len,0x800,0x14,tmp_data,0x540);
        pcVar4 = bin2hex(tmp_data,0x540);
        free(pcVar4);
        pcVar4 = bin2hex(x,indicesLen + out_len);
        free(pcVar4);
        vHash._0_4_ = *(undefined4 *)x;
        vHash._4_4_ = *(undefined4 *)(x + 4);
        vHash._8_4_ = *(undefined4 *)(x + 8);
        vHash._12_4_ = *(undefined4 *)(x + 0xc);
        vHash._16_4_ = *(undefined4 *)(x + 0x10);
        vHash._20_4_ = *(undefined4 *)(x + 0x14);
        vHash._24_4_ = *(undefined4 *)(x + 0x18);
        vHash._28_2_ = *(undefined2 *)(x + 0x1c);
        iVar5 = isZero(vHash,0x1e);
        if (iVar5 == 0) {
          err_type = 3;
        }
      }
LAB_000170c6:
      free(x);
      free(xc);
      return err_type;
    }
    while (j = j + 1, j < 0x200) {
      if (indices[i] == indices[j]) {
        err_type = 1;
        goto LAB_000170c6;
      }
    }
    i = i + 1;
  } while( true );
}




void zcashPerson(uint8_t *person,int n,int k)

{
  int k_local;
  int n_local;
  uint8_t *person_local;
  
  memcpy(person,"ZcashPoW",8);
  *(int *)(person + 8) = n;
  *(int *)(person + 0xc) = k;
  return;
}




void digestInit(blake2b_state *S,int n,int k)

{
  int iVar1;
  int iVar2;
  int k_local;
  int n_local;
  blake2b_state *S_local;
  blake2b_param P [1];
  
  memset(P,0,0x40);
  P[0].fanout = '\x01';
  P[0].depth = '\x01';
  iVar1 = __aeabi_idiv(0x200,n);
  iVar1 = n * iVar1;
  iVar2 = iVar1 + 7;
  if (-1 < iVar1) {
    iVar2 = iVar1;
  }
  P[0].digest_length = (uint8_t)(iVar2 >> 3);
  zcashPerson(P[0].personal,n,k);
  blake2b_init_param(S,P);
  return;
}




uint32_t target_zero_cal(uint8_t *target)

{
  uchar uVar1;
  uint8_t *target_local;
  uint8_t tmphash [32];
  int j;
  int i_1;
  int i;
  uint32_t zero_num;
  
  zero_num = 0;
  memset(tmphash,0,0x20);
  for (i = 0; i < 0x20; i = i + 1) {
    tmphash[i] = target[0x1f - i];
  }
  i_1 = 0;
  do {
    if (0x1f < i_1) {
      return zero_num;
    }
    for (j = 7; -1 < j; j = j + -1) {
      uVar1 = bit_read(tmphash + i_1,j);
      if (uVar1 != '\0') {
        return zero_num;
      }
      zero_num = zero_num + 1;
    }
    i_1 = i_1 + 1;
  } while( true );
}




_Bool equihash_target_match(uchar *result_value,uchar *target)

{
  uchar *target_local;
  uchar *result_value_local;
  int i;
  
  i = 0x1f;
  while( true ) {
    if (i < 0) {
      return true;
    }
    if (result_value[i] < target[i]) break;
    if (target[i] < result_value[i]) {
      return false;
    }
    i = i + -1;
  }
  return true;
}




uint32_t targetValidator(uint8_t *work,uint8_t *nonce,uint8_t *target)

{
  uint32_t uVar1;
  uint8_t *target_local;
  uint8_t *nonce_local;
  uint8_t *work_local;
  uint8_t output [32];
  uint8_t tmphash [32];
  uint8_t input [1487];
  uint8_t str [3];
  
  memset(input,0,0x5cf);
  memset(tmphash,0,0x20);
  memset(output,0,0x20);
  memcpy(input,work,0x8c);
  input[0x8c] = 0xfd;
  input[0x8d] = '@';
  input[0x8e] = '\x05';
  memcpy(input + 0x8f,nonce,0x540);
  Sha256_Onestep(input,0x5cf,tmphash);
  Sha256_Onestep(tmphash,0x20,output);
  *(undefined4 *)target = output._0_4_;
  *(undefined4 *)(target + 4) = output._4_4_;
  *(undefined4 *)(target + 8) = output._8_4_;
  *(undefined4 *)(target + 0xc) = output._12_4_;
  *(undefined4 *)(target + 0x10) = output._16_4_;
  *(undefined4 *)(target + 0x14) = output._20_4_;
  *(undefined4 *)(target + 0x18) = output._24_4_;
  *(undefined4 *)(target + 0x1c) = output._28_4_;
  uVar1 = target_zero_cal(output);
  return uVar1;
}




int equihash_nonce_verify(nonce_verify_info_t *verify_info,int *tm,uint32_t shift)

{
  int iVar1;
  uint32_t uVar2;
  uint32_t shift_local;
  int *tm_local;
  nonce_verify_info_t *verify_info_local;
  validData valData;
  blake2b_state digest [1];
  int valid;
  
  memcpy((void *)((int)verify_info + (verify_info->work_len - shift) + -4),verify_info->nonce,verify_info->nonce_len);
  valData.n = 200;
  valData.k = 9;
  valData.digest = digest;
  digestInit(digest,200,9);
  blake2b_update(digest,verify_info->work,(longlong)verify_info->work_len);
  iVar1 = sortValidator(&valData,verify_info->sol);
  uVar2 = targetValidator(verify_info->work,verify_info->sol,verify_info->target);
  *tm = uVar2;
  return iVar1;
}




void equihash_init_algo(void *args)

{
  void *args_local;
  runtime_base_t *runtime;
  
  *(undefined4 *)((int)args + 0x69c) = 0x8c;
  *(undefined4 *)((int)args + 0x6a0) = 4;
  *(undefined4 *)((int)args + 0x6a4) = 0x540;
  *(undefined4 *)((int)args + 0x6a8) = 0x20;
  *(undefined4 *)((int)args + 0xb7c) = 0x17229;
  *(undefined4 *)((int)args + 0xb78) = 0x1737d;
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void pcba_app_manual_test(void)

{
  return;
}




/* WARNING: Unknown calling convention */

int main(void)

{
  runtime_base_t *runtime_00;
  int iVar1;
  char tmp42 [1024];
  char command [64];
  runtime_base_t *runtime;
  int ret;
  
  memset(command,0,0x40);
  app_conf = app_config_init("/mnt/card/Config.ini");
  runtime_00 = (runtime_base_t *)calloc(0xb94,1);
  env_init(runtime_00);
  if (app_conf != (app_config_t *)0x0) {
    iVar1 = cgpu_init(runtime_00);
    if (-1 < iVar1) {
      display_arguments();
      fan_control('\x02');
      do {
        memset(command,0,0x40);
        iVar1 = strcmp(app_conf->pcba_repeat_ctrl,"keyboard");
        if (iVar1 == 0) {
          ret = __isoc99_fscanf(stdin,&DAT_000349dc,command);
        }
        else {
          iVar1 = strcmp(app_conf->pcba_repeat_ctrl,"button");
          if (iVar1 != 0) {
            if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
              builtin_strncpy(tmp42,"please assign ctrl type: keyboard or button\n",0x2c);
              tmp42[0x2c] = '\0';
              _applog(2,tmp42,false);
            }
            free(runtime_00);
            app_config_exit(app_conf);
            cgpu_exit();
            return 0;
          }
          ret = v9_key_read(command,0x40);
        }
        if ((0 < ret) && (command[0] == '0')) {
          singleBoardTest_Z15_BM1746();
        }
        usleep(100000);
      } while( true );
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"cgpu init failed",0x10);
      tmp42[0x10] = '\n';
      tmp42[0x11] = '\0';
      _applog(2,tmp42,false);
    }
  }
  return -1;
}




uchar CRC5(uchar *ptr,uchar len)

{
  uchar uVar1;
  uchar uVar2;
  uchar uVar3;
  byte bVar4;
  BADSPACEBASE *unaff_sp;
  bool bVar5;
  uchar len_local;
  uchar *ptr_local;
  uchar crcout [5];
  uchar crcin [5];
  uchar din;
  uchar crc;
  uchar k;
  uchar j;
  uchar i;
  
  builtin_memcpy(crcin,"\x01\x01\x01\x01\x01",5);
  j = 0x80;
  k = '\0';
  i = '\0';
  ptr_local = ptr;
  while( true ) {
    uVar1 = crcin[0];
    uVar2 = crcin[2];
    uVar3 = crcin[3];
    if (len <= i) break;
    bVar5 = (j & *ptr_local) != 0;
    bVar4 = crcin[4] ^ crcin[1];
    j = j >> 1;
    k = k + '\x01';
    if (k == '\b') {
      j = 0x80;
      k = '\0';
      ptr_local = ptr_local + 1;
    }
    crcin[0] = bVar5 ^ crcin[4];
    crcin[1] = uVar1;
    crcin[2] = bVar5 ^ bVar4;
    crcin[3] = uVar2;
    crcin[4] = uVar3;
    i = i + '\x01';
  }
  crc = '\0';
  if (crcin[4] != '\0') {
    crc = '\x10';
  }
  if (crcin[3] != '\0') {
    crc = crc | 8;
  }
  if (crcin[2] != '\0') {
    crc = crc | 4;
  }
  if (crcin[1] != '\0') {
    crc = crc | 2;
  }
  if (crcin[0] != '\0') {
    crc = crc | 1;
  }
  return crc;
}




uint16_t CRC16(uint8_t *p_data,uint16_t w_len)

{
  uint16_t w_len_local;
  uint8_t *p_data_local;
  uint16_t wIndex;
  uint8_t chCRCLo;
  uint8_t chCRCHi;
  
  _chCRCLo = 0xffff;
  w_len_local = w_len;
  p_data_local = p_data;
  while (w_len_local != 0) {
    _chCRCLo = CONCAT11(""[(ushort)(chCRCLo ^ *p_data_local)],chCRCHi ^ ""[(ushort)(chCRCLo ^ *p_data_local)]);
    w_len_local = w_len_local - 1;
    p_data_local = p_data_local + 1;
  }
  return _chCRCLo;
}




/* WARNING: Unknown calling convention */

int bitmain_axi_init(void)

{
  char tmp42 [1024];
  uint data;
  int ret;
  
  ret = 0;
  fd_fpga = open("/dev/axi_fpga_dev",2);
  if (fd_fpga < 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"/dev/axi_fpga_dev open failed. fd = %d\n",fd_fpga);
      _applog(2,tmp42,false);
    }
    ret = -1;
  }
  else {
    axi_fpga_addr = (uint *)mmap((void *)0x0,0x1200,3,1,fd_fpga,0);
    if (axi_fpga_addr == (uint *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"mmap axi_fpga_addr failed. axi_fpga_addr = 0x%p\n",0);
        _applog(2,tmp42,false);
      }
      ret = -1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"mmap axi_fpga_addr = 0x%p\n",axi_fpga_addr);
        _applog(2,tmp42,false);
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"axi_fpga_addr data = 0x%x\n",*axi_fpga_addr & 0xffff);
        _applog(2,tmp42,false);
      }
      fd_fpga_mem = open("/dev/fpga_mem",2);
      if (fd_fpga_mem < 0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          snprintf(tmp42,0x400,"/dev/fpga_mem open failed. fd_fpga_mem = %d\n",fd_fpga_mem);
          _applog(2,tmp42,false);
        }
        ret = -1;
      }
      else {
        fpga_mem_addr = (uint *)mmap((void *)0x0,0x1000000,3,1,fd_fpga_mem,0);
        if (fpga_mem_addr == (uint *)0x0) {
          if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
            snprintf(tmp42,0x400,"mmap fpga_mem_addr failed. fpga_mem_addr = 0x%p\n",0);
            _applog(2,tmp42,false);
          }
          ret = -1;
        }
        else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          snprintf(tmp42,0x400,"mmap fpga_mem_addr = 0x%p\n",fpga_mem_addr);
          _applog(2,tmp42,false);
        }
      }
    }
  }
  return ret;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void bitmain_axi_close(void)

{
  int iVar1;
  char tmp42 [1024];
  int ret;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","bitmain_axi_close");
    _applog(2,tmp42,false);
  }
  iVar1 = munmap(axi_fpga_addr,0x1200);
  if ((iVar1 < 0) && (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    builtin_strncpy(tmp42,"munmap failed!\n",0x10);
    _applog(2,tmp42,false);
  }
  iVar1 = munmap(fpga_mem_addr,0x1000000);
  if ((iVar1 < 0) && (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    builtin_strncpy(tmp42,"munmap failed!\n",0x10);
    _applog(2,tmp42,false);
  }
  close(fd_fpga);
  close(fd_fpga_mem);
  return;
}




uint read_axi_fpga(uint address)

{
  uint address_local;
  uint data;
  
  return axi_fpga_addr[address];
}




void write_axi_fpga(uint address,uint data)

{
  uint data_local;
  uint address_local;
  
  axi_fpga_addr[address] = data;
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void init_fpga(void)

{
  uint uVar1;
  char tmp42 [1024];
  uint data;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","init_fpga");
    _applog(2,tmp42,false);
  }
  write_axi_fpga(0x20,0x80008000);
  while (uVar1 = read_axi_fpga(0x20), (int)uVar1 < 0) {
    usleep(10000);
  }
  usleep(100000);
  return;
}




void get_return_nonce(uint *buf)

{
  uint uVar1;
  uint *buf_local;
  
  uVar1 = read_axi_fpga(4);
  *buf = uVar1;
  uVar1 = read_axi_fpga(5);
  buf[1] = uVar1;
  return;
}




void set_BC_command_buffer(uint *value)

{
  uint *value_local;
  
  write_axi_fpga(0x31,*value);
  write_axi_fpga(0x32,value[1]);
  write_axi_fpga(0x33,value[2]);
  return;
}




/* WARNING: Unknown calling convention */

uint get_BC_write_command(void)

{
  uint uVar1;
  uint ret;
  
  uVar1 = read_axi_fpga(0x30);
  return uVar1;
}




void set_BC_write_command(uint value)

{
  uint uVar1;
  uint value_local;
  char tmp42 [1024];
  uchar i;
  
  i = '\0';
  if ((int)value < 0) {
    do {
      uVar1 = get_BC_write_command();
      if (-1 < (int)uVar1) goto LAB_00017ef4;
      usleep(1000);
      i = i + 1;
    } while (i < 0x65);
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: timeout\n\n","set_BC_write_command");
      _applog(2,tmp42,false);
    }
  }
LAB_00017ef4:
  write_axi_fpga(0x30,value);
  return;
}




uchar asic_baud_to_fpga_baud(uchar asic_baud)

{
  uchar uVar1;
  uchar asic_baud_local;
  char tmp42 [1024];
  
  switch(asic_baud) {
  case '\0':
    uVar1 = '\x01';
    break;
  case '\x01':
    uVar1 = '\x03';
    break;
  case '\x02':
    uVar1 = '\x05';
    break;
  default:
    if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: Don\'t support ASIC baud = %d, error!!!\n","asic_baud_to_fpga_baud",(uint)asic_baud);
      _applog(2,tmp42,false);
    }
    uVar1 = '5';
    break;
  case '\x06':
    uVar1 = '\r';
    break;
  case '\x1a':
    uVar1 = '5';
  }
  return uVar1;
}




void set_fpga_baud(uchar asic_baud)

{
  byte bVar1;
  uchar asic_baud_local;
  uchar fpga_baud;
  
  bVar1 = asic_baud_to_fpga_baud(asic_baud);
  write_axi_fpga(0xf,(uint)bVar1);
  return;
}




/* WARNING: Removing unreachable block (ram,0x00018058) */
/* WARNING: Removing unreachable block (ram,0x00018066) */
/* WARNING: Removing unreachable block (ram,0x00018074) */
/* WARNING: Removing unreachable block (ram,0x00018082) */

void i2c_write(uint config_data)

{
  uint uVar1;
  uint config_data_local;
  char tmp42 [1024];
  uint send_counter;
  
  while (uVar1 = read_axi_fpga(0xc), -1 < (int)uVar1) {
    usleep(5000);
  }
  write_axi_fpga(0xc,config_data);
  return;
}




/* WARNING: Removing unreachable block (ram,0x00018118) */
/* WARNING: Removing unreachable block (ram,0x00018126) */
/* WARNING: Removing unreachable block (ram,0x00018134) */
/* WARNING: Removing unreachable block (ram,0x00018142) */
/* WARNING: Removing unreachable block (ram,0x0001816c) */

uchar i2c_read(uint config_data)

{
  uint uVar1;
  uint config_data_local;
  char tmp42 [1024];
  uint ret_data;
  uint send_counter;
  
  i2c_write(config_data | 0x2000000);
  do {
    usleep(5000);
    uVar1 = read_axi_fpga(0xc);
  } while (-1 < (int)uVar1);
  return (uchar)uVar1;
}




int ISL_page_enable(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr,uint8_t which_page)

{
  uint8_t which_page_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  
  which_page_local = which_page;
  i2c_dev_addr_local = i2c_dev_addr;
  which_i2c_local = which_i2c;
  which_chain_local = which_chain;
  write_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\0',&which_page_local,1);
  return 0;
}




int ISL_on(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr)

{
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint8_t oper;
  
  oper = 0x80;
  which_chain_local = which_chain;
  write_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x01',&oper,1);
  return 0;
}




int ISL_off(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr)

{
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint8_t oper;
  
  oper = '@';
  which_chain_local = which_chain;
  write_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x01',&oper,1);
  return 0;
}




int ISL_set_on_off_config(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr,uint8_t config)

{
  uint8_t config_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  
  config_local = config;
  i2c_dev_addr_local = i2c_dev_addr;
  which_i2c_local = which_i2c;
  which_chain_local = which_chain;
  write_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x02',&config_local,1);
  return 0;
}




int ISL_set_clear_faults(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr)

{
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint8_t clear;
  
  clear = '\x01';
  which_chain_local = which_chain;
  write_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x03',&clear,1);
  return 0;
}




int ISL_set_write_protect(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr,uint8_t mode)

{
  uint8_t mode_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  
  mode_local = mode;
  i2c_dev_addr_local = i2c_dev_addr;
  which_i2c_local = which_i2c;
  which_chain_local = which_chain;
  write_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x10',&mode_local,1);
  return 0;
}




int ISL_set_vout_command(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr,uint16_t voltage)

{
  uint16_t voltage_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint8_t cmd [2];
  
  which_chain_local = which_chain;
  cmd = (uint8_t  [2])voltage;
  printf("uint16 = 0x%04x[%u], cmd0=%02x cmd1=%02x\n",(uint)voltage,(uint)voltage,(uint)(byte)voltage,
         (uint)(byte)(voltage >> 8));
  write_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'!',cmd,2);
  return 0;
}




int ISL_set_apply_settings(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr)

{
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint8_t apply;
  
  apply = '\x01';
  which_chain_local = which_chain;
  write_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,0xe7,&apply,1);
  return 0;
}




int ISL_get_voltage(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr,uint16_t *voltage)

{
  uint16_t *voltage_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint8_t vol [2];
  
  which_chain_local = which_chain;
  memset(vol,0,2);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'!',vol,2);
  *voltage = (uint16_t)vol;
  return 0;
}




int ISL_read_reg_default(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr)

{
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint8_t value [2];
  
  value[0] = '\0';
  value[1] = '\0';
  which_chain_local = which_chain;
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\0',value,1);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x01',value,1);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x02',value,1);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x03',value,1);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\x10',value,1);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'!',value,2);
  read_dc_dc(&which_chain_local,which_i2c,i2c_dev_addr,'\"',value,1);
  return 0;
}




uint16_t ISL_set_voltage(uint8_t which_chain,uint8_t which_i2c,uint8_t i2c_dev_addr,uint16_t voltage)

{
  uint16_t voltage_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  uint8_t which_chain_local;
  uint16_t r_voltage;
  uint8_t retry_limits;
  uint8_t retry;
  
  puts("begin to read voltage");
  ISL_page_enable(which_chain,which_i2c,i2c_dev_addr,'\0');
  usleep(100000);
  usleep(100000);
  ISL_set_vout_command(which_chain,which_i2c,i2c_dev_addr,voltage);
  usleep(100000);
  usleep(100000);
  puts("end to read voltage");
  retry = '\0';
  retry_limits = '\x05';
  r_voltage = 0;
  do {
    usleep(100000);
    ISL_get_voltage(which_chain,which_i2c,i2c_dev_addr,&r_voltage);
    retry = retry + 1;
    if (retry_limits < retry) break;
  } while (r_voltage == 0);
  printf("--- ISL_get_voltage, Voltage: 0.%03d V\n\n",(uint)r_voltage);
  return r_voltage;
}




/* WARNING: Unknown calling convention */

int open_key(void)

{
  char tmp42 [1024];
  
  cgpu.key_fd = open("/sys/class/gpio/gpio943/value",0x800);
  if ((cgpu.key_fd < 0) && (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    builtin_strncpy(tmp42,"open key failed!!!\n",0x14);
    _applog(2,tmp42,false);
  }
  return cgpu.key_fd;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void close_key(void)

{
  char tmp42 [1024];
  
  close(cgpu.key_fd);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"key closed!!",0xc);
    tmp42[0xc] = '!';
    tmp42[0xd] = '\n';
    tmp42[0xe] = '\0';
    _applog(2,tmp42,false);
  }
  return;
}




ssize_t read_key(uchar value)

{
  ssize_t sVar1;
  ssize_t sVar2;
  uchar value_local;
  char tmp42 [1024];
  ssize_t ret_len;
  
  value_local = value;
  lseek(cgpu.key_fd,0,0);
  sVar1 = read(cgpu.key_fd,&value_local,1);
  if (sVar1 == 1) {
    sVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: can\'t read out key value\n","read_key");
      _applog(2,tmp42,false);
    }
    sVar2 = -1;
  }
  return sVar2;
}




/* WARNING: Unknown calling convention */

int open_lcd(void)

{
  char tmp42 [1024];
  
  cgpu.lcd_fd = open("/dev/bitmain-lcd",0x882);
  if ((cgpu.lcd_fd < 1) && (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    builtin_strncpy(tmp42,"open lcd failed!!!\n",0x14);
    _applog(2,tmp42,false);
  }
  return cgpu.lcd_fd;
}




/* WARNING: Unknown calling convention */

int close_lcd(void)

{
  int iVar1;
  char tmp42 [1024];
  int ret;
  
  iVar1 = close(cgpu.lcd_fd);
  if (iVar1 == 0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"lcd closed!!",0xc);
      tmp42[0xc] = '!';
      tmp42[0xd] = '\n';
      tmp42[0xe] = '\0';
      _applog(2,tmp42,false);
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"lcd close failed!!!\n",0x14);
    tmp42[0x14] = '\0';
    _applog(2,tmp42,false);
  }
  return iVar1;
}




void write_lcd(uint line,char *buf,uint size)

{
  uint size_local;
  char *buf_local;
  uint line_local;
  char tmp42 [1024];
  uint Copied;
  
  Copied = 0;
  if ((buf != (char *)0x0) && (0 < cgpu.lcd_fd)) {
    if ((line < 4) && (size < 0x41)) {
      lseek(cgpu.lcd_fd,0,0);
      memset(lcd_output,0x20,0x40);
      line_local = line;
      for (size_local = size; size_local != 0; size_local = size_local - 0x10) {
        if (size_local < 0x11) {
          memcpy(lcd_output + line_local,buf + Copied,size_local);
          break;
        }
        memcpy(lcd_output + line_local,buf + Copied,0x10);
        Copied = Copied + 0x10;
        line_local = line_local + 1;
      }
      write(cgpu.lcd_fd,lcd_output,0x40);
    }
    else if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: write_lcd\'s arg is overflow\n","write_lcd");
      _applog(2,tmp42,false);
    }
  }
  return;
}




void write_lcd_no_memset(uint line,char *buf,uint size)

{
  uint size_local;
  char *buf_local;
  uint line_local;
  char tmp42 [1024];
  uint Copied;
  
  Copied = 0;
  if ((buf != (char *)0x0) && (0 < cgpu.lcd_fd)) {
    if ((line < 4) && (size_local = size, line_local = line, size < 0x41)) {
      for (; size_local != 0; size_local = size_local - 0x10) {
        if (size_local < 0x11) {
          memcpy(lcd_output + line_local,buf + Copied,size_local);
          break;
        }
        memcpy(lcd_output + line_local,buf + Copied,0x10);
        Copied = Copied + 0x10;
        line_local = line_local + 1;
      }
      write(cgpu.lcd_fd,lcd_output,0x40);
    }
    else if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: write_lcd\'s arg is overflow\n","write_lcd_no_memset");
      _applog(2,tmp42,false);
    }
  }
  return;
}




/* WARNING: Unknown calling convention */

int open_red_led(void)

{
  char tmp42 [1024];
  
  red_led_fd = open("/sys/class/gpio/gpio941/value",0x801);
  if ((red_led_fd < 0) && (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    builtin_strncpy(tmp42,"open red led failed!!!\n",0x18);
    _applog(2,tmp42,false);
  }
  return red_led_fd;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void close_red_led(void)

{
  char tmp42 [1024];
  
  close(red_led_fd);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"red led closed!!",0x10);
    tmp42[0x10] = '!';
    tmp42[0x11] = '\n';
    tmp42[0x12] = '\0';
    _applog(2,tmp42,false);
  }
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void red_led_on(void)

{
  write(red_led_fd,&DAT_00035004,1);
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void red_led_off(void)

{
  write(red_led_fd,&DAT_00035008,1);
  return;
}




/* WARNING: Unknown calling convention */

int open_green_led(void)

{
  char tmp42 [1024];
  
  green_led_fd = open("/sys/class/gpio/gpio942/value",0x801);
  if ((green_led_fd < 0) && (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    builtin_strncpy(tmp42,"open green led failed!!!",0x18);
    tmp42[0x18] = '\n';
    tmp42[0x19] = '\0';
    _applog(2,tmp42,false);
  }
  return green_led_fd;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void close_green_led(void)

{
  char tmp42 [1024];
  
  close(green_led_fd);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"green led closed!!!\n",0x14);
    tmp42[0x14] = '\0';
    _applog(2,tmp42,false);
  }
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void green_led_on(void)

{
  write(green_led_fd,&DAT_00035004,1);
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void green_led_off(void)

{
  write(green_led_fd,&DAT_00035008,1);
  return;
}




void write_pic(uchar which_i2c,uchar which_chain,uchar data)

{
  uchar data_local;
  uchar which_chain_local;
  uchar which_i2c_local;
  uint config_data;
  
  i2c_write((uint)data | (uint)which_i2c << 0x1a | 0xa00000 | (uint)which_chain << 0x10);
  return;
}




uchar read_pic(uchar which_i2c,uchar which_chain)

{
  uchar uVar1;
  uchar which_chain_local;
  uchar which_i2c_local;
  uint config_data;
  
  uVar1 = i2c_read((uint)which_chain << 0x10 | (uint)which_i2c << 0x1a | 0xa00000);
  return uVar1;
}




int write_dc_dc(void *args,uint8_t which_i2c,uint8_t i2c_dev_addr,uint8_t reg,uint8_t *data,int len)

{
  uchar which_chain_00;
  byte bVar1;
  uchar uVar2;
  int iVar3;
  uint8_t reg_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  void *args_local;
  uint8_t send_data [16];
  uint8_t read_back_data [16];
  uint8_t crc_data [2];
  uint8_t length;
  uint8_t which_chain;
  int j;
  int i_1;
  uint8_t i;
  uint16_t crc;
  
                    /* WARNING: Load size is inaccurate */
  which_chain_00 = *args;
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  read_back_data[8] = '\0';
  read_back_data[9] = '\0';
  read_back_data[10] = '\0';
  read_back_data[0xb] = '\0';
  read_back_data[0xc] = '\0';
  read_back_data[0xd] = '\0';
  read_back_data[0xe] = '\0';
  read_back_data[0xf] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  crc = 0;
  send_data[0] = '\0';
  send_data[1] = '\0';
  send_data[2] = '\0';
  send_data[3] = '\0';
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[0xb] = '\0';
  send_data[0xc] = '\0';
  send_data[0xd] = '\0';
  send_data[0xe] = '\0';
  send_data[0xf] = '\0';
  bVar1 = (char)len + 6;
  printf("%s dev addr = %02x\n","write_dc_dc",(uint)i2c_dev_addr);
  send_data[2] = bVar1;
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '2';
  send_data[5] = reg;
  send_data[4] = i2c_dev_addr << 1;
  for (i_1 = 0; i_1 < len; i_1 = i_1 + 1) {
    send_data[i_1 + 6] = data[i_1];
  }
  for (j = 2; j < len + 6; j = j + 1) {
    crc = crc + send_data[j];
  }
  send_data[len + 6] = (uint8_t)(crc >> 8);
  send_data[len + 7] = (uint8_t)crc;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; (uint)i < bVar1 + 2; i = i + '\x01') {
    write_pic(which_i2c,which_chain_00,send_data[i]);
  }
  usleep(100000);
  memset(read_back_data,0,0x10);
  for (i = '\0'; i < 5; i = i + '\x01') {
    uVar2 = read_pic(which_i2c,which_chain_00);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((read_back_data[1] == '2') && (read_back_data[2] == '\x01')) {
    iVar3 = 0;
  }
  else {
    printf("--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_data[3] = 0x%02x\n\n"
           ,"write_dc_dc",read_back_data._0_4_ & 0xff,(uint)read_back_data[1],(uint)read_back_data[2],
           (uint)read_back_data._0_4_ >> 0x18);
    iVar3 = -1;
  }
  return iVar3;
}




int read_dc_dc(void *args,uint8_t which_i2c,uint8_t i2c_dev_addr,uint8_t reg,uint8_t *value,int len)

{
  uchar which_chain_00;
  uint3 uVar1;
  uchar uVar2;
  int iVar3;
  uint8_t reg_local;
  uint8_t i2c_dev_addr_local;
  uint8_t which_i2c_local;
  void *args_local;
  uint8_t send_data [9];
  uint8_t read_back_data [16];
  uint8_t crc_data [2];
  uint8_t length;
  uint8_t which_chain;
  int i_2;
  int i_1;
  uint8_t i;
  uint16_t crc;
  
                    /* WARNING: Load size is inaccurate */
  which_chain_00 = *args;
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  read_back_data[8] = '\0';
  read_back_data[9] = '\0';
  read_back_data[10] = '\0';
  read_back_data[0xb] = '\0';
  read_back_data[0xc] = '\0';
  read_back_data[0xd] = '\0';
  read_back_data[0xe] = '\0';
  read_back_data[0xf] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  crc = 0;
  send_data[8] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\a';
  send_data[3] = '2';
  uVar1 = CONCAT12((char)len,CONCAT11(reg,i2c_dev_addr << 1));
  send_data._4_3_ = uVar1 | 1;
  send_data[7] = '\0';
  for (i_1 = 2; i_1 < 7; i_1 = i_1 + 1) {
    crc = crc + send_data[i_1];
  }
  send_data[8] = (uint8_t)crc;
  send_data._4_4_ = CONCAT13((char)(crc >> 8),uVar1) | 1;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 9; i = i + '\x01') {
    write_pic(which_i2c,which_chain_00,send_data[i]);
  }
  usleep(100000);
  memset(read_back_data,0,0x10);
  for (i = '\0'; (int)(uint)i < len + 5; i = i + '\x01') {
    uVar2 = read_pic(which_i2c,which_chain_00);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(1000000);
  if ((read_back_data[1] == '2') && (read_back_data[2] == '\x01')) {
    for (i_2 = 0; i_2 < len; i_2 = i_2 + 1) {
      value[i_2] = read_back_data[i_2 + 3];
    }
    iVar3 = 0;
  }
  else {
    printf("--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_data[3] = 0x%02x\n"
           ,"read_dc_dc",read_back_data._0_4_ & 0xff,(uint)read_back_data[1],(uint)read_back_data[2],
           (uint)read_back_data._0_4_ >> 0x18);
    iVar3 = -1;
  }
  return iVar3;
}




int set_PIC16F1704_flash_pointer(uint which_i2c,uchar which_chain,uchar flash_addr_h,uchar flash_addr_l)

{
  short sVar1;
  uchar uVar2;
  int iVar3;
  uchar flash_addr_l_local;
  uchar flash_addr_h_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [8];
  uchar read_back_data [2];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  sVar1 = (ushort)flash_addr_l + (ushort)flash_addr_h + 7;
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x06';
  send_data[3] = '\x01';
  send_data[5] = flash_addr_l;
  send_data[4] = flash_addr_h;
  send_data[6] = (uchar)((ushort)sVar1 >> 8);
  send_data[7] = (uchar)sVar1;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 8; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(100000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((read_back_data[0] == '\x01') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","set_PIC16F1704_flash_pointer");
      _applog(2,tmp42,false);
    }
    iVar3 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "set_PIC16F1704_flash_pointer",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}




int send_data_to_PIC16F1704(uint which_i2c,uchar which_chain,uchar *buf)

{
  uchar uVar1;
  int iVar2;
  uchar *buf_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [22];
  uchar read_back_data [2];
  uchar crc_data [2];
  uchar length;
  uchar i;
  ushort crc;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[0xb] = '\0';
  send_data[0xc] = '\0';
  send_data[0xd] = '\0';
  send_data[0xe] = '\0';
  send_data[0xf] = '\0';
  send_data[0x10] = '\0';
  send_data[0x11] = '\0';
  send_data[0x12] = '\0';
  send_data[0x13] = '\0';
  crc = 0x16;
  for (i = '\0'; i < 0x10; i = i + '\x01') {
    crc = crc + buf[i];
  }
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x14';
  send_data[3] = '\x02';
  for (i = '\0'; i < 0x10; i = i + '\x01') {
    send_data[i + 4] = buf[i];
  }
  send_data[0x15] = (uchar)crc;
  send_data[0x14] = (uchar)(crc >> 8);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 0x16; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(100000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar1 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((read_back_data[0] == '\x02') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","send_data_to_PIC16F1704");
      _applog(2,tmp42,false);
    }
    iVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "send_data_to_PIC16F1704",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  return iVar2;
}




int read_PIC16F1704_flash_pointer(uint which_i2c,uchar which_chain,uchar *flash_addr_h,uchar *flash_addr_l)

{
  short sVar1;
  uchar uVar2;
  int iVar3;
  uchar *flash_addr_l_local;
  uchar *flash_addr_h_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [6];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\b';
  send_data[4] = '\0';
  send_data[5] = '\f';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(100000);
  for (i = '\0'; i < 6; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((read_back_data[1] == '\b') && (read_back_data[0] == '\x06')) {
    sVar1 = (ushort)read_back_data[3] + read_back_data[2] + 0xe;
    if (((uchar)((ushort)sVar1 >> 8) == read_back_data[4]) && ((uchar)sVar1 == read_back_data[5])) {
      *flash_addr_h = read_back_data[2];
      *flash_addr_l = read_back_data[3];
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s ok! flash_addr_h = 0x%02x, flash_addr_l = 0x%02x\n\n",
                 "read_PIC16F1704_flash_pointer",(uint)*flash_addr_h,(uint)*flash_addr_l);
        _applog(2,tmp42,false);
      }
      iVar3 = 1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,
                 "--- %s failed! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n\n"
                 ,"read_PIC16F1704_flash_pointer",read_back_data._0_4_ & 0xff,8,(uint)read_back_data[2],
                 (uint)read_back_data[3],(uint)read_back_data[4],(uint)read_back_data[5]);
        _applog(2,tmp42,false);
      }
      iVar3 = 0;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,
               "--- %s failed! read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n\n"
               ,"read_PIC16F1704_flash_pointer",read_back_data._0_4_ & 0xff,(uint)read_back_data[1],
               (uint)read_back_data[2],(uint)read_back_data[3],(uint)read_back_data[4],(uint)read_back_data[5]);
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}




int read_PIC16F1704_flash_data(uint which_i2c,uchar which_chain,uchar *buf)

{
  ushort uVar1;
  uchar uVar2;
  int iVar3;
  uchar *buf_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [20];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  read_back_data[8] = '\0';
  read_back_data[9] = '\0';
  read_back_data[10] = '\0';
  read_back_data[0xb] = '\0';
  read_back_data[0xc] = '\0';
  read_back_data[0xd] = '\0';
  read_back_data[0xe] = '\0';
  read_back_data[0xf] = '\0';
  read_back_data[0x10] = '\0';
  read_back_data[0x11] = '\0';
  read_back_data[0x12] = '\0';
  read_back_data[0x13] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\x03';
  send_data[4] = '\0';
  send_data[5] = '\a';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(300000);
  for (i = '\0'; i < 0x14; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,
             "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, \t\tread_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x, \t\tread_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x, \t\tread_back_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x, \t\tread_back_data[16] = 0x%x, read_back_data[17] = 0x%x, read_back_data[18] = 0x%x, read_back_data[19] = 0x%x\n"
             ,"read_PIC16F1704_flash_data",read_back_data._0_4_ & 0xff,(uint)read_back_data._0_4_ >> 8 & 0xff,
             (uint)read_back_data._0_4_ >> 0x10 & 0xff,(uint)read_back_data._0_4_ >> 0x18,read_back_data._4_4_ & 0xff,
             (uint)read_back_data._4_4_ >> 8 & 0xff,(uint)read_back_data._4_4_ >> 0x10 & 0xff,
             (uint)read_back_data._4_4_ >> 0x18,read_back_data._8_4_ & 0xff,(uint)read_back_data._8_4_ >> 8 & 0xff,
             (uint)read_back_data._8_4_ >> 0x10 & 0xff,(uint)read_back_data._8_4_ >> 0x18,read_back_data._12_4_ & 0xff,
             (uint)read_back_data._12_4_ >> 8 & 0xff,(uint)read_back_data._12_4_ >> 0x10 & 0xff,
             (uint)read_back_data._12_4_ >> 0x18,read_back_data._16_4_ & 0xff,(uint)read_back_data._16_4_ >> 8 & 0xff,
             (uint)read_back_data._16_4_ >> 0x10 & 0xff,(uint)read_back_data._16_4_ >> 0x18);
    _applog(2,tmp42,false);
  }
  usleep(100000);
  if ((read_back_data[1] == '\x03') && (read_back_data[0] == '\x14')) {
    uVar1 = (ushort)read_back_data[0x11] +
            (ushort)read_back_data[0x10] +
            (ushort)read_back_data[0xf] +
            (ushort)read_back_data[0xe] +
            (ushort)read_back_data[0xd] +
            (ushort)read_back_data[0xc] +
            (ushort)read_back_data[0xb] +
            (ushort)read_back_data[10] +
            (ushort)read_back_data[9] +
            (ushort)read_back_data[8] +
            (ushort)read_back_data[7] +
            (ushort)read_back_data[6] +
            (ushort)read_back_data[5] + (ushort)read_back_data[4] + (ushort)read_back_data[3] + read_back_data[2] + 0x17
    ;
    if (((uchar)(uVar1 >> 8) == read_back_data[0x12]) && ((uchar)uVar1 == read_back_data[0x13])) {
      for (i = '\0'; i < 0x10; i = i + '\x01') {
        buf[i] = read_back_data[i + 2];
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s ok\n\n","read_PIC16F1704_flash_data");
        _applog(2,tmp42,false);
      }
      iVar3 = 1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s failed! crc = 0x%04x\n\n","read_PIC16F1704_flash_data",(uint)uVar1);
        _applog(2,tmp42,false);
      }
      iVar3 = 0;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed!\n\n","read_PIC16F1704_flash_data");
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}




int erase_PIC16F1704_flash(uint which_i2c,uchar which_chain)

{
  uchar uVar1;
  int iVar2;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [2];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\x04';
  send_data[4] = '\0';
  send_data[5] = '\b';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(100000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar1 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[0] == '\x04') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","erase_PIC16F1704_flash");
      _applog(2,tmp42,false);
    }
    iVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "erase_PIC16F1704_flash",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  return iVar2;
}




int write_data_into_PIC16F1704_flash(uint which_i2c,uchar which_chain)

{
  uchar uVar1;
  int iVar2;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [2];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\x05';
  send_data[4] = '\0';
  send_data[5] = '\t';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar1 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[0] == '\x05') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","write_data_into_PIC16F1704_flash");
      _applog(2,tmp42,false);
    }
    iVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "write_data_into_PIC16F1704_flash",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  return iVar2;
}




int jump_from_loader_to_app_PIC16F1704(uint which_chain,uchar which_i2c)

{
  uchar uVar1;
  int iVar2;
  uchar which_i2c_local;
  uint which_chain_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [2];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\x06';
  send_data[4] = '\0';
  send_data[5] = '\n';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic(which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(100000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar1 = read_pic(which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(300000);
  if ((read_back_data[0] == '\x06') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","jump_from_loader_to_app_PIC16F1704");
      _applog(2,tmp42,false);
    }
    iVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "jump_from_loader_to_app_PIC16F1704",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  return iVar2;
}




int reset_PIC16F1704_pic(uint which_chain,uchar which_i2c)

{
  uchar uVar1;
  int iVar2;
  uchar which_i2c_local;
  uint which_chain_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [2];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\a';
  send_data[4] = '\0';
  send_data[5] = '\v';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic(which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(100000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar1 = read_pic(which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(1000000);
  if ((read_back_data[0] == '\a') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","reset_PIC16F1704_pic");
      _applog(2,tmp42,false);
    }
    iVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "reset_PIC16F1704_pic",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  return iVar2;
}




int set_PIC16F1704_voltage(uint which_chain,uchar which_i2c,uchar voltage)

{
  uchar uVar1;
  int iVar2;
  uchar voltage_local;
  uchar which_i2c_local;
  uint which_chain_local;
  char tmp42 [1024];
  uchar send_data [7];
  uchar read_back_data [2];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  send_data[5] = (uchar)((ushort)(voltage + 0x15) >> 8);
  send_data[6] = (uchar)(voltage + 0x15);
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x05';
  send_data[3] = '\x10';
  send_data[4] = voltage;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 7; i = i + '\x01') {
    write_pic(which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar1 = read_pic(which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[0] == '\x10') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","set_PIC16F1704_voltage");
      _applog(2,tmp42,false);
    }
    iVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "set_PIC16F1704_voltage",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  return iVar2;
}




int write_hash_ID_PIC16F1704(uint which_chain,uchar which_i2c,uchar *buf)

{
  uchar uVar1;
  int iVar2;
  uchar *buf_local;
  uchar which_i2c_local;
  uint which_chain_local;
  char tmp42 [1024];
  uchar send_data [18];
  uchar read_back_data [2];
  uchar crc_data [2];
  uchar length;
  uchar i;
  ushort crc;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[0xb] = '\0';
  send_data[0xc] = '\0';
  send_data[0xd] = '\0';
  send_data[0xe] = '\0';
  send_data[0xf] = '\0';
  crc = 0x22;
  for (i = '\0'; i < 0xc; i = i + '\x01') {
    crc = crc + buf[i];
  }
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x10';
  send_data[3] = '\x12';
  for (i = '\0'; i < 0xc; i = i + '\x01') {
    send_data[i + 4] = buf[i];
  }
  send_data[0x11] = (uchar)crc;
  send_data[0x10] = (uchar)(crc >> 8);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 0x12; i = i + '\x01') {
    write_pic(which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(400000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar1 = read_pic(which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[0] == '\x12') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","write_hash_ID_PIC16F1704");
      _applog(2,tmp42,false);
    }
    iVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "write_hash_ID_PIC16F1704",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  return iVar2;
}




int read_hash_id_PIC16F1704(uint which_i2c,uchar which_chain,uchar *buf)

{
  ushort uVar1;
  uchar uVar2;
  int iVar3;
  uchar *buf_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [16];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  read_back_data[8] = '\0';
  read_back_data[9] = '\0';
  read_back_data[10] = '\0';
  read_back_data[0xb] = '\0';
  read_back_data[0xc] = '\0';
  read_back_data[0xd] = '\0';
  read_back_data[0xe] = '\0';
  read_back_data[0xf] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\x13';
  send_data[4] = '\0';
  send_data[5] = '\x17';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; i < 0x10; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,
             "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x,\t\tread_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x,\t\tread_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x,\t\tread_back_data[12] = 0x%x, read_back_data[13] = 0x%x, read_back_data[14] = 0x%x, read_back_data[15] = 0x%x\n"
             ,"read_hash_id_PIC16F1704",read_back_data._0_4_ & 0xff,(uint)read_back_data._0_4_ >> 8 & 0xff,
             (uint)read_back_data._0_4_ >> 0x10 & 0xff,(uint)read_back_data._0_4_ >> 0x18,read_back_data._4_4_ & 0xff,
             (uint)read_back_data._4_4_ >> 8 & 0xff,(uint)read_back_data._4_4_ >> 0x10 & 0xff,
             (uint)read_back_data._4_4_ >> 0x18,read_back_data._8_4_ & 0xff,(uint)read_back_data._8_4_ >> 8 & 0xff,
             (uint)read_back_data._8_4_ >> 0x10 & 0xff,(uint)read_back_data._8_4_ >> 0x18,read_back_data._12_4_ & 0xff,
             (uint)read_back_data._12_4_ >> 8 & 0xff,(uint)read_back_data._12_4_ >> 0x10 & 0xff,
             (uint)read_back_data._12_4_ >> 0x18);
    _applog(2,tmp42,false);
  }
  if ((read_back_data[1] == '\x13') && (read_back_data[0] == '\x10')) {
    uVar1 = (ushort)read_back_data[0xd] +
            (ushort)read_back_data[0xc] +
            (ushort)read_back_data[0xb] +
            (ushort)read_back_data[10] +
            (ushort)read_back_data[9] +
            (ushort)read_back_data[8] +
            (ushort)read_back_data[7] +
            (ushort)read_back_data[6] +
            (ushort)read_back_data[5] + (ushort)read_back_data[4] + (ushort)read_back_data[3] + read_back_data[2] + 0x23
    ;
    if (((uchar)(uVar1 >> 8) == read_back_data[0xe]) && ((uchar)uVar1 == read_back_data[0xf])) {
      for (i = '\0'; i < 0xc; i = i + '\x01') {
        buf[i] = read_back_data[i + 2];
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s ok\n\n","read_hash_id_PIC16F1704");
        _applog(2,tmp42,false);
      }
      iVar3 = 1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s failed! crc = 0x%04x\n\n","read_hash_id_PIC16F1704",(uint)uVar1);
        _applog(2,tmp42,false);
      }
      iVar3 = 0;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed!\n\n","read_hash_id_PIC16F1704");
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}




int enable_PIC16F1704_dc_dc(uint which_chain,uchar which_i2c,uchar enable)

{
  uchar uVar1;
  int iVar2;
  uchar enable_local;
  uchar which_i2c_local;
  uint which_chain_local;
  char tmp42 [1024];
  uchar send_data [7];
  uchar read_back_data [2];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  send_data[5] = (uchar)((ushort)(enable + 0x1a) >> 8);
  send_data[6] = (uchar)(enable + 0x1a);
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x05';
  send_data[3] = '\x15';
  send_data[4] = enable;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 7; i = i + '\x01') {
    write_pic(which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(100000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar1 = read_pic(which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((read_back_data[0] == '\x15') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","enable_PIC16F1704_dc_dc");
      _applog(2,tmp42,false);
    }
    usleep(500000);
    iVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "enable_PIC16F1704_dc_dc",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  return iVar2;
}




int heart_beat_PIC16F1704(uint which_chain,uchar which_i2c)

{
  uchar uVar1;
  int iVar2;
  uchar which_i2c_local;
  uint which_chain_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [6];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\x16';
  send_data[4] = '\0';
  send_data[5] = '\x1a';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic(which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(100000);
  for (i = '\0'; i < 6; i = i + '\x01') {
    uVar1 = read_pic(which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if ((read_back_data[1] == '\x16') && (read_back_data[2] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","heart_beat_PIC16F1704");
      _applog(2,tmp42,false);
    }
    iVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed!\n\n","heart_beat_PIC16F1704");
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  return iVar2;
}




void * pic_heart_beat_func(void *arg)

{
  byte bVar1;
  uchar which_i2c_00;
  void *arg_local;
  uchar which_i2c;
  uchar which_chain;
  chain_info *chain_i;
  
                    /* WARNING: Load size is inaccurate */
  bVar1 = *arg;
  which_i2c_00 = *(uchar *)((int)arg + 1);
  do {
    heart_beat_PIC16F1704((uint)bVar1,which_i2c_00);
    sleep(10);
  } while( true );
}




int get_PIC16F1704_software_version(uint which_i2c,uchar which_chain,uchar *version)

{
  ushort uVar1;
  uchar uVar2;
  int iVar3;
  uchar *version_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [5];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[4] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\x17';
  send_data[4] = '\0';
  send_data[5] = '\x1b';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; i < 5; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,
             "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x\n"
             ,"get_PIC16F1704_software_version",read_back_data._0_4_ & 0xff,(uint)read_back_data._0_4_ >> 8 & 0xff,
             (uint)read_back_data._0_4_ >> 0x10 & 0xff,(uint)read_back_data._0_4_ >> 0x18,(uint)read_back_data[4]);
    _applog(2,tmp42,false);
  }
  if ((read_back_data[1] == '\x17') && (read_back_data[0] == '\x05')) {
    uVar1 = read_back_data[2] + 0x1c;
    if (((uchar)(uVar1 >> 8) == read_back_data[3]) && ((uchar)uVar1 == read_back_data[4])) {
      *version = read_back_data[2];
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s ok, version = 0x%02x\n\n","get_PIC16F1704_software_version",(uint)*version);
        _applog(2,tmp42,false);
      }
      iVar3 = 1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s failed! crc = 0x%04x\n\n","get_PIC16F1704_software_version",(uint)uVar1);
        _applog(2,tmp42,false);
      }
      iVar3 = 0;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed!\n\n","get_PIC16F1704_software_version");
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}




int PIC16F1704_i2c_forward_send
              (uint32_t i2c,uint8_t chain,uint8_t dev_addr,int rw_flag,uint8_t reg_addr,int len,uint8_t *data)

{
  uchar uVar1;
  int rw_flag_local;
  uint8_t dev_addr_local;
  uint8_t chain_local;
  uint32_t i2c_local;
  char tmp42 [1024];
  uint8_t recv_data [12];
  uint8_t send_data [32];
  int i_2;
  int i_1;
  int i;
  int body_len;
  uint16_t crc;
  
  memset(send_data,0,0x20);
  recv_data[0] = '\0';
  recv_data[1] = '\0';
  recv_data[2] = '\0';
  recv_data[3] = '\0';
  recv_data[4] = '\0';
  recv_data[5] = '\0';
  recv_data[6] = '\0';
  recv_data[7] = '\0';
  recv_data[8] = '\0';
  recv_data[9] = '\0';
  recv_data[10] = '\0';
  recv_data[0xb] = '\0';
  crc = 0;
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\0';
  send_data[3] = '&';
  send_data[4] = (byte)rw_flag | dev_addr << 1;
  send_data[5] = reg_addr;
  if (rw_flag == 0) {
    body_len = len + 4;
    memcpy(send_data + 6,data,len);
  }
  else {
    body_len = 5;
    send_data[6] = (uint8_t)len;
  }
  send_data[2] = (char)body_len + '\x02';
  for (i_1 = 0; i_1 < body_len; i_1 = i_1 + 1) {
    crc = crc + send_data[i_1 + 2];
  }
  send_data[body_len + 2] = (uint8_t)(crc >> 8);
  send_data[body_len + 3] = (uint8_t)crc;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = 0; i < body_len + 4; i = i + 1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"write pic i2c[%d] %02x\n",i,(uint)send_data[i]);
      _applog(2,tmp42,false);
    }
    write_pic((uchar)i2c,chain,send_data[i]);
  }
  usleep(200000);
  if (rw_flag == 1) {
    for (i = 0; i < len + 5; i = i + 1) {
      uVar1 = read_pic((uchar)i2c,chain);
      recv_data[i] = uVar1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"read pic i2c[%d] %02x\n",i,(uint)recv_data[i]);
        _applog(2,tmp42,false);
      }
    }
    for (i_2 = 0; i_2 < len + 3; i_2 = i_2 + 1) {
      crc = crc + recv_data[i_2];
    }
    if (crc != *(uint16_t *)(recv_data + len + 3)) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"crc failed 0x%x\n",(uint)crc);
        _applog(2,tmp42,false);
      }
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      return -1;
    }
    if ((((recv_data._0_4_ & 0xff) != body_len + 2U) || (recv_data[1] != '&')) || (recv_data[2] != '\x01')) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"pic read failed %d %d %d\n",(uint)*data,(uint)data[1],(uint)data[2]);
        _applog(2,tmp42,false);
      }
      pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
      return -1;
    }
    memcpy(data,recv_data + 3,len);
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  return 0;
}




void set_PIC16F1704_voltage_z9(uint32_t i2c,uint8_t chain,uint16_t vol)

{
  uint16_t vol_local;
  uint8_t chain_local;
  uint32_t i2c_local;
  size_t i;
  
  vol_local = vol;
  chain_local = chain;
  i2c_local = i2c;
  for (i = 0; i < 4; i = i + 1) {
    PIC16F1704_i2c_forward_send(i2c_local,chain_local,"PQTU"[i],0,'\0',1,(uint8_t *)0x0);
    PIC16F1704_i2c_forward_send(i2c_local,chain_local,"PQTU"[i],0,'!',2,(uint8_t *)&vol_local);
  }
  return;
}




void get_PIC16F1704_voltage_z9(uint32_t i2c,uint8_t chain)

{
  int iVar1;
  uint8_t chain_local;
  uint32_t i2c_local;
  char tmp42 [1024];
  uint8_t read_vol [12];
  int ret;
  size_t i;
  
  for (i = 0; i < 4; i = i + 1) {
    read_vol[0] = '\0';
    read_vol[1] = '\0';
    read_vol[2] = '\0';
    read_vol[3] = '\0';
    read_vol[4] = '\0';
    read_vol[5] = '\0';
    read_vol[6] = '\0';
    read_vol[7] = '\0';
    read_vol[8] = '\0';
    read_vol[9] = '\0';
    read_vol[10] = '\0';
    read_vol[0xb] = '\0';
    iVar1 = PIC16F1704_i2c_forward_send(i2c,chain,"PQTU"[i],1,'!',2,read_vol);
    if (iVar1 == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"read %02x vol success, 0x%02x%02x\n",(uint)"PQTU"[i],read_vol._0_4_ & 0xff,
                 (uint)read_vol[1]);
        _applog(2,tmp42,false);
      }
    }
    else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"read %02x vol failed, 0x%02x%02x\n",(uint)"PQTU"[i],read_vol._0_4_ & 0xff,(uint)read_vol[1])
      ;
      _applog(2,tmp42,false);
    }
  }
  return;
}




int get_PIC16F1704_voltage(uint which_i2c,uchar which_chain,uchar *voltage)

{
  ushort uVar1;
  uchar uVar2;
  int iVar3;
  uchar *voltage_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [5];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[4] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '\x18';
  send_data[4] = '\0';
  send_data[5] = '\x1c';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; i < 5; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,
             "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x\n"
             ,"get_PIC16F1704_voltage",read_back_data._0_4_ & 0xff,(uint)read_back_data._0_4_ >> 8 & 0xff,
             (uint)read_back_data._0_4_ >> 0x10 & 0xff,(uint)read_back_data._0_4_ >> 0x18,(uint)read_back_data[4]);
    _applog(2,tmp42,false);
  }
  if ((read_back_data[1] == '\x18') && (read_back_data[0] == '\x05')) {
    uVar1 = read_back_data[2] + 0x1d;
    if (((uchar)(uVar1 >> 8) == read_back_data[3]) && ((uchar)uVar1 == read_back_data[4])) {
      *voltage = read_back_data[2];
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s ok, voltage = 0x%02x\n\n","get_PIC16F1704_voltage",(uint)*voltage);
        _applog(2,tmp42,false);
      }
      iVar3 = 1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s failed! crc = 0x%04x\n\n","get_PIC16F1704_voltage",(uint)uVar1);
        _applog(2,tmp42,false);
      }
      iVar3 = 0;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed!\n\n","get_PIC16F1704_voltage");
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}




int write_temperature_offset_PIC16F1704(uint which_i2c,uchar which_chain,uchar *buf)

{
  uchar uVar1;
  int iVar2;
  uchar *buf_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [14];
  uchar read_back_data [2];
  uchar crc_data [2];
  uchar length;
  uchar i;
  ushort crc;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[0xb] = '\0';
  crc = 0x2e;
  for (i = '\0'; i < 8; i = i + '\x01') {
    crc = crc + buf[i];
  }
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\f';
  send_data[3] = '\"';
  for (i = '\0'; i < 8; i = i + '\x01') {
    send_data[i + 4] = buf[i];
  }
  send_data[0xd] = (uchar)crc;
  send_data[0xc] = (uchar)(crc >> 8);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 0xe; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar1 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar1;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[0] == '\"') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","write_temperature_offset_PIC16F1704");
      _applog(2,tmp42,false);
    }
    iVar2 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "write_temperature_offset_PIC16F1704",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  return iVar2;
}




int read_temperature_offset_PIC16F1704(uint which_i2c,uchar which_chain,uchar *buf)

{
  ushort uVar1;
  uchar uVar2;
  int iVar3;
  uchar *buf_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [12];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[6] = '\0';
  read_back_data[7] = '\0';
  read_back_data[8] = '\0';
  read_back_data[9] = '\0';
  read_back_data[10] = '\0';
  read_back_data[0xb] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '#';
  send_data[4] = '\0';
  send_data[5] = '\'';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; i < 0xc; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,
             "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, \t\tread_back_data[4] = 0x%x, read_back_data[5] = 0x%x, read_back_data[6] = 0x%x, read_back_data[7] = 0x%x, \t\tread_back_data[8] = 0x%x, read_back_data[9] = 0x%x, read_back_data[10] = 0x%x, read_back_data[11] = 0x%x\n"
             ,"read_temperature_offset_PIC16F1704",read_back_data._0_4_ & 0xff,(uint)read_back_data._0_4_ >> 8 & 0xff,
             (uint)read_back_data._0_4_ >> 0x10 & 0xff,(uint)read_back_data._0_4_ >> 0x18,read_back_data._4_4_ & 0xff,
             (uint)read_back_data._4_4_ >> 8 & 0xff,(uint)read_back_data._4_4_ >> 0x10 & 0xff,
             (uint)read_back_data._4_4_ >> 0x18,read_back_data._8_4_ & 0xff,(uint)read_back_data._8_4_ >> 8 & 0xff,
             (uint)read_back_data._8_4_ >> 0x10 & 0xff,(uint)read_back_data._8_4_ >> 0x18);
    _applog(2,tmp42,false);
  }
  if ((read_back_data[1] == '#') && (read_back_data[0] == '\f')) {
    uVar1 = (ushort)read_back_data[9] +
            (ushort)read_back_data[8] +
            (ushort)read_back_data[7] +
            (ushort)read_back_data[6] +
            (ushort)read_back_data[5] + (ushort)read_back_data[4] + (ushort)read_back_data[3] + read_back_data[2] + 0x2f
    ;
    if (((uchar)(uVar1 >> 8) == read_back_data[10]) && ((uchar)uVar1 == read_back_data[0xb])) {
      for (i = '\0'; i < 8; i = i + '\x01') {
        buf[i] = read_back_data[i + 2];
      }
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s ok\n\n","read_temperature_offset_PIC16F1704");
        _applog(2,tmp42,false);
      }
      iVar3 = 1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s failed! crc = 0x%04x\n\n","read_temperature_offset_PIC16F1704",(uint)uVar1);
        _applog(2,tmp42,false);
      }
      iVar3 = 0;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed!\n\n","read_temperature_offset_PIC16F1704");
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}




int erase_PIC16F1704_app_flash(uint which_i2c,uchar which_chain)

{
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uint pic_flash_length;
  uchar end_addr_l;
  uchar end_addr_h;
  uchar start_addr_l;
  uchar start_addr_h;
  uint erase_loop;
  uint i;
  
  set_PIC16F1704_flash_pointer(which_i2c,which_chain,'\x06','\0');
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s: erase_loop = %d\n","erase_PIC16F1704_app_flash",0x4c);
    _applog(2,tmp42,false);
  }
  for (i = 0; i < 0x4c; i = i + 1) {
    erase_PIC16F1704_flash(which_i2c,which_chain);
  }
  return 1;
}




int PIC1704_update_pic_app_program(uint which_i2c,uchar which_chain)

{
  FILE *__stream;
  ulong uVar1;
  int iVar2;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar buf [16];
  char data_read [5];
  uchar program_data [5000];
  FILE *pic_program_file;
  int ret;
  uint pic_flash_length;
  uchar end_addr_l;
  uchar end_addr_h;
  uchar start_addr_l;
  uchar start_addr_h;
  uint data_int;
  uint i;
  
  memset(program_data,0,5000);
  data_read[0] = '\0';
  data_read[1] = '\0';
  data_read[2] = '\0';
  data_read[3] = '\0';
  data_read[4] = '\0';
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  buf[9] = '\0';
  buf[10] = '\0';
  buf[0xb] = '\0';
  buf[0xc] = '\0';
  buf[0xd] = '\0';
  buf[0xe] = '\0';
  buf[0xf] = '\0';
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"--- update pic program\n",0x18);
    _applog(2,tmp42,false);
  }
  __stream = fopen("/mnt/card/pic16f1704_app.txt","r");
  if (__stream == (FILE *)0x0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: open pic16f1704_app.txt failed\n","PIC1704_update_pic_app_program");
      _applog(2,tmp42,false);
    }
    iVar2 = 0;
  }
  else {
    fseek(__stream,0,0);
    memset(program_data,0,5000);
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"pic_flash_length = %d\n",0x980);
      _applog(2,tmp42,false);
    }
    for (i = 0; i < 0x980; i = i + 1) {
      fgets(data_read,0x3ff,__stream);
      uVar1 = strtoul(data_read,(char **)0x0,0x10);
      program_data[i * 2] = (uchar)(uVar1 >> 8);
      program_data[i * 2 + 1] = (uchar)uVar1;
    }
    fclose(__stream);
    iVar2 = reset_PIC16F1704_pic(which_i2c,which_chain);
    if (iVar2 == 0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"!!! %s: reset pic error!\n\n","PIC1704_update_pic_app_program");
        _applog(2,tmp42,false);
      }
      iVar2 = 0;
    }
    else {
      iVar2 = erase_PIC16F1704_app_flash(which_i2c,which_chain);
      if (iVar2 == 0) {
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          snprintf(tmp42,0x400,"!!! %s: erase flash error!\n\n","PIC1704_update_pic_app_program");
          _applog(2,tmp42,false);
        }
        iVar2 = 0;
      }
      else {
        iVar2 = set_PIC16F1704_flash_pointer(which_i2c,which_chain,'\x06','\0');
        if (iVar2 == 0) {
          if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
            snprintf(tmp42,0x400,"!!! %s: set flash pointer error!\n\n","PIC1704_update_pic_app_program");
            _applog(2,tmp42,false);
          }
          iVar2 = 0;
        }
        else {
          for (i = 0; i < 0x130; i = i + 1) {
            iVar2 = i * 0x10;
            buf._0_4_ = *(undefined4 *)(program_data + iVar2);
            buf._4_4_ = *(undefined4 *)(program_data + iVar2 + 4);
            buf._8_4_ = *(undefined4 *)(program_data + iVar2 + 8);
            buf._12_4_ = *(undefined4 *)(program_data + iVar2 + 0xc);
            if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
              snprintf(tmp42,0x400,"send pic program time: %d\n",i);
              _applog(2,tmp42,false);
            }
            send_data_to_PIC16F1704(which_i2c,which_chain,buf);
            write_data_into_PIC16F1704_flash(which_i2c,which_chain);
          }
          iVar2 = reset_PIC16F1704_pic(which_i2c,which_chain);
          if (iVar2 == 0) {
            if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
              snprintf(tmp42,0x400,"!!! %s: reset pic error!\n\n","PIC1704_update_pic_app_program");
              _applog(2,tmp42,false);
            }
            iVar2 = 0;
          }
          else {
            iVar2 = 1;
          }
        }
      }
    }
  }
  return iVar2;
}




int save_freq_PIC16F1704(uint which_chain,uchar which_i2c,ushort freq)

{
  short sVar1;
  uchar uVar2;
  int iVar3;
  ushort freq_local;
  uchar which_i2c_local;
  uint which_chain_local;
  char tmp42 [1024];
  uchar send_data [8];
  uchar read_back_data [2];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  sVar1 = (freq & 0xff) + (freq >> 8) + 0x2a;
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x06';
  send_data[3] = '$';
  send_data[5] = (uchar)freq;
  send_data[4] = (uchar)(freq >> 8);
  send_data[6] = (uchar)((ushort)sVar1 >> 8);
  send_data[7] = (uchar)sVar1;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 8; i = i + '\x01') {
    write_pic(which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(300000);
  for (i = '\0'; i < 2; i = i + '\x01') {
    uVar2 = read_pic(which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[0] == '$') && (read_back_data[1] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","save_freq_PIC16F1704");
      _applog(2,tmp42,false);
    }
    iVar3 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x\n\n",
               "save_freq_PIC16F1704",(uint)read_back_data[0],(uint)read_back_data[1]);
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}




int get_PIC16F1704_freq(uint which_chain,uchar which_i2c,ushort *freq)

{
  ushort uVar1;
  uchar uVar2;
  int iVar3;
  ushort *freq_local;
  uchar which_i2c_local;
  uint which_chain_local;
  char tmp42 [1024];
  uchar send_data [6];
  uchar read_back_data [6];
  uchar crc_data [2];
  ushort crc;
  uchar length;
  uchar i;
  
  read_back_data[4] = '\0';
  read_back_data[5] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x04';
  send_data[3] = '%';
  send_data[4] = '\0';
  send_data[5] = ')';
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 6; i = i + '\x01') {
    write_pic(which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(300000);
  for (i = '\0'; i < 6; i = i + '\x01') {
    uVar2 = read_pic(which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,
             "--- %s: read_back_data[0] = 0x%x, read_back_data[1] = 0x%x, read_back_data[2] = 0x%x, read_back_data[3] = 0x%x, read_back_data[4] = 0x%x, read_back_data[5] = 0x%x\n"
             ,"get_PIC16F1704_freq",read_back_data._0_4_ & 0xff,(uint)read_back_data._0_4_ >> 8 & 0xff,
             (uint)read_back_data._0_4_ >> 0x10 & 0xff,(uint)read_back_data._0_4_ >> 0x18,(uint)read_back_data[4],
             (uint)read_back_data[5]);
    _applog(2,tmp42,false);
  }
  if ((read_back_data[1] == '%') && (read_back_data[0] == '\x06')) {
    uVar1 = (ushort)read_back_data[3] + read_back_data[2] + 0x2b;
    if (((uchar)(uVar1 >> 8) == read_back_data[4]) && ((uchar)uVar1 == read_back_data[5])) {
      *freq = CONCAT11(read_back_data[2],read_back_data[3]);
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s ok, freq = %d\n\n","get_PIC16F1704_freq",(uint)*freq);
        _applog(2,tmp42,false);
      }
      iVar3 = 1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s failed! crc = 0x%04x\n\n","get_PIC16F1704_freq",(uint)uVar1);
        _applog(2,tmp42,false);
      }
      iVar3 = 0;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"--- %s failed!\n\n","get_PIC16F1704_freq");
      _applog(2,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}




void set_temperature_offset_value(uint which_i2c,uchar which_chain,uchar *value)

{
  uchar *value_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","set_temperature_offset_value");
    _applog(2,tmp42,false);
  }
  write_temperature_offset_PIC16F1704(which_i2c,which_chain,value);
  usleep(100000);
  return;
}




int write_PIC16F1705_iic_slave(uint which_i2c,uchar which_chain,uchar *buf,uchar buf_len)

{
  byte bVar1;
  uchar uVar2;
  byte bVar3;
  int iVar4;
  uchar *buf_local;
  uchar buf_len_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [100];
  uchar read_back_data [5];
  uchar crc_data [2];
  uchar length;
  uchar i;
  ushort crc;
  
  bVar3 = buf_len + 4;
  read_back_data[4] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  memset(send_data,0,100);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","write_PIC16F1705_iic_slave");
    _applog(2,tmp42,false);
  }
  crc = bVar3 + 0x26;
  for (i = '\0'; i < buf_len; i = i + '\x01') {
    crc = crc + buf[i];
  }
  bVar1 = (byte)(crc >> 8);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n","write_PIC16F1705_iic_slave",(uint)bVar1,
             (uint)(byte)crc);
    _applog(2,tmp42,false);
  }
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '&';
  for (i = '\0'; i < buf_len; i = i + '\x01') {
    send_data[i + 4] = buf[i];
  }
  send_data[buf_len + 4] = bVar1;
  send_data[buf_len + 5] = (byte)crc;
  send_data[2] = bVar3;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; (uint)i < bVar3 + 2; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; i < 5; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[1] == '&') && (read_back_data[2] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","write_PIC16F1705_iic_slave");
      _applog(2,tmp42,false);
    }
    iVar4 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,
               "--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x, read_back_data[3] = 0x%02x, read_back_data[4] = 0x%02x\n\n"
               ,"write_PIC16F1705_iic_slave",read_back_data._0_4_ & 0xff,(uint)read_back_data[1],(uint)read_back_data[2]
               ,(uint)read_back_data._0_4_ >> 0x18,(uint)read_back_data[4]);
      _applog(2,tmp42,false);
    }
    iVar4 = 0;
  }
  return iVar4;
}




int read_PIC16F1705_iic_slave(uint which_i2c,uchar which_chain,uchar *buf,uchar buf_len,uchar *read_back_buf)

{
  byte bVar1;
  uchar uVar2;
  byte bVar3;
  int iVar4;
  uchar *buf_local;
  uchar buf_len_local;
  uchar which_chain_local;
  uint which_i2c_local;
  char tmp42 [1024];
  uchar send_data [100];
  uchar read_back_data [100];
  uchar crc_data [2];
  uchar length;
  uchar i;
  ushort crc;
  
  bVar3 = buf_len + 4;
  memset(read_back_data,0,100);
  read_back_data[0] = 0xff;
  memset(send_data,0,100);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","read_PIC16F1705_iic_slave");
    _applog(2,tmp42,false);
  }
  crc = bVar3 + 0x26;
  for (i = '\0'; i < buf_len; i = i + '\x01') {
    crc = crc + buf[i];
  }
  bVar1 = (byte)(crc >> 8);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n","read_PIC16F1705_iic_slave",(uint)bVar1,
             (uint)(byte)crc);
    _applog(2,tmp42,false);
  }
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '&';
  for (i = '\0'; i < buf_len; i = i + '\x01') {
    send_data[i + 4] = buf[i];
  }
  send_data[buf_len + 4] = bVar1;
  send_data[buf_len + 5] = (byte)crc;
  send_data[2] = bVar3;
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; (uint)i < bVar3 + 2; i = i + '\x01') {
    write_pic((uchar)which_i2c,which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; (uint)i < buf[2] + 3; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  if ((read_back_data[1] == '&') && (read_back_data[2] == '\x01')) {
    if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
      snprintf(tmp42,0x400,"--- %s ok\n\n","read_PIC16F1705_iic_slave");
      _applog(2,tmp42,false);
    }
    iVar4 = 1;
  }
  else {
    for (i = '\0'; (uint)i < buf[2] + 3; i = i + '\x01') {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"--- %s failed! read_back_data[%d] = 0x%02x\n\n","read_PIC16F1705_iic_slave",(uint)i,
                 (uint)read_back_data[i]);
        _applog(2,tmp42,false);
      }
    }
    iVar4 = 0;
  }
  return iVar4;
}




int write_data_to_PIC16F1704_flash(int which_chain,int which_i2c,uchar *buf,int buf_len)

{
  byte bVar1;
  uchar uVar2;
  int iVar3;
  int buf_len_local;
  uchar *buf_local;
  int which_i2c_local;
  int which_chain_local;
  char tmp42 [1024];
  uchar send_data [12];
  uchar read_back_data [5];
  uchar crc_data [2];
  int send_len;
  uchar length;
  uchar i;
  ushort crc;
  
  read_back_data[4] = '\0';
  read_back_data[0] = 0xff;
  read_back_data[1] = '\0';
  read_back_data[2] = '\0';
  read_back_data[3] = '\0';
  send_data[0] = '\0';
  send_data[1] = '\0';
  send_data[2] = '\0';
  send_data[3] = '\0';
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  send_data[8] = '\0';
  send_data[9] = '\0';
  send_data[10] = '\0';
  send_data[0xb] = '\0';
  if ((opt_debug) && (((use_syslog || (opt_log_output)) || (3 < opt_log_level)))) {
    snprintf(tmp42,0x400,"\n--- %s\n","write_data_to_PIC16F1704_flash");
    _applog(4,tmp42,false);
  }
  crc = (short)buf_len * 2 + 0x39;
  for (i = '\0'; (int)(uint)i < buf_len; i = i + '\x01') {
    crc = crc + buf[i];
  }
  bVar1 = (byte)(crc >> 8);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n","write_data_to_PIC16F1704_flash",(uint)bVar1
             ,(uint)(byte)crc);
    _applog(2,tmp42,false);
  }
  send_data[2] = (char)buf_len + '\x06';
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[3] = '3';
  send_data._4_4_ = (uint)CONCAT21(send_data._6_2_,(char)buf_len) << 8;
  memcpy(send_data + 6,buf,buf_len);
  send_data[buf_len + 6] = bVar1;
  send_data[buf_len + 7] = (byte)crc;
  for (i = '\0'; (int)(uint)i < buf_len + 8; i = i + '\x01') {
    printf("%02x ",(uint)send_data[i]);
  }
  putchar(10);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; (int)(uint)i < buf_len + 8; i = i + '\x01') {
    write_pic((uchar)which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; i < 5; i = i + '\x01') {
    uVar2 = read_pic((uchar)which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar2;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  for (i = '\0'; i < 5; i = i + '\x01') {
    printf("%02x ",(uint)read_back_data[i]);
  }
  putchar(10);
  if (((read_back_data[0] == '\x05') && (read_back_data[1] == '3')) && (read_back_data[2] == '\x01')) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"\n--- %s ok\n\n","write_data_to_PIC16F1704_flash");
      _applog(2,tmp42,false);
    }
    iVar3 = 1;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,
               "\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n"
               ,"write_data_to_PIC16F1704_flash",read_back_data._0_4_ & 0xff,(uint)read_back_data[1],
               (uint)read_back_data[2]);
      _applog(0,tmp42,false);
    }
    iVar3 = 0;
  }
  return iVar3;
}




int read_data_from_PIC16F1704_flash(int which_chain,int which_i2c,uchar *buf,uchar read_len)

{
  byte bVar1;
  byte bVar2;
  uchar uVar3;
  int iVar4;
  uchar read_len_local;
  uchar *buf_local;
  int which_i2c_local;
  int which_chain_local;
  char tmp42 [1024];
  uchar send_data [8];
  uchar read_back_data [40];
  uchar crc_data [2];
  uchar length;
  uchar i;
  ushort crc;
  
  memset(read_back_data,0,0x28);
  read_back_data[0] = 0xff;
  send_data[0] = '\0';
  send_data[1] = '\0';
  send_data[2] = '\0';
  send_data[3] = '\0';
  send_data[4] = '\0';
  send_data[5] = '\0';
  send_data[6] = '\0';
  send_data[7] = '\0';
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"\n--- %s\n","read_data_from_PIC16F1704_flash");
    _applog(2,tmp42,false);
  }
  bVar1 = (byte)((ushort)(read_len + 0x3a) >> 8);
  bVar2 = (byte)(read_len + 0x3a);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s: crc_data[0] = 0x%x, crc_data[1] = 0x%x\n","read_data_from_PIC16F1704_flash",
             (uint)bVar1,(uint)bVar2);
    _applog(2,tmp42,false);
  }
  send_data[0] = 'U';
  send_data[1] = 0xaa;
  send_data[2] = '\x06';
  send_data[3] = '4';
  send_data._4_4_ = (uint)CONCAT12(bVar2,CONCAT11(bVar1,read_len)) << 8;
  for (i = '\0'; i < 8; i = i + '\x01') {
    printf("%02x ",(uint)send_data[i]);
  }
  putchar(10);
  pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  for (i = '\0'; i < 8; i = i + '\x01') {
    write_pic((uchar)which_i2c,(uchar)which_chain,send_data[i]);
  }
  usleep(200000);
  for (i = '\0'; (uint)i < read_len + 5; i = i + '\x01') {
    uVar3 = read_pic((uchar)which_i2c,(uchar)which_chain);
    read_back_data[i] = uVar3;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  usleep(200000);
  for (i = '\0'; (uint)i < read_len + 5; i = i + '\x01') {
    printf("%02x ",(uint)read_back_data[i]);
  }
  putchar(10);
  if (((read_back_data[1] == '4') && ((uint)read_back_data[0] == read_len + 5)) && (read_back_data[2] == '\x01')) {
    crc = 0;
    for (i = '\0'; (uint)i < read_len + 3; i = i + '\x01') {
      crc = crc + read_back_data[i];
    }
    if (((uchar)(crc >> 8) == read_back_data[read_len + 3]) && ((uchar)crc == read_back_data[read_len + 4])) {
      memcpy(buf,read_back_data + 3,(uint)read_len);
      if ((use_syslog != false) || ((opt_log_output != false || (1 < opt_log_level)))) {
        snprintf(tmp42,0x400,"\n--- %s ok\n\n","read_data_from_PIC16F1704_flash");
        _applog(2,tmp42,false);
      }
      iVar4 = 1;
    }
    else {
      if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
        snprintf(tmp42,0x400,"\n--- %s failed! crc = 0x%04x\n\n","read_data_from_PIC16F1704_flash",(uint)crc);
        _applog(0,tmp42,false);
      }
      iVar4 = 0;
    }
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      snprintf(tmp42,0x400,
               "\n--- %s failed! read_back_data[0] = 0x%02x, read_back_data[1] = 0x%02x, read_back_data[2] = 0x%02x\n\n"
               ,"read_data_from_PIC16F1704_flash",(uint)read_back_data[0],(uint)read_back_data[1],
               (uint)read_back_data[2]);
      _applog(0,tmp42,false);
    }
    iVar4 = 0;
  }
  return iVar4;
}




/* WARNING: Unknown calling convention */

uint get_fan_speed(void)

{
  uint uVar1;
  
  uVar1 = read_axi_fpga(1);
  return uVar1;
}




void set_fan_speed(uint speed)

{
  uint speed_local;
  
  write_axi_fpga(0x21,speed);
  return;
}




void fan_control(uchar level)

{
  uchar level_local;
  uint speed;
  
  switch(level) {
  case '\0':
    speed = 100;
    break;
  case '\x01':
    speed = 0xa005a;
    break;
  case '\x02':
    speed = 0x140050;
    break;
  case '\x03':
    speed = 0x1e0046;
    break;
  case '\x04':
    speed = 0x28003c;
    break;
  case '\x05':
    speed = 0x320032;
    break;
  case '\x06':
    speed = 0x3c0028;
    break;
  case '\a':
    speed = 0x46001e;
    break;
  case '\b':
    speed = 0x500014;
    break;
  case '\t':
    speed = 0x5a000a;
    break;
  case '\n':
    speed = 0x640000;
    break;
  default:
    speed = 0x640000;
  }
  set_fan_speed(speed);
  return;
}




int uart_init(int comport,int baud)

{
  int baud_local;
  int comport_local;
  char tmp42 [1024];
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s chain=%d baudrate=%d\n","uart_init",comport,baud);
    _applog(2,tmp42,false);
  }
  return (uint)gChain;
}




int uart_exit(int fd)

{
  int fd_local;
  char tmp42 [1024];
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s fd=%d\n","uart_exit",fd);
    _applog(2,tmp42,false);
  }
  return 0;
}




uint check_how_many_uart_data_in_fpga(uchar which_uart)

{
  uint uVar1;
  uchar which_uart_local;
  char tmp42 [1024];
  
  switch(which_uart) {
  case '\0':
    uVar1 = read_axi_fpga(0x440);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case '\x01':
    uVar1 = read_axi_fpga(0x440);
    uVar1 = uVar1 & 0x3ff;
    break;
  case '\x02':
    uVar1 = read_axi_fpga(0x441);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case '\x03':
    uVar1 = read_axi_fpga(0x441);
    uVar1 = uVar1 & 0x3ff;
    break;
  case '\x04':
    uVar1 = read_axi_fpga(0x442);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case '\x05':
    uVar1 = read_axi_fpga(0x442);
    uVar1 = uVar1 & 0x3ff;
    break;
  case '\x06':
    uVar1 = read_axi_fpga(0x443);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case '\a':
    uVar1 = read_axi_fpga(0x443);
    uVar1 = uVar1 & 0x3ff;
    break;
  case '\b':
    uVar1 = read_axi_fpga(0x444);
    uVar1 = uVar1 >> 0x10 & 0x3ff;
    break;
  case '\t':
    uVar1 = read_axi_fpga(0x444);
    uVar1 = uVar1 & 0x3ff;
    break;
  default:
    if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: The uart%d is not supported!!!\n","check_how_many_uart_data_in_fpga",(uint)which_uart);
      _applog(2,tmp42,false);
    }
    uVar1 = 0;
  }
  return uVar1;
}




uint read_uart_data_in_fpga(uchar which_uart,uchar *buf,uint length)

{
  uchar uVar1;
  uchar uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint length_local;
  uchar *buf_local;
  uchar which_uart_local;
  char tmp42 [1024];
  uint ret_data;
  uint read_loop;
  uint data;
  uint ret_length;
  uint i;
  uint chain_read_data_addr;
  uint chain_read_enable_addr;
  
  switch(which_uart) {
  case '\0':
    chain_read_enable_addr = 0x44c;
    chain_read_data_addr = 0x44d;
    break;
  case '\x01':
    chain_read_enable_addr = 0x44e;
    chain_read_data_addr = 0x44f;
    break;
  case '\x02':
    chain_read_enable_addr = 0x450;
    chain_read_data_addr = 0x451;
    break;
  case '\x03':
    chain_read_enable_addr = 0x452;
    chain_read_data_addr = 0x453;
    break;
  case '\x04':
    chain_read_enable_addr = 0x454;
    chain_read_data_addr = 0x455;
    break;
  case '\x05':
    chain_read_enable_addr = 0x456;
    chain_read_data_addr = 0x457;
    break;
  case '\x06':
    chain_read_enable_addr = 0x458;
    chain_read_data_addr = 0x459;
    break;
  case '\a':
    chain_read_enable_addr = 0x45a;
    chain_read_data_addr = 0x45b;
    break;
  case '\b':
    chain_read_enable_addr = 0x45c;
    chain_read_data_addr = 0x45d;
    break;
  case '\t':
    chain_read_enable_addr = 0x45e;
    chain_read_data_addr = 0x45f;
    break;
  default:
    if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: The uart%d is not supported!!!\n","read_uart_data_in_fpga",(uint)which_uart);
      _applog(2,tmp42,false);
    }
    return 0;
  }
  write_axi_fpga(chain_read_enable_addr,length & 0x3ff | 0x80000000);
  for (i = 0; i < length >> 2; i = i + 1) {
    uVar5 = read_axi_fpga(chain_read_data_addr);
    buf[i * 4] = (uchar)(uVar5 >> 0x18);
    buf[i * 4 + 1] = (uchar)(uVar5 >> 0x10);
    buf[i * 4 + 2] = (uchar)(uVar5 >> 8);
    buf[i * 4 + 3] = (uchar)uVar5;
  }
  uVar4 = (length >> 2) * 4;
  uVar5 = length & 3;
  if (uVar5 != 0) {
    uVar3 = read_axi_fpga(chain_read_data_addr);
    uVar2 = (uchar)(uVar3 >> 0x10);
    uVar1 = (uchar)(uVar3 >> 0x18);
    if (uVar5 == 2) {
      buf[i * 4] = uVar1;
      buf[i * 4 + 1] = uVar2;
      uVar4 = uVar4 + 2;
    }
    else if (uVar5 == 3) {
      buf[i * 4] = uVar1;
      buf[i * 4 + 1] = uVar2;
      buf[i * 4 + 2] = (uchar)(uVar3 >> 8);
      uVar4 = uVar4 + 3;
    }
    else if (uVar5 == 1) {
      buf[i * 4] = uVar1;
      uVar4 = uVar4 + 1;
    }
    else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: the uart%d left data is 4*N length, error!!!\n","read_uart_data_in_fpga",
               (uint)which_uart);
      _applog(2,tmp42,false);
    }
  }
  return uVar4;
}




uint uart_send(uchar which_uart,uchar *buf,uint length)

{
  uint uVar1;
  uint length_local;
  uchar *buf_local;
  uchar which_uart_local;
  char tmp42 [1024];
  uchar send_buf [512];
  uint max_fpga_can_send_uart_data_len;
  uint send_data_len;
  int send_loop;
  uint bit_shift_num;
  uint chain_send_buffer_addr;
  uint chain_send_ready_addr;
  uint chain_send_fifo_status_addr;
  uint send_data;
  int i;
  int send_counter;
  
  memset(send_buf,0,0x200);
  send_data = 0;
  pthread_mutex_lock((pthread_mutex_t *)(uart_send_mutex + which_uart));
  switch(which_uart) {
  case '\0':
    bit_shift_num = 0x18;
    chain_send_fifo_status_addr = 0x400;
    chain_send_ready_addr = 0x404;
    chain_send_buffer_addr = 0x405;
    break;
  case '\x01':
    bit_shift_num = 0x10;
    chain_send_fifo_status_addr = 0x400;
    chain_send_ready_addr = 0x406;
    chain_send_buffer_addr = 0x407;
    break;
  case '\x02':
    bit_shift_num = 8;
    chain_send_fifo_status_addr = 0x400;
    chain_send_ready_addr = 0x408;
    chain_send_buffer_addr = 0x409;
    break;
  case '\x03':
    bit_shift_num = 0;
    chain_send_fifo_status_addr = 0x400;
    chain_send_ready_addr = 0x40a;
    chain_send_buffer_addr = 0x40b;
    break;
  case '\x04':
    bit_shift_num = 0x18;
    chain_send_fifo_status_addr = 0x401;
    chain_send_ready_addr = 0x40c;
    chain_send_buffer_addr = 0x40d;
    break;
  case '\x05':
    bit_shift_num = 0x10;
    chain_send_fifo_status_addr = 0x401;
    chain_send_ready_addr = 0x40e;
    chain_send_buffer_addr = 0x40f;
    break;
  case '\x06':
    bit_shift_num = 8;
    chain_send_fifo_status_addr = 0x401;
    chain_send_ready_addr = 0x410;
    chain_send_buffer_addr = 0x411;
    break;
  case '\a':
    bit_shift_num = 0;
    chain_send_fifo_status_addr = 0x401;
    chain_send_ready_addr = 0x412;
    chain_send_buffer_addr = 0x413;
    break;
  case '\b':
    bit_shift_num = 0x18;
    chain_send_fifo_status_addr = 0x402;
    chain_send_ready_addr = 0x414;
    chain_send_buffer_addr = 0x415;
    break;
  case '\t':
    bit_shift_num = 0x10;
    chain_send_fifo_status_addr = 0x402;
    chain_send_ready_addr = 0x416;
    chain_send_buffer_addr = 0x417;
    break;
  default:
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: The uart%d is not supported!!!\n","uart_send",(uint)which_uart);
      _applog(2,tmp42,false);
    }
    return 0;
  }
  send_counter = 0;
  do {
    uVar1 = read_axi_fpga(chain_send_fifo_status_addr);
    if (length <= (uVar1 >> bit_shift_num & 0xff)) {
      send_counter = 0;
      while( true ) {
        uVar1 = read_axi_fpga(chain_send_ready_addr);
        if (-1 < (int)uVar1) {
          memcpy(send_buf,buf,length);
          for (i = 0; i < (int)(length >> 2); i = i + 1) {
            send_data = (uint)send_buf[i * 4 + 2] << 8 |
                        (uint)send_buf[i * 4] << 0x18 | (uint)send_buf[i * 4 + 1] << 0x10 | (uint)send_buf[i * 4 + 3];
            write_axi_fpga(chain_send_buffer_addr,send_data);
          }
          uVar1 = length & 3;
          if (uVar1 != 0) {
            if (uVar1 == 2) {
              send_data = (uint)send_buf[i * 4 + 1] << 0x10 | (uint)send_buf[i * 4] << 0x18;
            }
            else if (uVar1 == 3) {
              send_data = (uint)send_buf[i * 4 + 2] << 8 |
                          (uint)send_buf[i * 4] << 0x18 | (uint)send_buf[i * 4 + 1] << 0x10;
            }
            else if (uVar1 == 1) {
              send_data = (uint)send_buf[i * 4] << 0x18;
            }
            else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
              snprintf(tmp42,0x400,"%s: the uart%d send left data is 4*N length, error!!!\n","uart_send",
                       (uint)which_uart);
              _applog(2,tmp42,false);
            }
            write_axi_fpga(chain_send_buffer_addr,send_data);
          }
          write_axi_fpga(chain_send_ready_addr,length | 0x80000000);
          pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + which_uart));
          return length;
        }
        if (0x14 < send_counter) break;
        send_counter = send_counter + 1;
        usleep(3000);
      }
      pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + which_uart));
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"%s: uart%d always busy, break\n","uart_send",(uint)which_uart);
        _applog(2,tmp42,false);
      }
      return 0;
    }
    usleep(3000);
    send_counter = send_counter + 1;
  } while (send_counter < 0x15);
  pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + which_uart));
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s: uart%d always dose not has enough send fifo space, break\n","uart_send",(uint)which_uart);
    _applog(2,tmp42,false);
  }
  return 0;
}




uint uart_receive(uchar which_uart,uchar *buf,uint buf_length)

{
  uint length;
  uint buf_length_local;
  uchar *buf_local;
  uchar which_uart_local;
  uint nbytes;
  uint len;
  
  pthread_mutex_lock((pthread_mutex_t *)(uart_receive_mutex + which_uart));
  length = check_how_many_uart_data_in_fpga(which_uart);
  if (length < buf_length) {
    if (length == 0) {
      len = 0;
    }
    else {
      len = read_uart_data_in_fpga(which_uart,buf,length);
    }
  }
  else {
    len = read_uart_data_in_fpga(which_uart,buf,buf_length);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + which_uart));
  return len;
}




uint clear_uart_send_fifo(uchar which_chain)

{
  uint uVar1;
  uchar which_chain_local;
  char tmp42 [1024];
  uint max_fpga_can_send_uart_data_len;
  uint chain_send_buffer_addr;
  uint send_counter;
  uint bit_shift_num;
  uint chain_send_ready_addr;
  uint chain_send_fifo_status_addr;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","clear_uart_send_fifo");
    _applog(2,tmp42,false);
  }
  pthread_mutex_lock((pthread_mutex_t *)(uart_send_mutex + which_chain));
  switch(which_chain) {
  case '\0':
    bit_shift_num = 0x18;
    chain_send_fifo_status_addr = 0x400;
    chain_send_ready_addr = 0x404;
    chain_send_buffer_addr = 0x405;
    break;
  case '\x01':
    bit_shift_num = 0x10;
    chain_send_fifo_status_addr = 0x400;
    chain_send_ready_addr = 0x406;
    chain_send_buffer_addr = 0x407;
    break;
  case '\x02':
    bit_shift_num = 8;
    chain_send_fifo_status_addr = 0x400;
    chain_send_ready_addr = 0x408;
    chain_send_buffer_addr = 0x409;
    break;
  case '\x03':
    bit_shift_num = 0;
    chain_send_fifo_status_addr = 0x400;
    chain_send_ready_addr = 0x40a;
    chain_send_buffer_addr = 0x40b;
    break;
  case '\x04':
    bit_shift_num = 0x18;
    chain_send_fifo_status_addr = 0x401;
    chain_send_ready_addr = 0x40c;
    chain_send_buffer_addr = 0x40d;
    break;
  case '\x05':
    bit_shift_num = 0x10;
    chain_send_fifo_status_addr = 0x401;
    chain_send_ready_addr = 0x40e;
    chain_send_buffer_addr = 0x40f;
    break;
  case '\x06':
    bit_shift_num = 8;
    chain_send_fifo_status_addr = 0x401;
    chain_send_ready_addr = 0x410;
    chain_send_buffer_addr = 0x411;
    break;
  case '\a':
    bit_shift_num = 0;
    chain_send_fifo_status_addr = 0x401;
    chain_send_ready_addr = 0x412;
    chain_send_buffer_addr = 0x413;
    break;
  case '\b':
    bit_shift_num = 0x18;
    chain_send_fifo_status_addr = 0x402;
    chain_send_ready_addr = 0x414;
    chain_send_buffer_addr = 0x415;
    break;
  case '\t':
    bit_shift_num = 0x10;
    chain_send_fifo_status_addr = 0x402;
    chain_send_ready_addr = 0x416;
    chain_send_buffer_addr = 0x417;
    break;
  default:
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: The uart%d is not supported!!!\n","clear_uart_send_fifo",(uint)which_chain);
      _applog(2,tmp42,false);
    }
    pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + which_chain));
    return 1;
  }
  if ((opt_debug != false) && (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
    snprintf(tmp42,0x400,"chain_send_ready_addr: 0x%08x, chain_send_buffer_addr: 0x%08x",chain_send_ready_addr,
             chain_send_buffer_addr);
    _applog(4,tmp42,false);
  }
  send_counter = 0;
  do {
    uVar1 = read_axi_fpga(chain_send_fifo_status_addr);
    uVar1 = uVar1 >> bit_shift_num & 0xff;
    if (uVar1 == 0xff) {
      pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + which_chain));
      return 0;
    }
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: waiting fpga uart%d clear send fifo space ...\n","clear_uart_send_fifo",
               (uint)which_chain);
      _applog(2,tmp42,false);
    }
    usleep(3000);
    send_counter = send_counter + 1;
  } while (send_counter < 0x15);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s: uart%d always dose not has enough send fifo space, break\n","clear_uart_send_fifo",
             (uint)which_chain);
    _applog(2,tmp42,false);
  }
  pthread_mutex_unlock((pthread_mutex_t *)(uart_send_mutex + which_chain));
  return uVar1;
}




uint clear_uart_rx_fifo(uchar which_chain)

{
  uint uVar1;
  uchar *buf_00;
  uint uVar2;
  uchar which_chain_local;
  char tmp42 [1024];
  uchar *buf;
  uint nbytes;
  uint len;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","clear_uart_rx_fifo");
    _applog(2,tmp42,false);
  }
  pthread_mutex_lock((pthread_mutex_t *)(uart_receive_mutex + which_chain));
  uVar1 = check_how_many_uart_data_in_fpga(which_chain);
  if (uVar1 == 0) {
    pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + which_chain));
    uVar1 = 0;
  }
  else {
    buf_00 = (uchar *)malloc(uVar1);
    if (buf_00 == (uchar *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"%s: uart%d malloc buffer error\n","clear_uart_rx_fifo",(uint)which_chain);
        _applog(2,tmp42,false);
      }
      usleep(500000);
      pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + which_chain));
      uVar1 = 1;
    }
    else {
      uVar2 = read_uart_data_in_fpga(which_chain,buf_00,uVar1);
      if (uVar2 == uVar1) {
        free(buf_00);
        usleep(10000);
        pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + which_chain));
        uVar1 = 1;
      }
      else {
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          snprintf(tmp42,0x400,"%s: uart%d clear rx fifo error. nbytes = %d, len = %d\n","clear_uart_rx_fifo",
                   (uint)which_chain,uVar1,uVar2);
          _applog(2,tmp42,false);
        }
        free(buf_00);
        usleep(10000);
        pthread_mutex_unlock((pthread_mutex_t *)(uart_receive_mutex + which_chain));
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}




int baud2bt8d(uint baud)

{
  uint baud_local;
  uchar bt8d;
  
  if (baud == 0xe1000) {
    bt8d = '\x02';
  }
  else if (baud < 0xe1001) {
    if (baud == 0x1c200) {
      bt8d = '\x1a';
    }
    else {
      if (baud != 0x70800) {
LAB_0001f802:
        printf("%s: the baud is not recommand value, so use 115200 baud\n","baud2bt8d");
        return -1;
      }
      bt8d = '\x06';
    }
  }
  else if (baud == 1500000) {
    bt8d = '\x01';
  }
  else {
    if (baud != 3000000) goto LAB_0001f802;
    bt8d = '\0';
  }
  return (uint)bt8d;
}




int cgpu_init(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int ret;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","cgpu_init");
    _applog(2,tmp42,false);
  }
  memset(&cgpu,0,0x60);
  iVar1 = open_lcd();
  if (iVar1 < 1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"!!! %s: open lcd driver error\n","cgpu_init");
      _applog(2,tmp42,false);
    }
  }
  else {
    memset(lcd_output,0x20,0x40);
    write(cgpu.lcd_fd,lcd_output,0x40);
    iVar1 = open_key();
    if (iVar1 < 1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"!!! %s: open start key error\n","cgpu_init");
        _applog(2,tmp42,false);
      }
    }
    else {
      iVar1 = open_red_led();
      if (iVar1 < 1) {
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          snprintf(tmp42,0x400,"!!! %s: open red led error\n","cgpu_init");
          _applog(2,tmp42,false);
        }
      }
      else {
        iVar1 = open_green_led();
        if (iVar1 < 1) {
          if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
            snprintf(tmp42,0x400,"!!! %s: open green led error\n","cgpu_init");
            _applog(2,tmp42,false);
          }
        }
        else {
          iVar1 = bitmain_axi_init();
          if (-1 < iVar1) {
            cgpu.runtime = runtime;
            patten_info_init();
            patten_load("/mnt/card/");
            return 0;
          }
          bitmain_axi_close();
        }
        close_green_led();
      }
      close_red_led();
    }
    close_key();
  }
  close_lcd();
  return -1;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void cgpu_exit(void)

{
  bitmain_axi_close();
  close_green_led();
  close_red_led();
  close_key();
  close_lcd();
  patten_info_destory();
  return;
}




int v9_key_read(char *command,int len)

{
  ssize_t sVar1;
  int len_local;
  char *command_local;
  
  lseek(cgpu.key_fd,0,0);
  sVar1 = read(cgpu.key_fd,command,len);
  return sVar1;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void display_arguments(void)

{
  size_t __n;
  char *__src;
  char output [4] [16];
  
  memset(output,0,0x40);
  lseek(cgpu.lcd_fd,0,0);
  memset(output,0x20,0x40);
  __src = app_conf->name;
  __n = strlen(app_conf->name);
  memcpy(output,__src,__n);
  sprintf(output[1],"IC:%2d",app_conf->asic_num);
  sprintf(output[2],"FREQ: %d",app_conf->pcba_freq);
  sprintf(output[3],"Voltage: %d",app_conf->pcba_voltage);
  write(cgpu.lcd_fd,output,0x40);
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void init_pcba_args(void)

{
  runtime_base_t *prVar1;
  runtime_base_t *runtime;
  int i;
  
  prVar1 = cgpu.runtime;
  for (i = 0; i < 1; i = i + 1) {
    prVar1->chain_status[i].real_asic_num = 0;
  }
  for (i = 0; i < 3; i = i + 1) {
    chip_temp[i] = '\0';
    pcb_temp[i] = '\0';
  }
  gChain = 0xff;
  pcb_high = '\0';
  chip_high = '\0';
  return;
}




/* WARNING: Unknown calling convention */

int check_chain(void)

{
  uint uVar1;
  int iVar2;
  char tmp42 [1024];
  int ret;
  uchar which_chain;
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"--- %s\n","check_chain");
    _applog(2,tmp42,false);
  }
  cgpu.chain_num = 0;
  uVar1 = read_axi_fpga(2);
  if (((uVar1 == 1) || (uVar1 == 2)) || ((uVar1 == 4 || (uVar1 == 8)))) {
    which_chain = '\0';
    while (which_chain == '\0') {
      chain_info[0].which_chain = '\0';
      chain_info[0].which_i2c = '\0';
      if ((uVar1 & 1) == 0) {
        cgpu.chain_exist[0] = 0;
      }
      else {
        cgpu.chain_exist[0] = 1;
        cgpu.chain_num = cgpu.chain_num + 1;
        gChain = which_chain;
        (cgpu.runtime)->chain_id = 0;
        gI2c = '\0';
        chain_info[0].which_chain = '\0';
        chain_info[0].which_i2c = '\0';
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          snprintf(tmp42,0x400,"%s: gChain = %d, gI2c = %d\n","check_chain",(uint)gChain,0);
          _applog(2,tmp42,false);
        }
      }
      which_chain = '\x01';
    }
    iVar2 = 0;
  }
  else {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: Test zhiju only support 1 plug, but now is 0x%08x\n","check_chain",uVar1);
      _applog(2,tmp42,false);
    }
    iVar2 = -1;
  }
  return iVar2;
}




/* WARNING: Unknown calling convention */

void * read_all_sensor(void)

{
  runtime_base_t *runtime_00;
  int iVar1;
  int chip_addr_00;
  char tmp42 [1024];
  int chip_addr;
  runtime_base_t *runtime;
  int high_temp_alarm_counter;
  int pcb_high_temp;
  int chip_high_temp;
  int which_asic;
  int i;
  
  runtime_00 = cgpu.runtime;
  high_temp_alarm_counter = 0;
  while (runtime_00->start_recv != 0) {
    for (i = 0; i < runtime_00->sensor_num; i = i + 1) {
      iVar1 = runtime_00->sensor_pos[i];
      chip_addr_00 = iVar1 * runtime_00->addr_interval;
      user_read_iic(runtime_00,chip_addr_00,'L','\x01',chip_temp + iVar1,1);
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"ASIC %d chip temp %d\n",iVar1,(uint)chip_temp[iVar1]);
        _applog(2,tmp42,false);
      }
      user_read_iic(runtime_00,chip_addr_00,'L','\0',pcb_temp + iVar1,1);
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"ASIC %d pcb temp %d\n",iVar1,(uint)pcb_temp[iVar1]);
        _applog(2,tmp42,false);
      }
    }
    pcb_high_temp = 0;
    chip_high_temp = 0;
    for (which_asic = 0; which_asic < 3; which_asic = which_asic + 1) {
      if ((uint)chip_high_temp < (uint)chip_temp[which_asic]) {
        chip_high_temp = (int)chip_temp[which_asic];
      }
      if ((uint)pcb_high_temp < (uint)pcb_temp[which_asic]) {
        pcb_high_temp = (int)pcb_temp[which_asic];
      }
    }
    chip_high = (uint8_t)chip_high_temp;
    pcb_high = (uint8_t)pcb_high_temp;
    if (app_conf->pcba_tempture_high < chip_high_temp) {
      high_temp_alarm_counter = high_temp_alarm_counter + 1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"temperature alarm counter %d\n",high_temp_alarm_counter);
        _applog(2,tmp42,false);
      }
      if (1 < high_temp_alarm_counter) {
        hardware_exception = 1;
      }
    }
    else {
      high_temp_alarm_counter = 0;
    }
    sleep(2);
  }
  return (void *)0x0;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void start_read_temp(void)

{
  user_i2c_enable(cgpu.runtime,gChain);
  usleep(50000);
  pthread_create(&cgpu.read_temp,(pthread_attr_t *)0x0,(__start_routine *)0x1ff09,(void *)0x0);
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void stop_read_temp(void)

{
  pthread_cancel(cgpu.read_temp);
  pthread_join(cgpu.read_temp,(void **)0x0);
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void show_result(void)

{
  runtime_base_t *prVar1;
  int iVar2;
  char tmp42 [1024];
  int which_asic;
  runtime_base_t *runtime;
  int i;
  
  prVar1 = cgpu.runtime;
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    memcpy(tmp42,"---------------------------------result-----------------------------------------------\n",0x58);
    _applog(2,tmp42,false);
  }
  read_temp_test_result = 1;
  for (i = 0; i < prVar1->sensor_num; i = i + 1) {
    iVar2 = prVar1->sensor_pos[i];
    if (((int)(uint)chip_temp[iVar2] < app_conf->pcba_tempture_low) ||
       (app_conf->pcba_tempture_high < (int)(uint)chip_temp[iVar2])) {
      if ((use_syslog != false) || ((opt_log_output != false || (-1 < opt_log_level)))) {
        snprintf(tmp42,0x400,"Sensor %d CHIP temp wrong!\n",prVar1->sensor_pos[0] + 1);
        _applog(0,tmp42,false);
      }
      read_temp_test_result = -1;
    }
    if (((int)(uint)pcb_temp[iVar2] < app_conf->pcba_tempture_low) ||
       (app_conf->pcba_tempture_high < (int)(uint)pcb_temp[iVar2])) {
      if ((use_syslog != false) || ((opt_log_output != false || (-1 < opt_log_level)))) {
        snprintf(tmp42,0x400,"Sensor %d PCB temp wrong!\n",prVar1->sensor_pos[0] + 1);
        _applog(0,tmp42,false);
      }
      read_temp_test_result = -1;
    }
  }
  if (read_temp_test_result < 1) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"Sensor NG.\n",0xc);
      _applog(2,tmp42,false);
    }
  }
  else if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    builtin_strncpy(tmp42,"Sensor OK.\n",0xc);
    _applog(2,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"Expect pass rate: %d, real pattern rate: %.2f\n",app_conf->pcba_pattern_pass_rate,
             (double)(g_patten.total_rate * 100.0));
    _applog(2,tmp42,false);
  }
  if (app_conf->pcba_enable_level == 1) {
    pattern_result = 1;
    if ((double)(g_patten.total_rate * 100.0) < *app_conf->pcba_level_rate) {
      if ((double)(g_patten.total_rate * 100.0) < app_conf->pcba_level_rate[1]) {
        if ((double)(g_patten.total_rate * 100.0) < app_conf->pcba_level_rate[2]) {
          pattern_level = 4;
          pattern_result = -1;
          if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
            builtin_strncpy(tmp42,"Pattern NG.\n",0xc);
            tmp42[0xc] = '\0';
            _applog(2,tmp42,false);
          }
        }
        else {
          pattern_level = 3;
          if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
            builtin_strncpy(tmp42,"Pattern OK.\n",0xc);
            tmp42[0xc] = '\0';
            _applog(2,tmp42,false);
          }
        }
      }
      else {
        pattern_level = 2;
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          builtin_strncpy(tmp42,"Pattern OK.\n",0xc);
          tmp42[0xc] = '\0';
          _applog(2,tmp42,false);
        }
      }
    }
    else {
      pattern_level = 1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        builtin_strncpy(tmp42,"Pattern OK.\n",0xc);
        tmp42[0xc] = '\0';
        _applog(2,tmp42,false);
      }
    }
  }
  else {
    pattern_level = 1;
    if (g_patten.total_rate * 100.0 < (float)(longlong)app_conf->pcba_pattern_pass_rate) {
      pattern_result = -1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        builtin_strncpy(tmp42,"Pattern NG.\n",0xc);
        tmp42[0xc] = '\0';
        _applog(2,tmp42,false);
      }
    }
    else {
      pattern_result = 1;
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        builtin_strncpy(tmp42,"Pattern OK.\n",0xc);
        tmp42[0xc] = '\0';
        _applog(2,tmp42,false);
      }
    }
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    memcpy(tmp42,"--------------------------------------------------------------------------------------\n",0x58);
    _applog(2,tmp42,false);
  }
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void V9_print_lcd(void)

{
  char level_str [17];
  char str [17];
  
  str[0] = '\0';
  str[1] = '\0';
  str[2] = '\0';
  str[3] = '\0';
  str[4] = '\0';
  str[5] = '\0';
  str[6] = '\0';
  str[7] = '\0';
  str[8] = '\0';
  str[9] = '\0';
  str[10] = '\0';
  str[0xb] = '\0';
  str[0xc] = '\0';
  str[0xd] = '\0';
  str[0xe] = '\0';
  str[0xf] = '\0';
  str[0x10] = '\0';
  show_result();
  sprintf(str,"Pattern %d %d %d   ",*g_patten.asic_recv_nonces,g_patten.asic_recv_nonces[1],g_patten.asic_recv_nonces[2]
         );
  write_lcd(0,str,0x10);
  if (pattern_result < 1) {
    write_lcd_no_memset(1,"Pattern NG      ",0x10);
  }
  else {
    write_lcd_no_memset(1,"Pattern OK      ",0x10);
  }
  if (read_temp_test_result < 1) {
    write_lcd_no_memset(2,"Sensor NG       ",0x10);
  }
  else {
    write_lcd_no_memset(2,"Sensor OK       ",0x10);
  }
  level_str[0] = '\0';
  level_str[1] = '\0';
  level_str[2] = '\0';
  level_str[3] = '\0';
  level_str[4] = '\0';
  level_str[5] = '\0';
  level_str[6] = '\0';
  level_str[7] = '\0';
  level_str[8] = '\0';
  level_str[9] = '\0';
  level_str[10] = '\0';
  level_str[0xb] = '\0';
  level_str[0xc] = '\0';
  level_str[0xd] = '\0';
  level_str[0xe] = '\0';
  level_str[0xf] = '\0';
  level_str[0x10] = '\0';
  sprintf(level_str,"    Level %d     ",pattern_level);
  write_lcd_no_memset(3,level_str,0x10);
  return;
}




void V9_print_lcd_type(int type)

{
  int type_local;
  
  if (type == -1) {
    write_lcd_no_memset(0," hardware error ",0x10);
    write_lcd_no_memset(1,"     check      ",0x10);
    write_lcd_no_memset(2," u2 u44 u16 u23 ",0x10);
    write_lcd_no_memset(3," u30            ",0x10);
  }
  else {
    V9_print_lcd();
  }
  return;
}




int is_asic_pass(int index)

{
  int index_local;
  
  return 1;
}




/* WARNING: Unknown calling convention */

void * show_stats_func_z15_3chips(void)

{
  size_t sVar1;
  char str [16];
  int len;
  int time_counter;
  
  time_counter = 0;
  do {
    memset(lcd_output,0x20,0x40);
    sprintf(lcd_output[0],"time %ds",time_counter);
    str[0] = '\0';
    str[1] = '\0';
    str[2] = '\0';
    str[3] = '\0';
    str[4] = '\0';
    str[5] = '\0';
    str[6] = '\0';
    str[7] = '\0';
    str[8] = '\0';
    str[9] = '\0';
    str[10] = '\0';
    str[0xb] = '\0';
    str[0xc] = '\0';
    str[0xd] = '\0';
    str[0xe] = '\0';
    str[0xf] = '\0';
    sprintf(str,"nonce=%d %d %d",*g_patten.asic_recv_nonces,g_patten.asic_recv_nonces[1],g_patten.asic_recv_nonces[2]);
    sVar1 = strlen(str);
    memset(str + sVar1,0x20,0x10 - sVar1);
    lcd_output[1][0] = str[0];
    lcd_output[1][1] = str[1];
    lcd_output[1][2] = str[2];
    lcd_output[1][3] = str[3];
    lcd_output[1][4] = str[4];
    lcd_output[1][5] = str[5];
    lcd_output[1][6] = str[6];
    lcd_output[1][7] = str[7];
    lcd_output[1][8] = str[8];
    lcd_output[1][9] = str[9];
    lcd_output[1][10] = str[10];
    lcd_output[1][0xb] = str[0xb];
    lcd_output[1][0xc] = str[0xc];
    lcd_output[1][0xd] = str[0xd];
    lcd_output[1][0xe] = str[0xe];
    lcd_output[1][0xf] = str[0xf];
    sprintf(lcd_output[2],"chip: %d\'C      ",(uint)chip_high);
    sprintf(lcd_output[3],"pcb : %d\'C      ",(uint)pcb_high);
    time_counter = time_counter + 1;
    write(cgpu.lcd_fd,lcd_output,0x40);
    usleep(1000000);
  } while( true );
}




/* WARNING: Unknown calling convention */

int bm1744_hashboard_init(void)

{
  runtime_base_t *runtime_00;
  int iVar1;
  char tmp42 [1024];
  runtime_base_t *runtime;
  
  runtime_00 = cgpu.runtime;
  fan_control('\x05');
  check_asic_num(runtime_00);
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s: Check ASIC number: chain %d has %d asic\n","bm1744_hashboard_init",runtime_00->chain_id,
             runtime_00->chain_status[runtime_00->chain_id].real_asic_num);
    _applog(2,tmp42,false);
  }
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s: Expect ASIC number: %d\n","bm1744_hashboard_init",
             runtime_00->chain_status[runtime_00->chain_id].design_asic_num);
    _applog(2,tmp42,false);
  }
  if (runtime_00->chain_status[runtime_00->chain_id].real_asic_num ==
      runtime_00->chain_status[runtime_00->chain_id].design_asic_num) {
    if (app_conf->pcba_only_find_asic == 0) {
      set_asic_address(runtime_00,gChain);
      user_i2c_enable(cgpu.runtime,gChain);
      (*runtime_00->set_core_timeout)(runtime_00->chain_status[gChain].fd,app_conf->core_timeout);
      usleep(10000);
      (*runtime_00->set_ticket_mask)(runtime_00->chain_status[gChain].fd,app_conf->ticket_mask);
      usleep(10000);
      (*runtime_00->set_frequency)(runtime_00->chain_status[gChain].fd,app_conf->pcba_freq);
      usleep(10000);
      (*runtime_00->set_nonce_shift)(runtime_00->chain_status[gChain].fd,0,&runtime_00->nonce_shift);
      usleep(10000);
      puts("re read asic address:");
      (*runtime_00->read_register)(runtime_00->chain_status[runtime_00->chain_id].fd,1,'\0','\0');
      iVar1 = 0;
    }
    else {
      write_lcd(0,"Find all ASIC!  ",0x10);
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        builtin_strncpy(tmp42,"Find all ASI",0xc);
        tmp42[0xc] = 'C';
        tmp42[0xd] = '\n';
        tmp42[0xe] = '\0';
        _applog(2,tmp42,false);
      }
      iVar1 = 1;
    }
  }
  else {
    memset(lcd_output,0x20,0x40);
    write_lcd(0,"Not enough ASIC!",0x10);
    sprintf(lcd_output[1],"%d ASIC",runtime_00->chain_status[runtime_00->chain_id].real_asic_num);
    write_lcd_no_memset(1,lcd_output[1],0x10);
    if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
      builtin_strncpy(tmp42,"Not enough ASIC!",0x10);
      tmp42[0x10] = '\n';
      tmp42[0x11] = '\0';
      _applog(0,tmp42,false);
    }
    iVar1 = -1;
  }
  return iVar1;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void singleboard_pattern_test(void)

{
  bool bVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char tmp42 [1024];
  int offset;
  int is_match;
  int counter_limit;
  int patten_check_interval;
  int one_patten_bin_len;
  int counter;
  int which_patten;
  int which_core;
  int which_asic;
  int i;
  
  iVar4 = g_patten.sol_bin_len + g_patten.work_bin_len + g_patten.nonce_bin_len;
  g_patten.start = 1;
  sleep(1);
  fan_control('\x05');
  which_asic = 0;
  do {
    if (g_patten.asic_num <= which_asic) {
      g_patten.start = 0;
      sleep(1);
      which_asic = 0;
      while( true ) {
        if (g_patten.asic_num <= which_asic) break;
        printf("ASIC %d result:\n",which_asic);
        iVar4 = g_patten.patten_num * which_asic * g_patten.core_num;
        for (i = 0; g_patten.patten_num * g_patten.core_num - i != 0 && i <= g_patten.patten_num * g_patten.core_num;
            i = i + 1) {
          if (g_patten.is_nonce_match[i + iVar4] == '\0') {
            uVar5 = 0x58;
          }
          else {
            uVar5 = 0x4f;
          }
          printf("%c ",uVar5);
          if (i % 10 == 9) {
            putchar(10);
          }
        }
        putchar(10);
        which_asic = which_asic + 1;
      }
      return;
    }
    for (which_core = 0; which_core < g_patten.core_num; which_core = which_core + 1) {
      for (which_patten = 0; which_patten < g_patten.patten_num; which_patten = which_patten + 1) {
        if (hardware_exception == 0) {
          pthread_mutex_lock((pthread_mutex_t *)&g_patten.patten_mutex);
          g_patten.cur_work =
               g_patten.patten_start +
               iVar4 * which_core * g_patten.patten_num + iVar4 * g_patten.patten_num * which_asic * g_patten.core_num +
               iVar4 * which_patten;
          g_patten.cur_asic = which_asic;
          g_patten.cur_core = which_core;
          g_patten.cur_patten = which_patten;
          pthread_mutex_unlock((pthread_mutex_t *)&g_patten.patten_mutex);
          user_send_work(cgpu.runtime,g_patten.cur_work,1,0);
          iVar3 = __aeabi_idiv(app_conf->send_pattern_timeout,50000);
          counter = 0;
          do {
            usleep(50000);
            pthread_mutex_lock((pthread_mutex_t *)&g_patten.patten_mutex);
            uVar2 = g_patten.is_nonce_match
                    [g_patten.cur_patten +
                     g_patten.patten_num * (g_patten.core_num * g_patten.cur_asic + g_patten.cur_core)];
            pthread_mutex_unlock((pthread_mutex_t *)&g_patten.patten_mutex);
            if (uVar2 == '\x01') break;
            bVar1 = counter < iVar3;
            counter = counter + 1;
          } while (bVar1);
          if (uVar2 != '\x01') {
            if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
              snprintf(tmp42,0x400,"pattern id %d receive failed\n",which_patten);
              _applog(2,tmp42,false);
            }
            dump_str(stderr,(char *)0x0,g_patten.cur_work,g_patten.work_bin_len);
          }
        }
        else {
          if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
            snprintf(tmp42,0x400,"%s hardware error\n","singleboard_pattern_test");
            _applog(1,tmp42,false);
          }
          which_patten = g_patten.patten_num;
          which_core = g_patten.core_num;
          which_asic = g_patten.asic_num;
        }
      }
    }
    which_asic = which_asic + 1;
  } while( true );
}




void * check_nonce(void *args)

{
  int asic_index_00;
  void *args_local;
  int nonceNum;
  nonce_rb_format nonce_tmp;
  int asic_index;
  runtime_base_t *runtime;
  
  nonceNum = 0;
  nonce_fifo_num(&nonceNum);
  while (nonceNum != 0) {
    nonceNum = nonceNum + -1;
    pop_nonce(&nonce_tmp);
    asic_index_00 = __aeabi_idiv(nonce_tmp.chip_addr,*(undefined4 *)((int)args + 0x6f0));
    is_patten_match(asic_index_00,nonce_tmp.chip_nonce,nonce_tmp.Nonce);
  }
  return (void *)0x0;
}




void * check_nonce_loop(void *args)

{
  void *args_local;
  pthread_t send_id;
  runtime_base_t *runtime;
  
  runtime = (runtime_base_t *)args;
  do {
    while (runtime->start_recv == 0) {
      usleep(100000);
    }
    pthread_create(&send_id,(pthread_attr_t *)0x0,(__start_routine *)0x21339,args);
    pthread_join(send_id,(void **)0x0);
    usleep(5000);
  } while( true );
}




int vol_init(ushort vol)

{
  uint16_t uVar1;
  int iVar2;
  ushort vol_local;
  char tmp42 [1024];
  ushort read_back;
  int which_asic;
  
  if ((vol < 0x385) && (0x2ed < vol)) {
    if (vol == 800) {
      if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"setting voltage == configed voltage %d\n",800);
        _applog(2,tmp42,false);
      }
      iVar2 = 1;
    }
    else {
      for (which_asic = 0; which_asic < 3; which_asic = which_asic + 1) {
        uVar1 = ISL_set_voltage(gChain,'\0',isl_dev_addr[which_asic],vol);
        if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
          snprintf(tmp42,0x400,"asic%d read back voltage = %d\n",which_asic,(uint)uVar1);
          _applog(2,tmp42,false);
        }
      }
      iVar2 = 0;
    }
  }
  else {
    if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"illeagel setting voltage is %d\n",(uint)vol);
      _applog(2,tmp42,false);
    }
    iVar2 = -1;
  }
  return iVar2;
}




void pcba_runtime_init(runtime_base_t *runtime)

{
  int iVar1;
  int iVar2;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int bt8d;
  int chainid;
  
  iVar2 = runtime->chain_id;
  runtime->chain_status[iVar2].design_asic_num = app_conf->asic_num;
  reg_list_init();
  work_list_init((runtime->nonce_verify_info).work_len);
  iVar1 = uart_init(runtime->chain_status[iVar2].comport,0x1c200);
  runtime->chain_status[iVar2].fd = iVar1;
  sleep(1);
  if (runtime->baudrate != 0x1c200) {
    iVar1 = baud2bt8d(runtime->baudrate);
    if (iVar1 < 1) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        builtin_strncpy(tmp42,"Don\'t support current baudrate, set to 11520",0x2c);
        tmp42[0x2c] = '0';
        tmp42[0x2d] = '\n';
        tmp42[0x2e] = '\0';
        _applog(2,tmp42,false);
      }
    }
    else {
      (*runtime->set_baud)(runtime->chain_status[iVar2].fd,runtime->baudrate);
      usleep(200000);
      set_fpga_baud((uchar)iVar1);
      sleep(1);
    }
  }
  pthread_create(&runtime->chain_status[iVar2].p_dispatch,(pthread_attr_t *)0x0,(__start_routine *)0x330a5,runtime);
  sleep(1);
  pthread_create(&runtime->p_scanhash,(pthread_attr_t *)0x0,(__start_routine *)0x213c5,runtime);
  runtime->start_recv = 1;
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s Done!\n","pcba_runtime_init");
    _applog(2,tmp42,false);
  }
  return;
}




void pcba_runtime_exit(runtime_base_t *runtime)

{
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  
  runtime->start_recv = 0;
  usleep(1000000);
  pthread_cancel(runtime->p_scanhash);
  pthread_join(runtime->p_scanhash,(void **)0x0);
  pthread_cancel(runtime->chain_status[runtime->chain_id].p_dispatch);
  pthread_join(runtime->chain_status[runtime->chain_id].p_dispatch,(void **)0x0);
  uart_exit(runtime->chain_status[runtime->chain_id].fd);
  reg_list_exit();
  work_list_exit();
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s Done!\n","pcba_runtime_exit");
    _applog(2,tmp42,false);
  }
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void start_single_board_test(void)

{
  int iVar1;
  int ret;
  
  pcba_runtime_init(cgpu.runtime);
  iVar1 = bm1744_hashboard_init();
  if (iVar1 == 0) {
    start_read_temp();
    singleboard_pattern_test();
    stop_read_temp();
  }
  pcba_runtime_exit(cgpu.runtime);
  return;
}




/* WARNING: Unknown calling convention */

int singleBoardTest_Z15_BM1746(void)

{
  int iVar1;
  char tmp42 [1024];
  
  if (((use_syslog) || (opt_log_output)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"Start %s[%d]\n","singleBoardTest_Z15_BM1746",0x2a4);
    _applog(2,tmp42,false);
  }
  init_pcba_args();
  pthread_create(&cgpu.show_id,(pthread_attr_t *)0x0,(__start_routine *)0x20a31,(void *)0x0);
  init_fpga();
  set_fpga_baud('\x1a');
  check_chain();
  if (gChain == 0xff) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"--- Chain Check Fail",0x14);
      tmp42[0x14] = '\n';
      tmp42[0x15] = '\0';
      _applog(2,tmp42,false);
    }
    iVar1 = -1;
  }
  else {
    reset_PIC16F1704_pic((uint)gChain,gI2c);
    jump_from_loader_to_app_PIC16F1704((uint)gChain,gI2c);
    pthread_create(&cgpu.pic_heart_beat_id,(pthread_attr_t *)0x0,(__start_routine *)0x1b3e9,chain_info + gChain);
    write_axi_fpga(0xd,0xffff);
    usleep(300000);
    enable_PIC16F1704_dc_dc((uint)gChain,gI2c,'\x01');
    usleep(300000);
    write_axi_fpga(0xd,0);
    vol_init((ushort)app_conf->pcba_voltage);
    usleep(300000);
    start_single_board_test();
    pthread_cancel(cgpu.show_id);
    pthread_join(cgpu.show_id,(void **)0x0);
    V9_print_lcd_type(hardware_exception);
    write_axi_fpga(0xd,0xffff);
    usleep(300000);
    write_axi_fpga(0xd,0);
    usleep(300000);
    enable_PIC16F1704_dc_dc((uint)gChain,gI2c,'\0');
    pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
    pthread_cancel(cgpu.pic_heart_beat_id);
    pthread_join(cgpu.pic_heart_beat_id,(void **)0x0);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    clear_last_test_results();
    fan_control('\x02');
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      builtin_strncpy(tmp42,"Test finishe",0xc);
      tmp42[0xc] = 'd';
      tmp42[0xd] = '\n';
      tmp42[0xe] = '\0';
      _applog(2,tmp42,false);
    }
    iVar1 = 1;
  }
  return iVar1;
}




int parse_config_ini_array(char *str,void **pointer)

{
  bool bVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  void **pointer_local;
  char *str_local;
  char item_str [32];
  int str_len;
  int i_1;
  int j;
  int item_str_counter;
  int i;
  void *local_pointer;
  int item_num;
  int type;
  
  sVar2 = strlen(str);
  bVar1 = true;
  item_num = 0;
  for (i = 0; i < (int)sVar2; i = i + 1) {
    if (str[i] == '.') {
      bVar1 = false;
    }
    if (str[i] == ',') {
      item_num = item_num + 1;
    }
  }
  iVar4 = item_num + 1;
  if (bVar1) {
    local_pointer = malloc(iVar4 * 4);
    memset(local_pointer,0,iVar4 * 4);
  }
  else {
    local_pointer = malloc(iVar4 * 8);
    memset(local_pointer,0,iVar4 * 8);
  }
  item_str_counter = 0;
  memset(item_str,0,0x20);
  j = 0;
  for (i_1 = 0; i_1 < (int)sVar2; i_1 = i_1 + 1) {
    if (((0x2f < (byte)str[i_1]) && ((byte)str[i_1] < 0x3a)) || (str[i_1] == '.')) {
      item_str[item_str_counter] = str[i_1];
      item_str_counter = item_str_counter + 1;
    }
    if ((str[i_1] == ',') || (str[i_1] == ']')) {
      item_str[item_str_counter] = '\0';
      if (bVar1) {
        iVar3 = atoi(item_str);
        *(int *)((int)local_pointer + j * 4) = iVar3;
      }
      else {
        dVar5 = atof(item_str);
        *(double *)((int)local_pointer + j * 8) = dVar5;
      }
      j = j + 1;
      memset(item_str,0x20,0x20);
      item_str_counter = 0;
    }
  }
  *pointer = local_pointer;
  return iVar4;
}




int app_config_handle(app_config_t *m_conf,char *config_filename)

{
  FILE *__stream;
  int iVar1;
  char *pcVar2;
  char *config_filename_local;
  app_config_t *m_conf_local;
  char tmp42 [1024];
  char str [1024];
  int num;
  int num_3;
  int num_2;
  int num_1;
  FILE *fd;
  char *temp;
  
  memset(str,0,0x400);
  __stream = fopen(config_filename,"r");
  if ((__stream == (FILE *)0x0) && (((use_syslog != false || (opt_log_output != false)) || (1 < opt_log_level)))) {
    snprintf(tmp42,0x400,"open %s failed\n",config_filename);
    _applog(2,tmp42,false);
  }
  do {
    do {
      pcVar2 = fgets(str,0x3ff,__stream);
      if (pcVar2 == (char *)0x0) {
        fclose(__stream);
        return 0;
      }
    } while (((str[0] == '#') || (str[1] == '#')) || (str[0] == '\0'));
    pcVar2 = strstr(str,"Name=");
    if (pcVar2 != (char *)0x0) {
      __isoc99_sscanf(pcVar2 + 5,&DAT_00036900,m_conf->name);
    }
    pcVar2 = strstr(str,"AsicNum=");
    if (pcVar2 != (char *)0x0) {
      __isoc99_sscanf(pcVar2 + 8,&DAT_00036910,&m_conf->asic_num);
    }
    pcVar2 = strstr(str,"CoreNum=");
    if (pcVar2 == (char *)0x0) {
      pcVar2 = strstr(str,"WorkMode=");
      if (pcVar2 == (char *)0x0) {
        pcVar2 = strstr(str,"Comport=");
        if (pcVar2 == (char *)0x0) {
          pcVar2 = strstr(str,"SensorPos=");
          if (pcVar2 == (char *)0x0) {
            pcVar2 = strstr(str,"EnableCp210x=");
            if (pcVar2 == (char *)0x0) {
              pcVar2 = strstr(str,"Baudrate=");
              if (pcVar2 == (char *)0x0) {
                pcVar2 = strstr(str,"TicketMask=");
                if (pcVar2 == (char *)0x0) {
                  pcVar2 = strstr(str,"CoreTimeout=");
                  if (pcVar2 == (char *)0x0) {
                    pcVar2 = strstr(str,"ChipAlarmTemp=");
                    if (pcVar2 == (char *)0x0) {
                      pcVar2 = strstr(str,"BringupFreq=");
                      if (pcVar2 == (char *)0x0) {
                        pcVar2 = strstr(str,"BringupVoltage=");
                        if (pcVar2 == (char *)0x0) {
                          pcVar2 = strstr(str,"BringupWorkIntervalS=");
                          if (pcVar2 == (char *)0x0) {
                            pcVar2 = strstr(str,"BringupAutoJHVolt=");
                            if (pcVar2 == (char *)0x0) {
                              pcVar2 = strstr(str,"BringupAutoJHFreq=");
                              if (pcVar2 == (char *)0x0) {
                                pcVar2 = strstr(str,"PattenNum=");
                                if (pcVar2 == (char *)0x0) {
                                  pcVar2 = strstr(str,"SltTestMode=");
                                  if (pcVar2 == (char *)0x0) {
                                    pcVar2 = strstr(str,"SltTunelPath=");
                                    if (pcVar2 == (char *)0x0) {
                                      pcVar2 = strstr(str,"SltCP210xRuntime=");
                                      if (pcVar2 == (char *)0x0) {
                                        pcVar2 = strstr(str,"SltBinRate=");
                                        if (pcVar2 == (char *)0x0) {
                                          pcVar2 = strstr(str,"SltDelay=");
                                          if (pcVar2 == (char *)0x0) {
                                            pcVar2 = strstr(str,"SltFreq=");
                                            if (pcVar2 == (char *)0x0) {
                                              pcVar2 = strstr(str,"SltWorkIntervalMs=");
                                              if (pcVar2 == (char *)0x0) {
                                                pcVar2 = strstr(str,"SltEnableReadTemp=");
                                                if (pcVar2 == (char *)0x0) {
                                                  pcVar2 = strstr(str,"PcbaRepeatCtrl=");
                                                  if (pcVar2 == (char *)0x0) {
                                                    pcVar2 = strstr(str,"PcbaFreq=");
                                                    if (pcVar2 == (char *)0x0) {
                                                      pcVar2 = strstr(str,"PcbaVoltage=");
                                                      if (pcVar2 == (char *)0x0) {
                                                        pcVar2 = strstr(str,"PcbaTemptureHigh=");
                                                        if (pcVar2 == (char *)0x0) {
                                                          pcVar2 = strstr(str,"PcbaTemptureLow=");
                                                          if (pcVar2 == (char *)0x0) {
                                                            pcVar2 = strstr(str,"PcbaOnlyFindASIC=");
                                                            if (pcVar2 == (char *)0x0) {
                                                              pcVar2 = strstr(str,"PcbaPatternPassRate=");
                                                              if (pcVar2 == (char *)0x0) {
                                                                pcVar2 = strstr(str,"PcbaSendPtTimeout=");
                                                                if (pcVar2 == (char *)0x0) {
                                                                  pcVar2 = strstr(str,"PcbaEnableLevel=");
                                                                  if (pcVar2 == (char *)0x0) {
                                                                    pcVar2 = strstr(str,"PcbaLevelRate=");
                                                                    if ((pcVar2 != (char *)0x0) &&
                                                                       (iVar1 = parse_config_ini_array
                                                                                          (pcVar2 + 0xe,
                                                                                           &m_conf->pcba_level_rate),
                                                                       iVar1 != 3)) {
                                                                      if ((use_syslog != false) ||
                                                                         ((opt_log_output != false ||
                                                                          (1 < opt_log_level)))) {
                                                                        snprintf(tmp42,0x400,
                                                                                                                                                                  
                                                            "PcbaLevelRate number should be 3, but not %d\n",iVar1);
                                                            _applog(2,tmp42,false);
                                                            }
                                                            return -1;
                                                            }
                                                            }
                                                            else {
                                                              __isoc99_sscanf(pcVar2 + 0x10,&DAT_00036910,
                                                                              &m_conf->pcba_enable_level);
                                                            }
                                                            }
                                                            else {
                                                              __isoc99_sscanf(pcVar2 + 0x12,&DAT_00036910,
                                                                              &m_conf->send_pattern_timeout);
                                                            }
                                                            }
                                                            else {
                                                              __isoc99_sscanf(pcVar2 + 0x14,&DAT_00036910,
                                                                              &m_conf->pcba_pattern_pass_rate);
                                                            }
                                                            }
                                                            else {
                                                              __isoc99_sscanf(pcVar2 + 0x11,&DAT_00036910,
                                                                              &m_conf->pcba_only_find_asic);
                                                            }
                                                          }
                                                          else {
                                                            __isoc99_sscanf(pcVar2 + 0x10,&DAT_00036910,
                                                                            &m_conf->pcba_tempture_low);
                                                          }
                                                        }
                                                        else {
                                                          __isoc99_sscanf(pcVar2 + 0x11,&DAT_00036910,
                                                                          &m_conf->pcba_tempture_high);
                                                        }
                                                      }
                                                      else {
                                                        __isoc99_sscanf(pcVar2 + 0xc,&DAT_00036910,&m_conf->pcba_voltage
                                                                       );
                                                      }
                                                    }
                                                    else {
                                                      __isoc99_sscanf(pcVar2 + 9,&DAT_00036910,&m_conf->pcba_freq);
                                                    }
                                                  }
                                                  else {
                                                    __isoc99_sscanf(pcVar2 + 0xf,&DAT_00036900,m_conf->pcba_repeat_ctrl)
                                                    ;
                                                  }
                                                }
                                                else {
                                                  __isoc99_sscanf(pcVar2 + 0x12,&DAT_00036910,
                                                                  &m_conf->slt_enable_read_temp);
                                                }
                                              }
                                              else {
                                                __isoc99_sscanf(pcVar2 + 0x12,&DAT_00036910,
                                                                &m_conf->slt_work_interval_ms);
                                              }
                                            }
                                            else {
                                              __isoc99_sscanf(pcVar2 + 8,&DAT_00036910,&m_conf->slt_freq);
                                            }
                                          }
                                          else {
                                            __isoc99_sscanf(pcVar2 + 9,&DAT_00036910,&m_conf->slt_delay);
                                          }
                                        }
                                        else {
                                          iVar1 = parse_config_ini_array(pcVar2 + 0xb,&m_conf->slt_bin_rate);
                                          if (iVar1 != 3) {
                                            if (((use_syslog != false) || (opt_log_output != false)) ||
                                               (1 < opt_log_level)) {
                                              snprintf(tmp42,0x400,"SltBinRate number error %d\n",iVar1);
                                              _applog(2,tmp42,false);
                                            }
                                            return -1;
                                          }
                                        }
                                      }
                                      else {
                                        __isoc99_sscanf(pcVar2 + 0x11,&DAT_00036900,m_conf->slt_cp210x_runtime);
                                      }
                                    }
                                    else {
                                      __isoc99_sscanf(pcVar2 + 0xd,&DAT_00036900,m_conf->slt_tunel_path);
                                    }
                                  }
                                  else {
                                    __isoc99_sscanf(pcVar2 + 0xc,&DAT_00036910,&m_conf->slt_test_mode);
                                  }
                                }
                                else {
                                  __isoc99_sscanf(pcVar2 + 10,&DAT_00036910,&m_conf->pattern_num);
                                }
                              }
                              else {
                                iVar1 = parse_config_ini_array(pcVar2 + 0x12,&m_conf->bringup_autojh_freq);
                                if (iVar1 != 3) {
                                  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
                                    snprintf(tmp42,0x400,"BringupAutoJHFreq number error %d\n",iVar1);
                                    _applog(2,tmp42,false);
                                  }
                                  return -1;
                                }
                              }
                            }
                            else {
                              iVar1 = parse_config_ini_array(pcVar2 + 0x12,&m_conf->bringup_autojh_volt);
                              if (iVar1 != 3) {
                                if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
                                  snprintf(tmp42,0x400,"BringupAutoJHVolt number error %d\n",iVar1);
                                  _applog(2,tmp42,false);
                                }
                                return -1;
                              }
                            }
                          }
                          else {
                            __isoc99_sscanf(pcVar2 + 0x15,&DAT_00036910,&m_conf->bringup_work_interval_s);
                          }
                        }
                        else {
                          __isoc99_sscanf(pcVar2 + 0xf,&DAT_00036910,&m_conf->bringup_voltage);
                        }
                      }
                      else {
                        __isoc99_sscanf(pcVar2 + 0xc,&DAT_00036910,&m_conf->bringup_freq);
                      }
                    }
                    else {
                      __isoc99_sscanf(pcVar2 + 0xe,&DAT_00036910,&m_conf->chip_alarm_temp);
                    }
                  }
                  else {
                    __isoc99_sscanf(pcVar2 + 0xc,&DAT_0003697c,&m_conf->core_timeout);
                  }
                }
                else {
                  __isoc99_sscanf(pcVar2 + 0xb,&DAT_00036910,&m_conf->ticket_mask);
                }
              }
              else {
                __isoc99_sscanf(pcVar2 + 9,&DAT_00036910,&m_conf->baudrate);
              }
            }
            else {
              __isoc99_sscanf(pcVar2 + 0xd,&DAT_00036910,&m_conf->enable_cp210x);
            }
          }
          else {
            iVar1 = parse_config_ini_array(pcVar2 + 10,&m_conf->sensor_pos);
            m_conf->sensor_num = iVar1;
          }
        }
        else {
          iVar1 = parse_config_ini_array(pcVar2 + 8,&m_conf->comport);
          m_conf->comport_num = iVar1;
        }
      }
      else {
        __isoc99_sscanf(pcVar2 + 9,&DAT_00036910,&m_conf->work_mode);
      }
    }
    else {
      __isoc99_sscanf(pcVar2 + 8,&DAT_00036910,&m_conf->core_num);
    }
    memset(str,0,0x400);
  } while( true );
}




app_config_t * app_config_init(char *config_filename)

{
  app_config_t *m_conf;
  int iVar1;
  FILE *pFVar2;
  char *config_filename_local;
  char tmp42 [1024];
  char dbg_fname [32];
  app_config_t *app_conf;
  
  m_conf = (app_config_t *)calloc(0x128,1);
  iVar1 = app_config_handle(m_conf,config_filename);
  if (iVar1 < 0) {
    m_conf = (app_config_t *)0x0;
  }
  else {
    memset(dbg_fname,0,0x20);
    sprintf(dbg_fname,"%s.log",m_conf->name);
    pFVar2 = fopen(dbg_fname,"w+");
    m_conf->dbg_fp = (FILE *)pFVar2;
    if (m_conf->dbg_fp == (FILE *)0x0) {
      if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
        snprintf(tmp42,0x400,"open %s file error\n",dbg_fname);
        _applog(2,tmp42,false);
      }
      m_conf = (app_config_t *)0x0;
    }
  }
  return m_conf;
}




void app_config_exit(app_config_t *conf)

{
  app_config_t *conf_local;
  
  fclose((FILE *)conf->dbg_fp);
  free(conf->comport);
  free(conf->sensor_pos);
  free(conf->bringup_autojh_freq);
  free(conf->bringup_autojh_volt);
  free(conf->slt_bin_rate);
  free(conf->pcba_level_rate);
  free(conf);
  return;
}




void my_log_curses(int prio,char *datetime,char *str,_Bool force)

{
  _Bool force_local;
  char *str_local;
  char *datetime_local;
  int prio_local;
  
  if ((!opt_quiet) || (prio == 0)) {
    if (force) {
      pthread_mutex_trylock((pthread_mutex_t *)&console_lock);
      pthread_mutex_unlock((pthread_mutex_t *)&console_lock);
    }
    pthread_mutex_lock((pthread_mutex_t *)&console_lock);
    if (prio == 0) {
      fprintf(stderr,"\x1b[0;31m%s%s\x1b[0m",datetime,str);
    }
    else if (prio == 1) {
      fprintf(stderr,"\x1b[1;34m%s%s\x1b[0m",datetime,str);
    }
    else {
      fprintf(stderr,"%s%s",datetime,str);
    }
    fflush(stderr);
    pthread_mutex_unlock((pthread_mutex_t *)&console_lock);
  }
  return;
}




void _applog(int prio,char *str,_Bool force)

{
  tm *ptVar1;
  int iVar2;
  _Bool force_local;
  char *str_local;
  int prio_local;
  char datetime [64];
  time_t tmp_time;
  timeval tv;
  tm *tm;
  int ms;
  
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  gettimeofday((timeval *)&tv,(__timezone_ptr_t)0x0);
  tmp_time = tv.tv_sec;
  iVar2 = tv.tv_usec / 1000;
  ptVar1 = localtime(&tmp_time);
  snprintf(datetime,0x40," [%d-%02d-%02d %02d:%02d:%02d.%03d] ",ptVar1->tm_year + 0x76c,ptVar1->tm_mon + 1,
           ptVar1->tm_mday,ptVar1->tm_hour,ptVar1->tm_min,ptVar1->tm_sec,iVar2);
  if (app_conf->dbg_fp != (FILE *)0x0) {
    iVar2 = fileno((FILE *)app_conf->dbg_fp);
    iVar2 = isatty(iVar2);
    if (iVar2 == 0) {
      fprintf((FILE *)app_conf->dbg_fp,"%s%s",datetime,str);
      fflush((FILE *)app_conf->dbg_fp);
    }
  }
  if (app_conf->work_mode != 1) {
    my_log_curses(prio,datetime,str,force);
  }
  return;
}




void _simplelog(int prio,char *str,_Bool force)

{
  int iVar1;
  _Bool force_local;
  char *str_local;
  int prio_local;
  
  iVar1 = fileno(stderr);
  iVar1 = isatty(iVar1);
  if (iVar1 == 0) {
    fprintf(stderr,"%s\n",str);
    fflush(stderr);
  }
  my_log_curses(prio,"",str,force);
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void patten_info_init(void)

{
  int one_patten_bin_len;
  
  memset(&g_patten,0,0x9c);
  g_patten.asic_num = app_conf->asic_num;
  g_patten.core_num = app_conf->core_num;
  g_patten.patten_num = app_conf->pattern_num;
  builtin_strncpy(g_patten.dir_root,"pattern",8);
  builtin_strncpy(g_patten.dir_algo,"zec-z15",8);
  builtin_strncpy(g_patten.dir_asic,"asic",4);
  g_patten.dir_asic[4] = '\0';
  builtin_strncpy(g_patten.file_core,"core",4);
  g_patten.file_core[4] = '\0';
  g_patten.work_bin_len = 0x8c;
  g_patten.nonce_bin_len = 4;
  g_patten.sol_bin_len = 0x540;
  g_patten.total_pattens = g_patten.patten_num * g_patten.core_num * g_patten.asic_num;
  g_patten.patten_start = (uchar *)malloc(g_patten.patten_num * g_patten.core_num * g_patten.asic_num * 0x5d0);
  if (g_patten.patten_start == (uchar *)0x0) {
    printf("%s[%d] malloc failed\n","patten_info_init",0x1d);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  memset(g_patten.patten_start,0,g_patten.patten_num * g_patten.core_num * g_patten.asic_num * 0x5d0);
  g_patten.is_nonce_match = (uchar *)malloc(g_patten.patten_num * g_patten.core_num * g_patten.asic_num);
  if (g_patten.is_nonce_match == (uchar *)0x0) {
    printf("%s[%d] malloc failed\n","patten_info_init",0x23);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  memset(g_patten.is_nonce_match,0,g_patten.patten_num * g_patten.core_num * g_patten.asic_num);
  g_patten.asic_recv_nonces = (int *)malloc(g_patten.asic_num << 2);
  if (g_patten.asic_recv_nonces == (int *)0x0) {
    printf("%s[%d] malloc failed\n","patten_info_init",0x29);
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  memset(g_patten.asic_recv_nonces,0,g_patten.asic_num << 2);
  pthread_mutex_init((pthread_mutex_t *)&g_patten.patten_mutex,(pthread_mutexattr_t *)0x0);
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void patten_info_destory(void)

{
  if (g_patten.patten_start != (uchar *)0x0) {
    free(g_patten.patten_start);
  }
  if (g_patten.is_nonce_match != (uchar *)0x0) {
    free(g_patten.is_nonce_match);
  }
  if (g_patten.asic_recv_nonces != (int *)0x0) {
    free(g_patten.asic_recv_nonces);
  }
  pthread_mutex_destroy((pthread_mutex_t *)&g_patten.patten_mutex);
  return;
}




void patten_load(char *root_path)

{
  FILE *__stream;
  char *pcVar1;
  int iVar2;
  uchar *p;
  char *root_path_local;
  char fname [128];
  char buff [4096];
  char *tmp;
  uint8_t *cur_patten;
  FILE *fp_patten;
  int one_patten_bin_len;
  int which_patten;
  int which_core;
  int which_asic;
  
  iVar2 = g_patten.sol_bin_len + g_patten.work_bin_len + g_patten.nonce_bin_len;
  which_asic = 0;
  do {
    if (g_patten.asic_num <= which_asic) {
      puts("Load Patten Done");
      return;
    }
    for (which_core = 0; which_core < g_patten.core_num; which_core = which_core + 1) {
      memset(fname,0,0x80);
      sprintf(fname,"%s/%s/%s/%s-0x%02x/%s-0x%02x.txt",root_path,0x4b840,0x4b850,0x4b860,which_asic,0x4b870,which_core);
      printf("fname %s\n",fname);
      __stream = fopen(fname,"r");
      if (__stream == (FILE *)0x0) {
        printf("open %s failed\n",fname);
                    /* WARNING: Subroutine does not return */
        exit(1);
      }
      for (which_patten = 0; which_patten < g_patten.patten_num; which_patten = which_patten + 1) {
        p = g_patten.patten_start +
            iVar2 * which_core * g_patten.patten_num + iVar2 * g_patten.patten_num * which_asic * g_patten.core_num +
            iVar2 * which_patten;
        memset(buff,0,0x1000);
        fgets(buff,0x1000,__stream);
        pcVar1 = strstr(buff,"work");
        hex2bin(p,pcVar1 + 5,g_patten.work_bin_len);
        pcVar1 = strstr(buff,"nonce");
        hex2bin(p + g_patten.work_bin_len,pcVar1 + 6,g_patten.nonce_bin_len);
        pcVar1 = strstr(buff,"sol");
        hex2bin(p + g_patten.nonce_bin_len + g_patten.work_bin_len,pcVar1 + 4,g_patten.sol_bin_len);
      }
      fclose(__stream);
    }
    which_asic = which_asic + 1;
  } while( true );
}




int is_patten_match(int asic_index,uint8_t *nonce,uint8_t *sol)

{
  int iVar1;
  int iVar2;
  uint8_t *sol_local;
  uint8_t *nonce_local;
  int asic_index_local;
  int sol_ret;
  int nonce_ret;
  int ret;
  
  if (g_patten.cur_asic == asic_index) {
    pthread_mutex_lock((pthread_mutex_t *)&g_patten.patten_mutex);
    iVar1 = memcmp(g_patten.cur_work + g_patten.work_bin_len,nonce,g_patten.nonce_bin_len);
    iVar2 = memcmp(g_patten.cur_work + g_patten.nonce_bin_len + g_patten.work_bin_len,sol,g_patten.sol_bin_len);
    if ((iVar1 == 0) && (iVar2 == 0)) {
      g_patten.is_nonce_match
      [g_patten.cur_patten + g_patten.patten_num * (g_patten.core_num * g_patten.cur_asic + g_patten.cur_core)] = '\x01'
      ;
      g_patten.recv_nonces = g_patten.recv_nonces + 1;
      g_patten.total_rate = (float)(longlong)g_patten.recv_nonces / (float)(longlong)g_patten.total_pattens;
      g_patten.asic_recv_nonces[g_patten.cur_asic] = g_patten.asic_recv_nonces[g_patten.cur_asic] + 1;
      ret = 0;
    }
    else {
      dump_str(stderr,"Not Match Recv:",nonce,g_patten.nonce_bin_len);
      dump_str(stderr,"Not Match Expect:",g_patten.cur_work + g_patten.work_bin_len,g_patten.nonce_bin_len);
      ret = -1;
    }
    pthread_mutex_unlock((pthread_mutex_t *)&g_patten.patten_mutex);
  }
  else {
    printf("asic is not match %d vs %d\n",asic_index,g_patten.cur_asic);
    ret = -1;
  }
  return ret;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void display_single_board_test(void)

{
  puts("******************Display Results*******************");
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void clear_last_test_results(void)

{
  memset(g_patten.is_nonce_match,0,g_patten.patten_num * g_patten.core_num * g_patten.asic_num);
  memset(g_patten.asic_recv_nonces,0,g_patten.asic_num << 2);
  g_patten.recv_nonces = 0;
  g_patten.total_rate = 0.0;
  return;
}




uint16_t rt_ringbuffer_get_size(rt_ringbuffer *rb)

{
  rt_ringbuffer *rb_local;
  
  return rb->buffer_size;
}




RINGBUFFER_STATE rt_ringbuffer_status(rt_ringbuffer *rb)

{
  RINGBUFFER_STATE RVar1;
  rt_ringbuffer *rb_local;
  
  if (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11 == ((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) {
    if ((rb->field_0x4 & 1) == (rb->field_0x6 & 1)) {
      RVar1 = RT_RINGBUFFER_EMPTY;
    }
    else {
      RVar1 = RT_RINGBUFFER_FULL;
    }
  }
  else {
    RVar1 = RT_RINGBUFFER_HALFFULL;
  }
  return RVar1;
}




uint16_t rt_ringbuffer_data_len(rt_ringbuffer *rb)

{
  RINGBUFFER_STATE RVar1;
  uint16_t uVar2;
  rt_ringbuffer *rb_local;
  
  RVar1 = rt_ringbuffer_status(rb);
  if (RVar1 == RT_RINGBUFFER_EMPTY) {
    uVar2 = 0;
  }
  else if (RVar1 == RT_RINGBUFFER_FULL) {
    uVar2 = rb->buffer_size;
  }
  else if (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11 < ((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) {
    uVar2 = (*(ushort *)&rb->field_0x6 >> 1) - (*(ushort *)&rb->field_0x4 >> 1);
  }
  else {
    uVar2 = ((*(ushort *)&rb->field_0x6 >> 1) - (*(ushort *)&rb->field_0x4 >> 1)) + rb->buffer_size;
  }
  return uVar2;
}




void rt_ringbuffer_init(rt_ringbuffer *rb,uint8_t *pool,int16_t size,ringbuffer_type_t ringbuffer_type)

{
  ringbuffer_type_t ringbuffer_type_local;
  int16_t size_local;
  uint8_t *pool_local;
  rt_ringbuffer *rb_local;
  
  *(ushort *)&rb->field_0x4 = *(ushort *)&rb->field_0x4 & 1;
  rb->field_0x4 = rb->field_0x4 & 0xfe | (byte)(((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11) & 1;
  *(ushort *)&rb->field_0x6 = *(ushort *)&rb->field_0x6 & 1;
  rb->field_0x6 = rb->field_0x6 & 0xfe | (byte)(((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) & 1;
  rb->buffer_ptr = pool;
  rb->buffer_size = size & 0xfffc;
  rb->ringbuffer_type = ringbuffer_type;
  pthread_mutex_init((pthread_mutex_t *)&rb->ringbuf_lock,(pthread_mutexattr_t *)0x0);
  if (rb->ringbuffer_type == BLOCK_TYPE) {
    pthread_cond_init((pthread_cond_t *)&rb->notfull,(pthread_condattr_t *)0x0);
    pthread_cond_init((pthread_cond_t *)&rb->notempty,(pthread_condattr_t *)0x0);
  }
  return;
}




void rt_ringbuffer_lock_destory(rt_ringbuffer *rb)

{
  rt_ringbuffer *rb_local;
  
  pthread_mutex_destroy((pthread_mutex_t *)&rb->ringbuf_lock);
  if (rb->ringbuffer_type == BLOCK_TYPE) {
    pthread_cond_destroy((pthread_cond_t *)&rb->notfull);
    pthread_cond_destroy((pthread_cond_t *)&rb->notempty);
  }
  return;
}




uint32_t rt_ringbuffer_put(rt_ringbuffer *rb,uint8_t *ptr,uint16_t length)

{
  ushort uVar1;
  uint16_t uVar2;
  uint16_t length_local;
  uint8_t *ptr_local;
  rt_ringbuffer *rb_local;
  uint16_t size;
  
  pthread_mutex_lock((pthread_mutex_t *)&rb->ringbuf_lock);
  uVar1 = rb->buffer_size;
  uVar2 = rt_ringbuffer_data_len(rb);
  size = uVar1 - uVar2;
  if (rb->ringbuffer_type == POLL_TYPE) {
    if (size == 0) {
      pthread_mutex_unlock((pthread_mutex_t *)&rb->ringbuf_lock);
      return 0;
    }
    length_local = length;
    if (size < length) {
      length_local = size;
    }
  }
  else {
    length_local = length;
    if (rb->ringbuffer_type == BLOCK_TYPE) {
      while (size < length) {
        pthread_cond_wait((pthread_cond_t *)&rb->notfull,(pthread_mutex_t *)&rb->ringbuf_lock);
        uVar1 = rb->buffer_size;
        uVar2 = rt_ringbuffer_data_len(rb);
        size = uVar1 - uVar2;
      }
    }
  }
  if ((int)(uint)length_local < (int)((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11))) {
    memcpy(rb->buffer_ptr + (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11),ptr,(uint)length_local);
    *(ushort *)&rb->field_0x6 =
         *(ushort *)&rb->field_0x6 & 1 |
         (ushort)(((uint)length_local + (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) & 0x7fff) << 1);
    pthread_cond_signal((pthread_cond_t *)&rb->notempty);
    pthread_mutex_unlock((pthread_mutex_t *)&rb->ringbuf_lock);
  }
  else {
    memcpy(rb->buffer_ptr + (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11),ptr,
           (uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11));
    memcpy(rb->buffer_ptr,ptr + ((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11)),
           (uint)length_local - ((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11)));
    rb->field_0x6 = rb->field_0x6 & 0xfe | ~(byte)(((uint)(byte)rb->field_0x6 << 0x1f) >> 0x1f) & 1;
    *(ushort *)&rb->field_0x6 =
         *(ushort *)&rb->field_0x6 & 1 |
         (ushort)(((uint)length_local +
                   ((((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) - (uint)rb->buffer_size & 0xffff) & 0x7fff) << 1
                 );
    pthread_cond_signal((pthread_cond_t *)&rb->notempty);
    pthread_mutex_unlock((pthread_mutex_t *)&rb->ringbuf_lock);
  }
  return (uint)length_local;
}




uint32_t rt_ringbuffer_put_force(rt_ringbuffer *rb,uint8_t *ptr,uint16_t length)

{
  ushort uVar1;
  uint16_t uVar2;
  uint16_t length_local;
  uint8_t *ptr_local;
  rt_ringbuffer *rb_local;
  uint16_t space_length;
  
  pthread_mutex_lock((pthread_mutex_t *)&rb->ringbuf_lock);
  uVar1 = rb->buffer_size;
  uVar2 = rt_ringbuffer_data_len(rb);
  uVar1 = uVar1 - uVar2;
  length_local = length;
  if (uVar1 < length) {
    length_local = rb->buffer_size;
  }
  if ((int)(uint)length_local < (int)((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11))) {
    memcpy(rb->buffer_ptr + (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11),ptr,(uint)length_local);
    *(ushort *)&rb->field_0x6 =
         *(ushort *)&rb->field_0x6 & 1 |
         (ushort)(((uint)length_local + (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) & 0x7fff) << 1);
    if (uVar1 < length_local) {
      *(ushort *)&rb->field_0x4 =
           *(ushort *)&rb->field_0x4 & 1 | (ushort)((((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) << 1);
    }
    pthread_cond_signal((pthread_cond_t *)&rb->notempty);
    pthread_mutex_unlock((pthread_mutex_t *)&rb->ringbuf_lock);
  }
  else {
    memcpy(rb->buffer_ptr + (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11),ptr,
           (uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11));
    memcpy(rb->buffer_ptr,ptr + ((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11)),
           (uint)length_local - ((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11)));
    rb->field_0x6 = rb->field_0x6 & 0xfe | ~(byte)(((uint)(byte)rb->field_0x6 << 0x1f) >> 0x1f) & 1;
    *(ushort *)&rb->field_0x6 =
         *(ushort *)&rb->field_0x6 & 1 |
         (ushort)(((uint)length_local +
                   ((((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) - (uint)rb->buffer_size & 0xffff) & 0x7fff) << 1
                 );
    if (uVar1 < length_local) {
      rb->field_0x4 = rb->field_0x4 & 0xfe | ~(byte)(((uint)(byte)rb->field_0x4 << 0x1f) >> 0x1f) & 1;
      *(ushort *)&rb->field_0x4 =
           *(ushort *)&rb->field_0x4 & 1 | (ushort)((((uint)*(ushort *)&rb->field_0x6 << 0x10) >> 0x11) << 1);
    }
    pthread_cond_signal((pthread_cond_t *)&rb->notempty);
    pthread_mutex_unlock((pthread_mutex_t *)&rb->ringbuf_lock);
  }
  return (uint)length_local;
}




uint32_t rt_ringbuffer_get(rt_ringbuffer *rb,uint8_t *ptr,uint16_t length)

{
  uint16_t uVar1;
  uint16_t length_local;
  uint8_t *ptr_local;
  rt_ringbuffer *rb_local;
  uint32_t size;
  
  pthread_mutex_lock((pthread_mutex_t *)&rb->ringbuf_lock);
  uVar1 = rt_ringbuffer_data_len(rb);
  size = (uint32_t)uVar1;
  if (rb->ringbuffer_type == POLL_TYPE) {
    if (size == 0) {
      pthread_mutex_unlock((pthread_mutex_t *)&rb->ringbuf_lock);
      return 0;
    }
    length_local = length;
    if (size < length) {
      length_local = uVar1;
    }
  }
  else {
    length_local = length;
    if (rb->ringbuffer_type == BLOCK_TYPE) {
      while (size < length) {
        pthread_cond_wait((pthread_cond_t *)&rb->notempty,(pthread_mutex_t *)&rb->ringbuf_lock);
        uVar1 = rt_ringbuffer_data_len(rb);
        size = (uint32_t)uVar1;
      }
    }
  }
  if ((int)(uint)length_local < (int)((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11))) {
    memcpy(ptr,rb->buffer_ptr + (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11),(uint)length_local);
    *(ushort *)&rb->field_0x4 =
         *(ushort *)&rb->field_0x4 & 1 |
         (ushort)(((uint)length_local + (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11) & 0x7fff) << 1);
    pthread_mutex_unlock((pthread_mutex_t *)&rb->ringbuf_lock);
    pthread_cond_signal((pthread_cond_t *)&rb->notfull);
  }
  else {
    memcpy(ptr,rb->buffer_ptr + (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11),
           (uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11));
    memcpy(ptr + ((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11)),rb->buffer_ptr,
           (uint)length_local - ((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11)));
    rb->field_0x4 = rb->field_0x4 & 0xfe | ~(byte)(((uint)(byte)rb->field_0x4 << 0x1f) >> 0x1f) & 1;
    *(ushort *)&rb->field_0x4 =
         *(ushort *)&rb->field_0x4 & 1 |
         (ushort)(((uint)length_local +
                   ((((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11) - (uint)rb->buffer_size & 0xffff) & 0x7fff) << 1
                 );
    pthread_cond_signal((pthread_cond_t *)&rb->notfull);
    pthread_mutex_unlock((pthread_mutex_t *)&rb->ringbuf_lock);
  }
  return (uint)length_local;
}




uint32_t rt_ringbuffer_prefetch(rt_ringbuffer *rb,uint8_t *ptr,uint16_t length)

{
  uint16_t uVar1;
  uint32_t uVar2;
  uint16_t length_local;
  uint8_t *ptr_local;
  rt_ringbuffer *rb_local;
  uint32_t size;
  
  uVar1 = rt_ringbuffer_data_len(rb);
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else {
    length_local = length;
    if (uVar1 < length) {
      length_local = uVar1;
    }
    if ((int)(uint)length_local < (int)((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11))) {
      memcpy(ptr,rb->buffer_ptr + (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11),(uint)length_local);
      uVar2 = (uint32_t)length_local;
    }
    else {
      memcpy(ptr,rb->buffer_ptr + (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11),
             (uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11));
      memcpy(ptr + ((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11)),rb->buffer_ptr,
             (uint)length_local - ((uint)rb->buffer_size - (((uint)*(ushort *)&rb->field_0x4 << 0x10) >> 0x11)));
      uVar2 = (uint32_t)length_local;
    }
  }
  return uVar2;
}




void get_current_time(char *dtime)

{
  int iVar1;
  tm *ptVar2;
  char *dtime_local;
  time_t tmp_time;
  timeval tv;
  char datetime [64];
  tm *tm;
  int ms;
  
  tv.tv_sec = 0;
  tv.tv_usec = 0;
  gettimeofday((timeval *)&tv,(__timezone_ptr_t)0x0);
  tmp_time = tv.tv_sec;
  iVar1 = tv.tv_usec / 1000;
  ptVar2 = localtime(&tmp_time);
  snprintf(datetime,0x40," [%d-%02d-%02d %02d:%02d:%02d.%03d] ",ptVar2->tm_year + 0x76c,ptVar2->tm_mon + 1,
           ptVar2->tm_mday,ptVar2->tm_hour,ptVar2->tm_min,ptVar2->tm_sec,iVar1);
  strcpy(dtime,datetime);
  return;
}




void __bin2hex(char *s,uchar *p,size_t len)

{
  char *pcVar1;
  size_t len_local;
  uchar *p_local;
  char *s_local;
  int i;
  
  s_local = s;
  for (i = 0; i < (int)len; i = i + 1) {
    pcVar1 = s_local + 1;
    *s_local = "0123456789abcdef"[p[i] >> 4];
    s_local = s_local + 2;
    *pcVar1 = "0123456789abcdef"[p[i] & 0xf];
  }
  *s_local = '\0';
  return;
}




char * bin2hex(uchar *p,size_t len)

{
  char *s_00;
  size_t len_local;
  uchar *p_local;
  char *s;
  size_t slen;
  
  slen = len * 2 + 1;
  if ((slen & 3) != 0) {
    slen = (slen & 0xfffffffc) + 4;
  }
  s_00 = (char *)calloc(slen,1);
  if (s_00 == (char *)0x0) {
    fwrite("Failed to calloc",1,0x10,stderr);
  }
  __bin2hex(s_00,p,len);
  return s_00;
}




int hex2bin(uchar *p,char *hexstr,size_t len)

{
  byte bVar1;
  byte *pbVar2;
  size_t len_local;
  char *hexstr_local;
  uchar *p_local;
  int nibble2;
  int nibble1;
  uchar idx;
  int ret;
  
  ret = 0;
  len_local = len;
  hexstr_local = hexstr;
  p_local = p;
  while( true ) {
    if ((*hexstr_local == '\0') || (len_local == 0)) {
      if ((len_local == 0) && (*hexstr_local == '\0')) {
        ret = 1;
      }
      return ret;
    }
    if (hexstr_local[1] == '\0') {
      return 0;
    }
    pbVar2 = (byte *)(hexstr_local + 1);
    bVar1 = *hexstr_local;
    hexstr_local = hexstr_local + 2;
    if ((hex2bin_tbl[bVar1] < 0) || (hex2bin_tbl[*pbVar2] < 0)) break;
    *p_local = (byte)hex2bin_tbl[*pbVar2] | (byte)((hex2bin_tbl[bVar1] & 0xffU) << 4);
    len_local = len_local - 1;
    p_local = p_local + 1;
  }
  return 0;
}




uchar swap_bit(uchar chr)

{
  uchar chr_local;
  int i;
  uchar ret;
  
  ret = '\0';
  for (i = 0; i < 8; i = i + 1) {
    if (((int)(uint)chr >> (i & 0xffU) & 1U) != 0) {
      ret = ret | (byte)(1 << (7U - i & 0xff));
    }
  }
  return ret;
}




void dump_str(void *fdp,char *func,uchar *str,int len)

{
  char *__ptr;
  int len_local;
  uchar *str_local;
  char *func_local;
  void *fdp_local;
  char *hexbuff;
  FILE *fd;
  
  if (fdp != (void *)0x0) {
    __ptr = bin2hex(str,len);
    if (func == (char *)0x0) {
      fprintf((FILE *)fdp,"%s\n",__ptr);
    }
    else {
      fprintf((FILE *)fdp,"%s %s len=%d\n",func,__ptr,len);
    }
    fflush((FILE *)fdp);
    free(__ptr);
  }
  return;
}




uchar bit_read(uchar *y,int x)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  int x_local;
  uchar *y_local;
  
  uVar2 = x & 7;
  if (x < 1) {
    uVar2 = -(-x & 7U);
  }
  switch(uVar2) {
  case 0:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 1) != 0;
    break;
  case 1:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 2) != 0;
    break;
  case 2:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 4) != 0;
    break;
  case 3:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 8) != 0;
    break;
  case 4:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 0x10) != 0;
    break;
  case 5:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 0x20) != 0;
    break;
  case 6:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (y[iVar1 >> 3] & 0x40) != 0;
    break;
  case 7:
    iVar1 = x + 7;
    if (-1 < x) {
      iVar1 = x;
    }
    bVar3 = (bool)(y[iVar1 >> 3] >> 7);
    break;
  default:
    bVar3 = false;
  }
  return bVar3;
}




void swab256(void *dest_p,void *src_p)

{
  uint uVar1;
  void *src_p_local;
  void *dest_p_local;
  uint32_t *src;
  uint32_t *dest;
  
  uVar1 = *(uint *)((int)src_p + 0x1c);
  *(uint *)dest_p = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  uVar1 = *(uint *)((int)src_p + 0x18);
  *(uint *)((int)dest_p + 4) = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18
  ;
  uVar1 = *(uint *)((int)src_p + 0x14);
  *(uint *)((int)dest_p + 8) = uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18
  ;
  uVar1 = *(uint *)((int)src_p + 0x10);
  *(uint *)((int)dest_p + 0xc) =
       uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  uVar1 = *(uint *)((int)src_p + 0xc);
  *(uint *)((int)dest_p + 0x10) =
       uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  uVar1 = *(uint *)((int)src_p + 8);
  *(uint *)((int)dest_p + 0x14) =
       uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  uVar1 = *(uint *)((int)src_p + 4);
  *(uint *)((int)dest_p + 0x18) =
       uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
                    /* WARNING: Load size is inaccurate */
  uVar1 = *src_p;
  *(uint *)((int)dest_p + 0x1c) =
       uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 | uVar1 >> 0x18;
  return;
}




uint64_t load64(void *src)

{
  void *src_local;
  uint64_t w;
  uint8_t *p;
  
                    /* WARNING: Load size is inaccurate */
  return *src;
}




void store32(void *dst,uint32_t w)

{
  uint32_t w_local;
  void *dst_local;
  uint8_t *p;
  
  *(char *)dst = (char)w;
  *(char *)((int)dst + 1) = (char)(w >> 8);
  *(char *)((int)dst + 2) = (char)(w >> 0x10);
  *(char *)((int)dst + 3) = (char)(w >> 0x18);
  return;
}




void store64(void *dst,uint64_t w)

{
  uint64_t w_local;
  void *dst_local;
  uint8_t *p;
  
  w_local._0_1_ = (undefined1)w;
  *(undefined1 *)dst = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 8);
  *(undefined1 *)((int)dst + 1) = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 0x10);
  *(undefined1 *)((int)dst + 2) = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 0x18);
  *(undefined1 *)((int)dst + 3) = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 0x20);
  *(undefined1 *)((int)dst + 4) = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 0x28);
  *(undefined1 *)((int)dst + 5) = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 0x30);
  *(undefined1 *)((int)dst + 6) = (undefined1)w_local;
  w_local._0_1_ = (undefined1)(w >> 0x38);
  *(undefined1 *)((int)dst + 7) = (undefined1)w_local;
  return;
}




uint64_t rotr64(uint64_t w,uint c)

{
  uint uVar1;
  uint c_local;
  uint64_t w_local;
  
  w_local._0_4_ = (uint)w;
  w_local._4_4_ = (uint)(w >> 0x20);
  uVar1 = -c & 0x3f;
  return CONCAT44(w_local._4_4_ << uVar1 | (uint)w_local << (uVar1 - 0x20 & 0xff) |
                  (uint)w_local >> (0x20 - uVar1 & 0xff) | w_local._4_4_ >> (c & 0xff),
                  (uint)w_local << uVar1 |
                  (uint)w_local >> (c & 0xff) | w_local._4_4_ << (0x20 - c & 0xff) | w_local._4_4_ >> (c - 0x20 & 0xff))
  ;
}




void secure_zero_memory(void *v,size_t n)

{
  size_t n_local;
  void *v_local;
  
  (*secure_zero_memory::memset_v)(v,0,n);
  return;
}




int blake2b_set_lastnode(blake2b_state *S)

{
  blake2b_state *S_local;
  
  *(undefined4 *)(S->f + 1) = 0xffffffff;
  *(undefined4 *)((int)S->f + 0xc) = 0xffffffff;
  return 0;
}




int blake2b_is_lastblock(blake2b_state *S)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  blake2b_state *S_local;
  
  uVar2 = (uint)S->f[0] | *(uint *)((int)S->f + 4);
  bVar3 = uVar2 != 0;
  if (bVar3) {
    uVar2 = 1;
  }
  bVar1 = (byte)uVar2;
  if (!bVar3) {
    bVar1 = 0;
  }
  return (uint)bVar1;
}




int blake2b_set_lastblock(blake2b_state *S)

{
  blake2b_state *S_local;
  
  if (S->last_node != '\0') {
    blake2b_set_lastnode(S);
  }
  *(undefined4 *)S->f = 0xffffffff;
  *(undefined4 *)((int)S->f + 4) = 0xffffffff;
  return 0;
}




int blake2b_increment_counter(blake2b_state *S,uint64_t inc)

{
  uint uVar1;
  byte bVar2;
  uint uVar3;
  bool bVar4;
  uint64_t inc_local;
  blake2b_state *S_local;
  
  inc_local._0_4_ = (uint)inc;
  inc_local._4_4_ = (uint)(inc >> 0x20);
  S->t[0] = inc + S->t[0];
  uVar1 = (uint)S->t[1];
  uVar3 = *(uint *)((int)S->t + 4);
  bVar4 = inc_local._4_4_ <= uVar3;
  if (uVar3 == inc_local._4_4_) {
    bVar4 = (uint)inc_local <= (uint)S->t[0];
  }
  if (!bVar4) {
    inc_local._0_4_ = 1;
  }
  bVar2 = (byte)(uint)inc_local;
  if (bVar4) {
    bVar2 = 0;
  }
  *(uint *)(S->t + 1) = bVar2 + uVar1;
  *(uint *)((int)S->t + 0xc) = *(int *)((int)S->t + 0xc) + (uint)CARRY4((uint)bVar2,uVar1);
  return 0;
}




int blake2b_init0(blake2b_state *S)

{
  undefined4 uVar1;
  blake2b_state *S_local;
  int i;
  
  memset(S,0,0x168);
  for (i = 0; i < 8; i = i + 1) {
    uVar1 = *(undefined4 *)((int)blake2b_IV + i * 8 + 4);
    *(int *)(S->h + i) = (int)blake2b_IV[i];
    *(undefined4 *)((int)(S->h + i) + 4) = uVar1;
  }
  return 0;
}




int blake2b_init_param(blake2b_state *S,blake2b_param *P)

{
  uint uVar1;
  uint64_t uVar2;
  blake2b_param *P_local;
  blake2b_state *S_local;
  uint8_t *p;
  size_t i;
  
  blake2b_init0(S);
  for (i = 0; i < 8; i = i + 1) {
    uVar2 = load64(P->reserved + i * 8 + -0x12);
    uVar1 = *(uint *)((int)(S->h + i) + 4);
    *(uint *)(S->h + i) = (uint)S->h[i] ^ (uint)uVar2;
    *(uint *)((int)(S->h + i) + 4) = uVar1 ^ (uint)(uVar2 >> 0x20);
  }
  return 0;
}




int blake2b_init(blake2b_state *S,uint8_t outlen)

{
  int iVar1;
  uint8_t outlen_local;
  blake2b_state *S_local;
  blake2b_param P [1];
  
  if ((outlen == '\0') || (0x40 < outlen)) {
    iVar1 = -1;
  }
  else {
    P[0].key_length = '\0';
    P[0].fanout = '\x01';
    P[0].depth = '\x01';
    P[0].digest_length = outlen;
    store32(&P[0].leaf_length,0);
    store64(&P[0].node_offset,0);
    P[0].node_depth = '\0';
    P[0].inner_length = '\0';
    memset(P[0].reserved,0,0xe);
    memset(P[0].salt,0,0x10);
    memset(P[0].personal,0,0x10);
    iVar1 = blake2b_init_param(S,P);
  }
  return iVar1;
}




int blake2b_init_key(blake2b_state *S,uint8_t outlen,void *key,uint8_t keylen)

{
  int iVar1;
  void *key_local;
  uint8_t keylen_local;
  uint8_t outlen_local;
  blake2b_state *S_local;
  uint8_t block [128];
  blake2b_param P [1];
  
  if ((outlen == '\0') || (0x40 < outlen)) {
    iVar1 = -1;
  }
  else if ((key == (void *)0x0) || ((keylen == '\0' || (0x40 < keylen)))) {
    iVar1 = -1;
  }
  else {
    P[0].fanout = '\x01';
    P[0].depth = '\x01';
    P[0].digest_length = outlen;
    P[0].key_length = keylen;
    store32(&P[0].leaf_length,0);
    store64(&P[0].node_offset,0);
    P[0].node_depth = '\0';
    P[0].inner_length = '\0';
    memset(P[0].reserved,0,0xe);
    memset(P[0].salt,0,0x10);
    memset(P[0].personal,0,0x10);
    iVar1 = blake2b_init_param(S,P);
    if (iVar1 < 0) {
      iVar1 = -1;
    }
    else {
      memset(block,0,0x80);
      memcpy(block,key,(uint)keylen);
      blake2b_update(S,block,0x80);
      secure_zero_memory(block,0x80);
      iVar1 = 0;
    }
  }
  return iVar1;
}




int blake2b_compress(blake2b_state *S,uint8_t *block)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  bool bVar5;
  uint64_t uVar6;
  uint8_t *block_local;
  blake2b_state *S_local;
  uint64_t v [16];
  uint64_t m [16];
  int i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    uVar6 = load64(block + i * 8);
    m[i] = uVar6;
  }
  for (i = 0; i < 8; i = i + 1) {
    uVar3 = *(undefined4 *)((int)(S->h + i) + 4);
    *(int *)(v + i) = (int)S->h[i];
    *(undefined4 *)((int)v + i * 8 + 4) = uVar3;
  }
  v[8]._0_4_ = 0xf3bcc908;
  v[8]._4_4_ = 0x6a09e667;
  v[9]._0_4_ = 0x84caa73b;
  v[9]._4_4_ = -0x4498517b;
  v[10]._0_4_ = 0xfe94f82b;
  v[10]._4_4_ = 0x3c6ef372;
  v[0xb]._0_4_ = 0x5f1d36f1;
  v[0xb]._4_4_ = -0x5ab00ac6;
  v[0xc]._0_4_ = (uint)S->t[0] ^ 0xade682d1;
  uVar2 = (uint)v[0xc];
  v[0xc] = S->t[0] ^ 0x510e527fade682d1;
  v[0xd] = S->t[1] ^ 0x9b05688c2b3e6c1f;
  v[0xe] = S->f[0] ^ 0x1f83d9abfb41bd6b;
  v[0xf] = S->f[1] ^ 0x5be0cd19137e2179;
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar1 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[0] + uVar1;
  v[0]._4_4_ = m[0]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0],uVar1);
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ uVar2),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[1] + uVar2;
  v[0]._4_4_ = m[1]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[1],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[4] = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[2] + uVar2;
  v[1]._4_4_ = m[2]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[2],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[3] + uVar2;
  v[1]._4_4_ = m[3]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[3],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[5] = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[4] + uVar2;
  v[2]._4_4_ = m[4]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[4],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[5] + uVar2;
  v[2]._4_4_ = m[5]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[5],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  v[6] = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[6] + uVar2;
  v[3]._4_4_ = m[6]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[6],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[7] + uVar2;
  v[3]._4_4_ = m[7]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[7],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[7] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[8] + uVar2;
  v[0]._4_4_ = m[8]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[8],uVar2);
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[9] + uVar2;
  v[0]._4_4_ = m[9]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[9],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[5] = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[10] + uVar2;
  v[1]._4_4_ = m[10]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[10],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[0xb] + uVar2;
  v[1]._4_4_ = m[0xb]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xb],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[6] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[0xc] + uVar2;
  v[2]._4_4_ = m[0xc]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xc],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[0xd] + uVar2;
  v[2]._4_4_ = m[0xd]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xd],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[7] = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[0xe] + uVar2;
  v[3]._4_4_ = m[0xe]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xe],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[0xf] + uVar2;
  v[3]._4_4_ = m[0xf]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xf],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x3f);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[0xe] + uVar2;
  v[0]._4_4_ = m[0xe]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xe],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[10] + uVar2;
  v[0]._4_4_ = m[10]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[10],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[4] = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[4] + uVar2;
  v[1]._4_4_ = m[4]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[4],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[8] + uVar2;
  v[1]._4_4_ = m[8]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[8],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[5] = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[9] + uVar2;
  v[2]._4_4_ = m[9]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[9],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[0xf] + uVar2;
  v[2]._4_4_ = m[0xf]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xf],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  v[6] = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[0xd] + uVar2;
  v[3]._4_4_ = m[0xd]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xd],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[6] + uVar2;
  v[3]._4_4_ = m[6]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[6],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[7] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[1] + uVar2;
  v[0]._4_4_ = m[1]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[1],uVar2);
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[0xc] + uVar2;
  v[0]._4_4_ = m[0xc]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xc],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[5] = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[0] + uVar2;
  v[1]._4_4_ = m[0]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[2] + uVar2;
  v[1]._4_4_ = m[2]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[2],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[6] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[0xb] + uVar2;
  v[2]._4_4_ = m[0xb]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xb],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[7] + uVar2;
  v[2]._4_4_ = m[7]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[7],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[7] = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[5] + uVar2;
  v[3]._4_4_ = m[5]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[5],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[3] + uVar2;
  v[3]._4_4_ = m[3]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[3],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x3f);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[0xb] + uVar2;
  v[0]._4_4_ = m[0xb]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xb],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[8] + uVar2;
  v[0]._4_4_ = m[8]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[8],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[4] = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[0xc] + uVar2;
  v[1]._4_4_ = m[0xc]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xc],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[0] + uVar2;
  v[1]._4_4_ = m[0]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[5] = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[5] + uVar2;
  v[2]._4_4_ = m[5]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[5],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[2] + uVar2;
  v[2]._4_4_ = m[2]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[2],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  v[6] = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[0xf] + uVar2;
  v[3]._4_4_ = m[0xf]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xf],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[0xd] + uVar2;
  v[3]._4_4_ = m[0xd]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xd],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[7] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[10] + uVar2;
  v[0]._4_4_ = m[10]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[10],uVar2);
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[0xe] + uVar2;
  v[0]._4_4_ = m[0xe]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xe],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[5] = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[3] + uVar2;
  v[1]._4_4_ = m[3]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[3],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[6] + uVar2;
  v[1]._4_4_ = m[6]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[6],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[6] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[7] + uVar2;
  v[2]._4_4_ = m[7]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[7],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[1] + uVar2;
  v[2]._4_4_ = m[1]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[1],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[7] = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[9] + uVar2;
  v[3]._4_4_ = m[9]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[9],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[4] + uVar2;
  v[3]._4_4_ = m[4]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[4],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x3f);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[7] + uVar2;
  v[0]._4_4_ = m[7]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[7],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[9] + uVar2;
  v[0]._4_4_ = m[9]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[9],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[4] = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[3] + uVar2;
  v[1]._4_4_ = m[3]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[3],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[1] + uVar2;
  v[1]._4_4_ = m[1]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[1],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[5] = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[0xd] + uVar2;
  v[2]._4_4_ = m[0xd]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xd],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[0xc] + uVar2;
  v[2]._4_4_ = m[0xc]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xc],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  v[6] = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[0xb] + uVar2;
  v[3]._4_4_ = m[0xb]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xb],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[0xe] + uVar2;
  v[3]._4_4_ = m[0xe]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xe],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[7] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[2] + uVar2;
  v[0]._4_4_ = m[2]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[2],uVar2);
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[6] + uVar2;
  v[0]._4_4_ = m[6]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[6],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[5] = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[5] + uVar2;
  v[1]._4_4_ = m[5]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[5],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[10] + uVar2;
  v[1]._4_4_ = m[10]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[10],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[6] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[4] + uVar2;
  v[2]._4_4_ = m[4]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[4],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[0] + uVar2;
  v[2]._4_4_ = m[0]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[7] = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[0xf] + uVar2;
  v[3]._4_4_ = m[0xf]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xf],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[8] + uVar2;
  v[3]._4_4_ = m[8]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[8],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x3f);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[9] + uVar2;
  v[0]._4_4_ = m[9]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[9],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[0] + uVar2;
  v[0]._4_4_ = m[0]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[4] = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[5] + uVar2;
  v[1]._4_4_ = m[5]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[5],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[7] + uVar2;
  v[1]._4_4_ = m[7]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[7],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[5] = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[2] + uVar2;
  v[2]._4_4_ = m[2]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[2],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[4] + uVar2;
  v[2]._4_4_ = m[4]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[4],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  v[6] = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[10] + uVar2;
  v[3]._4_4_ = m[10]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[10],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[0xf] + uVar2;
  v[3]._4_4_ = m[0xf]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xf],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[7] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[0xe] + uVar2;
  v[0]._4_4_ = m[0xe]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xe],uVar2);
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[1] + uVar2;
  v[0]._4_4_ = m[1]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[1],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[5] = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[0xb] + uVar2;
  v[1]._4_4_ = m[0xb]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xb],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[0xc] + uVar2;
  v[1]._4_4_ = m[0xc]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xc],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[6] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[6] + uVar2;
  v[2]._4_4_ = m[6]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[6],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[8] + uVar2;
  v[2]._4_4_ = m[8]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[8],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[7] = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[3] + uVar2;
  v[3]._4_4_ = m[3]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[3],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[0xd] + uVar2;
  v[3]._4_4_ = m[0xd]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xd],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x3f);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[2] + uVar2;
  v[0]._4_4_ = m[2]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[2],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[0xc] + uVar2;
  v[0]._4_4_ = m[0xc]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xc],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[4] = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[6] + uVar2;
  v[1]._4_4_ = m[6]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[6],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[10] + uVar2;
  v[1]._4_4_ = m[10]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[10],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[5] = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[0] + uVar2;
  v[2]._4_4_ = m[0]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[0xb] + uVar2;
  v[2]._4_4_ = m[0xb]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xb],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  v[6] = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[8] + uVar2;
  v[3]._4_4_ = m[8]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[8],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[3] + uVar2;
  v[3]._4_4_ = m[3]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[3],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[7] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[4] + uVar2;
  v[0]._4_4_ = m[4]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[4],uVar2);
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[0xd] + uVar2;
  v[0]._4_4_ = m[0xd]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xd],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[5] = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[7] + uVar2;
  v[1]._4_4_ = m[7]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[7],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[5] + uVar2;
  v[1]._4_4_ = m[5]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[5],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[6] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[0xf] + uVar2;
  v[2]._4_4_ = m[0xf]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xf],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[0xe] + uVar2;
  v[2]._4_4_ = m[0xe]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xe],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[7] = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[1] + uVar2;
  v[3]._4_4_ = m[1]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[1],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[9] + uVar2;
  v[3]._4_4_ = m[9]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[9],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x3f);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[0xc] + uVar2;
  v[0]._4_4_ = m[0xc]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xc],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[5] + uVar2;
  v[0]._4_4_ = m[5]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[5],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[4] = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[1] + uVar2;
  v[1]._4_4_ = m[1]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[1],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[0xf] + uVar2;
  v[1]._4_4_ = m[0xf]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xf],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[5] = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[0xe] + uVar2;
  v[2]._4_4_ = m[0xe]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xe],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[0xd] + uVar2;
  v[2]._4_4_ = m[0xd]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xd],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  v[6] = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[4] + uVar2;
  v[3]._4_4_ = m[4]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[4],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[10] + uVar2;
  v[3]._4_4_ = m[10]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[10],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[7] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[0] + uVar2;
  v[0]._4_4_ = m[0]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0],uVar2);
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[7] + uVar2;
  v[0]._4_4_ = m[7]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[7],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[5] = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[6] + uVar2;
  v[1]._4_4_ = m[6]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[6],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[3] + uVar2;
  v[1]._4_4_ = m[3]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[3],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[6] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[9] + uVar2;
  v[2]._4_4_ = m[9]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[9],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[2] + uVar2;
  v[2]._4_4_ = m[2]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[2],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[7] = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[8] + uVar2;
  v[3]._4_4_ = m[8]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[8],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[0xb] + uVar2;
  v[3]._4_4_ = m[0xb]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xb],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x3f);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[0xd] + uVar2;
  v[0]._4_4_ = m[0xd]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xd],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[0xb] + uVar2;
  v[0]._4_4_ = m[0xb]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xb],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[4] = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[7] + uVar2;
  v[1]._4_4_ = m[7]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[7],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[0xe] + uVar2;
  v[1]._4_4_ = m[0xe]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xe],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[5] = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[0xc] + uVar2;
  v[2]._4_4_ = m[0xc]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xc],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[1] + uVar2;
  v[2]._4_4_ = m[1]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[1],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  v[6] = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[3] + uVar2;
  v[3]._4_4_ = m[3]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[3],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[9] + uVar2;
  v[3]._4_4_ = m[9]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[9],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[7] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[5] + uVar2;
  v[0]._4_4_ = m[5]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[5],uVar2);
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[0] + uVar2;
  v[0]._4_4_ = m[0]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[5] = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[0xf] + uVar2;
  v[1]._4_4_ = m[0xf]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xf],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[4] + uVar2;
  v[1]._4_4_ = m[4]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[4],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[6] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[8] + uVar2;
  v[2]._4_4_ = m[8]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[8],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[6] + uVar2;
  v[2]._4_4_ = m[6]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[6],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[7] = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[2] + uVar2;
  v[3]._4_4_ = m[2]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[2],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[10] + uVar2;
  v[3]._4_4_ = m[10]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[10],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x3f);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[6] + uVar2;
  v[0]._4_4_ = m[6]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[6],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[0xf] + uVar2;
  v[0]._4_4_ = m[0xf]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xf],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[4] = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[0xe] + uVar2;
  v[1]._4_4_ = m[0xe]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xe],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[9] + uVar2;
  v[1]._4_4_ = m[9]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[9],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[5] = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[0xb] + uVar2;
  v[2]._4_4_ = m[0xb]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xb],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[3] + uVar2;
  v[2]._4_4_ = m[3]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[3],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  v[6] = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[0] + uVar2;
  v[3]._4_4_ = m[0]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[8] + uVar2;
  v[3]._4_4_ = m[8]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[8],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[7] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[0xc] + uVar2;
  v[0]._4_4_ = m[0xc]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xc],uVar2);
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[2] + uVar2;
  v[0]._4_4_ = m[2]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[2],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[5] = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[0xd] + uVar2;
  v[1]._4_4_ = m[0xd]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xd],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[7] + uVar2;
  v[1]._4_4_ = m[7]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[7],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[6] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[1] + uVar2;
  v[2]._4_4_ = m[1]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[1],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[4] + uVar2;
  v[2]._4_4_ = m[4]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[4],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[7] = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[10] + uVar2;
  v[3]._4_4_ = m[10]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[10],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[5] + uVar2;
  v[3]._4_4_ = m[5]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[5],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x3f);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[10] + uVar2;
  v[0]._4_4_ = m[10]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[10],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[2] + uVar2;
  v[0]._4_4_ = m[2]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[2],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[4] = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[8] + uVar2;
  v[1]._4_4_ = m[8]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[8],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[4] + uVar2;
  v[1]._4_4_ = m[4]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[4],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[5] = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[7] + uVar2;
  v[2]._4_4_ = m[7]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[7],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[6] + uVar2;
  v[2]._4_4_ = m[6]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[6],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  v[6] = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[1] + uVar2;
  v[3]._4_4_ = m[1]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[1],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[5] + uVar2;
  v[3]._4_4_ = m[5]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[5],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[7] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[0xf] + uVar2;
  v[0]._4_4_ = m[0xf]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xf],uVar2);
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[0xb] + uVar2;
  v[0]._4_4_ = m[0xb]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xb],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[5] = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[9] + uVar2;
  v[1]._4_4_ = m[9]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[9],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[0xe] + uVar2;
  v[1]._4_4_ = m[0xe]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xe],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[6] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[3] + uVar2;
  v[2]._4_4_ = m[3]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[3],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[0xc] + uVar2;
  v[2]._4_4_ = m[0xc]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xc],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[7] = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[0xd] + uVar2;
  v[3]._4_4_ = m[0xd]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xd],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[0] + uVar2;
  v[3]._4_4_ = m[0]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x3f);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[0] + uVar2;
  v[0]._4_4_ = m[0]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[1] + uVar2;
  v[0]._4_4_ = m[1]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[1],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[4] = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[2] + uVar2;
  v[1]._4_4_ = m[2]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[2],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[3] + uVar2;
  v[1]._4_4_ = m[3]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[3],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[5] = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[4] + uVar2;
  v[2]._4_4_ = m[4]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[4],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[5] + uVar2;
  v[2]._4_4_ = m[5]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[5],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  v[6] = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[6] + uVar2;
  v[3]._4_4_ = m[6]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[6],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[7] + uVar2;
  v[3]._4_4_ = m[7]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[7],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[7] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[8] + uVar2;
  v[0]._4_4_ = m[8]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[8],uVar2);
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[9] + uVar2;
  v[0]._4_4_ = m[9]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[9],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[5] = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[10] + uVar2;
  v[1]._4_4_ = m[10]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[10],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[0xb] + uVar2;
  v[1]._4_4_ = m[0xb]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xb],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[6] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[0xc] + uVar2;
  v[2]._4_4_ = m[0xc]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xc],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[0xd] + uVar2;
  v[2]._4_4_ = m[0xd]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xd],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[7] = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[0xe] + uVar2;
  v[3]._4_4_ = m[0xe]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xe],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[0xf] + uVar2;
  v[3]._4_4_ = m[0xf]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xf],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x3f);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[0xe] + uVar2;
  v[0]._4_4_ = m[0xe]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xe],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[4]);
  uVar2 = (uint)v[0] + (uint)v[4];
  v[0]._0_4_ = (uint)m[10] + uVar2;
  v[0]._4_4_ = m[10]._4_4_ + v[0]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[10],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xc]._4_4_,(uint)v[0] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xc] + (uint)v[8];
  v[8]._4_4_ = v[0xc]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[4] = rotr64(CONCAT44(v[8]._4_4_ ^ v[4]._4_4_,(uint)v[8] ^ (uint)v[4]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[4] + uVar2;
  v[1]._4_4_ = m[4]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[4],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[5]);
  uVar2 = (uint)v[1] + (uint)v[5];
  v[1]._0_4_ = (uint)m[8] + uVar2;
  v[1]._4_4_ = m[8]._4_4_ + v[1]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[8],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xd]._4_4_,(uint)v[1] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xd] + (uint)v[9];
  v[9]._4_4_ = v[0xd]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[5] = rotr64(CONCAT44(v[9]._4_4_ ^ v[5]._4_4_,(uint)v[9] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[9] + uVar2;
  v[2]._4_4_ = m[9]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[9],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[6]);
  uVar2 = (uint)v[2] + (uint)v[6];
  v[2]._0_4_ = (uint)m[0xf] + uVar2;
  v[2]._4_4_ = m[0xf]._4_4_ + v[2]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xf],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xe]._4_4_,(uint)v[2] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xe] + (uint)v[10];
  v[10]._4_4_ = v[0xe]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xe] = uVar6;
  v[6] = rotr64(CONCAT44(v[10]._4_4_ ^ v[6]._4_4_,(uint)v[10] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[0xd] + uVar2;
  v[3]._4_4_ = m[0xd]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xd],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[7]);
  uVar2 = (uint)v[3] + (uint)v[7];
  v[3]._0_4_ = (uint)m[6] + uVar2;
  v[3]._4_4_ = m[6]._4_4_ + v[3]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[6],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xf]._4_4_,(uint)v[3] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xf] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xf]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[7] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[7]._4_4_,(uint)v[0xb] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[1] + uVar2;
  v[0]._4_4_ = m[1]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[1],uVar2);
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x20);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  uVar6 = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x18);
  v[5]._0_4_ = (uint)uVar6;
  v[5]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0],(uint)v[5]);
  uVar2 = (uint)v[0] + (uint)v[5];
  v[0]._0_4_ = (uint)m[0xc] + uVar2;
  v[0]._4_4_ = m[0xc]._4_4_ + v[0]._4_4_ + v[5]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xc],uVar2);
  v[5] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0]._4_4_ ^ v[0xf]._4_4_,(uint)v[0] ^ (uint)v[0xf]),0x10);
  v[0xf]._0_4_ = (uint)uVar6;
  v[0xf]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xf],(uint)v[10]);
  v[10]._0_4_ = (uint)v[0xf] + (uint)v[10];
  v[10]._4_4_ = v[0xf]._4_4_ + v[10]._4_4_ + bVar5;
  v[0xf] = uVar6;
  v[5] = rotr64(CONCAT44(v[10]._4_4_ ^ v[5]._4_4_,(uint)v[10] ^ (uint)v[5]),0x3f);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[0] + uVar2;
  v[1]._4_4_ = m[0]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0],uVar2);
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x20);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  uVar6 = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x18);
  v[6]._0_4_ = (uint)uVar6;
  v[6]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[1],(uint)v[6]);
  uVar2 = (uint)v[1] + (uint)v[6];
  v[1]._0_4_ = (uint)m[2] + uVar2;
  v[1]._4_4_ = m[2]._4_4_ + v[1]._4_4_ + v[6]._4_4_ + bVar5 + (uint)CARRY4((uint)m[2],uVar2);
  v[6] = uVar6;
  uVar6 = rotr64(CONCAT44(v[1]._4_4_ ^ v[0xc]._4_4_,(uint)v[1] ^ (uint)v[0xc]),0x10);
  v[0xc]._0_4_ = (uint)uVar6;
  v[0xc]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xc],(uint)v[0xb]);
  v[0xb]._0_4_ = (uint)v[0xc] + (uint)v[0xb];
  v[0xb]._4_4_ = v[0xc]._4_4_ + v[0xb]._4_4_ + bVar5;
  v[0xc] = uVar6;
  v[6] = rotr64(CONCAT44(v[0xb]._4_4_ ^ v[6]._4_4_,(uint)v[0xb] ^ (uint)v[6]),0x3f);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[0xb] + uVar2;
  v[2]._4_4_ = m[0xb]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[0xb],uVar2);
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x20);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  uVar6 = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x18);
  v[7]._0_4_ = (uint)uVar6;
  v[7]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[2],(uint)v[7]);
  uVar2 = (uint)v[2] + (uint)v[7];
  v[2]._0_4_ = (uint)m[7] + uVar2;
  v[2]._4_4_ = m[7]._4_4_ + v[2]._4_4_ + v[7]._4_4_ + bVar5 + (uint)CARRY4((uint)m[7],uVar2);
  v[7] = uVar6;
  uVar6 = rotr64(CONCAT44(v[2]._4_4_ ^ v[0xd]._4_4_,(uint)v[2] ^ (uint)v[0xd]),0x10);
  v[0xd]._0_4_ = (uint)uVar6;
  v[0xd]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xd],(uint)v[8]);
  v[8]._0_4_ = (uint)v[0xd] + (uint)v[8];
  v[8]._4_4_ = v[0xd]._4_4_ + v[8]._4_4_ + bVar5;
  v[0xd] = uVar6;
  v[7] = rotr64(CONCAT44(v[8]._4_4_ ^ v[7]._4_4_,(uint)v[8] ^ (uint)v[7]),0x3f);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[5] + uVar2;
  v[3]._4_4_ = m[5]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[5],uVar2);
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x20);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  uVar6 = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x18);
  v[4]._0_4_ = (uint)uVar6;
  v[4]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[3],(uint)v[4]);
  uVar2 = (uint)v[3] + (uint)v[4];
  v[3]._0_4_ = (uint)m[3] + uVar2;
  v[3]._4_4_ = m[3]._4_4_ + v[3]._4_4_ + v[4]._4_4_ + bVar5 + (uint)CARRY4((uint)m[3],uVar2);
  v[4] = uVar6;
  uVar6 = rotr64(CONCAT44(v[3]._4_4_ ^ v[0xe]._4_4_,(uint)v[3] ^ (uint)v[0xe]),0x10);
  v[0xe]._0_4_ = (uint)uVar6;
  v[0xe]._4_4_ = (uint)(uVar6 >> 0x20);
  bVar5 = CARRY4((uint)v[0xe],(uint)v[9]);
  v[9]._0_4_ = (uint)v[0xe] + (uint)v[9];
  v[9]._4_4_ = v[0xe]._4_4_ + v[9]._4_4_ + bVar5;
  v[0xe] = uVar6;
  v[4] = rotr64(CONCAT44(v[9]._4_4_ ^ v[4]._4_4_,(uint)v[9] ^ (uint)v[4]),0x3f);
  for (i = 0; i < 8; i = i + 1) {
    uVar2 = *(uint *)((int)(S->h + i) + 4);
    uVar1 = *(uint *)((int)v + i * 8 + 4);
    uVar4 = *(uint *)((int)v + (i + 8) * 8 + 4);
    *(uint *)(S->h + i) = (uint)v[i + 8] ^ (uint)S->h[i] ^ (uint)v[i];
    *(uint *)((int)(S->h + i) + 4) = uVar4 ^ uVar2 ^ uVar1;
  }
  return 0;
}




int blake2b_update(blake2b_state *S,uint8_t *in,uint64_t inlen)

{
  size_t sVar1;
  uint __n;
  bool bVar2;
  uint64_t inlen_local;
  uint8_t *in_local;
  blake2b_state *S_local;
  size_t fill;
  size_t left;
  
  inlen_local = inlen;
  in_local = in;
  while ((uint)inlen_local != 0 || inlen_local._4_4_ != 0) {
    sVar1 = S->buflen;
    __n = 0x100 - sVar1;
    bVar2 = inlen_local._4_4_ == 0;
    if (inlen_local._4_4_ == 0) {
      bVar2 = (uint)inlen_local <= __n;
    }
    if (bVar2) {
      memcpy(S->buf + sVar1,in_local,(uint)inlen_local);
      S->buflen = S->buflen + (uint)inlen_local;
      in_local = in_local + (uint)inlen_local;
      inlen_local = 0;
    }
    else {
      memcpy(S->buf + sVar1,in_local,__n);
      S->buflen = S->buflen + __n;
      blake2b_increment_counter(S,0x80);
      blake2b_compress(S,S->buf);
      memcpy(S->buf,S->buf + 0x80,0x80);
      S->buflen = S->buflen - 0x80;
      in_local = in_local + __n;
      inlen_local = CONCAT44(inlen_local._4_4_ - (uint)((uint)inlen_local < __n),(uint)inlen_local - __n);
    }
  }
  return 0;
}




int blake2b_final(blake2b_state *S,uint8_t *out,uint8_t outlen)

{
  int iVar1;
  uint8_t outlen_local;
  uint8_t *out_local;
  blake2b_state *S_local;
  uint8_t buffer [64];
  int i;
  
  memset(buffer,0,0x40);
  if (((out == (uint8_t *)0x0) || (outlen == '\0')) || (0x40 < outlen)) {
    iVar1 = -1;
  }
  else {
    iVar1 = blake2b_is_lastblock(S);
    if (iVar1 == 0) {
      if (0x80 < S->buflen) {
        blake2b_increment_counter(S,0x80);
        blake2b_compress(S,S->buf);
        S->buflen = S->buflen - 0x80;
        memcpy(S->buf,S->buf + 0x80,S->buflen);
      }
      blake2b_increment_counter(S,(ulonglong)S->buflen);
      blake2b_set_lastblock(S);
      memset(S->buf + S->buflen,0,0x100 - S->buflen);
      blake2b_compress(S,S->buf);
      for (i = 0; i < 8; i = i + 1) {
        store64(buffer + i * 8,S->h[i]);
      }
      memcpy(out,buffer,(uint)outlen);
      iVar1 = 0;
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}




int blake2b(uint8_t *out,void *in,void *key,uint8_t outlen,uint64_t inlen,uint8_t keylen)

{
  int iVar1;
  uint8_t outlen_local;
  void *key_local;
  void *in_local;
  uint8_t *out_local;
  blake2b_state S [1];
  
  if ((in == (void *)0x0) && (inlen != 0)) {
    iVar1 = -1;
  }
  else if (out == (uint8_t *)0x0) {
    iVar1 = -1;
  }
  else if ((key == (void *)0x0) && (keylen != '\0')) {
    iVar1 = -1;
  }
  else if ((outlen == '\0') || (0x40 < outlen)) {
    iVar1 = -1;
  }
  else if (keylen < 0x41) {
    if (keylen == '\0') {
      iVar1 = blake2b_init(S,outlen);
      if (iVar1 < 0) {
        return -1;
      }
    }
    else {
      iVar1 = blake2b_init_key(S,outlen,key,keylen);
      if (iVar1 < 0) {
        return -1;
      }
    }
    blake2b_update(S,(uint8_t *)in,inlen);
    blake2b_final(S,out,outlen);
    iVar1 = 0;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}




ushort crc_itu_t_byte(ushort crc,uchar data)

{
  uchar data_local;
  ushort crc_local;
  
  return crc_itu_t_table[(uint)data ^ (uint)(crc >> 8)] ^ crc << 8;
}




ushort CRC16_v1(uchar *buffer,int len)

{
  int len_local;
  uchar *buffer_local;
  ushort crc;
  
  crc = 0xffff;
  len_local = len;
  buffer_local = buffer;
  while (len_local != 0) {
    crc = crc_itu_t_byte(crc,*buffer_local);
    len_local = len_local + -1;
    buffer_local = buffer_local + 1;
  }
  return crc;
}




uchar CRC5_v1(uchar *ptr,uchar len)

{
  uchar uVar1;
  uchar uVar2;
  uchar uVar3;
  byte bVar4;
  BADSPACEBASE *unaff_sp;
  bool bVar5;
  uchar len_local;
  uchar *ptr_local;
  uchar crcout [5];
  uchar crcin [5];
  uchar din;
  uchar crc;
  uchar k;
  uchar j;
  uchar i;
  
  builtin_memcpy(crcin,"\x01\x01\x01\x01\x01",5);
  j = 0x80;
  k = '\0';
  i = '\0';
  ptr_local = ptr;
  while( true ) {
    uVar1 = crcin[0];
    uVar2 = crcin[2];
    uVar3 = crcin[3];
    if (len <= i) break;
    bVar5 = (j & *ptr_local) != 0;
    bVar4 = crcin[4] ^ crcin[1];
    j = j >> 1;
    k = k + '\x01';
    if (k == '\b') {
      j = 0x80;
      k = '\0';
      ptr_local = ptr_local + 1;
    }
    crcin[0] = bVar5 ^ crcin[4];
    crcin[1] = uVar1;
    crcin[2] = bVar5 ^ bVar4;
    crcin[3] = uVar2;
    crcin[4] = uVar3;
    i = i + '\x01';
  }
  crc = '\0';
  if (crcin[4] != '\0') {
    crc = '\x10';
  }
  if (crcin[3] != '\0') {
    crc = crc | 8;
  }
  if (crcin[2] != '\0') {
    crc = crc | 4;
  }
  if (crcin[1] != '\0') {
    crc = crc | 2;
  }
  if (crcin[0] != '\0') {
    crc = crc | 1;
  }
  return crc;
}




void sha256_transf(sha256_ctx *ctx,uchar *message,uint block_nb)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint block_nb_local;
  uchar *message_local;
  sha256_ctx *ctx_local;
  uint32_t wv [8];
  uint32_t w [64];
  uint32_t t2;
  uint32_t t1;
  uchar *sub_block;
  int j;
  int i;
  
  for (i = 0; i < (int)block_nb; i = i + 1) {
    for (j = 0; j < 0x10; j = j + 1) {
      w[j] = CONCAT13(message[j * 4 + i * 0x40],
                      CONCAT12(message[j * 4 + 1 + i * 0x40],
                               CONCAT11(message[j * 4 + 2 + i * 0x40],message[j * 4 + 3 + i * 0x40])));
    }
    for (j = 0x10; j < 0x40; j = j + 1) {
      w[j] = ((w[j + -2] >> 0x11 | w[j + -2] << 0xf) ^ (w[j + -2] >> 0x13 | w[j + -2] << 0xd) ^ w[j + -2] >> 10) +
             w[j + -7] +
             (w[j + -0xf] >> 3 ^ (w[j + -0xf] >> 7 | w[j + -0xf] << 0x19) ^ (w[j + -0xf] >> 0x12 | w[j + -0xf] << 0xe))
             + w[j + -0x10];
    }
    for (j = 0; j < 8; j = j + 1) {
      wv[j] = ctx->h[j];
    }
    for (j = 0; j < 0x40; j = j + 1) {
      iVar2 = w[j] + wv[7] + ((wv[4] >> 0x19 | wv[4] << 7) ^
                             (wv[4] >> 6 | wv[4] << 0x1a) ^ (wv[4] >> 0xb | wv[4] << 0x15)) +
                     (wv[6] & ~wv[4] ^ wv[4] & wv[5]) + sha256_k[j];
      uVar1 = wv[0] & wv[1];
      uVar3 = wv[2] & wv[0];
      uVar4 = wv[2] & wv[1];
      wv[7] = wv[6];
      wv[6] = wv[5];
      wv[5] = wv[4];
      wv[4] = wv[3] + iVar2;
      wv[3] = wv[2];
      wv[2] = wv[1];
      wv[1] = wv[0];
      wv[0] = iVar2 + (uVar4 ^ uVar1 ^ uVar3) +
                      ((wv[0] >> 2 | wv[0] << 0x1e) ^ (wv[0] >> 0xd | wv[0] << 0x13) ^ (wv[0] >> 0x16 | wv[0] << 10));
    }
    for (j = 0; j < 8; j = j + 1) {
      ctx->h[j] = ctx->h[j] + wv[j];
    }
  }
  return;
}




void sha256(uchar *message,uint len,uchar *digest)

{
  uchar *digest_local;
  uint len_local;
  uchar *message_local;
  sha256_ctx ctx;
  
  sha256_init(&ctx);
  sha256_update(&ctx,message,len);
  sha256_final(&ctx,digest);
  return;
}




void sha256_init(sha256_ctx *ctx)

{
  sha256_ctx *ctx_local;
  int i;
  
  for (i = 0; i < 8; i = i + 1) {
    ctx->h[i] = sha256_h0[i];
  }
  ctx->len = 0;
  ctx->tot_len = 0;
  return;
}




void sha256_update(sha256_ctx *ctx,uchar *message,uint len)

{
  uint uVar1;
  uint __n;
  uint __n_00;
  uint len_local;
  uchar *message_local;
  sha256_ctx *ctx_local;
  uchar *shifted_message;
  uint block_nb;
  uint new_len;
  uint rem_len;
  uint tmp_len;
  
  uVar1 = 0x40 - ctx->len;
  __n = len;
  if (uVar1 <= len) {
    __n = uVar1;
  }
  memcpy(ctx->block + ctx->len,message,__n);
  if (len + ctx->len < 0x40) {
    ctx->len = ctx->len + len;
  }
  else {
    uVar1 = len - __n >> 6;
    sha256_transf(ctx,ctx->block,1);
    sha256_transf(ctx,message + __n,uVar1);
    __n_00 = len - __n & 0x3f;
    memcpy(ctx->block,message + __n + uVar1 * 0x40,__n_00);
    ctx->len = __n_00;
    ctx->tot_len = ctx->tot_len + (uVar1 + 1) * 0x40;
  }
  return;
}




void sha256_final(sha256_ctx *ctx,uchar *digest)

{
  uint block_nb_00;
  int iVar1;
  int iVar2;
  uchar *digest_local;
  sha256_ctx *ctx_local;
  uint pm_len;
  uint len_b;
  uint block_nb;
  int i;
  
  if ((ctx->len & 0x3f) < 0x38) {
    block_nb_00 = 1;
  }
  else {
    block_nb_00 = 2;
  }
  iVar1 = (ctx->len + ctx->tot_len) * 8;
  iVar2 = block_nb_00 * 0x40;
  memset(ctx->block + ctx->len,0,iVar2 - ctx->len);
  ctx->block[ctx->len] = 0x80;
  ctx->block[iVar2 + -1] = (uchar)iVar1;
  ctx->block[iVar2 + -2] = (uchar)((uint)iVar1 >> 8);
  ctx->block[iVar2 + -3] = (uchar)((uint)iVar1 >> 0x10);
  ctx->block[iVar2 + -4] = (uchar)((uint)iVar1 >> 0x18);
  sha256_transf(ctx,ctx->block,block_nb_00);
  for (i = 0; i < 8; i = i + 1) {
    digest[i * 4 + 3] = (uchar)ctx->h[i];
    digest[i * 4 + 2] = (uchar)(ctx->h[i] >> 8);
    digest[i * 4 + 1] = (uchar)(ctx->h[i] >> 0x10);
    digest[i * 4] = (uchar)(ctx->h[i] >> 0x18);
  }
  return;
}




void Sha256_Init(CSha256 *p)

{
  CSha256 *p_local;
  
  p->state[0] = 0x6a09e667;
  p->state[1] = 0xbb67ae85;
  p->state[2] = 0x3c6ef372;
  p->state[3] = 0xa54ff53a;
  p->state[4] = 0x510e527f;
  p->state[5] = 0x9b05688c;
  p->state[6] = 0x1f83d9ab;
  p->state[7] = 0x5be0cd19;
  *(undefined4 *)&p->count = 0;
  *(undefined4 *)((int)&p->count + 4) = 0;
  return;
}




void Sha256_Transform(uint32_t *state,uint32_t *data)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint32_t uVar7;
  uint32_t uVar8;
  uint uVar9;
  uint32_t *data_local;
  uint32_t *state_local;
  uint32_t T [8];
  uint32_t W [16];
  uint i;
  uint j;
  
  for (j = 0; j < 8; j = j + 1) {
    T[j] = state[j];
  }
  for (j = 0; j < 0x40; j = j + 0x10) {
    for (i = 0; i < 0x10; i = i + 1) {
      uVar3 = T[4 - i & 7];
      uVar4 = T[4 - i & 7];
      uVar5 = T[4 - i & 7];
      uVar2 = T[6 - i & 7];
      uVar1 = T[4 - i & 7];
      uVar9 = T[5 - i & 7];
      uVar6 = T[6 - i & 7];
      uVar7 = K[i + j];
      if (j == 0) {
        W[i] = data[i];
        uVar8 = W[i];
      }
      else {
        W[i & 0xf] = W[i & 0xf] +
                     (W[i - 0xf & 0xf] >> 3 ^
                     (W[i - 0xf & 0xf] >> 7 | W[i - 0xf & 0xf] << 0x19) ^
                     (W[i - 0xf & 0xf] >> 0x12 | W[i - 0xf & 0xf] << 0xe)) +
                     ((W[i - 2 & 0xf] >> 0x11 | W[i - 2 & 0xf] << 0xf) ^
                      (W[i - 2 & 0xf] >> 0x13 | W[i - 2 & 0xf] << 0xd) ^ W[i - 2 & 0xf] >> 10) + W[i - 7 & 0xf];
        uVar8 = W[i & 0xf];
      }
      T[7 - i & 7] = ((uVar3 >> 6 | uVar3 << 0x1a) ^ (uVar4 >> 0xb | uVar4 << 0x15) ^ (uVar5 >> 0x19 | uVar5 << 7)) +
                     ((uVar6 ^ uVar9) & uVar1 ^ uVar2) + uVar7 + uVar8 + T[7 - i & 7];
      T[3 - i & 7] = T[3 - i & 7] + T[7 - i & 7];
      T[7 - i & 7] = T[7 - i & 7] +
                     ((T[1 - i & 7] | T[-i & 7]) & T[2 - i & 7] | T[-i & 7] & T[1 - i & 7]) +
                     ((T[-i & 7] >> 2 | T[-i & 7] << 0x1e) ^ (T[-i & 7] >> 0xd | T[-i & 7] << 0x13) ^
                     (T[-i & 7] >> 0x16 | T[-i & 7] << 10));
    }
  }
  for (j = 0; j < 8; j = j + 1) {
    state[j] = T[j] + state[j];
  }
  return;
}




void Sha256_WriteByteBlock(CSha256 *p)

{
  CSha256 *p_local;
  uint32_t data32 [16];
  uint i;
  
  for (i = 0; i < 0x10; i = i + 1) {
    data32[i] = (uint)p->buffer[i * 4 + 3] +
                (uint)p->buffer[i * 4 + 2] * 0x100 +
                (uint)p->buffer[i * 4] * 0x1000000 + (uint)p->buffer[i * 4 + 1] * 0x10000;
  }
  Sha256_Transform(p->state,data32);
  return;
}




void Sha256_Update(CSha256 *p,uint8_t *data,size_t size)

{
  uint8_t *puVar1;
  uint32_t uVar2;
  uint uVar3;
  int iVar4;
  size_t size_local;
  uint8_t *data_local;
  CSha256 *p_local;
  uint32_t curBufferPos;
  
  size_local = size;
  data_local = data;
  curBufferPos = (uint)p->count & 0x3f;
  while (size_local != 0) {
    uVar2 = curBufferPos + 1;
    puVar1 = data_local + 1;
    p->buffer[curBufferPos] = *data_local;
    uVar3 = (uint)p->count;
    iVar4 = *(int *)((int)&p->count + 4);
    *(uint *)&p->count = uVar3 + 1;
    *(uint *)((int)&p->count + 4) = iVar4 + (uint)(0xfffffffe < uVar3);
    size_local = size_local - 1;
    data_local = puVar1;
    curBufferPos = uVar2;
    if (uVar2 == 0x40) {
      curBufferPos = 0;
      Sha256_WriteByteBlock(p);
    }
  }
  return;
}




void Sha256_Final(CSha256 *p,uint8_t *digest)

{
  uint8_t *puVar1;
  uint uVar2;
  uint8_t *digest_local;
  CSha256 *p_local;
  uint i;
  uint32_t curBufferPos;
  uint64_t lenInBits;
  
  uVar2 = (uint)p->count;
  lenInBits._4_4_ = *(int *)((int)&p->count + 4) << 3 | uVar2 >> 0x1d;
  lenInBits._0_4_ = uVar2 << 3;
  uVar2 = (uint)p->count & 0x3f;
  p->buffer[uVar2] = 0x80;
  while (curBufferPos = uVar2 + 1, curBufferPos != 0x38) {
    uVar2 = curBufferPos & 0x3f;
    if (uVar2 == 0) {
      Sha256_WriteByteBlock(p);
    }
    p->buffer[uVar2] = '\0';
  }
  for (i = 0; i < 8; i = i + 1) {
    p->buffer[curBufferPos] = (uint8_t)(lenInBits._4_4_ >> 0x18);
    lenInBits._4_4_ = lenInBits._4_4_ << 8 | (uint)lenInBits >> 0x18;
    lenInBits._0_4_ = (uint)lenInBits << 8;
    curBufferPos = curBufferPos + 1;
  }
  Sha256_WriteByteBlock(p);
  digest_local = digest;
  for (i = 0; i < 8; i = i + 1) {
    *digest_local = (uint8_t)(p->state[i] >> 0x18);
    digest_local[1] = (uint8_t)(p->state[i] >> 0x10);
    puVar1 = digest_local + 3;
    digest_local[2] = (uint8_t)(p->state[i] >> 8);
    digest_local = digest_local + 4;
    *puVar1 = (uint8_t)p->state[i];
  }
  Sha256_Init(p);
  return;
}




void Sha256_Onestep(uint8_t *data,size_t size,uint8_t *digest)

{
  uint8_t *digest_local;
  size_t size_local;
  uint8_t *data_local;
  CSha256 p;
  
  Sha256_Init(&p);
  Sha256_Update(&p,data,size);
  Sha256_Final(&p,digest);
  return;
}




void sha2_starts(sha2_context *ctx)

{
  sha2_context *ctx_local;
  
  ctx->total[0] = 0;
  ctx->total[1] = 0;
  ctx->state[0] = 0x6a09e667;
  ctx->state[1] = 0xbb67ae85;
  ctx->state[2] = 0x3c6ef372;
  ctx->state[3] = 0xa54ff53a;
  ctx->state[4] = 0x510e527f;
  ctx->state[5] = 0x9b05688c;
  ctx->state[6] = 0x1f83d9ab;
  ctx->state[7] = 0x5be0cd19;
  return;
}




void sha2_process(sha2_context *ctx,uchar *data)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  int iVar39;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uchar *data_local;
  sha2_context *ctx_local;
  uint32_t W [64];
  uint32_t temp2;
  uint32_t temp1;
  uint32_t H;
  uint32_t G;
  uint32_t F;
  uint32_t E;
  uint32_t D;
  uint32_t C;
  uint32_t B;
  uint32_t A;
  
  uVar1 = (uint)data[3] | (uint)data[2] << 8 | (uint)*data << 0x18 | (uint)data[1] << 0x10;
  uVar2 = (uint)data[4] << 0x18 | (uint)data[5] << 0x10;
  uVar3 = (uint)data[7] | (uint)data[6] << 8 | uVar2;
  uVar4 = (uint)data[8] << 0x18 | (uint)data[9] << 0x10;
  uVar5 = (uint)data[0xb] | (uint)data[10] << 8 | uVar4;
  uVar6 = (uint)data[0xc] << 0x18 | (uint)data[0xd] << 0x10;
  uVar7 = (uint)data[0xf] | (uint)data[0xe] << 8 | uVar6;
  uVar8 = (uint)data[0x10] << 0x18 | (uint)data[0x11] << 0x10;
  uVar9 = (uint)data[0x13] | (uint)data[0x12] << 8 | uVar8;
  uVar10 = (uint)data[0x14] << 0x18 | (uint)data[0x15] << 0x10;
  uVar11 = (uint)data[0x17] | (uint)data[0x16] << 8 | uVar10;
  uVar12 = (uint)data[0x18] << 0x18 | (uint)data[0x19] << 0x10;
  uVar13 = (uint)data[0x1b] | (uint)data[0x1a] << 8 | uVar12;
  uVar14 = (uint)data[0x1c] << 0x18 | (uint)data[0x1d] << 0x10;
  uVar15 = (uint)data[0x1f] | (uint)data[0x1e] << 8 | uVar14;
  uVar16 = (uint)data[0x20] << 0x18 | (uint)data[0x21] << 0x10;
  uVar17 = (uint)data[0x23] | (uint)data[0x22] << 8 | uVar16;
  uVar18 = (uint)data[0x24] << 0x18 | (uint)data[0x25] << 0x10;
  uVar19 = (uint)data[0x27] | (uint)data[0x26] << 8 | uVar18;
  uVar20 = (uint)data[0x28] << 0x18 | (uint)data[0x29] << 0x10;
  uVar21 = (uint)data[0x2b] | (uint)data[0x2a] << 8 | uVar20;
  uVar22 = (uint)data[0x2c] << 0x18 | (uint)data[0x2d] << 0x10;
  uVar23 = (uint)data[0x2f] | (uint)data[0x2e] << 8 | uVar22;
  uVar24 = (uint)data[0x30] << 0x18 | (uint)data[0x31] << 0x10;
  uVar25 = (uint)data[0x33] | (uint)data[0x32] << 8 | uVar24;
  uVar26 = (uint)data[0x34] << 0x18 | (uint)data[0x35] << 0x10;
  uVar27 = (uint)data[0x37] | (uint)data[0x36] << 8 | uVar26;
  uVar28 = (uint)data[0x38] << 0x18 | (uint)data[0x39] << 0x10;
  uVar32 = (uint)data[0x3a] << 8 | uVar28;
  uVar29 = data[0x3b] | uVar32;
  uVar30 = (uint)data[0x3c] << 0x18 | (uint)data[0x3d] << 0x10;
  uVar33 = (uint)data[0x3e] << 8 | uVar30;
  uVar31 = data[0x3f] | uVar33;
  uVar34 = ctx->state[0];
  uVar35 = ctx->state[1];
  uVar36 = ctx->state[4];
  uVar37 = ctx->state[5];
  uVar38 = ctx->state[6];
  iVar39 = ((uVar36 >> 6 | uVar36 << 0x1a) ^ (uVar36 >> 0xb | uVar36 << 0x15) ^ (uVar36 >> 0x19 | uVar36 << 7)) +
           ctx->state[7] + (uVar38 ^ (uVar37 ^ uVar38) & uVar36) + uVar1 + 0x428a2f98;
  uVar40 = iVar39 + ctx->state[3];
  uVar41 = (ctx->state[2] & (uVar34 | uVar35) | uVar34 & uVar35) +
           ((uVar34 >> 2 | uVar34 << 0x1e) ^ (uVar34 >> 0xd | uVar34 << 0x13) ^ (uVar34 >> 0x16 | uVar34 << 10)) +
           iVar39;
  iVar39 = ((uVar40 >> 6 | uVar40 * 0x4000000) ^ (uVar40 >> 0xb | uVar40 * 0x200000) ^ (uVar40 >> 0x19 | uVar40 * 0x80))
           + uVar38 + (uVar37 ^ (uVar36 ^ uVar37) & uVar40) + uVar3 + 0x71374491;
  uVar38 = iVar39 + ctx->state[2];
  uVar42 = (uVar35 & (uVar41 | uVar34) | uVar41 & uVar34) +
           ((uVar41 >> 2 | uVar41 * 0x40000000) ^ (uVar41 >> 0xd | uVar41 * 0x80000) ^ (uVar41 >> 0x16 | uVar41 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar38 >> 6 | uVar38 * 0x4000000) ^ (uVar38 >> 0xb | uVar38 * 0x200000) ^ (uVar38 >> 0x19 | uVar38 * 0x80))
           + uVar37 + (uVar36 ^ (uVar40 ^ uVar36) & uVar38) + uVar5 + -0x4a3f0431;
  uVar35 = iVar39 + uVar35;
  uVar37 = (uVar34 & (uVar42 | uVar41) | uVar42 & uVar41) +
           ((uVar42 >> 2 | uVar42 * 0x40000000) ^ (uVar42 >> 0xd | uVar42 * 0x80000) ^ (uVar42 >> 0x16 | uVar42 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar35 >> 6 | uVar35 * 0x4000000) ^ (uVar35 >> 0xb | uVar35 * 0x200000) ^ (uVar35 >> 0x19 | uVar35 * 0x80))
           + uVar36 + (uVar40 ^ (uVar38 ^ uVar40) & uVar35) + uVar7 + -0x164a245b;
  uVar34 = iVar39 + uVar34;
  uVar36 = (uVar41 & (uVar37 | uVar42) | uVar37 & uVar42) +
           ((uVar37 >> 2 | uVar37 * 0x40000000) ^ (uVar37 >> 0xd | uVar37 * 0x80000) ^ (uVar37 >> 0x16 | uVar37 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar34 >> 6 | uVar34 * 0x4000000) ^ (uVar34 >> 0xb | uVar34 * 0x200000) ^ (uVar34 >> 0x19 | uVar34 * 0x80))
           + uVar40 + (uVar38 ^ (uVar35 ^ uVar38) & uVar34) + uVar9 + 0x3956c25b;
  uVar41 = iVar39 + uVar41;
  uVar40 = (uVar42 & (uVar36 | uVar37) | uVar36 & uVar37) +
           ((uVar36 >> 2 | uVar36 * 0x40000000) ^ (uVar36 >> 0xd | uVar36 * 0x80000) ^ (uVar36 >> 0x16 | uVar36 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar41 >> 6 | uVar41 * 0x4000000) ^ (uVar41 >> 0xb | uVar41 * 0x200000) ^ (uVar41 >> 0x19 | uVar41 * 0x80))
           + uVar38 + (uVar35 ^ (uVar34 ^ uVar35) & uVar41) + uVar11 + 0x59f111f1;
  uVar42 = iVar39 + uVar42;
  uVar38 = (uVar37 & (uVar40 | uVar36) | uVar40 & uVar36) +
           ((uVar40 >> 2 | uVar40 * 0x40000000) ^ (uVar40 >> 0xd | uVar40 * 0x80000) ^ (uVar40 >> 0x16 | uVar40 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar42 >> 6 | uVar42 * 0x4000000) ^ (uVar42 >> 0xb | uVar42 * 0x200000) ^ (uVar42 >> 0x19 | uVar42 * 0x80))
           + uVar35 + (uVar34 ^ (uVar41 ^ uVar34) & uVar42) + uVar13 + -0x6dc07d5c;
  uVar37 = iVar39 + uVar37;
  uVar35 = (uVar36 & (uVar38 | uVar40) | uVar38 & uVar40) +
           ((uVar38 >> 2 | uVar38 * 0x40000000) ^ (uVar38 >> 0xd | uVar38 * 0x80000) ^ (uVar38 >> 0x16 | uVar38 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar37 >> 6 | uVar37 * 0x4000000) ^ (uVar37 >> 0xb | uVar37 * 0x200000) ^ (uVar37 >> 0x19 | uVar37 * 0x80))
           + uVar34 + (uVar41 ^ (uVar42 ^ uVar41) & uVar37) + uVar15 + -0x54e3a12b;
  uVar36 = iVar39 + uVar36;
  uVar34 = (uVar40 & (uVar35 | uVar38) | uVar35 & uVar38) +
           ((uVar35 >> 2 | uVar35 * 0x40000000) ^ (uVar35 >> 0xd | uVar35 * 0x80000) ^ (uVar35 >> 0x16 | uVar35 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar36 >> 6 | uVar36 * 0x4000000) ^ (uVar36 >> 0xb | uVar36 * 0x200000) ^ (uVar36 >> 0x19 | uVar36 * 0x80))
           + uVar41 + (uVar42 ^ (uVar37 ^ uVar42) & uVar36) + uVar17 + -0x27f85568;
  uVar40 = iVar39 + uVar40;
  uVar41 = (uVar38 & (uVar34 | uVar35) | uVar34 & uVar35) +
           ((uVar34 >> 2 | uVar34 * 0x40000000) ^ (uVar34 >> 0xd | uVar34 * 0x80000) ^ (uVar34 >> 0x16 | uVar34 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar40 >> 6 | uVar40 * 0x4000000) ^ (uVar40 >> 0xb | uVar40 * 0x200000) ^ (uVar40 >> 0x19 | uVar40 * 0x80))
           + uVar42 + (uVar37 ^ (uVar36 ^ uVar37) & uVar40) + uVar19 + 0x12835b01;
  uVar38 = iVar39 + uVar38;
  uVar42 = (uVar35 & (uVar41 | uVar34) | uVar41 & uVar34) +
           ((uVar41 >> 2 | uVar41 * 0x40000000) ^ (uVar41 >> 0xd | uVar41 * 0x80000) ^ (uVar41 >> 0x16 | uVar41 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar38 >> 6 | uVar38 * 0x4000000) ^ (uVar38 >> 0xb | uVar38 * 0x200000) ^ (uVar38 >> 0x19 | uVar38 * 0x80))
           + uVar37 + (uVar36 ^ (uVar40 ^ uVar36) & uVar38) + uVar21 + 0x243185be;
  uVar35 = iVar39 + uVar35;
  uVar37 = (uVar34 & (uVar42 | uVar41) | uVar42 & uVar41) +
           ((uVar42 >> 2 | uVar42 * 0x40000000) ^ (uVar42 >> 0xd | uVar42 * 0x80000) ^ (uVar42 >> 0x16 | uVar42 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar35 >> 6 | uVar35 * 0x4000000) ^ (uVar35 >> 0xb | uVar35 * 0x200000) ^ (uVar35 >> 0x19 | uVar35 * 0x80))
           + uVar36 + (uVar40 ^ (uVar38 ^ uVar40) & uVar35) + uVar23 + 0x550c7dc3;
  uVar34 = iVar39 + uVar34;
  uVar36 = (uVar41 & (uVar37 | uVar42) | uVar37 & uVar42) +
           ((uVar37 >> 2 | uVar37 * 0x40000000) ^ (uVar37 >> 0xd | uVar37 * 0x80000) ^ (uVar37 >> 0x16 | uVar37 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar34 >> 6 | uVar34 * 0x4000000) ^ (uVar34 >> 0xb | uVar34 * 0x200000) ^ (uVar34 >> 0x19 | uVar34 * 0x80))
           + uVar40 + (uVar38 ^ (uVar35 ^ uVar38) & uVar34) + uVar25 + 0x72be5d74;
  uVar41 = iVar39 + uVar41;
  uVar40 = (uVar42 & (uVar36 | uVar37) | uVar36 & uVar37) +
           ((uVar36 >> 2 | uVar36 * 0x40000000) ^ (uVar36 >> 0xd | uVar36 * 0x80000) ^ (uVar36 >> 0x16 | uVar36 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar41 >> 6 | uVar41 * 0x4000000) ^ (uVar41 >> 0xb | uVar41 * 0x200000) ^ (uVar41 >> 0x19 | uVar41 * 0x80))
           + uVar38 + (uVar35 ^ (uVar34 ^ uVar35) & uVar41) + uVar27 + -0x7f214e02;
  uVar42 = iVar39 + uVar42;
  uVar38 = (uVar37 & (uVar40 | uVar36) | uVar40 & uVar36) +
           ((uVar40 >> 2 | uVar40 * 0x40000000) ^ (uVar40 >> 0xd | uVar40 * 0x80000) ^ (uVar40 >> 0x16 | uVar40 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar42 >> 6 | uVar42 * 0x4000000) ^ (uVar42 >> 0xb | uVar42 * 0x200000) ^ (uVar42 >> 0x19 | uVar42 * 0x80))
           + uVar35 + (uVar34 ^ (uVar41 ^ uVar34) & uVar42) + uVar29 + -0x6423f959;
  uVar37 = iVar39 + uVar37;
  uVar35 = (uVar36 & (uVar38 | uVar40) | uVar38 & uVar40) +
           ((uVar38 >> 2 | uVar38 * 0x40000000) ^ (uVar38 >> 0xd | uVar38 * 0x80000) ^ (uVar38 >> 0x16 | uVar38 * 0x400)
           ) + iVar39;
  iVar39 = ((uVar37 >> 6 | uVar37 * 0x4000000) ^ (uVar37 >> 0xb | uVar37 * 0x200000) ^ (uVar37 >> 0x19 | uVar37 * 0x80))
           + uVar34 + (uVar41 ^ (uVar42 ^ uVar41) & uVar37) + uVar31 + -0x3e640e8c;
  uVar36 = iVar39 + uVar36;
  uVar34 = (uVar40 & (uVar35 | uVar38) | uVar35 & uVar38) +
           ((uVar35 >> 2 | uVar35 * 0x40000000) ^ (uVar35 >> 0xd | uVar35 * 0x80000) ^ (uVar35 >> 0x16 | uVar35 * 0x400)
           ) + iVar39;
  uVar1 = ((uVar28 >> 0x11 | uVar29 << 0xf) ^ (uVar28 >> 0x13 | uVar29 << 0xd) ^ uVar32 >> 10) + uVar19 +
          (uVar3 >> 3 ^ (uVar3 >> 7 | (uint)data[7] << 0x19) ^ (uVar2 >> 0x12 | uVar3 << 0xe)) + uVar1;
  iVar39 = ((uVar36 >> 6 | uVar36 * 0x4000000) ^ (uVar36 >> 0xb | uVar36 * 0x200000) ^ (uVar36 >> 0x19 | uVar36 * 0x80))
           + uVar41 + (uVar42 ^ (uVar37 ^ uVar42) & uVar36) + uVar1 + -0x1b64963f;
  uVar40 = iVar39 + uVar40;
  uVar2 = (uVar38 & (uVar34 | uVar35) | uVar34 & uVar35) +
          ((uVar34 >> 2 | uVar34 * 0x40000000) ^ (uVar34 >> 0xd | uVar34 * 0x80000) ^ (uVar34 >> 0x16 | uVar34 * 0x400))
          + iVar39;
  uVar3 = ((uVar30 >> 0x11 | uVar31 << 0xf) ^ (uVar30 >> 0x13 | uVar31 << 0xd) ^ uVar33 >> 10) + uVar21 +
          (uVar5 >> 3 ^ (uVar5 >> 7 | (uint)data[0xb] << 0x19) ^ (uVar4 >> 0x12 | uVar5 << 0xe)) + uVar3;
  iVar39 = ((uVar40 >> 6 | uVar40 * 0x4000000) ^ (uVar40 >> 0xb | uVar40 * 0x200000) ^ (uVar40 >> 0x19 | uVar40 * 0x80))
           + uVar42 + (uVar37 ^ (uVar36 ^ uVar37) & uVar40) + uVar3 + -0x1041b87a;
  uVar38 = iVar39 + uVar38;
  uVar4 = (uVar35 & (uVar2 | uVar34) | uVar2 & uVar34) +
          ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^ (uVar2 >> 0x16 | uVar2 * 0x400)) +
          iVar39;
  uVar5 = ((uVar1 >> 0x11 | uVar1 * 0x8000) ^ (uVar1 >> 0x13 | uVar1 * 0x2000) ^ uVar1 >> 10) + uVar23 +
          (uVar7 >> 3 ^ (uVar7 >> 7 | (uint)data[0xf] << 0x19) ^ (uVar6 >> 0x12 | uVar7 << 0xe)) + uVar5;
  iVar39 = ((uVar38 >> 6 | uVar38 * 0x4000000) ^ (uVar38 >> 0xb | uVar38 * 0x200000) ^ (uVar38 >> 0x19 | uVar38 * 0x80))
           + uVar37 + (uVar36 ^ (uVar40 ^ uVar36) & uVar38) + uVar5 + 0xfc19dc6;
  uVar35 = iVar39 + uVar35;
  uVar6 = (uVar34 & (uVar4 | uVar2) | uVar4 & uVar2) +
          ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^ (uVar4 >> 0x16 | uVar4 * 0x400)) +
          iVar39;
  uVar7 = ((uVar3 >> 0x11 | uVar3 * 0x8000) ^ (uVar3 >> 0x13 | uVar3 * 0x2000) ^ uVar3 >> 10) + uVar25 +
          (uVar9 >> 3 ^ (uVar9 >> 7 | (uint)data[0x13] << 0x19) ^ (uVar8 >> 0x12 | uVar9 << 0xe)) + uVar7;
  iVar39 = ((uVar35 >> 6 | uVar35 * 0x4000000) ^ (uVar35 >> 0xb | uVar35 * 0x200000) ^ (uVar35 >> 0x19 | uVar35 * 0x80))
           + uVar36 + (uVar40 ^ (uVar38 ^ uVar40) & uVar35) + uVar7 + 0x240ca1cc;
  uVar34 = iVar39 + uVar34;
  uVar8 = (uVar2 & (uVar6 | uVar4) | uVar6 & uVar4) +
          ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^ (uVar6 >> 0x16 | uVar6 * 0x400)) +
          iVar39;
  uVar9 = ((uVar5 >> 0x11 | uVar5 * 0x8000) ^ (uVar5 >> 0x13 | uVar5 * 0x2000) ^ uVar5 >> 10) + uVar27 +
          (uVar11 >> 3 ^ (uVar11 >> 7 | (uint)data[0x17] << 0x19) ^ (uVar10 >> 0x12 | uVar11 << 0xe)) + uVar9;
  iVar39 = ((uVar34 >> 6 | uVar34 * 0x4000000) ^ (uVar34 >> 0xb | uVar34 * 0x200000) ^ (uVar34 >> 0x19 | uVar34 * 0x80))
           + uVar40 + (uVar38 ^ (uVar35 ^ uVar38) & uVar34) + uVar9 + 0x2de92c6f;
  uVar2 = iVar39 + uVar2;
  uVar10 = (uVar4 & (uVar8 | uVar6) | uVar8 & uVar6) +
           ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^ (uVar8 >> 0x16 | uVar8 * 0x400)) +
           iVar39;
  uVar11 = ((uVar7 >> 0x11 | uVar7 * 0x8000) ^ (uVar7 >> 0x13 | uVar7 * 0x2000) ^ uVar7 >> 10) + uVar29 +
           (uVar13 >> 3 ^ (uVar13 >> 7 | (uint)data[0x1b] << 0x19) ^ (uVar12 >> 0x12 | uVar13 << 0xe)) + uVar11;
  iVar39 = ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^ (uVar2 >> 0x19 | uVar2 * 0x80)) +
           uVar38 + (uVar35 ^ (uVar34 ^ uVar35) & uVar2) + uVar11 + 0x4a7484aa;
  uVar4 = iVar39 + uVar4;
  uVar12 = (uVar6 & (uVar10 | uVar8) | uVar10 & uVar8) +
           ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^ (uVar10 >> 0x16 | uVar10 * 0x400)
           ) + iVar39;
  uVar13 = ((uVar9 >> 0x11 | uVar9 * 0x8000) ^ (uVar9 >> 0x13 | uVar9 * 0x2000) ^ uVar9 >> 10) + uVar31 +
           (uVar15 >> 3 ^ (uVar15 >> 7 | (uint)data[0x1f] << 0x19) ^ (uVar14 >> 0x12 | uVar15 << 0xe)) + uVar13;
  iVar39 = ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^ (uVar4 >> 0x19 | uVar4 * 0x80)) +
           uVar35 + (uVar34 ^ (uVar2 ^ uVar34) & uVar4) + uVar13 + 0x5cb0a9dc;
  uVar6 = iVar39 + uVar6;
  uVar14 = (uVar8 & (uVar12 | uVar10) | uVar12 & uVar10) +
           ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^ (uVar12 >> 0x16 | uVar12 * 0x400)
           ) + iVar39;
  uVar15 = ((uVar11 >> 0x11 | uVar11 * 0x8000) ^ (uVar11 >> 0x13 | uVar11 * 0x2000) ^ uVar11 >> 10) + uVar1 +
           (uVar17 >> 3 ^ (uVar17 >> 7 | (uint)data[0x23] << 0x19) ^ (uVar16 >> 0x12 | uVar17 << 0xe)) + uVar15;
  iVar39 = ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^ (uVar6 >> 0x19 | uVar6 * 0x80)) +
           uVar34 + (uVar2 ^ (uVar4 ^ uVar2) & uVar6) + uVar15 + 0x76f988da;
  uVar8 = iVar39 + uVar8;
  uVar16 = (uVar10 & (uVar14 | uVar12) | uVar14 & uVar12) +
           ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^ (uVar14 >> 0x16 | uVar14 * 0x400)
           ) + iVar39;
  uVar17 = ((uVar13 >> 0x11 | uVar13 * 0x8000) ^ (uVar13 >> 0x13 | uVar13 * 0x2000) ^ uVar13 >> 10) + uVar3 +
           (uVar19 >> 3 ^ (uVar19 >> 7 | (uint)data[0x27] << 0x19) ^ (uVar18 >> 0x12 | uVar19 << 0xe)) + uVar17;
  iVar39 = ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^ (uVar8 >> 0x19 | uVar8 * 0x80)) +
           uVar2 + (uVar4 ^ (uVar6 ^ uVar4) & uVar8) + uVar17 + -0x67c1aeae;
  uVar10 = iVar39 + uVar10;
  uVar2 = (uVar12 & (uVar16 | uVar14) | uVar16 & uVar14) +
          ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^ (uVar16 >> 0x16 | uVar16 * 0x400))
          + iVar39;
  uVar19 = ((uVar15 >> 0x11 | uVar15 * 0x8000) ^ (uVar15 >> 0x13 | uVar15 * 0x2000) ^ uVar15 >> 10) + uVar5 +
           (uVar21 >> 3 ^ (uVar21 >> 7 | (uint)data[0x2b] << 0x19) ^ (uVar20 >> 0x12 | uVar21 << 0xe)) + uVar19;
  iVar39 = ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^ (uVar10 >> 0x19 | uVar10 * 0x80))
           + uVar4 + (uVar6 ^ (uVar8 ^ uVar6) & uVar10) + uVar19 + -0x57ce3993;
  uVar12 = iVar39 + uVar12;
  uVar4 = (uVar14 & (uVar2 | uVar16) | uVar2 & uVar16) +
          ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^ (uVar2 >> 0x16 | uVar2 * 0x400)) +
          iVar39;
  uVar21 = ((uVar17 >> 0x11 | uVar17 * 0x8000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000) ^ uVar17 >> 10) + uVar7 +
           (uVar23 >> 3 ^ (uVar23 >> 7 | (uint)data[0x2f] << 0x19) ^ (uVar22 >> 0x12 | uVar23 << 0xe)) + uVar21;
  iVar39 = ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^ (uVar12 >> 0x19 | uVar12 * 0x80))
           + uVar6 + (uVar8 ^ (uVar10 ^ uVar8) & uVar12) + uVar21 + -0x4ffcd838;
  uVar14 = iVar39 + uVar14;
  uVar6 = (uVar16 & (uVar4 | uVar2) | uVar4 & uVar2) +
          ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^ (uVar4 >> 0x16 | uVar4 * 0x400)) +
          iVar39;
  uVar23 = ((uVar19 >> 0x11 | uVar19 * 0x8000) ^ (uVar19 >> 0x13 | uVar19 * 0x2000) ^ uVar19 >> 10) + uVar9 +
           (uVar25 >> 3 ^ (uVar25 >> 7 | (uint)data[0x33] << 0x19) ^ (uVar24 >> 0x12 | uVar25 << 0xe)) + uVar23;
  iVar39 = ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^ (uVar14 >> 0x19 | uVar14 * 0x80))
           + uVar8 + (uVar10 ^ (uVar12 ^ uVar10) & uVar14) + uVar23 + -0x40a68039;
  uVar16 = iVar39 + uVar16;
  uVar8 = (uVar2 & (uVar6 | uVar4) | uVar6 & uVar4) +
          ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^ (uVar6 >> 0x16 | uVar6 * 0x400)) +
          iVar39;
  uVar25 = ((uVar21 >> 0x11 | uVar21 * 0x8000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000) ^ uVar21 >> 10) + uVar11 +
           (uVar27 >> 3 ^ (uVar27 >> 7 | (uint)data[0x37] << 0x19) ^ (uVar26 >> 0x12 | uVar27 << 0xe)) + uVar25;
  iVar39 = ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^ (uVar16 >> 0x19 | uVar16 * 0x80))
           + uVar10 + (uVar12 ^ (uVar14 ^ uVar12) & uVar16) + uVar25 + -0x391ff40d;
  uVar2 = iVar39 + uVar2;
  uVar10 = (uVar4 & (uVar8 | uVar6) | uVar8 & uVar6) +
           ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^ (uVar8 >> 0x16 | uVar8 * 0x400)) +
           iVar39;
  uVar27 = ((uVar23 >> 0x11 | uVar23 * 0x8000) ^ (uVar23 >> 0x13 | uVar23 * 0x2000) ^ uVar23 >> 10) + uVar13 +
           (uVar29 >> 3 ^ (uVar29 >> 7 | (uint)data[0x3b] << 0x19) ^ (uVar28 >> 0x12 | uVar29 << 0xe)) + uVar27;
  iVar39 = ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^ (uVar2 >> 0x19 | uVar2 * 0x80)) +
           uVar12 + (uVar14 ^ (uVar16 ^ uVar14) & uVar2) + uVar27 + -0x2a586eb9;
  uVar4 = iVar39 + uVar4;
  uVar12 = (uVar6 & (uVar10 | uVar8) | uVar10 & uVar8) +
           ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^ (uVar10 >> 0x16 | uVar10 * 0x400)
           ) + iVar39;
  uVar29 = ((uVar25 >> 0x11 | uVar25 * 0x8000) ^ (uVar25 >> 0x13 | uVar25 * 0x2000) ^ uVar25 >> 10) + uVar15 +
           (uVar31 >> 3 ^ (uVar31 >> 7 | (uint)data[0x3f] << 0x19) ^ (uVar30 >> 0x12 | uVar31 << 0xe)) + uVar29;
  iVar39 = ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^ (uVar4 >> 0x19 | uVar4 * 0x80)) +
           uVar14 + (uVar16 ^ (uVar2 ^ uVar16) & uVar4) + uVar29 + 0x6ca6351;
  uVar6 = iVar39 + uVar6;
  uVar14 = (uVar8 & (uVar12 | uVar10) | uVar12 & uVar10) +
           ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^ (uVar12 >> 0x16 | uVar12 * 0x400)
           ) + iVar39;
  uVar31 = ((uVar27 >> 0x11 | uVar27 * 0x8000) ^ (uVar27 >> 0x13 | uVar27 * 0x2000) ^ uVar27 >> 10) + uVar17 +
           (uVar1 >> 3 ^ (uVar1 >> 7 | uVar1 * 0x2000000) ^ (uVar1 >> 0x12 | uVar1 * 0x4000)) + uVar31;
  iVar39 = ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^ (uVar6 >> 0x19 | uVar6 * 0x80)) +
           uVar16 + (uVar2 ^ (uVar4 ^ uVar2) & uVar6) + uVar31 + 0x14292967;
  uVar8 = iVar39 + uVar8;
  uVar16 = (uVar10 & (uVar14 | uVar12) | uVar14 & uVar12) +
           ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^ (uVar14 >> 0x16 | uVar14 * 0x400)
           ) + iVar39;
  uVar1 = ((uVar29 >> 0x11 | uVar29 * 0x8000) ^ (uVar29 >> 0x13 | uVar29 * 0x2000) ^ uVar29 >> 10) + uVar19 +
          (uVar3 >> 3 ^ (uVar3 >> 7 | uVar3 * 0x2000000) ^ (uVar3 >> 0x12 | uVar3 * 0x4000)) + uVar1;
  iVar39 = ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^ (uVar8 >> 0x19 | uVar8 * 0x80)) +
           uVar2 + (uVar4 ^ (uVar6 ^ uVar4) & uVar8) + uVar1 + 0x27b70a85;
  uVar10 = iVar39 + uVar10;
  uVar2 = (uVar12 & (uVar16 | uVar14) | uVar16 & uVar14) +
          ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^ (uVar16 >> 0x16 | uVar16 * 0x400))
          + iVar39;
  uVar3 = ((uVar31 >> 0x11 | uVar31 * 0x8000) ^ (uVar31 >> 0x13 | uVar31 * 0x2000) ^ uVar31 >> 10) + uVar21 +
          (uVar5 >> 3 ^ (uVar5 >> 7 | uVar5 * 0x2000000) ^ (uVar5 >> 0x12 | uVar5 * 0x4000)) + uVar3;
  iVar39 = ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^ (uVar10 >> 0x19 | uVar10 * 0x80))
           + uVar4 + (uVar6 ^ (uVar8 ^ uVar6) & uVar10) + uVar3 + 0x2e1b2138;
  uVar12 = iVar39 + uVar12;
  uVar4 = (uVar14 & (uVar2 | uVar16) | uVar2 & uVar16) +
          ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^ (uVar2 >> 0x16 | uVar2 * 0x400)) +
          iVar39;
  uVar5 = ((uVar1 >> 0x11 | uVar1 * 0x8000) ^ (uVar1 >> 0x13 | uVar1 * 0x2000) ^ uVar1 >> 10) + uVar23 +
          (uVar7 >> 3 ^ (uVar7 >> 7 | uVar7 * 0x2000000) ^ (uVar7 >> 0x12 | uVar7 * 0x4000)) + uVar5;
  iVar39 = ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^ (uVar12 >> 0x19 | uVar12 * 0x80))
           + uVar6 + (uVar8 ^ (uVar10 ^ uVar8) & uVar12) + uVar5 + 0x4d2c6dfc;
  uVar14 = iVar39 + uVar14;
  uVar6 = (uVar16 & (uVar4 | uVar2) | uVar4 & uVar2) +
          ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^ (uVar4 >> 0x16 | uVar4 * 0x400)) +
          iVar39;
  uVar7 = ((uVar3 >> 0x11 | uVar3 * 0x8000) ^ (uVar3 >> 0x13 | uVar3 * 0x2000) ^ uVar3 >> 10) + uVar25 +
          (uVar9 >> 3 ^ (uVar9 >> 7 | uVar9 * 0x2000000) ^ (uVar9 >> 0x12 | uVar9 * 0x4000)) + uVar7;
  iVar39 = ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^ (uVar14 >> 0x19 | uVar14 * 0x80))
           + uVar8 + (uVar10 ^ (uVar12 ^ uVar10) & uVar14) + uVar7 + 0x53380d13;
  uVar16 = iVar39 + uVar16;
  uVar8 = (uVar2 & (uVar6 | uVar4) | uVar6 & uVar4) +
          ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^ (uVar6 >> 0x16 | uVar6 * 0x400)) +
          iVar39;
  uVar9 = ((uVar5 >> 0x11 | uVar5 * 0x8000) ^ (uVar5 >> 0x13 | uVar5 * 0x2000) ^ uVar5 >> 10) + uVar27 +
          (uVar11 >> 3 ^ (uVar11 >> 7 | uVar11 * 0x2000000) ^ (uVar11 >> 0x12 | uVar11 * 0x4000)) + uVar9;
  iVar39 = ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^ (uVar16 >> 0x19 | uVar16 * 0x80))
           + uVar10 + (uVar12 ^ (uVar14 ^ uVar12) & uVar16) + uVar9 + 0x650a7354;
  uVar2 = iVar39 + uVar2;
  uVar10 = (uVar4 & (uVar8 | uVar6) | uVar8 & uVar6) +
           ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^ (uVar8 >> 0x16 | uVar8 * 0x400)) +
           iVar39;
  uVar11 = ((uVar7 >> 0x11 | uVar7 * 0x8000) ^ (uVar7 >> 0x13 | uVar7 * 0x2000) ^ uVar7 >> 10) + uVar29 +
           (uVar13 >> 3 ^ (uVar13 >> 7 | uVar13 * 0x2000000) ^ (uVar13 >> 0x12 | uVar13 * 0x4000)) + uVar11;
  iVar39 = ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^ (uVar2 >> 0x19 | uVar2 * 0x80)) +
           uVar12 + (uVar14 ^ (uVar16 ^ uVar14) & uVar2) + uVar11 + 0x766a0abb;
  uVar4 = iVar39 + uVar4;
  uVar12 = (uVar6 & (uVar10 | uVar8) | uVar10 & uVar8) +
           ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^ (uVar10 >> 0x16 | uVar10 * 0x400)
           ) + iVar39;
  uVar13 = ((uVar9 >> 0x11 | uVar9 * 0x8000) ^ (uVar9 >> 0x13 | uVar9 * 0x2000) ^ uVar9 >> 10) + uVar31 +
           (uVar15 >> 3 ^ (uVar15 >> 7 | uVar15 * 0x2000000) ^ (uVar15 >> 0x12 | uVar15 * 0x4000)) + uVar13;
  iVar39 = ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^ (uVar4 >> 0x19 | uVar4 * 0x80)) +
           uVar14 + (uVar16 ^ (uVar2 ^ uVar16) & uVar4) + uVar13 + -0x7e3d36d2;
  uVar6 = iVar39 + uVar6;
  uVar14 = (uVar8 & (uVar12 | uVar10) | uVar12 & uVar10) +
           ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^ (uVar12 >> 0x16 | uVar12 * 0x400)
           ) + iVar39;
  uVar15 = ((uVar11 >> 0x11 | uVar11 * 0x8000) ^ (uVar11 >> 0x13 | uVar11 * 0x2000) ^ uVar11 >> 10) + uVar1 +
           (uVar17 >> 3 ^ (uVar17 >> 7 | uVar17 * 0x2000000) ^ (uVar17 >> 0x12 | uVar17 * 0x4000)) + uVar15;
  iVar39 = ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^ (uVar6 >> 0x19 | uVar6 * 0x80)) +
           uVar16 + (uVar2 ^ (uVar4 ^ uVar2) & uVar6) + uVar15 + -0x6d8dd37b;
  uVar8 = iVar39 + uVar8;
  uVar16 = (uVar10 & (uVar14 | uVar12) | uVar14 & uVar12) +
           ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^ (uVar14 >> 0x16 | uVar14 * 0x400)
           ) + iVar39;
  uVar17 = ((uVar13 >> 0x11 | uVar13 * 0x8000) ^ (uVar13 >> 0x13 | uVar13 * 0x2000) ^ uVar13 >> 10) + uVar3 +
           (uVar19 >> 3 ^ (uVar19 >> 7 | uVar19 * 0x2000000) ^ (uVar19 >> 0x12 | uVar19 * 0x4000)) + uVar17;
  iVar39 = ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^ (uVar8 >> 0x19 | uVar8 * 0x80)) +
           uVar2 + (uVar4 ^ (uVar6 ^ uVar4) & uVar8) + uVar17 + -0x5d40175f;
  uVar10 = iVar39 + uVar10;
  uVar2 = (uVar12 & (uVar16 | uVar14) | uVar16 & uVar14) +
          ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^ (uVar16 >> 0x16 | uVar16 * 0x400))
          + iVar39;
  uVar19 = ((uVar15 >> 0x11 | uVar15 * 0x8000) ^ (uVar15 >> 0x13 | uVar15 * 0x2000) ^ uVar15 >> 10) + uVar5 +
           (uVar21 >> 3 ^ (uVar21 >> 7 | uVar21 * 0x2000000) ^ (uVar21 >> 0x12 | uVar21 * 0x4000)) + uVar19;
  iVar39 = ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^ (uVar10 >> 0x19 | uVar10 * 0x80))
           + uVar4 + (uVar6 ^ (uVar8 ^ uVar6) & uVar10) + uVar19 + -0x57e599b5;
  uVar12 = iVar39 + uVar12;
  uVar4 = (uVar14 & (uVar2 | uVar16) | uVar2 & uVar16) +
          ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^ (uVar2 >> 0x16 | uVar2 * 0x400)) +
          iVar39;
  uVar21 = ((uVar17 >> 0x11 | uVar17 * 0x8000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000) ^ uVar17 >> 10) + uVar7 +
           (uVar23 >> 3 ^ (uVar23 >> 7 | uVar23 * 0x2000000) ^ (uVar23 >> 0x12 | uVar23 * 0x4000)) + uVar21;
  iVar39 = ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^ (uVar12 >> 0x19 | uVar12 * 0x80))
           + uVar6 + (uVar8 ^ (uVar10 ^ uVar8) & uVar12) + uVar21 + -0x3db47490;
  uVar14 = iVar39 + uVar14;
  uVar6 = (uVar16 & (uVar4 | uVar2) | uVar4 & uVar2) +
          ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^ (uVar4 >> 0x16 | uVar4 * 0x400)) +
          iVar39;
  uVar23 = ((uVar19 >> 0x11 | uVar19 * 0x8000) ^ (uVar19 >> 0x13 | uVar19 * 0x2000) ^ uVar19 >> 10) + uVar9 +
           (uVar25 >> 3 ^ (uVar25 >> 7 | uVar25 * 0x2000000) ^ (uVar25 >> 0x12 | uVar25 * 0x4000)) + uVar23;
  iVar39 = ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^ (uVar14 >> 0x19 | uVar14 * 0x80))
           + uVar8 + (uVar10 ^ (uVar12 ^ uVar10) & uVar14) + uVar23 + -0x3893ae5d;
  uVar16 = iVar39 + uVar16;
  uVar8 = (uVar2 & (uVar6 | uVar4) | uVar6 & uVar4) +
          ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^ (uVar6 >> 0x16 | uVar6 * 0x400)) +
          iVar39;
  uVar25 = ((uVar21 >> 0x11 | uVar21 * 0x8000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000) ^ uVar21 >> 10) + uVar11 +
           (uVar27 >> 3 ^ (uVar27 >> 7 | uVar27 * 0x2000000) ^ (uVar27 >> 0x12 | uVar27 * 0x4000)) + uVar25;
  iVar39 = ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^ (uVar16 >> 0x19 | uVar16 * 0x80))
           + uVar10 + (uVar12 ^ (uVar14 ^ uVar12) & uVar16) + uVar25 + -0x2e6d17e7;
  uVar2 = iVar39 + uVar2;
  uVar10 = (uVar4 & (uVar8 | uVar6) | uVar8 & uVar6) +
           ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^ (uVar8 >> 0x16 | uVar8 * 0x400)) +
           iVar39;
  uVar27 = ((uVar23 >> 0x11 | uVar23 * 0x8000) ^ (uVar23 >> 0x13 | uVar23 * 0x2000) ^ uVar23 >> 10) + uVar13 +
           (uVar29 >> 3 ^ (uVar29 >> 7 | uVar29 * 0x2000000) ^ (uVar29 >> 0x12 | uVar29 * 0x4000)) + uVar27;
  iVar39 = ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^ (uVar2 >> 0x19 | uVar2 * 0x80)) +
           uVar12 + (uVar14 ^ (uVar16 ^ uVar14) & uVar2) + uVar27 + -0x2966f9dc;
  uVar4 = iVar39 + uVar4;
  uVar12 = (uVar6 & (uVar10 | uVar8) | uVar10 & uVar8) +
           ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^ (uVar10 >> 0x16 | uVar10 * 0x400)
           ) + iVar39;
  uVar29 = ((uVar25 >> 0x11 | uVar25 * 0x8000) ^ (uVar25 >> 0x13 | uVar25 * 0x2000) ^ uVar25 >> 10) + uVar15 +
           (uVar31 >> 3 ^ (uVar31 >> 7 | uVar31 * 0x2000000) ^ (uVar31 >> 0x12 | uVar31 * 0x4000)) + uVar29;
  iVar39 = ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^ (uVar4 >> 0x19 | uVar4 * 0x80)) +
           uVar14 + (uVar16 ^ (uVar2 ^ uVar16) & uVar4) + uVar29 + -0xbf1ca7b;
  uVar6 = iVar39 + uVar6;
  uVar14 = (uVar8 & (uVar12 | uVar10) | uVar12 & uVar10) +
           ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^ (uVar12 >> 0x16 | uVar12 * 0x400)
           ) + iVar39;
  uVar31 = ((uVar27 >> 0x11 | uVar27 * 0x8000) ^ (uVar27 >> 0x13 | uVar27 * 0x2000) ^ uVar27 >> 10) + uVar17 +
           (uVar1 >> 3 ^ (uVar1 >> 7 | uVar1 * 0x2000000) ^ (uVar1 >> 0x12 | uVar1 * 0x4000)) + uVar31;
  iVar39 = ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^ (uVar6 >> 0x19 | uVar6 * 0x80)) +
           uVar16 + (uVar2 ^ (uVar4 ^ uVar2) & uVar6) + uVar31 + 0x106aa070;
  uVar8 = iVar39 + uVar8;
  uVar16 = (uVar10 & (uVar14 | uVar12) | uVar14 & uVar12) +
           ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^ (uVar14 >> 0x16 | uVar14 * 0x400)
           ) + iVar39;
  uVar1 = ((uVar29 >> 0x11 | uVar29 * 0x8000) ^ (uVar29 >> 0x13 | uVar29 * 0x2000) ^ uVar29 >> 10) + uVar19 +
          (uVar3 >> 3 ^ (uVar3 >> 7 | uVar3 * 0x2000000) ^ (uVar3 >> 0x12 | uVar3 * 0x4000)) + uVar1;
  iVar39 = ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^ (uVar8 >> 0x19 | uVar8 * 0x80)) +
           uVar2 + (uVar4 ^ (uVar6 ^ uVar4) & uVar8) + uVar1 + 0x19a4c116;
  uVar10 = iVar39 + uVar10;
  uVar2 = (uVar12 & (uVar16 | uVar14) | uVar16 & uVar14) +
          ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^ (uVar16 >> 0x16 | uVar16 * 0x400))
          + iVar39;
  uVar3 = ((uVar31 >> 0x11 | uVar31 * 0x8000) ^ (uVar31 >> 0x13 | uVar31 * 0x2000) ^ uVar31 >> 10) + uVar21 +
          (uVar5 >> 3 ^ (uVar5 >> 7 | uVar5 * 0x2000000) ^ (uVar5 >> 0x12 | uVar5 * 0x4000)) + uVar3;
  iVar39 = ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^ (uVar10 >> 0x19 | uVar10 * 0x80))
           + uVar4 + (uVar6 ^ (uVar8 ^ uVar6) & uVar10) + uVar3 + 0x1e376c08;
  uVar12 = iVar39 + uVar12;
  uVar4 = (uVar14 & (uVar2 | uVar16) | uVar2 & uVar16) +
          ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^ (uVar2 >> 0x16 | uVar2 * 0x400)) +
          iVar39;
  uVar5 = ((uVar1 >> 0x11 | uVar1 * 0x8000) ^ (uVar1 >> 0x13 | uVar1 * 0x2000) ^ uVar1 >> 10) + uVar23 +
          (uVar7 >> 3 ^ (uVar7 >> 7 | uVar7 * 0x2000000) ^ (uVar7 >> 0x12 | uVar7 * 0x4000)) + uVar5;
  iVar39 = ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^ (uVar12 >> 0x19 | uVar12 * 0x80))
           + uVar6 + (uVar8 ^ (uVar10 ^ uVar8) & uVar12) + uVar5 + 0x2748774c;
  uVar14 = iVar39 + uVar14;
  uVar6 = (uVar16 & (uVar4 | uVar2) | uVar4 & uVar2) +
          ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^ (uVar4 >> 0x16 | uVar4 * 0x400)) +
          iVar39;
  uVar7 = ((uVar3 >> 0x11 | uVar3 * 0x8000) ^ (uVar3 >> 0x13 | uVar3 * 0x2000) ^ uVar3 >> 10) + uVar25 +
          (uVar9 >> 3 ^ (uVar9 >> 7 | uVar9 * 0x2000000) ^ (uVar9 >> 0x12 | uVar9 * 0x4000)) + uVar7;
  iVar39 = ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^ (uVar14 >> 0x19 | uVar14 * 0x80))
           + uVar8 + (uVar10 ^ (uVar12 ^ uVar10) & uVar14) + uVar7 + 0x34b0bcb5;
  uVar16 = iVar39 + uVar16;
  uVar8 = (uVar2 & (uVar6 | uVar4) | uVar6 & uVar4) +
          ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^ (uVar6 >> 0x16 | uVar6 * 0x400)) +
          iVar39;
  uVar9 = ((uVar5 >> 0x11 | uVar5 * 0x8000) ^ (uVar5 >> 0x13 | uVar5 * 0x2000) ^ uVar5 >> 10) + uVar27 +
          (uVar11 >> 3 ^ (uVar11 >> 7 | uVar11 * 0x2000000) ^ (uVar11 >> 0x12 | uVar11 * 0x4000)) + uVar9;
  iVar39 = ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^ (uVar16 >> 0x19 | uVar16 * 0x80))
           + uVar10 + (uVar12 ^ (uVar14 ^ uVar12) & uVar16) + uVar9 + 0x391c0cb3;
  uVar2 = iVar39 + uVar2;
  uVar10 = (uVar4 & (uVar8 | uVar6) | uVar8 & uVar6) +
           ((uVar8 >> 2 | uVar8 * 0x40000000) ^ (uVar8 >> 0xd | uVar8 * 0x80000) ^ (uVar8 >> 0x16 | uVar8 * 0x400)) +
           iVar39;
  uVar11 = ((uVar7 >> 0x11 | uVar7 * 0x8000) ^ (uVar7 >> 0x13 | uVar7 * 0x2000) ^ uVar7 >> 10) + uVar29 +
           (uVar13 >> 3 ^ (uVar13 >> 7 | uVar13 * 0x2000000) ^ (uVar13 >> 0x12 | uVar13 * 0x4000)) + uVar11;
  iVar39 = ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^ (uVar2 >> 0x19 | uVar2 * 0x80)) +
           uVar12 + (uVar14 ^ (uVar16 ^ uVar14) & uVar2) + uVar11 + 0x4ed8aa4a;
  uVar4 = iVar39 + uVar4;
  uVar12 = (uVar6 & (uVar10 | uVar8) | uVar10 & uVar8) +
           ((uVar10 >> 2 | uVar10 * 0x40000000) ^ (uVar10 >> 0xd | uVar10 * 0x80000) ^ (uVar10 >> 0x16 | uVar10 * 0x400)
           ) + iVar39;
  uVar13 = ((uVar9 >> 0x11 | uVar9 * 0x8000) ^ (uVar9 >> 0x13 | uVar9 * 0x2000) ^ uVar9 >> 10) + uVar31 +
           (uVar15 >> 3 ^ (uVar15 >> 7 | uVar15 * 0x2000000) ^ (uVar15 >> 0x12 | uVar15 * 0x4000)) + uVar13;
  iVar39 = ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^ (uVar4 >> 0x19 | uVar4 * 0x80)) +
           uVar14 + (uVar16 ^ (uVar2 ^ uVar16) & uVar4) + uVar13 + 0x5b9cca4f;
  uVar6 = iVar39 + uVar6;
  uVar14 = (uVar8 & (uVar12 | uVar10) | uVar12 & uVar10) +
           ((uVar12 >> 2 | uVar12 * 0x40000000) ^ (uVar12 >> 0xd | uVar12 * 0x80000) ^ (uVar12 >> 0x16 | uVar12 * 0x400)
           ) + iVar39;
  uVar15 = ((uVar11 >> 0x11 | uVar11 * 0x8000) ^ (uVar11 >> 0x13 | uVar11 * 0x2000) ^ uVar11 >> 10) + uVar1 +
           (uVar17 >> 3 ^ (uVar17 >> 7 | uVar17 * 0x2000000) ^ (uVar17 >> 0x12 | uVar17 * 0x4000)) + uVar15;
  iVar39 = ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^ (uVar6 >> 0x19 | uVar6 * 0x80)) +
           uVar16 + (uVar2 ^ (uVar4 ^ uVar2) & uVar6) + uVar15 + 0x682e6ff3;
  uVar8 = iVar39 + uVar8;
  uVar16 = (uVar10 & (uVar14 | uVar12) | uVar14 & uVar12) +
           ((uVar14 >> 2 | uVar14 * 0x40000000) ^ (uVar14 >> 0xd | uVar14 * 0x80000) ^ (uVar14 >> 0x16 | uVar14 * 0x400)
           ) + iVar39;
  uVar17 = ((uVar13 >> 0x11 | uVar13 * 0x8000) ^ (uVar13 >> 0x13 | uVar13 * 0x2000) ^ uVar13 >> 10) + uVar3 +
           (uVar19 >> 3 ^ (uVar19 >> 7 | uVar19 * 0x2000000) ^ (uVar19 >> 0x12 | uVar19 * 0x4000)) + uVar17;
  iVar39 = ((uVar8 >> 6 | uVar8 * 0x4000000) ^ (uVar8 >> 0xb | uVar8 * 0x200000) ^ (uVar8 >> 0x19 | uVar8 * 0x80)) +
           uVar2 + (uVar4 ^ (uVar6 ^ uVar4) & uVar8) + uVar17 + 0x748f82ee;
  uVar10 = iVar39 + uVar10;
  uVar2 = (uVar12 & (uVar16 | uVar14) | uVar16 & uVar14) +
          ((uVar16 >> 2 | uVar16 * 0x40000000) ^ (uVar16 >> 0xd | uVar16 * 0x80000) ^ (uVar16 >> 0x16 | uVar16 * 0x400))
          + iVar39;
  uVar19 = ((uVar15 >> 0x11 | uVar15 * 0x8000) ^ (uVar15 >> 0x13 | uVar15 * 0x2000) ^ uVar15 >> 10) + uVar5 +
           (uVar21 >> 3 ^ (uVar21 >> 7 | uVar21 * 0x2000000) ^ (uVar21 >> 0x12 | uVar21 * 0x4000)) + uVar19;
  iVar39 = ((uVar10 >> 6 | uVar10 * 0x4000000) ^ (uVar10 >> 0xb | uVar10 * 0x200000) ^ (uVar10 >> 0x19 | uVar10 * 0x80))
           + uVar4 + (uVar6 ^ (uVar8 ^ uVar6) & uVar10) + uVar19 + 0x78a5636f;
  uVar12 = iVar39 + uVar12;
  uVar4 = (uVar14 & (uVar2 | uVar16) | uVar2 & uVar16) +
          ((uVar2 >> 2 | uVar2 * 0x40000000) ^ (uVar2 >> 0xd | uVar2 * 0x80000) ^ (uVar2 >> 0x16 | uVar2 * 0x400)) +
          iVar39;
  uVar21 = ((uVar17 >> 0x11 | uVar17 * 0x8000) ^ (uVar17 >> 0x13 | uVar17 * 0x2000) ^ uVar17 >> 10) + uVar7 +
           (uVar23 >> 3 ^ (uVar23 >> 7 | uVar23 * 0x2000000) ^ (uVar23 >> 0x12 | uVar23 * 0x4000)) + uVar21;
  iVar39 = ((uVar12 >> 6 | uVar12 * 0x4000000) ^ (uVar12 >> 0xb | uVar12 * 0x200000) ^ (uVar12 >> 0x19 | uVar12 * 0x80))
           + uVar6 + (uVar8 ^ (uVar10 ^ uVar8) & uVar12) + uVar21 + -0x7b3787ec;
  uVar14 = iVar39 + uVar14;
  uVar6 = (uVar16 & (uVar4 | uVar2) | uVar4 & uVar2) +
          ((uVar4 >> 2 | uVar4 * 0x40000000) ^ (uVar4 >> 0xd | uVar4 * 0x80000) ^ (uVar4 >> 0x16 | uVar4 * 0x400)) +
          iVar39;
  uVar23 = ((uVar19 >> 0x11 | uVar19 * 0x8000) ^ (uVar19 >> 0x13 | uVar19 * 0x2000) ^ uVar19 >> 10) + uVar9 +
           (uVar25 >> 3 ^ (uVar25 >> 7 | uVar25 * 0x2000000) ^ (uVar25 >> 0x12 | uVar25 * 0x4000)) + uVar23;
  iVar39 = ((uVar14 >> 6 | uVar14 * 0x4000000) ^ (uVar14 >> 0xb | uVar14 * 0x200000) ^ (uVar14 >> 0x19 | uVar14 * 0x80))
           + uVar8 + (uVar10 ^ (uVar12 ^ uVar10) & uVar14) + uVar23 + -0x7338fdf8;
  uVar16 = iVar39 + uVar16;
  uVar3 = (uVar2 & (uVar6 | uVar4) | uVar6 & uVar4) +
          ((uVar6 >> 2 | uVar6 * 0x40000000) ^ (uVar6 >> 0xd | uVar6 * 0x80000) ^ (uVar6 >> 0x16 | uVar6 * 0x400)) +
          iVar39;
  uVar25 = ((uVar21 >> 0x11 | uVar21 * 0x8000) ^ (uVar21 >> 0x13 | uVar21 * 0x2000) ^ uVar21 >> 10) + uVar11 +
           (uVar27 >> 3 ^ (uVar27 >> 7 | uVar27 * 0x2000000) ^ (uVar27 >> 0x12 | uVar27 * 0x4000)) + uVar25;
  iVar39 = ((uVar16 >> 6 | uVar16 * 0x4000000) ^ (uVar16 >> 0xb | uVar16 * 0x200000) ^ (uVar16 >> 0x19 | uVar16 * 0x80))
           + uVar10 + (uVar12 ^ (uVar14 ^ uVar12) & uVar16) + uVar25 + -0x6f410006;
  uVar2 = iVar39 + uVar2;
  uVar5 = (uVar4 & (uVar3 | uVar6) | uVar3 & uVar6) +
          ((uVar3 >> 2 | uVar3 * 0x40000000) ^ (uVar3 >> 0xd | uVar3 * 0x80000) ^ (uVar3 >> 0x16 | uVar3 * 0x400)) +
          iVar39;
  uVar27 = ((uVar23 >> 0x11 | uVar23 * 0x8000) ^ (uVar23 >> 0x13 | uVar23 * 0x2000) ^ uVar23 >> 10) + uVar13 +
           (uVar29 >> 3 ^ (uVar29 >> 7 | uVar29 * 0x2000000) ^ (uVar29 >> 0x12 | uVar29 * 0x4000)) + uVar27;
  iVar39 = ((uVar2 >> 6 | uVar2 * 0x4000000) ^ (uVar2 >> 0xb | uVar2 * 0x200000) ^ (uVar2 >> 0x19 | uVar2 * 0x80)) +
           uVar12 + (uVar14 ^ (uVar16 ^ uVar14) & uVar2) + uVar27 + -0x5baf9315;
  uVar4 = iVar39 + uVar4;
  uVar7 = (uVar6 & (uVar5 | uVar3) | uVar5 & uVar3) +
          ((uVar5 >> 2 | uVar5 * 0x40000000) ^ (uVar5 >> 0xd | uVar5 * 0x80000) ^ (uVar5 >> 0x16 | uVar5 * 0x400)) +
          iVar39;
  iVar39 = ((uVar4 >> 6 | uVar4 * 0x4000000) ^ (uVar4 >> 0xb | uVar4 * 0x200000) ^ (uVar4 >> 0x19 | uVar4 * 0x80)) +
           uVar14 + (uVar16 ^ (uVar2 ^ uVar16) & uVar4) +
           ((uVar25 >> 0x11 | uVar25 * 0x8000) ^ (uVar25 >> 0x13 | uVar25 * 0x2000) ^ uVar25 >> 10) + uVar15 +
           (uVar31 >> 3 ^ (uVar31 >> 7 | uVar31 * 0x2000000) ^ (uVar31 >> 0x12 | uVar31 * 0x4000)) + uVar29 +
           -0x41065c09;
  uVar6 = iVar39 + uVar6;
  uVar29 = (uVar3 & (uVar7 | uVar5) | uVar7 & uVar5) +
           ((uVar7 >> 2 | uVar7 * 0x40000000) ^ (uVar7 >> 0xd | uVar7 * 0x80000) ^ (uVar7 >> 0x16 | uVar7 * 0x400)) +
           iVar39;
  iVar39 = ((uVar6 >> 6 | uVar6 * 0x4000000) ^ (uVar6 >> 0xb | uVar6 * 0x200000) ^ (uVar6 >> 0x19 | uVar6 * 0x80)) +
           uVar16 + (uVar2 ^ (uVar4 ^ uVar2) & uVar6) +
           ((uVar27 >> 0x11 | uVar27 * 0x8000) ^ (uVar27 >> 0x13 | uVar27 * 0x2000) ^ uVar27 >> 10) + uVar17 +
           (uVar1 >> 3 ^ (uVar1 >> 7 | uVar1 * 0x2000000) ^ (uVar1 >> 0x12 | uVar1 * 0x4000)) + uVar31 + -0x398e870e;
  ctx->state[0] =
       ctx->state[0] +
       (uVar5 & (uVar29 | uVar7) | uVar29 & uVar7) +
       ((uVar29 >> 2 | uVar29 * 0x40000000) ^ (uVar29 >> 0xd | uVar29 * 0x80000) ^ (uVar29 >> 0x16 | uVar29 * 0x400)) +
       iVar39;
  ctx->state[1] = ctx->state[1] + uVar29;
  ctx->state[2] = ctx->state[2] + uVar7;
  ctx->state[3] = ctx->state[3] + uVar5;
  ctx->state[4] = ctx->state[4] + iVar39 + uVar3;
  ctx->state[5] = ctx->state[5] + uVar6;
  ctx->state[6] = ctx->state[6] + uVar4;
  ctx->state[7] = ctx->state[7] + uVar2;
  return;
}




void sha2_update(sha2_context *ctx,uchar *input,int ilen)

{
  size_t __n;
  int ilen_local;
  uchar *input_local;
  sha2_context *ctx_local;
  int fill;
  uint32_t left;
  
  if (0 < ilen) {
    left = ctx->total[0] & 0x3f;
    __n = 0x40 - left;
    ctx->total[0] = ctx->total[0] + ilen;
    ctx->total[0] = ctx->total[0];
    if (ctx->total[0] < (uint)ilen) {
      ctx->total[1] = ctx->total[1] + 1;
    }
    ilen_local = ilen;
    input_local = input;
    if ((left != 0) && ((int)__n <= ilen)) {
      memcpy(ctx->buffer + left,input,__n);
      sha2_process(ctx,ctx->buffer);
      input_local = input + __n;
      ilen_local = ilen - __n;
      left = 0;
    }
    for (; 0x3f < ilen_local; ilen_local = ilen_local + -0x40) {
      sha2_process(ctx,input_local);
      input_local = input_local + 0x40;
    }
    if (0 < ilen_local) {
      memcpy(ctx->buffer + left,input_local,ilen_local);
    }
  }
  return;
}




void sha2_finish(sha2_context *ctx,uchar *output)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uchar *output_local;
  sha2_context *ctx_local;
  uchar msglen [8];
  uint32_t padn;
  uint32_t last;
  uint32_t low;
  uint32_t high;
  
  iVar1 = ctx->total[1] << 3;
  msglen[3] = (byte)iVar1 | (byte)(ctx->total[0] >> 0x1d);
  iVar2 = ctx->total[0] << 3;
  msglen[0] = (uchar)((uint)iVar1 >> 0x18);
  msglen[1] = (uchar)((uint)iVar1 >> 0x10);
  msglen[2] = (uchar)((uint)iVar1 >> 8);
  msglen[4] = (uchar)((uint)iVar2 >> 0x18);
  msglen[5] = (uchar)((uint)iVar2 >> 0x10);
  msglen[6] = (uchar)((uint)iVar2 >> 8);
  msglen[7] = (uchar)iVar2;
  uVar3 = ctx->total[0] & 0x3f;
  if (uVar3 < 0x38) {
    iVar1 = 0x38 - uVar3;
  }
  else {
    iVar1 = 0x78 - uVar3;
  }
  sha2_update(ctx,sha2_padding,iVar1);
  sha2_update(ctx,msglen,8);
  *output = (uchar)(ctx->state[0] >> 0x18);
  output[1] = (uchar)(ctx->state[0] >> 0x10);
  output[2] = (uchar)(ctx->state[0] >> 8);
  output[3] = (uchar)ctx->state[0];
  output[4] = (uchar)(ctx->state[1] >> 0x18);
  output[5] = (uchar)(ctx->state[1] >> 0x10);
  output[6] = (uchar)(ctx->state[1] >> 8);
  output[7] = (uchar)ctx->state[1];
  output[8] = (uchar)(ctx->state[2] >> 0x18);
  output[9] = (uchar)(ctx->state[2] >> 0x10);
  output[10] = (uchar)(ctx->state[2] >> 8);
  output[0xb] = (uchar)ctx->state[2];
  output[0xc] = (uchar)(ctx->state[3] >> 0x18);
  output[0xd] = (uchar)(ctx->state[3] >> 0x10);
  output[0xe] = (uchar)(ctx->state[3] >> 8);
  output[0xf] = (uchar)ctx->state[3];
  output[0x10] = (uchar)(ctx->state[4] >> 0x18);
  output[0x11] = (uchar)(ctx->state[4] >> 0x10);
  output[0x12] = (uchar)(ctx->state[4] >> 8);
  output[0x13] = (uchar)ctx->state[4];
  output[0x14] = (uchar)(ctx->state[5] >> 0x18);
  output[0x15] = (uchar)(ctx->state[5] >> 0x10);
  output[0x16] = (uchar)(ctx->state[5] >> 8);
  output[0x17] = (uchar)ctx->state[5];
  output[0x18] = (uchar)(ctx->state[6] >> 0x18);
  output[0x19] = (uchar)(ctx->state[6] >> 0x10);
  output[0x1a] = (uchar)(ctx->state[6] >> 8);
  output[0x1b] = (uchar)ctx->state[6];
  output[0x1c] = (uchar)(ctx->state[7] >> 0x18);
  output[0x1d] = (uchar)(ctx->state[7] >> 0x10);
  output[0x1e] = (uchar)(ctx->state[7] >> 8);
  output[0x1f] = (uchar)ctx->state[7];
  return;
}




void sha2(uchar *input,int ilen,uchar *output)

{
  uchar *output_local;
  int ilen_local;
  uchar *input_local;
  sha2_context ctx;
  
  sha2_starts(&ctx);
  sha2_update(&ctx,input,ilen);
  sha2_finish(&ctx,output);
  memset(&ctx,0,0xe8);
  return;
}




uint32_t swab32(uint32_t v)

{
  uint32_t v_local;
  
  return v << 0x18 | (v >> 8 & 0xff) << 0x10 | (v >> 0x10 & 0xff) << 8 | v >> 0x18;
}




void flip_swab(void *dest_p,void *src_p,uint length)

{
  uint32_t uVar1;
  uint length_local;
  void *src_p_local;
  void *dest_p_local;
  uint32_t *src;
  uint32_t *dest;
  uint i;
  
  for (i = 0; i < length >> 2; i = i + 1) {
    uVar1 = swab32(*(uint32_t *)(i * 4 + (int)src_p));
    *(uint32_t *)((int)dest_p + i * 4) = uVar1;
  }
  return;
}




void flip32(void *dest_p,void *src_p)

{
  uint32_t uVar1;
  void *src_p_local;
  void *dest_p_local;
  uint32_t *src;
  uint32_t *dest;
  int i;
  
  for (i = 0; i < 8; i = i + 1) {
    uVar1 = swab32(*(uint32_t *)(i * 4 + (int)src_p));
    *(uint32_t *)((int)dest_p + i * 4) = uVar1;
  }
  return;
}




void push_nonce(nonce_rb_format *nonce_item)

{
  nonce_rb_format *nonce_item_local;
  char tmp42 [1024];
  
  pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
  memcpy(nonce_fifo.nonce_buffer + nonce_fifo.p_wr,nonce_item,0x54d);
  if (nonce_fifo.p_wr < 0x1fe) {
    nonce_fifo.p_wr = nonce_fifo.p_wr + 1;
  }
  else {
    nonce_fifo.p_wr = 0;
  }
  if (nonce_fifo.nonce_num < 0x1ff) {
    nonce_fifo.nonce_num = nonce_fifo.nonce_num + 1;
  }
  else {
    nonce_fifo.nonce_num = 0x1ff;
    if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s: nonce fifo full!!!\n","push_nonce");
      _applog(1,tmp42,false);
    }
  }
  pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void clear_nonce_fifo(void)

{
  pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
  nonce_fifo.p_wr = 0;
  nonce_fifo.p_rd = 0;
  nonce_fifo.nonce_num = 0;
  pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
  return;
}




void pop_nonce(nonce_rb_format *nonce_tmp)

{
  nonce_rb_format *nonce_tmp_local;
  
  pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
  nonce_fifo.nonce_num = nonce_fifo.nonce_num - 1;
  memcpy(nonce_tmp,nonce_fifo.nonce_buffer + nonce_fifo.p_rd,0x54d);
  if (nonce_fifo.p_rd < 0x1fe) {
    nonce_fifo.p_rd = nonce_fifo.p_rd + 1;
  }
  else {
    nonce_fifo.p_rd = 0;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
  return;
}




void nonce_fifo_num(int *num)

{
  int *num_local;
  
  pthread_mutex_lock((pthread_mutex_t *)&nonce_mutex);
  *num = nonce_fifo.nonce_num;
  pthread_mutex_unlock((pthread_mutex_t *)&nonce_mutex);
  return;
}




int add_reg_item(reg_list_item_t item)

{
  undefined4 uVar1;
  reg_list_item_t *prVar2;
  reg_list_item_t item_local;
  int i;
  
  uVar1 = item._0_4_;
  pthread_mutex_lock((pthread_mutex_t *)&rs.reg_list_mutex);
  i = 0;
  while( true ) {
    if (99 < i) {
      pthread_mutex_unlock((pthread_mutex_t *)&rs.reg_list_mutex);
      return -1;
    }
    if (rs.reg_list_items[i].age < 0) break;
    i = i + 1;
  }
  prVar2 = rs.reg_list_items + i;
  prVar2->chainid = (char)uVar1;
  prVar2->chip_addr = (char)((uint)uVar1 >> 8);
  prVar2->reg_addr = (char)((uint)uVar1 >> 0x10);
  prVar2->field_0x3 = (char)((uint)uVar1 >> 0x18);
  prVar2->reg_data = item.reg_data;
  prVar2->age = item.age;
  pthread_mutex_unlock((pthread_mutex_t *)&rs.reg_list_mutex);
  return 1;
}




int read_reg_item(reg_list_item_t *item,int ms)

{
  bool bVar1;
  int iVar2;
  int extraout_r1;
  int ms_local;
  reg_list_item_t *item_local;
  int check_interval_ms;
  int i;
  int check_times;
  
  iVar2 = __aeabi_idiv(ms,0x32);
  __aeabi_idivmod(ms,0x32);
  check_times = extraout_r1 + iVar2;
  do {
    usleep(50000);
    pthread_mutex_lock((pthread_mutex_t *)&rs.reg_list_mutex);
    for (i = 0; i < 100; i = i + 1) {
      if ((((rs.reg_list_items[i].chainid == item->chainid) && (rs.reg_list_items[i].chip_addr == item->chip_addr)) &&
          (rs.reg_list_items[i].reg_addr == item->reg_addr)) && (-1 < rs.reg_list_items[i].age)) {
        item->reg_data = rs.reg_list_items[i].reg_data;
        rs.reg_list_items[i].age = -1;
        pthread_mutex_unlock((pthread_mutex_t *)&rs.reg_list_mutex);
        return 1;
      }
    }
    pthread_mutex_unlock((pthread_mutex_t *)&rs.reg_list_mutex);
    bVar1 = check_times < 1;
    check_times = check_times + -1;
    if (bVar1) {
      return -1;
    }
  } while( true );
}




/* WARNING: Unknown calling convention */

void * reg_list_aging(void)

{
  pthread_t __th;
  int i;
  
  __th = pthread_self();
  pthread_detach(__th);
  while (rs.alive == 1) {
    sleep(1);
    pthread_mutex_lock((pthread_mutex_t *)&rs.reg_list_mutex);
    for (i = 0; i < 100; i = i + 1) {
      if (-1 < rs.reg_list_items[i].age) {
        rs.reg_list_items[i].age = rs.reg_list_items[i].age + -1;
      }
    }
    pthread_mutex_unlock((pthread_mutex_t *)&rs.reg_list_mutex);
  }
  return (void *)0x0;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void reg_list_init(void)

{
  int id;
  
  rs.alive = 1;
  pthread_mutex_init((pthread_mutex_t *)&rs.reg_list_mutex,(pthread_mutexattr_t *)0x0);
  rs.reg_list_items = (reg_list_item_t *)calloc(0xc,100);
  for (id = 0; id < 100; id = id + 1) {
    rs.reg_list_items[id].age = -1;
  }
  pthread_create(&rs.p_reg_list,(pthread_attr_t *)0x0,(__start_routine *)0x32869,(void *)0x0);
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void reg_list_exit(void)

{
  rs.alive = 0;
  usleep(1500000);
  pthread_cancel(rs.p_reg_list);
  pthread_join(rs.p_reg_list,(void **)0x0);
  free(rs.reg_list_items);
  pthread_mutex_destroy((pthread_mutex_t *)&rs.reg_list_mutex);
  return;
}




void * nonce_scanhash(void *args)

{
  _Bool _Var1;
  int iVar2;
  void *args_local;
  uint8_t work [140];
  char tmp42 [1024];
  nonce_rb_format nonce_tmp;
  int ticket_mask;
  int nonceNum;
  int valid;
  int chainid;
  runtime_base_t *runtime;
  int asic;
  int asic_index;
  
  nonceNum = 0;
  runtime = (runtime_base_t *)args;
  nonce_fifo_num(&nonceNum);
  while (nonceNum != 0) {
    nonceNum = nonceNum + -1;
    pop_nonce(&nonce_tmp);
    chainid = (int)nonce_tmp.chain_id;
    memset(work,0,0x8c);
    work_list_find(nonce_tmp.work_id,work);
    memcpy(&runtime->nonce_verify_info,work,(runtime->nonce_verify_info).work_len);
    memcpy((runtime->nonce_verify_info).nonce,nonce_tmp.chip_nonce,(runtime->nonce_verify_info).nonce_len);
    memcpy((runtime->nonce_verify_info).sol,&nonce_tmp,(runtime->nonce_verify_info).sol_len);
    memset((runtime->nonce_verify_info).target,0,(runtime->nonce_verify_info).target_len);
    ticket_mask = 0;
    valid = (*runtime->nonce_verify)(&runtime->nonce_verify_info,&ticket_mask,runtime->nonce_shift);
    if (runtime->new_block != false) {
      runtime->new_block = false;
      memset(runtime->chain_status[chainid].one_work_nonce_each_asic,0,
             runtime->chain_status[chainid].design_asic_num << 2);
      memset(runtime->chain_status[chainid].one_work_invalid_nonce_each_asic,0,
             runtime->chain_status[chainid].design_asic_num << 2);
      memset(runtime->chain_status[chainid].one_work_invalid_nonce_each_asic_type,0,
             runtime->chain_status[chainid].design_asic_num * 0xc);
    }
    if (valid == 0) {
      runtime->valid_nonce_total = runtime->valid_nonce_total + 1;
      for (asic_index = 0; asic_index < 3; asic_index = asic_index + 1) {
        iVar2 = __aeabi_idiv(nonce_tmp.chip_addr,runtime->addr_interval);
        if (iVar2 == asic_index) {
          runtime->chain_status[chainid].one_work_nonce_each_asic[asic_index] =
               runtime->chain_status[chainid].one_work_nonce_each_asic[asic_index] + 1;
          runtime->chain_status[chainid].nonce_num_each_asic[asic_index] =
               runtime->chain_status[chainid].nonce_num_each_asic[asic_index] + 1;
          if (g_patten.start != 0) {
            is_patten_match(asic_index,nonce_tmp.chip_nonce,nonce_tmp.Nonce);
          }
          if (((use_syslog != false) || (opt_log_output != false)) || (0 < opt_log_level)) {
            snprintf(tmp42,0x400,"Success:valid nonce: chainid=%d chipaddr=%02x nonces=%d total=%d tm=%d err=%d\n",
                     chainid,(uint)nonce_tmp.chip_addr,
                     runtime->chain_status[chainid].one_work_nonce_each_asic[asic_index],runtime->submit_nonce,
                     ticket_mask,valid);
            _applog(1,tmp42,false);
          }
          if ((opt_debug != false) && (((use_syslog != false || (opt_log_output != false)) || (3 < opt_log_level)))) {
            snprintf(tmp42,0x400,"SHA256:%02x%02x%02x%02x\n",(uint)nonce_tmp.sha256[0],(uint)nonce_tmp.sha256[1],
                     (uint)nonce_tmp.sha256[2],(uint)nonce_tmp.sha256[3]);
            _applog(4,tmp42,false);
          }
        }
      }
      if ((app_conf->work_mode == 1) &&
         (_Var1 = (*runtime->nonce_verify_target_match)((runtime->nonce_verify_info).target,g_work_info.target), _Var1))
      {
        (*runtime->nonce_submit)
                  (nonce_tmp.Nonce,(runtime->nonce_verify_info).work,g_work_info.fixed_nonce_bytes,(char *)0x4b608);
      }
    }
    else {
      runtime->invalid_nonce_total = runtime->invalid_nonce_total + 1;
      for (asic = 0; asic < 3; asic = asic + 1) {
        iVar2 = __aeabi_idiv(nonce_tmp.chip_addr,runtime->addr_interval);
        if (iVar2 == asic) {
          runtime->chain_status[chainid].nonce_invalid_num_each_asic[asic] =
               runtime->chain_status[chainid].nonce_invalid_num_each_asic[asic] + 1;
          *(int *)((runtime->nonce_verify_info).work + (chainid * 0x24 + asic) * 4 + -0x4c) =
               *(int *)((runtime->nonce_verify_info).work + (chainid * 0x24 + asic) * 4 + -0x4c) + 1;
          if (valid == 1) {
            runtime->chain_status[chainid].one_work_invalid_nonce_each_asic_type[asic][1] =
                 runtime->chain_status[chainid].one_work_invalid_nonce_each_asic_type[asic][1] + 1;
          }
          else if (valid == 2) {
            runtime->chain_status[chainid].one_work_invalid_nonce_each_asic_type[asic][2] =
                 runtime->chain_status[chainid].one_work_invalid_nonce_each_asic_type[asic][2] + 1;
          }
          if (((use_syslog != false) || (opt_log_output != false)) || (-1 < opt_log_level)) {
            snprintf(tmp42,0x400,"Fail:invalid nonce: chainid=%d chipaddr=%02x nonces=%d tm=%d errtype=%d\n",chainid,
                     (uint)nonce_tmp.chip_addr,
                     *(undefined4 *)((runtime->nonce_verify_info).work + (chainid * 0x24 + asic) * 4 + -0x4c),
                     ticket_mask,valid);
            _applog(0,tmp42,false);
          }
        }
      }
    }
  }
  return (void *)0x0;
}




void * nonce_scanhash_loop(void *args)

{
  void *args_local;
  pthread_t send_id;
  runtime_base_t *runtime;
  
  runtime = (runtime_base_t *)args;
  do {
    while (runtime->start_recv == 0) {
      pthread_testcancel();
      usleep(100000);
    }
    pthread_create(&send_id,(pthread_attr_t *)0x0,(__start_routine *)0x329d1,args);
    pthread_join(send_id,(void **)0x0);
    usleep(1000);
  } while( true );
}




void add_point(int *point,int MAX_SIZE)

{
  int MAX_SIZE_local;
  int *point_local;
  
  *point = *point + 1;
  if (MAX_SIZE <= *point) {
    *point = 0;
  }
  return;
}




void * handle_asic_response(void *args)

{
  int iVar1;
  void *args_local;
  char tmp42 [1024];
  uint8_t header [3];
  int p_header;
  int data_buf_wp;
  int data_buf_rp;
  int max;
  uint8_t *tmp;
  uint8_t *data_buf;
  int data_buf_len;
  uint8_t *receive_buf;
  int resp_nonce_len;
  int chainid;
  runtime_base_t *runtime;
  int i;
  int len;
  
  chainid = *(int *)((int)args + 0x6ec);
  len = 0;
  resp_nonce_len = *(int *)((int)args + 0x94) * *(int *)((int)args + 0x90);
  runtime = (runtime_base_t *)args;
  receive_buf = (uint8_t *)calloc(1,resp_nonce_len);
  data_buf_len = resp_nonce_len * 0x32;
  data_buf = (uint8_t *)calloc(data_buf_len,1);
  data_buf_rp = 0;
  data_buf_wp = 0;
  tmp = (uint8_t *)calloc(1,(runtime->asic_data_info).resp_frame_max_len);
  if (tmp == (uint8_t *)0x0) {
    if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
      snprintf(tmp42,0x400,"%s calloc tmp failed\n","handle_asic_response");
      _applog(2,tmp42,false);
    }
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  max = data_buf_len;
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"Start A New Asic Response.Chain Id:[%d]\n",chainid);
    _applog(2,tmp42,false);
  }
  do {
    do {
      while (runtime->start_recv == 0) {
        pthread_testcancel();
        usleep(100000);
      }
      usleep(500);
      memset(receive_buf,0,resp_nonce_len);
      len = uart_receive((uchar)runtime->chain_status[chainid].fd,receive_buf,resp_nonce_len);
      for (i = 0; i < len; i = i + 1) {
        data_buf[data_buf_wp] = receive_buf[i];
        add_point(&data_buf_wp,max);
      }
    } while (data_buf_rp == data_buf_wp);
    if (data_buf_rp < data_buf_wp) {
      iVar1 = -data_buf_rp;
    }
    else {
      iVar1 = data_buf_len - data_buf_rp;
    }
    len = data_buf_wp + iVar1;
    while (2 < len) {
      p_header = data_buf_rp;
      header[0] = '\0';
      header[1] = '\0';
      header[2] = '\0';
      for (i = 0; i < 3; i = i + 1) {
        header[i] = data_buf[p_header];
        add_point(&p_header,max);
      }
      if ((header[0] == 0xaa) && (header[1] == 'U')) {
        if ((header[2] & 0xf0) == 0xe0) {
          if (len < (runtime->asic_data_info).resp_nonce_frame_len) break;
          for (i = 0; i < (runtime->asic_data_info).resp_nonce_frame_len; i = i + 1) {
            tmp[i] = data_buf[data_buf_rp];
            add_point(&data_buf_rp,max);
          }
          len = len - (runtime->asic_data_info).resp_nonce_frame_len;
          (*runtime->nonce_handle)(tmp,(runtime->asic_data_info).resp_nonce_frame_len,chainid,runtime->addr_interval);
        }
        else if (header[2] == 0xcc) {
          if (len < (runtime->asic_data_info).resp_pm_len) break;
          for (i = 0; i < (runtime->asic_data_info).resp_pm_len; i = i + 1) {
            tmp[i] = data_buf[data_buf_rp];
            add_point(&data_buf_rp,max);
          }
          len = len - (runtime->asic_data_info).resp_pm_len;
          (*runtime->pm_handle)(tmp,(runtime->asic_data_info).resp_pm_len,(uint8_t)chainid);
        }
        else if (header[2] == 0xd0) {
          if (len < (runtime->asic_data_info).resp_pt_len) break;
          for (i = 0; i < (runtime->asic_data_info).resp_pt_len; i = i + 1) {
            tmp[i] = data_buf[data_buf_rp];
            add_point(&data_buf_rp,max);
          }
          len = len - (runtime->asic_data_info).resp_pt_len;
          (*runtime->pt_handle)(tmp,(runtime->asic_data_info).resp_pt_len,(uint8_t)chainid);
        }
        else {
          if (len < (runtime->asic_data_info).resp_reg_len) break;
          for (i = 0; i < (runtime->asic_data_info).resp_reg_len; i = i + 1) {
            tmp[i] = data_buf[data_buf_rp];
            add_point(&data_buf_rp,max);
          }
          len = len - (runtime->asic_data_info).resp_reg_len;
          (*runtime->reg_handle)(tmp,(runtime->asic_data_info).resp_reg_len,(uint8_t)chainid);
        }
      }
      else {
        add_point(&data_buf_rp,max);
        len = len + -1;
      }
    }
  } while( true );
}




void runtime_init(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int chainid;
  
  work_list_init((runtime->nonce_verify_info).work_len);
  reg_list_init();
  iVar1 = runtime->chain_id;
  sleep(1);
  pthread_create(&runtime->chain_status[iVar1].p_dispatch,(pthread_attr_t *)0x0,(__start_routine *)0x330a5,runtime);
  pthread_create(&runtime->p_scanhash,(pthread_attr_t *)0x0,(__start_routine *)0x33025,runtime);
  runtime->start_recv = 1;
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s Done!\n","runtime_init");
    _applog(2,tmp42,false);
  }
  return;
}




void runtime_exit(runtime_base_t *runtime)

{
  int iVar1;
  runtime_base_t *runtime_local;
  char tmp42 [1024];
  int chainid;
  
  runtime->start_recv = 0;
  iVar1 = runtime->chain_id;
  usleep(300000);
  pthread_cancel(runtime->p_scanhash);
  pthread_join(runtime->p_scanhash,(void **)0x0);
  pthread_cancel(runtime->chain_status[iVar1].p_dispatch);
  pthread_join(runtime->chain_status[iVar1].p_dispatch,(void **)0x0);
  reg_list_exit();
  work_list_exit();
  if (((use_syslog != false) || (opt_log_output != false)) || (1 < opt_log_level)) {
    snprintf(tmp42,0x400,"%s Done!\n","runtime_exit");
    _applog(2,tmp42,false);
  }
  return;
}




void work_list_init(int work_len)

{
  uint8_t *puVar1;
  int work_len_local;
  int i;
  
  memset(&work_list_info,0,0x70);
  work_list_info.work_len = work_len;
  pthread_mutex_init((pthread_mutex_t *)&work_list_info.work_list_mutex,(pthread_mutexattr_t *)0x0);
  for (i = 0; i < 10; i = i + 1) {
    puVar1 = (uint8_t *)calloc(work_len,1);
    work_list_info.work_list[i].work = puVar1;
  }
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void work_list_exit(void)

{
  int i;
  
  for (i = 0; i < 10; i = i + 1) {
    free(work_list_info.work_list[i].work);
  }
  pthread_mutex_destroy((pthread_mutex_t *)&work_list_info.work_list_mutex);
  return;
}




void work_list_insert(uint8_t workid,uint8_t *work)

{
  uint8_t *work_local;
  uint8_t workid_local;
  
  pthread_mutex_lock((pthread_mutex_t *)&work_list_info.work_list_mutex);
  work_list_info.work_list[work_list_info.work_list_insert_index].workid = workid;
  memcpy(work_list_info.work_list[work_list_info.work_list_insert_index].work,work,work_list_info.work_len);
  work_list_info.work_list_insert_index = work_list_info.work_list_insert_index + 1;
  if (9 < work_list_info.work_list_insert_index) {
    work_list_info.work_list_insert_index = 0;
  }
  pthread_mutex_unlock((pthread_mutex_t *)&work_list_info.work_list_mutex);
  return;
}




void work_list_find(uint8_t workid,uint8_t *work)

{
  uint8_t *work_local;
  uint8_t workid_local;
  int i;
  
  pthread_mutex_lock((pthread_mutex_t *)&work_list_info.work_list_mutex);
  i = 0;
  do {
    if (9 < i) {
LAB_0003392c:
      pthread_mutex_unlock((pthread_mutex_t *)&work_list_info.work_list_mutex);
      return;
    }
    if (workid == work_list_info.work_list[i].workid) {
      memcpy(work,work_list_info.work_list[i].work,work_list_info.work_len);
      goto LAB_0003392c;
    }
    i = i + 1;
  } while( true );
}




uint __udivsi3(uint param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 - 1 == 0) {
    return param_1;
  }
  if (param_2 == 0) {
    if (param_1 != 0) {
      param_1 = 0xffffffff;
    }
    uVar1 = __aeabi_idiv0(param_1);
    return uVar1;
  }
  if (param_1 <= param_2) {
    return (uint)(param_1 == param_2);
  }
  if ((param_2 & param_2 - 1) == 0) {
    return param_1 >> (0x1fU - LZCOUNT(param_2) & 0xff);
  }
                    /* WARNING: Could not recover jumptable at 0x00033970. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(&UNK_00033978 + (0x1f - (LZCOUNT(param_2) - LZCOUNT(param_1))) * 0x10))(param_1,param_2,0);
  return uVar1;
}




/* WARNING: Control flow encountered bad instruction data */

void FUN_00033941(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




void __aeabi_uidivmod(int param_1,int param_2)

{
  if (param_2 != 0) {
    __udivsi3();
    return;
  }
  if (param_1 != 0) {
    param_1 = -1;
  }
  __aeabi_idiv0(param_1);
  return;
}




uint __aeabi_idiv(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  if (param_2 == 0) {
    bVar4 = (int)param_1 < 0;
    if (0 < (int)param_1) {
      param_1 = 0x7fffffff;
    }
    if (bVar4) {
      param_1 = 0x80000000;
    }
    uVar1 = __aeabi_idiv0(param_1);
    return uVar1;
  }
  uVar3 = param_1 ^ param_2;
  uVar1 = param_2;
  if ((int)param_2 < 0) {
    uVar1 = -param_2;
  }
  if (uVar1 - 1 == 0) {
    if ((int)param_2 < 0) {
      param_1 = -param_1;
    }
    return param_1;
  }
  uVar2 = param_1;
  if ((int)param_1 < 0) {
    uVar2 = -param_1;
  }
  if (uVar2 <= uVar1) {
    if (uVar2 < uVar1) {
      param_1 = 0;
    }
    if (uVar2 == uVar1) {
      param_1 = (int)uVar3 >> 0x1f | 1;
    }
    return param_1;
  }
  if ((uVar1 & uVar1 - 1) == 0) {
    uVar2 = uVar2 >> (0x1fU - LZCOUNT(uVar1) & 0xff);
    if ((int)uVar3 < 0) {
      uVar2 = -uVar2;
    }
    return uVar2;
  }
                    /* WARNING: Could not recover jumptable at 0x00033bf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(&UNK_00033c00 + (0x1f - (LZCOUNT(uVar1) - LZCOUNT(uVar2))) * 0x10))(0);
  return uVar1;
}




/* WARNING: Control flow encountered bad instruction data */

void FUN_00033bb9(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}




uint _divsi3_skip_div0_test(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char in_NG;
  
  uVar3 = param_1 ^ param_2;
  uVar1 = param_2;
  if (in_NG != '\0') {
    uVar1 = -param_2;
  }
  if (uVar1 - 1 == 0) {
    if ((int)param_2 < 0) {
      param_1 = -param_1;
    }
    return param_1;
  }
  uVar2 = param_1;
  if ((int)param_1 < 0) {
    uVar2 = -param_1;
  }
  if (uVar2 <= uVar1) {
    if (uVar2 < uVar1) {
      param_1 = 0;
    }
    if (uVar2 == uVar1) {
      param_1 = (int)uVar3 >> 0x1f | 1;
    }
    return param_1;
  }
  if ((uVar1 & uVar1 - 1) == 0) {
    uVar2 = uVar2 >> (0x1fU - LZCOUNT(uVar1) & 0xff);
    if ((int)uVar3 < 0) {
      uVar2 = -uVar2;
    }
    return uVar2;
  }
                    /* WARNING: Could not recover jumptable at 0x00033bf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)(&UNK_00033c00 + (0x1f - (LZCOUNT(uVar1) - LZCOUNT(uVar2))) * 0x10))(0);
  return uVar1;
}




void __aeabi_idivmod(int param_1,int param_2)

{
  bool bVar1;
  
  if (param_2 != 0) {
    _divsi3_skip_div0_test();
    return;
  }
  bVar1 = param_1 < 0;
  if (0 < param_1) {
    param_1 = 0x7fffffff;
  }
  if (bVar1) {
    param_1 = -0x80000000;
  }
  __aeabi_idiv0(param_1);
  return;
}




void __aeabi_idiv0(void)

{
  raise(8);
  return;
}




/* WARNING: Unknown calling convention */

void __libc_csu_init(int argc,char **argv,char **envp)

{
  undefined **ppuVar1;
  int iVar2;
  
  _init((EVP_PKEY_CTX *)argc);
  iVar2 = 0;
  do {
    ppuVar1 = &__frame_dummy_init_array_entry + iVar2;
    iVar2 = iVar2 + 1;
    (*(code *)*ppuVar1)(argc,argv,envp);
  } while (iVar2 != 1);
  return;
}




/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void __libc_csu_fini(void)

{
  return;
}




void _fini(void)

{
  return;
}



