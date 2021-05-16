/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lseema <lseema@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 04:06:13 by lseema            #+#    #+#             */
/*   Updated: 2021/05/16 08:14:09 by lseema           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int	init_audio(t_w *w)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		return (0);
	w->sounds.move = Mix_LoadWAV("audio/step.wav");
	if (w->sounds.move == NULL)
		return (0);
	w->sounds.wood_door = Mix_LoadWAV("audio/creaking_door.wav");
	if (w->sounds.wood_door == NULL)
		return (0);
	w->sounds.metal_door = Mix_LoadWAV("audio/metal_door_open.wav");
	if (w->sounds.wood_door == NULL)
		return (0);
	w->sounds.birds_chill = Mix_LoadMUS("audio/chill_birds.wav");
	if (w->sounds.birds_chill == NULL)
		return (0);
	w->sounds.dark_loops = Mix_LoadMUS("audio/dark_loops.wav");
	if (w->sounds.dark_loops == NULL)
		return (0);
	w->sounds.asian_loop = Mix_LoadMUS("audio/asian_loop.wav");
	if (w->sounds.asian_loop == NULL)
		return (0);
	Mix_VolumeChunk(w->sounds.move, MIX_MAX_VOLUME / 4);
	Mix_VolumeChunk(w->sounds.metal_door, MIX_MAX_VOLUME / 3);
	return (1);
}

void	audio_handle(t_w *w, const uint8_t *keys)
{
	if ((keys[SDL_SCANCODE_UP] || keys[SDL_SCANCODE_DOWN]) \
		&& Mix_Playing(0) == 0)
		Mix_PlayChannel(0, w->sounds.move, 1);
	if (keys[SDL_SCANCODE_O] && Mix_Playing(1) == 0)
	{
		if (w->map.z[8][3] == 0)
			Mix_PlayChannel(1, w->sounds.wood_door, 0);
		if (w->map.z[9][12] == 0)
			Mix_PlayChannel(1, w->sounds.metal_door, 0);
		if (w->map.z[9][12] == 0 && (int)w->player_x == 10)
			Mix_FadeInMusic(w->sounds.dark_loops, -1, 2000);
		if (w->map.z[9][12] == 0 && (int)w->player_x == 8)
			Mix_FadeInMusic(w->sounds.birds_chill, -1, 2000);
		if (w->map.z[8][12] == 0 && w->player_x >= 9.6 && w->player_x <= 9.9)
			Mix_FadeInMusic(w->sounds.asian_loop, -1, 2000);
		if (w->map.z[8][12] == 0 && (int)w->player_x == 7)
			Mix_FadeInMusic(w->sounds.birds_chill, -1, 2000);
	}
	if (Mix_PlayingMusic() == 0)
		Mix_PlayMusic(w->sounds.birds_chill, -1);
}

void	free_audio(t_w *w)
{
	Mix_FreeMusic(w->sounds.birds_chill);
	Mix_FreeMusic(w->sounds.asian_loop);
	Mix_FreeMusic(w->sounds.dark_loops);
	Mix_FreeChunk(w->sounds.move);
	Mix_FreeChunk(w->sounds.wood_door);
	Mix_FreeChunk(w->sounds.metal_door);
	w->sounds.move = NULL;
	w->sounds.birds_chill = NULL;
	w->sounds.wood_door = NULL;
	w->sounds.metal_door = NULL;
	w->sounds.dark_loops = NULL;
	w->sounds.asian_loop = NULL;
	Mix_Quit();
}
