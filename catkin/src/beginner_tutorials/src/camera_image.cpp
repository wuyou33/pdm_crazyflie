#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
  // 接続しているデバイスで画像情報をキャプチャする
  cv::VideoCapture cap(0);
  // キャプチャする画像のサイズ(幅と高さ)を設定する
  cap.set(CV_CAP_PROP_FRAME_WIDTH, 160);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 120);
  // カメラがオープンできたかの確認
  if(!cap.isOpened()) return -1;
  
  // Captureと言う名前のウィンドウを作成する.後ろの二つはサイズと倍率を設定している
  cv::namedWindow("Capture", CV_WINDOW_AUTOSIZE);
  cv::Mat frame;
  // 以下のループではある瞬間にキャプチャした映像を，画像情報を扱うcv::Matにコピーし,
  // 連続的に表示する事で，カメラ画像の描画を実現する
  while(1) {
    cap >> frame; // キャプチャした画像をframeにコピーする
    cv::imshow("Capture", frame); // CaptureというWindowにframeの画像を描画する
    // cv::waitKey()は指定されたミリ秒の間，キー入力を受け付けるために待機を行う
    // キーを入力された場合,押されたキーのアスキーコードが戻り値となる
    // 画像表示などのようなイベント後にcv::waitKeyを用いないと不具合が出ることもある
    if(cv::waitKey(60) >= 0) // 60ミリ秒間待機している間にキー入力があると以下を実行
    {
      cv::imwrite("cap.png", frame); // frameの画像をcap.pngと言う名前で保存する
      break;
    }
  }
}

