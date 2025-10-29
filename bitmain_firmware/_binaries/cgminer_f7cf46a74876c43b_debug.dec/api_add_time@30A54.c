api_data *__fastcall api_add_time(api_data *root, char *name, time_t *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_TIME, data, copy_data);
}
