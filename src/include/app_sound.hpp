#pragma once


#include <string>

#include "raylib.h"
#include "logger.hpp"

extern Sound sfx_die;
extern Sound sfx_hit;
extern Sound sfx_point;
extern Sound sfx_swooshing;
extern Sound sfx_wing;

void InitSounds();

void PlayDeathSound();
void PlayHitSound();
void PlayPointSound();
void PlaySwooshingSound();
void PlayWingSound();

void UnloadSounds();