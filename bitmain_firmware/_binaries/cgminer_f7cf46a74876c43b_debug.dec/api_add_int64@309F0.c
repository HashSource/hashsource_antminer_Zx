api_data *__fastcall api_add_int64(api_data *root, char *name, int64_t *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_INT64, data, copy_data);
}
