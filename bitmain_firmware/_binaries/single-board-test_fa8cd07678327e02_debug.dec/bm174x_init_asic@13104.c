int __cdecl bm174x_init_asic(void *args)
{
  *((_DWORD *)args + 36) = 16;
  *((_DWORD *)args + 37) = 93;
  *((_DWORD *)args + 38) = 9;
  *((_DWORD *)args + 39) = 9;
  *((_DWORD *)args + 40) = 1030;
  *((_DWORD *)args + 41) = 1030;
  *((_DWORD *)args + 42) = 146;
  *((_DWORD *)args + 716) = bm174x_read_register;
  *((_DWORD *)args + 717) = bm174x_write_register;
  *((_DWORD *)args + 718) = bm174x_send_work;
  *((_DWORD *)args + 719) = bm174x_set_ticket_mask;
  *((_DWORD *)args + 720) = bm174x_set_core_timeout;
  *((_DWORD *)args + 721) = bm174x_set_pt_ctrl;
  *((_DWORD *)args + 722) = bm174x_set_pt_result;
  *((_DWORD *)args + 723) = bm174x_set_txn_data;
  *((_DWORD *)args + 724) = bm174x_set_baud;
  *((_DWORD *)args + 725) = bm174x_chain_inactive;
  *((_DWORD *)args + 726) = bm174x_set_address;
  *((_DWORD *)args + 727) = bm174x_set_frequency;
  *((_DWORD *)args + 728) = bm174x_set_nonce_shift;
  *((_DWORD *)args + 729) = bm174x_set_vmount;
  *((_DWORD *)args + 732) = bm174x_i2c_enable;
  *((_DWORD *)args + 733) = bm174x_i2c_status;
  *((_DWORD *)args + 731) = bm174x_i2c_recv;
  *((_DWORD *)args + 730) = bm174x_i2c_send;
  *((_DWORD *)args + 739) = bm174x_reg_handle;
  *((_DWORD *)args + 740) = bm174x_nonce_handle;
  *((_DWORD *)args + 738) = bm174x_pt_handle;
  *((_DWORD *)args + 737) = bm174x_pm_handle;
  return 0;
}
