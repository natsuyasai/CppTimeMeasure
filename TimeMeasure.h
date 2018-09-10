#ifndef TIME_MEASURE_H
#define TIME_MEASURE_H
#include <iostream>
#include <chrono>
#include <mutex>


enum class PrintUnit
{
    nano,   // ナノ秒
    micro,  // マイクロ秒
    mill,   // ミリ秒
    sec,    // 秒
    minut,  // 分
    hours,  // 時
};

using time_pt = std::chrono::high_resolution_clock::time_point;
class TimeMeasure
{
    // メンバ変数定義
private:
    // 開始時間
    time_pt mStart;
    // 終了時間
    time_pt mEnd;
    // 自インスタンス
    static TimeMeasure* instance;
    // onceフラグ
    static std::once_flag once;

private:
    // コンストラクタ
    TimeMeasure()
    {

    }
    // デストラクタ
    ~TimeMeasure()
    {
        destroyInstance();
    }

public:
    // インスタンス取得
    static TimeMeasure & getInstance()
    {
        std::call_once(once, createInstance);
        return *instance;
    }

    // 計測開始
    void startMeasure()
    {
        mStart = std::chrono::high_resolution_clock::now();
    }
    
    // 計測停止
    void stopMeasure()
    {
        mEnd = std::chrono::high_resolution_clock::now();
    }

    // 結果表示
    void printResult(PrintUnit unit = PrintUnit::mill)
    {
        switch (unit)
        {
            case PrintUnit::nano:
                printResultForNano();
                break;
            case PrintUnit::micro:
                printResultForMicro();
                break;
            case PrintUnit::mill:
                printResultForMill();
                break;
            case PrintUnit::sec:
                printResultForSec();
                break;
            case PrintUnit::minut:
                printResultForMinutes();
                break;
            case PrintUnit::hours:
                printResultForHours();
                break;
            default:
                printResultForMill();
                break;
        }
    }

private:
    // インスタンス生成
    static void createInstance()
    {
        if (instance == nullptr)
            instance = new TimeMeasure();
    }

    // インスタンス破棄
    static void destroyInstance()
    {
        if (instance != nullptr)
        {
            delete instance;
            instance = nullptr;
        }
    }
    // 結果表示(単位別)
    void printResultForNano()
    {
        double elapsed = (double)std::chrono::duration_cast<std::chrono::nanoseconds>(mEnd - mStart).count();
        std::cout << "Time : " << elapsed << "ns" << std::endl;
    }
    void printResultForMicro()
    {
        double elapsed = (double)std::chrono::duration_cast<std::chrono::microseconds>(mEnd - mStart).count();
        std::cout << "Time : " << elapsed << "us" << std::endl;
    }
    void printResultForMill()
    {
        double elapsed = (double)std::chrono::duration_cast<std::chrono::milliseconds>(mEnd - mStart).count();
        std::cout << "Time : " << elapsed << "ms" << std::endl;
    }
    void printResultForSec()
    {
        double elapsed = (double)std::chrono::duration_cast<std::chrono::seconds>(mEnd - mStart).count();
        std::cout << "Time : " << elapsed << "s" << std::endl;
    }
    void printResultForMinutes()
    {
        double elapsed = (double)std::chrono::duration_cast<std::chrono::minutes>(mEnd - mStart).count();
        std::cout << "Time : " << elapsed << "m" << std::endl;
    }
    void printResultForHours()
    {
        double elapsed = (double)std::chrono::duration_cast<std::chrono::hours>(mEnd - mStart).count();
        std::cout << "Time : " << elapsed << "h" << std::endl;
    }
};
TimeMeasure* TimeMeasure::instance;
std::once_flag TimeMeasure::once;

#endif // TIME_MEASURE_H
