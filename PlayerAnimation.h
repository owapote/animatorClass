#pragma once

/// <summary>
/// �A�j���[�V�����ԍ���<para/>
/// </summary>
enum class PlayerAnimation : int
{
	None = -1,
	Wait = 0,
	WalkingStart,
	Walking,
	WalkingEnd,
	Running,
	FirstSlash,
	NextSlash,
	GunWait,
	Falling,
	Landing,
};