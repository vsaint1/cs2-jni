#pragma once
#include <Windows.h>

HWND entry_hwnd = NULL;

RECT rect;

int pid = 0;
ULONG64 client = 0;
uintptr_t global_pawn = 0;

namespace offsets {
std::ptrdiff_t dwEntityList = 0x17BB820;
std::ptrdiff_t dwLocalPlayerPawn = 0x16C2D98;
std::ptrdiff_t dwViewMatrix = 0x1819FC0;
std::ptrdiff_t dwPawnHealth = 0x7F8;    // m_iPawnHealth = 0x7F8; // uint32_t
std::ptrdiff_t dwPlayerPawn = 0x7EC;    // m_hPlayerPawn client.dll.rs
std::ptrdiff_t dwSanitizedName = 0x640; //  m_iszPlayerName = 0x640; // char[128]
std::ptrdiff_t m_bDormant = 0xE7;
std::ptrdiff_t m_iTeamNum = 0x3bf;
std::ptrdiff_t m_vecOrigin = 0x1224;          // m_vOldOrigin client.dll.rs
std::ptrdiff_t m_iHealth = 0x32C;             // m_iHealth client.dll.rs
std::ptrdiff_t bSpottedByMask = 0x1630 + 0xC; // entitySpottedState + bSpottedByMask
std::ptrdiff_t m_iszPlayerName = 0x640;       // char[128]
std::ptrdiff_t iIDEntIndex = 0x153C;          // m_iIDEntIndex = 0x153C;
} // namespace offsets
