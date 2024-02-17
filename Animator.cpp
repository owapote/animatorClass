#include "Animator.h"
#include "Log.h"
#include "DxLib.h"

template <typename T>
Animator<T>::Animator()
{
    Log::getInstance()->WriteLog("animator create now...");
    T attachAnime;
    int attachAnimeIndex;   //�A�j���[�V�����̃A�^�b�`���ꂽ�ԍ��A-1�ȊO�������Ă��鎞�̓A�j���[�V����������
    float animeTimer;       //�A�j���[�V�����̃^�C�}�[
    float animeStopTime;    //�A�j���[�V�����̏I���^�C�}�[
    bool isPlayable;        //�A�j���[�V�������Đ��\���ۂ�
    bool isLoopAnime;       //���[�v����A�j���[�V�������ۂ�
    Log::getInstance()->WriteLog("animator create completed!");
}

template <typename T>
Animator<T>::~Animator()
{

}

template <typename T>
void Animator<T>::SetAnime(const int &modelHandle, const T &animeNum)
{
    //���ݍĐ����̃A�j���[�V�������w�肳��Ă��Đݒ肵�Ȃ�
    if (animeNum == attachAnime) return;

    int anim = static_cast<int>(animeNum);

    attachAnimeIndex = MV1AttachAnim(modelHandle, anim, -1, FALSE);
    attachAnime = animeNum;
    animeStopTime = MV1GetAttachAnimTotalTime(modelHandle, attachAnimeIndex);
    animeTimer = 0.0f;
}

template <typename T>
void Animator<T>::RemoveAnime(const int &modelHandle)
{
    MV1DetachAnim(modelHandle, attachAnimeIndex);
    attachAnime = static_cast<T>(-1);
    attachAnimeIndex = -1;
    animeStopTime = 0.0f;
    animeTimer = 0.0f;
}
template <typename T>
void Animator<T>::PlayAnime(const int &modelHandle)
{
    if (attachAnimeIndex == -1) return;

    if (animeStopTime <= animeTimer)
    {
        if (isLoopAnime)
        {   //���[�v�A�j���[�V�����̏ꍇ
            animeTimer = 0.0f;
        } else
        {
            RemoveAnime(modelHandle);
        }
    }

    MV1SetAttachAnimTime(modelHandle, attachAnimeIndex, animeTimer);

    animeTimer += 0.5f;
}