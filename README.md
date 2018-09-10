# TimeMeasure
C++11以降対応時間計測用クラス


# exsample
```
#include "TimeMeasure.h"

int main()
{
	// 開始時間記録
	TimeMeasure::getInstance().startMeasure();

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int* dmy = new int[100];
			delete dmy;
		}
	}
	// 終了時間記録
	TimeMeasure::getInstance().stopMeasure();
	// 結果表示(ms)
	TimeMeasure::getInstance().printResult();
	// 結果表示(ns)
	TimeMeasure::getInstance().printResult(PrintUnit::nano);

	return 0;
}
```
