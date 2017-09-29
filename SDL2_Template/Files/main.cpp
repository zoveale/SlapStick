/*

*/

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

int main(int argc, char* args[]) {
  //
  SDL_Window* window = NULL;
  SDL_Surface* windowSurface = NULL;
  SDL_Surface* prompt = NULL;
  SDL_Surface* testImage = NULL;
  SDL_Rect image = {510, 25, NULL, NULL};

  //
  Mix_Music* music = NULL;
  Mix_Chunk* soundOne = NULL;
  Mix_Chunk* soundTwo = NULL;

  //


  //
  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
  window = SDL_CreateWindow("Test Program",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    640, 480, SDL_WINDOW_SHOWN);

  //
  windowSurface = SDL_GetWindowSurface(window);

  //
  prompt = IMG_Load("Support Files/prompt_test.png");
  testImage = IMG_Load("Support Files/image_test.png");
  prompt = SDL_ConvertSurface(prompt, windowSurface->format, NULL);
  music = Mix_LoadMUS("Support Files/music_test.wav");
  soundOne = Mix_LoadWAV("Support Files/sound_test_1.wav");
  soundTwo = Mix_LoadWAV("Support Files/sound_test_2.wav");

  //
  SDL_BlitSurface(prompt, NULL, windowSurface, NULL);

  
  //
  SDL_Event event;
  bool flag = true;
  while (flag) {
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.scancode) { // Begin switch scancode.
          case SDL_SCANCODE_ESCAPE:
            flag = false;
            break;

          case SDL_SCANCODE_0:
            SDL_BlitSurface(testImage, NULL, windowSurface, &image);
            break;

          case SDL_SCANCODE_1:
            Mix_PlayChannel(-1, soundOne, 0);
            break;

          case SDL_SCANCODE_2:
            Mix_PlayChannel(-1, soundTwo, 0);
            break;

          case SDL_SCANCODE_3:
            if (Mix_PlayingMusic() == 0) {
              Mix_PlayMusic(music, -1);
            } else {
              if (Mix_PausedMusic() == 1) {
                Mix_ResumeMusic();
              } else {
                //Pause the music
                Mix_PauseMusic();
              }
            }
            break;

          case SDL_SCANCODE_4:
            Mix_HaltMusic();
            break;

          case SDL_SCANCODE_5:
            break;
        } // End switch scancode.
      }
    }

    //
    SDL_UpdateWindowSurface(window);
  }

  // Deallocate memory.


  return 0;
}