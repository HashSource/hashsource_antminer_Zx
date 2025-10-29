void __fastcall minecoin(io_data *io_data, int c, char *param, bool isjson, char group)
{
  _BOOL4 v5; // r4
  char *v7; // r1
  _BOOL4 v8; // r0
  void *v9; // r3
  _BOOL4 v10; // r8
  char *v11; // r1
  api_data *v12; // r7
  const char *v13; // r2
  int v14; // r3
  const char *v15; // r2
  int v16; // r3
  char *v17; // r1
  api_data *v18; // r0
  char *v19; // r1
  api_data *v20; // r9
  const char *v21; // r2
  int v22; // r3
  char *v23; // r1
  api_data *v24; // r0
  char *v25; // r1
  api_data *v26; // r0

  v5 = isjson;
  message(io_data, 78, 0, 0, isjson);
  LOWORD(v7) = 22356;
  HIWORD(v7) = (unsigned int)"LCD" >> 16;
  if ( !v5 )
    v7 = "COIN,";
  v8 = io_add(io_data, v7);
  LOWORD(v9) = 22376;
  v10 = v8;
  LOWORD(v11) = 22384;
  HIWORD(v9) = (unsigned int)"fan" >> 16;
  HIWORD(v11) = (unsigned int)"" >> 16;
  v12 = api_add_data_full(0, v11, api_data_type::API_CONST, v9, 0);
  if ( pthread_mutex_lock(&ch_lock.mutex) )
    mutex_lock_1((pthread_mutex_t *)(&_func___11933.__align + 3), (const char *)0xE72, v13, v14);
  rd_lock_0(&ch_lock.rwlock, &_func___11933.__size[12], (const char *)0xE72, v14);
  if ( pthread_mutex_unlock(&ch_lock.mutex) )
    mutex_unlock_noyield_1((pthread_mutex_t *)(&_func___11933.__align + 3), (const char *)0xE72, v15, v16);
  LOWORD(v17) = 22396;
  HIWORD(v17) = (unsigned int)"user" >> 16;
  v18 = api_add_data_full(v12, v17, api_data_type::API_TIMEVAL, &block_timeval, 1);
  LOWORD(v19) = 22416;
  HIWORD(v19) = (unsigned int)"sed" >> 16;
  v20 = api_add_data_full(v18, v19, api_data_type::API_STRING, current_hash, 1);
  if ( pthread_rwlock_unlock(&ch_lock.rwlock) )
    rw_unlock_0((pthread_rwlock_t *)(&_func___11933.__align + 3), (const char *)0xE75, v21, v22);
  selective_yield();
  LOWORD(v23) = 22436;
  HIWORD(v23) = (unsigned int)"Max" >> 16;
  v24 = api_add_data_full(v20, v23, api_data_type::API_BOOL, &have_longpoll, 0);
  LOWORD(v25) = 22440;
  HIWORD(v25) = (unsigned int)"Min" >> 16;
  v26 = api_add_data_full(v24, v25, api_data_type::API_DIFF, &current_diff, 1);
  print_data(io_data, v26, v5, 0);
  if ( v5 && v10 )
    io_data->close = 1;
}
