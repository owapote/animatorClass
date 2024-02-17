//------------------------------------------------
//		自作のAnimatorライブラリー
//								2024/02/17 更新
//------------------------------------------------

#pragma once

template<typename T>    //任意のanimation enum
class Animator
{
public:
    Animator();
    ~Animator();

    /// <summary>
    /// アニメーションのアタッチ
    /// </summary>
    /// <param name="modelHandle">モデルのハンドル</param>
    /// <param name="charaAnime">charaAnimeの列挙値</param>
    void SetAnime(const int &, const T &);

    /// <summary>
    /// 全アニメーションの削除
    /// </summary>
    /// <param name="modelHandle">モデルのハンドル</param>
    void RemoveAnime(const int &);

    /// <summary>
    /// アニメーションの再生
    /// </summary>
    /// <param name="modelHandle">モデルのハンドル</param>
    void PlayAnime(const int &);

    const T getNowAnime() const { return attachAnime; };

    const bool isEndAnimation() const { return animeStopTime <= animeTimer; }

    const float getNowAnimeTimer() const { return animeTimer; };
    const float getNowAnimeStopTime() const { return animeStopTime; };

private:
    T attachAnime;          //再生中のアニメーション名
    int attachAnimeIndex;   //アニメーションのアタッチされた番号、-1以外が入っている時はアニメーションがある
    float animeTimer;       //アニメーションのタイマー
    float animeStopTime;    //アニメーションの終了タイマー
    bool isPlayable;        //アニメーションが再生可能か否か
    bool isLoopAnime;       //ループするアニメーションか否か
};