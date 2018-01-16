#include "memory.h"

int __stdcall memapi::write(unsigned long ul_address, std::string write_buffer)
{

  DWORD dw_old_protection_flags, dw_size;
  void *pv_address = (void *)ul_address;

  size_t size = std::count(write_buffer.begin(), write_buffer.end(), ' ') + 1;
  utils::replace_string(write_buffer, " ", "");
  std::vector<unsigned char> bytes = utils::hex_to_bytes(write_buffer);
  PBYTE pb_write_buffer = bytes.data();

  ul_address = ROUND_DOWN(pv_address, 0x1000);
  dw_size = ROUND_UP(size, 0x1000);

  if (VirtualProtect((LPVOID)ul_address, dw_size, PAGE_EXECUTE_READWRITE, &dw_old_protection_flags))
  {
    memcpy(pv_address, pb_write_buffer, size);
    if (VirtualProtect((LPVOID)ul_address, dw_size, dw_old_protection_flags, &dw_old_protection_flags))
    {
      if (FlushInstructionCache(GetCurrentProcess(), (LPCVOID)ul_address, dw_size))
        return 0;
      return GetLastError();
    }
  }
  return GetLastError();

}

void memapi::write_int(unsigned long ul_address, int value) {

  DWORD dw_old_protection_flags, dw_size;
  void *pv_address = (void *)ul_address;
  size_t size = sizeof(value);

  ul_address = ROUND_DOWN(pv_address, 0x1000);
  dw_size = ROUND_UP(size, 0x1000);

  if (VirtualProtect((LPVOID)ul_address, dw_size, PAGE_EXECUTE_READWRITE, &dw_old_protection_flags))
  {
    memcpy(pv_address, static_cast<char*>(static_cast<void*>(&value)), size);
    if (VirtualProtect((LPVOID)ul_address, dw_size, dw_old_protection_flags, &dw_old_protection_flags))
      FlushInstructionCache(GetCurrentProcess(), (LPCVOID)ul_address, dw_size);
  }

}

void memapi::write_float(unsigned long ul_address, float value) {

  DWORD dw_old_protection_flags, dw_size;
  void *pv_address = (void *)ul_address;
  size_t size = sizeof(value);

  ul_address = ROUND_DOWN(pv_address, 0x1000);
  dw_size = ROUND_UP(size, 0x1000);

  if (VirtualProtect((LPVOID)ul_address, dw_size, PAGE_EXECUTE_READWRITE, &dw_old_protection_flags))
  {
    memcpy(pv_address, static_cast<char*>(static_cast<void*>(&value)), size);
    if (VirtualProtect((LPVOID)ul_address, dw_size, dw_old_protection_flags, &dw_old_protection_flags))
      FlushInstructionCache(GetCurrentProcess(), (LPCVOID)ul_address, dw_size);
  }

}

unsigned long memapi::pointer::ptr_address(unsigned long base, unsigned long offsets[]) {

  int ptr_level = sizeof(offsets);
  unsigned long ptr = *(unsigned long*)(base);
  if (ptr == 0)
    return 0;

  for (int i = 0; i < ptr_level; i++)
  {
    if (i == ptr_level - 1)
    {
      ptr = (DWORD)(ptr + offsets[i]);
      if (ptr == 0)
        return 0;
      return ptr;
    }
    else
    {
      ptr = *(DWORD*)(ptr + offsets[i]);
      if (ptr == 0)
        return 0;
    }
  }
  return ptr;

}

bool memapi::pointer::valid(unsigned long base, unsigned long offset)
{

  ULONG_PTR *ul_base = (ULONG_PTR *)base;
  if (!IsBadReadPtr((VOID *)ul_base, sizeof(ULONG_PTR)))
    if (!IsBadReadPtr((VOID *)((*(ULONG_PTR *)ul_base) + offset), sizeof(ULONG_PTR)))
      return true;
  return false;

}

int memapi::pointer::read_int(unsigned long base, unsigned long offset)
{

  if (valid(base, offset))
    return *(int *)(*(unsigned long *)base + offset);
  else
    return 0;

}

void memapi::pointer::write_int(unsigned long base, unsigned long offset, int value)
{

  if (valid(base, offset))
    *(int *)(*(unsigned long *)base + offset) = value;

}

std::string memapi::pointer::read_str(unsigned long base, unsigned long offset)
{

  if (valid(base, offset))
    return *(std::string *)(*(unsigned long *)base + offset);
  else
    return "";

}

void memapi::pointer::write_str(unsigned long base, unsigned long offset, std::string value)
{

  if (valid(base, offset))
    *(std::string *)(*(unsigned long *)base + offset) = value;

}

float memapi::pointer::read_float(unsigned long base, unsigned long offset)
{

  if (valid(base, offset))
    return *(float *)(*(unsigned long *)base + offset);
  else
    return 0;

}

void memapi::pointer::write_float(unsigned long base, unsigned long offset, float value)
{

  if (valid(base, offset))
    *(float *)(*(unsigned long *)base + offset) = value;

}
