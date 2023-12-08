#pragma once
#include "utils.h"
#include <Windows.h>
#include <TlHelp32.h>
#include <string>

typedef NTSTATUS(WINAPI *pNtReadVirtualMemory)(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToRead, PULONG NumberOfBytesRead);
typedef NTSTATUS(WINAPI *pNtWriteVirtualMemory)(HANDLE Processhandle, PVOID BaseAddress, PVOID Buffer, ULONG NumberOfBytesToWrite, PULONG NumberOfBytesWritten);

class Memory {

  HANDLE m_Handle = 0;
  DWORD m_Pid = 0;

  pNtReadVirtualMemory m_ReadVM;
  pNtWriteVirtualMemory m_WriteVM;

public:
  ~Memory() {

    if (m_Handle)
      CloseHandle(m_Handle);
  }

  long get_process_by_name(const char *process_name) {

    LOG("process_name: %s", process_name);

    PROCESSENTRY32 pe;
    HANDLE valid_ts = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, m_Pid);
    m_Pid = 0;

    if (valid_ts != INVALID_HANDLE_VALUE) {
      while (Process32Next(valid_ts, &pe)) {
        if (!strcmp(process_name, pe.szExeFile)) {

          m_Pid = pe.th32ProcessID;
          break;
        }
      }
    }

    if (valid_ts)
      CloseHandle(valid_ts);

    LOG("pid: %d", m_Pid);

    return m_Pid;
  }

  uintptr_t get_module_base(const char *module_name) {
    MODULEENTRY32 pe;

    LOG("module_name: %s", module_name);

    HANDLE valid_ts = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, m_Pid);

    uintptr_t module_base = 0;

    if (valid_ts != INVALID_HANDLE_VALUE) {
      while (Module32Next(valid_ts, &pe)) {
        if (!strcmp(module_name, pe.szModule)) {

          module_base = reinterpret_cast<uintptr_t>(pe.modBaseAddr);
          break;
        }
      }
    }

    if (valid_ts)
      CloseHandle(valid_ts);

    LOG("module_base: %llu", module_base);

    if (module_base != 0)
      return module_base;

    return false;
  }

  template <typename T> T readv(uintptr_t address) {
    T buffer{};
    m_ReadVM(m_Handle, (void *)address, &buffer, sizeof(T), 0);
    return buffer;
  }

  bool read_raw(uintptr_t address, void *buffer, size_t size) {
    ULONG bytes_read;
    if (m_ReadVM(m_Handle, (void *)address, &buffer, static_cast<ULONG>(size - 1), &bytes_read))
      return bytes_read == size;

    return false;
  }

};

inline Memory g_Memory;