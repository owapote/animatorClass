//------------------------------------------------
//		�����Animator���C�u�����[
//								2024/02/17 �X�V
//------------------------------------------------

#pragma once

template<typename T>    //�C�ӂ�animation enum
class Animator
{
public:
    Animator();
    ~Animator();

    /// <summary>
    /// �A�j���[�V�����̃A�^�b�`
    /// </summary>
    /// <param name="modelHandle">���f���̃n���h��</param>
    /// <param name="charaAnime">charaAnime�̗񋓒l</param>
    void SetAnime(const int &, const T &);

    /// <summary>
    /// �S�A�j���[�V�����̍폜
    /// </summary>
    /// <param name="modelHandle">���f���̃n���h��</param>
    void RemoveAnime(const int &);

    /// <summary>
    /// �A�j���[�V�����̍Đ�
    /// </summary>
    /// <param name="modelHandle">���f���̃n���h��</param>
    void PlayAnime(const int &);

    const T getNowAnime() const { return attachAnime; };

    const bool isEndAnimation() const { return animeStopTime <= animeTimer; }

    const float getNowAnimeTimer() const { return animeTimer; };
    const float getNowAnimeStopTime() const { return animeStopTime; };

private:
    T attachAnime;          //�Đ����̃A�j���[�V������
    int attachAnimeIndex;   //�A�j���[�V�����̃A�^�b�`���ꂽ�ԍ��A-1�ȊO�������Ă��鎞�̓A�j���[�V����������
    float animeTimer;       //�A�j���[�V�����̃^�C�}�[
    float animeStopTime;    //�A�j���[�V�����̏I���^�C�}�[
    bool isPlayable;        //�A�j���[�V�������Đ��\���ۂ�
    bool isLoopAnime;       //���[�v����A�j���[�V�������ۂ�
};