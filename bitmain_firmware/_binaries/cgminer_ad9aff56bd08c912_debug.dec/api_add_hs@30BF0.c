api_data *__fastcall api_add_hs(api_data *root, char *name, double *data, bool copy_data)
{
  return api_add_data_full(root, name, api_data_type::API_HS, data, copy_data);
}
