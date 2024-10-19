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
    Logger::log_error("Ошибка инициализации аудиоустройства!");
    return false;
  }

  if (!IsSoundReady(sound)) {
    Logger::log_error("Звук " + soundName + " не готов к воспроизведению!");
    return false;
  }

  PlaySound(sound);
  Logger::log_info("Воспроизведение звука " + soundName + "...");
  return true;
}

void PlayDeathSound() { IsSoundReadyAndPlay(sfx_die, "смерти"); }

void PlayHitSound() { IsSoundReadyAndPlay(sfx_hit, "удара"); }

void PlayPointSound() { IsSoundReadyAndPlay(sfx_point, "очка"); }

void PlaySwooshingSound() { IsSoundReadyAndPlay(sfx_swooshing, "свиста"); }

void PlayWingSound() { IsSoundReadyAndPlay(sfx_wing, "крыльев"); }

void UnloadSounds() {
  UnloadSound(sfx_die);
  UnloadSound(sfx_hit);
  UnloadSound(sfx_point);
  UnloadSound(sfx_swooshing);
  UnloadSound(sfx_wing);

  CloseAudioDevice();
}
