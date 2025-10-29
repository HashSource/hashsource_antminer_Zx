api_data *__fastcall api_add_int16(api_data *root, char *name, int16_t *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_INT16, data, copy_data);
}
