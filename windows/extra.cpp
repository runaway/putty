#include <string>
#include <iostream>

using namespace std;

extern "C"
char* RemoveChinese(char* szSrc, char* szDst)
{
	unsigned int nDstIndex = 0;
    unsigned int nSrcIndex;
	string strSrc = szSrc;

	for (nSrcIndex = 0; nSrcIndex < strSrc.length(); )
	{
		// ����һ��Ҫ���޷��ŵģ����������ַ��Ƚ�Ҳ��ͨ��~
		unsigned char byTemp = strSrc[nSrcIndex];
        unsigned char byTemp1 = strSrc[nSrcIndex + 1];

		//if ((byTemp >= 0xb0 && byTemp <= 0xf7) || (byTemp >= 0xa1 && byTemp <= 0xfe)) continue;
		if ((byTemp >= 0x81 && byTemp <= 0xFE) || (byTemp1 >= 0xA1 && byTemp1 <= 0xFE))
        //if (byTemp > 0x80)
        {
            // ���֣�������++
            nSrcIndex += 2; // �Ǻ�����Ȼ�͸�ֱ��+2��
            continue;
        }
        else
        {
    		szDst[nDstIndex] = strSrc[nSrcIndex];
            nSrcIndex++;
    		nDstIndex++;
        }

	}

    szDst[nDstIndex] = '\0';

	return szDst;
}
