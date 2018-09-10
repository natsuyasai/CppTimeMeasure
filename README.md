# TimeMeasure
C++11以降対応時間計測用クラス


# exsample
```
#include "TimeMeasure.h"

int main()
{
	TimeMeasure::getInstance().startMeasure();

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			int* dmy = new int[100];
			delete dmy;
		}
	}

	TimeMeasure::getInstance().stopMeasure();

	TimeMeasure::getInstance().printResult();
	TimeMeasure::getInstance().printResult(PrintUnit::nano);
  return 0;
}
```
