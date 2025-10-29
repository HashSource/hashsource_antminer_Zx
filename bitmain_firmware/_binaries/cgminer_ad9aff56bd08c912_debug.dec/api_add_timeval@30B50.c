api_data *__fastcall api_add_timeval(api_data *root, char *name, timeval *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_TIMEVAL, data, copy_data);
}
