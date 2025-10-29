void __fastcall minecoin(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r4
  char *v7; // r1
  _BOOL4 v8; // r8
  api_data *v9; // r7
  const char *v10; // r2
  int v11; // r3
  const char *v12; // r2
  int v13; // r3
  api_data *v14; // r0
  api_data *v15; // r9
  const char *v16; // r2
  int v17; // r3
  api_data *v18; // r0
  api_data *v19; // r0

  v5 = isjson;
  message(io_data, 78, 0, 0, isjson);
  v7 = ",\"COIN\":[";
  if ( !v5 )
    v7 = "COIN,";
  v8 = io_add(io_data, v7);
  v9 = api_add_data_full(0, "Hash Method", api_data_type::API_CONST, "sha256", 0);
  if ( pthread_mutex_lock(&ch_lock.mutex) )
    mutex_lock_1((pthread_mutex_t *)(&_func___11933.__align + 3), (const char *)0xE72, v10, v11);
  rd_lock_0(&ch_lock.rwlock, &_func___11933.__size[12], (const char *)0xE72, v11);
  if ( pthread_mutex_unlock(&ch_lock.mutex) )
    mutex_unlock_noyield_1((pthread_mutex_t *)(&_func___11933.__align + 3), (const char *)0xE72, v12, v13);
  v14 = api_add_data_full(v9, "Current Block Time", api_data_type::API_TIMEVAL, &block_timeval, 1);
  v15 = api_add_data_full(v14, "Current Block Hash", api_data_type::API_STRING, current_hash, 1);
  if ( pthread_rwlock_unlock(&ch_lock.rwlock) )
    rw_unlock_0((pthread_rwlock_t *)(&_func___11933.__align + 3), (const char *)0xE75, v16, v17);
  selective_yield();
  v18 = api_add_data_full(v15, "LP", api_data_type::API_BOOL, &have_longpoll, 0);
  v19 = api_add_data_full(v18, "Network Difficulty", api_data_type::API_DIFF, &current_diff, 1);
  print_data(io_data, v19, v5, 0);
  if ( v5 && v8 )
    io_data->close = 1;
}
