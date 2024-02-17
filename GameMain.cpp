//ざっくりとしたAnimatorクラスの使用例(愚直に実行しても一切動きません、あくまでもイメージです)

#include "PlayerAnimation.h"
#include "Animator.h"
#include "Model3D.h"

#include "DxLib.h"
#include <memory>

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
  // DxLibの初期化処理
  if (DxLib_Init() == -1) 
  {
      //初期化に失敗
      return -1;
  }

  //宣言
  std::unique_ptr<Model3D> model;	//キャラのモデル
  std::unique_ptr<Animator<PlayerAnimation>> animator;  //アニメーター

  //作成
  model = std::make_unique<Model3D>("素材/character/Otokonoko.pmd", Model3D::CenterState::Middle);  //男モデル、センター中央で作成
  animator = std::make_unique<Animator<PlayerAnimation>>();  //PlayerAnimation列挙型を使用したアニメーターの作成

  //再生アニメーションの設定
  anim->SetAnime(model->getModelHandle(), PlayerAnimation::Walking);  //歩行モーションの設定

  while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0)
  {
    //アニメーションの再生
    anim->PlayAnime(model->getModelHandle());
    //モデル描画
    model->Draw();
    //画面更新
    ScreenFlip();
    //escで終了
    if (CheckHitKey(KEY_INPUT_ESCAPE) || GetWindowUserCloseFlag())
    {
        DxLib_End();
        return 0;
    }
  }
}
