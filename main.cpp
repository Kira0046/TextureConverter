#include <cstdio>
#include <cstdlib>
#include <DirectXTex.h>
#include "TextureConverter.h"

enum Argument {
	kApplicationPath,
	kFilePath,

	NumArgument
};

int main(int argc,char* argv[]) {
	
	for (int i = 0; i < argc; i++) {
		printf(argv[i]);

		printf("\n");
	}

	assert(argc >= NumArgument);

	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
	assert(SUCCEEDED(hr));

	TextureConverter converter;

	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	CoUninitialize();

	system("pause");
	return 0;
}