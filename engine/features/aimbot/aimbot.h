#pragma once
#include "../globals.h"
#include "../math.h"

void aimbot(Entity entity, FVector3 head_bone) {

  float closest_pawn = FLT_MAX;

  auto dx = head_bone.x - (width / 2);
  auto dy = head_bone.y - (height / 2);
  auto dist = sqrtf(dx * dx + dy * dy);

  if (settings::aimbot::fov_circle)
    ImGui::GetBackgroundDrawList()->AddCircle(ImVec2(width / 2, height / 2), settings::aimbot::aim_fov, ImColor(255, 255, 255, 255), 100);
	
  if (settings::aimbot::aimbot) {

    if (settings::bMenu)
      return;

    if (GetAsyncKeyState(hotkeys::aimkey)) {

      if (dist < closest_pawn) {

        closest_pawn = dist;

        // just basic smoothing
        if (settings::aimbot::smooth > 0) {
          dx = dx / (rand() % settings::aimbot::smooth + 1);
          dy = dy / (rand() % settings::aimbot::smooth + 1);
        }

        if (closest_pawn > settings::aimbot::aim_fov)
          return;

        if (entity.health <= 0)
          return;

        if (settings::aimbot::selectedhitbox == 0)
          dx, dy;

        if (settings::aimbot::selectedhitbox == 1)
          dy = dy + 20;

        mouse_event(MOUSEEVENTF_MOVE, dx, dy, NULL, NULL);
      }
    }
  }
}
