 #include "TimeMeasure.h"
 using namespace YasaiUtility;

// 実態定義
TimeMeasure* TimeMeasure::instance;
std::once_flag TimeMeasure::once;

// コンストラクタ
TimeMeasure::TimeMeasure()
{

}

// デストラクタ
TimeMeasure::~TimeMeasure()
{
    destroyInstance();
}

// 結果表示
void TimeMeasure::printResult(PrintUnit unit)
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