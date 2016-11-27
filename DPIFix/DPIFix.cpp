// DPIFix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main(int argc, char** argv)
{
	if (argc < 2) {
		cout << "Usage " << argv[0] << " [program.exe]" << endl;
		return -1;
	}
	string xml = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?> <assembly xmlns=\"urn:schemas-microsoft-com:asm.v1\" manifestVersion=\"1.0\"> <application xmlns=\"urn:schemas-microsoft-com:asm.v3\"> <windowsSettings> <dpiAware xmlns=\"http://schemas.microsoft.com/SMI/2005/WindowsSettings\">False</dpiAware> </windowsSettings> </application> </assembly>";
	string filepath = string(argv[1]);
	filepath.append(".manifest");
	ofstream outfile(filepath);
	outfile << xml;
	outfile.close();
	//Prompt to reboot
	
	int retcode = InitiateShutdown(NULL, NULL, 30, SHUTDOWN_RESTARTAPPS, SHTDN_REASON_MINOR_INSTALLATION);
	if (retcode == ERROR_SUCCESS) {
		return 0;
	}
	return retcode;
}

