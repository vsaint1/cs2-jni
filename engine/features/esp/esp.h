#pragma once


#include "../math.h"
#include "../../overlay/drawing.h"
#include "../cheat.h"
#include "../aimbot/aimbot.h"



void draw_esp(FVector3 pos, FVector3 screen_pos, Entity entity, uintptr_t  bone_array, view_matrix_t view_matrix) {
	if (global_pawn) {

		if (settings::visuals::esp) {

			if (settings::visuals::bDistance)
				draw_distance(screen_pos, entity.position);

			if (settings::visuals::bSnaplines)
				draw_snapline(screen_pos, ImColor(255, 255, 255, 255));

			if (settings::visuals::bHealth)
				draw_healthbar(screen_pos, entity.health);

			if (settings::visuals::bSkeleton)
				draw_skeleton(bone_array, view_matrix);
		}


	}

}
