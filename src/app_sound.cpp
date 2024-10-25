#include "app_sound.h"

Sound sfx_die;
Sound sfx_hit;
Sound sfx_point;
Sound sfx_swooshing;
Sound sfx_wing;

const std::string sound_folder = "assets/sounds/";

void InitSounds() {
  sfx_die = LoadSound((sound_folder + "sfx_die.ogg").c_str());
  sfx_hit = LoadSound((sound_folder + "sfx_hit.ogg").c_str());
  sfx_point = LoadSound((sound_folder + "sfx_point.ogg").c_str());
  sfx_swooshing = LoadSound((sound_folder + "sfx_swooshing.ogg").c_str());
  sfx_wing = LoadSound((sound_folder + "sfx_wing.ogg").c_str());
}
bool IsSoundReadyAndPlay(Sound sound, const std::string& soundName) {
  if (!IsAudioDeviceReady()) {
    Logger::log_error("Audio device initialization error!");
    return false;
  }

  if (!IsSoundReady(sound)) {
    Logger::log_error("Sound " + soundName + " is not ready to play!");
    return false;
  }

  PlaySound(sound);
  Logger::log_info("Playing sound " + soundName + "...");
  return true;
}

void PlayDeathSound() { IsSoundReadyAndPlay(sfx_die, "death"); }

void PlayHitSound() { IsSoundReadyAndPlay(sfx_hit, "hit"); }

void PlayPointSound() { IsSoundReadyAndPlay(sfx_point, "point"); }

void PlaySwooshingSound() { IsSoundReadyAndPlay(sfx_swooshing, "swoosh"); }

void PlayWingSound() { IsSoundReadyAndPlay(sfx_wing, "wing"); }

void UnloadSounds() {
  UnloadSound(sfx_die);
  UnloadSound(sfx_hit);
  UnloadSound(sfx_point);
  UnloadSound(sfx_swooshing);
  UnloadSound(sfx_wing);

  CloseAudioDevice();
}
