#pragma once


void change_key(void *blank) {
  keystatus = 1;
  while (true) {
    for (int i = 0; i < 0x87; i++) {
      if (GetKeyState(i) & 0x8000) {
        hotkeys::aimkey = i;
        keystatus = 0;
        return;
      }
    }
  }
}

static bool key_array(void *data, int idx, const char **out_text) {
  const char *const *items = (const char *const *)data;
  if (out_text)
    *out_text = items[idx];
  return true;
}

void hotkey_button(int aimkey, void *changekey, int status) {
  const char *preview_value = NULL;
  if (aimkey >= 0 && aimkey < IM_ARRAYSIZE(key_names))
    key_array(key_names, aimkey, &preview_value);

  std::string aimkeys;

  if (preview_value == NULL)
    aimkeys = "Select any Key";
  else
    aimkeys = preview_value;

  if (status == 1)
    aimkeys = "Press the Key";

  if (ImGui::Button(aimkeys.c_str(), ImVec2(125, 20))) {
    if (status == 0)
      CreateThread(0, 0, (LPTHREAD_START_ROUTINE)changekey, nullptr, 0, nullptr);
  }
}
