void __fastcall addpool(io_data *io_data, int c, char *param, bool isjson, char group)
{
  char *v8; // r8
  pool *v9; // r7
  char *v10; // r4
  char *url; // [sp+Ch] [bp-Ch] BYREF
  char *user; // [sp+10h] [bp-8h] BYREF
  char *pass; // [sp+14h] [bp-4h] BYREF

  if ( param && *param )
  {
    if ( pooldetails(param, &url, &user, &pass) )
    {
      v9 = add_pool();
      detect_stratum(v9, url);
      add_pool_details(v9, 1, url, user, pass);
      v10 = escape_string(url, isjson);
      message(io_data, 55, v9->pool_no, v10, isjson);
      if ( url != v10 )
        free(v10);
    }
    else
    {
      v8 = escape_string(param, isjson);
      message(io_data, 53, 0, v8, isjson);
      if ( param != v8 )
        free(v8);
    }
  }
  else
  {
    message(io_data, 52, 0, 0, isjson);
  }
}
