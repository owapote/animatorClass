#include "Animator.h"
#include "Log.h"
#include "DxLib.h"

template <typename T>
Animator<T>::Animator()
{
    Log::getInstance()->WriteLog("animator create now...");
    T attachAnime;
    int attachAnimeIndex;   //アニメーションのアタッチされた番号、-1以外が入っている時はアニメーションがある
    float animeTimer;       //アニメーションのタイマー
    float animeStopTime;    //アニメーションの終了タイマー
    bool isPlayable;        //アニメーションが再生可能か否か
    bool isLoopAnime;       //ループするアニメーションか否か
    Log::getInstance()->WriteLog("animator create completed!");
}

template <typename T>
Animator<T>::~Animator()
{

}

template <typename T>
void Animator<T>::SetAnime(const int &modelHandle, const T &animeNum)
{
    //現在再生中のアニメーションを指定されても再設定しない
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
        {   //ループアニメーションの場合
            animeTimer = 0.0f;
        } else
        {
            RemoveAnime(modelHandle);
        }
    }

    MV1SetAttachAnimTime(modelHandle, attachAnimeIndex, animeTimer);

    animeTimer += 0.5f;
}