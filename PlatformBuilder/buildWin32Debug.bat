rmdir /s /q %2
mkdir %2
unrar x ./Win32Package/Debug.rar %2/"bin/"
xcopy /E /Y /I /R /F "../device" %2"/device"
%2"/bin/"%1
